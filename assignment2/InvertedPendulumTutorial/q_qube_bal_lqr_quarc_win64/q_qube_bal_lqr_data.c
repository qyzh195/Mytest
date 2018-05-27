/*
 * q_qube_bal_lqr_data.c
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

#include "q_qube_bal_lqr.h"
#include "q_qube_bal_lqr_private.h"

/* Block parameters (auto storage) */
P_q_qube_bal_lqr_T q_qube_bal_lqr_P = {
  /*  Variable: K
   * Referenced by: '<Root>/u = -K*x'
   */
  { -1.0000000000000142, 35.592082865779787, -1.4744179524757843,
    3.0960397873775527 },
  0.17453292519943295,                 /* Mask Parameter: EnableBalanceControl_const
                                        * Referenced by: '<S3>/Constant'
                                        */
  5.0,                                 /* Mask Parameter: StallMonitor_control_threshold
                                        * Referenced by: '<S8>/control threshold'
                                        */
  20.0,                                /* Mask Parameter: StallMonitor_duration_s
                                        * Referenced by: '<S8>/control threshold1'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_analog_outp
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.3,                                 /* Mask Parameter: StallMonitor_motion_threshold
                                        * Referenced by: '<S8>/motion threshold'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILReadEncoderTimebase_clock
                                        * Referenced by: '<Root>/HIL Read Encoder Timebase'
                                        */

  /*  Mask Parameter: HILReadEncoderTimebase_channels
   * Referenced by: '<Root>/HIL Read Encoder Timebase'
   */
  { 0U, 1U },
  0U,                                  /* Mask Parameter: HILWriteAnalog_channels
                                        * Referenced by: '<Root>/HIL Write Analog'
                                        */
  500U,                                /* Mask Parameter: HILReadEncoderTimebase_samples_
                                        * Referenced by: '<Root>/HIL Read Encoder Timebase'
                                        */
  1,                                   /* Mask Parameter: StopwithMessage_message_icon
                                        * Referenced by: '<S9>/Show Message on Host'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_output
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_outp_d
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_p
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */

  /*  Expression: [1 0 0 0]
   * Referenced by: '<Root>/Convert to Vector'
   */
  { 1.0, 0.0, 0.0, 0.0 },
  0.0030679615757712823,               /* Expression: 2*pi/512/4
                                        * Referenced by: '<S1>/Pendulum:  counts to rad'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S1>/Constant1'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S1>/Bias'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/u = 0V'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  0.125,                               /* Expression: 0.125
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S2>/Gain1'
                                        */
  -0.0030679615757712823,              /* Expression: -2*pi/512/4
                                        * Referenced by: '<S1>/Arm: counts to rad'
                                        */
  -50.0,                               /* Computed Parameter: theta_dot_A
                                        * Referenced by: '<S7>/theta_dot'
                                        */
  -2500.0,                             /* Computed Parameter: theta_dot_C
                                        * Referenced by: '<S7>/theta_dot'
                                        */
  50.0,                                /* Computed Parameter: theta_dot_D
                                        * Referenced by: '<S7>/theta_dot'
                                        */
  -50.0,                               /* Computed Parameter: alpha_dot_A
                                        * Referenced by: '<S7>/alpha_dot'
                                        */
  -2500.0,                             /* Computed Parameter: alpha_dot_C
                                        * Referenced by: '<S7>/alpha_dot'
                                        */
  50.0,                                /* Computed Parameter: alpha_dot_D
                                        * Referenced by: '<S7>/alpha_dot'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/For +ve CCW'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S4>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S5>/Gain'
                                        */
  0.002,                               /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S8>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Discrete-Time Integrator'
                                        */
  1,                                   /* Computed Parameter: HILReadEncoderTimebase_Active
                                        * Referenced by: '<Root>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<Root>/HIL Write Analog'
                                        */
  0                                    /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S10>/Constant'
                                        */
};
