/*
 * samerHARDWAREPOTread_private.h
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

#ifndef samerHARDWAREPOTread_private_h_
#define samerHARDWAREPOTread_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "samerHARDWAREPOTread.h"
#include "samerHARDWAREPOTread_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern uint32_T plook_u32u16u32n16_evenc_gf(uint16_T u, uint16_T bp0, uint16_T
  bpSpace, uint32_T maxIndex, uint32_T *fraction);
extern int16_T intrp1d_s16s32s32u32u32n16l_f(uint32_T bpIndex, uint32_T frac,
  const int16_T table[]);
extern void samerHARDWA_MATLABFunction_Init(DW_MATLABFunction_samerHARDWA_T
  *localDW);
extern void samerHARDWAREPOT_MATLABFunction(real_T rtu_u,
  B_MATLABFunction_samerHARDWAR_T *localB, DW_MATLABFunction_samerHARDWA_T
  *localDW);
extern void samerHARDW_MATLABFunction1_Init(DW_MATLABFunction1_samerHARDW_T
  *localDW);
extern void samerHARDWAREPO_MATLABFunction1(real_T rtu_u, real_T rtu_v,
  B_MATLABFunction1_samerHARDWA_T *localB, DW_MATLABFunction1_samerHARDW_T
  *localDW);

#endif                                 /* samerHARDWAREPOTread_private_h_ */
