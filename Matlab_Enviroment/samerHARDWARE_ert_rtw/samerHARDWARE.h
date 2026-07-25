/*
 * samerHARDWARE.h
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

#ifndef samerHARDWARE_h_
#define samerHARDWARE_h_
#ifndef samerHARDWARE_COMMON_INCLUDES_
#define samerHARDWARE_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "MW_AnalogIn.h"
#endif                                 /* samerHARDWARE_COMMON_INCLUDES_ */

#include "samerHARDWARE_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
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

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals for system '<S5>/MATLAB Function' */
typedef struct {
  real_T y;                            /* '<S5>/MATLAB Function' */
  real_T x;                            /* '<S5>/MATLAB Function' */
} B_MATLABFunction_samerHARDWAR_T;

/* Block states (default storage) for system '<S5>/MATLAB Function' */
typedef struct {
  int32_T sfEvent;                     /* '<S5>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S5>/MATLAB Function' */
} DW_MATLABFunction_samerHARDWA_T;

/* Block signals for system '<S5>/MATLAB Function1' */
typedef struct {
  real_T y;                            /* '<S5>/MATLAB Function1' */
} B_MATLABFunction1_samerHARDWA_T;

/* Block states (default storage) for system '<S5>/MATLAB Function1' */
typedef struct {
  int32_T sfEvent;                     /* '<S5>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit;    /* '<S5>/MATLAB Function1' */
} DW_MATLABFunction1_samerHARDW_T;

/* Block signals (default storage) */
typedef struct {
  real_T b[18];
  real_T flags[15];
  real_T R[9];
  real_T UnitDelay[6];                 /* '<Root>/Unit Delay' */
  real_T Reshape1[6];                  /* '<Root>/Reshape1' */
  real_T P_start[3];
  real_T L[3];
  real32_T L_cmd_mm[6];
  real_T Gain16;                       /* '<S11>/Gain16' */
  real_T Add1;                         /* '<S9>/Add1' */
  real_T Gain;                         /* '<S11>/Gain' */
  real_T Add1_d;                       /* '<S5>/Add1' */
  real_T Gain4;                        /* '<S11>/Gain4' */
  real_T Add1_e;                       /* '<S6>/Add1' */
  real_T Gain8;                        /* '<S11>/Gain8' */
  real_T Add1_eq;                      /* '<S7>/Add1' */
  real_T Gain12;                       /* '<S11>/Gain12' */
  real_T Add1_a;                       /* '<S8>/Add1' */
  real_T Gain20;                       /* '<S11>/Gain20' */
  real_T Add1_f;                       /* '<S10>/Add1' */
  real_T TmpSignalConversionAt_asyncqueu[25];
  /* '<Root>/TmpSignal ConversionAt_asyncqueue_inserted_for_To Workspace2Inport1' */
  real_T Add;                          /* '<S10>/Add' */
  real_T Abs4;                         /* '<S10>/Abs4' */
  real_T Saturation1;                  /* '<S10>/Saturation1' */
  real_T Abs4_n;                       /* '<S8>/Abs4' */
  real_T Saturation1_g;                /* '<S8>/Saturation1' */
  real_T Abs4_m;                       /* '<S7>/Abs4' */
  real_T Saturation1_p;                /* '<S7>/Saturation1' */
  real_T Abs4_c;                       /* '<S6>/Abs4' */
  real_T Saturation1_i;                /* '<S6>/Saturation1' */
  real_T Abs4_d;                       /* '<S5>/Abs4' */
  real_T Saturation1_k;                /* '<S5>/Saturation1' */
  real_T Abs4_ns;                      /* '<S9>/Abs4' */
  real_T Saturation1_a;                /* '<S9>/Saturation1' */
  real_T u_des[6];                     /* '<Root>/MATLAB Function4' */
  real_T t_traj;                       /* '<Root>/MATLAB Function2' */
  real_T deltaL[6];                    /* '<Root>/MATLAB Function' */
  real_T X;
  real_T Y;
  real_T Z;
  real_T Roll;
  real_T Pitch;
  real_T Yaw;
  real_T activeSlot;
  real_T tau;
  real_T Clock1;                       /* '<Root>/Clock1' */
  real_T Tsamp_b;                      /* '<S277>/Tsamp' */
  real_T Tsamp_m;                      /* '<S103>/Tsamp' */
  real_T Tsamp_j;                      /* '<S161>/Tsamp' */
  real_T Tsamp_a;                      /* '<S219>/Tsamp' */
  real_T Tsamp;                        /* '<S335>/Tsamp' */
  real_T FilterCoefficient;            /* '<S53>/Filter Coefficient' */
  real_T DataTypeConversion11;         /* '<S11>/Data Type Conversion11' */
  real_T DataTypeConversion8;          /* '<S11>/Data Type Conversion8' */
  real_T DataTypeConversion6;          /* '<S11>/Data Type Conversion6' */
  real_T DataTypeConversion4;          /* '<S11>/Data Type Conversion4' */
  real_T DataTypeConversion3;          /* '<S11>/Data Type Conversion3' */
  real_T DataTypeConversion10;         /* '<S11>/Data Type Conversion10' */
  real_T Gain4_b;                      /* '<S9>/Gain4' */
  real_T Add_m;                        /* '<S9>/Add' */
  real_T Gain4_d;                      /* '<S5>/Gain4' */
  real_T Add_o;                        /* '<S5>/Add' */
  real_T Gain4_g;                      /* '<S6>/Gain4' */
  real_T Add_l;                        /* '<S6>/Add' */
  real_T Gain4_o;                      /* '<S7>/Gain4' */
  real_T Add_c;                        /* '<S7>/Add' */
  real_T Gain4_m;                      /* '<S8>/Gain4' */
  real_T Add_mb;                       /* '<S8>/Add' */
  real_T Gain4_c;                      /* '<S10>/Gain4' */
  real_T Sum5;                         /* '<S11>/Sum5' */
  real_T Sum3;                         /* '<S11>/Sum3' */
  real_T Sum2;                         /* '<S11>/Sum2' */
  real_T Sum1;                         /* '<S11>/Sum1' */
  real_T Sum;                          /* '<S11>/Sum' */
  real_T Sum4;                         /* '<S11>/Sum4' */
  real_T IntegralGain_j;               /* '<S279>/Integral Gain' */
  real_T IntegralGain_i;               /* '<S47>/Integral Gain' */
  real_T IntegralGain;                 /* '<S337>/Integral Gain' */
  real_T IntegralGain_b;               /* '<S221>/Integral Gain' */
  real_T IntegralGain_e;               /* '<S163>/Integral Gain' */
  real_T IntegralGain_ev;              /* '<S105>/Integral Gain' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction2_h;/* '<S10>/MATLAB Function2' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction1_i3;/* '<S10>/MATLAB Function1' */
  B_MATLABFunction_samerHARDWAR_T sf_MATLABFunction_b;/* '<S10>/MATLAB Function' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction2_f;/* '<S9>/MATLAB Function2' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction1_i;/* '<S9>/MATLAB Function1' */
  B_MATLABFunction_samerHARDWAR_T sf_MATLABFunction_dw;/* '<S9>/MATLAB Function' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction2_e;/* '<S8>/MATLAB Function2' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction1_g;/* '<S8>/MATLAB Function1' */
  B_MATLABFunction_samerHARDWAR_T sf_MATLABFunction_m;/* '<S8>/MATLAB Function' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction2_mw;/* '<S7>/MATLAB Function2' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction1_k;/* '<S7>/MATLAB Function1' */
  B_MATLABFunction_samerHARDWAR_T sf_MATLABFunction_hb;/* '<S7>/MATLAB Function' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction2_o;/* '<S6>/MATLAB Function2' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction1_h;/* '<S6>/MATLAB Function1' */
  B_MATLABFunction_samerHARDWAR_T sf_MATLABFunction_d;/* '<S6>/MATLAB Function' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction2_m;/* '<S5>/MATLAB Function2' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction1;/* '<S5>/MATLAB Function1' */
  B_MATLABFunction_samerHARDWAR_T sf_MATLABFunction_h;/* '<S5>/MATLAB Function' */
} B_samerHARDWARE_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Output' */
  codertarget_arduinobase_inter_T obj_k;/* '<S10>/PWM3' */
  codertarget_arduinobase_inter_T obj_p;/* '<S10>/PWM2' */
  codertarget_arduinobase_inter_T obj_n;/* '<S9>/PWM3' */
  codertarget_arduinobase_inter_T obj_f;/* '<S9>/PWM2' */
  codertarget_arduinobase_inter_T obj_nt;/* '<S8>/PWM3' */
  codertarget_arduinobase_inter_T obj_j;/* '<S8>/PWM2' */
  codertarget_arduinobase_inter_T obj_l;/* '<S7>/PWM3' */
  codertarget_arduinobase_inter_T obj_b;/* '<S7>/PWM2' */
  codertarget_arduinobase_inter_T obj_lt;/* '<S6>/PWM3' */
  codertarget_arduinobase_inter_T obj_pv;/* '<S6>/PWM2' */
  codertarget_arduinobase_inter_T obj_g;/* '<S5>/PWM3' */
  codertarget_arduinobase_inter_T obj_e;/* '<S5>/PWM2' */
  codertarget_arduinobase_int_h_T obj_na;/* '<S11>/Analog Input5' */
  codertarget_arduinobase_int_h_T obj_i;/* '<S11>/Analog Input4' */
  codertarget_arduinobase_int_h_T obj_i3;/* '<S11>/Analog Input3' */
  codertarget_arduinobase_int_h_T obj_m;/* '<S11>/Analog Input2' */
  codertarget_arduinobase_int_h_T obj_o;/* '<S11>/Analog Input1' */
  codertarget_arduinobase_int_h_T obj_ic;/* '<S11>/Analog Input' */
  real_T UnitDelay_DSTATE[6];          /* '<Root>/Unit Delay' */
  real_T UnitDelay8_DSTATE;            /* '<S11>/Unit Delay8' */
  real_T UnitDelay9_DSTATE;            /* '<S11>/Unit Delay9' */
  real_T UnitDelay_DSTATE_a;           /* '<S11>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S11>/Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S11>/Unit Delay2' */
  real_T UnitDelay3_DSTATE;            /* '<S11>/Unit Delay3' */
  real_T UnitDelay4_DSTATE;            /* '<S11>/Unit Delay4' */
  real_T UnitDelay5_DSTATE;            /* '<S11>/Unit Delay5' */
  real_T UnitDelay6_DSTATE;            /* '<S11>/Unit Delay6' */
  real_T UnitDelay7_DSTATE;            /* '<S11>/Unit Delay7' */
  real_T UnitDelay10_DSTATE;           /* '<S11>/Unit Delay10' */
  real_T UnitDelay11_DSTATE;           /* '<S11>/Unit Delay11' */
  real_T Integrator_DSTATE;            /* '<S340>/Integrator' */
  real_T UD_DSTATE;                    /* '<S333>/UD' */
  real_T Integrator_DSTATE_f;          /* '<S224>/Integrator' */
  real_T UD_DSTATE_n;                  /* '<S217>/UD' */
  real_T Integrator_DSTATE_g;          /* '<S166>/Integrator' */
  real_T UD_DSTATE_b;                  /* '<S159>/UD' */
  real_T Integrator_DSTATE_j;          /* '<S108>/Integrator' */
  real_T UD_DSTATE_a;                  /* '<S101>/UD' */
  real_T Integrator_DSTATE_c;          /* '<S50>/Integrator' */
  real_T Filter_DSTATE;                /* '<S45>/Filter' */
  real_T Integrator_DSTATE_fp;         /* '<S282>/Integrator' */
  real_T UD_DSTATE_o;                  /* '<S275>/UD' */
  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S10>/Scope4' */

  int32_T sfEvent;                     /* '<Root>/MATLAB Function4' */
  int32_T sfEvent_j;                   /* '<Root>/MATLAB Function3' */
  int32_T sfEvent_b;                   /* '<Root>/MATLAB Function2' */
  int32_T sfEvent_jw;                  /* '<Root>/MATLAB Function' */
  boolean_T objisempty;                /* '<S11>/Analog Input5' */
  boolean_T objisempty_f;              /* '<S11>/Analog Input4' */
  boolean_T objisempty_k;              /* '<S11>/Analog Input3' */
  boolean_T objisempty_a;              /* '<S11>/Analog Input2' */
  boolean_T objisempty_k4;             /* '<S11>/Analog Input1' */
  boolean_T objisempty_l;              /* '<S11>/Analog Input' */
  boolean_T objisempty_j;              /* '<S10>/PWM3' */
  boolean_T objisempty_lk;             /* '<S10>/PWM2' */
  boolean_T objisempty_fm;             /* '<S9>/PWM3' */
  boolean_T objisempty_o;              /* '<S9>/PWM2' */
  boolean_T objisempty_h;              /* '<S8>/PWM3' */
  boolean_T objisempty_m;              /* '<S8>/PWM2' */
  boolean_T objisempty_p;              /* '<S7>/PWM3' */
  boolean_T objisempty_c;              /* '<S7>/PWM2' */
  boolean_T objisempty_f2;             /* '<S6>/PWM3' */
  boolean_T objisempty_h1;             /* '<S6>/PWM2' */
  boolean_T objisempty_ln;             /* '<S5>/PWM3' */
  boolean_T objisempty_e;              /* '<S5>/PWM2' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/MATLAB Function4' */
  boolean_T doneDoubleBufferReInit_n;  /* '<Root>/MATLAB Function3' */
  boolean_T doneDoubleBufferReInit_g;  /* '<Root>/MATLAB Function2' */
  boolean_T doneDoubleBufferReInit_b;  /* '<Root>/MATLAB Function' */
  boolean_T objisempty_jk;             /* '<Root>/Digital Output' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction2_h;/* '<S10>/MATLAB Function2' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction1_i3;/* '<S10>/MATLAB Function1' */
  DW_MATLABFunction_samerHARDWA_T sf_MATLABFunction_b;/* '<S10>/MATLAB Function' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction2_f;/* '<S9>/MATLAB Function2' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction1_i;/* '<S9>/MATLAB Function1' */
  DW_MATLABFunction_samerHARDWA_T sf_MATLABFunction_dw;/* '<S9>/MATLAB Function' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction2_e;/* '<S8>/MATLAB Function2' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction1_g;/* '<S8>/MATLAB Function1' */
  DW_MATLABFunction_samerHARDWA_T sf_MATLABFunction_m;/* '<S8>/MATLAB Function' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction2_mw;/* '<S7>/MATLAB Function2' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction1_k;/* '<S7>/MATLAB Function1' */
  DW_MATLABFunction_samerHARDWA_T sf_MATLABFunction_hb;/* '<S7>/MATLAB Function' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction2_o;/* '<S6>/MATLAB Function2' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction1_h;/* '<S6>/MATLAB Function1' */
  DW_MATLABFunction_samerHARDWA_T sf_MATLABFunction_d;/* '<S6>/MATLAB Function' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction2_m;/* '<S5>/MATLAB Function2' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction1;/* '<S5>/MATLAB Function1' */
  DW_MATLABFunction_samerHARDWA_T sf_MATLABFunction_h;/* '<S5>/MATLAB Function' */
} DW_samerHARDWARE_T;

/* Parameters (default storage) */
struct P_samerHARDWARE_T_ {
  real_T DiscretePIDController1_D;   /* Mask Parameter: DiscretePIDController1_D
                                      * Referenced by: '<S331>/Derivative Gain'
                                      */
  real_T DiscretePIDController1_D_c;
                                   /* Mask Parameter: DiscretePIDController1_D_c
                                    * Referenced by: '<S215>/Derivative Gain'
                                    */
  real_T DiscretePIDController1_D_a;
                                   /* Mask Parameter: DiscretePIDController1_D_a
                                    * Referenced by: '<S157>/Derivative Gain'
                                    */
  real_T DiscretePIDController1_D_k;
                                   /* Mask Parameter: DiscretePIDController1_D_k
                                    * Referenced by: '<S99>/Derivative Gain'
                                    */
  real_T DiscretePIDController1_D_e;
                                   /* Mask Parameter: DiscretePIDController1_D_e
                                    * Referenced by: '<S43>/Derivative Gain'
                                    */
  real_T DiscretePIDController1_D_cj;
                                  /* Mask Parameter: DiscretePIDController1_D_cj
                                   * Referenced by: '<S273>/Derivative Gain'
                                   */
  real_T DiscretePIDController1_Differen;
                              /* Mask Parameter: DiscretePIDController1_Differen
                               * Referenced by: '<S333>/UD'
                               */
  real_T DiscretePIDController1_Differ_c;
                              /* Mask Parameter: DiscretePIDController1_Differ_c
                               * Referenced by: '<S217>/UD'
                               */
  real_T DiscretePIDController1_Differ_g;
                              /* Mask Parameter: DiscretePIDController1_Differ_g
                               * Referenced by: '<S159>/UD'
                               */
  real_T DiscretePIDController1_Differ_j;
                              /* Mask Parameter: DiscretePIDController1_Differ_j
                               * Referenced by: '<S101>/UD'
                               */
  real_T DiscretePIDController1_Differ_d;
                              /* Mask Parameter: DiscretePIDController1_Differ_d
                               * Referenced by: '<S275>/UD'
                               */
  real_T DiscretePIDController1_I;   /* Mask Parameter: DiscretePIDController1_I
                                      * Referenced by: '<S337>/Integral Gain'
                                      */
  real_T DiscretePIDController1_I_l;
                                   /* Mask Parameter: DiscretePIDController1_I_l
                                    * Referenced by: '<S221>/Integral Gain'
                                    */
  real_T DiscretePIDController1_I_i;
                                   /* Mask Parameter: DiscretePIDController1_I_i
                                    * Referenced by: '<S163>/Integral Gain'
                                    */
  real_T DiscretePIDController1_I_f;
                                   /* Mask Parameter: DiscretePIDController1_I_f
                                    * Referenced by: '<S105>/Integral Gain'
                                    */
  real_T DiscretePIDController1_I_m;
                                   /* Mask Parameter: DiscretePIDController1_I_m
                                    * Referenced by: '<S47>/Integral Gain'
                                    */
  real_T DiscretePIDController1_I_o;
                                   /* Mask Parameter: DiscretePIDController1_I_o
                                    * Referenced by: '<S279>/Integral Gain'
                                    */
  real_T DiscretePIDController1_InitialC;
                              /* Mask Parameter: DiscretePIDController1_InitialC
                               * Referenced by: '<S45>/Filter'
                               */
  real_T DiscretePIDController1_Initia_d;
                              /* Mask Parameter: DiscretePIDController1_Initia_d
                               * Referenced by: '<S340>/Integrator'
                               */
  real_T DiscretePIDController1_Initia_c;
                              /* Mask Parameter: DiscretePIDController1_Initia_c
                               * Referenced by: '<S224>/Integrator'
                               */
  real_T DiscretePIDController1_Initia_l;
                              /* Mask Parameter: DiscretePIDController1_Initia_l
                               * Referenced by: '<S166>/Integrator'
                               */
  real_T DiscretePIDController1_Initia_h;
                              /* Mask Parameter: DiscretePIDController1_Initia_h
                               * Referenced by: '<S108>/Integrator'
                               */
  real_T DiscretePIDController1_Initi_la;
                              /* Mask Parameter: DiscretePIDController1_Initi_la
                               * Referenced by: '<S50>/Integrator'
                               */
  real_T DiscretePIDController1_Initia_f;
                              /* Mask Parameter: DiscretePIDController1_Initia_f
                               * Referenced by: '<S282>/Integrator'
                               */
  real_T DiscretePIDController1_N;   /* Mask Parameter: DiscretePIDController1_N
                                      * Referenced by: '<S53>/Filter Coefficient'
                                      */
  real_T DiscretePIDController1_P;   /* Mask Parameter: DiscretePIDController1_P
                                      * Referenced by: '<S345>/Proportional Gain'
                                      */
  real_T DiscretePIDController1_P_f;
                                   /* Mask Parameter: DiscretePIDController1_P_f
                                    * Referenced by: '<S229>/Proportional Gain'
                                    */
  real_T DiscretePIDController1_P_o;
                                   /* Mask Parameter: DiscretePIDController1_P_o
                                    * Referenced by: '<S171>/Proportional Gain'
                                    */
  real_T DiscretePIDController1_P_e;
                                   /* Mask Parameter: DiscretePIDController1_P_e
                                    * Referenced by: '<S113>/Proportional Gain'
                                    */
  real_T DiscretePIDController1_P_a;
                                   /* Mask Parameter: DiscretePIDController1_P_a
                                    * Referenced by: '<S55>/Proportional Gain'
                                    */
  real_T DiscretePIDController1_P_fd;
                                  /* Mask Parameter: DiscretePIDController1_P_fd
                                   * Referenced by: '<S287>/Proportional Gain'
                                   */
  real_T Constant_Value[15];      /* Expression: [0;0;0;0;0;0;0;0;0;0;0;0;0;0;1]
                                   * Referenced by: '<Root>/Constant'
                                   */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T UnitDelay8_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S11>/Unit Delay8'
                                        */
  real_T Gain18_Gain;                  /* Expression: 0.13575
                                        * Referenced by: '<S11>/Gain18'
                                        */
  real_T Gain17_Gain;                  /* Expression: 0.13575
                                        * Referenced by: '<S11>/Gain17'
                                        */
  real_T UnitDelay9_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S11>/Unit Delay9'
                                        */
  real_T Gain19_Gain;                  /* Expression: 0.72848
                                        * Referenced by: '<S11>/Gain19'
                                        */
  real_T Gain16_Gain;                  /* Expression: 100/1024
                                        * Referenced by: '<S11>/Gain16'
                                        */
  real_T UnitDelay_InitialCondition_o; /* Expression: 0
                                        * Referenced by: '<S11>/Unit Delay'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.13575
                                        * Referenced by: '<S11>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.13575
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S11>/Unit Delay1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 0.72848
                                        * Referenced by: '<S11>/Gain3'
                                        */
  real_T Gain_Gain;                    /* Expression: 100/1024
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T UnitDelay2_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S11>/Unit Delay2'
                                        */
  real_T Gain6_Gain;                   /* Expression: 0.13575
                                        * Referenced by: '<S11>/Gain6'
                                        */
  real_T Gain5_Gain;                   /* Expression: 0.13575
                                        * Referenced by: '<S11>/Gain5'
                                        */
  real_T UnitDelay3_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S11>/Unit Delay3'
                                        */
  real_T Gain7_Gain;                   /* Expression: 0.72848
                                        * Referenced by: '<S11>/Gain7'
                                        */
  real_T Gain4_Gain;                   /* Expression: 100/1024
                                        * Referenced by: '<S11>/Gain4'
                                        */
  real_T UnitDelay4_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S11>/Unit Delay4'
                                        */
  real_T Gain10_Gain;                  /* Expression: 0.13575
                                        * Referenced by: '<S11>/Gain10'
                                        */
  real_T Gain9_Gain;                   /* Expression: 0.13575
                                        * Referenced by: '<S11>/Gain9'
                                        */
  real_T UnitDelay5_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S11>/Unit Delay5'
                                        */
  real_T Gain11_Gain;                  /* Expression: 0.72848
                                        * Referenced by: '<S11>/Gain11'
                                        */
  real_T Gain8_Gain;                   /* Expression: 100/1024
                                        * Referenced by: '<S11>/Gain8'
                                        */
  real_T UnitDelay6_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S11>/Unit Delay6'
                                        */
  real_T Gain14_Gain;                  /* Expression: 0.13575
                                        * Referenced by: '<S11>/Gain14'
                                        */
  real_T Gain13_Gain;                  /* Expression: 0.13575
                                        * Referenced by: '<S11>/Gain13'
                                        */
  real_T UnitDelay7_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S11>/Unit Delay7'
                                        */
  real_T Gain15_Gain;                  /* Expression: 0.72848
                                        * Referenced by: '<S11>/Gain15'
                                        */
  real_T Gain12_Gain;                  /* Expression: 100/1024
                                        * Referenced by: '<S11>/Gain12'
                                        */
  real_T UnitDelay10_InitialCondition; /* Expression: 0
                                        * Referenced by: '<S11>/Unit Delay10'
                                        */
  real_T Gain22_Gain;                  /* Expression: 0.13575
                                        * Referenced by: '<S11>/Gain22'
                                        */
  real_T Gain21_Gain;                  /* Expression: 0.13575
                                        * Referenced by: '<S11>/Gain21'
                                        */
  real_T UnitDelay11_InitialCondition; /* Expression: 0
                                        * Referenced by: '<S11>/Unit Delay11'
                                        */
  real_T Gain23_Gain;                  /* Expression: 0.72848
                                        * Referenced by: '<S11>/Gain23'
                                        */
  real_T Gain20_Gain;                  /* Expression: 100/1024
                                        * Referenced by: '<S11>/Gain20'
                                        */
  real_T Constant_Value_d;             /* Expression: 255
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S340>/Integrator'
                                        */
  real_T Tsamp_WtEt;                   /* Computed Parameter: Tsamp_WtEt
                                        * Referenced by: '<S335>/Tsamp'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 220
                                        * Referenced by: '<S10>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S10>/Saturation1'
                                        */
  real_T Switch_Threshold;             /* Expression: 5
                                        * Referenced by: '<S10>/Switch'
                                        */
  real_T Gain4_Gain_d;                 /* Expression: 0.45
                                        * Referenced by: '<S10>/Gain4'
                                        */
  real_T Constant_Value_i;             /* Expression: 255
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Integrator_gainval_k;       /* Computed Parameter: Integrator_gainval_k
                                      * Referenced by: '<S224>/Integrator'
                                      */
  real_T Tsamp_WtEt_o;                 /* Computed Parameter: Tsamp_WtEt_o
                                        * Referenced by: '<S219>/Tsamp'
                                        */
  real_T Saturation1_UpperSat_b;       /* Expression: 220
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: 0
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  real_T Switch_Threshold_e;           /* Expression: 5
                                        * Referenced by: '<S8>/Switch'
                                        */
  real_T Gain4_Gain_dn;                /* Expression: 0.45
                                        * Referenced by: '<S8>/Gain4'
                                        */
  real_T Constant_Value_o;             /* Expression: 255
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Integrator_gainval_k3;     /* Computed Parameter: Integrator_gainval_k3
                                     * Referenced by: '<S166>/Integrator'
                                     */
  real_T Tsamp_WtEt_d;                 /* Computed Parameter: Tsamp_WtEt_d
                                        * Referenced by: '<S161>/Tsamp'
                                        */
  real_T Saturation1_UpperSat_k;       /* Expression: 220
                                        * Referenced by: '<S7>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_b;       /* Expression: 0
                                        * Referenced by: '<S7>/Saturation1'
                                        */
  real_T Switch_Threshold_d;           /* Expression: 5
                                        * Referenced by: '<S7>/Switch'
                                        */
  real_T Gain4_Gain_h;                 /* Expression: 0.45
                                        * Referenced by: '<S7>/Gain4'
                                        */
  real_T Constant_Value_k;             /* Expression: 255
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Integrator_gainval_g;       /* Computed Parameter: Integrator_gainval_g
                                      * Referenced by: '<S108>/Integrator'
                                      */
  real_T Tsamp_WtEt_b;                 /* Computed Parameter: Tsamp_WtEt_b
                                        * Referenced by: '<S103>/Tsamp'
                                        */
  real_T Saturation1_UpperSat_j;       /* Expression: 220
                                        * Referenced by: '<S6>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_j;       /* Expression: 0
                                        * Referenced by: '<S6>/Saturation1'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 5
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Gain4_Gain_k;                 /* Expression: 0.45
                                        * Referenced by: '<S6>/Gain4'
                                        */
  real_T Constant_Value_c;             /* Expression: 255
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Integrator_gainval_l;       /* Computed Parameter: Integrator_gainval_l
                                      * Referenced by: '<S50>/Integrator'
                                      */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S45>/Filter'
                                        */
  real_T Saturation1_UpperSat_c;       /* Expression: 220
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_d;       /* Expression: 0
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 5
                                        * Referenced by: '<S5>/Switch'
                                        */
  real_T Gain4_Gain_i;                 /* Expression: 0.45
                                        * Referenced by: '<S5>/Gain4'
                                        */
  real_T Constant_Value_p;             /* Expression: 255
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Integrator_gainval_l4;     /* Computed Parameter: Integrator_gainval_l4
                                     * Referenced by: '<S282>/Integrator'
                                     */
  real_T Tsamp_WtEt_a;                 /* Computed Parameter: Tsamp_WtEt_a
                                        * Referenced by: '<S277>/Tsamp'
                                        */
  real_T Saturation1_UpperSat_i;       /* Expression: 220
                                        * Referenced by: '<S9>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_f;       /* Expression: 0
                                        * Referenced by: '<S9>/Saturation1'
                                        */
  real_T Switch_Threshold_eq;          /* Expression: 5
                                        * Referenced by: '<S9>/Switch'
                                        */
  real_T Gain4_Gain_j;                 /* Expression: 0.45
                                        * Referenced by: '<S9>/Gain4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_samerHARDWARE_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

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
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_samerHARDWARE_T samerHARDWARE_P;

/* Block signals (default storage) */
extern B_samerHARDWARE_T samerHARDWARE_B;

/* Block states (default storage) */
extern DW_samerHARDWARE_T samerHARDWARE_DW;

/* Model entry point functions */
extern void samerHARDWARE_initialize(void);
extern void samerHARDWARE_step(void);
extern void samerHARDWARE_terminate(void);

/* Real-time Model object */
extern RT_MODEL_samerHARDWARE_T *const samerHARDWARE_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Abs' : Unused code path elimination
 * Block '<S5>/Add2' : Unused code path elimination
 * Block '<S5>/Data Type Conversion' : Unused code path elimination
 * Block '<S5>/Data Type Conversion1' : Unused code path elimination
 * Block '<S6>/Abs' : Unused code path elimination
 * Block '<S6>/Add2' : Unused code path elimination
 * Block '<S6>/Data Type Conversion' : Unused code path elimination
 * Block '<S6>/Data Type Conversion1' : Unused code path elimination
 * Block '<S101>/DTDup' : Unused code path elimination
 * Block '<S7>/Abs' : Unused code path elimination
 * Block '<S7>/Add2' : Unused code path elimination
 * Block '<S7>/Data Type Conversion' : Unused code path elimination
 * Block '<S7>/Data Type Conversion1' : Unused code path elimination
 * Block '<S159>/DTDup' : Unused code path elimination
 * Block '<S8>/Abs' : Unused code path elimination
 * Block '<S8>/Add2' : Unused code path elimination
 * Block '<S8>/Data Type Conversion' : Unused code path elimination
 * Block '<S8>/Data Type Conversion1' : Unused code path elimination
 * Block '<S217>/DTDup' : Unused code path elimination
 * Block '<S9>/Abs' : Unused code path elimination
 * Block '<S9>/Add2' : Unused code path elimination
 * Block '<S9>/Data Type Conversion' : Unused code path elimination
 * Block '<S9>/Data Type Conversion1' : Unused code path elimination
 * Block '<S275>/DTDup' : Unused code path elimination
 * Block '<S10>/Abs' : Unused code path elimination
 * Block '<S10>/Add2' : Unused code path elimination
 * Block '<S10>/Data Type Conversion' : Unused code path elimination
 * Block '<S10>/Data Type Conversion1' : Unused code path elimination
 * Block '<S333>/DTDup' : Unused code path elimination
 * Block '<Root>/Reshape3' : Reshape block reduction
 * Block '<S11>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion12' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion9' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'samerHARDWARE'
 * '<S1>'   : 'samerHARDWARE/MATLAB Function'
 * '<S2>'   : 'samerHARDWARE/MATLAB Function2'
 * '<S3>'   : 'samerHARDWARE/MATLAB Function3'
 * '<S4>'   : 'samerHARDWARE/MATLAB Function4'
 * '<S5>'   : 'samerHARDWARE/Subsystem'
 * '<S6>'   : 'samerHARDWARE/Subsystem1'
 * '<S7>'   : 'samerHARDWARE/Subsystem2'
 * '<S8>'   : 'samerHARDWARE/Subsystem3'
 * '<S9>'   : 'samerHARDWARE/Subsystem4'
 * '<S10>'  : 'samerHARDWARE/Subsystem5'
 * '<S11>'  : 'samerHARDWARE/Subsystem8'
 * '<S12>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1'
 * '<S13>'  : 'samerHARDWARE/Subsystem/MATLAB Function'
 * '<S14>'  : 'samerHARDWARE/Subsystem/MATLAB Function1'
 * '<S15>'  : 'samerHARDWARE/Subsystem/MATLAB Function2'
 * '<S16>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Anti-windup'
 * '<S17>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/D Gain'
 * '<S18>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/External Derivative'
 * '<S19>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Filter'
 * '<S20>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Filter ICs'
 * '<S21>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/I Gain'
 * '<S22>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Ideal P Gain'
 * '<S23>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S24>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Integrator'
 * '<S25>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Integrator ICs'
 * '<S26>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/N Copy'
 * '<S27>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/N Gain'
 * '<S28>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/P Copy'
 * '<S29>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Parallel P Gain'
 * '<S30>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Reset Signal'
 * '<S31>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Saturation'
 * '<S32>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Saturation Fdbk'
 * '<S33>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Sum'
 * '<S34>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Sum Fdbk'
 * '<S35>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Tracking Mode'
 * '<S36>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Tracking Mode Sum'
 * '<S37>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Tsamp - Integral'
 * '<S38>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Tsamp - Ngain'
 * '<S39>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/postSat Signal'
 * '<S40>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/preInt Signal'
 * '<S41>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/preSat Signal'
 * '<S42>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S43>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S44>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/External Derivative/Error'
 * '<S45>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S46>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S47>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S48>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S49>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S50>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Integrator/Discrete'
 * '<S51>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S52>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/N Copy/Disabled'
 * '<S53>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S54>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/P Copy/Disabled'
 * '<S55>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S56>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S57>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Saturation/Passthrough'
 * '<S58>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S59>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Sum/Sum_PID'
 * '<S60>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S61>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S62>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S63>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S64>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S65>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S66>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S67>'  : 'samerHARDWARE/Subsystem/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S68>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1'
 * '<S69>'  : 'samerHARDWARE/Subsystem1/MATLAB Function'
 * '<S70>'  : 'samerHARDWARE/Subsystem1/MATLAB Function1'
 * '<S71>'  : 'samerHARDWARE/Subsystem1/MATLAB Function2'
 * '<S72>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Anti-windup'
 * '<S73>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/D Gain'
 * '<S74>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/External Derivative'
 * '<S75>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Filter'
 * '<S76>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Filter ICs'
 * '<S77>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/I Gain'
 * '<S78>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Ideal P Gain'
 * '<S79>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S80>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Integrator'
 * '<S81>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Integrator ICs'
 * '<S82>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/N Copy'
 * '<S83>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/N Gain'
 * '<S84>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/P Copy'
 * '<S85>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Parallel P Gain'
 * '<S86>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Reset Signal'
 * '<S87>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Saturation'
 * '<S88>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Saturation Fdbk'
 * '<S89>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Sum'
 * '<S90>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Sum Fdbk'
 * '<S91>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Tracking Mode'
 * '<S92>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Tracking Mode Sum'
 * '<S93>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Tsamp - Integral'
 * '<S94>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Tsamp - Ngain'
 * '<S95>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/postSat Signal'
 * '<S96>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/preInt Signal'
 * '<S97>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/preSat Signal'
 * '<S98>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S99>'  : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S100>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/External Derivative/Error'
 * '<S101>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Filter/Differentiator'
 * '<S102>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Filter/Differentiator/Tsamp'
 * '<S103>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S104>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S105>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S106>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S107>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S108>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Integrator/Discrete'
 * '<S109>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S110>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S111>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/N Gain/Passthrough'
 * '<S112>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/P Copy/Disabled'
 * '<S113>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S114>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S115>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Saturation/Passthrough'
 * '<S116>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S117>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Sum/Sum_PID'
 * '<S118>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S119>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S120>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S121>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S122>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S123>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S124>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S125>' : 'samerHARDWARE/Subsystem1/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S126>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1'
 * '<S127>' : 'samerHARDWARE/Subsystem2/MATLAB Function'
 * '<S128>' : 'samerHARDWARE/Subsystem2/MATLAB Function1'
 * '<S129>' : 'samerHARDWARE/Subsystem2/MATLAB Function2'
 * '<S130>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Anti-windup'
 * '<S131>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/D Gain'
 * '<S132>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/External Derivative'
 * '<S133>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Filter'
 * '<S134>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Filter ICs'
 * '<S135>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/I Gain'
 * '<S136>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Ideal P Gain'
 * '<S137>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S138>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Integrator'
 * '<S139>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Integrator ICs'
 * '<S140>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/N Copy'
 * '<S141>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/N Gain'
 * '<S142>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/P Copy'
 * '<S143>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Parallel P Gain'
 * '<S144>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Reset Signal'
 * '<S145>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Saturation'
 * '<S146>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Saturation Fdbk'
 * '<S147>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Sum'
 * '<S148>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Sum Fdbk'
 * '<S149>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Tracking Mode'
 * '<S150>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Tracking Mode Sum'
 * '<S151>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Tsamp - Integral'
 * '<S152>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Tsamp - Ngain'
 * '<S153>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/postSat Signal'
 * '<S154>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/preInt Signal'
 * '<S155>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/preSat Signal'
 * '<S156>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S157>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S158>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/External Derivative/Error'
 * '<S159>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Filter/Differentiator'
 * '<S160>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Filter/Differentiator/Tsamp'
 * '<S161>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S162>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S163>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S164>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S165>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S166>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Integrator/Discrete'
 * '<S167>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S168>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S169>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/N Gain/Passthrough'
 * '<S170>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/P Copy/Disabled'
 * '<S171>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S172>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S173>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Saturation/Passthrough'
 * '<S174>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S175>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Sum/Sum_PID'
 * '<S176>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S177>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S178>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S179>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S180>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S181>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S182>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S183>' : 'samerHARDWARE/Subsystem2/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S184>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1'
 * '<S185>' : 'samerHARDWARE/Subsystem3/MATLAB Function'
 * '<S186>' : 'samerHARDWARE/Subsystem3/MATLAB Function1'
 * '<S187>' : 'samerHARDWARE/Subsystem3/MATLAB Function2'
 * '<S188>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Anti-windup'
 * '<S189>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/D Gain'
 * '<S190>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/External Derivative'
 * '<S191>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Filter'
 * '<S192>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Filter ICs'
 * '<S193>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/I Gain'
 * '<S194>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Ideal P Gain'
 * '<S195>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S196>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Integrator'
 * '<S197>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Integrator ICs'
 * '<S198>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/N Copy'
 * '<S199>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/N Gain'
 * '<S200>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/P Copy'
 * '<S201>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Parallel P Gain'
 * '<S202>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Reset Signal'
 * '<S203>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Saturation'
 * '<S204>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Saturation Fdbk'
 * '<S205>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Sum'
 * '<S206>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Sum Fdbk'
 * '<S207>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Tracking Mode'
 * '<S208>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Tracking Mode Sum'
 * '<S209>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Tsamp - Integral'
 * '<S210>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Tsamp - Ngain'
 * '<S211>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/postSat Signal'
 * '<S212>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/preInt Signal'
 * '<S213>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/preSat Signal'
 * '<S214>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S215>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S216>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/External Derivative/Error'
 * '<S217>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Filter/Differentiator'
 * '<S218>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Filter/Differentiator/Tsamp'
 * '<S219>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S220>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S221>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S222>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S223>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S224>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Integrator/Discrete'
 * '<S225>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S226>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S227>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/N Gain/Passthrough'
 * '<S228>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/P Copy/Disabled'
 * '<S229>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S230>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S231>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Saturation/Passthrough'
 * '<S232>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S233>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Sum/Sum_PID'
 * '<S234>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S235>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S236>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S237>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S238>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S239>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S240>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S241>' : 'samerHARDWARE/Subsystem3/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S242>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1'
 * '<S243>' : 'samerHARDWARE/Subsystem4/MATLAB Function'
 * '<S244>' : 'samerHARDWARE/Subsystem4/MATLAB Function1'
 * '<S245>' : 'samerHARDWARE/Subsystem4/MATLAB Function2'
 * '<S246>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Anti-windup'
 * '<S247>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/D Gain'
 * '<S248>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/External Derivative'
 * '<S249>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Filter'
 * '<S250>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Filter ICs'
 * '<S251>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/I Gain'
 * '<S252>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Ideal P Gain'
 * '<S253>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S254>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Integrator'
 * '<S255>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Integrator ICs'
 * '<S256>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/N Copy'
 * '<S257>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/N Gain'
 * '<S258>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/P Copy'
 * '<S259>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Parallel P Gain'
 * '<S260>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Reset Signal'
 * '<S261>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Saturation'
 * '<S262>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Saturation Fdbk'
 * '<S263>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Sum'
 * '<S264>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Sum Fdbk'
 * '<S265>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Tracking Mode'
 * '<S266>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Tracking Mode Sum'
 * '<S267>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Tsamp - Integral'
 * '<S268>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Tsamp - Ngain'
 * '<S269>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/postSat Signal'
 * '<S270>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/preInt Signal'
 * '<S271>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/preSat Signal'
 * '<S272>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S273>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S274>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/External Derivative/Error'
 * '<S275>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Filter/Differentiator'
 * '<S276>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Filter/Differentiator/Tsamp'
 * '<S277>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S278>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S279>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S280>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S281>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S282>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Integrator/Discrete'
 * '<S283>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S284>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S285>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/N Gain/Passthrough'
 * '<S286>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/P Copy/Disabled'
 * '<S287>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S288>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S289>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Saturation/Passthrough'
 * '<S290>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S291>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Sum/Sum_PID'
 * '<S292>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S293>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S294>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S295>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S296>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S297>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S298>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S299>' : 'samerHARDWARE/Subsystem4/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S300>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1'
 * '<S301>' : 'samerHARDWARE/Subsystem5/MATLAB Function'
 * '<S302>' : 'samerHARDWARE/Subsystem5/MATLAB Function1'
 * '<S303>' : 'samerHARDWARE/Subsystem5/MATLAB Function2'
 * '<S304>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Anti-windup'
 * '<S305>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/D Gain'
 * '<S306>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/External Derivative'
 * '<S307>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Filter'
 * '<S308>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Filter ICs'
 * '<S309>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/I Gain'
 * '<S310>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Ideal P Gain'
 * '<S311>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S312>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Integrator'
 * '<S313>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Integrator ICs'
 * '<S314>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/N Copy'
 * '<S315>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/N Gain'
 * '<S316>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/P Copy'
 * '<S317>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Parallel P Gain'
 * '<S318>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Reset Signal'
 * '<S319>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Saturation'
 * '<S320>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Saturation Fdbk'
 * '<S321>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Sum'
 * '<S322>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Sum Fdbk'
 * '<S323>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Tracking Mode'
 * '<S324>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Tracking Mode Sum'
 * '<S325>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Tsamp - Integral'
 * '<S326>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Tsamp - Ngain'
 * '<S327>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/postSat Signal'
 * '<S328>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/preInt Signal'
 * '<S329>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/preSat Signal'
 * '<S330>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S331>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S332>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/External Derivative/Error'
 * '<S333>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Filter/Differentiator'
 * '<S334>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Filter/Differentiator/Tsamp'
 * '<S335>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S336>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S337>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S338>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S339>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S340>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Integrator/Discrete'
 * '<S341>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S342>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S343>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/N Gain/Passthrough'
 * '<S344>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/P Copy/Disabled'
 * '<S345>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S346>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S347>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Saturation/Passthrough'
 * '<S348>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S349>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Sum/Sum_PID'
 * '<S350>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S351>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S352>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S353>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S354>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S355>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S356>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S357>' : 'samerHARDWARE/Subsystem5/Discrete PID Controller1/preSat Signal/Forward_Path'
 */
#endif                                 /* samerHARDWARE_h_ */
