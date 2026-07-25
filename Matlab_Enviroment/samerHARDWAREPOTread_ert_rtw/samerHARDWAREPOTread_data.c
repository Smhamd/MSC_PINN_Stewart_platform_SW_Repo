/*
 * samerHARDWAREPOTread_data.c
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

/* Block parameters (default storage) */
P_samerHARDWAREPOTread_T samerHARDWAREPOTread_P = {
  /* Mask Parameter: DiscretePIDController1_D
   * Referenced by: '<S335>/Derivative Gain'
   */
  0.75,

  /* Mask Parameter: DiscretePIDController1_D_c
   * Referenced by: '<S277>/Derivative Gain'
   */
  0.75,

  /* Mask Parameter: DiscretePIDController1_D_ct
   * Referenced by: '<S219>/Derivative Gain'
   */
  0.75,

  /* Mask Parameter: DiscretePIDController1_D_a
   * Referenced by: '<S161>/Derivative Gain'
   */
  0.75,

  /* Mask Parameter: DiscretePIDController1_D_k
   * Referenced by: '<S103>/Derivative Gain'
   */
  0.75,

  /* Mask Parameter: DiscretePIDController1_D_e
   * Referenced by: '<S45>/Derivative Gain'
   */
  0.75,

  /* Mask Parameter: DiscretePIDController1_Differen
   * Referenced by: '<S337>/UD'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_Differ_d
   * Referenced by: '<S279>/UD'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_Differ_c
   * Referenced by: '<S221>/UD'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_Differ_g
   * Referenced by: '<S163>/UD'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_Differ_j
   * Referenced by: '<S105>/UD'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_Differ_n
   * Referenced by: '<S47>/UD'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_P
   * Referenced by: '<S349>/Proportional Gain'
   */
  325.0,

  /* Mask Parameter: DiscretePIDController1_P_f
   * Referenced by: '<S291>/Proportional Gain'
   */
  325.0,

  /* Mask Parameter: DiscretePIDController1_P_fb
   * Referenced by: '<S233>/Proportional Gain'
   */
  325.0,

  /* Mask Parameter: DiscretePIDController1_P_o
   * Referenced by: '<S175>/Proportional Gain'
   */
  325.0,

  /* Mask Parameter: DiscretePIDController1_P_e
   * Referenced by: '<S117>/Proportional Gain'
   */
  325.0,

  /* Mask Parameter: DiscretePIDController1_P_a
   * Referenced by: '<S59>/Proportional Gain'
   */
  325.0,

  /* Expression: 10
   * Referenced by: '<Root>/Constant2'
   */
  10.0,

  /* Expression: 0.03
   * Referenced by: '<Root>/Gain18'
   */
  0.03,

  /* Expression: 10
   * Referenced by: '<Root>/Gain19'
   */
  10.0,

  /* Expression: 0.001
   * Referenced by: '<Root>/Gain15'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: 0.001
   * Referenced by: '<Root>/Gain14'
   */
  0.001,

  /* Expression: 278.7
   * Referenced by: '<Root>/Constant6'
   */
  278.7,

  /* Expression: 20
   * Referenced by: '<Root>/Constant8'
   */
  20.0,

  /* Expression: 10
   * Referenced by: '<Root>/Constant7'
   */
  10.0,

  /* Expression: 0.03
   * Referenced by: '<Root>/Gain16'
   */
  0.03,

  /* Expression: 10
   * Referenced by: '<Root>/Gain17'
   */
  10.0,

  /* Expression: 0.001
   * Referenced by: '<Root>/Gain21'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/Constant3'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<Root>/Gain12'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<Root>/Constant4'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<Root>/Gain13'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<Root>/Constant5'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<Root>/Gain20'
   */
  0.017453292519943295,

  /* Expression: 1000
   * Referenced by: '<Root>/Gain3'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S4>/Unit Delay'
   */
  0.0,

  /* Expression: 0.13575
   * Referenced by: '<S4>/Gain2'
   */
  0.13575,

  /* Expression: 0.13575
   * Referenced by: '<S4>/Gain1'
   */
  0.13575,

  /* Expression: 0
   * Referenced by: '<S4>/Unit Delay1'
   */
  0.0,

  /* Expression: 0.72848
   * Referenced by: '<S4>/Gain3'
   */
  0.72848,

  /* Expression: 100/1024
   * Referenced by: '<S4>/Gain'
   */
  0.09765625,

  /* Expression: 1000
   * Referenced by: '<Root>/Gain4'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S5>/Unit Delay'
   */
  0.0,

  /* Expression: 0.13575
   * Referenced by: '<S5>/Gain2'
   */
  0.13575,

  /* Expression: 0.13575
   * Referenced by: '<S5>/Gain1'
   */
  0.13575,

  /* Expression: 0
   * Referenced by: '<S5>/Unit Delay1'
   */
  0.0,

  /* Expression: 0.72848
   * Referenced by: '<S5>/Gain3'
   */
  0.72848,

  /* Expression: 100/1024
   * Referenced by: '<S5>/Gain'
   */
  0.09765625,

  /* Expression: 1000
   * Referenced by: '<Root>/Gain5'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S6>/Unit Delay'
   */
  0.0,

  /* Expression: 0.13575
   * Referenced by: '<S6>/Gain2'
   */
  0.13575,

  /* Expression: 0.13575
   * Referenced by: '<S6>/Gain1'
   */
  0.13575,

  /* Expression: 0
   * Referenced by: '<S6>/Unit Delay1'
   */
  0.0,

  /* Expression: 0.72848
   * Referenced by: '<S6>/Gain3'
   */
  0.72848,

  /* Expression: 100/1024
   * Referenced by: '<S6>/Gain'
   */
  0.09765625,

  /* Expression: 1000
   * Referenced by: '<Root>/Gain6'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay'
   */
  0.0,

  /* Expression: 0.13575
   * Referenced by: '<S7>/Gain2'
   */
  0.13575,

  /* Expression: 0.13575
   * Referenced by: '<S7>/Gain1'
   */
  0.13575,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay1'
   */
  0.0,

  /* Expression: 0.72848
   * Referenced by: '<S7>/Gain3'
   */
  0.72848,

  /* Expression: 100/1024
   * Referenced by: '<S7>/Gain'
   */
  0.09765625,

  /* Expression: 1000
   * Referenced by: '<Root>/Gain7'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S8>/Unit Delay'
   */
  0.0,

  /* Expression: 0.13575
   * Referenced by: '<S8>/Gain2'
   */
  0.13575,

  /* Expression: 0.13575
   * Referenced by: '<S8>/Gain1'
   */
  0.13575,

  /* Expression: 0
   * Referenced by: '<S8>/Unit Delay1'
   */
  0.0,

  /* Expression: 0.72848
   * Referenced by: '<S8>/Gain3'
   */
  0.72848,

  /* Expression: 100/1024
   * Referenced by: '<S8>/Gain'
   */
  0.09765625,

  /* Expression: 1000
   * Referenced by: '<Root>/Gain8'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S9>/Unit Delay'
   */
  0.0,

  /* Expression: 0.13575
   * Referenced by: '<S9>/Gain2'
   */
  0.13575,

  /* Expression: 0.13575
   * Referenced by: '<S9>/Gain1'
   */
  0.13575,

  /* Expression: 0
   * Referenced by: '<S9>/Unit Delay1'
   */
  0.0,

  /* Expression: 0.72848
   * Referenced by: '<S9>/Gain3'
   */
  0.72848,

  /* Expression: 100/1024
   * Referenced by: '<S9>/Gain'
   */
  0.09765625,

  /* Expression: 255
   * Referenced by: '<S9>/Constant'
   */
  255.0,

  /* Computed Parameter: Tsamp_WtEt
   * Referenced by: '<S339>/Tsamp'
   */
  100.0,

  /* Expression: 200
   * Referenced by: '<S9>/Saturation1'
   */
  200.0,

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
  0.45,

  /* Expression: 255
   * Referenced by: '<S8>/Constant'
   */
  255.0,

  /* Computed Parameter: Tsamp_WtEt_a
   * Referenced by: '<S281>/Tsamp'
   */
  100.0,

  /* Expression: 200
   * Referenced by: '<S8>/Saturation1'
   */
  200.0,

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

  /* Computed Parameter: Tsamp_WtEt_o
   * Referenced by: '<S223>/Tsamp'
   */
  100.0,

  /* Expression: 200
   * Referenced by: '<S7>/Saturation1'
   */
  200.0,

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

  /* Computed Parameter: Tsamp_WtEt_d
   * Referenced by: '<S165>/Tsamp'
   */
  100.0,

  /* Expression: 200
   * Referenced by: '<S6>/Saturation1'
   */
  200.0,

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

  /* Computed Parameter: Tsamp_WtEt_b
   * Referenced by: '<S107>/Tsamp'
   */
  100.0,

  /* Expression: 200
   * Referenced by: '<S5>/Saturation1'
   */
  200.0,

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
   * Referenced by: '<S4>/Constant'
   */
  255.0,

  /* Computed Parameter: Tsamp_WtEt_i
   * Referenced by: '<S49>/Tsamp'
   */
  100.0,

  /* Expression: 200
   * Referenced by: '<S4>/Saturation1'
   */
  200.0,

  /* Expression: 0
   * Referenced by: '<S4>/Saturation1'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S4>/Switch'
   */
  5.0,

  /* Expression: 0.45
   * Referenced by: '<S4>/Gain4'
   */
  0.45,

  /* Computed Parameter: LookUpTable_tableData
   * Referenced by: '<S10>/Look-Up Table'
   */
  { 0, 804, 1606, 2404, 3196, 3981, 4756, 5520, 6270, 7005, 7723, 8423, 9102,
    9760, 10394, 11003, 11585, 12140, 12665, 13160, 13623, 14053, 14449, 14811,
    15137, 15426, 15679, 15893, 16069, 16207, 16305, 16364, 16384 },

  /* Computed Parameter: LookUpTable_tableData_i
   * Referenced by: '<S12>/Look-Up Table'
   */
  { 0, 804, 1606, 2404, 3196, 3981, 4756, 5520, 6270, 7005, 7723, 8423, 9102,
    9760, 10394, 11003, 11585, 12140, 12665, 13160, 13623, 14053, 14449, 14811,
    15137, 15426, 15679, 15893, 16069, 16207, 16305, 16364, 16384 },

  /* Computed Parameter: Point25_Value
   * Referenced by: '<S11>/Point25'
   */
  16384U,

  /* Computed Parameter: Point50_Value
   * Referenced by: '<S11>/Point50'
   */
  32768U,

  /* Computed Parameter: Point75_Value
   * Referenced by: '<S11>/Point75'
   */
  49152U,

  /* Computed Parameter: LookUpTable_bp01Data
   * Referenced by: '<S10>/Look-Up Table'
   */
  { 0U, 512U, 1024U, 1536U, 2048U, 2560U, 3072U, 3584U, 4096U, 4608U, 5120U,
    5632U, 6144U, 6656U, 7168U, 7680U, 8192U, 8704U, 9216U, 9728U, 10240U,
    10752U, 11264U, 11776U, 12288U, 12800U, 13312U, 13824U, 14336U, 14848U,
    15360U, 15872U, 16384U },

  /* Computed Parameter: Point50_Value_p
   * Referenced by: '<S13>/Point50'
   */
  32768U,

  /* Computed Parameter: Point25_Value_a
   * Referenced by: '<S13>/Point25'
   */
  16384U,

  /* Computed Parameter: LookUpTable_bp01Data_l
   * Referenced by: '<S12>/Look-Up Table'
   */
  { 0U, 512U, 1024U, 1536U, 2048U, 2560U, 3072U, 3584U, 4096U, 4608U, 5120U,
    5632U, 6144U, 6656U, 7168U, 7680U, 8192U, 8704U, 9216U, 9728U, 10240U,
    10752U, 11264U, 11776U, 12288U, 12800U, 13312U, 13824U, 14336U, 14848U,
    15360U, 15872U, 16384U }
};
