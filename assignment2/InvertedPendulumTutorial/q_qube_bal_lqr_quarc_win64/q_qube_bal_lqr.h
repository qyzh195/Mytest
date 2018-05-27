/*
 * q_qube_bal_lqr.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "q_qube_bal_lqr".
 *
 * Model version              : 1.453
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Tue May 15 12:17:07 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_q_qube_bal_lqr_h_
#define RTW_HEADER_q_qube_bal_lqr_h_
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef q_qube_bal_lqr_COMMON_INCLUDES_
# define q_qube_bal_lqr_COMMON_INCLUDES_
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
#endif                                 /* q_qube_bal_lqr_COMMON_INCLUDES_ */

#include "q_qube_bal_lqr_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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
  real_T HILReadEncoderTimebase_o1;    /* '<Root>/HIL Read Encoder Timebase' */
  real_T HILReadEncoderTimebase_o2;    /* '<Root>/HIL Read Encoder Timebase' */
  real_T Pendulumcountstorad;          /* '<S1>/Pendulum:  counts to rad' */
  real_T MathFunction;                 /* '<S1>/Math Function' */
  real_T Bias;                         /* '<S1>/Bias' */
  real_T alpha;                        /* '<Root>/|alpha|' */
  real_T SignalGenerator;              /* '<Root>/Signal Generator' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Gain1;                        /* '<S2>/Gain1' */
  real_T Armcountstorad;               /* '<S1>/Arm: counts to rad' */
  real_T theta_dot;                    /* '<S7>/theta_dot' */
  real_T alpha_dot;                    /* '<S7>/alpha_dot' */
  real_T EnableBalanceControlSwitch;   /* '<Root>/Enable Balance Control Switch' */
  real_T ForveCCW;                     /* '<Root>/For +ve CCW' */
  real_T Gain_i;                       /* '<S4>/Gain' */
  real_T Gain_b[2];                    /* '<S5>/Gain' */
  real_T Abs;                          /* '<S8>/Abs' */
  real_T Abs1;                         /* '<S8>/Abs1' */
  real_T DiscreteTimeIntegrator;       /* '<S8>/Discrete-Time Integrator' */
  real_T DataTypeConversion;           /* '<S8>/Data Type Conversion' */
  real_T ConverttoVector[4];           /* '<Root>/Convert to Vector' */
  real_T Sum[4];                       /* '<Root>/Sum' */
  real_T uKx;                          /* '<Root>/u = -K*x' */
  uint8_T Compare;                     /* '<S3>/Compare' */
  boolean_T RelationalOperator1;       /* '<S8>/Relational Operator1' */
  boolean_T RelationalOperator;        /* '<S8>/Relational Operator' */
  boolean_T LogicalOperator;           /* '<S8>/Logical Operator' */
  boolean_T LogicalOperator1;          /* '<S8>/Logical Operator1' */
  boolean_T RelationalOperator2;       /* '<S8>/Relational Operator2' */
  boolean_T Compare_j;                 /* '<S10>/Compare' */
} B_q_qube_bal_lqr_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S8>/Discrete-Time Integrator' */
  real_T HILInitialize_AOVoltages[2];  /* '<Root>/HIL Initialize' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  t_task HILReadEncoderTimebase_Task;  /* '<Root>/HIL Read Encoder Timebase' */
  void *HILWriteAnalog_PWORK;          /* '<Root>/HIL Write Analog' */
  struct {
    void *LoggedData;
  } MotorVoltageV_PWORK;               /* '<Root>/Motor Voltage (V)' */

  struct {
    void *LoggedData;
  } Pendulumdeg_PWORK;                 /* '<Root>/Pendulum (deg)' */

  struct {
    void *LoggedData;
  } RotaryArmdeg_PWORK;                /* '<Root>/Rotary Arm (deg)' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<Root>/To Workspace2' */

  int32_T HILInitialize_ClockModes;    /* '<Root>/HIL Initialize' */
  int32_T HILReadEncoderTimebase_Buffer[2];/* '<Root>/HIL Read Encoder Timebase' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S8>/Discrete-Time Integrator' */
} DW_q_qube_bal_lqr_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T theta_dot_CSTATE;             /* '<S7>/theta_dot' */
  real_T alpha_dot_CSTATE;             /* '<S7>/alpha_dot' */
} X_q_qube_bal_lqr_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T theta_dot_CSTATE;             /* '<S7>/theta_dot' */
  real_T alpha_dot_CSTATE;             /* '<S7>/alpha_dot' */
} XDot_q_qube_bal_lqr_T;

/* State disabled  */
typedef struct {
  boolean_T theta_dot_CSTATE;          /* '<S7>/theta_dot' */
  boolean_T alpha_dot_CSTATE;          /* '<S7>/alpha_dot' */
} XDis_q_qube_bal_lqr_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (auto storage) */
struct P_q_qube_bal_lqr_T_ {
  real_T K[4];                         /* Variable: K
                                        * Referenced by: '<Root>/u = -K*x'
                                        */
  real_T EnableBalanceControl_const;   /* Mask Parameter: EnableBalanceControl_const
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T StallMonitor_control_threshold;/* Mask Parameter: StallMonitor_control_threshold
                                         * Referenced by: '<S8>/control threshold'
                                         */
  real_T StallMonitor_duration_s;      /* Mask Parameter: StallMonitor_duration_s
                                        * Referenced by: '<S8>/control threshold1'
                                        */
  real_T HILInitialize_final_analog_outp;/* Mask Parameter: HILInitialize_final_analog_outp
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T StallMonitor_motion_threshold;/* Mask Parameter: StallMonitor_motion_threshold
                                        * Referenced by: '<S8>/motion threshold'
                                        */
  real_T HILInitialize_set_other_outputs;/* Mask Parameter: HILInitialize_set_other_outputs
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_k;/* Mask Parameter: HILInitialize_set_other_outpu_k
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
                                        * Referenced by: '<S9>/Show Message on Host'
                                        */
  boolean_T HILInitialize_active;      /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_set_analog_output;/* Mask Parameter: HILInitialize_set_analog_output
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_d;/* Mask Parameter: HILInitialize_set_analog_outp_d
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_outpu;/* Mask Parameter: HILInitialize_set_digital_outpu
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_p;/* Mask Parameter: HILInitialize_set_digital_out_p
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_a;/* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_c;/* Mask Parameter: HILInitialize_set_pwm_outputs_c
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T ConverttoVector_Gain[4];      /* Expression: [1 0 0 0]
                                        * Referenced by: '<Root>/Convert to Vector'
                                        */
  real_T Pendulumcountstorad_Gain;     /* Expression: 2*pi/512/4
                                        * Referenced by: '<S1>/Pendulum:  counts to rad'
                                        */
  real_T Constant1_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Bias_Bias;                    /* Expression: -pi
                                        * Referenced by: '<S1>/Bias'
                                        */
  real_T u0V_Value;                    /* Expression: 0
                                        * Referenced by: '<Root>/u = 0V'
                                        */
  real_T SignalGenerator_Amplitude;    /* Expression: 1
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  real_T SignalGenerator_Frequency;    /* Expression: 0.125
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  real_T Gain_Gain;                    /* Expression: 30
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Armcountstorad_Gain;          /* Expression: -2*pi/512/4
                                        * Referenced by: '<S1>/Arm: counts to rad'
                                        */
  real_T theta_dot_A;                  /* Computed Parameter: theta_dot_A
                                        * Referenced by: '<S7>/theta_dot'
                                        */
  real_T theta_dot_C;                  /* Computed Parameter: theta_dot_C
                                        * Referenced by: '<S7>/theta_dot'
                                        */
  real_T theta_dot_D;                  /* Computed Parameter: theta_dot_D
                                        * Referenced by: '<S7>/theta_dot'
                                        */
  real_T alpha_dot_A;                  /* Computed Parameter: alpha_dot_A
                                        * Referenced by: '<S7>/alpha_dot'
                                        */
  real_T alpha_dot_C;                  /* Computed Parameter: alpha_dot_C
                                        * Referenced by: '<S7>/alpha_dot'
                                        */
  real_T alpha_dot_D;                  /* Computed Parameter: alpha_dot_D
                                        * Referenced by: '<S7>/alpha_dot'
                                        */
  real_T ForveCCW_Gain;                /* Expression: -1
                                        * Referenced by: '<Root>/For +ve CCW'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 180/pi
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Gain_Gain_ae;                 /* Expression: 180/pi
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S8>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S8>/Discrete-Time Integrator'
                                        */
  boolean_T HILReadEncoderTimebase_Active;/* Computed Parameter: HILReadEncoderTimebase_Active
                                           * Referenced by: '<Root>/HIL Read Encoder Timebase'
                                           */
  boolean_T HILWriteAnalog_Active;     /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<Root>/HIL Write Analog'
                                        */
  boolean_T Constant_Value;            /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S10>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_q_qube_bal_lqr_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_q_qube_bal_lqr_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][2];
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
extern P_q_qube_bal_lqr_T q_qube_bal_lqr_P;

/* Block signals (auto storage) */
extern B_q_qube_bal_lqr_T q_qube_bal_lqr_B;

/* Continuous states (auto storage) */
extern X_q_qube_bal_lqr_T q_qube_bal_lqr_X;

/* Block states (auto storage) */
extern DW_q_qube_bal_lqr_T q_qube_bal_lqr_DW;

/* Model entry point functions */
extern void q_qube_bal_lqr_initialize(void);
extern void q_qube_bal_lqr_step(void);
extern void q_qube_bal_lqr_terminate(void);

/* Real-time Model object */
extern RT_MODEL_q_qube_bal_lqr_T *const q_qube_bal_lqr_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S6>/Rate Transition1' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'q_qube_bal_lqr'
 * '<S1>'   : 'q_qube_bal_lqr/Counts to Angles'
 * '<S2>'   : 'q_qube_bal_lqr/Degrees to Radians'
 * '<S3>'   : 'q_qube_bal_lqr/Enable Balance Control'
 * '<S4>'   : 'q_qube_bal_lqr/Radians to Degrees'
 * '<S5>'   : 'q_qube_bal_lqr/Radians to Degrees1'
 * '<S6>'   : 'q_qube_bal_lqr/Stall Detection'
 * '<S7>'   : 'q_qube_bal_lqr/State X'
 * '<S8>'   : 'q_qube_bal_lqr/Stall Detection/Stall Monitor'
 * '<S9>'   : 'q_qube_bal_lqr/Stall Detection/Stop with Message'
 * '<S10>'  : 'q_qube_bal_lqr/Stall Detection/Stop with Message/Compare'
 */
#endif                                 /* RTW_HEADER_q_qube_bal_lqr_h_ */
