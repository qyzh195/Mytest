/*
 * q_ss_model_step_data.c
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

#include "q_ss_model_step.h"
#include "q_ss_model_step_private.h"

/* Block parameters (auto storage) */
P_q_ss_model_step_T q_ss_model_step_P = {
  /*  Variable: A
   * Referenced by: '<Root>/State-Space Model'
   */
  { 0.0, 0.0, -0.0, -0.0, 0.0, 0.0, 149.2750968650933, -261.609107366662, 1.0,
    0.0, -4.9831962372832166, 4.9252520949892258, 0.0, 1.0, 4.914930740434313,
    -8.6135642902045166 },

  /*  Variable: B
   * Referenced by: '<Root>/State-Space Model'
   */
  { 0.0, 0.0, 49.727534550276587, -49.149307404343141 },

  /*  Variable: C
   * Referenced by: '<Root>/State-Space Model'
   */
  { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },
  5.0,                                 /* Mask Parameter: StallMonitor_control_threshold
                                        * Referenced by: '<S2>/control threshold'
                                        */
  20.0,                                /* Mask Parameter: StallMonitor_duration_s
                                        * Referenced by: '<S2>/control threshold1'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_analog_outp
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.3,                                 /* Mask Parameter: StallMonitor_motion_threshold
                                        * Referenced by: '<S2>/motion threshold'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_o
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
                                        * Referenced by: '<S3>/Show Message on Host'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_output
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_outp_e
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_d
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_n
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Amplitude (V)'
                                        */
  -0.00307,                            /* Expression: -0.00307
                                        * Referenced by: '<Root>/Pendulum: counts to rad'
                                        */

  /*  Expression: [0 0 0 0]
   * Referenced by: '<Root>/State-Space Model'
   */
  { 0.0, 0.0, 0.0, 0.0 },
  0.00307,                             /* Expression: 0.00307
                                        * Referenced by: '<Root>/Rotary Arm: counts to rad'
                                        */
  -50.0,                               /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
  -2500.0,                             /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
  50.0,                                /* Computed Parameter: TransferFcn_D
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
  0.002,                               /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  1,                                   /* Computed Parameter: HILReadEncoderTimebase_Active
                                        * Referenced by: '<Root>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<Root>/HIL Write Analog'
                                        */
  0                                    /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S4>/Constant'
                                        */
};
