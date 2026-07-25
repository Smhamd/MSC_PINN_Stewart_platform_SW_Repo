/*
 * samerHARDWARE0x2DPOTread_restored_from_autosave.c
 *
 * Code generation for model "samerHARDWARE0x2DPOTread_restored_from_autosave".
 *
 * Model version              : 6.11
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Sun Jul 12 04:06:30 2026
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "samerHARDWARE0x2DPOTread_restored_from_autosave.h"
#include "samerHARDWARE0x2DPOTread_restored_from_autosave_private.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>

/* Block signals (default storage) */
B_samerHARDWARE0x2DPOTread_re_T samerHARDWARE0x2DPOTread_rest_B;

/* Block states (default storage) */
DW_samerHARDWARE0x2DPOTread_r_T samerHARDWARE0x2DPOTread_res_DW;

/* Real-time model */
static RT_MODEL_samerHARDWARE0x2DPOT_T samerHARDWARE0x2DPOTread_res_M_;
RT_MODEL_samerHARDWARE0x2DPOT_T *const samerHARDWARE0x2DPOTread_res_M =
  &samerHARDWARE0x2DPOTread_res_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void samerHARDWARE0x2DPOTread_restored_from_autosave_step(void)
{
  real_T tmp;
  uint8_T tmp_0;

  /* MATLABSystem: '<Root>/Analog Input' */
  samerHARDWARE0x2DPOTread_res_DW.obj_ar.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(54UL);

  /* MATLABSystem: '<Root>/Analog Input' */
  MW_AnalogInSingle_ReadResult
    (samerHARDWARE0x2DPOTread_res_DW.obj_ar.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &samerHARDWARE0x2DPOTread_rest_B.M1, MW_ANALOGIN_UINT16);

  /* MATLABSystem: '<Root>/Analog Input1' */
  samerHARDWARE0x2DPOTread_res_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(55UL);

  /* MATLABSystem: '<Root>/Analog Input1' */
  MW_AnalogInSingle_ReadResult
    (samerHARDWARE0x2DPOTread_res_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &samerHARDWARE0x2DPOTread_rest_B.M2, MW_ANALOGIN_UINT16);

  /* MATLABSystem: '<Root>/Analog Input2' */
  samerHARDWARE0x2DPOTread_res_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(56UL);

  /* MATLABSystem: '<Root>/Analog Input2' */
  MW_AnalogInSingle_ReadResult
    (samerHARDWARE0x2DPOTread_res_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &samerHARDWARE0x2DPOTread_rest_B.M3, MW_ANALOGIN_UINT16);

  /* MATLABSystem: '<Root>/Analog Input3' */
  samerHARDWARE0x2DPOTread_res_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(57UL);

  /* MATLABSystem: '<Root>/Analog Input3' */
  MW_AnalogInSingle_ReadResult
    (samerHARDWARE0x2DPOTread_res_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &samerHARDWARE0x2DPOTread_rest_B.M4, MW_ANALOGIN_UINT16);

  /* MATLABSystem: '<Root>/Analog Input4' */
  samerHARDWARE0x2DPOTread_res_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(58UL);

  /* MATLABSystem: '<Root>/Analog Input4' */
  MW_AnalogInSingle_ReadResult
    (samerHARDWARE0x2DPOTread_res_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &samerHARDWARE0x2DPOTread_rest_B.M5, MW_ANALOGIN_UINT16);

  /* MATLABSystem: '<Root>/Analog Input5' */
  samerHARDWARE0x2DPOTread_res_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(59UL);

  /* MATLABSystem: '<Root>/Analog Input5' */
  MW_AnalogInSingle_ReadResult
    (samerHARDWARE0x2DPOTread_res_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &samerHARDWARE0x2DPOTread_rest_B.M6, MW_ANALOGIN_UINT16);

  /* SignalConversion generated from: '<Root>/Mux' */
  samerHARDWARE0x2DPOTread_rest_B.TmpSignalConversionAtTAQSigLogg[0] =
    samerHARDWARE0x2DPOTread_rest_B.M1;
  samerHARDWARE0x2DPOTread_rest_B.TmpSignalConversionAtTAQSigLogg[1] =
    samerHARDWARE0x2DPOTread_rest_B.M2;
  samerHARDWARE0x2DPOTread_rest_B.TmpSignalConversionAtTAQSigLogg[2] =
    samerHARDWARE0x2DPOTread_rest_B.M3;
  samerHARDWARE0x2DPOTread_rest_B.TmpSignalConversionAtTAQSigLogg[3] =
    samerHARDWARE0x2DPOTread_rest_B.M4;
  samerHARDWARE0x2DPOTread_rest_B.TmpSignalConversionAtTAQSigLogg[4] =
    samerHARDWARE0x2DPOTread_rest_B.M5;
  samerHARDWARE0x2DPOTread_rest_B.TmpSignalConversionAtTAQSigLogg[5] =
    samerHARDWARE0x2DPOTread_rest_B.M6;

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  tmp = rt_roundd_snf(samerHARDWARE0x2DPOTread_rest_P.Constant1_Value);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(2, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output1' */

  /* MATLABSystem: '<Root>/Digital Output10' incorporates:
   *  Constant: '<Root>/Constant10'
   */
  tmp = rt_roundd_snf(samerHARDWARE0x2DPOTread_rest_P.Constant10_Value);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(11, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output10' */

  /* MATLABSystem: '<Root>/Digital Output11' incorporates:
   *  Constant: '<Root>/Constant11'
   */
  tmp = rt_roundd_snf(samerHARDWARE0x2DPOTread_rest_P.Constant11_Value);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(12, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output11' */

  /* MATLABSystem: '<Root>/Digital Output12' incorporates:
   *  Constant: '<Root>/Constant12'
   */
  tmp = rt_roundd_snf(samerHARDWARE0x2DPOTread_rest_P.Constant12_Value);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output12' */

  /* MATLABSystem: '<Root>/Digital Output2' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  tmp = rt_roundd_snf(samerHARDWARE0x2DPOTread_rest_P.Constant2_Value);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(4, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output2' */

  /* MATLABSystem: '<Root>/Digital Output3' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  tmp = rt_roundd_snf(samerHARDWARE0x2DPOTread_rest_P.Constant3_Value);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(5, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output3' */

  /* MATLABSystem: '<Root>/Digital Output4' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  tmp = rt_roundd_snf(samerHARDWARE0x2DPOTread_rest_P.Constant4_Value);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(3, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output4' */

  /* MATLABSystem: '<Root>/Digital Output5' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  tmp = rt_roundd_snf(samerHARDWARE0x2DPOTread_rest_P.Constant5_Value);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(6, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output5' */

  /* MATLABSystem: '<Root>/Digital Output6' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  tmp = rt_roundd_snf(samerHARDWARE0x2DPOTread_rest_P.Constant6_Value);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output6' */

  /* MATLABSystem: '<Root>/Digital Output7' incorporates:
   *  Constant: '<Root>/Constant7'
   */
  tmp = rt_roundd_snf(samerHARDWARE0x2DPOTread_rest_P.Constant7_Value);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output7' */

  /* MATLABSystem: '<Root>/Digital Output8' incorporates:
   *  Constant: '<Root>/Constant8'
   */
  tmp = rt_roundd_snf(samerHARDWARE0x2DPOTread_rest_P.Constant8_Value);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(9, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output8' */

  /* MATLABSystem: '<Root>/Digital Output9' incorporates:
   *  Constant: '<Root>/Constant9'
   */
  tmp = rt_roundd_snf(samerHARDWARE0x2DPOTread_rest_P.Constant9_Value);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(10, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output9' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  samerHARDWARE0x2DPOTread_res_M->Timing.clockTick0++;
  if (!samerHARDWARE0x2DPOTread_res_M->Timing.clockTick0) {
    samerHARDWARE0x2DPOTread_res_M->Timing.clockTickH0++;
  }
}

/* Model initialize function */
void samerHARDWARE0x2DPOTread_restored_from_autosave_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)samerHARDWARE0x2DPOTread_res_M, 0,
                sizeof(RT_MODEL_samerHARDWARE0x2DPOT_T));
  rtmSetTFinal(samerHARDWARE0x2DPOTread_res_M, -1);

  /* External mode info */
  samerHARDWARE0x2DPOTread_res_M->Sizes.checksums[0] = (1861367445U);
  samerHARDWARE0x2DPOTread_res_M->Sizes.checksums[1] = (1919228633U);
  samerHARDWARE0x2DPOTread_res_M->Sizes.checksums[2] = (1721151919U);
  samerHARDWARE0x2DPOTread_res_M->Sizes.checksums[3] = (307321431U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[19];
    samerHARDWARE0x2DPOTread_res_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(samerHARDWARE0x2DPOTread_res_M->extModeInfo,
      &samerHARDWARE0x2DPOTread_res_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(samerHARDWARE0x2DPOTread_res_M->extModeInfo,
                        samerHARDWARE0x2DPOTread_res_M->Sizes.checksums);
    rteiSetTFinalTicks(samerHARDWARE0x2DPOTread_res_M->extModeInfo, -1);
  }

  /* block I/O */
  (void) memset(((void *) &samerHARDWARE0x2DPOTread_rest_B), 0,
                sizeof(B_samerHARDWARE0x2DPOTread_re_T));

  /* states (dwork) */
  (void) memset((void *)&samerHARDWARE0x2DPOTread_res_DW, 0,
                sizeof(DW_samerHARDWARE0x2DPOTread_r_T));

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  samerHARDWARE0x2DPOTread_res_DW.obj_ar.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_mm = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_ar.isInitialized = 1L;
  samerHARDWARE0x2DPOTread_res_DW.obj_ar.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(54UL);
  samerHARDWARE0x2DPOTread_res_DW.obj_ar.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  samerHARDWARE0x2DPOTread_res_DW.obj_p.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_a4 = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_p.isInitialized = 1L;
  samerHARDWARE0x2DPOTread_res_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(55UL);
  samerHARDWARE0x2DPOTread_res_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input2' */
  samerHARDWARE0x2DPOTread_res_DW.obj_l.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_c = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_l.isInitialized = 1L;
  samerHARDWARE0x2DPOTread_res_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(56UL);
  samerHARDWARE0x2DPOTread_res_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input3' */
  samerHARDWARE0x2DPOTread_res_DW.obj_a.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_a0 = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_a.isInitialized = 1L;
  samerHARDWARE0x2DPOTread_res_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(57UL);
  samerHARDWARE0x2DPOTread_res_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input4' */
  samerHARDWARE0x2DPOTread_res_DW.obj_n.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_f = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_n.isInitialized = 1L;
  samerHARDWARE0x2DPOTread_res_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(58UL);
  samerHARDWARE0x2DPOTread_res_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input5' */
  samerHARDWARE0x2DPOTread_res_DW.obj.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_ij = true;
  samerHARDWARE0x2DPOTread_res_DW.obj.isInitialized = 1L;
  samerHARDWARE0x2DPOTread_res_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(59UL);
  samerHARDWARE0x2DPOTread_res_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  samerHARDWARE0x2DPOTread_res_DW.obj_mm.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_ga = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_mm.isInitialized = 1L;
  digitalIOSetup(2, 1);
  samerHARDWARE0x2DPOTread_res_DW.obj_mm.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output10' */
  samerHARDWARE0x2DPOTread_res_DW.obj_p4.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_ap = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_p4.isInitialized = 1L;
  digitalIOSetup(11, 1);
  samerHARDWARE0x2DPOTread_res_DW.obj_p4.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output11' */
  samerHARDWARE0x2DPOTread_res_DW.obj_ko.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_o = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_ko.isInitialized = 1L;
  digitalIOSetup(12, 1);
  samerHARDWARE0x2DPOTread_res_DW.obj_ko.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output12' */
  samerHARDWARE0x2DPOTread_res_DW.obj_m.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_mk = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(13, 1);
  samerHARDWARE0x2DPOTread_res_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output2' */
  samerHARDWARE0x2DPOTread_res_DW.obj_pl.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_a = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_pl.isInitialized = 1L;
  digitalIOSetup(4, 1);
  samerHARDWARE0x2DPOTread_res_DW.obj_pl.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output3' */
  samerHARDWARE0x2DPOTread_res_DW.obj_c.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_i = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_c.isInitialized = 1L;
  digitalIOSetup(5, 1);
  samerHARDWARE0x2DPOTread_res_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output4' */
  samerHARDWARE0x2DPOTread_res_DW.obj_f.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_d = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_f.isInitialized = 1L;
  digitalIOSetup(3, 1);
  samerHARDWARE0x2DPOTread_res_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output5' */
  samerHARDWARE0x2DPOTread_res_DW.obj_k.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_g = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_k.isInitialized = 1L;
  digitalIOSetup(6, 1);
  samerHARDWARE0x2DPOTread_res_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output6' */
  samerHARDWARE0x2DPOTread_res_DW.obj_e.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_mn = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_e.isInitialized = 1L;
  digitalIOSetup(7, 1);
  samerHARDWARE0x2DPOTread_res_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output7' */
  samerHARDWARE0x2DPOTread_res_DW.obj_o.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_m = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_o.isInitialized = 1L;
  digitalIOSetup(8, 1);
  samerHARDWARE0x2DPOTread_res_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output8' */
  samerHARDWARE0x2DPOTread_res_DW.obj_pu.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty_b = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_pu.isInitialized = 1L;
  digitalIOSetup(9, 1);
  samerHARDWARE0x2DPOTread_res_DW.obj_pu.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output9' */
  samerHARDWARE0x2DPOTread_res_DW.obj_d.matlabCodegenIsDeleted = false;
  samerHARDWARE0x2DPOTread_res_DW.objisempty = true;
  samerHARDWARE0x2DPOTread_res_DW.obj_d.isInitialized = 1L;
  digitalIOSetup(10, 1);
  samerHARDWARE0x2DPOTread_res_DW.obj_d.isSetupComplete = true;
}

/* Model terminate function */
void samerHARDWARE0x2DPOTread_restored_from_autosave_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_ar.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_ar.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE0x2DPOTread_res_DW.obj_ar.isInitialized == 1L) &&
        samerHARDWARE0x2DPOTread_res_DW.obj_ar.isSetupComplete) {
      samerHARDWARE0x2DPOTread_res_DW.obj_ar.AnalogInDriverObj.MW_ANALOGIN_HANDLE
        = MW_AnalogIn_GetHandle(54UL);
      MW_AnalogIn_Close
        (samerHARDWARE0x2DPOTread_res_DW.obj_ar.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_p.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE0x2DPOTread_res_DW.obj_p.isInitialized == 1L) &&
        samerHARDWARE0x2DPOTread_res_DW.obj_p.isSetupComplete) {
      samerHARDWARE0x2DPOTread_res_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE
        = MW_AnalogIn_GetHandle(55UL);
      MW_AnalogIn_Close
        (samerHARDWARE0x2DPOTread_res_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input2' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_l.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE0x2DPOTread_res_DW.obj_l.isInitialized == 1L) &&
        samerHARDWARE0x2DPOTread_res_DW.obj_l.isSetupComplete) {
      samerHARDWARE0x2DPOTread_res_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE
        = MW_AnalogIn_GetHandle(56UL);
      MW_AnalogIn_Close
        (samerHARDWARE0x2DPOTread_res_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input2' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input3' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_a.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE0x2DPOTread_res_DW.obj_a.isInitialized == 1L) &&
        samerHARDWARE0x2DPOTread_res_DW.obj_a.isSetupComplete) {
      samerHARDWARE0x2DPOTread_res_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE
        = MW_AnalogIn_GetHandle(57UL);
      MW_AnalogIn_Close
        (samerHARDWARE0x2DPOTread_res_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input3' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input4' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_n.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE0x2DPOTread_res_DW.obj_n.isInitialized == 1L) &&
        samerHARDWARE0x2DPOTread_res_DW.obj_n.isSetupComplete) {
      samerHARDWARE0x2DPOTread_res_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE
        = MW_AnalogIn_GetHandle(58UL);
      MW_AnalogIn_Close
        (samerHARDWARE0x2DPOTread_res_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input4' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input5' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj.matlabCodegenIsDeleted = true;
    if ((samerHARDWARE0x2DPOTread_res_DW.obj.isInitialized == 1L) &&
        samerHARDWARE0x2DPOTread_res_DW.obj.isSetupComplete) {
      samerHARDWARE0x2DPOTread_res_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(59UL);
      MW_AnalogIn_Close
        (samerHARDWARE0x2DPOTread_res_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input5' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_mm.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_mm.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output10' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_p4.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_p4.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output10' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output11' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_ko.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_ko.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output11' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output12' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_m.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output12' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_pl.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_pl.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_c.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output4' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_f.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output5' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_k.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output5' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output6' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_e.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output6' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output7' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_o.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output7' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output8' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_pu.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_pu.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output8' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output9' */
  if (!samerHARDWARE0x2DPOTread_res_DW.obj_d.matlabCodegenIsDeleted) {
    samerHARDWARE0x2DPOTread_res_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output9' */
}
