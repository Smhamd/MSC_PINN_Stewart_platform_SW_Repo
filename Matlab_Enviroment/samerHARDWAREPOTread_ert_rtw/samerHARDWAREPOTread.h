/*
 * samerHARDWAREPOTread.h
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

#ifndef samerHARDWAREPOTread_h_
#define samerHARDWAREPOTread_h_
#ifndef samerHARDWAREPOTread_COMMON_INCLUDES_
#define samerHARDWAREPOTread_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#endif                               /* samerHARDWAREPOTread_COMMON_INCLUDES_ */

#include "samerHARDWAREPOTread_types.h"
#include <string.h>
#include "rt_nonfinite.h"
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

/* Block signals for system '<S4>/MATLAB Function' */
typedef struct {
  real_T y;                            /* '<S4>/MATLAB Function' */
  real_T x;                            /* '<S4>/MATLAB Function' */
} B_MATLABFunction_samerHARDWAR_T;

/* Block states (default storage) for system '<S4>/MATLAB Function' */
typedef struct {
  int32_T sfEvent;                     /* '<S4>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S4>/MATLAB Function' */
} DW_MATLABFunction_samerHARDWA_T;

/* Block signals for system '<S4>/MATLAB Function1' */
typedef struct {
  real_T y;                            /* '<S4>/MATLAB Function1' */
} B_MATLABFunction1_samerHARDWA_T;

/* Block states (default storage) for system '<S4>/MATLAB Function1' */
typedef struct {
  int32_T sfEvent;                     /* '<S4>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit;    /* '<S4>/MATLAB Function1' */
} DW_MATLABFunction1_samerHARDW_T;

/* Block signals (default storage) */
typedef struct {
  real_T b[18];
  real_T R[9];
  real_T r[3];
  real_T L[3];
  real_T Gain14;                       /* '<Root>/Gain14' */
  real_T Gain12;                       /* '<Root>/Gain12' */
  real_T Gain13;                       /* '<Root>/Gain13' */
  real_T Gain20;                       /* '<Root>/Gain20' */
  real_T DataTypeConversion1;          /* '<S4>/Data Type Conversion1' */
  real_T Sum;                          /* '<S4>/Sum' */
  real_T Gain;                         /* '<S4>/Gain' */
  real_T DataTypeConversion;           /* '<S4>/Data Type Conversion' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Subsystem_at_outport_1Inport1' */
  real_T DataTypeConversion1_d;        /* '<S5>/Data Type Conversion1' */
  real_T Sum_l;                        /* '<S5>/Sum' */
  real_T Gain_b;                       /* '<S5>/Gain' */
  real_T DataTypeConversion_j;         /* '<S5>/Data Type Conversion' */
  real_T TmpSignalConversionAtTAQSigLo_m[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Subsystem1_at_outport_1Inport1' */
  real_T DataTypeConversion1_o;        /* '<S6>/Data Type Conversion1' */
  real_T Sum_c;                        /* '<S6>/Sum' */
  real_T Gain_be;                      /* '<S6>/Gain' */
  real_T DataTypeConversion_c;         /* '<S6>/Data Type Conversion' */
  real_T TmpSignalConversionAtTAQSigLo_j[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Subsystem2_at_outport_1Inport1' */
  real_T DataTypeConversion1_c;        /* '<S7>/Data Type Conversion1' */
  real_T Sum_m;                        /* '<S7>/Sum' */
  real_T Gain_j;                       /* '<S7>/Gain' */
  real_T DataTypeConversion_c3;        /* '<S7>/Data Type Conversion' */
  real_T TmpSignalConversionAtTAQSigLo_g[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Subsystem3_at_outport_1Inport1' */
  real_T DataTypeConversion1_os;       /* '<S8>/Data Type Conversion1' */
  real_T Sum_k;                        /* '<S8>/Sum' */
  real_T Gain_p;                       /* '<S8>/Gain' */
  real_T DataTypeConversion_e;         /* '<S8>/Data Type Conversion' */
  real_T TmpSignalConversionAtTAQSigLo_c[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Subsystem4_at_outport_1Inport1' */
  real_T DataTypeConversion1_cx;       /* '<S9>/Data Type Conversion1' */
  real_T Sum_g;                        /* '<S9>/Sum' */
  real_T Gain_k;                       /* '<S9>/Gain' */
  real_T DataTypeConversion_i;         /* '<S9>/Data Type Conversion' */
  real_T TmpSignalConversionAtTAQSigLo_e[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Subsystem5_at_outport_1Inport1' */
  real_T Add1;                         /* '<S9>/Add1' */
  real_T Add1_d;                       /* '<S4>/Add1' */
  real_T Add1_e;                       /* '<S5>/Add1' */
  real_T Add1_eq;                      /* '<S6>/Add1' */
  real_T Add1_a;                       /* '<S7>/Add1' */
  real_T Add1_k;                       /* '<S8>/Add1' */
  real_T Add;                          /* '<S9>/Add' */
  real_T Abs4;                         /* '<S9>/Abs4' */
  real_T Saturation1;                  /* '<S9>/Saturation1' */
  real_T Abs;                          /* '<S9>/Abs' */
  real_T Add_m;                        /* '<S8>/Add' */
  real_T Abs4_n;                       /* '<S8>/Abs4' */
  real_T Saturation1_a;                /* '<S8>/Saturation1' */
  real_T Abs_l;                        /* '<S8>/Abs' */
  real_T Add_h;                        /* '<S7>/Add' */
  real_T Abs4_nd;                      /* '<S7>/Abs4' */
  real_T Saturation1_g;                /* '<S7>/Saturation1' */
  real_T Abs_p;                        /* '<S7>/Abs' */
  real_T Add_c;                        /* '<S6>/Add' */
  real_T Abs4_m;                       /* '<S6>/Abs4' */
  real_T Saturation1_p;                /* '<S6>/Saturation1' */
  real_T Abs_n;                        /* '<S6>/Abs' */
  real_T Add_l;                        /* '<S5>/Add' */
  real_T Abs4_c;                       /* '<S5>/Abs4' */
  real_T Saturation1_i;                /* '<S5>/Saturation1' */
  real_T Abs_b;                        /* '<S5>/Abs' */
  real_T Add_o;                        /* '<S4>/Add' */
  real_T Abs4_d;                       /* '<S4>/Abs4' */
  real_T Saturation1_k;                /* '<S4>/Saturation1' */
  real_T Abs_ng;                       /* '<S4>/Abs' */
  real_T deltaL[6];                    /* '<Root>/MATLAB Function' */
  real_T cy;
  real_T cp;
  real_T sp;
  real_T cr;
  real_T sr;
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T R_tmp;
  real_T DataTypeConversion3;          /* '<S4>/Data Type Conversion3' */
  real_T DataTypeConversion3_b;        /* '<S5>/Data Type Conversion3' */
  real_T DataTypeConversion3_k;        /* '<S6>/Data Type Conversion3' */
  real_T DataTypeConversion3_c;        /* '<S7>/Data Type Conversion3' */
  real_T DataTypeConversion3_p;        /* '<S8>/Data Type Conversion3' */
  real_T DataTypeConversion3_j;        /* '<S9>/Data Type Conversion3' */
  real_T Tsamp;                        /* '<S339>/Tsamp' */
  real_T Gain4;                        /* '<S9>/Gain4' */
  real_T Tsamp_b;                      /* '<S281>/Tsamp' */
  real_T Gain4_b;                      /* '<S8>/Gain4' */
  real_T Tsamp_a;                      /* '<S223>/Tsamp' */
  real_T Gain4_m;                      /* '<S7>/Gain4' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction2_h;/* '<S9>/MATLAB Function2' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction1_i3;/* '<S9>/MATLAB Function1' */
  B_MATLABFunction_samerHARDWAR_T sf_MATLABFunction_b;/* '<S9>/MATLAB Function' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction2_f;/* '<S8>/MATLAB Function2' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction1_i;/* '<S8>/MATLAB Function1' */
  B_MATLABFunction_samerHARDWAR_T sf_MATLABFunction_dw;/* '<S8>/MATLAB Function' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction2_e;/* '<S7>/MATLAB Function2' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction1_g;/* '<S7>/MATLAB Function1' */
  B_MATLABFunction_samerHARDWAR_T sf_MATLABFunction_m;/* '<S7>/MATLAB Function' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction2_m;/* '<S6>/MATLAB Function2' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction1_k;/* '<S6>/MATLAB Function1' */
  B_MATLABFunction_samerHARDWAR_T sf_MATLABFunction_hb;/* '<S6>/MATLAB Function' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction2_o;/* '<S5>/MATLAB Function2' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction1_h;/* '<S5>/MATLAB Function1' */
  B_MATLABFunction_samerHARDWAR_T sf_MATLABFunction_d;/* '<S5>/MATLAB Function' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction2;/* '<S4>/MATLAB Function2' */
  B_MATLABFunction1_samerHARDWA_T sf_MATLABFunction1;/* '<S4>/MATLAB Function1' */
  B_MATLABFunction_samerHARDWAR_T sf_MATLABFunction_h;/* '<S4>/MATLAB Function' */
} B_samerHARDWAREPOTread_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S9>/Analog Input' */
  codertarget_arduinobase_inter_T obj_c;/* '<S8>/Analog Input' */
  codertarget_arduinobase_inter_T obj_p;/* '<S7>/Analog Input' */
  codertarget_arduinobase_inter_T obj_n;/* '<S6>/Analog Input' */
  codertarget_arduinobase_inter_T obj_g;/* '<S5>/Analog Input' */
  codertarget_arduinobase_inter_T obj_k;/* '<S4>/Analog Input' */
  codertarget_arduinobase_int_h_T obj_kc;/* '<S9>/PWM3' */
  codertarget_arduinobase_int_h_T obj_po;/* '<S9>/PWM2' */
  codertarget_arduinobase_int_h_T obj_nn;/* '<S8>/PWM3' */
  codertarget_arduinobase_int_h_T obj_f;/* '<S8>/PWM2' */
  codertarget_arduinobase_int_h_T obj_nt;/* '<S7>/PWM3' */
  codertarget_arduinobase_int_h_T obj_j;/* '<S7>/PWM2' */
  codertarget_arduinobase_int_h_T obj_l;/* '<S6>/PWM3' */
  codertarget_arduinobase_int_h_T obj_b;/* '<S6>/PWM2' */
  codertarget_arduinobase_int_h_T obj_lt;/* '<S5>/PWM3' */
  codertarget_arduinobase_int_h_T obj_pv;/* '<S5>/PWM2' */
  codertarget_arduinobase_int_h_T obj_gy;/* '<S4>/PWM3' */
  codertarget_arduinobase_int_h_T obj_e;/* '<S4>/PWM2' */
  real_T UnitDelay_DSTATE;             /* '<S4>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S4>/Unit Delay1' */
  real_T UnitDelay_DSTATE_a;           /* '<S5>/Unit Delay' */
  real_T UnitDelay1_DSTATE_e;          /* '<S5>/Unit Delay1' */
  real_T UnitDelay_DSTATE_l;           /* '<S6>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c;          /* '<S6>/Unit Delay1' */
  real_T UnitDelay_DSTATE_as;          /* '<S7>/Unit Delay' */
  real_T UnitDelay1_DSTATE_e1;         /* '<S7>/Unit Delay1' */
  real_T UnitDelay_DSTATE_o;           /* '<S8>/Unit Delay' */
  real_T UnitDelay1_DSTATE_cs;         /* '<S8>/Unit Delay1' */
  real_T UnitDelay_DSTATE_i;           /* '<S9>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i;          /* '<S9>/Unit Delay1' */
  real_T UD_DSTATE;                    /* '<S337>/UD' */
  real_T UD_DSTATE_o;                  /* '<S279>/UD' */
  real_T UD_DSTATE_n;                  /* '<S221>/UD' */
  real_T UD_DSTATE_b;                  /* '<S163>/UD' */
  real_T UD_DSTATE_a;                  /* '<S105>/UD' */
  real_T UD_DSTATE_bd;                 /* '<S47>/UD' */
  struct {
    void *LoggedData[6];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[6];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_f;                    /* '<S9>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S9>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S9>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S9>/Scope4' */

  struct {
    void *LoggedData;
  } Scope_PWORK_p;                     /* '<S9>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_m;                    /* '<S8>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_g;                    /* '<S8>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_c;                    /* '<S8>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_g;                    /* '<S8>/Scope4' */

  struct {
    void *LoggedData;
  } Scope_PWORK_i;                     /* '<S8>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_e;                    /* '<S7>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_o;                    /* '<S7>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_m;                    /* '<S7>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_o;                    /* '<S7>/Scope4' */

  struct {
    void *LoggedData;
  } Scope_PWORK_a;                     /* '<S7>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_j;                    /* '<S6>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_k;                    /* '<S6>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_i;                    /* '<S6>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_ol;                   /* '<S6>/Scope4' */

  struct {
    void *LoggedData;
  } Scope_PWORK_f;                     /* '<S6>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_g;                    /* '<S5>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_d;                    /* '<S5>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_o;                    /* '<S5>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_gq;                   /* '<S5>/Scope4' */

  struct {
    void *LoggedData;
  } Scope_PWORK_pe;                    /* '<S5>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_k;                    /* '<S4>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_f;                    /* '<S4>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_iz;                   /* '<S4>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_k;                    /* '<S4>/Scope4' */

  struct {
    void *LoggedData;
  } Scope_PWORK_c;                     /* '<S4>/Scope' */

  int32_T sfEvent;                     /* '<Root>/MATLAB Function' */
  boolean_T objisempty;                /* '<S9>/PWM3' */
  boolean_T objisempty_l;              /* '<S9>/PWM2' */
  boolean_T objisempty_j;              /* '<S9>/Analog Input' */
  boolean_T objisempty_f;              /* '<S8>/PWM3' */
  boolean_T objisempty_o;              /* '<S8>/PWM2' */
  boolean_T objisempty_lv;             /* '<S8>/Analog Input' */
  boolean_T objisempty_h;              /* '<S7>/PWM3' */
  boolean_T objisempty_m;              /* '<S7>/PWM2' */
  boolean_T objisempty_jt;             /* '<S7>/Analog Input' */
  boolean_T objisempty_p;              /* '<S6>/PWM3' */
  boolean_T objisempty_c;              /* '<S6>/PWM2' */
  boolean_T objisempty_lo;             /* '<S6>/Analog Input' */
  boolean_T objisempty_f2;             /* '<S5>/PWM3' */
  boolean_T objisempty_h1;             /* '<S5>/PWM2' */
  boolean_T objisempty_g;              /* '<S5>/Analog Input' */
  boolean_T objisempty_ln;             /* '<S4>/PWM3' */
  boolean_T objisempty_e;              /* '<S4>/PWM2' */
  boolean_T objisempty_d;              /* '<S4>/Analog Input' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/MATLAB Function' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction2_h;/* '<S9>/MATLAB Function2' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction1_i3;/* '<S9>/MATLAB Function1' */
  DW_MATLABFunction_samerHARDWA_T sf_MATLABFunction_b;/* '<S9>/MATLAB Function' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction2_f;/* '<S8>/MATLAB Function2' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction1_i;/* '<S8>/MATLAB Function1' */
  DW_MATLABFunction_samerHARDWA_T sf_MATLABFunction_dw;/* '<S8>/MATLAB Function' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction2_e;/* '<S7>/MATLAB Function2' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction1_g;/* '<S7>/MATLAB Function1' */
  DW_MATLABFunction_samerHARDWA_T sf_MATLABFunction_m;/* '<S7>/MATLAB Function' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction2_m;/* '<S6>/MATLAB Function2' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction1_k;/* '<S6>/MATLAB Function1' */
  DW_MATLABFunction_samerHARDWA_T sf_MATLABFunction_hb;/* '<S6>/MATLAB Function' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction2_o;/* '<S5>/MATLAB Function2' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction1_h;/* '<S5>/MATLAB Function1' */
  DW_MATLABFunction_samerHARDWA_T sf_MATLABFunction_d;/* '<S5>/MATLAB Function' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction2;/* '<S4>/MATLAB Function2' */
  DW_MATLABFunction1_samerHARDW_T sf_MATLABFunction1;/* '<S4>/MATLAB Function1' */
  DW_MATLABFunction_samerHARDWA_T sf_MATLABFunction_h;/* '<S4>/MATLAB Function' */
} DW_samerHARDWAREPOTread_T;

/* Parameters (default storage) */
struct P_samerHARDWAREPOTread_T_ {
  real_T DiscretePIDController1_D;   /* Mask Parameter: DiscretePIDController1_D
                                      * Referenced by: '<S335>/Derivative Gain'
                                      */
  real_T DiscretePIDController1_D_c;
                                   /* Mask Parameter: DiscretePIDController1_D_c
                                    * Referenced by: '<S277>/Derivative Gain'
                                    */
  real_T DiscretePIDController1_D_ct;
                                  /* Mask Parameter: DiscretePIDController1_D_ct
                                   * Referenced by: '<S219>/Derivative Gain'
                                   */
  real_T DiscretePIDController1_D_a;
                                   /* Mask Parameter: DiscretePIDController1_D_a
                                    * Referenced by: '<S161>/Derivative Gain'
                                    */
  real_T DiscretePIDController1_D_k;
                                   /* Mask Parameter: DiscretePIDController1_D_k
                                    * Referenced by: '<S103>/Derivative Gain'
                                    */
  real_T DiscretePIDController1_D_e;
                                   /* Mask Parameter: DiscretePIDController1_D_e
                                    * Referenced by: '<S45>/Derivative Gain'
                                    */
  real_T DiscretePIDController1_Differen;
                              /* Mask Parameter: DiscretePIDController1_Differen
                               * Referenced by: '<S337>/UD'
                               */
  real_T DiscretePIDController1_Differ_d;
                              /* Mask Parameter: DiscretePIDController1_Differ_d
                               * Referenced by: '<S279>/UD'
                               */
  real_T DiscretePIDController1_Differ_c;
                              /* Mask Parameter: DiscretePIDController1_Differ_c
                               * Referenced by: '<S221>/UD'
                               */
  real_T DiscretePIDController1_Differ_g;
                              /* Mask Parameter: DiscretePIDController1_Differ_g
                               * Referenced by: '<S163>/UD'
                               */
  real_T DiscretePIDController1_Differ_j;
                              /* Mask Parameter: DiscretePIDController1_Differ_j
                               * Referenced by: '<S105>/UD'
                               */
  real_T DiscretePIDController1_Differ_n;
                              /* Mask Parameter: DiscretePIDController1_Differ_n
                               * Referenced by: '<S47>/UD'
                               */
  real_T DiscretePIDController1_P;   /* Mask Parameter: DiscretePIDController1_P
                                      * Referenced by: '<S349>/Proportional Gain'
                                      */
  real_T DiscretePIDController1_P_f;
                                   /* Mask Parameter: DiscretePIDController1_P_f
                                    * Referenced by: '<S291>/Proportional Gain'
                                    */
  real_T DiscretePIDController1_P_fb;
                                  /* Mask Parameter: DiscretePIDController1_P_fb
                                   * Referenced by: '<S233>/Proportional Gain'
                                   */
  real_T DiscretePIDController1_P_o;
                                   /* Mask Parameter: DiscretePIDController1_P_o
                                    * Referenced by: '<S175>/Proportional Gain'
                                    */
  real_T DiscretePIDController1_P_e;
                                   /* Mask Parameter: DiscretePIDController1_P_e
                                    * Referenced by: '<S117>/Proportional Gain'
                                    */
  real_T DiscretePIDController1_P_a;
                                   /* Mask Parameter: DiscretePIDController1_P_a
                                    * Referenced by: '<S59>/Proportional Gain'
                                    */
  real_T Constant2_Value;              /* Expression: 10
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Gain18_Gain;                  /* Expression: 0.03
                                        * Referenced by: '<Root>/Gain18'
                                        */
  real_T Gain19_Gain;                  /* Expression: 10
                                        * Referenced by: '<Root>/Gain19'
                                        */
  real_T Gain15_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<Root>/Gain15'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain14_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<Root>/Gain14'
                                        */
  real_T Constant6_Value;              /* Expression: 278.7
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant8_Value;              /* Expression: 20
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant7_Value;              /* Expression: 10
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Gain16_Gain;                  /* Expression: 0.03
                                        * Referenced by: '<Root>/Gain16'
                                        */
  real_T Gain17_Gain;                  /* Expression: 10
                                        * Referenced by: '<Root>/Gain17'
                                        */
  real_T Gain21_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<Root>/Gain21'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Gain12_Gain;                  /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain12'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Gain13_Gain;                  /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain13'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Gain20_Gain;                  /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain20'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1000
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S4>/Unit Delay'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.13575
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.13575
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S4>/Unit Delay1'
                                        */
  real_T Gain3_Gain_p;                 /* Expression: 0.72848
                                        * Referenced by: '<S4>/Gain3'
                                        */
  real_T Gain_Gain;                    /* Expression: 100/1024
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1000
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T UnitDelay_InitialCondition_f; /* Expression: 0
                                        * Referenced by: '<S5>/Unit Delay'
                                        */
  real_T Gain2_Gain_h;                 /* Expression: 0.13575
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: 0.13575
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T UnitDelay1_InitialCondition_g;/* Expression: 0
                                        * Referenced by: '<S5>/Unit Delay1'
                                        */
  real_T Gain3_Gain_j;                 /* Expression: 0.72848
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 100/1024
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1000
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T UnitDelay_InitialCondition_a; /* Expression: 0
                                        * Referenced by: '<S6>/Unit Delay'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: 0.13575
                                        * Referenced by: '<S6>/Gain2'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 0.13575
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T UnitDelay1_InitialCondition_c;/* Expression: 0
                                        * Referenced by: '<S6>/Unit Delay1'
                                        */
  real_T Gain3_Gain_g;                 /* Expression: 0.72848
                                        * Referenced by: '<S6>/Gain3'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 100/1024
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1000
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T UnitDelay_InitialCondition_as;/* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay'
                                        */
  real_T Gain2_Gain_ea;                /* Expression: 0.13575
                                        * Referenced by: '<S7>/Gain2'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: 0.13575
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T UnitDelay1_InitialCondition_h;/* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay1'
                                        */
  real_T Gain3_Gain_e;                 /* Expression: 0.72848
                                        * Referenced by: '<S7>/Gain3'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 100/1024
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Gain7_Gain;                   /* Expression: 1000
                                        * Referenced by: '<Root>/Gain7'
                                        */
  real_T UnitDelay_InitialCondition_n; /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay'
                                        */
  real_T Gain2_Gain_m;                 /* Expression: 0.13575
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: 0.13575
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T UnitDelay1_InitialCondition_gp;/* Expression: 0
                                         * Referenced by: '<S8>/Unit Delay1'
                                         */
  real_T Gain3_Gain_go;                /* Expression: 0.72848
                                        * Referenced by: '<S8>/Gain3'
                                        */
  real_T Gain_Gain_es;                 /* Expression: 100/1024
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Gain8_Gain;                   /* Expression: 1000
                                        * Referenced by: '<Root>/Gain8'
                                        */
  real_T UnitDelay_InitialCondition_g; /* Expression: 0
                                        * Referenced by: '<S9>/Unit Delay'
                                        */
  real_T Gain2_Gain_ha;                /* Expression: 0.13575
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: 0.13575
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T UnitDelay1_InitialCondition_l;/* Expression: 0
                                        * Referenced by: '<S9>/Unit Delay1'
                                        */
  real_T Gain3_Gain_h;                 /* Expression: 0.72848
                                        * Referenced by: '<S9>/Gain3'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 100/1024
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 255
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Tsamp_WtEt;                   /* Computed Parameter: Tsamp_WtEt
                                        * Referenced by: '<S339>/Tsamp'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 200
                                        * Referenced by: '<S9>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S9>/Saturation1'
                                        */
  real_T Switch_Threshold;             /* Expression: 5
                                        * Referenced by: '<S9>/Switch'
                                        */
  real_T Gain4_Gain_d;                 /* Expression: 0.45
                                        * Referenced by: '<S9>/Gain4'
                                        */
  real_T Constant_Value_p;             /* Expression: 255
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Tsamp_WtEt_a;                 /* Computed Parameter: Tsamp_WtEt_a
                                        * Referenced by: '<S281>/Tsamp'
                                        */
  real_T Saturation1_UpperSat_i;       /* Expression: 200
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_f;       /* Expression: 0
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  real_T Switch_Threshold_e;           /* Expression: 5
                                        * Referenced by: '<S8>/Switch'
                                        */
  real_T Gain4_Gain_j;                 /* Expression: 0.45
                                        * Referenced by: '<S8>/Gain4'
                                        */
  real_T Constant_Value_i;             /* Expression: 255
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Tsamp_WtEt_o;                 /* Computed Parameter: Tsamp_WtEt_o
                                        * Referenced by: '<S223>/Tsamp'
                                        */
  real_T Saturation1_UpperSat_b;       /* Expression: 200
                                        * Referenced by: '<S7>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: 0
                                        * Referenced by: '<S7>/Saturation1'
                                        */
  real_T Switch_Threshold_eq;          /* Expression: 5
                                        * Referenced by: '<S7>/Switch'
                                        */
  real_T Gain4_Gain_dn;                /* Expression: 0.45
                                        * Referenced by: '<S7>/Gain4'
                                        */
  real_T Constant_Value_o;             /* Expression: 255
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Tsamp_WtEt_d;                 /* Computed Parameter: Tsamp_WtEt_d
                                        * Referenced by: '<S165>/Tsamp'
                                        */
  real_T Saturation1_UpperSat_k;       /* Expression: 200
                                        * Referenced by: '<S6>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_b;       /* Expression: 0
                                        * Referenced by: '<S6>/Saturation1'
                                        */
  real_T Switch_Threshold_d;           /* Expression: 5
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Gain4_Gain_h;                 /* Expression: 0.45
                                        * Referenced by: '<S6>/Gain4'
                                        */
  real_T Constant_Value_k;             /* Expression: 255
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Tsamp_WtEt_b;                 /* Computed Parameter: Tsamp_WtEt_b
                                        * Referenced by: '<S107>/Tsamp'
                                        */
  real_T Saturation1_UpperSat_j;       /* Expression: 200
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_j;       /* Expression: 0
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 5
                                        * Referenced by: '<S5>/Switch'
                                        */
  real_T Gain4_Gain_k;                 /* Expression: 0.45
                                        * Referenced by: '<S5>/Gain4'
                                        */
  real_T Constant_Value_c;             /* Expression: 255
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Tsamp_WtEt_i;                 /* Computed Parameter: Tsamp_WtEt_i
                                        * Referenced by: '<S49>/Tsamp'
                                        */
  real_T Saturation1_UpperSat_c;       /* Expression: 200
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_d;       /* Expression: 0
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 5
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Gain4_Gain_i;                 /* Expression: 0.45
                                        * Referenced by: '<S4>/Gain4'
                                        */
  int16_T LookUpTable_tableData[33];/* Computed Parameter: LookUpTable_tableData
                                     * Referenced by: '<S10>/Look-Up Table'
                                     */
  int16_T LookUpTable_tableData_i[33];
                                  /* Computed Parameter: LookUpTable_tableData_i
                                   * Referenced by: '<S12>/Look-Up Table'
                                   */
  uint16_T Point25_Value;              /* Computed Parameter: Point25_Value
                                        * Referenced by: '<S11>/Point25'
                                        */
  uint16_T Point50_Value;              /* Computed Parameter: Point50_Value
                                        * Referenced by: '<S11>/Point50'
                                        */
  uint16_T Point75_Value;              /* Computed Parameter: Point75_Value
                                        * Referenced by: '<S11>/Point75'
                                        */
  uint16_T LookUpTable_bp01Data[33]; /* Computed Parameter: LookUpTable_bp01Data
                                      * Referenced by: '<S10>/Look-Up Table'
                                      */
  uint16_T Point50_Value_p;            /* Computed Parameter: Point50_Value_p
                                        * Referenced by: '<S13>/Point50'
                                        */
  uint16_T Point25_Value_a;            /* Computed Parameter: Point25_Value_a
                                        * Referenced by: '<S13>/Point25'
                                        */
  uint16_T LookUpTable_bp01Data_l[33];
                                   /* Computed Parameter: LookUpTable_bp01Data_l
                                    * Referenced by: '<S12>/Look-Up Table'
                                    */
};

/* Real-time Model Data Structure */
struct tag_RTM_samerHARDWAREPOTread_T {
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
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_samerHARDWAREPOTread_T samerHARDWAREPOTread_P;

/* Block signals (default storage) */
extern B_samerHARDWAREPOTread_T samerHARDWAREPOTread_B;

/* Block states (default storage) */
extern DW_samerHARDWAREPOTread_T samerHARDWAREPOTread_DW;

/* Model entry point functions */
extern void samerHARDWAREPOTread_initialize(void);
extern void samerHARDWAREPOTread_step(void);
extern void samerHARDWAREPOTread_terminate(void);

/* Real-time Model object */
extern RT_MODEL_samerHARDWAREPOTread_T *const samerHARDWAREPOTread_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S47>/DTDup' : Unused code path elimination
 * Block '<S105>/DTDup' : Unused code path elimination
 * Block '<S163>/DTDup' : Unused code path elimination
 * Block '<S221>/DTDup' : Unused code path elimination
 * Block '<S279>/DTDup' : Unused code path elimination
 * Block '<S337>/DTDup' : Unused code path elimination
 * Block '<S4>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S7>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'samerHARDWAREPOTread'
 * '<S1>'   : 'samerHARDWAREPOTread/Cosine'
 * '<S2>'   : 'samerHARDWAREPOTread/MATLAB Function'
 * '<S3>'   : 'samerHARDWAREPOTread/Sine2'
 * '<S4>'   : 'samerHARDWAREPOTread/Subsystem'
 * '<S5>'   : 'samerHARDWAREPOTread/Subsystem1'
 * '<S6>'   : 'samerHARDWAREPOTread/Subsystem2'
 * '<S7>'   : 'samerHARDWAREPOTread/Subsystem3'
 * '<S8>'   : 'samerHARDWAREPOTread/Subsystem4'
 * '<S9>'   : 'samerHARDWAREPOTread/Subsystem5'
 * '<S10>'  : 'samerHARDWAREPOTread/Cosine/Cosine'
 * '<S11>'  : 'samerHARDWAREPOTread/Cosine/Cosine/Handle Quarter Symmetry Cosine'
 * '<S12>'  : 'samerHARDWAREPOTread/Sine2/Sine'
 * '<S13>'  : 'samerHARDWAREPOTread/Sine2/Sine/Handle Quarter Symmetry Sine'
 * '<S14>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1'
 * '<S15>'  : 'samerHARDWAREPOTread/Subsystem/MATLAB Function'
 * '<S16>'  : 'samerHARDWAREPOTread/Subsystem/MATLAB Function1'
 * '<S17>'  : 'samerHARDWAREPOTread/Subsystem/MATLAB Function2'
 * '<S18>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Anti-windup'
 * '<S19>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/D Gain'
 * '<S20>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/External Derivative'
 * '<S21>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Filter'
 * '<S22>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Filter ICs'
 * '<S23>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/I Gain'
 * '<S24>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Ideal P Gain'
 * '<S25>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S26>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Integrator'
 * '<S27>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Integrator ICs'
 * '<S28>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/N Copy'
 * '<S29>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/N Gain'
 * '<S30>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/P Copy'
 * '<S31>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Parallel P Gain'
 * '<S32>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Reset Signal'
 * '<S33>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Saturation'
 * '<S34>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Saturation Fdbk'
 * '<S35>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Sum'
 * '<S36>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Sum Fdbk'
 * '<S37>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Tracking Mode'
 * '<S38>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Tracking Mode Sum'
 * '<S39>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Tsamp - Integral'
 * '<S40>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Tsamp - Ngain'
 * '<S41>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/postSat Signal'
 * '<S42>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/preInt Signal'
 * '<S43>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/preSat Signal'
 * '<S44>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Anti-windup/Disabled'
 * '<S45>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S46>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/External Derivative/Error'
 * '<S47>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Filter/Differentiator'
 * '<S48>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Filter/Differentiator/Tsamp'
 * '<S49>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S50>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S51>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/I Gain/Disabled'
 * '<S52>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S53>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S54>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Integrator/Disabled'
 * '<S55>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Integrator ICs/Disabled'
 * '<S56>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S57>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/N Gain/Passthrough'
 * '<S58>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/P Copy/Disabled'
 * '<S59>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S60>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S61>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Saturation/Passthrough'
 * '<S62>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S63>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Sum/Sum_PD'
 * '<S64>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S65>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S66>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S67>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S68>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S69>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S70>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S71>'  : 'samerHARDWAREPOTread/Subsystem/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S72>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1'
 * '<S73>'  : 'samerHARDWAREPOTread/Subsystem1/MATLAB Function'
 * '<S74>'  : 'samerHARDWAREPOTread/Subsystem1/MATLAB Function1'
 * '<S75>'  : 'samerHARDWAREPOTread/Subsystem1/MATLAB Function2'
 * '<S76>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Anti-windup'
 * '<S77>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/D Gain'
 * '<S78>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/External Derivative'
 * '<S79>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Filter'
 * '<S80>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Filter ICs'
 * '<S81>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/I Gain'
 * '<S82>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Ideal P Gain'
 * '<S83>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S84>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Integrator'
 * '<S85>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Integrator ICs'
 * '<S86>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/N Copy'
 * '<S87>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/N Gain'
 * '<S88>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/P Copy'
 * '<S89>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Parallel P Gain'
 * '<S90>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Reset Signal'
 * '<S91>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Saturation'
 * '<S92>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Saturation Fdbk'
 * '<S93>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Sum'
 * '<S94>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Sum Fdbk'
 * '<S95>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Tracking Mode'
 * '<S96>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Tracking Mode Sum'
 * '<S97>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Tsamp - Integral'
 * '<S98>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Tsamp - Ngain'
 * '<S99>'  : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/postSat Signal'
 * '<S100>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/preInt Signal'
 * '<S101>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/preSat Signal'
 * '<S102>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Anti-windup/Disabled'
 * '<S103>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S104>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/External Derivative/Error'
 * '<S105>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Filter/Differentiator'
 * '<S106>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Filter/Differentiator/Tsamp'
 * '<S107>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S108>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S109>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/I Gain/Disabled'
 * '<S110>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S111>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S112>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Integrator/Disabled'
 * '<S113>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Integrator ICs/Disabled'
 * '<S114>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S115>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/N Gain/Passthrough'
 * '<S116>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/P Copy/Disabled'
 * '<S117>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S118>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S119>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Saturation/Passthrough'
 * '<S120>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S121>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Sum/Sum_PD'
 * '<S122>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S123>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S124>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S125>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S126>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S127>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S128>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S129>' : 'samerHARDWAREPOTread/Subsystem1/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S130>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1'
 * '<S131>' : 'samerHARDWAREPOTread/Subsystem2/MATLAB Function'
 * '<S132>' : 'samerHARDWAREPOTread/Subsystem2/MATLAB Function1'
 * '<S133>' : 'samerHARDWAREPOTread/Subsystem2/MATLAB Function2'
 * '<S134>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Anti-windup'
 * '<S135>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/D Gain'
 * '<S136>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/External Derivative'
 * '<S137>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Filter'
 * '<S138>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Filter ICs'
 * '<S139>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/I Gain'
 * '<S140>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Ideal P Gain'
 * '<S141>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S142>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Integrator'
 * '<S143>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Integrator ICs'
 * '<S144>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/N Copy'
 * '<S145>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/N Gain'
 * '<S146>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/P Copy'
 * '<S147>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Parallel P Gain'
 * '<S148>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Reset Signal'
 * '<S149>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Saturation'
 * '<S150>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Saturation Fdbk'
 * '<S151>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Sum'
 * '<S152>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Sum Fdbk'
 * '<S153>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Tracking Mode'
 * '<S154>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Tracking Mode Sum'
 * '<S155>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Tsamp - Integral'
 * '<S156>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Tsamp - Ngain'
 * '<S157>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/postSat Signal'
 * '<S158>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/preInt Signal'
 * '<S159>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/preSat Signal'
 * '<S160>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Anti-windup/Disabled'
 * '<S161>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S162>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/External Derivative/Error'
 * '<S163>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Filter/Differentiator'
 * '<S164>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Filter/Differentiator/Tsamp'
 * '<S165>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S166>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S167>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/I Gain/Disabled'
 * '<S168>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S169>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S170>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Integrator/Disabled'
 * '<S171>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Integrator ICs/Disabled'
 * '<S172>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S173>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/N Gain/Passthrough'
 * '<S174>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/P Copy/Disabled'
 * '<S175>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S176>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S177>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Saturation/Passthrough'
 * '<S178>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S179>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Sum/Sum_PD'
 * '<S180>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S181>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S182>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S183>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S184>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S185>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S186>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S187>' : 'samerHARDWAREPOTread/Subsystem2/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S188>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1'
 * '<S189>' : 'samerHARDWAREPOTread/Subsystem3/MATLAB Function'
 * '<S190>' : 'samerHARDWAREPOTread/Subsystem3/MATLAB Function1'
 * '<S191>' : 'samerHARDWAREPOTread/Subsystem3/MATLAB Function2'
 * '<S192>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Anti-windup'
 * '<S193>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/D Gain'
 * '<S194>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/External Derivative'
 * '<S195>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Filter'
 * '<S196>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Filter ICs'
 * '<S197>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/I Gain'
 * '<S198>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Ideal P Gain'
 * '<S199>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S200>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Integrator'
 * '<S201>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Integrator ICs'
 * '<S202>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/N Copy'
 * '<S203>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/N Gain'
 * '<S204>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/P Copy'
 * '<S205>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Parallel P Gain'
 * '<S206>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Reset Signal'
 * '<S207>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Saturation'
 * '<S208>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Saturation Fdbk'
 * '<S209>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Sum'
 * '<S210>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Sum Fdbk'
 * '<S211>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Tracking Mode'
 * '<S212>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Tracking Mode Sum'
 * '<S213>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Tsamp - Integral'
 * '<S214>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Tsamp - Ngain'
 * '<S215>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/postSat Signal'
 * '<S216>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/preInt Signal'
 * '<S217>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/preSat Signal'
 * '<S218>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Anti-windup/Disabled'
 * '<S219>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S220>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/External Derivative/Error'
 * '<S221>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Filter/Differentiator'
 * '<S222>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Filter/Differentiator/Tsamp'
 * '<S223>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S224>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S225>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/I Gain/Disabled'
 * '<S226>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S227>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S228>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Integrator/Disabled'
 * '<S229>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Integrator ICs/Disabled'
 * '<S230>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S231>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/N Gain/Passthrough'
 * '<S232>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/P Copy/Disabled'
 * '<S233>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S234>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S235>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Saturation/Passthrough'
 * '<S236>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S237>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Sum/Sum_PD'
 * '<S238>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S239>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S240>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S241>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S242>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S243>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S244>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S245>' : 'samerHARDWAREPOTread/Subsystem3/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S246>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1'
 * '<S247>' : 'samerHARDWAREPOTread/Subsystem4/MATLAB Function'
 * '<S248>' : 'samerHARDWAREPOTread/Subsystem4/MATLAB Function1'
 * '<S249>' : 'samerHARDWAREPOTread/Subsystem4/MATLAB Function2'
 * '<S250>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Anti-windup'
 * '<S251>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/D Gain'
 * '<S252>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/External Derivative'
 * '<S253>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Filter'
 * '<S254>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Filter ICs'
 * '<S255>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/I Gain'
 * '<S256>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Ideal P Gain'
 * '<S257>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S258>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Integrator'
 * '<S259>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Integrator ICs'
 * '<S260>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/N Copy'
 * '<S261>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/N Gain'
 * '<S262>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/P Copy'
 * '<S263>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Parallel P Gain'
 * '<S264>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Reset Signal'
 * '<S265>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Saturation'
 * '<S266>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Saturation Fdbk'
 * '<S267>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Sum'
 * '<S268>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Sum Fdbk'
 * '<S269>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Tracking Mode'
 * '<S270>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Tracking Mode Sum'
 * '<S271>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Tsamp - Integral'
 * '<S272>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Tsamp - Ngain'
 * '<S273>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/postSat Signal'
 * '<S274>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/preInt Signal'
 * '<S275>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/preSat Signal'
 * '<S276>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Anti-windup/Disabled'
 * '<S277>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S278>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/External Derivative/Error'
 * '<S279>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Filter/Differentiator'
 * '<S280>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Filter/Differentiator/Tsamp'
 * '<S281>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S282>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S283>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/I Gain/Disabled'
 * '<S284>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S285>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S286>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Integrator/Disabled'
 * '<S287>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Integrator ICs/Disabled'
 * '<S288>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S289>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/N Gain/Passthrough'
 * '<S290>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/P Copy/Disabled'
 * '<S291>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S292>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S293>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Saturation/Passthrough'
 * '<S294>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S295>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Sum/Sum_PD'
 * '<S296>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S297>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S298>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S299>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S300>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S301>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S302>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S303>' : 'samerHARDWAREPOTread/Subsystem4/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S304>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1'
 * '<S305>' : 'samerHARDWAREPOTread/Subsystem5/MATLAB Function'
 * '<S306>' : 'samerHARDWAREPOTread/Subsystem5/MATLAB Function1'
 * '<S307>' : 'samerHARDWAREPOTread/Subsystem5/MATLAB Function2'
 * '<S308>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Anti-windup'
 * '<S309>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/D Gain'
 * '<S310>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/External Derivative'
 * '<S311>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Filter'
 * '<S312>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Filter ICs'
 * '<S313>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/I Gain'
 * '<S314>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Ideal P Gain'
 * '<S315>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S316>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Integrator'
 * '<S317>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Integrator ICs'
 * '<S318>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/N Copy'
 * '<S319>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/N Gain'
 * '<S320>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/P Copy'
 * '<S321>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Parallel P Gain'
 * '<S322>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Reset Signal'
 * '<S323>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Saturation'
 * '<S324>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Saturation Fdbk'
 * '<S325>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Sum'
 * '<S326>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Sum Fdbk'
 * '<S327>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Tracking Mode'
 * '<S328>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Tracking Mode Sum'
 * '<S329>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Tsamp - Integral'
 * '<S330>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Tsamp - Ngain'
 * '<S331>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/postSat Signal'
 * '<S332>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/preInt Signal'
 * '<S333>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/preSat Signal'
 * '<S334>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Anti-windup/Disabled'
 * '<S335>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S336>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/External Derivative/Error'
 * '<S337>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Filter/Differentiator'
 * '<S338>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Filter/Differentiator/Tsamp'
 * '<S339>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S340>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S341>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/I Gain/Disabled'
 * '<S342>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S343>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S344>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Integrator/Disabled'
 * '<S345>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Integrator ICs/Disabled'
 * '<S346>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S347>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/N Gain/Passthrough'
 * '<S348>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/P Copy/Disabled'
 * '<S349>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S350>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S351>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Saturation/Passthrough'
 * '<S352>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S353>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Sum/Sum_PD'
 * '<S354>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S355>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S356>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S357>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S358>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S359>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S360>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S361>' : 'samerHARDWAREPOTread/Subsystem5/Discrete PID Controller1/preSat Signal/Forward_Path'
 */
#endif                                 /* samerHARDWAREPOTread_h_ */
