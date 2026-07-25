/*
 * samerHARDWAREPOTread.c
 *
 * Code generation for model "samerHARDWAREPOTread".
 *
 * Model version              : 6.0
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Sat Jun 13 23:21:22 2026
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "samerHARDWAREPOTread.h"
#include "rtwtypes.h"
#include "samerHARDWAREPOTread_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>

/* Named constants for MATLAB Function: '<S4>/MATLAB Function' */
#define samerHARDWAREPOTread_CALL_EVENT (-1L)

/* Named constants for MATLAB Function: '<S4>/MATLAB Function1' */
#define samerHARDWAREPOTre_CALL_EVENT_n (-1L)

/* Named constants for MATLAB Function: '<Root>/MATLAB Function' */
#define samerHARDWAREPOTre_CALL_EVENT_a (-1L)

/* Block signals (default storage) */
B_samerHARDWAREPOTread_T samerHARDWAREPOTread_B;

/* Block states (default storage) */
DW_samerHARDWAREPOTread_T samerHARDWAREPOTread_DW;

/* Real-time model */
static RT_MODEL_samerHARDWAREPOTread_T samerHARDWAREPOTread_M_;
RT_MODEL_samerHARDWAREPOTread_T *const samerHARDWAREPOTread_M =
  &samerHARDWAREPOTread_M_;
uint32_T plook_u32u16u32n16_evenc_gf(uint16_T u, uint16_T bp0, uint16_T bpSpace,
  uint32_T maxIndex, uint32_T *fraction)
{
  uint32_T bpIndex;
  uint16_T fbpIndex;
  uint16_T uAdjust;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
     Rounding mode: 'floor'
   */
  uAdjust = u - bp0;
  fbpIndex = uAdjust / bpSpace;
  if (fbpIndex < maxIndex) {
    bpIndex = fbpIndex;
    *fraction = ((uint32_T)(uAdjust - fbpIndex * bpSpace) << 16) / bpSpace;
  } else {
    bpIndex = maxIndex - 1UL;
    *fraction = 65536UL;
  }

  return bpIndex;
}

int16_T intrp1d_s16s32s32u32u32n16l_f(uint32_T bpIndex, uint32_T frac, const
  int16_T table[])
{
  int16_T yL_0d0;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'floor'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[bpIndex];
  return (int16_T)((((int32_T)table[bpIndex + 1UL] - yL_0d0) * (int32_T)frac) >>
                   16) + yL_0d0;
}

/*
 * System initialize for atomic system:
 *    '<S4>/MATLAB Function'
 *    '<S5>/MATLAB Function'
 *    '<S6>/MATLAB Function'
 *    '<S7>/MATLAB Function'
 *    '<S8>/MATLAB Function'
 *    '<S9>/MATLAB Function'
 */
void samerHARDWA_MATLABFunction_Init(DW_MATLABFunction_samerHARDWA_T *localDW)
{
  localDW->sfEvent = samerHARDWAREPOTread_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<S4>/MATLAB Function'
 *    '<S5>/MATLAB Function'
 *    '<S6>/MATLAB Function'
 *    '<S7>/MATLAB Function'
 *    '<S8>/MATLAB Function'
 *    '<S9>/MATLAB Function'
 */
void samerHARDWAREPOT_MATLABFunction(real_T rtu_u,
  B_MATLABFunction_samerHARDWAR_T *localB, DW_MATLABFunction_samerHARDWA_T
  *localDW)
{
  localDW->sfEvent = samerHARDWAREPOTread_CALL_EVENT;
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
 *    '<S4>/MATLAB Function1'
 *    '<S4>/MATLAB Function2'
 *    '<S5>/MATLAB Function1'
 *    '<S5>/MATLAB Function2'
 *    '<S6>/MATLAB Function1'
 *    '<S6>/MATLAB Function2'
 *    '<S7>/MATLAB Function1'
 *    '<S7>/MATLAB Function2'
 *    '<S8>/MATLAB Function1'
 *    '<S8>/MATLAB Function2'
 *    ...
 */
void samerHARDW_MATLABFunction1_Init(DW_MATLABFunction1_samerHARDW_T *localDW)
{
  localDW->sfEvent = samerHARDWAREPOTre_CALL_EVENT_n;
}

/*
 * Output and update for atomic system:
 *    '<S4>/MATLAB Function1'
 *    '<S4>/MATLAB Function2'
 *    '<S5>/MATLAB Function1'
 *    '<S5>/MATLAB Function2'
 *    '<S6>/MATLAB Function1'
 *    '<S6>/MATLAB Function2'
 *    '<S7>/MATLAB Function1'
 *    '<S7>/MATLAB Function2'
 *    '<S8>/MATLAB Function1'
 *    '<S8>/MATLAB Function2'
 *    ...
 */
void samerHARDWAREPO_MATLABFunction1(real_T rtu_u, real_T rtu_v,
  B_MATLABFunction1_samerHARDWA_T *localB, DW_MATLABFunction1_samerHARDW_T
  *localDW)
{
  localDW->sfEvent = samerHARDWAREPOTre_CALL_EVENT_n;
  localB->y = rtu_u * rtu_v;
}

/* Model step function */
void samerHARDWAREPOTread_step(void)
{
  /* local block i/o variables */
  real_T rtb_Gain4_o;
  real_T rtb_Gain4_g;
  real_T rtb_Gain4_d;
  real_T rtb_Tsamp_j;
  real_T rtb_Tsamp_m;
  real_T rtb_Tsamp_d;
  uint32_T bpIdx;
  uint32_T frac;
  int16_T i;
  int16_T rtb_SignCorrected;
  uint16_T rtb_CastU16En16;
  boolean_T rtb_GTEp75;
  boolean_T rtb_LTEp25;
  static const real_T c[6] = { 0.43633231299858238, 0.85521133347722145,
    2.530727415391778, 2.9496064358704168, 4.6251225177849733,
    5.0440015382636121 };

  static const real_T d[6] = { 0.0, 1.2915436464758039, 2.0943951023931953,
    3.3859387488689991, 4.1887902047863905, 5.4803338512621949 };

  /* Gain: '<Root>/Gain4' incorporates:
   *  Clock: '<Root>/Clock'
   */
  samerHARDWAREPOTread_B.DataTypeConversion1_d =
    samerHARDWAREPOTread_M->Timing.t[0];

  /* DataTypeConversion: '<S11>/CastU16En16' incorporates:
   *  Gain: '<Root>/Gain18'
   */
  samerHARDWAREPOTread_B.cy = floor(samerHARDWAREPOTread_P.Gain18_Gain *
    samerHARDWAREPOTread_B.DataTypeConversion1_d * 65536.0);
  if (rtIsNaN(samerHARDWAREPOTread_B.cy) || rtIsInf(samerHARDWAREPOTread_B.cy))
  {
    samerHARDWAREPOTread_B.cy = 0.0;
  } else {
    samerHARDWAREPOTread_B.cy = fmod(samerHARDWAREPOTread_B.cy, 65536.0);
  }

  rtb_CastU16En16 = samerHARDWAREPOTread_B.cy < 0.0 ? (uint16_T)-(int16_T)
    (uint16_T)-samerHARDWAREPOTread_B.cy : (uint16_T)samerHARDWAREPOTread_B.cy;

  /* End of DataTypeConversion: '<S11>/CastU16En16' */

  /* RelationalOperator: '<S11>/LTEp25' incorporates:
   *  Constant: '<S11>/Point25'
   *  DataTypeConversion: '<S11>/CastU16En16'
   */
  rtb_LTEp25 = (rtb_CastU16En16 <= samerHARDWAREPOTread_P.Point25_Value);

  /* RelationalOperator: '<S11>/GTEp75' incorporates:
   *  Constant: '<S11>/Point75'
   *  DataTypeConversion: '<S11>/CastU16En16'
   */
  rtb_GTEp75 = (rtb_CastU16En16 >= samerHARDWAREPOTread_P.Point75_Value);

  /* Switch: '<S11>/QuadHandle2' incorporates:
   *  Constant: '<S11>/Point50'
   *  Constant: '<S11>/Point75'
   *  DataTypeConversion: '<S11>/CastU16En16'
   *  RelationalOperator: '<S11>/LTEp50'
   *  Sum: '<S11>/p75mA'
   *  Switch: '<S11>/QuadHandle1b'
   */
  if (rtb_CastU16En16 <= samerHARDWAREPOTread_P.Point50_Value) {
    /* Switch: '<S11>/QuadHandle1a' incorporates:
     *  Constant: '<S11>/Point25'
     *  Sum: '<S11>/Amp25'
     *  Sum: '<S11>/p25mA'
     */
    if (rtb_LTEp25) {
      rtb_CastU16En16 = samerHARDWAREPOTread_P.Point25_Value - rtb_CastU16En16;
    } else {
      rtb_CastU16En16 -= samerHARDWAREPOTread_P.Point25_Value;
    }

    /* End of Switch: '<S11>/QuadHandle1a' */
  } else if (rtb_GTEp75) {
    /* Switch: '<S11>/QuadHandle1b' incorporates:
     *  Constant: '<S11>/Point75'
     *  Sum: '<S11>/Amp75'
     */
    rtb_CastU16En16 -= samerHARDWAREPOTread_P.Point75_Value;
  } else {
    rtb_CastU16En16 = samerHARDWAREPOTread_P.Point75_Value - rtb_CastU16En16;
  }

  /* Lookup_n-D: '<S10>/Look-Up Table' incorporates:
   *  Switch: '<S11>/QuadHandle2'
   */
  bpIdx = plook_u32u16u32n16_evenc_gf(rtb_CastU16En16,
    samerHARDWAREPOTread_P.LookUpTable_bp01Data[0],
    samerHARDWAREPOTread_P.LookUpTable_bp01Data[1] -
    samerHARDWAREPOTread_P.LookUpTable_bp01Data[0], 32UL, &frac);

  /* Switch: '<S11>/SignCorrected' incorporates:
   *  Logic: '<S11>/1st or 4th Quad'
   *  Lookup_n-D: '<S10>/Look-Up Table'
   *  Switch: '<S13>/SignCorrected'
   *  UnaryMinus: '<S11>/Negate'
   */
  if (rtb_LTEp25 || rtb_GTEp75) {
    rtb_SignCorrected = intrp1d_s16s32s32u32u32n16l_f(bpIdx, frac,
      samerHARDWAREPOTread_P.LookUpTable_tableData);
  } else {
    rtb_SignCorrected = -intrp1d_s16s32s32u32u32n16l_f(bpIdx, frac,
      samerHARDWAREPOTread_P.LookUpTable_tableData);
  }

  /* End of Switch: '<S11>/SignCorrected' */

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Constant2'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  Gain: '<Root>/Gain19'
   *  Switch: '<S13>/SignCorrected'
   */
  samerHARDWAREPOTread_B.Sum2 = (real_T)rtb_SignCorrected * 6.103515625E-5 *
    samerHARDWAREPOTread_P.Gain19_Gain + samerHARDWAREPOTread_P.Constant2_Value;

  /* Gain: '<Root>/Gain14' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  samerHARDWAREPOTread_B.Gain14 = samerHARDWAREPOTread_P.Gain14_Gain *
    samerHARDWAREPOTread_P.Constant1_Value;

  /* DataTypeConversion: '<S13>/CastU16En16' incorporates:
   *  Gain: '<Root>/Gain16'
   */
  samerHARDWAREPOTread_B.cy = floor(samerHARDWAREPOTread_P.Gain16_Gain *
    samerHARDWAREPOTread_B.DataTypeConversion1_d * 65536.0);
  if (rtIsNaN(samerHARDWAREPOTread_B.cy) || rtIsInf(samerHARDWAREPOTread_B.cy))
  {
    samerHARDWAREPOTread_B.cy = 0.0;
  } else {
    samerHARDWAREPOTread_B.cy = fmod(samerHARDWAREPOTread_B.cy, 65536.0);
  }

  rtb_CastU16En16 = samerHARDWAREPOTread_B.cy < 0.0 ? (uint16_T)-(int16_T)
    (uint16_T)-samerHARDWAREPOTread_B.cy : (uint16_T)samerHARDWAREPOTread_B.cy;

  /* End of DataTypeConversion: '<S13>/CastU16En16' */

  /* RelationalOperator: '<S13>/LTEp50' incorporates:
   *  Constant: '<S13>/Point50'
   *  DataTypeConversion: '<S13>/CastU16En16'
   */
  rtb_LTEp25 = (rtb_CastU16En16 <= samerHARDWAREPOTread_P.Point50_Value_p);

  /* Switch: '<S13>/QuadHandle1' incorporates:
   *  Constant: '<S13>/Point50'
   *  DataTypeConversion: '<S13>/CastU16En16'
   *  Sum: '<S13>/Amp50'
   */
  if (!rtb_LTEp25) {
    rtb_CastU16En16 -= samerHARDWAREPOTread_P.Point50_Value_p;
  }

  /* End of Switch: '<S13>/QuadHandle1' */

  /* Switch: '<S13>/QuadHandle2' incorporates:
   *  Constant: '<S13>/Point25'
   *  Constant: '<S13>/Point50'
   *  RelationalOperator: '<S13>/LTEp25'
   *  Sum: '<S13>/p50mA'
   *  Switch: '<S13>/QuadHandle1'
   */
  if (rtb_CastU16En16 > samerHARDWAREPOTread_P.Point25_Value_a) {
    rtb_CastU16En16 = samerHARDWAREPOTread_P.Point50_Value_p - rtb_CastU16En16;
  }

  /* Lookup_n-D: '<S12>/Look-Up Table' incorporates:
   *  Switch: '<S13>/QuadHandle2'
   */
  bpIdx = plook_u32u16u32n16_evenc_gf(rtb_CastU16En16,
    samerHARDWAREPOTread_P.LookUpTable_bp01Data_l[0],
    samerHARDWAREPOTread_P.LookUpTable_bp01Data_l[1] -
    samerHARDWAREPOTread_P.LookUpTable_bp01Data_l[0], 32UL, &frac);

  /* Switch: '<S13>/SignCorrected' incorporates:
   *  Lookup_n-D: '<S12>/Look-Up Table'
   *  UnaryMinus: '<S13>/Negate'
   */
  if (rtb_LTEp25) {
    rtb_SignCorrected = intrp1d_s16s32s32u32u32n16l_f(bpIdx, frac,
      samerHARDWAREPOTread_P.LookUpTable_tableData_i);
  } else {
    rtb_SignCorrected = -intrp1d_s16s32s32u32u32n16l_f(bpIdx, frac,
      samerHARDWAREPOTread_P.LookUpTable_tableData_i);
  }

  /* End of Switch: '<S13>/SignCorrected' */

  /* Gain: '<Root>/Gain12' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  samerHARDWAREPOTread_B.Gain12 = samerHARDWAREPOTread_P.Gain12_Gain *
    samerHARDWAREPOTread_P.Constant3_Value;

  /* Gain: '<Root>/Gain13' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  samerHARDWAREPOTread_B.Gain13 = samerHARDWAREPOTread_P.Gain13_Gain *
    samerHARDWAREPOTread_P.Constant4_Value;

  /* Gain: '<Root>/Gain20' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  samerHARDWAREPOTread_B.Gain20 = samerHARDWAREPOTread_P.Gain20_Gain *
    samerHARDWAREPOTread_P.Constant5_Value;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Constant7'
   *  Constant: '<Root>/Constant8'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  Gain: '<Root>/Gain15'
   *  Gain: '<Root>/Gain17'
   *  Gain: '<Root>/Gain21'
   *  Sum: '<Root>/Sum'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<Root>/Sum3'
   *  Switch: '<S13>/SignCorrected'
   */
  samerHARDWAREPOTread_DW.sfEvent = samerHARDWAREPOTre_CALL_EVENT_a;
  samerHARDWAREPOTread_B.r[0] = samerHARDWAREPOTread_P.Gain15_Gain *
    samerHARDWAREPOTread_B.Sum2;
  samerHARDWAREPOTread_B.r[1] = samerHARDWAREPOTread_B.Gain14;
  samerHARDWAREPOTread_B.r[2] = ((((real_T)rtb_SignCorrected * 6.103515625E-5 *
    samerHARDWAREPOTread_P.Gain17_Gain + samerHARDWAREPOTread_P.Constant7_Value)
    + samerHARDWAREPOTread_P.Constant8_Value) +
    samerHARDWAREPOTread_P.Constant6_Value) * samerHARDWAREPOTread_P.Gain21_Gain;
  samerHARDWAREPOTread_B.cy = cos(samerHARDWAREPOTread_B.Gain20);
  samerHARDWAREPOTread_B.Sum2 = sin(samerHARDWAREPOTread_B.Gain20);
  samerHARDWAREPOTread_B.cp = cos(samerHARDWAREPOTread_B.Gain13);
  samerHARDWAREPOTread_B.sp = sin(samerHARDWAREPOTread_B.Gain13);
  samerHARDWAREPOTread_B.cr = cos(samerHARDWAREPOTread_B.Gain12);
  samerHARDWAREPOTread_B.sr = sin(samerHARDWAREPOTread_B.Gain12);
  samerHARDWAREPOTread_B.R[0] = samerHARDWAREPOTread_B.cy *
    samerHARDWAREPOTread_B.cp;
  samerHARDWAREPOTread_B.R_tmp = samerHARDWAREPOTread_B.cy *
    samerHARDWAREPOTread_B.sp;
  samerHARDWAREPOTread_B.R[3] = samerHARDWAREPOTread_B.R_tmp *
    samerHARDWAREPOTread_B.sr - samerHARDWAREPOTread_B.Sum2 *
    samerHARDWAREPOTread_B.cr;
  samerHARDWAREPOTread_B.R[6] = samerHARDWAREPOTread_B.R_tmp *
    samerHARDWAREPOTread_B.cr + samerHARDWAREPOTread_B.Sum2 *
    samerHARDWAREPOTread_B.sr;
  samerHARDWAREPOTread_B.R[1] = samerHARDWAREPOTread_B.Sum2 *
    samerHARDWAREPOTread_B.cp;
  samerHARDWAREPOTread_B.R_tmp = samerHARDWAREPOTread_B.Sum2 *
    samerHARDWAREPOTread_B.sp;
  samerHARDWAREPOTread_B.R[4] = samerHARDWAREPOTread_B.R_tmp *
    samerHARDWAREPOTread_B.sr + samerHARDWAREPOTread_B.cy *
    samerHARDWAREPOTread_B.cr;
  samerHARDWAREPOTread_B.R[7] = samerHARDWAREPOTread_B.R_tmp *
    samerHARDWAREPOTread_B.cr - samerHARDWAREPOTread_B.cy *
    samerHARDWAREPOTread_B.sr;
  samerHARDWAREPOTread_B.R[2] = -samerHARDWAREPOTread_B.sp;
  samerHARDWAREPOTread_B.R[5] = samerHARDWAREPOTread_B.cp *
    samerHARDWAREPOTread_B.sr;
  samerHARDWAREPOTread_B.R[8] = samerHARDWAREPOTread_B.cp *
    samerHARDWAREPOTread_B.cr;
  for (rtb_SignCorrected = 0; rtb_SignCorrected < 6; rtb_SignCorrected++) {
    samerHARDWAREPOTread_B.cy = c[rtb_SignCorrected];
    samerHARDWAREPOTread_B.b[3 * rtb_SignCorrected] = 0.185 * cos
      (samerHARDWAREPOTread_B.cy);
    samerHARDWAREPOTread_B.b[3 * rtb_SignCorrected + 1] = 0.185 * sin
      (samerHARDWAREPOTread_B.cy);
    samerHARDWAREPOTread_B.b[3 * rtb_SignCorrected + 2] = 0.0;
    samerHARDWAREPOTread_B.Sum2 = d[rtb_SignCorrected];
    samerHARDWAREPOTread_B.cy = 0.15 * cos(samerHARDWAREPOTread_B.Sum2);
    samerHARDWAREPOTread_B.Sum2 = 0.15 * sin(samerHARDWAREPOTread_B.Sum2);
    for (i = 0; i < 3; i++) {
      samerHARDWAREPOTread_B.L[i] = (((samerHARDWAREPOTread_B.R[i + 3] *
        samerHARDWAREPOTread_B.Sum2 + samerHARDWAREPOTread_B.cy *
        samerHARDWAREPOTread_B.R[i]) + samerHARDWAREPOTread_B.R[i + 6] * 0.0) +
        samerHARDWAREPOTread_B.r[i]) - samerHARDWAREPOTread_B.b[3 *
        rtb_SignCorrected + i];
    }

    samerHARDWAREPOTread_B.deltaL[rtb_SignCorrected] = sqrt
      ((samerHARDWAREPOTread_B.L[0] * samerHARDWAREPOTread_B.L[0] +
        samerHARDWAREPOTread_B.L[1] * samerHARDWAREPOTread_B.L[1]) +
       samerHARDWAREPOTread_B.L[2] * samerHARDWAREPOTread_B.L[2]) - 0.29;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Gain: '<Root>/Gain3' */
  samerHARDWAREPOTread_B.DataTypeConversion1 = samerHARDWAREPOTread_P.Gain3_Gain
    * samerHARDWAREPOTread_B.deltaL[0];

  /* MATLABSystem: '<S4>/Analog Input' */
  samerHARDWAREPOTread_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(54UL);
  MW_AnalogInSingle_ReadResult
    (samerHARDWAREPOTread_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_CastU16En16, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<S4>/Data Type Conversion3' incorporates:
   *  MATLABSystem: '<S4>/Analog Input'
   * */
  samerHARDWAREPOTread_B.DataTypeConversion3 = rtb_CastU16En16;

  /* Sum: '<S4>/Sum' incorporates:
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S4>/Gain2'
   *  Gain: '<S4>/Gain3'
   *  UnitDelay: '<S4>/Unit Delay'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  samerHARDWAREPOTread_B.Sum = (samerHARDWAREPOTread_P.Gain2_Gain *
    samerHARDWAREPOTread_DW.UnitDelay_DSTATE + samerHARDWAREPOTread_P.Gain1_Gain
    * samerHARDWAREPOTread_B.DataTypeConversion3) +
    samerHARDWAREPOTread_P.Gain3_Gain_p *
    samerHARDWAREPOTread_DW.UnitDelay1_DSTATE;

  /* Gain: '<S4>/Gain' */
  samerHARDWAREPOTread_B.Gain = samerHARDWAREPOTread_P.Gain_Gain *
    samerHARDWAREPOTread_B.Sum;

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  samerHARDWAREPOTread_B.DataTypeConversion = samerHARDWAREPOTread_B.Gain;

  /* SignalConversion generated from: '<Root>/Subsystem' */
  samerHARDWAREPOTread_B.TmpSignalConversionAtTAQSigLogg[0] =
    samerHARDWAREPOTread_B.DataTypeConversion1;
  samerHARDWAREPOTread_B.TmpSignalConversionAtTAQSigLogg[1] =
    samerHARDWAREPOTread_B.DataTypeConversion;

  /* Gain: '<Root>/Gain4' */
  samerHARDWAREPOTread_B.DataTypeConversion1_d =
    samerHARDWAREPOTread_P.Gain4_Gain * samerHARDWAREPOTread_B.deltaL[1];

  /* MATLABSystem: '<S5>/Analog Input' */
  samerHARDWAREPOTread_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(59UL);
  MW_AnalogInSingle_ReadResult
    (samerHARDWAREPOTread_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_CastU16En16, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<S5>/Data Type Conversion3' incorporates:
   *  MATLABSystem: '<S5>/Analog Input'
   * */
  samerHARDWAREPOTread_B.DataTypeConversion3_b = rtb_CastU16En16;

  /* Sum: '<S5>/Sum' incorporates:
   *  Gain: '<S5>/Gain1'
   *  Gain: '<S5>/Gain2'
   *  Gain: '<S5>/Gain3'
   *  UnitDelay: '<S5>/Unit Delay'
   *  UnitDelay: '<S5>/Unit Delay1'
   */
  samerHARDWAREPOTread_B.Sum_l = (samerHARDWAREPOTread_P.Gain2_Gain_h *
    samerHARDWAREPOTread_DW.UnitDelay_DSTATE_a +
    samerHARDWAREPOTread_P.Gain1_Gain_j *
    samerHARDWAREPOTread_B.DataTypeConversion3_b) +
    samerHARDWAREPOTread_P.Gain3_Gain_j *
    samerHARDWAREPOTread_DW.UnitDelay1_DSTATE_e;

  /* Gain: '<S5>/Gain' */
  samerHARDWAREPOTread_B.Gain_b = samerHARDWAREPOTread_P.Gain_Gain_l *
    samerHARDWAREPOTread_B.Sum_l;

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  samerHARDWAREPOTread_B.DataTypeConversion_j = samerHARDWAREPOTread_B.Gain_b;

  /* SignalConversion generated from: '<Root>/Subsystem1' */
  samerHARDWAREPOTread_B.TmpSignalConversionAtTAQSigLo_m[0] =
    samerHARDWAREPOTread_B.DataTypeConversion1_d;
  samerHARDWAREPOTread_B.TmpSignalConversionAtTAQSigLo_m[1] =
    samerHARDWAREPOTread_B.DataTypeConversion_j;

  /* Gain: '<Root>/Gain5' */
  samerHARDWAREPOTread_B.DataTypeConversion1_o =
    samerHARDWAREPOTread_P.Gain5_Gain * samerHARDWAREPOTread_B.deltaL[2];

  /* MATLABSystem: '<S6>/Analog Input' */
  samerHARDWAREPOTread_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(58UL);
  MW_AnalogInSingle_ReadResult
    (samerHARDWAREPOTread_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_CastU16En16, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<S6>/Data Type Conversion3' incorporates:
   *  MATLABSystem: '<S6>/Analog Input'
   * */
  samerHARDWAREPOTread_B.DataTypeConversion3_k = rtb_CastU16En16;

  /* Sum: '<S6>/Sum' incorporates:
   *  Gain: '<S6>/Gain1'
   *  Gain: '<S6>/Gain2'
   *  Gain: '<S6>/Gain3'
   *  UnitDelay: '<S6>/Unit Delay'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  samerHARDWAREPOTread_B.Sum_c = (samerHARDWAREPOTread_P.Gain2_Gain_e *
    samerHARDWAREPOTread_DW.UnitDelay_DSTATE_l +
    samerHARDWAREPOTread_P.Gain1_Gain_n *
    samerHARDWAREPOTread_B.DataTypeConversion3_k) +
    samerHARDWAREPOTread_P.Gain3_Gain_g *
    samerHARDWAREPOTread_DW.UnitDelay1_DSTATE_c;

  /* Gain: '<S6>/Gain' */
  samerHARDWAREPOTread_B.Gain_be = samerHARDWAREPOTread_P.Gain_Gain_f *
    samerHARDWAREPOTread_B.Sum_c;

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  samerHARDWAREPOTread_B.DataTypeConversion_c = samerHARDWAREPOTread_B.Gain_be;

  /* SignalConversion generated from: '<Root>/Subsystem2' */
  samerHARDWAREPOTread_B.TmpSignalConversionAtTAQSigLo_j[0] =
    samerHARDWAREPOTread_B.DataTypeConversion1_o;
  samerHARDWAREPOTread_B.TmpSignalConversionAtTAQSigLo_j[1] =
    samerHARDWAREPOTread_B.DataTypeConversion_c;

  /* Gain: '<Root>/Gain6' */
  samerHARDWAREPOTread_B.DataTypeConversion1_c =
    samerHARDWAREPOTread_P.Gain6_Gain * samerHARDWAREPOTread_B.deltaL[3];

  /* MATLABSystem: '<S7>/Analog Input' */
  samerHARDWAREPOTread_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(57UL);
  MW_AnalogInSingle_ReadResult
    (samerHARDWAREPOTread_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_CastU16En16, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<S7>/Data Type Conversion3' incorporates:
   *  MATLABSystem: '<S7>/Analog Input'
   * */
  samerHARDWAREPOTread_B.DataTypeConversion3_c = rtb_CastU16En16;

  /* Sum: '<S7>/Sum' incorporates:
   *  Gain: '<S7>/Gain1'
   *  Gain: '<S7>/Gain2'
   *  Gain: '<S7>/Gain3'
   *  UnitDelay: '<S7>/Unit Delay'
   *  UnitDelay: '<S7>/Unit Delay1'
   */
  samerHARDWAREPOTread_B.Sum_m = (samerHARDWAREPOTread_P.Gain2_Gain_ea *
    samerHARDWAREPOTread_DW.UnitDelay_DSTATE_as +
    samerHARDWAREPOTread_P.Gain1_Gain_m *
    samerHARDWAREPOTread_B.DataTypeConversion3_c) +
    samerHARDWAREPOTread_P.Gain3_Gain_e *
    samerHARDWAREPOTread_DW.UnitDelay1_DSTATE_e1;

  /* Gain: '<S7>/Gain' */
  samerHARDWAREPOTread_B.Gain_j = samerHARDWAREPOTread_P.Gain_Gain_e *
    samerHARDWAREPOTread_B.Sum_m;

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  samerHARDWAREPOTread_B.DataTypeConversion_c3 = samerHARDWAREPOTread_B.Gain_j;

  /* SignalConversion generated from: '<Root>/Subsystem3' */
  samerHARDWAREPOTread_B.TmpSignalConversionAtTAQSigLo_g[0] =
    samerHARDWAREPOTread_B.DataTypeConversion1_c;
  samerHARDWAREPOTread_B.TmpSignalConversionAtTAQSigLo_g[1] =
    samerHARDWAREPOTread_B.DataTypeConversion_c3;

  /* Gain: '<Root>/Gain7' */
  samerHARDWAREPOTread_B.DataTypeConversion1_os =
    samerHARDWAREPOTread_P.Gain7_Gain * samerHARDWAREPOTread_B.deltaL[4];

  /* MATLABSystem: '<S8>/Analog Input' */
  samerHARDWAREPOTread_DW.obj_c.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(56UL);
  MW_AnalogInSingle_ReadResult
    (samerHARDWAREPOTread_DW.obj_c.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_CastU16En16, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<S8>/Data Type Conversion3' incorporates:
   *  MATLABSystem: '<S8>/Analog Input'
   * */
  samerHARDWAREPOTread_B.DataTypeConversion3_p = rtb_CastU16En16;

  /* Sum: '<S8>/Sum' incorporates:
   *  Gain: '<S8>/Gain1'
   *  Gain: '<S8>/Gain2'
   *  Gain: '<S8>/Gain3'
   *  UnitDelay: '<S8>/Unit Delay'
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  samerHARDWAREPOTread_B.Sum_k = (samerHARDWAREPOTread_P.Gain2_Gain_m *
    samerHARDWAREPOTread_DW.UnitDelay_DSTATE_o +
    samerHARDWAREPOTread_P.Gain1_Gain_l *
    samerHARDWAREPOTread_B.DataTypeConversion3_p) +
    samerHARDWAREPOTread_P.Gain3_Gain_go *
    samerHARDWAREPOTread_DW.UnitDelay1_DSTATE_cs;

  /* Gain: '<S8>/Gain' */
  samerHARDWAREPOTread_B.Gain_p = samerHARDWAREPOTread_P.Gain_Gain_es *
    samerHARDWAREPOTread_B.Sum_k;

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  samerHARDWAREPOTread_B.DataTypeConversion_e = samerHARDWAREPOTread_B.Gain_p;

  /* SignalConversion generated from: '<Root>/Subsystem4' */
  samerHARDWAREPOTread_B.TmpSignalConversionAtTAQSigLo_c[0] =
    samerHARDWAREPOTread_B.DataTypeConversion1_os;
  samerHARDWAREPOTread_B.TmpSignalConversionAtTAQSigLo_c[1] =
    samerHARDWAREPOTread_B.DataTypeConversion_e;

  /* Sum: '<S4>/Add2' incorporates:
   *  Gain: '<Root>/Gain8'
   */
  samerHARDWAREPOTread_B.DataTypeConversion1_cx =
    samerHARDWAREPOTread_P.Gain8_Gain * samerHARDWAREPOTread_B.deltaL[5];

  /* MATLABSystem: '<S9>/Analog Input' */
  samerHARDWAREPOTread_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(55UL);
  MW_AnalogInSingle_ReadResult
    (samerHARDWAREPOTread_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_CastU16En16, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<S9>/Data Type Conversion3' incorporates:
   *  MATLABSystem: '<S9>/Analog Input'
   * */
  samerHARDWAREPOTread_B.DataTypeConversion3_j = rtb_CastU16En16;

  /* Sum: '<S9>/Sum' incorporates:
   *  Gain: '<S9>/Gain1'
   *  Gain: '<S9>/Gain2'
   *  Gain: '<S9>/Gain3'
   *  UnitDelay: '<S9>/Unit Delay'
   *  UnitDelay: '<S9>/Unit Delay1'
   */
  samerHARDWAREPOTread_B.Sum_g = (samerHARDWAREPOTread_P.Gain2_Gain_ha *
    samerHARDWAREPOTread_DW.UnitDelay_DSTATE_i +
    samerHARDWAREPOTread_P.Gain1_Gain_g *
    samerHARDWAREPOTread_B.DataTypeConversion3_j) +
    samerHARDWAREPOTread_P.Gain3_Gain_h *
    samerHARDWAREPOTread_DW.UnitDelay1_DSTATE_i;

  /* Gain: '<S9>/Gain' */
  samerHARDWAREPOTread_B.Gain_k = samerHARDWAREPOTread_P.Gain_Gain_i *
    samerHARDWAREPOTread_B.Sum_g;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  samerHARDWAREPOTread_B.DataTypeConversion_i = samerHARDWAREPOTread_B.Gain_k;

  /* SignalConversion generated from: '<Root>/Subsystem5' */
  samerHARDWAREPOTread_B.TmpSignalConversionAtTAQSigLo_e[0] =
    samerHARDWAREPOTread_B.DataTypeConversion1_cx;
  samerHARDWAREPOTread_B.TmpSignalConversionAtTAQSigLo_e[1] =
    samerHARDWAREPOTread_B.DataTypeConversion_i;

  /* Sum: '<S9>/Add1' */
  samerHARDWAREPOTread_B.Add1 = samerHARDWAREPOTread_B.DataTypeConversion1_cx -
    samerHARDWAREPOTread_B.Gain_k;

  /* Sum: '<S4>/Add1' */
  samerHARDWAREPOTread_B.Add1_d = samerHARDWAREPOTread_B.DataTypeConversion1 -
    samerHARDWAREPOTread_B.Gain;

  /* Sum: '<S5>/Add1' */
  samerHARDWAREPOTread_B.Add1_e = samerHARDWAREPOTread_B.DataTypeConversion1_d -
    samerHARDWAREPOTread_B.Gain_b;

  /* Sum: '<S6>/Add1' */
  samerHARDWAREPOTread_B.Add1_eq = samerHARDWAREPOTread_B.DataTypeConversion1_o
    - samerHARDWAREPOTread_B.Gain_be;

  /* Sum: '<S7>/Add1' */
  samerHARDWAREPOTread_B.Add1_a = samerHARDWAREPOTread_B.DataTypeConversion1_c -
    samerHARDWAREPOTread_B.Gain_j;

  /* Sum: '<S8>/Add1' */
  samerHARDWAREPOTread_B.Add1_k = samerHARDWAREPOTread_B.DataTypeConversion1_os
    - samerHARDWAREPOTread_B.Gain_p;

  /* Sum: '<S9>/Add' */
  samerHARDWAREPOTread_B.Add = samerHARDWAREPOTread_B.DataTypeConversion1_cx -
    samerHARDWAREPOTread_B.Gain_k;

  /* MATLAB Function: '<S9>/MATLAB Function' */
  samerHARDWAREPOT_MATLABFunction(samerHARDWAREPOTread_B.Add,
    &samerHARDWAREPOTread_B.sf_MATLABFunction_b,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction_b);

  /* Abs: '<S9>/Abs4' */
  samerHARDWAREPOTread_B.Abs4 = fabs(samerHARDWAREPOTread_B.Add);

  /* SampleTimeMath: '<S339>/Tsamp' incorporates:
   *  Gain: '<S335>/Derivative Gain'
   *
   * About '<S339>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  samerHARDWAREPOTread_B.Tsamp = samerHARDWAREPOTread_P.DiscretePIDController1_D
    * samerHARDWAREPOTread_B.Abs4 * samerHARDWAREPOTread_P.Tsamp_WtEt;

  /* Sum: '<S353>/Sum' incorporates:
   *  Delay: '<S337>/UD'
   *  Gain: '<S349>/Proportional Gain'
   *  Sum: '<S337>/Diff'
   */
  samerHARDWAREPOTread_B.Saturation1 =
    samerHARDWAREPOTread_P.DiscretePIDController1_P *
    samerHARDWAREPOTread_B.Abs4 + (samerHARDWAREPOTread_B.Tsamp -
    samerHARDWAREPOTread_DW.UD_DSTATE);

  /* Saturate: '<S9>/Saturation1' */
  if (samerHARDWAREPOTread_B.Saturation1 >
      samerHARDWAREPOTread_P.Saturation1_UpperSat) {
    /* Sum: '<S353>/Sum' incorporates:
     *  Saturate: '<S9>/Saturation1'
     */
    samerHARDWAREPOTread_B.Saturation1 =
      samerHARDWAREPOTread_P.Saturation1_UpperSat;
  } else if (samerHARDWAREPOTread_B.Saturation1 <
             samerHARDWAREPOTread_P.Saturation1_LowerSat) {
    /* Sum: '<S353>/Sum' incorporates:
     *  Saturate: '<S9>/Saturation1'
     */
    samerHARDWAREPOTread_B.Saturation1 =
      samerHARDWAREPOTread_P.Saturation1_LowerSat;
  }

  /* End of Saturate: '<S9>/Saturation1' */

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   */
  if (samerHARDWAREPOTread_B.Abs4 > samerHARDWAREPOTread_P.Switch_Threshold) {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_P.Constant_Value;
  } else {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.Saturation1;
  }

  /* Gain: '<S9>/Gain4' incorporates:
   *  Switch: '<S9>/Switch'
   */
  samerHARDWAREPOTread_B.Gain4 = samerHARDWAREPOTread_P.Gain4_Gain_d *
    samerHARDWAREPOTread_B.cy;

  /* MATLAB Function: '<S9>/MATLAB Function1' */
  samerHARDWAREPO_MATLABFunction1(samerHARDWAREPOTread_B.sf_MATLABFunction_b.y,
    samerHARDWAREPOTread_B.Gain4, &samerHARDWAREPOTread_B.sf_MATLABFunction1_i3,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction1_i3);

  /* MATLABSystem: '<S9>/PWM2' */
  samerHARDWAREPOTread_DW.obj_po.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (6UL);

  /* Start for MATLABSystem: '<S9>/PWM2' */
  if (samerHARDWAREPOTread_B.sf_MATLABFunction1_i3.y <= 255.0) {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.sf_MATLABFunction1_i3.y;
  } else {
    samerHARDWAREPOTread_B.cy = 255.0;
  }

  if (!(samerHARDWAREPOTread_B.cy >= 0.0)) {
    samerHARDWAREPOTread_B.cy = 0.0;
  }

  /* MATLABSystem: '<S9>/PWM2' */
  MW_PWM_SetDutyCycle(samerHARDWAREPOTread_DW.obj_po.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWAREPOTread_B.cy);

  /* MATLAB Function: '<S9>/MATLAB Function2' */
  samerHARDWAREPO_MATLABFunction1(samerHARDWAREPOTread_B.sf_MATLABFunction_b.x,
    samerHARDWAREPOTread_B.Gain4, &samerHARDWAREPOTread_B.sf_MATLABFunction2_h,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction2_h);

  /* Abs: '<S9>/Abs' incorporates:
   *  Sum: '<S9>/Add2'
   */
  samerHARDWAREPOTread_B.Abs = fabs
    (samerHARDWAREPOTread_B.sf_MATLABFunction1_i3.y -
     samerHARDWAREPOTread_B.sf_MATLABFunction2_h.y);

  /* MATLABSystem: '<S9>/PWM3' */
  samerHARDWAREPOTread_DW.obj_kc.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (7UL);

  /* Start for MATLABSystem: '<S9>/PWM3' */
  if (samerHARDWAREPOTread_B.sf_MATLABFunction2_h.y <= 255.0) {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.sf_MATLABFunction2_h.y;
  } else {
    samerHARDWAREPOTread_B.cy = 255.0;
  }

  if (!(samerHARDWAREPOTread_B.cy >= 0.0)) {
    samerHARDWAREPOTread_B.cy = 0.0;
  }

  /* MATLABSystem: '<S9>/PWM3' */
  MW_PWM_SetDutyCycle(samerHARDWAREPOTread_DW.obj_kc.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWAREPOTread_B.cy);

  /* Sum: '<S8>/Add' */
  samerHARDWAREPOTread_B.Add_m = samerHARDWAREPOTread_B.DataTypeConversion1_os -
    samerHARDWAREPOTread_B.Gain_p;

  /* MATLAB Function: '<S8>/MATLAB Function' */
  samerHARDWAREPOT_MATLABFunction(samerHARDWAREPOTread_B.Add_m,
    &samerHARDWAREPOTread_B.sf_MATLABFunction_dw,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction_dw);

  /* Abs: '<S8>/Abs4' */
  samerHARDWAREPOTread_B.Abs4_n = fabs(samerHARDWAREPOTread_B.Add_m);

  /* SampleTimeMath: '<S281>/Tsamp' incorporates:
   *  Gain: '<S277>/Derivative Gain'
   *
   * About '<S281>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  samerHARDWAREPOTread_B.Tsamp_b =
    samerHARDWAREPOTread_P.DiscretePIDController1_D_c *
    samerHARDWAREPOTread_B.Abs4_n * samerHARDWAREPOTread_P.Tsamp_WtEt_a;

  /* Sum: '<S295>/Sum' incorporates:
   *  Delay: '<S279>/UD'
   *  Gain: '<S291>/Proportional Gain'
   *  Sum: '<S279>/Diff'
   */
  samerHARDWAREPOTread_B.Saturation1_a =
    samerHARDWAREPOTread_P.DiscretePIDController1_P_f *
    samerHARDWAREPOTread_B.Abs4_n + (samerHARDWAREPOTread_B.Tsamp_b -
    samerHARDWAREPOTread_DW.UD_DSTATE_o);

  /* Saturate: '<S8>/Saturation1' */
  if (samerHARDWAREPOTread_B.Saturation1_a >
      samerHARDWAREPOTread_P.Saturation1_UpperSat_i) {
    /* Sum: '<S295>/Sum' incorporates:
     *  Saturate: '<S8>/Saturation1'
     */
    samerHARDWAREPOTread_B.Saturation1_a =
      samerHARDWAREPOTread_P.Saturation1_UpperSat_i;
  } else if (samerHARDWAREPOTread_B.Saturation1_a <
             samerHARDWAREPOTread_P.Saturation1_LowerSat_f) {
    /* Sum: '<S295>/Sum' incorporates:
     *  Saturate: '<S8>/Saturation1'
     */
    samerHARDWAREPOTread_B.Saturation1_a =
      samerHARDWAREPOTread_P.Saturation1_LowerSat_f;
  }

  /* End of Saturate: '<S8>/Saturation1' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant'
   */
  if (samerHARDWAREPOTread_B.Abs4_n > samerHARDWAREPOTread_P.Switch_Threshold_e)
  {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_P.Constant_Value_p;
  } else {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.Saturation1_a;
  }

  /* Gain: '<S8>/Gain4' incorporates:
   *  Switch: '<S8>/Switch'
   */
  samerHARDWAREPOTread_B.Gain4_b = samerHARDWAREPOTread_P.Gain4_Gain_j *
    samerHARDWAREPOTread_B.cy;

  /* MATLAB Function: '<S8>/MATLAB Function1' */
  samerHARDWAREPO_MATLABFunction1(samerHARDWAREPOTread_B.sf_MATLABFunction_dw.y,
    samerHARDWAREPOTread_B.Gain4_b, &samerHARDWAREPOTread_B.sf_MATLABFunction1_i,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction1_i);

  /* MATLABSystem: '<S8>/PWM2' */
  samerHARDWAREPOTread_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (8UL);

  /* Start for MATLABSystem: '<S8>/PWM2' */
  if (samerHARDWAREPOTread_B.sf_MATLABFunction1_i.y <= 255.0) {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.sf_MATLABFunction1_i.y;
  } else {
    samerHARDWAREPOTread_B.cy = 255.0;
  }

  if (!(samerHARDWAREPOTread_B.cy >= 0.0)) {
    samerHARDWAREPOTread_B.cy = 0.0;
  }

  /* MATLABSystem: '<S8>/PWM2' */
  MW_PWM_SetDutyCycle(samerHARDWAREPOTread_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWAREPOTread_B.cy);

  /* MATLAB Function: '<S8>/MATLAB Function2' */
  samerHARDWAREPO_MATLABFunction1(samerHARDWAREPOTread_B.sf_MATLABFunction_dw.x,
    samerHARDWAREPOTread_B.Gain4_b, &samerHARDWAREPOTread_B.sf_MATLABFunction2_f,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction2_f);

  /* Abs: '<S8>/Abs' incorporates:
   *  Sum: '<S8>/Add2'
   */
  samerHARDWAREPOTread_B.Abs_l = fabs
    (samerHARDWAREPOTread_B.sf_MATLABFunction1_i.y -
     samerHARDWAREPOTread_B.sf_MATLABFunction2_f.y);

  /* MATLABSystem: '<S8>/PWM3' */
  samerHARDWAREPOTread_DW.obj_nn.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (9UL);

  /* Start for MATLABSystem: '<S8>/PWM3' */
  if (samerHARDWAREPOTread_B.sf_MATLABFunction2_f.y <= 255.0) {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.sf_MATLABFunction2_f.y;
  } else {
    samerHARDWAREPOTread_B.cy = 255.0;
  }

  if (!(samerHARDWAREPOTread_B.cy >= 0.0)) {
    samerHARDWAREPOTread_B.cy = 0.0;
  }

  /* MATLABSystem: '<S8>/PWM3' */
  MW_PWM_SetDutyCycle(samerHARDWAREPOTread_DW.obj_nn.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWAREPOTread_B.cy);

  /* Sum: '<S7>/Add' */
  samerHARDWAREPOTread_B.Add_h = samerHARDWAREPOTread_B.DataTypeConversion1_c -
    samerHARDWAREPOTread_B.Gain_j;

  /* MATLAB Function: '<S7>/MATLAB Function' */
  samerHARDWAREPOT_MATLABFunction(samerHARDWAREPOTread_B.Add_h,
    &samerHARDWAREPOTread_B.sf_MATLABFunction_m,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction_m);

  /* Abs: '<S7>/Abs4' */
  samerHARDWAREPOTread_B.Abs4_nd = fabs(samerHARDWAREPOTread_B.Add_h);

  /* SampleTimeMath: '<S223>/Tsamp' incorporates:
   *  Gain: '<S219>/Derivative Gain'
   *
   * About '<S223>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  samerHARDWAREPOTread_B.Tsamp_a =
    samerHARDWAREPOTread_P.DiscretePIDController1_D_ct *
    samerHARDWAREPOTread_B.Abs4_nd * samerHARDWAREPOTread_P.Tsamp_WtEt_o;

  /* Sum: '<S237>/Sum' incorporates:
   *  Delay: '<S221>/UD'
   *  Gain: '<S233>/Proportional Gain'
   *  Sum: '<S221>/Diff'
   */
  samerHARDWAREPOTread_B.Saturation1_g =
    samerHARDWAREPOTread_P.DiscretePIDController1_P_fb *
    samerHARDWAREPOTread_B.Abs4_nd + (samerHARDWAREPOTread_B.Tsamp_a -
    samerHARDWAREPOTread_DW.UD_DSTATE_n);

  /* Saturate: '<S7>/Saturation1' */
  if (samerHARDWAREPOTread_B.Saturation1_g >
      samerHARDWAREPOTread_P.Saturation1_UpperSat_b) {
    /* Sum: '<S237>/Sum' incorporates:
     *  Saturate: '<S7>/Saturation1'
     */
    samerHARDWAREPOTread_B.Saturation1_g =
      samerHARDWAREPOTread_P.Saturation1_UpperSat_b;
  } else if (samerHARDWAREPOTread_B.Saturation1_g <
             samerHARDWAREPOTread_P.Saturation1_LowerSat_n) {
    /* Sum: '<S237>/Sum' incorporates:
     *  Saturate: '<S7>/Saturation1'
     */
    samerHARDWAREPOTread_B.Saturation1_g =
      samerHARDWAREPOTread_P.Saturation1_LowerSat_n;
  }

  /* End of Saturate: '<S7>/Saturation1' */

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if (samerHARDWAREPOTread_B.Abs4_nd >
      samerHARDWAREPOTread_P.Switch_Threshold_eq) {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_P.Constant_Value_i;
  } else {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.Saturation1_g;
  }

  /* Gain: '<S7>/Gain4' incorporates:
   *  Switch: '<S7>/Switch'
   */
  samerHARDWAREPOTread_B.Gain4_m = samerHARDWAREPOTread_P.Gain4_Gain_dn *
    samerHARDWAREPOTread_B.cy;

  /* MATLAB Function: '<S7>/MATLAB Function1' */
  samerHARDWAREPO_MATLABFunction1(samerHARDWAREPOTread_B.sf_MATLABFunction_m.y,
    samerHARDWAREPOTread_B.Gain4_m, &samerHARDWAREPOTread_B.sf_MATLABFunction1_g,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction1_g);

  /* MATLABSystem: '<S7>/PWM2' */
  samerHARDWAREPOTread_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (12UL);

  /* Start for MATLABSystem: '<S7>/PWM2' */
  if (samerHARDWAREPOTread_B.sf_MATLABFunction1_g.y <= 255.0) {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.sf_MATLABFunction1_g.y;
  } else {
    samerHARDWAREPOTread_B.cy = 255.0;
  }

  if (!(samerHARDWAREPOTread_B.cy >= 0.0)) {
    samerHARDWAREPOTread_B.cy = 0.0;
  }

  /* MATLABSystem: '<S7>/PWM2' */
  MW_PWM_SetDutyCycle(samerHARDWAREPOTread_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWAREPOTread_B.cy);

  /* MATLAB Function: '<S7>/MATLAB Function2' */
  samerHARDWAREPO_MATLABFunction1(samerHARDWAREPOTread_B.sf_MATLABFunction_m.x,
    samerHARDWAREPOTread_B.Gain4_m, &samerHARDWAREPOTread_B.sf_MATLABFunction2_e,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction2_e);

  /* Abs: '<S7>/Abs' incorporates:
   *  Sum: '<S7>/Add2'
   */
  samerHARDWAREPOTread_B.Abs_p = fabs
    (samerHARDWAREPOTread_B.sf_MATLABFunction1_g.y -
     samerHARDWAREPOTread_B.sf_MATLABFunction2_e.y);

  /* MATLABSystem: '<S7>/PWM3' */
  samerHARDWAREPOTread_DW.obj_nt.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (13UL);

  /* Start for MATLABSystem: '<S7>/PWM3' */
  if (samerHARDWAREPOTread_B.sf_MATLABFunction2_e.y <= 255.0) {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.sf_MATLABFunction2_e.y;
  } else {
    samerHARDWAREPOTread_B.cy = 255.0;
  }

  if (!(samerHARDWAREPOTread_B.cy >= 0.0)) {
    samerHARDWAREPOTread_B.cy = 0.0;
  }

  /* MATLABSystem: '<S7>/PWM3' */
  MW_PWM_SetDutyCycle(samerHARDWAREPOTread_DW.obj_nt.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWAREPOTread_B.cy);

  /* Sum: '<S6>/Add' */
  samerHARDWAREPOTread_B.Add_c = samerHARDWAREPOTread_B.DataTypeConversion1_o -
    samerHARDWAREPOTread_B.Gain_be;

  /* MATLAB Function: '<S6>/MATLAB Function' */
  samerHARDWAREPOT_MATLABFunction(samerHARDWAREPOTread_B.Add_c,
    &samerHARDWAREPOTread_B.sf_MATLABFunction_hb,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction_hb);

  /* Abs: '<S6>/Abs4' */
  samerHARDWAREPOTread_B.Abs4_m = fabs(samerHARDWAREPOTread_B.Add_c);

  /* SampleTimeMath: '<S165>/Tsamp' incorporates:
   *  Gain: '<S161>/Derivative Gain'
   *
   * About '<S165>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_Tsamp_j = samerHARDWAREPOTread_P.DiscretePIDController1_D_a *
    samerHARDWAREPOTread_B.Abs4_m * samerHARDWAREPOTread_P.Tsamp_WtEt_d;

  /* Sum: '<S179>/Sum' incorporates:
   *  Delay: '<S163>/UD'
   *  Gain: '<S175>/Proportional Gain'
   *  Sum: '<S163>/Diff'
   */
  samerHARDWAREPOTread_B.Saturation1_p =
    samerHARDWAREPOTread_P.DiscretePIDController1_P_o *
    samerHARDWAREPOTread_B.Abs4_m + (rtb_Tsamp_j -
    samerHARDWAREPOTread_DW.UD_DSTATE_b);

  /* Saturate: '<S6>/Saturation1' */
  if (samerHARDWAREPOTread_B.Saturation1_p >
      samerHARDWAREPOTread_P.Saturation1_UpperSat_k) {
    /* Sum: '<S179>/Sum' incorporates:
     *  Saturate: '<S6>/Saturation1'
     */
    samerHARDWAREPOTread_B.Saturation1_p =
      samerHARDWAREPOTread_P.Saturation1_UpperSat_k;
  } else if (samerHARDWAREPOTread_B.Saturation1_p <
             samerHARDWAREPOTread_P.Saturation1_LowerSat_b) {
    /* Sum: '<S179>/Sum' incorporates:
     *  Saturate: '<S6>/Saturation1'
     */
    samerHARDWAREPOTread_B.Saturation1_p =
      samerHARDWAREPOTread_P.Saturation1_LowerSat_b;
  }

  /* End of Saturate: '<S6>/Saturation1' */

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   */
  if (samerHARDWAREPOTread_B.Abs4_m > samerHARDWAREPOTread_P.Switch_Threshold_d)
  {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_P.Constant_Value_o;
  } else {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.Saturation1_p;
  }

  /* Gain: '<S6>/Gain4' incorporates:
   *  Switch: '<S6>/Switch'
   */
  rtb_Gain4_o = samerHARDWAREPOTread_P.Gain4_Gain_h * samerHARDWAREPOTread_B.cy;

  /* MATLAB Function: '<S6>/MATLAB Function1' */
  samerHARDWAREPO_MATLABFunction1(samerHARDWAREPOTread_B.sf_MATLABFunction_hb.y,
    rtb_Gain4_o, &samerHARDWAREPOTread_B.sf_MATLABFunction1_k,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction1_k);

  /* MATLABSystem: '<S6>/PWM2' */
  samerHARDWAREPOTread_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (10UL);

  /* Start for MATLABSystem: '<S6>/PWM2' */
  if (samerHARDWAREPOTread_B.sf_MATLABFunction1_k.y <= 255.0) {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.sf_MATLABFunction1_k.y;
  } else {
    samerHARDWAREPOTread_B.cy = 255.0;
  }

  if (!(samerHARDWAREPOTread_B.cy >= 0.0)) {
    samerHARDWAREPOTread_B.cy = 0.0;
  }

  /* MATLABSystem: '<S6>/PWM2' */
  MW_PWM_SetDutyCycle(samerHARDWAREPOTread_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWAREPOTread_B.cy);

  /* MATLAB Function: '<S6>/MATLAB Function2' */
  samerHARDWAREPO_MATLABFunction1(samerHARDWAREPOTread_B.sf_MATLABFunction_hb.x,
    rtb_Gain4_o, &samerHARDWAREPOTread_B.sf_MATLABFunction2_m,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction2_m);

  /* Abs: '<S6>/Abs' incorporates:
   *  Sum: '<S6>/Add2'
   */
  samerHARDWAREPOTread_B.Abs_n = fabs
    (samerHARDWAREPOTread_B.sf_MATLABFunction1_k.y -
     samerHARDWAREPOTread_B.sf_MATLABFunction2_m.y);

  /* MATLABSystem: '<S6>/PWM3' */
  samerHARDWAREPOTread_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (11UL);

  /* Start for MATLABSystem: '<S6>/PWM3' */
  if (samerHARDWAREPOTread_B.sf_MATLABFunction2_m.y <= 255.0) {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.sf_MATLABFunction2_m.y;
  } else {
    samerHARDWAREPOTread_B.cy = 255.0;
  }

  if (!(samerHARDWAREPOTread_B.cy >= 0.0)) {
    samerHARDWAREPOTread_B.cy = 0.0;
  }

  /* MATLABSystem: '<S6>/PWM3' */
  MW_PWM_SetDutyCycle(samerHARDWAREPOTread_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWAREPOTread_B.cy);

  /* Sum: '<S5>/Add' */
  samerHARDWAREPOTread_B.Add_l = samerHARDWAREPOTread_B.DataTypeConversion1_d -
    samerHARDWAREPOTread_B.Gain_b;

  /* MATLAB Function: '<S5>/MATLAB Function' */
  samerHARDWAREPOT_MATLABFunction(samerHARDWAREPOTread_B.Add_l,
    &samerHARDWAREPOTread_B.sf_MATLABFunction_d,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction_d);

  /* Abs: '<S5>/Abs4' */
  samerHARDWAREPOTread_B.Abs4_c = fabs(samerHARDWAREPOTread_B.Add_l);

  /* SampleTimeMath: '<S107>/Tsamp' incorporates:
   *  Gain: '<S103>/Derivative Gain'
   *
   * About '<S107>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_Tsamp_m = samerHARDWAREPOTread_P.DiscretePIDController1_D_k *
    samerHARDWAREPOTread_B.Abs4_c * samerHARDWAREPOTread_P.Tsamp_WtEt_b;

  /* Sum: '<S121>/Sum' incorporates:
   *  Delay: '<S105>/UD'
   *  Gain: '<S117>/Proportional Gain'
   *  Sum: '<S105>/Diff'
   */
  samerHARDWAREPOTread_B.Saturation1_i =
    samerHARDWAREPOTread_P.DiscretePIDController1_P_e *
    samerHARDWAREPOTread_B.Abs4_c + (rtb_Tsamp_m -
    samerHARDWAREPOTread_DW.UD_DSTATE_a);

  /* Saturate: '<S5>/Saturation1' */
  if (samerHARDWAREPOTread_B.Saturation1_i >
      samerHARDWAREPOTread_P.Saturation1_UpperSat_j) {
    /* Sum: '<S121>/Sum' incorporates:
     *  Saturate: '<S5>/Saturation1'
     */
    samerHARDWAREPOTread_B.Saturation1_i =
      samerHARDWAREPOTread_P.Saturation1_UpperSat_j;
  } else if (samerHARDWAREPOTread_B.Saturation1_i <
             samerHARDWAREPOTread_P.Saturation1_LowerSat_j) {
    /* Sum: '<S121>/Sum' incorporates:
     *  Saturate: '<S5>/Saturation1'
     */
    samerHARDWAREPOTread_B.Saturation1_i =
      samerHARDWAREPOTread_P.Saturation1_LowerSat_j;
  }

  /* End of Saturate: '<S5>/Saturation1' */

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant'
   */
  if (samerHARDWAREPOTread_B.Abs4_c > samerHARDWAREPOTread_P.Switch_Threshold_n)
  {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_P.Constant_Value_k;
  } else {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.Saturation1_i;
  }

  /* Gain: '<S5>/Gain4' incorporates:
   *  Switch: '<S5>/Switch'
   */
  rtb_Gain4_g = samerHARDWAREPOTread_P.Gain4_Gain_k * samerHARDWAREPOTread_B.cy;

  /* MATLAB Function: '<S5>/MATLAB Function1' */
  samerHARDWAREPO_MATLABFunction1(samerHARDWAREPOTread_B.sf_MATLABFunction_d.y,
    rtb_Gain4_g, &samerHARDWAREPOTread_B.sf_MATLABFunction1_h,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction1_h);

  /* MATLABSystem: '<S5>/PWM2' */
  samerHARDWAREPOTread_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (4UL);

  /* Start for MATLABSystem: '<S5>/PWM2' */
  if (samerHARDWAREPOTread_B.sf_MATLABFunction1_h.y <= 255.0) {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.sf_MATLABFunction1_h.y;
  } else {
    samerHARDWAREPOTread_B.cy = 255.0;
  }

  if (!(samerHARDWAREPOTread_B.cy >= 0.0)) {
    samerHARDWAREPOTread_B.cy = 0.0;
  }

  /* MATLABSystem: '<S5>/PWM2' */
  MW_PWM_SetDutyCycle(samerHARDWAREPOTread_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWAREPOTread_B.cy);

  /* MATLAB Function: '<S5>/MATLAB Function2' */
  samerHARDWAREPO_MATLABFunction1(samerHARDWAREPOTread_B.sf_MATLABFunction_d.x,
    rtb_Gain4_g, &samerHARDWAREPOTread_B.sf_MATLABFunction2_o,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction2_o);

  /* Abs: '<S5>/Abs' incorporates:
   *  Sum: '<S5>/Add2'
   */
  samerHARDWAREPOTread_B.Abs_b = fabs
    (samerHARDWAREPOTread_B.sf_MATLABFunction1_h.y -
     samerHARDWAREPOTread_B.sf_MATLABFunction2_o.y);

  /* MATLABSystem: '<S5>/PWM3' */
  samerHARDWAREPOTread_DW.obj_lt.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (5UL);

  /* Start for MATLABSystem: '<S5>/PWM3' */
  if (samerHARDWAREPOTread_B.sf_MATLABFunction2_o.y <= 255.0) {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.sf_MATLABFunction2_o.y;
  } else {
    samerHARDWAREPOTread_B.cy = 255.0;
  }

  if (!(samerHARDWAREPOTread_B.cy >= 0.0)) {
    samerHARDWAREPOTread_B.cy = 0.0;
  }

  /* MATLABSystem: '<S5>/PWM3' */
  MW_PWM_SetDutyCycle(samerHARDWAREPOTread_DW.obj_lt.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWAREPOTread_B.cy);

  /* Sum: '<S4>/Add' */
  samerHARDWAREPOTread_B.Add_o = samerHARDWAREPOTread_B.DataTypeConversion1 -
    samerHARDWAREPOTread_B.Gain;

  /* MATLAB Function: '<S4>/MATLAB Function' */
  samerHARDWAREPOT_MATLABFunction(samerHARDWAREPOTread_B.Add_o,
    &samerHARDWAREPOTread_B.sf_MATLABFunction_h,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction_h);

  /* Abs: '<S4>/Abs4' */
  samerHARDWAREPOTread_B.Abs4_d = fabs(samerHARDWAREPOTread_B.Add_o);

  /* SampleTimeMath: '<S49>/Tsamp' incorporates:
   *  Gain: '<S45>/Derivative Gain'
   *
   * About '<S49>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_Tsamp_d = samerHARDWAREPOTread_P.DiscretePIDController1_D_e *
    samerHARDWAREPOTread_B.Abs4_d * samerHARDWAREPOTread_P.Tsamp_WtEt_i;

  /* Sum: '<S63>/Sum' incorporates:
   *  Delay: '<S47>/UD'
   *  Gain: '<S59>/Proportional Gain'
   *  Sum: '<S47>/Diff'
   */
  samerHARDWAREPOTread_B.Saturation1_k =
    samerHARDWAREPOTread_P.DiscretePIDController1_P_a *
    samerHARDWAREPOTread_B.Abs4_d + (rtb_Tsamp_d -
    samerHARDWAREPOTread_DW.UD_DSTATE_bd);

  /* Saturate: '<S4>/Saturation1' */
  if (samerHARDWAREPOTread_B.Saturation1_k >
      samerHARDWAREPOTread_P.Saturation1_UpperSat_c) {
    /* Sum: '<S63>/Sum' incorporates:
     *  Saturate: '<S4>/Saturation1'
     */
    samerHARDWAREPOTread_B.Saturation1_k =
      samerHARDWAREPOTread_P.Saturation1_UpperSat_c;
  } else if (samerHARDWAREPOTread_B.Saturation1_k <
             samerHARDWAREPOTread_P.Saturation1_LowerSat_d) {
    /* Sum: '<S63>/Sum' incorporates:
     *  Saturate: '<S4>/Saturation1'
     */
    samerHARDWAREPOTread_B.Saturation1_k =
      samerHARDWAREPOTread_P.Saturation1_LowerSat_d;
  }

  /* End of Saturate: '<S4>/Saturation1' */

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant'
   */
  if (samerHARDWAREPOTread_B.Abs4_d > samerHARDWAREPOTread_P.Switch_Threshold_a)
  {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_P.Constant_Value_c;
  } else {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.Saturation1_k;
  }

  /* Gain: '<S4>/Gain4' incorporates:
   *  Switch: '<S4>/Switch'
   */
  rtb_Gain4_d = samerHARDWAREPOTread_P.Gain4_Gain_i * samerHARDWAREPOTread_B.cy;

  /* MATLAB Function: '<S4>/MATLAB Function1' */
  samerHARDWAREPO_MATLABFunction1(samerHARDWAREPOTread_B.sf_MATLABFunction_h.y,
    rtb_Gain4_d, &samerHARDWAREPOTread_B.sf_MATLABFunction1,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction1);

  /* MATLABSystem: '<S4>/PWM2' */
  samerHARDWAREPOTread_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (2UL);

  /* Start for MATLABSystem: '<S4>/PWM2' */
  if (samerHARDWAREPOTread_B.sf_MATLABFunction1.y <= 255.0) {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.sf_MATLABFunction1.y;
  } else {
    samerHARDWAREPOTread_B.cy = 255.0;
  }

  if (!(samerHARDWAREPOTread_B.cy >= 0.0)) {
    samerHARDWAREPOTread_B.cy = 0.0;
  }

  /* MATLABSystem: '<S4>/PWM2' */
  MW_PWM_SetDutyCycle(samerHARDWAREPOTread_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWAREPOTread_B.cy);

  /* MATLAB Function: '<S4>/MATLAB Function2' */
  samerHARDWAREPO_MATLABFunction1(samerHARDWAREPOTread_B.sf_MATLABFunction_h.x,
    rtb_Gain4_d, &samerHARDWAREPOTread_B.sf_MATLABFunction2,
    &samerHARDWAREPOTread_DW.sf_MATLABFunction2);

  /* Abs: '<S4>/Abs' incorporates:
   *  Sum: '<S4>/Add2'
   */
  samerHARDWAREPOTread_B.Abs_ng = fabs
    (samerHARDWAREPOTread_B.sf_MATLABFunction1.y -
     samerHARDWAREPOTread_B.sf_MATLABFunction2.y);

  /* MATLABSystem: '<S4>/PWM3' */
  samerHARDWAREPOTread_DW.obj_gy.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (3UL);

  /* Start for MATLABSystem: '<S4>/PWM3' */
  if (samerHARDWAREPOTread_B.sf_MATLABFunction2.y <= 255.0) {
    samerHARDWAREPOTread_B.cy = samerHARDWAREPOTread_B.sf_MATLABFunction2.y;
  } else {
    samerHARDWAREPOTread_B.cy = 255.0;
  }

  if (!(samerHARDWAREPOTread_B.cy >= 0.0)) {
    samerHARDWAREPOTread_B.cy = 0.0;
  }

  /* MATLABSystem: '<S4>/PWM3' */
  MW_PWM_SetDutyCycle(samerHARDWAREPOTread_DW.obj_gy.PWMDriverObj.MW_PWM_HANDLE,
                      samerHARDWAREPOTread_B.cy);

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  samerHARDWAREPOTread_DW.UnitDelay_DSTATE =
    samerHARDWAREPOTread_B.DataTypeConversion3;

  /* Update for UnitDelay: '<S4>/Unit Delay1' */
  samerHARDWAREPOTread_DW.UnitDelay1_DSTATE = samerHARDWAREPOTread_B.Sum;

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  samerHARDWAREPOTread_DW.UnitDelay_DSTATE_a =
    samerHARDWAREPOTread_B.DataTypeConversion3_b;

  /* Update for UnitDelay: '<S5>/Unit Delay1' */
  samerHARDWAREPOTread_DW.UnitDelay1_DSTATE_e = samerHARDWAREPOTread_B.Sum_l;

  /* Update for UnitDelay: '<S6>/Unit Delay' */
  samerHARDWAREPOTread_DW.UnitDelay_DSTATE_l =
    samerHARDWAREPOTread_B.DataTypeConversion3_k;

  /* Update for UnitDelay: '<S6>/Unit Delay1' */
  samerHARDWAREPOTread_DW.UnitDelay1_DSTATE_c = samerHARDWAREPOTread_B.Sum_c;

  /* Update for UnitDelay: '<S7>/Unit Delay' */
  samerHARDWAREPOTread_DW.UnitDelay_DSTATE_as =
    samerHARDWAREPOTread_B.DataTypeConversion3_c;

  /* Update for UnitDelay: '<S7>/Unit Delay1' */
  samerHARDWAREPOTread_DW.UnitDelay1_DSTATE_e1 = samerHARDWAREPOTread_B.Sum_m;

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  samerHARDWAREPOTread_DW.UnitDelay_DSTATE_o =
    samerHARDWAREPOTread_B.DataTypeConversion3_p;

  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  samerHARDWAREPOTread_DW.UnitDelay1_DSTATE_cs = samerHARDWAREPOTread_B.Sum_k;

  /* Update for UnitDelay: '<S9>/Unit Delay' */
  samerHARDWAREPOTread_DW.UnitDelay_DSTATE_i =
    samerHARDWAREPOTread_B.DataTypeConversion3_j;

  /* Update for UnitDelay: '<S9>/Unit Delay1' */
  samerHARDWAREPOTread_DW.UnitDelay1_DSTATE_i = samerHARDWAREPOTread_B.Sum_g;

  /* Update for Delay: '<S337>/UD' */
  samerHARDWAREPOTread_DW.UD_DSTATE = samerHARDWAREPOTread_B.Tsamp;

  /* Update for Delay: '<S279>/UD' */
  samerHARDWAREPOTread_DW.UD_DSTATE_o = samerHARDWAREPOTread_B.Tsamp_b;

  /* Update for Delay: '<S221>/UD' */
  samerHARDWAREPOTread_DW.UD_DSTATE_n = samerHARDWAREPOTread_B.Tsamp_a;

  /* Update for Delay: '<S163>/UD' */
  samerHARDWAREPOTread_DW.UD_DSTATE_b = rtb_Tsamp_j;

  /* Update for Delay: '<S105>/UD' */
  samerHARDWAREPOTread_DW.UD_DSTATE_a = rtb_Tsamp_m;

  /* Update for Delay: '<S47>/UD' */
  samerHARDWAREPOTread_DW.UD_DSTATE_bd = rtb_Tsamp_d;

  {                                    /* Sample time: [0.01s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      (((samerHARDWAREPOTread_M->Timing.clockTick1+
         samerHARDWAREPOTread_M->Timing.clockTickH1* 4294967296.0) * 1) + 0);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1, extmodeTime);
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
  if (!(++samerHARDWAREPOTread_M->Timing.clockTick0)) {
    ++samerHARDWAREPOTread_M->Timing.clockTickH0;
  }

  samerHARDWAREPOTread_M->Timing.t[0] =
    samerHARDWAREPOTread_M->Timing.clockTick0 *
    samerHARDWAREPOTread_M->Timing.stepSize0 +
    samerHARDWAREPOTread_M->Timing.clockTickH0 *
    samerHARDWAREPOTread_M->Timing.stepSize0 * 4294967296.0;

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
    samerHARDWAREPOTread_M->Timing.clockTick1++;
    if (!samerHARDWAREPOTread_M->Timing.clockTick1) {
      samerHARDWAREPOTread_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void samerHARDWAREPOTread_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)samerHARDWAREPOTread_M, 0,
                sizeof(RT_MODEL_samerHARDWAREPOTread_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&samerHARDWAREPOTread_M->solverInfo,
                          &samerHARDWAREPOTread_M->Timing.simTimeStep);
    rtsiSetTPtr(&samerHARDWAREPOTread_M->solverInfo, &rtmGetTPtr
                (samerHARDWAREPOTread_M));
    rtsiSetStepSizePtr(&samerHARDWAREPOTread_M->solverInfo,
                       &samerHARDWAREPOTread_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&samerHARDWAREPOTread_M->solverInfo,
                          (&rtmGetErrorStatus(samerHARDWAREPOTread_M)));
    rtsiSetRTModelPtr(&samerHARDWAREPOTread_M->solverInfo,
                      samerHARDWAREPOTread_M);
  }

  rtsiSetSimTimeStep(&samerHARDWAREPOTread_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&samerHARDWAREPOTread_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&samerHARDWAREPOTread_M->solverInfo, false);
  rtsiSetSolverName(&samerHARDWAREPOTread_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(samerHARDWAREPOTread_M, &samerHARDWAREPOTread_M->Timing.tArray[0]);
  rtmSetTFinal(samerHARDWAREPOTread_M, -1);
  samerHARDWAREPOTread_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  samerHARDWAREPOTread_M->Sizes.checksums[0] = (2382388547U);
  samerHARDWAREPOTread_M->Sizes.checksums[1] = (2179842920U);
  samerHARDWAREPOTread_M->Sizes.checksums[2] = (1817714998U);
  samerHARDWAREPOTread_M->Sizes.checksums[3] = (2566752852U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[48];
    samerHARDWAREPOTread_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[42] = &rtAlwaysEnabled;
    systemRan[43] = &rtAlwaysEnabled;
    systemRan[44] = &rtAlwaysEnabled;
    systemRan[45] = &rtAlwaysEnabled;
    systemRan[46] = &rtAlwaysEnabled;
    systemRan[47] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(samerHARDWAREPOTread_M->extModeInfo,
      &samerHARDWAREPOTread_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(samerHARDWAREPOTread_M->extModeInfo,
                        samerHARDWAREPOTread_M->Sizes.checksums);
    rteiSetTFinalTicks(samerHARDWAREPOTread_M->extModeInfo, -1);
  }

  /* block I/O */
  (void) memset(((void *) &samerHARDWAREPOTread_B), 0,
                sizeof(B_samerHARDWAREPOTread_T));

  /* states (dwork) */
  (void) memset((void *)&samerHARDWAREPOTread_DW, 0,
                sizeof(DW_samerHARDWAREPOTread_T));

  /* Start for MATLABSystem: '<S4>/Analog Input' */
  samerHARDWAREPOTread_DW.obj_k.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_d = true;
  samerHARDWAREPOTread_DW.obj_k.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(54UL);
  samerHARDWAREPOTread_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Analog Input' */
  samerHARDWAREPOTread_DW.obj_g.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_g = true;
  samerHARDWAREPOTread_DW.obj_g.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(59UL);
  samerHARDWAREPOTread_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/Analog Input' */
  samerHARDWAREPOTread_DW.obj_n.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_lo = true;
  samerHARDWAREPOTread_DW.obj_n.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(58UL);
  samerHARDWAREPOTread_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/Analog Input' */
  samerHARDWAREPOTread_DW.obj_p.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_jt = true;
  samerHARDWAREPOTread_DW.obj_p.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(57UL);
  samerHARDWAREPOTread_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/Analog Input' */
  samerHARDWAREPOTread_DW.obj_c.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_lv = true;
  samerHARDWAREPOTread_DW.obj_c.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_c.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(56UL);
  samerHARDWAREPOTread_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/Analog Input' */
  samerHARDWAREPOTread_DW.obj.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_j = true;
  samerHARDWAREPOTread_DW.obj.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(55UL);
  samerHARDWAREPOTread_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/PWM2' */
  samerHARDWAREPOTread_DW.obj_po.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_l = true;
  samerHARDWAREPOTread_DW.obj_po.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_po.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL,
    0.0, 0.0);
  samerHARDWAREPOTread_DW.obj_po.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/PWM3' */
  samerHARDWAREPOTread_DW.obj_kc.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty = true;
  samerHARDWAREPOTread_DW.obj_kc.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_kc.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(7UL,
    0.0, 0.0);
  samerHARDWAREPOTread_DW.obj_kc.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/PWM2' */
  samerHARDWAREPOTread_DW.obj_f.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_o = true;
  samerHARDWAREPOTread_DW.obj_f.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(8UL,
    0.0, 0.0);
  samerHARDWAREPOTread_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/PWM3' */
  samerHARDWAREPOTread_DW.obj_nn.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_f = true;
  samerHARDWAREPOTread_DW.obj_nn.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_nn.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL,
    0.0, 0.0);
  samerHARDWAREPOTread_DW.obj_nn.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/PWM2' */
  samerHARDWAREPOTread_DW.obj_j.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_m = true;
  samerHARDWAREPOTread_DW.obj_j.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL,
    0.0, 0.0);
  samerHARDWAREPOTread_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/PWM3' */
  samerHARDWAREPOTread_DW.obj_nt.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_h = true;
  samerHARDWAREPOTread_DW.obj_nt.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_nt.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(13UL,
    0.0, 0.0);
  samerHARDWAREPOTread_DW.obj_nt.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/PWM2' */
  samerHARDWAREPOTread_DW.obj_b.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_c = true;
  samerHARDWAREPOTread_DW.obj_b.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL,
    0.0, 0.0);
  samerHARDWAREPOTread_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/PWM3' */
  samerHARDWAREPOTread_DW.obj_l.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_p = true;
  samerHARDWAREPOTread_DW.obj_l.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL,
    0.0, 0.0);
  samerHARDWAREPOTread_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/PWM2' */
  samerHARDWAREPOTread_DW.obj_pv.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_h1 = true;
  samerHARDWAREPOTread_DW.obj_pv.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4UL,
    0.0, 0.0);
  samerHARDWAREPOTread_DW.obj_pv.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/PWM3' */
  samerHARDWAREPOTread_DW.obj_lt.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_f2 = true;
  samerHARDWAREPOTread_DW.obj_lt.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_lt.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL,
    0.0, 0.0);
  samerHARDWAREPOTread_DW.obj_lt.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/PWM2' */
  samerHARDWAREPOTread_DW.obj_e.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_e = true;
  samerHARDWAREPOTread_DW.obj_e.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(2UL,
    0.0, 0.0);
  samerHARDWAREPOTread_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/PWM3' */
  samerHARDWAREPOTread_DW.obj_gy.matlabCodegenIsDeleted = false;
  samerHARDWAREPOTread_DW.objisempty_ln = true;
  samerHARDWAREPOTread_DW.obj_gy.isInitialized = 1L;
  samerHARDWAREPOTread_DW.obj_gy.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(3UL,
    0.0, 0.0);
  samerHARDWAREPOTread_DW.obj_gy.isSetupComplete = true;

  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
  samerHARDWAREPOTread_DW.UnitDelay_DSTATE =
    samerHARDWAREPOTread_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay1' */
  samerHARDWAREPOTread_DW.UnitDelay1_DSTATE =
    samerHARDWAREPOTread_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay' */
  samerHARDWAREPOTread_DW.UnitDelay_DSTATE_a =
    samerHARDWAREPOTread_P.UnitDelay_InitialCondition_f;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay1' */
  samerHARDWAREPOTread_DW.UnitDelay1_DSTATE_e =
    samerHARDWAREPOTread_P.UnitDelay1_InitialCondition_g;

  /* InitializeConditions for UnitDelay: '<S6>/Unit Delay' */
  samerHARDWAREPOTread_DW.UnitDelay_DSTATE_l =
    samerHARDWAREPOTread_P.UnitDelay_InitialCondition_a;

  /* InitializeConditions for UnitDelay: '<S6>/Unit Delay1' */
  samerHARDWAREPOTread_DW.UnitDelay1_DSTATE_c =
    samerHARDWAREPOTread_P.UnitDelay1_InitialCondition_c;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
  samerHARDWAREPOTread_DW.UnitDelay_DSTATE_as =
    samerHARDWAREPOTread_P.UnitDelay_InitialCondition_as;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay1' */
  samerHARDWAREPOTread_DW.UnitDelay1_DSTATE_e1 =
    samerHARDWAREPOTread_P.UnitDelay1_InitialCondition_h;

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
  samerHARDWAREPOTread_DW.UnitDelay_DSTATE_o =
    samerHARDWAREPOTread_P.UnitDelay_InitialCondition_n;

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay1' */
  samerHARDWAREPOTread_DW.UnitDelay1_DSTATE_cs =
    samerHARDWAREPOTread_P.UnitDelay1_InitialCondition_gp;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
  samerHARDWAREPOTread_DW.UnitDelay_DSTATE_i =
    samerHARDWAREPOTread_P.UnitDelay_InitialCondition_g;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay1' */
  samerHARDWAREPOTread_DW.UnitDelay1_DSTATE_i =
    samerHARDWAREPOTread_P.UnitDelay1_InitialCondition_l;

  /* InitializeConditions for Delay: '<S337>/UD' */
  samerHARDWAREPOTread_DW.UD_DSTATE =
    samerHARDWAREPOTread_P.DiscretePIDController1_Differen;

  /* InitializeConditions for Delay: '<S279>/UD' */
  samerHARDWAREPOTread_DW.UD_DSTATE_o =
    samerHARDWAREPOTread_P.DiscretePIDController1_Differ_d;

  /* InitializeConditions for Delay: '<S221>/UD' */
  samerHARDWAREPOTread_DW.UD_DSTATE_n =
    samerHARDWAREPOTread_P.DiscretePIDController1_Differ_c;

  /* InitializeConditions for Delay: '<S163>/UD' */
  samerHARDWAREPOTread_DW.UD_DSTATE_b =
    samerHARDWAREPOTread_P.DiscretePIDController1_Differ_g;

  /* InitializeConditions for Delay: '<S105>/UD' */
  samerHARDWAREPOTread_DW.UD_DSTATE_a =
    samerHARDWAREPOTread_P.DiscretePIDController1_Differ_j;

  /* InitializeConditions for Delay: '<S47>/UD' */
  samerHARDWAREPOTread_DW.UD_DSTATE_bd =
    samerHARDWAREPOTread_P.DiscretePIDController1_Differ_n;

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
  samerHARDWAREPOTread_DW.sfEvent = samerHARDWAREPOTre_CALL_EVENT_a;

  /* SystemInitialize for MATLAB Function: '<S9>/MATLAB Function' */
  samerHARDWA_MATLABFunction_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction_b);

  /* SystemInitialize for MATLAB Function: '<S9>/MATLAB Function1' */
  samerHARDW_MATLABFunction1_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction1_i3);

  /* SystemInitialize for MATLAB Function: '<S9>/MATLAB Function2' */
  samerHARDW_MATLABFunction1_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction2_h);

  /* SystemInitialize for MATLAB Function: '<S8>/MATLAB Function' */
  samerHARDWA_MATLABFunction_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction_dw);

  /* SystemInitialize for MATLAB Function: '<S8>/MATLAB Function1' */
  samerHARDW_MATLABFunction1_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction1_i);

  /* SystemInitialize for MATLAB Function: '<S8>/MATLAB Function2' */
  samerHARDW_MATLABFunction1_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction2_f);

  /* SystemInitialize for MATLAB Function: '<S7>/MATLAB Function' */
  samerHARDWA_MATLABFunction_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction_m);

  /* SystemInitialize for MATLAB Function: '<S7>/MATLAB Function1' */
  samerHARDW_MATLABFunction1_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction1_g);

  /* SystemInitialize for MATLAB Function: '<S7>/MATLAB Function2' */
  samerHARDW_MATLABFunction1_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction2_e);

  /* SystemInitialize for MATLAB Function: '<S6>/MATLAB Function' */
  samerHARDWA_MATLABFunction_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction_hb);

  /* SystemInitialize for MATLAB Function: '<S6>/MATLAB Function1' */
  samerHARDW_MATLABFunction1_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction1_k);

  /* SystemInitialize for MATLAB Function: '<S6>/MATLAB Function2' */
  samerHARDW_MATLABFunction1_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction2_m);

  /* SystemInitialize for MATLAB Function: '<S5>/MATLAB Function' */
  samerHARDWA_MATLABFunction_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction_d);

  /* SystemInitialize for MATLAB Function: '<S5>/MATLAB Function1' */
  samerHARDW_MATLABFunction1_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction1_h);

  /* SystemInitialize for MATLAB Function: '<S5>/MATLAB Function2' */
  samerHARDW_MATLABFunction1_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction2_o);

  /* SystemInitialize for MATLAB Function: '<S4>/MATLAB Function' */
  samerHARDWA_MATLABFunction_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction_h);

  /* SystemInitialize for MATLAB Function: '<S4>/MATLAB Function1' */
  samerHARDW_MATLABFunction1_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction1);

  /* SystemInitialize for MATLAB Function: '<S4>/MATLAB Function2' */
  samerHARDW_MATLABFunction1_Init(&samerHARDWAREPOTread_DW.sf_MATLABFunction2);
}

/* Model terminate function */
void samerHARDWAREPOTread_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/Analog Input' */
  if (!samerHARDWAREPOTread_DW.obj_k.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_k.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_k.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(54UL);
      MW_AnalogIn_Close
        (samerHARDWAREPOTread_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Analog Input' */

  /* Terminate for MATLABSystem: '<S5>/Analog Input' */
  if (!samerHARDWAREPOTread_DW.obj_g.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_g.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_g.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(59UL);
      MW_AnalogIn_Close
        (samerHARDWAREPOTread_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Analog Input' */

  /* Terminate for MATLABSystem: '<S6>/Analog Input' */
  if (!samerHARDWAREPOTread_DW.obj_n.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_n.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_n.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(58UL);
      MW_AnalogIn_Close
        (samerHARDWAREPOTread_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Analog Input' */

  /* Terminate for MATLABSystem: '<S7>/Analog Input' */
  if (!samerHARDWAREPOTread_DW.obj_p.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_p.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_p.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(57UL);
      MW_AnalogIn_Close
        (samerHARDWAREPOTread_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Analog Input' */

  /* Terminate for MATLABSystem: '<S8>/Analog Input' */
  if (!samerHARDWAREPOTread_DW.obj_c.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_c.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_c.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_c.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(56UL);
      MW_AnalogIn_Close
        (samerHARDWAREPOTread_DW.obj_c.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/Analog Input' */

  /* Terminate for MATLABSystem: '<S9>/Analog Input' */
  if (!samerHARDWAREPOTread_DW.obj.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(55UL);
      MW_AnalogIn_Close
        (samerHARDWAREPOTread_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/Analog Input' */
  /* Terminate for MATLABSystem: '<S9>/PWM2' */
  if (!samerHARDWAREPOTread_DW.obj_po.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_po.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_po.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_po.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_po.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle
        (samerHARDWAREPOTread_DW.obj_po.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWAREPOTread_DW.obj_po.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(6UL);
      MW_PWM_Close(samerHARDWAREPOTread_DW.obj_po.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/PWM2' */
  /* Terminate for MATLABSystem: '<S9>/PWM3' */
  if (!samerHARDWAREPOTread_DW.obj_kc.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_kc.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_kc.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_kc.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_kc.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(7UL);
      MW_PWM_SetDutyCycle
        (samerHARDWAREPOTread_DW.obj_kc.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWAREPOTread_DW.obj_kc.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(7UL);
      MW_PWM_Close(samerHARDWAREPOTread_DW.obj_kc.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/PWM3' */
  /* Terminate for MATLABSystem: '<S8>/PWM2' */
  if (!samerHARDWAREPOTread_DW.obj_f.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_f.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_f.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(8UL);
      MW_PWM_SetDutyCycle
        (samerHARDWAREPOTread_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWAREPOTread_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(8UL);
      MW_PWM_Close(samerHARDWAREPOTread_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/PWM2' */
  /* Terminate for MATLABSystem: '<S8>/PWM3' */
  if (!samerHARDWAREPOTread_DW.obj_nn.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_nn.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_nn.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_nn.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_nn.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle
        (samerHARDWAREPOTread_DW.obj_nn.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWAREPOTread_DW.obj_nn.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);
      MW_PWM_Close(samerHARDWAREPOTread_DW.obj_nn.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/PWM3' */
  /* Terminate for MATLABSystem: '<S7>/PWM2' */
  if (!samerHARDWAREPOTread_DW.obj_j.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_j.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_j.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(12UL);
      MW_PWM_SetDutyCycle
        (samerHARDWAREPOTread_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWAREPOTread_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(12UL);
      MW_PWM_Close(samerHARDWAREPOTread_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/PWM2' */
  /* Terminate for MATLABSystem: '<S7>/PWM3' */
  if (!samerHARDWAREPOTread_DW.obj_nt.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_nt.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_nt.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_nt.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_nt.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(13UL);
      MW_PWM_SetDutyCycle
        (samerHARDWAREPOTread_DW.obj_nt.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWAREPOTread_DW.obj_nt.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(13UL);
      MW_PWM_Close(samerHARDWAREPOTread_DW.obj_nt.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/PWM3' */
  /* Terminate for MATLABSystem: '<S6>/PWM2' */
  if (!samerHARDWAREPOTread_DW.obj_b.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_b.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_b.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle
        (samerHARDWAREPOTread_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWAREPOTread_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(10UL);
      MW_PWM_Close(samerHARDWAREPOTread_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM2' */
  /* Terminate for MATLABSystem: '<S6>/PWM3' */
  if (!samerHARDWAREPOTread_DW.obj_l.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_l.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_l.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle
        (samerHARDWAREPOTread_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWAREPOTread_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(11UL);
      MW_PWM_Close(samerHARDWAREPOTread_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM3' */
  /* Terminate for MATLABSystem: '<S5>/PWM2' */
  if (!samerHARDWAREPOTread_DW.obj_pv.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_pv.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_pv.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_pv.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(4UL);
      MW_PWM_SetDutyCycle
        (samerHARDWAREPOTread_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWAREPOTread_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(4UL);
      MW_PWM_Close(samerHARDWAREPOTread_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM2' */
  /* Terminate for MATLABSystem: '<S5>/PWM3' */
  if (!samerHARDWAREPOTread_DW.obj_lt.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_lt.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_lt.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_lt.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_lt.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle
        (samerHARDWAREPOTread_DW.obj_lt.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWAREPOTread_DW.obj_lt.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);
      MW_PWM_Close(samerHARDWAREPOTread_DW.obj_lt.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM3' */
  /* Terminate for MATLABSystem: '<S4>/PWM2' */
  if (!samerHARDWAREPOTread_DW.obj_e.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_e.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_e.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(2UL);
      MW_PWM_SetDutyCycle
        (samerHARDWAREPOTread_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWAREPOTread_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(2UL);
      MW_PWM_Close(samerHARDWAREPOTread_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM2' */
  /* Terminate for MATLABSystem: '<S4>/PWM3' */
  if (!samerHARDWAREPOTread_DW.obj_gy.matlabCodegenIsDeleted) {
    samerHARDWAREPOTread_DW.obj_gy.matlabCodegenIsDeleted = true;
    if ((samerHARDWAREPOTread_DW.obj_gy.isInitialized == 1L) &&
        samerHARDWAREPOTread_DW.obj_gy.isSetupComplete) {
      samerHARDWAREPOTread_DW.obj_gy.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(3UL);
      MW_PWM_SetDutyCycle
        (samerHARDWAREPOTread_DW.obj_gy.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      samerHARDWAREPOTread_DW.obj_gy.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(3UL);
      MW_PWM_Close(samerHARDWAREPOTread_DW.obj_gy.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM3' */
}
