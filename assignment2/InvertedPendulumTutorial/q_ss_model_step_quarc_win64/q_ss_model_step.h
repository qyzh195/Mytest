/*
 * q_ss_model_step.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "q_ss_model_step".
 *
 * Model version              : 1.8
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Tue May 15 11:25:42 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_q_ss_model_step_h_
#define RTW_HEADER_q_ss_model_step_h_
#include <math.h>
#include <float.h>
#include <string.h>
#ifndef q_ss_model_step_COMMON_INCLUDES_
# define q_ss_model_step_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_extern.h"
#endif                                 /* q_ss_model_step_COMMON_INCLUDES_ */

#include "q_ss_model_step_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T AmplitudeV;                   /* '<Root>/Amplitude (V)' */
  real_T Pendulumcountstorad;          /* '<Root>/Pendulum: counts to rad' */
  real_T StateSpaceModel[2];           /* '<Root>/State-Space Model' */
  real_T RotaryArmcountstorad;         /* '<Root>/Rotary Arm: counts to rad' */
  real_T TransferFcn;                  /* '<S1>/Transfer Fcn' */
  boolean_T RelationalOperator2;       /* '<S2>/Relational Operator2' */
} B_q_ss_model_step_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S2>/Discrete-Time Integrator' */
  real_T HILInitialize_AOVoltages[2];  /* '<Root>/HIL Initialize' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  t_task HILReadEncoderTimebase_Task;  /* '<Root>/HIL Read Encoder Timebase' */
  void *HILWriteAnalog_PWORK;          /* '<Root>/HIL Write Analog' */
  struct {
    void *LoggedData;
  } PendulumAnglerad_PWORK;            /* '<Root>/Pendulum Angle (rad)' */

  struct {
    void *LoggedData;
  } RotaryArmAnglerad_PWORK;           /* '<Root>/Rotary Arm Angle (rad)' */

  int32_T HILInitialize_ClockModes;    /* '<Root>/HIL Initialize' */
  int32_T HILReadEncoderTimebase_Buffer[2];/* '<Root>/HIL Read Encoder Timebase' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S2>/Discrete-Time Integrator' */
} DW_q_ss_model_step_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T StateSpaceModel_CSTATE[4];    /* '<Root>/State-Space Model' */
  real_T TransferFcn_CSTATE;           /* '<S1>/Transfer Fcn' */
} X_q_ss_model_step_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T StateSpaceModel_CSTATE[4];    /* '<Root>/State-Space Model' */
  real_T TransferFcn_CSTATE;           /* '<S1>/Transfer Fcn' */
} XDot_q_ss_model_step_T;

/* State disabled  */
typedef struct {
  boolean_T StateSpaceModel_CSTATE[4]; /* '<Root>/State-Space Model' */
  boolean_T TransferFcn_CSTATE;        /* '<S1>/Transfer Fcn' */
} XDis_q_ss_model_step_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (auto storage) */
struct P_q_ss_model_step_T_ {
  real_T A[16];                        /* Variable: A
                                        * Referenced by: '<Root>/State-Space Model'
                                        */
  real_T B[4];                         /* Variable: B
                                        * Referenced by: '<Root>/State-Space Model'
                                        */
  real_T C[8];                         /* Variable: C
                                        * Referenced by: '<Root>/State-Space Model'
                                        */
  real_T StallMonitor_control_threshold;/* Mask Parameter: StallMonitor_control_threshold
                                         * Referenced by: '<S2>/control threshold'
                                         */
  real_T StallMonitor_duration_s;      /* Mask Parameter: StallMonitor_duration_s
                                        * Referenced by: '<S2>/control threshold1'
                                        */
  real_T HILInitialize_final_analog_outp;/* Mask Parameter: HILInitialize_final_analog_outp
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T StallMonitor_motion_threshold;/* Mask Parameter: StallMonitor_motion_threshold
                                        * Referenced by: '<S2>/motion threshold'
                                        */
  real_T HILInitialize_set_other_outputs;/* Mask Parameter: HILInitialize_set_other_outputs
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_o;/* Mask Parameter: HILInitialize_set_other_outpu_o
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  int32_T HILReadEncoderTimebase_clock;/* Mask Parameter: HILReadEncoderTimebase_clock
                                        * Referenced by: '<Root>/HIL Read Encoder Timebase'
                                        */
  uint32_T HILReadEncoderTimebase_channels[2];/* Mask Parameter: HILReadEncoderTimebase_channels
                                               * Referenced by: '<Root>/HIL Read Encoder Timebase'
                                               */
  uint32_T HILWriteAnalog_channels;    /* Mask Parameter: HILWriteAnalog_channels
                                        * Referenced by: '<Root>/HIL Write Analog'
                                        */
  uint32_T HILReadEncoderTimebase_samples_;/* Mask Parameter: HILReadEncoderTimebase_samples_
                                            * Referenced by: '<Root>/HIL Read Encoder Timebase'
                                            */
  int8_T StopwithMessage_message_icon; /* Mask Parameter: StopwithMessage_message_icon
                                        * Referenced by: '<S3>/Show Message on Host'
                                        */
  boolean_T HILInitialize_active;      /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_set_analog_output;/* Mask Parameter: HILInitialize_set_analog_output
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_e;/* Mask Parameter: HILInitialize_set_analog_outp_e
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_outpu;/* Mask Parameter: HILInitialize_set_digital_outpu
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_d;/* Mask Parameter: HILInitialize_set_digital_out_d
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_a;/* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_n;/* Mask Parameter: HILInitialize_set_pwm_outputs_n
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T SignalGenerator_Amplitude;    /* Expression: 1
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  real_T SignalGenerator_Frequency;    /* Expression: 1
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  real_T AmplitudeV_Gain;              /* Expression: 1
                                        * Referenced by: '<Root>/Amplitude (V)'
                                        */
  real_T Pendulumcountstorad_Gain;     /* Expression: -0.00307
                                        * Referenced by: '<Root>/Pendulum: counts to rad'
                                        */
  real_T StateSpaceModel_X0[4];        /* Expression: [0 0 0 0]
                                        * Referenced by: '<Root>/State-Space Model'
                                        */
  real_T RotaryArmcountstorad_Gain;    /* Expression: 0.00307
                                        * Referenced by: '<Root>/Rotary Arm: counts to rad'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
  real_T TransferFcn_D;                /* Computed Parameter: TransferFcn_D
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S2>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  boolean_T HILReadEncoderTimebase_Active;/* Computed Parameter: HILReadEncoderTimebase_Active
                                           * Referenced by: '<Root>/HIL Read Encoder Timebase'
                                           */
  boolean_T HILWriteAnalog_Active;     /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<Root>/HIL Write Analog'
                                        */
  boolean_T Constant_Value;            /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S4>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_q_ss_model_step_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_q_ss_model_step_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][5];
    ODE1_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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

/* Block parameters (auto storage) */
extern P_q_ss_model_step_T q_ss_model_step_P;

/* Block signals (auto storage) */
extern B_q_ss_model_step_T q_ss_model_step_B;

/* Continuous states (auto storage) */
extern X_q_ss_model_step_T q_ss_model_step_X;

/* Block states (auto storage) */
extern DW_q_ss_model_step_T q_ss_model_step_DW;

/* Model entry point functions */
extern void q_ss_model_step_initialize(void);
extern void q_ss_model_step_step(void);
extern void q_ss_model_step_terminate(void);

/* Real-time Model object */
extern RT_MODEL_q_ss_model_step_T *const q_ss_model_step_M;

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
 * '<Root>' : 'q_ss_model_step'
 * '<S1>'   : 'q_ss_model_step/Stall Detection'
 * '<S2>'   : 'q_ss_model_step/Stall Detection/Stall Monitor'
 * '<S3>'   : 'q_ss_model_step/Stall Detection/Stop with Message'
 * '<S4>'   : 'q_ss_model_step/Stall Detection/Stop with Message/Compare'
 */
#endif                                 /* RTW_HEADER_q_ss_model_step_h_ */
