/*
 * samerHARDWARE_private.h
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

#ifndef samerHARDWARE_private_h_
#define samerHARDWARE_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "samerHARDWARE.h"
#include "samerHARDWARE_types.h"

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

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void samerHARDWA_MATLABFunction_Init(DW_MATLABFunction_samerHARDWA_T
  *localDW);
extern void samerHARDWARE_MATLABFunction(real_T rtu_u,
  B_MATLABFunction_samerHARDWAR_T *localB, DW_MATLABFunction_samerHARDWA_T
  *localDW);
extern void samerHARDW_MATLABFunction1_Init(DW_MATLABFunction1_samerHARDW_T
  *localDW);
extern void samerHARDWARE_MATLABFunction1(real_T rtu_u, real_T rtu_v,
  B_MATLABFunction1_samerHARDWA_T *localB, DW_MATLABFunction1_samerHARDW_T
  *localDW);

#endif                                 /* samerHARDWARE_private_h_ */
