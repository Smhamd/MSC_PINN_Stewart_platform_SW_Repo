/*
 * samerHARDWARE0x2DPOTread_restored_from_autosave.h
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

#ifndef samerHARDWARE0x2DPOTread_restored_from_autosave_h_
#define samerHARDWARE0x2DPOTread_restored_from_autosave_h_
#ifndef samerHARDWARE0x2DPOTread_restored_from_autosave_COMMON_INCLUDES_
#define samerHARDWARE0x2DPOTread_restored_from_autosave_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#endif    /* samerHARDWARE0x2DPOTread_restored_from_autosave_COMMON_INCLUDES_ */

#include "samerHARDWARE0x2DPOTread_restored_from_autosave_types.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&)
#endif

#define samerHARDWARE0x2DPOTread_restored_from_autosave_M (samerHARDWARE0x2DPOTread_res_M)

/* Block signals (default storage) */
typedef struct {
  uint16_T TmpSignalConversionAtTAQSigLogg[6];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  uint16_T M6;                         /* '<Root>/Analog Input5' */
  uint16_T M5;                         /* '<Root>/Analog Input4' */
  uint16_T M4;                         /* '<Root>/Analog Input3' */
  uint16_T M3;                         /* '<Root>/Analog Input2' */
  uint16_T M2;                         /* '<Root>/Analog Input1' */
  uint16_T M1;                         /* '<Root>/Analog Input' */
} B_samerHARDWARE0x2DPOTread_re_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input5' */
  codertarget_arduinobase_inter_T obj_n;/* '<Root>/Analog Input4' */
  codertarget_arduinobase_inter_T obj_a;/* '<Root>/Analog Input3' */
  codertarget_arduinobase_inter_T obj_l;/* '<Root>/Analog Input2' */
  codertarget_arduinobase_inter_T obj_p;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_ar;/* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_d;/* '<Root>/Digital Output9' */
  codertarget_arduinobase_block_T obj_pu;/* '<Root>/Digital Output8' */
  codertarget_arduinobase_block_T obj_o;/* '<Root>/Digital Output7' */
  codertarget_arduinobase_block_T obj_e;/* '<Root>/Digital Output6' */
  codertarget_arduinobase_block_T obj_k;/* '<Root>/Digital Output5' */
  codertarget_arduinobase_block_T obj_f;/* '<Root>/Digital Output4' */
  codertarget_arduinobase_block_T obj_c;/* '<Root>/Digital Output3' */
  codertarget_arduinobase_block_T obj_pl;/* '<Root>/Digital Output2' */
  codertarget_arduinobase_block_T obj_m;/* '<Root>/Digital Output12' */
  codertarget_arduinobase_block_T obj_ko;/* '<Root>/Digital Output11' */
  codertarget_arduinobase_block_T obj_p4;/* '<Root>/Digital Output10' */
  codertarget_arduinobase_block_T obj_mm;/* '<Root>/Digital Output1' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  boolean_T objisempty;                /* '<Root>/Digital Output9' */
  boolean_T objisempty_b;              /* '<Root>/Digital Output8' */
  boolean_T objisempty_m;              /* '<Root>/Digital Output7' */
  boolean_T objisempty_mn;             /* '<Root>/Digital Output6' */
  boolean_T objisempty_g;              /* '<Root>/Digital Output5' */
  boolean_T objisempty_d;              /* '<Root>/Digital Output4' */
  boolean_T objisempty_i;              /* '<Root>/Digital Output3' */
  boolean_T objisempty_a;              /* '<Root>/Digital Output2' */
  boolean_T objisempty_mk;             /* '<Root>/Digital Output12' */
  boolean_T objisempty_o;              /* '<Root>/Digital Output11' */
  boolean_T objisempty_ap;             /* '<Root>/Digital Output10' */
  boolean_T objisempty_ga;             /* '<Root>/Digital Output1' */
  boolean_T objisempty_ij;             /* '<Root>/Analog Input5' */
  boolean_T objisempty_f;              /* '<Root>/Analog Input4' */
  boolean_T objisempty_a0;             /* '<Root>/Analog Input3' */
  boolean_T objisempty_c;              /* '<Root>/Analog Input2' */
  boolean_T objisempty_a4;             /* '<Root>/Analog Input1' */
  boolean_T objisempty_mm;             /* '<Root>/Analog Input' */
} DW_samerHARDWARE0x2DPOTread_r_T;

/* Parameters (default storage) */
struct P_samerHARDWARE0x2DPOTread_re_T_ {
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant10_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Constant11_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant11'
                                        */
  real_T Constant12_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant12'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant9'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_samerHARDWARE0x2DPOTr_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_samerHARDWARE0x2DPOTread_re_T samerHARDWARE0x2DPOTread_rest_P;

/* Block signals (default storage) */
extern B_samerHARDWARE0x2DPOTread_re_T samerHARDWARE0x2DPOTread_rest_B;

/* Block states (default storage) */
extern DW_samerHARDWARE0x2DPOTread_r_T samerHARDWARE0x2DPOTread_res_DW;

/* Model entry point functions */
extern void samerHARDWARE0x2DPOTread_restored_from_autosave_initialize(void);
extern void samerHARDWARE0x2DPOTread_restored_from_autosave_step(void);
extern void samerHARDWARE0x2DPOTread_restored_from_autosave_terminate(void);

/* Real-time Model object */
extern RT_MODEL_samerHARDWARE0x2DPOT_T *const samerHARDWARE0x2DPOTread_res_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'samerHARDWARE0x2DPOTread_restored_from_autosave'
 */
#endif                  /* samerHARDWARE0x2DPOTread_restored_from_autosave_h_ */
