/*
 * q_ss_model_step.c
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
#include "q_ss_model_step_dt.h"

/* Block signals (auto storage) */
B_q_ss_model_step_T q_ss_model_step_B;

/* Continuous states */
X_q_ss_model_step_T q_ss_model_step_X;

/* Block states (auto storage) */
DW_q_ss_model_step_T q_ss_model_step_DW;

/* Real-time model */
RT_MODEL_q_ss_model_step_T q_ss_model_step_M_;
RT_MODEL_q_ss_model_step_T *const q_ss_model_step_M = &q_ss_model_step_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  q_ss_model_step_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void q_ss_model_step_step(void)
{
  /* local block i/o variables */
  real_T rtb_DataTypeConversion;
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_DiscreteTimeIntegrator;
  boolean_T rtb_LogicalOperator1;
  real_T temp;
  int_T iy;
  boolean_T rtb_RelationalOperator1;
  if (rtmIsMajorTimeStep(q_ss_model_step_M)) {
    /* set solver stop time */
    if (!(q_ss_model_step_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&q_ss_model_step_M->solverInfo,
                            ((q_ss_model_step_M->Timing.clockTickH0 + 1) *
        q_ss_model_step_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&q_ss_model_step_M->solverInfo,
                            ((q_ss_model_step_M->Timing.clockTick0 + 1) *
        q_ss_model_step_M->Timing.stepSize0 +
        q_ss_model_step_M->Timing.clockTickH0 *
        q_ss_model_step_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(q_ss_model_step_M)) {
    q_ss_model_step_M->Timing.t[0] = rtsiGetT(&q_ss_model_step_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(q_ss_model_step_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

    /* S-Function Block: q_ss_model_step/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (q_ss_model_step_DW.HILReadEncoderTimebase_Task, 1,
         &q_ss_model_step_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_ss_model_step_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          q_ss_model_step_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_DiscreteTimeIntegrator =
          q_ss_model_step_DW.HILReadEncoderTimebase_Buffer[1];
      }
    }
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  temp = q_ss_model_step_P.SignalGenerator_Frequency *
    q_ss_model_step_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    temp = q_ss_model_step_P.SignalGenerator_Amplitude;
  } else {
    temp = -q_ss_model_step_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Gain: '<Root>/Amplitude (V)' */
  q_ss_model_step_B.AmplitudeV = q_ss_model_step_P.AmplitudeV_Gain * temp;
  if (rtmIsMajorTimeStep(q_ss_model_step_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: q_ss_model_step/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(q_ss_model_step_DW.HILInitialize_Card,
        &q_ss_model_step_P.HILWriteAnalog_channels, 1,
        &q_ss_model_step_B.AmplitudeV);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_ss_model_step_M, _rt_error_message);
      }
    }

    /* Gain: '<Root>/Pendulum: counts to rad' */
    q_ss_model_step_B.Pendulumcountstorad =
      q_ss_model_step_P.Pendulumcountstorad_Gain * rtb_DiscreteTimeIntegrator;
  }

  /* StateSpace: '<Root>/State-Space Model' */
  for (iy = 0; iy < 2; iy++) {
    q_ss_model_step_B.StateSpaceModel[iy] = 0.0;
    q_ss_model_step_B.StateSpaceModel[iy] += q_ss_model_step_P.C[iy] *
      q_ss_model_step_X.StateSpaceModel_CSTATE[0];
    q_ss_model_step_B.StateSpaceModel[iy] += q_ss_model_step_P.C[2 + iy] *
      q_ss_model_step_X.StateSpaceModel_CSTATE[1];
    q_ss_model_step_B.StateSpaceModel[iy] += q_ss_model_step_P.C[4 + iy] *
      q_ss_model_step_X.StateSpaceModel_CSTATE[2];
    q_ss_model_step_B.StateSpaceModel[iy] += q_ss_model_step_P.C[6 + iy] *
      q_ss_model_step_X.StateSpaceModel_CSTATE[3];
  }

  /* End of StateSpace: '<Root>/State-Space Model' */
  if (rtmIsMajorTimeStep(q_ss_model_step_M)) {
    /* Gain: '<Root>/Rotary Arm: counts to rad' */
    q_ss_model_step_B.RotaryArmcountstorad =
      q_ss_model_step_P.RotaryArmcountstorad_Gain *
      rtb_HILReadEncoderTimebase_o1;

    /* Abs: '<S2>/Abs' */
    rtb_DiscreteTimeIntegrator = fabs(q_ss_model_step_B.AmplitudeV);

    /* RelationalOperator: '<S2>/Relational Operator1' incorporates:
     *  Constant: '<S2>/control threshold'
     */
    rtb_RelationalOperator1 = (rtb_DiscreteTimeIntegrator >=
      q_ss_model_step_P.StallMonitor_control_threshold);
  }

  /* TransferFcn: '<S1>/Transfer Fcn' */
  q_ss_model_step_B.TransferFcn = 0.0;
  q_ss_model_step_B.TransferFcn += q_ss_model_step_P.TransferFcn_C *
    q_ss_model_step_X.TransferFcn_CSTATE;
  q_ss_model_step_B.TransferFcn += q_ss_model_step_P.TransferFcn_D *
    q_ss_model_step_B.RotaryArmcountstorad;
  if (rtmIsMajorTimeStep(q_ss_model_step_M)) {
    /* Abs: '<S2>/Abs1' */
    rtb_DiscreteTimeIntegrator = fabs(q_ss_model_step_B.TransferFcn);

    /* Logic: '<S2>/Logical Operator' incorporates:
     *  Constant: '<S2>/motion threshold'
     *  RelationalOperator: '<S2>/Relational Operator'
     */
    rtb_RelationalOperator1 = (rtb_RelationalOperator1 &&
      (rtb_DiscreteTimeIntegrator <=
       q_ss_model_step_P.StallMonitor_motion_threshold));

    /* Logic: '<S2>/Logical Operator1' */
    rtb_LogicalOperator1 = !rtb_RelationalOperator1;

    /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    if (rtb_LogicalOperator1 &&
        (q_ss_model_step_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      q_ss_model_step_DW.DiscreteTimeIntegrator_DSTATE =
        q_ss_model_step_P.DiscreteTimeIntegrator_IC;
    }

    rtb_DiscreteTimeIntegrator =
      q_ss_model_step_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */

    /* RelationalOperator: '<S2>/Relational Operator2' incorporates:
     *  Constant: '<S2>/control threshold1'
     */
    q_ss_model_step_B.RelationalOperator2 = (rtb_DiscreteTimeIntegrator >=
      q_ss_model_step_P.StallMonitor_duration_s);

    /* Stop: '<S3>/Stop Simulation' incorporates:
     *  Constant: '<S4>/Constant'
     *  RelationalOperator: '<S4>/Compare'
     */
    if (q_ss_model_step_B.RelationalOperator2 !=
        q_ss_model_step_P.Constant_Value) {
      rtmSetStopRequested(q_ss_model_step_M, 1);
    }

    /* End of Stop: '<S3>/Stop Simulation' */

    /* DataTypeConversion: '<S2>/Data Type Conversion' */
    rtb_DataTypeConversion = rtb_RelationalOperator1;
  }

  if (rtmIsMajorTimeStep(q_ss_model_step_M)) {
    if (rtmIsMajorTimeStep(q_ss_model_step_M)) {
      /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
      q_ss_model_step_DW.DiscreteTimeIntegrator_DSTATE +=
        q_ss_model_step_P.DiscreteTimeIntegrator_gainval *
        rtb_DataTypeConversion;
      q_ss_model_step_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
        rtb_LogicalOperator1;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, q_ss_model_step_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(q_ss_model_step_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((q_ss_model_step_M->Timing.clockTick1+
                            q_ss_model_step_M->Timing.clockTickH1* 4294967296.0))
                          * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(q_ss_model_step_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(q_ss_model_step_M)!=-1) &&
          !((rtmGetTFinal(q_ss_model_step_M)-
             (((q_ss_model_step_M->Timing.clockTick1+
                q_ss_model_step_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((q_ss_model_step_M->Timing.clockTick1+
               q_ss_model_step_M->Timing.clockTickH1* 4294967296.0)) * 0.002) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(q_ss_model_step_M, "Simulation finished");
      }

      if (rtmGetStopRequested(q_ss_model_step_M)) {
        rtmSetErrorStatus(q_ss_model_step_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&q_ss_model_step_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++q_ss_model_step_M->Timing.clockTick0)) {
      ++q_ss_model_step_M->Timing.clockTickH0;
    }

    q_ss_model_step_M->Timing.t[0] = rtsiGetSolverStopTime
      (&q_ss_model_step_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.002s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.002, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      q_ss_model_step_M->Timing.clockTick1++;
      if (!q_ss_model_step_M->Timing.clockTick1) {
        q_ss_model_step_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void q_ss_model_step_derivatives(void)
{
  int_T is;
  XDot_q_ss_model_step_T *_rtXdot;
  _rtXdot = ((XDot_q_ss_model_step_T *) q_ss_model_step_M->ModelData.derivs);

  /* Derivatives for StateSpace: '<Root>/State-Space Model' */
  for (is = 0; is < 4; is++) {
    _rtXdot->StateSpaceModel_CSTATE[is] = 0.0;
    _rtXdot->StateSpaceModel_CSTATE[is] += q_ss_model_step_P.A[is] *
      q_ss_model_step_X.StateSpaceModel_CSTATE[0];
    _rtXdot->StateSpaceModel_CSTATE[is] += q_ss_model_step_P.A[4 + is] *
      q_ss_model_step_X.StateSpaceModel_CSTATE[1];
    _rtXdot->StateSpaceModel_CSTATE[is] += q_ss_model_step_P.A[8 + is] *
      q_ss_model_step_X.StateSpaceModel_CSTATE[2];
    _rtXdot->StateSpaceModel_CSTATE[is] += q_ss_model_step_P.A[12 + is] *
      q_ss_model_step_X.StateSpaceModel_CSTATE[3];
  }

  _rtXdot->StateSpaceModel_CSTATE[0] += q_ss_model_step_P.B[0] *
    q_ss_model_step_B.AmplitudeV;
  _rtXdot->StateSpaceModel_CSTATE[1] += q_ss_model_step_P.B[1] *
    q_ss_model_step_B.AmplitudeV;
  _rtXdot->StateSpaceModel_CSTATE[2] += q_ss_model_step_P.B[2] *
    q_ss_model_step_B.AmplitudeV;
  _rtXdot->StateSpaceModel_CSTATE[3] += q_ss_model_step_P.B[3] *
    q_ss_model_step_B.AmplitudeV;

  /* End of Derivatives for StateSpace: '<Root>/State-Space Model' */

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += q_ss_model_step_P.TransferFcn_A *
    q_ss_model_step_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += q_ss_model_step_B.RotaryArmcountstorad;
}

/* Model initialize function */
void q_ss_model_step_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)q_ss_model_step_M, 0,
                sizeof(RT_MODEL_q_ss_model_step_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&q_ss_model_step_M->solverInfo,
                          &q_ss_model_step_M->Timing.simTimeStep);
    rtsiSetTPtr(&q_ss_model_step_M->solverInfo, &rtmGetTPtr(q_ss_model_step_M));
    rtsiSetStepSizePtr(&q_ss_model_step_M->solverInfo,
                       &q_ss_model_step_M->Timing.stepSize0);
    rtsiSetdXPtr(&q_ss_model_step_M->solverInfo,
                 &q_ss_model_step_M->ModelData.derivs);
    rtsiSetContStatesPtr(&q_ss_model_step_M->solverInfo, (real_T **)
                         &q_ss_model_step_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&q_ss_model_step_M->solverInfo,
      &q_ss_model_step_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&q_ss_model_step_M->solverInfo,
      &q_ss_model_step_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&q_ss_model_step_M->solverInfo,
      &q_ss_model_step_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&q_ss_model_step_M->solverInfo,
      &q_ss_model_step_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&q_ss_model_step_M->solverInfo, (&rtmGetErrorStatus
      (q_ss_model_step_M)));
    rtsiSetRTModelPtr(&q_ss_model_step_M->solverInfo, q_ss_model_step_M);
  }

  rtsiSetSimTimeStep(&q_ss_model_step_M->solverInfo, MAJOR_TIME_STEP);
  q_ss_model_step_M->ModelData.intgData.f[0] = q_ss_model_step_M->
    ModelData.odeF[0];
  q_ss_model_step_M->ModelData.contStates = ((X_q_ss_model_step_T *)
    &q_ss_model_step_X);
  rtsiSetSolverData(&q_ss_model_step_M->solverInfo, (void *)
                    &q_ss_model_step_M->ModelData.intgData);
  rtsiSetSolverName(&q_ss_model_step_M->solverInfo,"ode1");
  rtmSetTPtr(q_ss_model_step_M, &q_ss_model_step_M->Timing.tArray[0]);
  rtmSetTFinal(q_ss_model_step_M, 10.0);
  q_ss_model_step_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  q_ss_model_step_M->Sizes.checksums[0] = (2656204316U);
  q_ss_model_step_M->Sizes.checksums[1] = (1674601428U);
  q_ss_model_step_M->Sizes.checksums[2] = (393453125U);
  q_ss_model_step_M->Sizes.checksums[3] = (722645006U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    q_ss_model_step_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(q_ss_model_step_M->extModeInfo,
      &q_ss_model_step_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(q_ss_model_step_M->extModeInfo,
                        q_ss_model_step_M->Sizes.checksums);
    rteiSetTPtr(q_ss_model_step_M->extModeInfo, rtmGetTPtr(q_ss_model_step_M));
  }

  /* block I/O */
  (void) memset(((void *) &q_ss_model_step_B), 0,
                sizeof(B_q_ss_model_step_T));

  /* states (continuous) */
  {
    (void) memset((void *)&q_ss_model_step_X, 0,
                  sizeof(X_q_ss_model_step_T));
  }

  /* states (dwork) */
  (void) memset((void *)&q_ss_model_step_DW, 0,
                sizeof(DW_q_ss_model_step_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    q_ss_model_step_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: q_ss_model_step/HIL Initialize (hil_initialize_block) */
  {
    static const t_uint analog_output_channels[2U] = {
      0
      , 1
    };

    static const t_double analog_output_minimums[2U] = {
      -10.0
      , -10.0
    };

    static const t_double analog_output_maximums[2U] = {
      10.0
      , 10.0
    };

    static const t_double initial_analog_outputs[2U] = {
      0.0
      , 0.0
    };

    static const t_uint encoder_input_channels[2U] = {
      0
      , 1
    };

    static const t_encoder_quadrature_mode encoder_quadrature[2U] = {
      ENCODER_QUADRATURE_4X
      , ENCODER_QUADRATURE_4X
    };

    static const t_int32 initial_encoder_counts[2U] = {
      0
      , 0
    };

    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo_usb", "0",
                      &q_ss_model_step_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_ss_model_step_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(q_ss_model_step_DW.HILInitialize_Card,
      "d0=pwm;d1=pwm;led=auto;update_rate=normal;decimation=1", 55);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_ss_model_step_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(q_ss_model_step_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_ss_model_step_M, _rt_error_message);
      return;
    }

    if (!is_switching) {
      result = hil_set_analog_output_ranges
        (q_ss_model_step_DW.HILInitialize_Card, analog_output_channels, 2U,
         analog_output_minimums, analog_output_maximums);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_ss_model_step_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_write_analog(q_ss_model_step_DW.HILInitialize_Card,
        analog_output_channels, 2U, initial_analog_outputs);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_ss_model_step_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_quadrature_mode
        (q_ss_model_step_DW.HILInitialize_Card, encoder_input_channels, 2U,
         (t_encoder_quadrature_mode *) encoder_quadrature);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_ss_model_step_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_counts(q_ss_model_step_DW.HILInitialize_Card,
        encoder_input_channels, 2U, initial_encoder_counts);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_ss_model_step_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: q_ss_model_step/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (q_ss_model_step_DW.HILInitialize_Card,
       q_ss_model_step_P.HILReadEncoderTimebase_samples_,
       q_ss_model_step_P.HILReadEncoderTimebase_channels, 2,
       &q_ss_model_step_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_ss_model_step_M, _rt_error_message);
    }
  }

  /* InitializeConditions for StateSpace: '<Root>/State-Space Model' */
  q_ss_model_step_X.StateSpaceModel_CSTATE[0] =
    q_ss_model_step_P.StateSpaceModel_X0[0];
  q_ss_model_step_X.StateSpaceModel_CSTATE[1] =
    q_ss_model_step_P.StateSpaceModel_X0[1];
  q_ss_model_step_X.StateSpaceModel_CSTATE[2] =
    q_ss_model_step_P.StateSpaceModel_X0[2];
  q_ss_model_step_X.StateSpaceModel_CSTATE[3] =
    q_ss_model_step_P.StateSpaceModel_X0[3];

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn' */
  q_ss_model_step_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  q_ss_model_step_DW.DiscreteTimeIntegrator_DSTATE =
    q_ss_model_step_P.DiscreteTimeIntegrator_IC;
  q_ss_model_step_DW.DiscreteTimeIntegrator_PrevRese = 2;
}

/* Model terminate function */
void q_ss_model_step_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: q_ss_model_step/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    static const t_uint analog_output_channels[2U] = {
      0
      , 1
    };

    hil_task_stop_all(q_ss_model_step_DW.HILInitialize_Card);
    hil_monitor_stop_all(q_ss_model_step_DW.HILInitialize_Card);
    is_switching = false;
    if ((q_ss_model_step_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (q_ss_model_step_P.HILInitialize_set_analog_output && is_switching)) {
      q_ss_model_step_DW.HILInitialize_AOVoltages[0] =
        q_ss_model_step_P.HILInitialize_final_analog_outp;
      q_ss_model_step_DW.HILInitialize_AOVoltages[1] =
        q_ss_model_step_P.HILInitialize_final_analog_outp;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(q_ss_model_step_DW.HILInitialize_Card,
        analog_output_channels, num_final_analog_outputs,
        &q_ss_model_step_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_ss_model_step_M, _rt_error_message);
      }
    }

    hil_task_delete_all(q_ss_model_step_DW.HILInitialize_Card);
    hil_monitor_delete_all(q_ss_model_step_DW.HILInitialize_Card);
    hil_close(q_ss_model_step_DW.HILInitialize_Card);
    q_ss_model_step_DW.HILInitialize_Card = NULL;
  }
}
