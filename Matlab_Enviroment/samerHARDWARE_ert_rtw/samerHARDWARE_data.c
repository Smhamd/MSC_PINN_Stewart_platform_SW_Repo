/*
 * samerHARDWARE_data.c
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

/* Block parameters (default storage) */
P_samerHARDWARE_T samerHARDWARE_P = {
  /* Mask Parameter: DiscretePIDController1_D
   * Referenced by: '<S331>/Derivative Gain'
   */
  0.75,

  /* Mask Parameter: DiscretePIDController1_D_c
   * Referenced by: '<S215>/Derivative Gain'
   */
  0.75,

  /* Mask Parameter: DiscretePIDController1_D_a
   * Referenced by: '<S157>/Derivative Gain'
   */
  0.75,

  /* Mask Parameter: DiscretePIDController1_D_k
   * Referenced by: '<S99>/Derivative Gain'
   */
  0.75,

  /* Mask Parameter: DiscretePIDController1_D_e
   * Referenced by: '<S43>/Derivative Gain'
   */
  0.75,

  /* Mask Parameter: DiscretePIDController1_D_cj
   * Referenced by: '<S273>/Derivative Gain'
   */
  0.75,

  /* Mask Parameter: DiscretePIDController1_Differen
   * Referenced by: '<S333>/UD'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_Differ_c
   * Referenced by: '<S217>/UD'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_Differ_g
   * Referenced by: '<S159>/UD'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_Differ_j
   * Referenced by: '<S101>/UD'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_Differ_d
   * Referenced by: '<S275>/UD'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_I
   * Referenced by: '<S337>/Integral Gain'
   */
  0.5,

  /* Mask Parameter: DiscretePIDController1_I_l
   * Referenced by: '<S221>/Integral Gain'
   */
  0.5,

  /* Mask Parameter: DiscretePIDController1_I_i
   * Referenced by: '<S163>/Integral Gain'
   */
  0.5,

  /* Mask Parameter: DiscretePIDController1_I_f
   * Referenced by: '<S105>/Integral Gain'
   */
  0.5,

  /* Mask Parameter: DiscretePIDController1_I_m
   * Referenced by: '<S47>/Integral Gain'
   */
  0.5,

  /* Mask Parameter: DiscretePIDController1_I_o
   * Referenced by: '<S279>/Integral Gain'
   */
  0.5,

  /* Mask Parameter: DiscretePIDController1_InitialC
   * Referenced by: '<S45>/Filter'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_Initia_d
   * Referenced by: '<S340>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_Initia_c
   * Referenced by: '<S224>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_Initia_l
   * Referenced by: '<S166>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_Initia_h
   * Referenced by: '<S108>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_Initi_la
   * Referenced by: '<S50>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_Initia_f
   * Referenced by: '<S282>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_N
   * Referenced by: '<S53>/Filter Coefficient'
   */
  1.0,

  /* Mask Parameter: DiscretePIDController1_P
   * Referenced by: '<S345>/Proportional Gain'
   */
  175.0,

  /* Mask Parameter: DiscretePIDController1_P_f
   * Referenced by: '<S229>/Proportional Gain'
   */
  175.0,

  /* Mask Parameter: DiscretePIDController1_P_o
   * Referenced by: '<S171>/Proportional Gain'
   */
  175.0,

  /* Mask Parameter: DiscretePIDController1_P_e
   * Referenced by: '<S113>/Proportional Gain'
   */
  175.0,

  /* Mask Parameter: DiscretePIDController1_P_a
   * Referenced by: '<S55>/Proportional Gain'
   */
  175.0,

  /* Mask Parameter: DiscretePIDController1_P_fd
   * Referenced by: '<S287>/Proportional Gain'
   */
  175.0,

  /* Expression: [0;0;0;0;0;0;0;0;0;0;0;0;0;0;1]
   * Referenced by: '<Root>/Constant'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/Unit Delay8'
   */
  0.0,

  /* Expression: 0.13575
   * Referenced by: '<S11>/Gain18'
   */
  0.13575,

  /* Expression: 0.13575
   * Referenced by: '<S11>/Gain17'
   */
  0.13575,

  /* Expression: 0
   * Referenced by: '<S11>/Unit Delay9'
   */
  0.0,

  /* Expression: 0.72848
   * Referenced by: '<S11>/Gain19'
   */
  0.72848,

  /* Expression: 100/1024
   * Referenced by: '<S11>/Gain16'
   */
  0.09765625,

  /* Expression: 0
   * Referenced by: '<S11>/Unit Delay'
   */
  0.0,

  /* Expression: 0.13575
   * Referenced by: '<S11>/Gain2'
   */
  0.13575,

  /* Expression: 0.13575
   * Referenced by: '<S11>/Gain1'
   */
  0.13575,

  /* Expression: 0
   * Referenced by: '<S11>/Unit Delay1'
   */
  0.0,

  /* Expression: 0.72848
   * Referenced by: '<S11>/Gain3'
   */
  0.72848,

  /* Expression: 100/1024
   * Referenced by: '<S11>/Gain'
   */
  0.09765625,

  /* Expression: 0
   * Referenced by: '<S11>/Unit Delay2'
   */
  0.0,

  /* Expression: 0.13575
   * Referenced by: '<S11>/Gain6'
   */
  0.13575,

  /* Expression: 0.13575
   * Referenced by: '<S11>/Gain5'
   */
  0.13575,

  /* Expression: 0
   * Referenced by: '<S11>/Unit Delay3'
   */
  0.0,

  /* Expression: 0.72848
   * Referenced by: '<S11>/Gain7'
   */
  0.72848,

  /* Expression: 100/1024
   * Referenced by: '<S11>/Gain4'
   */
  0.09765625,

  /* Expression: 0
   * Referenced by: '<S11>/Unit Delay4'
   */
  0.0,

  /* Expression: 0.13575
   * Referenced by: '<S11>/Gain10'
   */
  0.13575,

  /* Expression: 0.13575
   * Referenced by: '<S11>/Gain9'
   */
  0.13575,

  /* Expression: 0
   * Referenced by: '<S11>/Unit Delay5'
   */
  0.0,

  /* Expression: 0.72848
   * Referenced by: '<S11>/Gain11'
   */
  0.72848,

  /* Expression: 100/1024
   * Referenced by: '<S11>/Gain8'
   */
  0.09765625,

  /* Expression: 0
   * Referenced by: '<S11>/Unit Delay6'
   */
  0.0,

  /* Expression: 0.13575
   * Referenced by: '<S11>/Gain14'
   */
  0.13575,

  /* Expression: 0.13575
   * Referenced by: '<S11>/Gain13'
   */
  0.13575,

  /* Expression: 0
   * Referenced by: '<S11>/Unit Delay7'
   */
  0.0,

  /* Expression: 0.72848
   * Referenced by: '<S11>/Gain15'
   */
  0.72848,

  /* Expression: 100/1024
   * Referenced by: '<S11>/Gain12'
   */
  0.09765625,

  /* Expression: 0
   * Referenced by: '<S11>/Unit Delay10'
   */
  0.0,

  /* Expression: 0.13575
   * Referenced by: '<S11>/Gain22'
   */
  0.13575,

  /* Expression: 0.13575
   * Referenced by: '<S11>/Gain21'
   */
  0.13575,

  /* Expression: 0
   * Referenced by: '<S11>/Unit Delay11'
   */
  0.0,

  /* Expression: 0.72848
   * Referenced by: '<S11>/Gain23'
   */
  0.72848,

  /* Expression: 100/1024
   * Referenced by: '<S11>/Gain20'
   */
  0.09765625,

  /* Expression: 255
   * Referenced by: '<S10>/Constant'
   */
  255.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S340>/Integrator'
   */
  0.01,

  /* Computed Parameter: Tsamp_WtEt
   * Referenced by: '<S335>/Tsamp'
   */
  100.0,

  /* Expression: 220
   * Referenced by: '<S10>/Saturation1'
   */
  220.0,

  /* Expression: 0
   * Referenced by: '<S10>/Saturation1'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S10>/Switch'
   */
  5.0,

  /* Expression: 0.45
   * Referenced by: '<S10>/Gain4'
   */
  0.45,

  /* Expression: 255
   * Referenced by: '<S8>/Constant'
   */
  255.0,

  /* Computed Parameter: Integrator_gainval_k
   * Referenced by: '<S224>/Integrator'
   */
  0.01,

  /* Computed Parameter: Tsamp_WtEt_o
   * Referenced by: '<S219>/Tsamp'
   */
  100.0,

  /* Expression: 220
   * Referenced by: '<S8>/Saturation1'
   */
  220.0,

  /* Expression: 0
   * Referenced by: '<S8>/Saturation1'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S8>/Switch'
   */
  5.0,

  /* Expression: 0.45
   * Referenced by: '<S8>/Gain4'
   */
  0.45,

  /* Expression: 255
   * Referenced by: '<S7>/Constant'
   */
  255.0,

  /* Computed Parameter: Integrator_gainval_k3
   * Referenced by: '<S166>/Integrator'
   */
  0.01,

  /* Computed Parameter: Tsamp_WtEt_d
   * Referenced by: '<S161>/Tsamp'
   */
  100.0,

  /* Expression: 220
   * Referenced by: '<S7>/Saturation1'
   */
  220.0,

  /* Expression: 0
   * Referenced by: '<S7>/Saturation1'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S7>/Switch'
   */
  5.0,

  /* Expression: 0.45
   * Referenced by: '<S7>/Gain4'
   */
  0.45,

  /* Expression: 255
   * Referenced by: '<S6>/Constant'
   */
  255.0,

  /* Computed Parameter: Integrator_gainval_g
   * Referenced by: '<S108>/Integrator'
   */
  0.01,

  /* Computed Parameter: Tsamp_WtEt_b
   * Referenced by: '<S103>/Tsamp'
   */
  100.0,

  /* Expression: 220
   * Referenced by: '<S6>/Saturation1'
   */
  220.0,

  /* Expression: 0
   * Referenced by: '<S6>/Saturation1'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S6>/Switch'
   */
  5.0,

  /* Expression: 0.45
   * Referenced by: '<S6>/Gain4'
   */
  0.45,

  /* Expression: 255
   * Referenced by: '<S5>/Constant'
   */
  255.0,

  /* Computed Parameter: Integrator_gainval_l
   * Referenced by: '<S50>/Integrator'
   */
  0.01,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S45>/Filter'
   */
  0.01,

  /* Expression: 220
   * Referenced by: '<S5>/Saturation1'
   */
  220.0,

  /* Expression: 0
   * Referenced by: '<S5>/Saturation1'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S5>/Switch'
   */
  5.0,

  /* Expression: 0.45
   * Referenced by: '<S5>/Gain4'
   */
  0.45,

  /* Expression: 255
   * Referenced by: '<S9>/Constant'
   */
  255.0,

  /* Computed Parameter: Integrator_gainval_l4
   * Referenced by: '<S282>/Integrator'
   */
  0.01,

  /* Computed Parameter: Tsamp_WtEt_a
   * Referenced by: '<S277>/Tsamp'
   */
  100.0,

  /* Expression: 220
   * Referenced by: '<S9>/Saturation1'
   */
  220.0,

  /* Expression: 0
   * Referenced by: '<S9>/Saturation1'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S9>/Switch'
   */
  5.0,

  /* Expression: 0.45
   * Referenced by: '<S9>/Gain4'
   */
  0.45
};
