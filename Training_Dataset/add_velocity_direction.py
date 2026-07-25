"""
Add actuator velocity and direction columns to a Stewart-platform CSV log.

Input CSV must contain:
- time
- L1_desired ... L6_desired   (ideal IK lengths in mm)
- L1_actual  ... L6_actual    (measured actuator lengths in mm)

Output adds, for each actuator i:
- dL{i}_desired_mm, vL{i}_desired_mm_s, dirL{i}_desired
- dL{i}_actual_mm,  vL{i}_actual_mm_s,  dirL{i}_actual

Direction convention:
+1 = extending, -1 = retracting, 0 = nearly stationary
python add_velocity_direction.py --input Traj1.csv --output Traj1_fulldata.csv
python add_velocity_direction.py --input Traj2.csv --output Traj2_fulldata.csv
python add_velocity_direction.py --input Traj3.csv --output Traj3_fulldata.csv
python add_velocity_direction.py --input Traj4.csv --output Traj4_fulldata.csv
python add_velocity_direction.py --input Traj5.csv --output Traj5_fulldata.csv
python add_velocity_direction.py --input Traj6.csv --output Traj6_fulldata.csv
python add_velocity_direction.py --input Traj7.csv --output Traj7_fulldata.csv
python add_velocity_direction.py --input Traj8.csv --output Traj8_fulldata.csv
python add_velocity_direction.py --input Traj9.csv --output Traj9_fulldata.csv
python add_velocity_direction.py --input Traj10.csv --output Traj10_fulldata.csv
python add_velocity_direction.py --input Traj11.csv --output Traj11_fulldata.csv
python add_velocity_direction.py --input Traj12.csv --output Traj12_fulldata.csv
python add_velocity_direction.py --input Traj13.csv --output Traj13_fulldata.csv
python add_velocity_direction.py --input Traj14.csv --output Traj14_fulldata.csv
"""

import argparse
import numpy as np
import pandas as pd


def safe_dt(time_values: pd.Series) -> np.ndarray:
    """Return positive dt array. Bad/zero dt values are replaced by median positive dt."""
    t = pd.to_numeric(time_values, errors="coerce").to_numpy(dtype=float)
    dt = np.diff(t, prepend=t[0])

    positive_dt = dt[dt > 0]
    if len(positive_dt) == 0:
        raise ValueError("No positive time differences found. Check the time column.")

    default_dt = np.median(positive_dt)
    dt[dt <= 0] = default_dt
    dt[~np.isfinite(dt)] = default_dt
    return dt


def add_velocity_direction(
    input_csv: str,
    output_csv: str,
    time_col: str = "time",
    desired_prefix: str = "L",
    desired_suffix: str = "_desired",
    actual_suffix: str = "_actual",
    eps_velocity: float = 0.05,
) -> None:
    """Read CSV, add velocity/direction columns, and save updated CSV."""

    df = pd.read_csv(input_csv)

    if time_col not in df.columns:
        raise ValueError(f"Missing time column: {time_col}")

    # Keep original order, but warn by sorting is not done automatically.
    # If your data is not ordered by time, uncomment the next line:
    # df = df.sort_values(time_col).reset_index(drop=True)

    dt = safe_dt(df[time_col])

    for i in range(1, 7):
        desired_col = f"{desired_prefix}{i}{desired_suffix}"
        actual_col = f"{desired_prefix}{i}{actual_suffix}"

        for col in [desired_col, actual_col]:
            if col not in df.columns:
                raise ValueError(f"Missing required column: {col}")

        # Convert to numeric in case the CSV has text formatting
        desired = pd.to_numeric(df[desired_col], errors="coerce").to_numpy(dtype=float)
        actual = pd.to_numeric(df[actual_col], errors="coerce").to_numpy(dtype=float)

        # Change in length between samples, in mm
        d_desired = np.diff(desired, prepend=desired[0])
        d_actual = np.diff(actual, prepend=actual[0])

        # Velocity, in mm/s if length is mm and time is seconds
        v_desired = d_desired / dt
        v_actual = d_actual / dt

        # First velocity is set to zero because there is no previous sample
        d_desired[0] = 0.0
        d_actual[0] = 0.0
        v_desired[0] = 0.0
        v_actual[0] = 0.0

        # Direction using a threshold to avoid noise around zero
        dir_desired = np.zeros(len(df), dtype=int)
        dir_actual = np.zeros(len(df), dtype=int)

        dir_desired[v_desired > eps_velocity] = 1
        dir_desired[v_desired < -eps_velocity] = -1

        dir_actual[v_actual > eps_velocity] = 1
        dir_actual[v_actual < -eps_velocity] = -1

        # Add columns
        df[f"dL{i}_desired_mm"] = d_desired
        df[f"vL{i}_desired_mm_s"] = v_desired
        df[f"dirL{i}_desired"] = dir_desired

        df[f"dL{i}_actual_mm"] = d_actual
        df[f"vL{i}_actual_mm_s"] = v_actual
        df[f"dirL{i}_actual"] = dir_actual

    df.to_csv(output_csv, index=False)
    print(f"Saved updated file to: {output_csv}")
    print(f"Rows: {len(df)}")
    print(f"Columns: {len(df.columns)}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--input", default="Traj1.csv", help="Input CSV path")
    parser.add_argument("--output", default="Traj1_with_velocity_direction.csv", help="Output CSV path")
    parser.add_argument("--eps", type=float, default=0.05, help="Velocity threshold for direction, in mm/s")
    args = parser.parse_args()

    add_velocity_direction(
        input_csv=args.input,
        output_csv=args.output,
        eps_velocity=args.eps,
    )
