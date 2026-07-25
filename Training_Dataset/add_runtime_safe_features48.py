"""
Add runtime-safe dynamic features to Stewart-platform CSV logs.

This script creates columns needed by the 48-input PC PINN.

Input CSV must contain:
    time
    X_desired, Y_desired, Z_desired, Roll_desired, Pitch_desired, Yaw_desired
    L1_desired ... L6_desired
    L1_actual  ... L6_actual

Output adds:
    dL{i}_desired_mm
    vL{i}_desired_mm_s
    dirL{i}_desired
    dL{i}_actual_mm
    vL{i}_actual_mm_s
    dirL{i}_actual

Runtime-safe shifted columns:
    L{i}_actual_prev
    L{i}_actual_prev2
    L{i}_desired_prev
    vL{i}_actual_prev_mm_s
    dirL{i}_actual_prev
    errorL{i}_prev_mm

Direction convention:
    +1 = extending
    -1 = retracting
     0 = nearly stationary

Examples:
    python add_runtime_safe_features48.py --input Traj1.csv --output Traj1_fulldata.csv --eps 0.5
    python add_runtime_safe_features48.py --input Traj2.csv --output Traj2_fulldata.csv --eps 0.5
    python add_runtime_safe_features48.py --input Traj3.csv --output Traj3_fulldata.csv --eps 0.5
    python add_runtime_safe_features48.py --input Traj4.csv --output Traj4_fulldata.csv --eps 0.5
    python add_runtime_safe_features48.py --input Traj5.csv --output Traj5_fulldata.csv --eps 0.5
    python add_runtime_safe_features48.py --input Traj6.csv --output Traj6_fulldata.csv --eps 0.5
    python add_runtime_safe_features48.py --input Traj7.csv --output Traj7_fulldata.csv --eps 0.5
    python add_runtime_safe_features48.py --input Traj8.csv --output Traj8_fulldata.csv --eps 0.5
    python add_runtime_safe_features48.py --input Traj9.csv --output Traj9_fulldata.csv --eps 0.5
    python add_runtime_safe_features48.py --input Traj10.csv --output Traj10_fulldata.csv --eps 0.5
    python add_runtime_safe_features48.py --input Traj11.csv --output Traj11_fulldata.csv --eps 0.5
    python add_runtime_safe_features48.py --input Traj12.csv --output Traj12_fulldata.csv --eps 0.5
    python add_runtime_safe_features48.py --input Traj13.csv --output Traj13_fulldata.csv --eps 0.5
    python add_runtime_safe_features48.py --input Traj14.csv --output Traj14_fulldata.csv --eps 0.5

Batch folder:
    python add_runtime_safe_features48.py --input-folder "C:\data\raw" --output-folder "C:\data\full" --eps 0.5
"""

import argparse
import os
from pathlib import Path

import numpy as np
import pandas as pd


POSE_COLS = [
    "X_desired", "Y_desired", "Z_desired",
    "Roll_desired", "Pitch_desired", "Yaw_desired"
]


def safe_dt(time_values: pd.Series) -> np.ndarray:
    """Return positive dt array. Bad/zero dt values are replaced by median positive dt."""
    t = pd.to_numeric(time_values, errors="coerce").to_numpy(dtype=float)
    dt = np.diff(t, prepend=t[0])

    positive_dt = dt[np.isfinite(dt) & (dt > 0)]
    if len(positive_dt) == 0:
        raise ValueError("No positive time differences found. Check the time column.")

    default_dt = float(np.median(positive_dt))
    dt[(dt <= 0) | (~np.isfinite(dt))] = default_dt
    return dt


def require_columns(df: pd.DataFrame) -> None:
    missing = []
    for c in ["time", *POSE_COLS]:
        if c not in df.columns:
            missing.append(c)

    for i in range(1, 7):
        for c in [f"L{i}_desired", f"L{i}_actual"]:
            if c not in df.columns:
                missing.append(c)

    if missing:
        raise ValueError("Missing required columns:\n" + "\n".join(missing))


def add_runtime_safe_features(
    input_csv: str,
    output_csv: str,
    eps_velocity: float = 0.5,
    sort_by_time: bool = False,
    drop_invalid_start_rows: bool = True,
) -> None:
    df = pd.read_csv(input_csv)

    if sort_by_time:
        df = df.sort_values("time").reset_index(drop=True)

    require_columns(df)

    # Force important columns numeric.
    numeric_cols = ["time", *POSE_COLS]
    for i in range(1, 7):
        numeric_cols += [f"L{i}_desired", f"L{i}_actual"]

    for c in numeric_cols:
        df[c] = pd.to_numeric(df[c], errors="coerce")

    dt = safe_dt(df["time"])

    for i in range(1, 7):
        desired_col = f"L{i}_desired"
        actual_col = f"L{i}_actual"

        desired = df[desired_col].to_numpy(dtype=float)
        actual = df[actual_col].to_numpy(dtype=float)

        # Current-row differences, useful for analysis and desired velocity.
        d_desired = np.diff(desired, prepend=desired[0])
        d_actual = np.diff(actual, prepend=actual[0])

        v_desired = d_desired / dt
        v_actual = d_actual / dt

        d_desired[0] = 0.0
        d_actual[0] = 0.0
        v_desired[0] = 0.0
        v_actual[0] = 0.0

        dir_desired = np.zeros(len(df), dtype=int)
        dir_actual = np.zeros(len(df), dtype=int)

        dir_desired[v_desired > eps_velocity] = 1
        dir_desired[v_desired < -eps_velocity] = -1

        dir_actual[v_actual > eps_velocity] = 1
        dir_actual[v_actual < -eps_velocity] = -1

        df[f"dL{i}_desired_mm"] = d_desired
        df[f"vL{i}_desired_mm_s"] = v_desired
        df[f"dirL{i}_desired"] = dir_desired

        df[f"dL{i}_actual_mm"] = d_actual
        df[f"vL{i}_actual_mm_s"] = v_actual
        df[f"dirL{i}_actual"] = dir_actual

        # Runtime-safe previous-state features.
        # At time k, the controller can know these:
        #   L_actual(k-1)
        #   L_actual(k-2)
        #   v_actual(k-1)
        #   dir_actual(k-1)
        #   error(k-1) = L_desired(k-1) - L_actual(k-1)
        df[f"L{i}_actual_prev"] = df[actual_col].shift(1)
        df[f"L{i}_actual_prev2"] = df[actual_col].shift(2)
        df[f"L{i}_desired_prev"] = df[desired_col].shift(1)

        df[f"vL{i}_actual_prev_mm_s"] = df[f"vL{i}_actual_mm_s"].shift(1)
        df[f"dirL{i}_actual_prev"] = df[f"dirL{i}_actual"].shift(1)

        df[f"errorL{i}_prev_mm"] = df[f"L{i}_desired_prev"] - df[f"L{i}_actual_prev"]

    # Drop first rows where shifted previous data does not exist.
    if drop_invalid_start_rows:
        required_runtime_cols = []
        for i in range(1, 7):
            required_runtime_cols += [
                f"L{i}_actual_prev",
                f"L{i}_actual_prev2",
                f"L{i}_desired_prev",
                f"vL{i}_actual_prev_mm_s",
                f"dirL{i}_actual_prev",
                f"errorL{i}_prev_mm",
                f"vL{i}_desired_mm_s",
                f"dirL{i}_desired",
            ]

        df = df.dropna(subset=required_runtime_cols).reset_index(drop=True)

    Path(output_csv).parent.mkdir(parents=True, exist_ok=True)
    for i in range(1, 7):
        desired_col = f"L{i}_desired"
        actual_col  = f"L{i}_actual"

        # your velocity/direction code here
        # your previous actual / previous velocity / error_prev code here

    # ============================================================
    # Remove rows with unrealistic desired actuator velocity
    # caused by trajectory reset / discontinuity
    # ============================================================
    max_desired_velocity_mm_s = 50.0

    bad_rows = np.zeros(len(df), dtype=bool)

    for i in range(1, 7):
        vcol = f"vL{i}_desired_mm_s"
        bad_rows |= np.abs(df[vcol].to_numpy(dtype=float)) > max_desired_velocity_mm_s

    # Also remove one row before and after the bad jump for safety
    bad_rows_shifted = bad_rows.copy()
    bad_rows_shifted[1:]  |= bad_rows[:-1]
    bad_rows_shifted[:-1] |= bad_rows[1:]

    removed = int(np.sum(bad_rows_shifted))
    df = df.loc[~bad_rows_shifted].reset_index(drop=True)

    print(f"Removed {removed} reset/jump rows using max desired velocity = {max_desired_velocity_mm_s} mm/s")

    # Remove first rows caused by shift(1), shift(2)
    df = df.dropna().reset_index(drop=True)

    df.to_csv(output_csv, index=False)
    print(f"Saved: {output_csv}")
    print(f"Rows: {len(df)}")
    print(f"Columns: {len(df.columns)}")
    print(f"eps_velocity: {eps_velocity} mm/s")


def process_folder(input_folder: str, output_folder: str, eps_velocity: float, sort_by_time: bool) -> None:
    input_folder = Path(input_folder)
    output_folder = Path(output_folder)
    output_folder.mkdir(parents=True, exist_ok=True)

    csv_files = sorted(input_folder.glob("*.csv"))
    if not csv_files:
        raise FileNotFoundError(f"No CSV files found in: {input_folder}")

    for csv_path in csv_files:
        out_path = output_folder / f"{csv_path.stem}_fulldata.csv"
        add_runtime_safe_features(
            input_csv=str(csv_path),
            output_csv=str(out_path),
            eps_velocity=eps_velocity,
            sort_by_time=sort_by_time,
            drop_invalid_start_rows=True,
        )


if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    parser.add_argument("--input", default=None, help="Single input CSV path")
    parser.add_argument("--output", default=None, help="Single output CSV path")

    parser.add_argument("--input-folder", default=None, help="Folder containing raw CSV files")
    parser.add_argument("--output-folder", default=None, help="Folder where processed CSV files are saved")

    parser.add_argument("--eps", type=float, default=0.5, help="Velocity threshold for direction [mm/s]")
    parser.add_argument("--sort-by-time", action="store_true", help="Sort rows by time before processing")

    args = parser.parse_args()

    if args.input_folder is not None:
        if args.output_folder is None:
            raise ValueError("--output-folder is required when using --input-folder")

        process_folder(
            input_folder=args.input_folder,
            output_folder=args.output_folder,
            eps_velocity=args.eps,
            sort_by_time=args.sort_by_time,
        )

    else:
        if args.input is None:
            raise ValueError("Use --input/--output for one file or --input-folder/--output-folder for batch mode.")

        output = args.output
        if output is None:
            in_path = Path(args.input)
            output = str(in_path.with_name(in_path.stem + "_fulldata.csv"))

        add_runtime_safe_features(
            input_csv=args.input,
            output_csv=output,
            eps_velocity=args.eps,
            sort_by_time=args.sort_by_time,
            drop_invalid_start_rows=True,
        )
