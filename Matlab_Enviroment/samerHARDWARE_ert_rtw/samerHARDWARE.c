/*
 * samerHARDWARE.c
 *
 * Code generation for model "samerHARDWARE".
 *
 * Model version              : 6.1081
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Tue Jul  7 00:23:39 2026
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "samerHARDWARE.h"
#include "rtwtypes.h"
#include "samerHARDWARE_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>

/* Named constants for MATLAB Function: '<S5>/MATLAB Function' */
#define samerHARDWARE_CALL_EVENT       (-1L)

/* Named constants for MATLAB Function: '<S5>/MATLAB Function1' */
#define samerHARDWARE_CALL_EVENT_n     (-1L)

/* Named constants for MATLAB Function: '<Root>/MATLAB Function' */
#define samerHARDWARE_CALL_EVENT_a     (-1L)

/* Block signals (default storage) */
B_samerHARDWARE_T samerHARDWARE_B;

/* Block states (default storage) */
DW_samerHARDWARE_T samerHARDWARE_DW;

/* Real-time model */
static RT_MODEL_samerHARDWARE_T samerHARDWARE_M_;
RT_MODEL_samerHARDWARE_T *const samerHARDWARE_M = &samerHARDWARE_M_;

/* Forward declaration for local functions */
static real_T samerHARDWARE_mod(real_T x, real_T y);
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (samerHARDWARE_M->Timing.TaskCounters.TID[2])++;
  if ((samerHARDWARE_M->Timing.TaskCounters.TID[2]) > 2) {/* Sample time: [0.03s, 0.0s] */
    samerHARDWARE_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    '<S5>/MATLAB Function'
 *    '<S6>/MATLAB Function'
 *    '<S7>/MATLAB Function'
 *    '<S8>/MATLAB Function'
 *    '<S9>/MATLAB Function'
 *    '<S10>/MATLAB Function'
 */
void samerHARDWA_MATLABFunction_Init(DW_MATLABFunction_samerHARDWA_T *localDW)
{
  localDW->sfEvent = samerHARDWARE_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<S5>/MATLAB Function'
 *    '<S6>/MATLAB Function'
 *    '<S7>/MATLAB Function'
 *    '<S8>/MATLAB Function'
 *    '<S9>/MATLAB Function'
 *    '<S10>/MATLAB Function'
 */
void samerHARDWARE_MATLABFunction(real_T rtu_u, B_MATLABFunction_samerHARDWAR_T *
  localB, DW_MATLABFunction_samerHARDWA_T *localDW)
{
  localDW->sfEvent = samerHARDWARE_CALL_EVENT;
  if (rtu_u >= 0.0) {
    localB->y = 1.0;
    localB->x = 0.0;
  } else {
    localB->y = 0.0;
    localB->x = 1.0;
  }
}

/*
 * System initialize for atomic system:
 *    '<S5>/MATLAB Function1'
 *    '<S5>/MATLAB Function2'
 *    '<S6>/MATLAB Function1'
 *    '<S6>/MATLAB Function2'
 *    '<S7>/MATLAB Function1'
 *    '<S7>/MATLAB Function2'
 *    '<S8>/MATLAB Function1'
 *    '<S8>/MATLAB Function2'
 *    '<S9>/MATLAB Function1'
 *    '<S9>/MATLAB Function2'
 *    ...
 */
void samerHARDW_MATLABFunction1_Init(DW_MATLABFunction1_samerHARDW_T *localDW)
{
  localDW->sfEvent = samerHARDWARE_CALL_EVENT_n;
}

/*
 * Output and update for atomic system:
 *    '<S5>/MATLAB Function1'
 *    '<S5>/MATLAB Function2'
 *    '<S6>/MATLAB Function1'
 *    '<S6>/MATLAB Function2'
 *    '<S7>/MATLAB Function1'
 *    '<S7>/MATLAB Function2'
 *    '<S8>/MATLAB Function1'
 *    '<S8>/MATLAB Function2'
 *    '<S9>/MATLAB Function1'
 *    '<S9>/MATLAB Function2'
 *    ...
 */
void samerHARDWARE_MATLABFunction1(real_T rtu_u, real_T rtu_v,
  B_MATLABFunction1_samerHARDWA_T *localB, DW_MATLABFunction1_samerHARDW_T
  *localDW)
{
  localDW->sfEvent = samerHARDWARE_CALL_EVENT_n;
  localB->y = rtu_u * rtu_v;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function4' */
static real_T samerHARDWARE_mod(real_T x, real_T y)
{
  real_T q;
  real_T r;
  if (y == 0.0) {
    r = x;
    if (x == 0.0) {
      r = y;
    }
  } else if (rtIsNaN(x) || rtIsNaN(y) || rtIsInf(x)) {
    r = (rtNaN);
  } else if (rtIsInf(y)) {
    if (y > 0.0) {
      if (x > 0.0) {
        r = x;
      } else if (x < 0.0) {
        r = y;
      } else {
        r = 0.0;
      }
    } else if (x > 0.0) {
      r = y;
    } else if (x < 0.0) {
      r = x;
    } else {
      r = -0.0;
    }
  } else {
    if (y > floor(y)) {
      q = fabs(x / y);
      if (fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q) {
        r = fmod(x, y);
      } else {
        r = 0.0;
      }
    } else {
      r = fmod(x, y);
    }

    if (r == 0.0) {
      r = y * 0.0;
    } else if (r < 0.0) {
      if (y > 0.0) {
        r += y;
      }
    } else if ((r > 0.0) && (y < 0.0)) {
      r += y;
    }
  }

  return r;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void samerHARDWARE_step(void)
{
  int16_T active_count;
  int16_T i;
  int16_T shape_id;
  uint16_T b_varargout_1;
  int8_T P_end_idx_0;
  int8_T P_end_idx_1;
  int8_T P_end_idx_2;
  static const real_T c[6] = { 0.43633231299858238, 0.85521133347722145,
    2.530727415391778, 2.9496064358704168, 4.6251225177849733,
    5.0440015382636121 };

  static const real_T d[6] = { 0.0, 1.2915436464758039, 2.0943951023931953,
    3.3859387488689991, 4.1887902047863905, 5.4803338512621949 };

  /* Clock: '<Root>/Clock1' */
  samerHARDWARE_B.Clock1 = samerHARDWARE_M->Timing.t[0];

  /* MATLAB Function: '<Root>/MATLAB Function2' */
  samerHARDWARE_DW.sfEvent_b = samerHARDWARE_CALL_EVENT_a;
  if (samerHARDWARE_B.Clock1 < 10.0) {
    samerHARDWARE_B.t_traj = 0.0;
  } else {
    samerHARDWARE_B.t_traj = samerHARDWARE_B.Clock1 - 10.0;
  }

  /* MATLAB Function: '<Root>/MATLAB Function4' incorporates:
   *  Constant: '<Root>/Constant'
   */
  samerHARDWARE_DW.sfEvent = samerHARDWARE_CALL_EVENT_a;
  active_count = 0;
  for (i = 0; i < 15; i++) {
    samerHARDWARE_B.Yaw = samerHARDWARE_P.Constant_Value[i];
    samerHARDWARE_B.flags[i] = samerHARDWARE_B.Yaw;
    if (samerHARDWARE_B.Yaw != 0.0) {
      active_count++;
    }
  }

  samerHARDWARE_B.X = 0.0;
  samerHARDWARE_B.Y = 0.0;
  samerHARDWARE_B.Z = 323.5;
  samerHARDWARE_B.Roll = 0.0;
  samerHARDWARE_B.Pitch = 0.0;
  samerHARDWARE_B.Yaw = 0.0;
  shape_id = 0;
  samerHARDWARE_B.u_des[0] = 0.0;
  samerHARDWARE_B.u_des[1] = 0.0;
  samerHARDWARE_B.u_des[2] = 323.5;
  samerHARDWARE_B.u_des[3] = 0.0;
  samerHARDWARE_B.u_des[4] = 0.0;
  samerHARDWARE_B.u_des[5] = 0.0;
  if (active_count != 0) {
    samerHARDWARE_B.activeSlot = samerHARDWARE_mod(floor(samerHARDWARE_B.t_traj /
      180.0), (real_T)active_count) + 1.0;
    active_count = 0;
    for (i = 0; i < 15; i++) {
      if (samerHARDWARE_B.flags[i] != 0.0) {
        active_count++;
        if (active_count == samerHARDWARE_B.activeSlot) {
          shape_id = i + 1;
        }
      }
    }

    samerHARDWARE_B.tau = samerHARDWARE_B.t_traj - floor(samerHARDWARE_B.t_traj /
      180.0) * 180.0;
    if (shape_id == 1) {
      samerHARDWARE_B.X = sin(0.62831853071795862 * samerHARDWARE_B.tau) * 50.0;
    } else if (shape_id == 2) {
      samerHARDWARE_B.Z = sin(0.62831853071795862 * samerHARDWARE_B.tau) * 35.0
        + 323.5;
    } else if (shape_id == 3) {
      samerHARDWARE_B.activeSlot = 0.62831853071795862 * samerHARDWARE_B.tau;
      samerHARDWARE_B.X = sin(samerHARDWARE_B.activeSlot) * 50.0;
      samerHARDWARE_B.Z = cos(samerHARDWARE_B.activeSlot) * 25.0 + 323.5;
    } else if (shape_id == 4) {
      samerHARDWARE_B.X = sin(0.62831853071795862 * samerHARDWARE_B.tau) * 40.0;
      samerHARDWARE_B.Z = sin(1.2566370614359172 * samerHARDWARE_B.tau) * 20.0 +
        323.5;
    } else if (shape_id == 5) {
      samerHARDWARE_B.Z = samerHARDWARE_B.tau / 50.0;
      samerHARDWARE_B.Z -= floor(samerHARDWARE_B.Z);
      if (samerHARDWARE_B.Z < 0.25) {
        samerHARDWARE_B.X = samerHARDWARE_B.Z / 0.25 * 100.0 - 50.0;
        samerHARDWARE_B.Z = 348.5;
      } else if (samerHARDWARE_B.Z < 0.5) {
        samerHARDWARE_B.X = 50.0;
        samerHARDWARE_B.Z = (25.0 - (samerHARDWARE_B.Z - 0.25) / 0.25 * 50.0) +
          323.5;
      } else if (samerHARDWARE_B.Z < 0.75) {
        samerHARDWARE_B.X = 50.0 - (samerHARDWARE_B.Z - 0.5) / 0.25 * 100.0;
        samerHARDWARE_B.Z = 298.5;
      } else {
        samerHARDWARE_B.X = -50.0;
        samerHARDWARE_B.Z = ((samerHARDWARE_B.Z - 0.75) / 0.25 * 50.0 - 25.0) +
          323.5;
      }
    } else if (shape_id == 6) {
      samerHARDWARE_B.Z = samerHARDWARE_B.tau / 30.0;
      samerHARDWARE_B.Z -= floor(samerHARDWARE_B.Z);
      if (samerHARDWARE_B.Z < 0.33333333333333331) {
        samerHARDWARE_B.X = samerHARDWARE_B.Z / 0.33333333333333331 * 60.0 -
          30.0;
        samerHARDWARE_B.Z = 308.5;
      } else if (samerHARDWARE_B.Z < 0.66666666666666663) {
        samerHARDWARE_B.activeSlot = (samerHARDWARE_B.Z - 0.33333333333333331) /
          0.33333333333333331 * 30.0;
        samerHARDWARE_B.X = 30.0 - samerHARDWARE_B.activeSlot;
        samerHARDWARE_B.Z = (samerHARDWARE_B.activeSlot - 15.0) + 323.5;
      } else {
        samerHARDWARE_B.activeSlot = (samerHARDWARE_B.Z - 0.66666666666666663) /
          0.33333333333333331 * 30.0;
        samerHARDWARE_B.X = 0.0 - samerHARDWARE_B.activeSlot;
        samerHARDWARE_B.Z = (15.0 - samerHARDWARE_B.activeSlot) + 323.5;
      }
    } else if (shape_id == 7) {
      samerHARDWARE_B.activeSlot = 0.62831853071795862 * samerHARDWARE_B.tau;
      samerHARDWARE_B.X = cos(samerHARDWARE_B.activeSlot) * 25.0;
      samerHARDWARE_B.Y = sin(samerHARDWARE_B.activeSlot) * 25.0;
    } else if (shape_id == 8) {
      samerHARDWARE_B.X = sin(0.62831853071795862 * samerHARDWARE_B.tau) * 15.0;
      samerHARDWARE_B.Y = sin(1.2566370614359172 * samerHARDWARE_B.tau) * 8.0;
      samerHARDWARE_B.Z = cos(1.8849555921538759 * samerHARDWARE_B.tau) * 8.0 +
        323.5;
    } else if (shape_id == 9) {
      samerHARDWARE_B.Z = samerHARDWARE_B.tau / 60.0;
      samerHARDWARE_B.Z -= floor(samerHARDWARE_B.Z);
      samerHARDWARE_B.activeSlot = 1.2566370614359172 * samerHARDWARE_B.tau;
      samerHARDWARE_B.X = samerHARDWARE_B.Z * 30.0 * cos
        (samerHARDWARE_B.activeSlot);
      samerHARDWARE_B.Z = samerHARDWARE_B.Z * 15.0 * sin
        (samerHARDWARE_B.activeSlot) + 323.5;
    } else if (shape_id == 10) {
      samerHARDWARE_B.Z = samerHARDWARE_B.tau / 10.0;
      if ((samerHARDWARE_B.Z <= 0.0) || rtIsNaN(samerHARDWARE_B.Z)) {
        samerHARDWARE_B.Z = 0.0;
      }

      if (samerHARDWARE_B.Z >= 1.0) {
        samerHARDWARE_B.Z = 1.0;
      }

      samerHARDWARE_B.Y = sin(0.94247779607693793 * samerHARDWARE_B.tau) * 0.15
        + 1.0;
      samerHARDWARE_B.activeSlot = 0.31415926535897931 * samerHARDWARE_B.tau;
      samerHARDWARE_B.X = samerHARDWARE_B.Z * 50.0 * samerHARDWARE_B.Y * cos
        (samerHARDWARE_B.activeSlot);
      samerHARDWARE_B.Y = samerHARDWARE_B.Z * 40.0 * samerHARDWARE_B.Y * sin
        (samerHARDWARE_B.activeSlot);
      samerHARDWARE_B.Z = samerHARDWARE_B.Z * 25.0 * sin(0.62831853071795862 *
        samerHARDWARE_B.tau) + 323.5;
    } else if (shape_id == 11) {
      samerHARDWARE_B.Roll = 0.62831853071795862 * samerHARDWARE_B.tau;
      samerHARDWARE_B.activeSlot = sin(samerHARDWARE_B.Roll);
      samerHARDWARE_B.X = 15.0 * samerHARDWARE_B.activeSlot;
      samerHARDWARE_B.Pitch = cos(samerHARDWARE_B.Roll);
      samerHARDWARE_B.Z = 8.0 * samerHARDWARE_B.Pitch + 323.5;
      samerHARDWARE_B.Roll = 0.034906585039886591 * samerHARDWARE_B.activeSlot;
      samerHARDWARE_B.Pitch *= 0.034906585039886591;
    } else if (shape_id == 12) {
      samerHARDWARE_B.activeSlot = sin(0.62831853071795862 * samerHARDWARE_B.tau);
      samerHARDWARE_B.X = 15.0 * samerHARDWARE_B.activeSlot;
      samerHARDWARE_B.Z = sin(1.2566370614359172 * samerHARDWARE_B.tau) * 8.0 +
        323.5;
      samerHARDWARE_B.Yaw = 0.034906585039886591 * samerHARDWARE_B.activeSlot;
    } else if (shape_id == 13) {
      samerHARDWARE_B.activeSlot = 0.62831853071795862 * samerHARDWARE_B.tau;
      samerHARDWARE_B.X = cos(samerHARDWARE_B.activeSlot) * 15.0;
      samerHARDWARE_B.Y = sin(samerHARDWARE_B.activeSlot) * 15.0;
      samerHARDWARE_B.Z = sin(1.2566370614359172 * samerHARDWARE_B.tau) * 8.0 +
        323.5;
    } else if (shape_id == 14) {
      samerHARDWARE_B.X = samerHARDWARE_B.t_traj - floor(samerHARDWARE_B.t_traj /
        90.0) * 90.0;
      if ((samerHARDWARE_B.X <= 0.0) || rtIsNaN(samerHARDWARE_B.X)) {
        samerHARDWARE_B.Z = 0.0;
      } else {
        samerHARDWARE_B.Z = samerHARDWARE_B.X;
      }

      if (samerHARDWARE_B.Z >= 1.0) {
        samerHARDWARE_B.Z = 1.0;
      }

      samerHARDWARE_B.tau = samerHARDWARE_B.X / 90.0;
      samerHARDWARE_B.Y = 18.849555921538759 * samerHARDWARE_B.tau;
      samerHARDWARE_B.activeSlot = samerHARDWARE_B.Z * 40.0;
      samerHARDWARE_B.X = samerHARDWARE_B.activeSlot * cos(samerHARDWARE_B.Y);
      samerHARDWARE_B.Y = samerHARDWARE_B.activeSlot * sin(samerHARDWARE_B.Y);
      samerHARDWARE_B.Z = 50.0 * samerHARDWARE_B.tau + 323.5;
    } else if (shape_id == 15) {
      samerHARDWARE_B.Y = samerHARDWARE_B.t_traj - floor(samerHARDWARE_B.t_traj /
        45.0) * 45.0;
      samerHARDWARE_B.X = floor(samerHARDWARE_B.Y / 11.25);
      samerHARDWARE_B.tau = (samerHARDWARE_B.Y - samerHARDWARE_B.X * 11.25) /
        11.25;
      samerHARDWARE_B.activeSlot = samerHARDWARE_B.tau * samerHARDWARE_B.tau *
        3.0 - 2.0 * rt_powd_snf(samerHARDWARE_B.tau, 3.0);
      if (samerHARDWARE_B.X == 0.0) {
        samerHARDWARE_B.P_start[0] = -40.0;
        P_end_idx_0 = 40;
        samerHARDWARE_B.P_start[1] = -40.0;
        P_end_idx_1 = -40;
        samerHARDWARE_B.P_start[2] = -25.0;
        P_end_idx_2 = 0;
      } else if (samerHARDWARE_B.X == 1.0) {
        samerHARDWARE_B.P_start[0] = 40.0;
        P_end_idx_0 = 40;
        samerHARDWARE_B.P_start[1] = -40.0;
        P_end_idx_1 = 40;
        samerHARDWARE_B.P_start[2] = 0.0;
        P_end_idx_2 = 25;
      } else if (samerHARDWARE_B.X == 2.0) {
        samerHARDWARE_B.P_start[0] = 40.0;
        P_end_idx_0 = -40;
        samerHARDWARE_B.P_start[1] = 40.0;
        P_end_idx_1 = 40;
        samerHARDWARE_B.P_start[2] = 25.0;
        P_end_idx_2 = 0;
      } else {
        samerHARDWARE_B.P_start[0] = -40.0;
        P_end_idx_0 = -40;
        samerHARDWARE_B.P_start[1] = 40.0;
        P_end_idx_1 = -40;
        samerHARDWARE_B.P_start[2] = 0.0;
        P_end_idx_2 = -25;
      }

      samerHARDWARE_B.X = ((real_T)P_end_idx_0 - samerHARDWARE_B.P_start[0]) *
        samerHARDWARE_B.activeSlot + samerHARDWARE_B.P_start[0];
      samerHARDWARE_B.Y = ((real_T)P_end_idx_1 - samerHARDWARE_B.P_start[1]) *
        samerHARDWARE_B.activeSlot + samerHARDWARE_B.P_start[1];
      samerHARDWARE_B.Z = (((real_T)P_end_idx_2 - samerHARDWARE_B.P_start[2]) *
                           samerHARDWARE_B.activeSlot + samerHARDWARE_B.P_start
                           [2]) + 323.5;
    }

    samerHARDWARE_B.u_des[0] = samerHARDWARE_B.X;
    samerHARDWARE_B.u_des[1] = samerHARDWARE_B.Y;
    samerHARDWARE_B.u_des[2] = samerHARDWARE_B.Z;
    samerHARDWARE_B.u_des[3] = samerHARDWARE_B.Roll;
    samerHARDWARE_B.u_des[4] = samerHARDWARE_B.Pitch;
    samerHARDWARE_B.u_des[5] = samerHARDWARE_B.Yaw;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function4' */

  /* MATLAB Function: '<Root>/MATLAB Function' */
  samerHARDWARE_DW.sfEvent_jw = samerHARDWARE_CALL_EVENT_a;
  samerHARDWARE_B.P_start[0] = samerHARDWARE_B.u_des[0];
  samerHARDWARE_B.P_start[1] = samerHARDWARE_B.u_des[1];
  samerHARDWARE_B.P_start[2] = samerHARDWARE_B.u_des[2];
  samerHARDWARE_B.Yaw = cos(samerHARDWARE_B.u_des[5]);
  samerHARDWARE_B.Roll = sin(samerHARDWARE_B.u_des[5]);
  samerHARDWARE_B.Pitch = cos(samerHARDWARE_B.u_des[4]);
  samerHARDWARE_B.X = sin(samerHARDWARE_B.u_des[4]);
  samerHARDWARE_B.Y = cos(samerHARDWARE_B.u_des[3]);
  samerHARDWARE_B.activeSlot = sin(samerHARDWARE_B.u_des[3]);
  samerHARDWARE_B.R[0] = samerHARDWARE_B.Yaw * samerHARDWARE_B.Pitch;
  samerHARDWARE_B.Z = samerHARDWARE_B.Yaw * samerHARDWARE_B.X;
  samerHARDWARE_B.R[3] = samerHARDWARE_B.Z * samerHARDWARE_B.activeSlot -
    samerHARDWARE_B.Roll * samerHARDWARE_B.Y;
  samerHARDWARE_B.R[6] = samerHARDWARE_B.Z * samerHARDWARE_B.Y +
    samerHARDWARE_B.Roll * samerHARDWARE_B.activeSlot;
  samerHARDWARE_B.R[1] = samerHARDWARE_B.Roll * samerHARDWARE_B.Pitch;
  samerHARDWARE_B.Z = samerHARDWARE_B.Roll * samerHARDWARE_B.X;
  samerHARDWARE_B.R[4] = samerHARDWARE_B.Z * samerHARDWARE_B.activeSlot +
    samerHARDWARE_B.Yaw * samerHARDWARE_B.Y;
  samerHARDWARE_B.R[7] = samerHARDWARE_B.Z * samerHARDWARE_B.Y -
    samerHARDWARE_B.Yaw * samerHARDWARE_B.activeSlot;
  samerHARDWARE_B.R[2] = -samerHARDWARE_B.X;
  samerHARDWARE_B.R[5] = samerHARDWARE_B.Pitch * samerHARDWARE_B.activeSlot;
  samerHARDWARE_B.R[8] = samerHARDWARE_B.Pitch * samerHARDWARE_B.Y;

  /* MATLAB Function: '<Root>/MATLAB Function3' */
  samerHARDWARE_DW.sfEvent_j = samerHARDWARE_CALL_EVENT_a;
  for (i = 0; i < 6; i++) {
    /* MATLAB Function: '<Root>/MATLAB Function' */
    samerHARDWARE_B.Yaw = c[i];
    samerHARDWARE_B.b[3 * i] = 185.0 * cos(samerHARDWARE_B.Yaw);
    samerHARDWARE_B.b[3 * i + 1] = 185.0 * sin(samerHARDWARE_B.Yaw);
    samerHARDWARE_B.b[3 * i + 2] = 0.0;
    samerHARDWARE_B.Roll = d[i];
    samerHARDWARE_B.Yaw = 150.0 * cos(samerHARDWARE_B.Roll);
    samerHARDWARE_B.Roll = 150.0 * sin(samerHARDWARE_B.Roll);
    for (shape_id = 0; shape_id < 3; shape_id++) {
      samerHARDWARE_B.L[shape_id] = (((samerHARDWARE_B.R[shape_id + 3] *
        samerHARDWARE_B.Roll + samerHARDWARE_B.Yaw * samerHARDWARE_B.R[shape_id])
        + samerHARDWARE_B.R[shape_id + 6] * 0.0) +
        samerHARDWARE_B.P_start[shape_id]) - samerHARDWARE_B.b[3 * i + shape_id];
    }

    samerHARDWARE_B.Yaw = sqrt((samerHARDWARE_B.L[0] * samerHARDWARE_B.L[0] +
      samerHARDWARE_B.L[1] * samerHARDWARE_B.L[1]) + samerHARDWARE_B.L[2] *
      samerHARDWARE_B.L[2]) - 290.0;
    samerHARDWARE_B.deltaL[i] = samerHARDWARE_B.Yaw;

    /* UnitDelay: '<Root>/Unit Delay' */
    samerHARDWARE_B.UnitDelay[i] = samerHARDWARE_DW.UnitDelay_DSTATE[i];

    /* SignalConversion generated from: '<S3>/ SFunction ' incorporates:
     *  MATLAB Function: '<Root>/MATLAB Function3'
     */
    samerHARDWARE_B.L_cmd_mm[i] = (real32_T)samerHARDWARE_B.Yaw;
  }

  /* MATLABSystem: '<S11>/Analog Input4' */
  samerHARDWARE_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(56UL);
  MW_AnalogInSingle_ReadResult
    (samerHARDWARE_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<S11>/Data Type Conversion10' incorporates:
   *  MATLABSystem: '<S11>/Analog Input4'
   * */
  samerHARDWARE_B.DataTypeConversion10 = b_varargout_1;

  /* Sum: '<S11>/Sum4' incorporates:
   *  Gain: '<S11>/Gain17'
   *  Gain: '<S11>/Gain18'
   *  Gain: '<S11>/Gain19'
   *  UnitDelay: '<S11>/Unit Delay8'
   *  UnitDelay: '<S11>/Unit Delay9'
   */
  samerHARDWARE_B.Sum4 = (samerHARDWARE_P.Gain18_Gain *
    samerHARDWARE_DW.UnitDelay8_DSTATE + samerHARDWARE_P.Gain17_Gain *
    samerHARDWARE_B.DataTypeConversion10) + samerHARDWARE_P.Gain19_Gain *
    samerHARDWARE_DW.UnitDelay9_DSTATE;

  /* Gain: '<S11>/Gain16' */
  samerHARDWARE_B.Gain16 = samerHARDWARE_P.Gain16_Gain * samerHARDWARE_B.Sum4;

  /* Sum: '<S9>/Add1' */
  samerHARDWARE_B.Add1 = samerHARDWARE_B.L_cmd_mm[4] - samerHARDWARE_B.Gain16;
  for (i = 0; i < 6; i++) {
    /* Reshape: '<Root>/Reshape1' */
    samerHARDWARE_B.Reshape1[i] = samerHARDWARE_B.u_des[i];
  }

  /* MATLABSystem: '<S11>/Analog Input' */
  samerHARDWARE_DW.obj_ic.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(54UL);
  MW_AnalogInSingle_ReadResult
    (samerHARDWARE_DW.obj_ic.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  MATLABSystem: '<S11>/Analog Input'
   * */
  samerHARDWARE_B.DataTypeConversion3 = b_varargout_1;

  /* Sum: '<S11>/Sum' incorporates:
   *  Gain: '<S11>/Gain1'
   *  Gain: '<S11>/Gain2'
   *  Gain: '<S11>/Gain3'
   *  UnitDelay: '<S11>/Unit Delay'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  samerHARDWARE_B.Sum = (samerHARDWARE_P.Gain2_Gain *
    samerHARDWARE_DW.UnitDelay_DSTATE_a + samerHARDWARE_P.Gain1_Gain *
    samerHARDWARE_B.DataTypeConversion3) + samerHARDWARE_P.Gain3_Gain *
    samerHARDWARE_DW.UnitDelay1_DSTATE;

  /* Gain: '<S11>/Gain' */
  samerHARDWARE_B.Gain = samerHARDWARE_P.Gain_Gain * samerHARDWARE_B.Sum;

  /* Sum: '<S5>/Add1' */
  samerHARDWARE_B.Add1_d = samerHARDWARE_B.L_cmd_mm[0] - samerHARDWARE_B.Gain;

  /* MATLABSystem: '<S11>/Analog Input1' */
  samerHARDWARE_DW.obj_o.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(59UL);
  MW_AnalogInSingle_ReadResult
    (samerHARDWARE_DW.obj_o.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<S11>/Data Type Conversion4' incorporates:
   *  MATLABSystem: '<S11>/Analog Input1'
   * */
  samerHARDWARE_B.DataTypeConversion4 = b_varargout_1;

  /* Sum: '<S11>/Sum1' incorporates:
   *  Gain: '<S11>/Gain5'
   *  Gain: '<S11>/Gain6'
   *  Gain: '<S11>/Gain7'
   *  UnitDelay: '<S11>/Unit Delay2'
   *  UnitDelay: '<S11>/Unit Delay3'
   */
  samerHARDWARE_B.Sum1 = (samerHARDWARE_P.Gain6_Gain *
    samerHARDWARE_DW.UnitDelay2_DSTATE + samerHARDWARE_P.Gain5_Gain *
    samerHARDWARE_B.DataTypeConversion4) + samerHARDWARE_P.Gain7_Gain *
    samerHARDWARE_DW.UnitDelay3_DSTATE;

  /* Gain: '<S11>/Gain4' */
  samerHARDWARE_B.Gain4 = samerHARDWARE_P.Gain4_Gain * samerHARDWARE_B.Sum1;

  /* Sum: '<S6>/Add1' */
  samerHARDWARE_B.Add1_e = samerHARDWARE_B.L_cmd_mm[1] - samerHARDWARE_B.Gain4;

  /* MATLABSystem: '<S11>/Analog Input2' */
  samerHARDWARE_DW.obj_m.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(58UL);
  MW_AnalogInSingle_ReadResult
    (samerHARDWARE_DW.obj_m.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<S11>/Data Type Conversion6' incorporates:
   *  MATLABSystem: '<S11>/Analog Input2'
   * */
  samerHARDWARE_B.DataTypeConversion6 = b_varargout_1;

  /* Sum: '<S11>/Sum2' incorporates:
   *  Gain: '<S11>/Gain10'
   *  Gain: '<S11>/Gain11'
   *  Gain: '<S11>/Gain9'
   *  UnitDelay: '<S11>/Unit Delay4'
   *  UnitDelay: '<S11>/Unit Delay5'
   */
  samerHARDWARE_B.Sum2 = (samerHARDWARE_P.Gain10_Gain *
    samerHARDWARE_DW.UnitDelay4_DSTATE + samerHARDWARE_P.Gain9_Gain *
    samerHARDWARE_B.DataTypeConversion6) + samerHARDWARE_P.Gain11_Gain *
    samerHARDWARE_DW.UnitDelay5_DSTATE;

  /* Gain: '<S11>/Gain8' */
  samerHARDWARE_B.Gain8 = samerHARDWARE_P.Gain8_Gain * samerHARDWARE_B.Sum2;

  /* Sum: '<S7>/Add1' */
  samerHARDWARE_B.Add1_eq = samerHARDWARE_B.L_cmd_mm[2] - samerHARDWARE_B.Gain8;

  /* MATLABSystem: '<S11>/Analog Input3' */
  samerHARDWARE_DW.obj_i3.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(57UL);
  MW_AnalogInSingle_ReadResult
    (samerHARDWARE_DW.obj_i3.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<S11>/Data Type Conversion8' incorporates:
   *  MATLABSystem: '<S11>/Analog Input3'
   * */
  samerHARDWARE_B.DataTypeConversion8 = b_varargout_1;

  /* Sum: '<S11>/Sum3' incorporates:
   *  Gain: '<S11>/Gain13'
   *  Gain: '<S11>/Gain14'
   *  Gain: '<S11>/Gain15'
   *  UnitDelay: '<S11>/Unit Delay6'
   *  UnitDelay: '<S11>/Unit Delay7'
   */
  samerHARDWARE_B.Sum3 = (samerHARDWARE_P.Gain14_Gain *
    samerHARDWARE_DW.UnitDelay6_DSTATE + samerHARDWARE_P.Gain13_Gain *
    samerHARDWARE_B.DataTypeConversion8) + samerHARDWARE_P.Gain15_Gain *
    samerHARDWARE_DW.UnitDelay7_DSTATE;

  /* Gain: '<S11>/Gain12' */
  samerHARDWARE_B.Gain12 = samerHARDWARE_P.Gain12_Gain * samerHARDWARE_B.Sum3;

  /* Sum: '<S8>/Add1' */
  samerHARDWARE_B.Add1_a = samerHARDWARE_B.L_cmd_mm[3] - samerHARDWARE_B.Gain12;

  /* MATLABSystem: '<S11>/Analog Input5' */
  samerHARDWARE_DW.obj_na.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(55UL);
  MW_AnalogInSingle_ReadResult
    (samerHARDWARE_DW.obj_na.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<S11>/Data Type Conversion11' incorporates:
   *  MATLABSystem: '<S11>/Analog Input5'
   * */
  samerHARDWARE_B.DataTypeConversion11 = b_varargout_1;

  /* Sum: '<S11>/Sum5' incorporates:
   *  Gain: '<S11>/Gain21'
   *  Gain: '<S11>/Gain22'
   *  Gain: '<S11>/Gain23'
   *  UnitDelay: '<S11>/Unit Delay10'
   *  UnitDelay: '<S11>/Unit Delay11'
   */
  samerHARDWARE_B.Sum5 = (samerHARDWARE_P.Gain22_Gain *
    samerHARDWARE_DW.UnitDelay10_DSTATE + samerHARDWARE_P.Gain21_Gain *
    samerHARDWARE_B.DataTypeConversion11) + samerHARDWARE_P.Gain23_Gain *
    samerHARDWARE_DW.UnitDelay11_DSTATE;

  /* Gain: '<S11>/Gain20' */
  samerHARDWARE_B.Gain20 = samerHARDWARE_P.Gain20_Gain * samerHARDWARE_B.Sum5;

  /* Sum: '<S10>/Add1' */
  samerHARDWARE_B.Add1_f = samerHARDWARE_B.L_cmd_mm[5] - samerHARDWARE_B.Gain20;
  if (samerHARDWARE_M->Timing.TaskCounters.TID[2] == 0) {
    /* SignalConversion generated from: '<Root>/To Workspace2' */
    samerHARDWARE_B.TmpSignalConversionAt_asyncqueu[0] = samerHARDWARE_B.t_traj;
    for (i = 0; i < 6; i++) {
      samerHARDWARE_B.TmpSignalConversionAt_asyncqueu[i + 1] =
        samerHARDWARE_B.Reshape1[i];
      samerHARDWARE_B.TmpSignalConversionAt_asyncqueu[i + 7] =
        samerHARDWARE_B.deltaL[i];
      samerHARDWARE_B.TmpSignalConversionAt_asyncqueu[i + 13] =
        samerHARDWARE_B.UnitDelay[i];
    }

    samerHARDWARE_B.TmpSignalConversionAt_asyncqueu[19] = samerHARDWARE_B.Add1_d;
    samerHARDWARE_B.TmpSignalConversionAt_asyncqueu[20] = samerHARDWARE_B.Add1_e;
    samerHARDWARE_B.TmpSignalConversionAt_asyncqueu[21] =
      samerHARDWARE_B.Add1_eq;
    samerHARDWARE_B.TmpSignalConversionAt_asyncqueu[22] = samerHARDWARE_B.Add1_a;
    samerHARDWARE_B.TmpSignalConversionAt_asyncqueu[23] = samerHARDWARE_B.Add1;
    samerHARDWARE_B.TmpSignalConversionAt_asyncqueu[24] = samerHARDWARE_B.Add1_f;

    /* End of SignalConversion generated from: '<Root>/To Workspace2' */
  }

  /* Sum: '<S10>/Add' */
  samerHARDWARE_B.Add = samerHARDWARE_B.L_cmd_mm[5] - samerHARDWARE_B.Gain20;

  /* MATLAB Function: '<S10>/MATLAB Function' */
  samerHARDWARE_MATLABFunction(samerHARDWARE_B.Add,
    &samerHARDWARE_B.sf_MATLABFunction_b, &samerHARDWARE_DW.sf_MATLABFunction_b);

  /* Abs: '<S10>/Abs4' */
  samerHARDWARE_B.Abs4 = fabs(samerHARDWARE_B.Add);

  /* SampleTimeMath: '<S335>/Tsamp' incorporates:
   *  Gain: '<S331>/Derivative Gain'
   *
   * About '<S335>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  samerHARDWARE_B.Tsamp = samerHARDWARE_P.DiscretePIDController1_D *
    samerHARDWARE_B.Abs4 * samerHARDWARE_P.Tsamp_WtEt;

  /* Sum: '<S349>/Sum' incorporates:
   *  Delay: '<S333>/UD'
   *  DiscreteIntegrator: '<S340>/Integrator'
   *  Gain: '<S345>/Proportional Gain'
   *  Sum: '<S333>/Diff'
   */
  samerHARDWARE_B.Saturation1 = (samerHARDWARE_P.DiscretePIDController1_P *
    samerHARDWARE_B.Abs4 + samerHARDWARE_DW.Integrator_DSTATE) +
    (samerHARDWARE_B.Tsamp - samerHARDWARE_DW.UD_DSTATE);

  /* Saturate: '<S10>/Saturation1' */
  if (samerHARDWARE_B.Saturation1 > samerHARDWARE_P.Saturation1_UpperSat) {
    /* Sum: '<S349>/Sum' incorporates:
     *  Saturate: '<S10>/Saturation1'
     */
    samerHARDWARE_B.Saturation1 = samerHARDWARE_P.Saturation1_UpperSat;
  } else if (samerHARDWARE_B.Saturation1 < samerHARDWARE_P.Saturation1_LowerSat)
  {
    /* Sum: '<S349>/Sum' incorporates:
     *  Saturate: '<S10>/Saturation1'
     */
    samerHARDWARE_B.Saturation1 = samerHARDWARE_P.Saturation1_LowerSat;
  }

  /* End of Saturate: '<S10>/Saturation1' */

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   */
  if (samerHARDWARE_B.Abs4 > samerHARDWARE_P.Switch_Threshold) {
    samerHARDWARE_B.Yaw = samerHARDWARE_P.Constant_Value_d;
  } else {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.Saturation1;
  }

  /* Gain: '<S10>/Gain4' incorporates:
   *  Switch: '<S10>/Switch'
   */
  samerHARDWARE_B.Gain4_c = samerHARDWARE_P.Gain4_Gain_d * samerHARDWARE_B.Yaw;

  /* MATLAB Function: '<S10>/MATLAB Function1' */
  samerHARDWARE_MATLABFunction1(samerHARDWARE_B.sf_MATLABFunction_b.y,
    samerHARDWARE_B.Gain4_c, &samerHARDWARE_B.sf_MATLABFunction1_i3,
    &samerHARDWARE_DW.sf_MATLABFunction1_i3);

  /* MATLABSystem: '<S10>/PWM2' */
  samerHARDWARE_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);

  /* Start for MATLABSystem: '<S10>/PWM2' */
  if (samerHARDWARE_B.sf_MATLABFunction1_i3.y <= 255.0) {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.sf_MATLABFunction1_i3.y;
  } else {
    samerHARDWARE_B.Yaw = 255.0;
  }

  if (!(samerHARDWARE_B.Yaw >= 0.0)) {
    samerHARDWARE_B.Yaw = 0.0;
  }

  /* MATLABSystem: '<S10>/PWM2' */
  MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWARE_B.Yaw);

  /* MATLAB Function: '<S10>/MATLAB Function2' */
  samerHARDWARE_MATLABFunction1(samerHARDWARE_B.sf_MATLABFunction_b.x,
    samerHARDWARE_B.Gain4_c, &samerHARDWARE_B.sf_MATLABFunction2_h,
    &samerHARDWARE_DW.sf_MATLABFunction2_h);

  /* MATLABSystem: '<S10>/PWM3' */
  samerHARDWARE_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7UL);

  /* Start for MATLABSystem: '<S10>/PWM3' */
  if (samerHARDWARE_B.sf_MATLABFunction2_h.y <= 255.0) {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.sf_MATLABFunction2_h.y;
  } else {
    samerHARDWARE_B.Yaw = 255.0;
  }

  if (!(samerHARDWARE_B.Yaw >= 0.0)) {
    samerHARDWARE_B.Yaw = 0.0;
  }

  /* MATLABSystem: '<S10>/PWM3' */
  MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWARE_B.Yaw);

  /* Gain: '<S337>/Integral Gain' */
  samerHARDWARE_B.IntegralGain = samerHARDWARE_P.DiscretePIDController1_I *
    samerHARDWARE_B.Abs4;

  /* Sum: '<S8>/Add' */
  samerHARDWARE_B.Add_mb = samerHARDWARE_B.L_cmd_mm[3] - samerHARDWARE_B.Gain12;

  /* MATLAB Function: '<S8>/MATLAB Function' */
  samerHARDWARE_MATLABFunction(samerHARDWARE_B.Add_mb,
    &samerHARDWARE_B.sf_MATLABFunction_m, &samerHARDWARE_DW.sf_MATLABFunction_m);

  /* Abs: '<S8>/Abs4' */
  samerHARDWARE_B.Abs4_n = fabs(samerHARDWARE_B.Add_mb);

  /* SampleTimeMath: '<S219>/Tsamp' incorporates:
   *  Gain: '<S215>/Derivative Gain'
   *
   * About '<S219>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  samerHARDWARE_B.Tsamp_a = samerHARDWARE_P.DiscretePIDController1_D_c *
    samerHARDWARE_B.Abs4_n * samerHARDWARE_P.Tsamp_WtEt_o;

  /* Sum: '<S233>/Sum' incorporates:
   *  Delay: '<S217>/UD'
   *  DiscreteIntegrator: '<S224>/Integrator'
   *  Gain: '<S229>/Proportional Gain'
   *  Sum: '<S217>/Diff'
   */
  samerHARDWARE_B.Saturation1_g = (samerHARDWARE_P.DiscretePIDController1_P_f *
    samerHARDWARE_B.Abs4_n + samerHARDWARE_DW.Integrator_DSTATE_f) +
    (samerHARDWARE_B.Tsamp_a - samerHARDWARE_DW.UD_DSTATE_n);

  /* Saturate: '<S8>/Saturation1' */
  if (samerHARDWARE_B.Saturation1_g > samerHARDWARE_P.Saturation1_UpperSat_b) {
    /* Sum: '<S233>/Sum' incorporates:
     *  Saturate: '<S8>/Saturation1'
     */
    samerHARDWARE_B.Saturation1_g = samerHARDWARE_P.Saturation1_UpperSat_b;
  } else if (samerHARDWARE_B.Saturation1_g <
             samerHARDWARE_P.Saturation1_LowerSat_n) {
    /* Sum: '<S233>/Sum' incorporates:
     *  Saturate: '<S8>/Saturation1'
     */
    samerHARDWARE_B.Saturation1_g = samerHARDWARE_P.Saturation1_LowerSat_n;
  }

  /* End of Saturate: '<S8>/Saturation1' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant'
   */
  if (samerHARDWARE_B.Abs4_n > samerHARDWARE_P.Switch_Threshold_e) {
    samerHARDWARE_B.Yaw = samerHARDWARE_P.Constant_Value_i;
  } else {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.Saturation1_g;
  }

  /* Gain: '<S8>/Gain4' incorporates:
   *  Switch: '<S8>/Switch'
   */
  samerHARDWARE_B.Gain4_m = samerHARDWARE_P.Gain4_Gain_dn * samerHARDWARE_B.Yaw;

  /* MATLAB Function: '<S8>/MATLAB Function1' */
  samerHARDWARE_MATLABFunction1(samerHARDWARE_B.sf_MATLABFunction_m.y,
    samerHARDWARE_B.Gain4_m, &samerHARDWARE_B.sf_MATLABFunction1_g,
    &samerHARDWARE_DW.sf_MATLABFunction1_g);

  /* MATLABSystem: '<S8>/PWM2' */
  samerHARDWARE_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);

  /* Start for MATLABSystem: '<S8>/PWM2' */
  if (samerHARDWARE_B.sf_MATLABFunction1_g.y <= 255.0) {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.sf_MATLABFunction1_g.y;
  } else {
    samerHARDWARE_B.Yaw = 255.0;
  }

  if (!(samerHARDWARE_B.Yaw >= 0.0)) {
    samerHARDWARE_B.Yaw = 0.0;
  }

  /* MATLABSystem: '<S8>/PWM2' */
  MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWARE_B.Yaw);

  /* MATLAB Function: '<S8>/MATLAB Function2' */
  samerHARDWARE_MATLABFunction1(samerHARDWARE_B.sf_MATLABFunction_m.x,
    samerHARDWARE_B.Gain4_m, &samerHARDWARE_B.sf_MATLABFunction2_e,
    &samerHARDWARE_DW.sf_MATLABFunction2_e);

  /* MATLABSystem: '<S8>/PWM3' */
  samerHARDWARE_DW.obj_nt.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(13UL);

  /* Start for MATLABSystem: '<S8>/PWM3' */
  if (samerHARDWARE_B.sf_MATLABFunction2_e.y <= 255.0) {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.sf_MATLABFunction2_e.y;
  } else {
    samerHARDWARE_B.Yaw = 255.0;
  }

  if (!(samerHARDWARE_B.Yaw >= 0.0)) {
    samerHARDWARE_B.Yaw = 0.0;
  }

  /* MATLABSystem: '<S8>/PWM3' */
  MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_nt.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWARE_B.Yaw);

  /* Gain: '<S221>/Integral Gain' */
  samerHARDWARE_B.IntegralGain_b = samerHARDWARE_P.DiscretePIDController1_I_l *
    samerHARDWARE_B.Abs4_n;

  /* Sum: '<S7>/Add' */
  samerHARDWARE_B.Add_c = samerHARDWARE_B.L_cmd_mm[2] - samerHARDWARE_B.Gain8;

  /* MATLAB Function: '<S7>/MATLAB Function' */
  samerHARDWARE_MATLABFunction(samerHARDWARE_B.Add_c,
    &samerHARDWARE_B.sf_MATLABFunction_hb,
    &samerHARDWARE_DW.sf_MATLABFunction_hb);

  /* Abs: '<S7>/Abs4' */
  samerHARDWARE_B.Abs4_m = fabs(samerHARDWARE_B.Add_c);

  /* SampleTimeMath: '<S161>/Tsamp' incorporates:
   *  Gain: '<S157>/Derivative Gain'
   *
   * About '<S161>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  samerHARDWARE_B.Tsamp_j = samerHARDWARE_P.DiscretePIDController1_D_a *
    samerHARDWARE_B.Abs4_m * samerHARDWARE_P.Tsamp_WtEt_d;

  /* Sum: '<S175>/Sum' incorporates:
   *  Delay: '<S159>/UD'
   *  DiscreteIntegrator: '<S166>/Integrator'
   *  Gain: '<S171>/Proportional Gain'
   *  Sum: '<S159>/Diff'
   */
  samerHARDWARE_B.Saturation1_p = (samerHARDWARE_P.DiscretePIDController1_P_o *
    samerHARDWARE_B.Abs4_m + samerHARDWARE_DW.Integrator_DSTATE_g) +
    (samerHARDWARE_B.Tsamp_j - samerHARDWARE_DW.UD_DSTATE_b);

  /* Saturate: '<S7>/Saturation1' */
  if (samerHARDWARE_B.Saturation1_p > samerHARDWARE_P.Saturation1_UpperSat_k) {
    /* Sum: '<S175>/Sum' incorporates:
     *  Saturate: '<S7>/Saturation1'
     */
    samerHARDWARE_B.Saturation1_p = samerHARDWARE_P.Saturation1_UpperSat_k;
  } else if (samerHARDWARE_B.Saturation1_p <
             samerHARDWARE_P.Saturation1_LowerSat_b) {
    /* Sum: '<S175>/Sum' incorporates:
     *  Saturate: '<S7>/Saturation1'
     */
    samerHARDWARE_B.Saturation1_p = samerHARDWARE_P.Saturation1_LowerSat_b;
  }

  /* End of Saturate: '<S7>/Saturation1' */

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if (samerHARDWARE_B.Abs4_m > samerHARDWARE_P.Switch_Threshold_d) {
    samerHARDWARE_B.Yaw = samerHARDWARE_P.Constant_Value_o;
  } else {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.Saturation1_p;
  }

  /* Gain: '<S7>/Gain4' incorporates:
   *  Switch: '<S7>/Switch'
   */
  samerHARDWARE_B.Gain4_o = samerHARDWARE_P.Gain4_Gain_h * samerHARDWARE_B.Yaw;

  /* MATLAB Function: '<S7>/MATLAB Function1' */
  samerHARDWARE_MATLABFunction1(samerHARDWARE_B.sf_MATLABFunction_hb.y,
    samerHARDWARE_B.Gain4_o, &samerHARDWARE_B.sf_MATLABFunction1_k,
    &samerHARDWARE_DW.sf_MATLABFunction1_k);

  /* MATLABSystem: '<S7>/PWM2' */
  samerHARDWARE_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

  /* Start for MATLABSystem: '<S7>/PWM2' */
  if (samerHARDWARE_B.sf_MATLABFunction1_k.y <= 255.0) {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.sf_MATLABFunction1_k.y;
  } else {
    samerHARDWARE_B.Yaw = 255.0;
  }

  if (!(samerHARDWARE_B.Yaw >= 0.0)) {
    samerHARDWARE_B.Yaw = 0.0;
  }

  /* MATLABSystem: '<S7>/PWM2' */
  MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWARE_B.Yaw);

  /* MATLAB Function: '<S7>/MATLAB Function2' */
  samerHARDWARE_MATLABFunction1(samerHARDWARE_B.sf_MATLABFunction_hb.x,
    samerHARDWARE_B.Gain4_o, &samerHARDWARE_B.sf_MATLABFunction2_mw,
    &samerHARDWARE_DW.sf_MATLABFunction2_mw);

  /* MATLABSystem: '<S7>/PWM3' */
  samerHARDWARE_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

  /* Start for MATLABSystem: '<S7>/PWM3' */
  if (samerHARDWARE_B.sf_MATLABFunction2_mw.y <= 255.0) {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.sf_MATLABFunction2_mw.y;
  } else {
    samerHARDWARE_B.Yaw = 255.0;
  }

  if (!(samerHARDWARE_B.Yaw >= 0.0)) {
    samerHARDWARE_B.Yaw = 0.0;
  }

  /* MATLABSystem: '<S7>/PWM3' */
  MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWARE_B.Yaw);

  /* Gain: '<S163>/Integral Gain' */
  samerHARDWARE_B.IntegralGain_e = samerHARDWARE_P.DiscretePIDController1_I_i *
    samerHARDWARE_B.Abs4_m;

  /* Sum: '<S6>/Add' */
  samerHARDWARE_B.Add_l = samerHARDWARE_B.L_cmd_mm[1] - samerHARDWARE_B.Gain4;

  /* MATLAB Function: '<S6>/MATLAB Function' */
  samerHARDWARE_MATLABFunction(samerHARDWARE_B.Add_l,
    &samerHARDWARE_B.sf_MATLABFunction_d, &samerHARDWARE_DW.sf_MATLABFunction_d);

  /* Abs: '<S6>/Abs4' */
  samerHARDWARE_B.Abs4_c = fabs(samerHARDWARE_B.Add_l);

  /* SampleTimeMath: '<S103>/Tsamp' incorporates:
   *  Gain: '<S99>/Derivative Gain'
   *
   * About '<S103>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  samerHARDWARE_B.Tsamp_m = samerHARDWARE_P.DiscretePIDController1_D_k *
    samerHARDWARE_B.Abs4_c * samerHARDWARE_P.Tsamp_WtEt_b;

  /* Sum: '<S117>/Sum' incorporates:
   *  Delay: '<S101>/UD'
   *  DiscreteIntegrator: '<S108>/Integrator'
   *  Gain: '<S113>/Proportional Gain'
   *  Sum: '<S101>/Diff'
   */
  samerHARDWARE_B.Saturation1_i = (samerHARDWARE_P.DiscretePIDController1_P_e *
    samerHARDWARE_B.Abs4_c + samerHARDWARE_DW.Integrator_DSTATE_j) +
    (samerHARDWARE_B.Tsamp_m - samerHARDWARE_DW.UD_DSTATE_a);

  /* Saturate: '<S6>/Saturation1' */
  if (samerHARDWARE_B.Saturation1_i > samerHARDWARE_P.Saturation1_UpperSat_j) {
    /* Sum: '<S117>/Sum' incorporates:
     *  Saturate: '<S6>/Saturation1'
     */
    samerHARDWARE_B.Saturation1_i = samerHARDWARE_P.Saturation1_UpperSat_j;
  } else if (samerHARDWARE_B.Saturation1_i <
             samerHARDWARE_P.Saturation1_LowerSat_j) {
    /* Sum: '<S117>/Sum' incorporates:
     *  Saturate: '<S6>/Saturation1'
     */
    samerHARDWARE_B.Saturation1_i = samerHARDWARE_P.Saturation1_LowerSat_j;
  }

  /* End of Saturate: '<S6>/Saturation1' */

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   */
  if (samerHARDWARE_B.Abs4_c > samerHARDWARE_P.Switch_Threshold_n) {
    samerHARDWARE_B.Yaw = samerHARDWARE_P.Constant_Value_k;
  } else {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.Saturation1_i;
  }

  /* Gain: '<S6>/Gain4' incorporates:
   *  Switch: '<S6>/Switch'
   */
  samerHARDWARE_B.Gain4_g = samerHARDWARE_P.Gain4_Gain_k * samerHARDWARE_B.Yaw;

  /* MATLAB Function: '<S6>/MATLAB Function1' */
  samerHARDWARE_MATLABFunction1(samerHARDWARE_B.sf_MATLABFunction_d.y,
    samerHARDWARE_B.Gain4_g, &samerHARDWARE_B.sf_MATLABFunction1_h,
    &samerHARDWARE_DW.sf_MATLABFunction1_h);

  /* MATLABSystem: '<S6>/PWM2' */
  samerHARDWARE_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);

  /* Start for MATLABSystem: '<S6>/PWM2' */
  if (samerHARDWARE_B.sf_MATLABFunction1_h.y <= 255.0) {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.sf_MATLABFunction1_h.y;
  } else {
    samerHARDWARE_B.Yaw = 255.0;
  }

  if (!(samerHARDWARE_B.Yaw >= 0.0)) {
    samerHARDWARE_B.Yaw = 0.0;
  }

  /* MATLABSystem: '<S6>/PWM2' */
  MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWARE_B.Yaw);

  /* MATLAB Function: '<S6>/MATLAB Function2' */
  samerHARDWARE_MATLABFunction1(samerHARDWARE_B.sf_MATLABFunction_d.x,
    samerHARDWARE_B.Gain4_g, &samerHARDWARE_B.sf_MATLABFunction2_o,
    &samerHARDWARE_DW.sf_MATLABFunction2_o);

  /* MATLABSystem: '<S6>/PWM3' */
  samerHARDWARE_DW.obj_lt.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Start for MATLABSystem: '<S6>/PWM3' */
  if (samerHARDWARE_B.sf_MATLABFunction2_o.y <= 255.0) {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.sf_MATLABFunction2_o.y;
  } else {
    samerHARDWARE_B.Yaw = 255.0;
  }

  if (!(samerHARDWARE_B.Yaw >= 0.0)) {
    samerHARDWARE_B.Yaw = 0.0;
  }

  /* MATLABSystem: '<S6>/PWM3' */
  MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_lt.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWARE_B.Yaw);

  /* Gain: '<S105>/Integral Gain' */
  samerHARDWARE_B.IntegralGain_ev = samerHARDWARE_P.DiscretePIDController1_I_f *
    samerHARDWARE_B.Abs4_c;

  /* Sum: '<S5>/Add' */
  samerHARDWARE_B.Add_o = samerHARDWARE_B.L_cmd_mm[0] - samerHARDWARE_B.Gain;

  /* MATLAB Function: '<S5>/MATLAB Function' */
  samerHARDWARE_MATLABFunction(samerHARDWARE_B.Add_o,
    &samerHARDWARE_B.sf_MATLABFunction_h, &samerHARDWARE_DW.sf_MATLABFunction_h);

  /* Abs: '<S5>/Abs4' */
  samerHARDWARE_B.Abs4_d = fabs(samerHARDWARE_B.Add_o);

  /* Gain: '<S53>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S45>/Filter'
   *  Gain: '<S43>/Derivative Gain'
   *  Sum: '<S45>/SumD'
   */
  samerHARDWARE_B.FilterCoefficient =
    (samerHARDWARE_P.DiscretePIDController1_D_e * samerHARDWARE_B.Abs4_d -
     samerHARDWARE_DW.Filter_DSTATE) * samerHARDWARE_P.DiscretePIDController1_N;

  /* Sum: '<S59>/Sum' incorporates:
   *  DiscreteIntegrator: '<S50>/Integrator'
   *  Gain: '<S55>/Proportional Gain'
   */
  samerHARDWARE_B.Saturation1_k = (samerHARDWARE_P.DiscretePIDController1_P_a *
    samerHARDWARE_B.Abs4_d + samerHARDWARE_DW.Integrator_DSTATE_c) +
    samerHARDWARE_B.FilterCoefficient;

  /* Saturate: '<S5>/Saturation1' */
  if (samerHARDWARE_B.Saturation1_k > samerHARDWARE_P.Saturation1_UpperSat_c) {
    /* Sum: '<S59>/Sum' incorporates:
     *  Saturate: '<S5>/Saturation1'
     */
    samerHARDWARE_B.Saturation1_k = samerHARDWARE_P.Saturation1_UpperSat_c;
  } else if (samerHARDWARE_B.Saturation1_k <
             samerHARDWARE_P.Saturation1_LowerSat_d) {
    /* Sum: '<S59>/Sum' incorporates:
     *  Saturate: '<S5>/Saturation1'
     */
    samerHARDWARE_B.Saturation1_k = samerHARDWARE_P.Saturation1_LowerSat_d;
  }

  /* End of Saturate: '<S5>/Saturation1' */

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant'
   */
  if (samerHARDWARE_B.Abs4_d > samerHARDWARE_P.Switch_Threshold_a) {
    samerHARDWARE_B.Yaw = samerHARDWARE_P.Constant_Value_c;
  } else {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.Saturation1_k;
  }

  /* Gain: '<S5>/Gain4' incorporates:
   *  Switch: '<S5>/Switch'
   */
  samerHARDWARE_B.Gain4_d = samerHARDWARE_P.Gain4_Gain_i * samerHARDWARE_B.Yaw;

  /* MATLAB Function: '<S5>/MATLAB Function1' */
  samerHARDWARE_MATLABFunction1(samerHARDWARE_B.sf_MATLABFunction_h.y,
    samerHARDWARE_B.Gain4_d, &samerHARDWARE_B.sf_MATLABFunction1,
    &samerHARDWARE_DW.sf_MATLABFunction1);

  /* MATLABSystem: '<S5>/PWM2' */
  samerHARDWARE_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2UL);

  /* Start for MATLABSystem: '<S5>/PWM2' */
  if (samerHARDWARE_B.sf_MATLABFunction1.y <= 255.0) {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.sf_MATLABFunction1.y;
  } else {
    samerHARDWARE_B.Yaw = 255.0;
  }

  if (!(samerHARDWARE_B.Yaw >= 0.0)) {
    samerHARDWARE_B.Yaw = 0.0;
  }

  /* MATLABSystem: '<S5>/PWM2' */
  MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWARE_B.Yaw);

  /* MATLAB Function: '<S5>/MATLAB Function2' */
  samerHARDWARE_MATLABFunction1(samerHARDWARE_B.sf_MATLABFunction_h.x,
    samerHARDWARE_B.Gain4_d, &samerHARDWARE_B.sf_MATLABFunction2_m,
    &samerHARDWARE_DW.sf_MATLABFunction2_m);

  /* MATLABSystem: '<S5>/PWM3' */
  samerHARDWARE_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3UL);

  /* Start for MATLABSystem: '<S5>/PWM3' */
  if (samerHARDWARE_B.sf_MATLABFunction2_m.y <= 255.0) {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.sf_MATLABFunction2_m.y;
  } else {
    samerHARDWARE_B.Yaw = 255.0;
  }

  if (!(samerHARDWARE_B.Yaw >= 0.0)) {
    samerHARDWARE_B.Yaw = 0.0;
  }

  /* MATLABSystem: '<S5>/PWM3' */
  MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWARE_B.Yaw);

  /* Gain: '<S47>/Integral Gain' */
  samerHARDWARE_B.IntegralGain_i = samerHARDWARE_P.DiscretePIDController1_I_m *
    samerHARDWARE_B.Abs4_d;

  /* Sum: '<S9>/Add' */
  samerHARDWARE_B.Add_m = samerHARDWARE_B.L_cmd_mm[4] - samerHARDWARE_B.Gain16;

  /* MATLAB Function: '<S9>/MATLAB Function' */
  samerHARDWARE_MATLABFunction(samerHARDWARE_B.Add_m,
    &samerHARDWARE_B.sf_MATLABFunction_dw,
    &samerHARDWARE_DW.sf_MATLABFunction_dw);

  /* Abs: '<S9>/Abs4' */
  samerHARDWARE_B.Abs4_ns = fabs(samerHARDWARE_B.Add_m);

  /* SampleTimeMath: '<S277>/Tsamp' incorporates:
   *  Gain: '<S273>/Derivative Gain'
   *
   * About '<S277>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  samerHARDWARE_B.Tsamp_b = samerHARDWARE_P.DiscretePIDController1_D_cj *
    samerHARDWARE_B.Abs4_ns * samerHARDWARE_P.Tsamp_WtEt_a;

  /* Sum: '<S291>/Sum' incorporates:
   *  Delay: '<S275>/UD'
   *  DiscreteIntegrator: '<S282>/Integrator'
   *  Gain: '<S287>/Proportional Gain'
   *  Sum: '<S275>/Diff'
   */
  samerHARDWARE_B.Saturation1_a = (samerHARDWARE_P.DiscretePIDController1_P_fd *
    samerHARDWARE_B.Abs4_ns + samerHARDWARE_DW.Integrator_DSTATE_fp) +
    (samerHARDWARE_B.Tsamp_b - samerHARDWARE_DW.UD_DSTATE_o);

  /* Saturate: '<S9>/Saturation1' */
  if (samerHARDWARE_B.Saturation1_a > samerHARDWARE_P.Saturation1_UpperSat_i) {
    /* Sum: '<S291>/Sum' incorporates:
     *  Saturate: '<S9>/Saturation1'
     */
    samerHARDWARE_B.Saturation1_a = samerHARDWARE_P.Saturation1_UpperSat_i;
  } else if (samerHARDWARE_B.Saturation1_a <
             samerHARDWARE_P.Saturation1_LowerSat_f) {
    /* Sum: '<S291>/Sum' incorporates:
     *  Saturate: '<S9>/Saturation1'
     */
    samerHARDWARE_B.Saturation1_a = samerHARDWARE_P.Saturation1_LowerSat_f;
  }

  /* End of Saturate: '<S9>/Saturation1' */

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   */
  if (samerHARDWARE_B.Abs4_ns > samerHARDWARE_P.Switch_Threshold_eq) {
    samerHARDWARE_B.Yaw = samerHARDWARE_P.Constant_Value_p;
  } else {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.Saturation1_a;
  }

  /* Gain: '<S9>/Gain4' incorporates:
   *  Switch: '<S9>/Switch'
   */
  samerHARDWARE_B.Gain4_b = samerHARDWARE_P.Gain4_Gain_j * samerHARDWARE_B.Yaw;

  /* MATLAB Function: '<S9>/MATLAB Function1' */
  samerHARDWARE_MATLABFunction1(samerHARDWARE_B.sf_MATLABFunction_dw.y,
    samerHARDWARE_B.Gain4_b, &samerHARDWARE_B.sf_MATLABFunction1_i,
    &samerHARDWARE_DW.sf_MATLABFunction1_i);

  /* MATLABSystem: '<S9>/PWM2' */
  samerHARDWARE_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);

  /* Start for MATLABSystem: '<S9>/PWM2' */
  if (samerHARDWARE_B.sf_MATLABFunction1_i.y <= 255.0) {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.sf_MATLABFunction1_i.y;
  } else {
    samerHARDWARE_B.Yaw = 255.0;
  }

  if (!(samerHARDWARE_B.Yaw >= 0.0)) {
    samerHARDWARE_B.Yaw = 0.0;
  }

  /* MATLABSystem: '<S9>/PWM2' */
  MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWARE_B.Yaw);

  /* MATLAB Function: '<S9>/MATLAB Function2' */
  samerHARDWARE_MATLABFunction1(samerHARDWARE_B.sf_MATLABFunction_dw.x,
    samerHARDWARE_B.Gain4_b, &samerHARDWARE_B.sf_MATLABFunction2_f,
    &samerHARDWARE_DW.sf_MATLABFunction2_f);

  /* MATLABSystem: '<S9>/PWM3' */
  samerHARDWARE_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

  /* Start for MATLABSystem: '<S9>/PWM3' */
  if (samerHARDWARE_B.sf_MATLABFunction2_f.y <= 255.0) {
    samerHARDWARE_B.Yaw = samerHARDWARE_B.sf_MATLABFunction2_f.y;
  } else {
    samerHARDWARE_B.Yaw = 255.0;
  }

  if (!(samerHARDWARE_B.Yaw >= 0.0)) {
    samerHARDWARE_B.Yaw = 0.0;
  }

  /* MATLABSystem: '<S9>/PWM3' */
  MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWARE_B.Yaw);

  /* Gain: '<S279>/Integral Gain' */
  samerHARDWARE_B.IntegralGain_j = samerHARDWARE_P.DiscretePIDController1_I_o *
    samerHARDWARE_B.Abs4_ns;

  /* MATLAB Function: '<Root>/MATLAB Function2' */
  if (samerHARDWARE_B.Clock1 < 2.0) {
    shape_id = 1;
  } else if (samerHARDWARE_B.Clock1 < 4.0) {
    shape_id = 0;
  } else {
    shape_id = (samerHARDWARE_B.Clock1 < 10.0);
  }

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function2'
   */
  writeDigitalPin(22, (uint8_T)shape_id);

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  samerHARDWARE_DW.UnitDelay_DSTATE[0] = samerHARDWARE_B.Gain;
  samerHARDWARE_DW.UnitDelay_DSTATE[1] = samerHARDWARE_B.Gain4;
  samerHARDWARE_DW.UnitDelay_DSTATE[2] = samerHARDWARE_B.Gain8;
  samerHARDWARE_DW.UnitDelay_DSTATE[3] = samerHARDWARE_B.Gain12;
  samerHARDWARE_DW.UnitDelay_DSTATE[4] = samerHARDWARE_B.Gain16;
  samerHARDWARE_DW.UnitDelay_DSTATE[5] = samerHARDWARE_B.Gain20;

  /* Update for UnitDelay: '<S11>/Unit Delay8' */
  samerHARDWARE_DW.UnitDelay8_DSTATE = samerHARDWARE_B.DataTypeConversion10;

  /* Update for UnitDelay: '<S11>/Unit Delay9' */
  samerHARDWARE_DW.UnitDelay9_DSTATE = samerHARDWARE_B.Sum4;

  /* Update for UnitDelay: '<S11>/Unit Delay' */
  samerHARDWARE_DW.UnitDelay_DSTATE_a = samerHARDWARE_B.DataTypeConversion3;

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  samerHARDWARE_DW.UnitDelay1_DSTATE = samerHARDWARE_B.Sum;

  /* Update for UnitDelay: '<S11>/Unit Delay2' */
  samerHARDWARE_DW.UnitDelay2_DSTATE = samerHARDWARE_B.DataTypeConversion4;

  /* Update for UnitDelay: '<S11>/Unit Delay3' */
  samerHARDWARE_DW.UnitDelay3_DSTATE = samerHARDWARE_B.Sum1;

  /* Update for UnitDelay: '<S11>/Unit Delay4' */
  samerHARDWARE_DW.UnitDelay4_DSTATE = samerHARDWARE_B.DataTypeConversion6;

  /* Update for UnitDelay: '<S11>/Unit Delay5' */
  samerHARDWARE_DW.UnitDelay5_DSTATE = samerHARDWARE_B.Sum2;

  /* Update for UnitDelay: '<S11>/Unit Delay6' */
  samerHARDWARE_DW.UnitDelay6_DSTATE = samerHARDWARE_B.DataTypeConversion8;

  /* Update for UnitDelay: '<S11>/Unit Delay7' */
  samerHARDWARE_DW.UnitDelay7_DSTATE = samerHARDWARE_B.Sum3;

  /* Update for UnitDelay: '<S11>/Unit Delay10' */
  samerHARDWARE_DW.UnitDelay10_DSTATE = samerHARDWARE_B.DataTypeConversion11;

  /* Update for UnitDelay: '<S11>/Unit Delay11' */
  samerHARDWARE_DW.UnitDelay11_DSTATE = samerHARDWARE_B.Sum5;

  /* Update for DiscreteIntegrator: '<S340>/Integrator' */
  samerHARDWARE_DW.Integrator_DSTATE += samerHARDWARE_P.Integrator_gainval *
    samerHARDWARE_B.IntegralGain;

  /* Update for Delay: '<S333>/UD' */
  samerHARDWARE_DW.UD_DSTATE = samerHARDWARE_B.Tsamp;

  /* Update for DiscreteIntegrator: '<S224>/Integrator' */
  samerHARDWARE_DW.Integrator_DSTATE_f += samerHARDWARE_P.Integrator_gainval_k *
    samerHARDWARE_B.IntegralGain_b;

  /* Update for Delay: '<S217>/UD' */
  samerHARDWARE_DW.UD_DSTATE_n = samerHARDWARE_B.Tsamp_a;

  /* Update for DiscreteIntegrator: '<S166>/Integrator' */
  samerHARDWARE_DW.Integrator_DSTATE_g += samerHARDWARE_P.Integrator_gainval_k3 *
    samerHARDWARE_B.IntegralGain_e;

  /* Update for Delay: '<S159>/UD' */
  samerHARDWARE_DW.UD_DSTATE_b = samerHARDWARE_B.Tsamp_j;

  /* Update for DiscreteIntegrator: '<S108>/Integrator' */
  samerHARDWARE_DW.Integrator_DSTATE_j += samerHARDWARE_P.Integrator_gainval_g *
    samerHARDWARE_B.IntegralGain_ev;

  /* Update for Delay: '<S101>/UD' */
  samerHARDWARE_DW.UD_DSTATE_a = samerHARDWARE_B.Tsamp_m;

  /* Update for DiscreteIntegrator: '<S50>/Integrator' */
  samerHARDWARE_DW.Integrator_DSTATE_c += samerHARDWARE_P.Integrator_gainval_l *
    samerHARDWARE_B.IntegralGain_i;

  /* Update for DiscreteIntegrator: '<S45>/Filter' */
  samerHARDWARE_DW.Filter_DSTATE += samerHARDWARE_P.Filter_gainval *
    samerHARDWARE_B.FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S282>/Integrator' */
  samerHARDWARE_DW.Integrator_DSTATE_fp += samerHARDWARE_P.Integrator_gainval_l4
    * samerHARDWARE_B.IntegralGain_j;

  /* Update for Delay: '<S275>/UD' */
  samerHARDWARE_DW.UD_DSTATE_o = samerHARDWARE_B.Tsamp_b;

  {                                    /* Sample time: [0.01s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      (((samerHARDWARE_M->Timing.clockTick1+samerHARDWARE_M->Timing.clockTickH1*
         4294967296.0) * 1) + 0);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (samerHARDWARE_M->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.03s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      (((samerHARDWARE_M->Timing.clockTick2+samerHARDWARE_M->Timing.clockTickH2*
         4294967296.0) * 3) + 0);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(2, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++samerHARDWARE_M->Timing.clockTick0)) {
    ++samerHARDWARE_M->Timing.clockTickH0;
  }

  samerHARDWARE_M->Timing.t[0] = samerHARDWARE_M->Timing.clockTick0 *
    samerHARDWARE_M->Timing.stepSize0 + samerHARDWARE_M->Timing.clockTickH0 *
    samerHARDWARE_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    samerHARDWARE_M->Timing.clockTick1++;
    if (!samerHARDWARE_M->Timing.clockTick1) {
      samerHARDWARE_M->Timing.clockTickH1++;
    }
  }

  if (samerHARDWARE_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.03s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.03, which is the step size
     * of the task. Size of "clockTick2" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    samerHARDWARE_M->Timing.clockTick2++;
    if (!samerHARDWARE_M->Timing.clockTick2) {
      samerHARDWARE_M->Timing.clockTickH2++;
    }
  }

  rate_scheduler();
}

/* Model initialize function */
void samerHARDWARE_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)samerHARDWARE_M, 0,
                sizeof(RT_MODEL_samerHARDWARE_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&samerHARDWARE_M->solverInfo,
                          &samerHARDWARE_M->Timing.simTimeStep);
    rtsiSetTPtr(&samerHARDWARE_M->solverInfo, &rtmGetTPtr(samerHARDWARE_M));
    rtsiSetStepSizePtr(&samerHARDWARE_M->solverInfo,
                       &samerHARDWARE_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&samerHARDWARE_M->solverInfo, (&rtmGetErrorStatus
      (samerHARDWARE_M)));
    rtsiSetRTModelPtr(&samerHARDWARE_M->solverInfo, samerHARDWARE_M);
  }

  rtsiSetSimTimeStep(&samerHARDWARE_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&samerHARDWARE_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&samerHARDWARE_M->solverInfo, false);
  rtsiSetSolverName(&samerHARDWARE_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(samerHARDWARE_M, &samerHARDWARE_M->Timing.tArray[0]);
  rtmSetTFinal(samerHARDWARE_M, -1);
  samerHARDWARE_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  samerHARDWARE_M->Sizes.checksums[0] = (2843656178U);
  samerHARDWARE_M->Sizes.checksums[1] = (989657445U);
  samerHARDWARE_M->Sizes.checksums[2] = (2705542171U);
  samerHARDWARE_M->Sizes.checksums[3] = (2375432490U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[42];
    samerHARDWARE_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(samerHARDWARE_M->extModeInfo,
      &samerHARDWARE_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(samerHARDWARE_M->extModeInfo,
                        samerHARDWARE_M->Sizes.checksums);
    rteiSetTFinalTicks(samerHARDWARE_M->extModeInfo, -1);
  }

  /* block I/O */
  (void) memset(((void *) &samerHARDWARE_B), 0,
                sizeof(B_samerHARDWARE_T));

  /* states (dwork) */
  (void) memset((void *)&samerHARDWARE_DW, 0,
                sizeof(DW_samerHARDWARE_T));

  /* Start for MATLABSystem: '<S11>/Analog Input4' */
  samerHARDWARE_DW.obj_i.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_f = true;
  samerHARDWARE_DW.obj_i.isInitialized = 1L;
  samerHARDWARE_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(56UL);
  samerHARDWARE_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/Analog Input' */
  samerHARDWARE_DW.obj_ic.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_l = true;
  samerHARDWARE_DW.obj_ic.isInitialized = 1L;
  samerHARDWARE_DW.obj_ic.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(54UL);
  samerHARDWARE_DW.obj_ic.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/Analog Input1' */
  samerHARDWARE_DW.obj_o.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_k4 = true;
  samerHARDWARE_DW.obj_o.isInitialized = 1L;
  samerHARDWARE_DW.obj_o.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(59UL);
  samerHARDWARE_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/Analog Input2' */
  samerHARDWARE_DW.obj_m.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_a = true;
  samerHARDWARE_DW.obj_m.isInitialized = 1L;
  samerHARDWARE_DW.obj_m.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(58UL);
  samerHARDWARE_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/Analog Input3' */
  samerHARDWARE_DW.obj_i3.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_k = true;
  samerHARDWARE_DW.obj_i3.isInitialized = 1L;
  samerHARDWARE_DW.obj_i3.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(57UL);
  samerHARDWARE_DW.obj_i3.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/Analog Input5' */
  samerHARDWARE_DW.obj_na.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty = true;
  samerHARDWARE_DW.obj_na.isInitialized = 1L;
  samerHARDWARE_DW.obj_na.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(55UL);
  samerHARDWARE_DW.obj_na.isSetupComplete = true;

  /* Start for MATLABSystem: '<S10>/PWM2' */
  samerHARDWARE_DW.obj_p.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_lk = true;
  samerHARDWARE_DW.obj_p.isInitialized = 1L;
  samerHARDWARE_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0, 0.0);
  samerHARDWARE_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S10>/PWM3' */
  samerHARDWARE_DW.obj_k.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_j = true;
  samerHARDWARE_DW.obj_k.isInitialized = 1L;
  samerHARDWARE_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(7UL, 0.0, 0.0);
  samerHARDWARE_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/PWM2' */
  samerHARDWARE_DW.obj_j.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_m = true;
  samerHARDWARE_DW.obj_j.isInitialized = 1L;
  samerHARDWARE_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0, 0.0);
  samerHARDWARE_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/PWM3' */
  samerHARDWARE_DW.obj_nt.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_h = true;
  samerHARDWARE_DW.obj_nt.isInitialized = 1L;
  samerHARDWARE_DW.obj_nt.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(13UL, 0.0,
    0.0);
  samerHARDWARE_DW.obj_nt.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/PWM2' */
  samerHARDWARE_DW.obj_b.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_c = true;
  samerHARDWARE_DW.obj_b.isInitialized = 1L;
  samerHARDWARE_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
  samerHARDWARE_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/PWM3' */
  samerHARDWARE_DW.obj_l.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_p = true;
  samerHARDWARE_DW.obj_l.isInitialized = 1L;
  samerHARDWARE_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  samerHARDWARE_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/PWM2' */
  samerHARDWARE_DW.obj_pv.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_h1 = true;
  samerHARDWARE_DW.obj_pv.isInitialized = 1L;
  samerHARDWARE_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4UL, 0.0, 0.0);
  samerHARDWARE_DW.obj_pv.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/PWM3' */
  samerHARDWARE_DW.obj_lt.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_f2 = true;
  samerHARDWARE_DW.obj_lt.isInitialized = 1L;
  samerHARDWARE_DW.obj_lt.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
  samerHARDWARE_DW.obj_lt.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/PWM2' */
  samerHARDWARE_DW.obj_e.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_e = true;
  samerHARDWARE_DW.obj_e.isInitialized = 1L;
  samerHARDWARE_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(2UL, 0.0, 0.0);
  samerHARDWARE_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/PWM3' */
  samerHARDWARE_DW.obj_g.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_ln = true;
  samerHARDWARE_DW.obj_g.isInitialized = 1L;
  samerHARDWARE_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(3UL, 0.0, 0.0);
  samerHARDWARE_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/PWM2' */
  samerHARDWARE_DW.obj_f.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_o = true;
  samerHARDWARE_DW.obj_f.isInitialized = 1L;
  samerHARDWARE_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(8UL, 0.0, 0.0);
  samerHARDWARE_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/PWM3' */
  samerHARDWARE_DW.obj_n.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_fm = true;
  samerHARDWARE_DW.obj_n.isInitialized = 1L;
  samerHARDWARE_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
  samerHARDWARE_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  samerHARDWARE_DW.obj.matlabCodegenIsDeleted = false;
  samerHARDWARE_DW.objisempty_jk = true;
  samerHARDWARE_DW.obj.isInitialized = 1L;
  digitalIOSetup(22, 1);
  samerHARDWARE_DW.obj.isSetupComplete = true;

  {
    int16_T i;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      samerHARDWARE_DW.UnitDelay_DSTATE[i] =
        samerHARDWARE_P.UnitDelay_InitialCondition;
    }

    /* End of InitializeConditions for UnitDelay: '<Root>/Unit Delay' */

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay8' */
    samerHARDWARE_DW.UnitDelay8_DSTATE =
      samerHARDWARE_P.UnitDelay8_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay9' */
    samerHARDWARE_DW.UnitDelay9_DSTATE =
      samerHARDWARE_P.UnitDelay9_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
    samerHARDWARE_DW.UnitDelay_DSTATE_a =
      samerHARDWARE_P.UnitDelay_InitialCondition_o;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay1' */
    samerHARDWARE_DW.UnitDelay1_DSTATE =
      samerHARDWARE_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay2' */
    samerHARDWARE_DW.UnitDelay2_DSTATE =
      samerHARDWARE_P.UnitDelay2_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay3' */
    samerHARDWARE_DW.UnitDelay3_DSTATE =
      samerHARDWARE_P.UnitDelay3_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay4' */
    samerHARDWARE_DW.UnitDelay4_DSTATE =
      samerHARDWARE_P.UnitDelay4_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay5' */
    samerHARDWARE_DW.UnitDelay5_DSTATE =
      samerHARDWARE_P.UnitDelay5_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay6' */
    samerHARDWARE_DW.UnitDelay6_DSTATE =
      samerHARDWARE_P.UnitDelay6_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay7' */
    samerHARDWARE_DW.UnitDelay7_DSTATE =
      samerHARDWARE_P.UnitDelay7_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay10' */
    samerHARDWARE_DW.UnitDelay10_DSTATE =
      samerHARDWARE_P.UnitDelay10_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay11' */
    samerHARDWARE_DW.UnitDelay11_DSTATE =
      samerHARDWARE_P.UnitDelay11_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S340>/Integrator' */
    samerHARDWARE_DW.Integrator_DSTATE =
      samerHARDWARE_P.DiscretePIDController1_Initia_d;

    /* InitializeConditions for Delay: '<S333>/UD' */
    samerHARDWARE_DW.UD_DSTATE = samerHARDWARE_P.DiscretePIDController1_Differen;

    /* InitializeConditions for DiscreteIntegrator: '<S224>/Integrator' */
    samerHARDWARE_DW.Integrator_DSTATE_f =
      samerHARDWARE_P.DiscretePIDController1_Initia_c;

    /* InitializeConditions for Delay: '<S217>/UD' */
    samerHARDWARE_DW.UD_DSTATE_n =
      samerHARDWARE_P.DiscretePIDController1_Differ_c;

    /* InitializeConditions for DiscreteIntegrator: '<S166>/Integrator' */
    samerHARDWARE_DW.Integrator_DSTATE_g =
      samerHARDWARE_P.DiscretePIDController1_Initia_l;

    /* InitializeConditions for Delay: '<S159>/UD' */
    samerHARDWARE_DW.UD_DSTATE_b =
      samerHARDWARE_P.DiscretePIDController1_Differ_g;

    /* InitializeConditions for DiscreteIntegrator: '<S108>/Integrator' */
    samerHARDWARE_DW.Integrator_DSTATE_j =
      samerHARDWARE_P.DiscretePIDController1_Initia_h;

    /* InitializeConditions for Delay: '<S101>/UD' */
    samerHARDWARE_DW.UD_DSTATE_a =
      samerHARDWARE_P.DiscretePIDController1_Differ_j;

    /* InitializeConditions for DiscreteIntegrator: '<S50>/Integrator' */
    samerHARDWARE_DW.Integrator_DSTATE_c =
      samerHARDWARE_P.DiscretePIDController1_Initi_la;

    /* InitializeConditions for DiscreteIntegrator: '<S45>/Filter' */
    samerHARDWARE_DW.Filter_DSTATE =
      samerHARDWARE_P.DiscretePIDController1_InitialC;

    /* InitializeConditions for DiscreteIntegrator: '<S282>/Integrator' */
    samerHARDWARE_DW.Integrator_DSTATE_fp =
      samerHARDWARE_P.DiscretePIDController1_Initia_f;

    /* InitializeConditions for Delay: '<S275>/UD' */
    samerHARDWARE_DW.UD_DSTATE_o =
      samerHARDWARE_P.DiscretePIDController1_Differ_d;

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function2' */
    samerHARDWARE_DW.sfEvent_b = samerHARDWARE_CALL_EVENT_a;

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function4' */
    samerHARDWARE_DW.sfEvent = samerHARDWARE_CALL_EVENT_a;

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
    samerHARDWARE_DW.sfEvent_jw = samerHARDWARE_CALL_EVENT_a;

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function3' */
    samerHARDWARE_DW.sfEvent_j = samerHARDWARE_CALL_EVENT_a;

    /* SystemInitialize for MATLAB Function: '<S10>/MATLAB Function' */
    samerHARDWA_MATLABFunction_Init(&samerHARDWARE_DW.sf_MATLABFunction_b);

    /* SystemInitialize for MATLAB Function: '<S10>/MATLAB Function1' */
    samerHARDW_MATLABFunction1_Init(&samerHARDWARE_DW.sf_MATLABFunction1_i3);

    /* SystemInitialize for MATLAB Function: '<S10>/MATLAB Function2' */
    samerHARDW_MATLABFunction1_Init(&samerHARDWARE_DW.sf_MATLABFunction2_h);

    /* SystemInitialize for MATLAB Function: '<S8>/MATLAB Function' */
    samerHARDWA_MATLABFunction_Init(&samerHARDWARE_DW.sf_MATLABFunction_m);

    /* SystemInitialize for MATLAB Function: '<S8>/MATLAB Function1' */
    samerHARDW_MATLABFunction1_Init(&samerHARDWARE_DW.sf_MATLABFunction1_g);

    /* SystemInitialize for MATLAB Function: '<S8>/MATLAB Function2' */
    samerHARDW_MATLABFunction1_Init(&samerHARDWARE_DW.sf_MATLABFunction2_e);

    /* SystemInitialize for MATLAB Function: '<S7>/MATLAB Function' */
    samerHARDWA_MATLABFunction_Init(&samerHARDWARE_DW.sf_MATLABFunction_hb);

    /* SystemInitialize for MATLAB Function: '<S7>/MATLAB Function1' */
    samerHARDW_MATLABFunction1_Init(&samerHARDWARE_DW.sf_MATLABFunction1_k);

    /* SystemInitialize for MATLAB Function: '<S7>/MATLAB Function2' */
    samerHARDW_MATLABFunction1_Init(&samerHARDWARE_DW.sf_MATLABFunction2_mw);

    /* SystemInitialize for MATLAB Function: '<S6>/MATLAB Function' */
    samerHARDWA_MATLABFunction_Init(&samerHARDWARE_DW.sf_MATLABFunction_d);

    /* SystemInitialize for MATLAB Function: '<S6>/MATLAB Function1' */
    samerHARDW_MATLABFunction1_Init(&samerHARDWARE_DW.sf_MATLABFunction1_h);

    /* SystemInitialize for MATLAB Function: '<S6>/MATLAB Function2' */
    samerHARDW_MATLABFunction1_Init(&samerHARDWARE_DW.sf_MATLABFunction2_o);

    /* SystemInitialize for MATLAB Function: '<S5>/MATLAB Function' */
    samerHARDWA_MATLABFunction_Init(&samerHARDWARE_DW.sf_MATLABFunction_h);

    /* SystemInitialize for MATLAB Function: '<S5>/MATLAB Function1' */
    samerHARDW_MATLABFunction1_Init(&samerHARDWARE_DW.sf_MATLABFunction1);

    /* SystemInitialize for MATLAB Function: '<S5>/MATLAB Function2' */
    samerHARDW_MATLABFunction1_Init(&samerHARDWARE_DW.sf_MATLABFunction2_m);

    /* SystemInitialize for MATLAB Function: '<S9>/MATLAB Function' */
    samerHARDWA_MATLABFunction_Init(&samerHARDWARE_DW.sf_MATLABFunction_dw);

    /* SystemInitialize for MATLAB Function: '<S9>/MATLAB Function1' */
    samerHARDW_MATLABFunction1_Init(&samerHARDWARE_DW.sf_MATLABFunction1_i);

    /* SystemInitialize for MATLAB Function: '<S9>/MATLAB Function2' */
    samerHARDW_MATLABFunction1_Init(&samerHARDWARE_DW.sf_MATLABFunction2_f);
  }
}

/* Model terminate function */
void samerHARDWARE_terminate(void)
{
  /* Terminate for MATLABSystem: '<S11>/Analog Input4' */
  if (!samerHARDWARE_DW.obj_i.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_i.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_i.isSetupComplete) {
      samerHARDWARE_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(56UL);
      MW_AnalogIn_Close
        (samerHARDWARE_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/Analog Input4' */

  /* Terminate for MATLABSystem: '<S11>/Analog Input' */
  if (!samerHARDWARE_DW.obj_ic.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_ic.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_ic.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_ic.isSetupComplete) {
      samerHARDWARE_DW.obj_ic.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(54UL);
      MW_AnalogIn_Close
        (samerHARDWARE_DW.obj_ic.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/Analog Input' */

  /* Terminate for MATLABSystem: '<S11>/Analog Input1' */
  if (!samerHARDWARE_DW.obj_o.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_o.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_o.isSetupComplete) {
      samerHARDWARE_DW.obj_o.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(59UL);
      MW_AnalogIn_Close
        (samerHARDWARE_DW.obj_o.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/Analog Input1' */

  /* Terminate for MATLABSystem: '<S11>/Analog Input2' */
  if (!samerHARDWARE_DW.obj_m.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_m.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_m.isSetupComplete) {
      samerHARDWARE_DW.obj_m.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(58UL);
      MW_AnalogIn_Close
        (samerHARDWARE_DW.obj_m.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/Analog Input2' */

  /* Terminate for MATLABSystem: '<S11>/Analog Input3' */
  if (!samerHARDWARE_DW.obj_i3.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_i3.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_i3.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_i3.isSetupComplete) {
      samerHARDWARE_DW.obj_i3.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(57UL);
      MW_AnalogIn_Close
        (samerHARDWARE_DW.obj_i3.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/Analog Input3' */

  /* Terminate for MATLABSystem: '<S11>/Analog Input5' */
  if (!samerHARDWARE_DW.obj_na.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_na.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_na.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_na.isSetupComplete) {
      samerHARDWARE_DW.obj_na.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(55UL);
      MW_AnalogIn_Close
        (samerHARDWARE_DW.obj_na.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/Analog Input5' */
  /* Terminate for MATLABSystem: '<S10>/PWM2' */
  if (!samerHARDWARE_DW.obj_p.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_p.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_p.isSetupComplete) {
      samerHARDWARE_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWARE_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_Close(samerHARDWARE_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S10>/PWM2' */

  /* Terminate for MATLABSystem: '<S10>/PWM3' */
  if (!samerHARDWARE_DW.obj_k.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_k.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_k.isSetupComplete) {
      samerHARDWARE_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7UL);
      MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWARE_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7UL);
      MW_PWM_Close(samerHARDWARE_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S10>/PWM3' */
  /* Terminate for MATLABSystem: '<S8>/PWM2' */
  if (!samerHARDWARE_DW.obj_j.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_j.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_j.isSetupComplete) {
      samerHARDWARE_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWARE_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_Close(samerHARDWARE_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/PWM2' */

  /* Terminate for MATLABSystem: '<S8>/PWM3' */
  if (!samerHARDWARE_DW.obj_nt.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_nt.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_nt.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_nt.isSetupComplete) {
      samerHARDWARE_DW.obj_nt.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(13UL);
      MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_nt.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      samerHARDWARE_DW.obj_nt.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(13UL);
      MW_PWM_Close(samerHARDWARE_DW.obj_nt.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/PWM3' */

  /* Terminate for MATLABSystem: '<S7>/PWM2' */
  if (!samerHARDWARE_DW.obj_b.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_b.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_b.isSetupComplete) {
      samerHARDWARE_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWARE_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close(samerHARDWARE_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/PWM2' */

  /* Terminate for MATLABSystem: '<S7>/PWM3' */
  if (!samerHARDWARE_DW.obj_l.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_l.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_l.isSetupComplete) {
      samerHARDWARE_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWARE_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(samerHARDWARE_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/PWM3' */

  /* Terminate for MATLABSystem: '<S6>/PWM2' */
  if (!samerHARDWARE_DW.obj_pv.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_pv.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_pv.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_pv.isSetupComplete) {
      samerHARDWARE_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      samerHARDWARE_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_Close(samerHARDWARE_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM2' */

  /* Terminate for MATLABSystem: '<S6>/PWM3' */
  if (!samerHARDWARE_DW.obj_lt.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_lt.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_lt.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_lt.isSetupComplete) {
      samerHARDWARE_DW.obj_lt.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_lt.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      samerHARDWARE_DW.obj_lt.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(samerHARDWARE_DW.obj_lt.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM3' */

  /* Terminate for MATLABSystem: '<S5>/PWM2' */
  if (!samerHARDWARE_DW.obj_e.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_e.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_e.isSetupComplete) {
      samerHARDWARE_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2UL);
      MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWARE_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2UL);
      MW_PWM_Close(samerHARDWARE_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM2' */

  /* Terminate for MATLABSystem: '<S5>/PWM3' */
  if (!samerHARDWARE_DW.obj_g.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_g.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_g.isSetupComplete) {
      samerHARDWARE_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3UL);
      MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWARE_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3UL);
      MW_PWM_Close(samerHARDWARE_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM3' */
  /* Terminate for MATLABSystem: '<S9>/PWM2' */
  if (!samerHARDWARE_DW.obj_f.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_f.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_f.isSetupComplete) {
      samerHARDWARE_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWARE_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_Close(samerHARDWARE_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/PWM2' */

  /* Terminate for MATLABSystem: '<S9>/PWM3' */
  if (!samerHARDWARE_DW.obj_n.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE_DW.obj_n.isInitialized == 1L) &&
        samerHARDWARE_DW.obj_n.isSetupComplete) {
      samerHARDWARE_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(samerHARDWARE_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWARE_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(samerHARDWARE_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/PWM3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!samerHARDWARE_DW.obj.matlabCodegenIsDeleted) {
    samerHARDWARE_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}
