/*
 * q_qube_bal_lqr.c
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
#include "q_qube_bal_lqr_dt.h"

/* Block signals (auto storage) */
B_q_qube_bal_lqr_T q_qube_bal_lqr_B;

/* Continuous states */
X_q_qube_bal_lqr_T q_qube_bal_lqr_X;

/* Block states (auto storage) */
DW_q_qube_bal_lqr_T q_qube_bal_lqr_DW;

/* Real-time model */
RT_MODEL_q_qube_bal_lqr_T q_qube_bal_lqr_M_;
RT_MODEL_q_qube_bal_lqr_T *const q_qube_bal_lqr_M = &q_qube_bal_lqr_M_;

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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  q_qube_bal_lqr_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  boolean_T y_0;
  boolean_T y_1;
  if (u1 == 0.0) {
    y = u0;
  } else {
    y_0 = ((!rtIsNaN(u0)) && (!rtIsInf(u0)));
    y_1 = ((!rtIsNaN(u1)) && (!rtIsInf(u1)));
    if (!(y_0 && y_1)) {
      y = (rtNaN);
    } else {
      tmp = u0 / u1;
      if (u1 <= floor(u1)) {
        y = u0 - floor(tmp) * u1;
      } else if (fabs(tmp - rt_roundd_snf(tmp)) <= DBL_EPSILON * fabs(tmp)) {
        y = 0.0;
      } else {
        y = (tmp - floor(tmp)) * u1;
      }
    }
  }

  return y;
}

/* Model step function */
void q_qube_bal_lqr_step(void)
{
  real_T temp;
  if (rtmIsMajorTimeStep(q_qube_bal_lqr_M)) {
    /* set solver stop time */
    if (!(q_qube_bal_lqr_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&q_qube_bal_lqr_M->solverInfo,
                            ((q_qube_bal_lqr_M->Timing.clockTickH0 + 1) *
        q_qube_bal_lqr_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&q_qube_bal_lqr_M->solverInfo,
                            ((q_qube_bal_lqr_M->Timing.clockTick0 + 1) *
        q_qube_bal_lqr_M->Timing.stepSize0 +
        q_qube_bal_lqr_M->Timing.clockTickH0 *
        q_qube_bal_lqr_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(q_qube_bal_lqr_M)) {
    q_qube_bal_lqr_M->Timing.t[0] = rtsiGetT(&q_qube_bal_lqr_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(q_qube_bal_lqr_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

    /* S-Function Block: q_qube_bal_lqr/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (q_qube_bal_lqr_DW.HILReadEncoderTimebase_Task, 1,
         &q_qube_bal_lqr_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube_bal_lqr_M, _rt_error_message);
      } else {
        q_qube_bal_lqr_B.HILReadEncoderTimebase_o1 =
          q_qube_bal_lqr_DW.HILReadEncoderTimebase_Buffer[0];
        q_qube_bal_lqr_B.HILReadEncoderTimebase_o2 =
          q_qube_bal_lqr_DW.HILReadEncoderTimebase_Buffer[1];
      }
    }

    /* Gain: '<S1>/Pendulum:  counts to rad' */
    q_qube_bal_lqr_B.Pendulumcountstorad =
      q_qube_bal_lqr_P.Pendulumcountstorad_Gain *
      q_qube_bal_lqr_B.HILReadEncoderTimebase_o2;

    /* Math: '<S1>/Math Function' incorporates:
     *  Constant: '<S1>/Constant1'
     */
    q_qube_bal_lqr_B.MathFunction = rt_modd_snf
      (q_qube_bal_lqr_B.Pendulumcountstorad, q_qube_bal_lqr_P.Constant1_Value);

    /* Bias: '<S1>/Bias' */
    q_qube_bal_lqr_B.Bias = q_qube_bal_lqr_B.MathFunction +
      q_qube_bal_lqr_P.Bias_Bias;

    /* Abs: '<Root>/|alpha|' */
    q_qube_bal_lqr_B.alpha = fabs(q_qube_bal_lqr_B.Bias);

    /* RelationalOperator: '<S3>/Compare' incorporates:
     *  Constant: '<S3>/Constant'
     */
    q_qube_bal_lqr_B.Compare = (uint8_T)(q_qube_bal_lqr_B.alpha <=
      q_qube_bal_lqr_P.EnableBalanceControl_const);
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  temp = q_qube_bal_lqr_P.SignalGenerator_Frequency * q_qube_bal_lqr_M->
    Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    q_qube_bal_lqr_B.SignalGenerator =
      q_qube_bal_lqr_P.SignalGenerator_Amplitude;
  } else {
    q_qube_bal_lqr_B.SignalGenerator =
      -q_qube_bal_lqr_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Gain: '<Root>/Gain' */
  q_qube_bal_lqr_B.Gain = q_qube_bal_lqr_P.Gain_Gain *
    q_qube_bal_lqr_B.SignalGenerator;

  /* Gain: '<S2>/Gain1' */
  q_qube_bal_lqr_B.Gain1 = q_qube_bal_lqr_P.Gain1_Gain * q_qube_bal_lqr_B.Gain;
  if (rtmIsMajorTimeStep(q_qube_bal_lqr_M)) {
    /* Gain: '<S1>/Arm: counts to rad' */
    q_qube_bal_lqr_B.Armcountstorad = q_qube_bal_lqr_P.Armcountstorad_Gain *
      q_qube_bal_lqr_B.HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S7>/theta_dot' */
  q_qube_bal_lqr_B.theta_dot = 0.0;
  q_qube_bal_lqr_B.theta_dot += q_qube_bal_lqr_P.theta_dot_C *
    q_qube_bal_lqr_X.theta_dot_CSTATE;
  q_qube_bal_lqr_B.theta_dot += q_qube_bal_lqr_P.theta_dot_D *
    q_qube_bal_lqr_B.Armcountstorad;

  /* TransferFcn: '<S7>/alpha_dot' */
  q_qube_bal_lqr_B.alpha_dot = 0.0;
  q_qube_bal_lqr_B.alpha_dot += q_qube_bal_lqr_P.alpha_dot_C *
    q_qube_bal_lqr_X.alpha_dot_CSTATE;
  q_qube_bal_lqr_B.alpha_dot += q_qube_bal_lqr_P.alpha_dot_D *
    q_qube_bal_lqr_B.Bias;

  /* MultiPortSwitch: '<Root>/Enable Balance Control Switch' incorporates:
   *  Constant: '<Root>/u = 0V'
   */
  if (q_qube_bal_lqr_B.Compare == 0) {
    q_qube_bal_lqr_B.EnableBalanceControlSwitch = q_qube_bal_lqr_P.u0V_Value;
  } else {
    /* Gain: '<Root>/Convert to Vector' */
    q_qube_bal_lqr_B.ConverttoVector[0] = q_qube_bal_lqr_P.ConverttoVector_Gain
      [0] * q_qube_bal_lqr_B.Gain1;
    q_qube_bal_lqr_B.ConverttoVector[1] = q_qube_bal_lqr_P.ConverttoVector_Gain
      [1] * q_qube_bal_lqr_B.Gain1;
    q_qube_bal_lqr_B.ConverttoVector[2] = q_qube_bal_lqr_P.ConverttoVector_Gain
      [2] * q_qube_bal_lqr_B.Gain1;
    q_qube_bal_lqr_B.ConverttoVector[3] = q_qube_bal_lqr_P.ConverttoVector_Gain
      [3] * q_qube_bal_lqr_B.Gain1;

    /* Sum: '<Root>/Sum' */
    q_qube_bal_lqr_B.Sum[0] = q_qube_bal_lqr_B.ConverttoVector[0] -
      q_qube_bal_lqr_B.Armcountstorad;
    q_qube_bal_lqr_B.Sum[1] = q_qube_bal_lqr_B.ConverttoVector[1] -
      q_qube_bal_lqr_B.Bias;
    q_qube_bal_lqr_B.Sum[2] = q_qube_bal_lqr_B.ConverttoVector[2] -
      q_qube_bal_lqr_B.theta_dot;
    q_qube_bal_lqr_B.Sum[3] = q_qube_bal_lqr_B.ConverttoVector[3] -
      q_qube_bal_lqr_B.alpha_dot;

    /* Gain: '<Root>/u = -K*x' */
    temp = q_qube_bal_lqr_P.K[0] * q_qube_bal_lqr_B.Sum[0];
    temp += q_qube_bal_lqr_P.K[1] * q_qube_bal_lqr_B.Sum[1];
    temp += q_qube_bal_lqr_P.K[2] * q_qube_bal_lqr_B.Sum[2];
    temp += q_qube_bal_lqr_P.K[3] * q_qube_bal_lqr_B.Sum[3];
    q_qube_bal_lqr_B.uKx = temp;
    q_qube_bal_lqr_B.EnableBalanceControlSwitch = q_qube_bal_lqr_B.uKx;
  }

  /* End of MultiPortSwitch: '<Root>/Enable Balance Control Switch' */

  /* Gain: '<Root>/For +ve CCW' */
  q_qube_bal_lqr_B.ForveCCW = q_qube_bal_lqr_P.ForveCCW_Gain *
    q_qube_bal_lqr_B.EnableBalanceControlSwitch;
  if (rtmIsMajorTimeStep(q_qube_bal_lqr_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: q_qube_bal_lqr/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(q_qube_bal_lqr_DW.HILInitialize_Card,
        &q_qube_bal_lqr_P.HILWriteAnalog_channels, 1, &q_qube_bal_lqr_B.ForveCCW);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube_bal_lqr_M, _rt_error_message);
      }
    }

    /* Gain: '<S4>/Gain' */
    q_qube_bal_lqr_B.Gain_i = q_qube_bal_lqr_P.Gain_Gain_a *
      q_qube_bal_lqr_B.Bias;
  }

  /* Gain: '<S5>/Gain' */
  q_qube_bal_lqr_B.Gain_b[0] = q_qube_bal_lqr_P.Gain_Gain_ae *
    q_qube_bal_lqr_B.Gain1;
  q_qube_bal_lqr_B.Gain_b[1] = q_qube_bal_lqr_P.Gain_Gain_ae *
    q_qube_bal_lqr_B.Armcountstorad;
  if (rtmIsMajorTimeStep(q_qube_bal_lqr_M)) {
    /* Abs: '<S8>/Abs' */
    q_qube_bal_lqr_B.Abs = fabs(q_qube_bal_lqr_B.EnableBalanceControlSwitch);

    /* RelationalOperator: '<S8>/Relational Operator1' incorporates:
     *  Constant: '<S8>/control threshold'
     */
    q_qube_bal_lqr_B.RelationalOperator1 = (q_qube_bal_lqr_B.Abs >=
      q_qube_bal_lqr_P.StallMonitor_control_threshold);

    /* Abs: '<S8>/Abs1' */
    q_qube_bal_lqr_B.Abs1 = fabs(q_qube_bal_lqr_B.theta_dot);

    /* RelationalOperator: '<S8>/Relational Operator' incorporates:
     *  Constant: '<S8>/motion threshold'
     */
    q_qube_bal_lqr_B.RelationalOperator = (q_qube_bal_lqr_B.Abs1 <=
      q_qube_bal_lqr_P.StallMonitor_motion_threshold);

    /* Logic: '<S8>/Logical Operator' */
    q_qube_bal_lqr_B.LogicalOperator = (q_qube_bal_lqr_B.RelationalOperator1 &&
      q_qube_bal_lqr_B.RelationalOperator);

    /* Logic: '<S8>/Logical Operator1' */
    q_qube_bal_lqr_B.LogicalOperator1 = !q_qube_bal_lqr_B.LogicalOperator;

    /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
    if (q_qube_bal_lqr_B.LogicalOperator1 &&
        (q_qube_bal_lqr_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      q_qube_bal_lqr_DW.DiscreteTimeIntegrator_DSTATE =
        q_qube_bal_lqr_P.DiscreteTimeIntegrator_IC;
    }

    q_qube_bal_lqr_B.DiscreteTimeIntegrator =
      q_qube_bal_lqr_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */

    /* RelationalOperator: '<S8>/Relational Operator2' incorporates:
     *  Constant: '<S8>/control threshold1'
     */
    q_qube_bal_lqr_B.RelationalOperator2 =
      (q_qube_bal_lqr_B.DiscreteTimeIntegrator >=
       q_qube_bal_lqr_P.StallMonitor_duration_s);

    /* RelationalOperator: '<S10>/Compare' incorporates:
     *  Constant: '<S10>/Constant'
     */
    q_qube_bal_lqr_B.Compare_j = (q_qube_bal_lqr_B.RelationalOperator2 !=
      q_qube_bal_lqr_P.Constant_Value);

    /* Stop: '<S9>/Stop Simulation' */
    if (q_qube_bal_lqr_B.Compare_j) {
      rtmSetStopRequested(q_qube_bal_lqr_M, 1);
    }

    /* End of Stop: '<S9>/Stop Simulation' */

    /* DataTypeConversion: '<S8>/Data Type Conversion' */
    q_qube_bal_lqr_B.DataTypeConversion = q_qube_bal_lqr_B.LogicalOperator;
  }

  if (rtmIsMajorTimeStep(q_qube_bal_lqr_M)) {
    if (rtmIsMajorTimeStep(q_qube_bal_lqr_M)) {
      /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
      q_qube_bal_lqr_DW.DiscreteTimeIntegrator_DSTATE +=
        q_qube_bal_lqr_P.DiscreteTimeIntegrator_gainval *
        q_qube_bal_lqr_B.DataTypeConversion;
      q_qube_bal_lqr_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
        q_qube_bal_lqr_B.LogicalOperator1;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, q_qube_bal_lqr_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(q_qube_bal_lqr_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((q_qube_bal_lqr_M->Timing.clockTick1+
                            q_qube_bal_lqr_M->Timing.clockTickH1* 4294967296.0))
                          * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(q_qube_bal_lqr_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(q_qube_bal_lqr_M)!=-1) &&
          !((rtmGetTFinal(q_qube_bal_lqr_M)-
             (((q_qube_bal_lqr_M->Timing.clockTick1+
                q_qube_bal_lqr_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((q_qube_bal_lqr_M->Timing.clockTick1+
               q_qube_bal_lqr_M->Timing.clockTickH1* 4294967296.0)) * 0.002) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(q_qube_bal_lqr_M, "Simulation finished");
      }

      if (rtmGetStopRequested(q_qube_bal_lqr_M)) {
        rtmSetErrorStatus(q_qube_bal_lqr_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&q_qube_bal_lqr_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++q_qube_bal_lqr_M->Timing.clockTick0)) {
      ++q_qube_bal_lqr_M->Timing.clockTickH0;
    }

    q_qube_bal_lqr_M->Timing.t[0] = rtsiGetSolverStopTime
      (&q_qube_bal_lqr_M->solverInfo);

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
      q_qube_bal_lqr_M->Timing.clockTick1++;
      if (!q_qube_bal_lqr_M->Timing.clockTick1) {
        q_qube_bal_lqr_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void q_qube_bal_lqr_derivatives(void)
{
  XDot_q_qube_bal_lqr_T *_rtXdot;
  _rtXdot = ((XDot_q_qube_bal_lqr_T *) q_qube_bal_lqr_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S7>/theta_dot' */
  _rtXdot->theta_dot_CSTATE = 0.0;
  _rtXdot->theta_dot_CSTATE += q_qube_bal_lqr_P.theta_dot_A *
    q_qube_bal_lqr_X.theta_dot_CSTATE;
  _rtXdot->theta_dot_CSTATE += q_qube_bal_lqr_B.Armcountstorad;

  /* Derivatives for TransferFcn: '<S7>/alpha_dot' */
  _rtXdot->alpha_dot_CSTATE = 0.0;
  _rtXdot->alpha_dot_CSTATE += q_qube_bal_lqr_P.alpha_dot_A *
    q_qube_bal_lqr_X.alpha_dot_CSTATE;
  _rtXdot->alpha_dot_CSTATE += q_qube_bal_lqr_B.Bias;
}

/* Model initialize function */
void q_qube_bal_lqr_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)q_qube_bal_lqr_M, 0,
                sizeof(RT_MODEL_q_qube_bal_lqr_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&q_qube_bal_lqr_M->solverInfo,
                          &q_qube_bal_lqr_M->Timing.simTimeStep);
    rtsiSetTPtr(&q_qube_bal_lqr_M->solverInfo, &rtmGetTPtr(q_qube_bal_lqr_M));
    rtsiSetStepSizePtr(&q_qube_bal_lqr_M->solverInfo,
                       &q_qube_bal_lqr_M->Timing.stepSize0);
    rtsiSetdXPtr(&q_qube_bal_lqr_M->solverInfo,
                 &q_qube_bal_lqr_M->ModelData.derivs);
    rtsiSetContStatesPtr(&q_qube_bal_lqr_M->solverInfo, (real_T **)
                         &q_qube_bal_lqr_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&q_qube_bal_lqr_M->solverInfo,
      &q_qube_bal_lqr_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&q_qube_bal_lqr_M->solverInfo,
      &q_qube_bal_lqr_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&q_qube_bal_lqr_M->solverInfo,
      &q_qube_bal_lqr_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&q_qube_bal_lqr_M->solverInfo,
      &q_qube_bal_lqr_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&q_qube_bal_lqr_M->solverInfo, (&rtmGetErrorStatus
      (q_qube_bal_lqr_M)));
    rtsiSetRTModelPtr(&q_qube_bal_lqr_M->solverInfo, q_qube_bal_lqr_M);
  }

  rtsiSetSimTimeStep(&q_qube_bal_lqr_M->solverInfo, MAJOR_TIME_STEP);
  q_qube_bal_lqr_M->ModelData.intgData.f[0] = q_qube_bal_lqr_M->ModelData.odeF[0];
  q_qube_bal_lqr_M->ModelData.contStates = ((X_q_qube_bal_lqr_T *)
    &q_qube_bal_lqr_X);
  rtsiSetSolverData(&q_qube_bal_lqr_M->solverInfo, (void *)
                    &q_qube_bal_lqr_M->ModelData.intgData);
  rtsiSetSolverName(&q_qube_bal_lqr_M->solverInfo,"ode1");
  rtmSetTPtr(q_qube_bal_lqr_M, &q_qube_bal_lqr_M->Timing.tArray[0]);
  rtmSetTFinal(q_qube_bal_lqr_M, -1);
  q_qube_bal_lqr_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  q_qube_bal_lqr_M->Sizes.checksums[0] = (108665077U);
  q_qube_bal_lqr_M->Sizes.checksums[1] = (2047754471U);
  q_qube_bal_lqr_M->Sizes.checksums[2] = (1872010138U);
  q_qube_bal_lqr_M->Sizes.checksums[3] = (60185919U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    q_qube_bal_lqr_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(q_qube_bal_lqr_M->extModeInfo,
      &q_qube_bal_lqr_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(q_qube_bal_lqr_M->extModeInfo,
                        q_qube_bal_lqr_M->Sizes.checksums);
    rteiSetTPtr(q_qube_bal_lqr_M->extModeInfo, rtmGetTPtr(q_qube_bal_lqr_M));
  }

  /* block I/O */
  (void) memset(((void *) &q_qube_bal_lqr_B), 0,
                sizeof(B_q_qube_bal_lqr_T));

  {
    q_qube_bal_lqr_B.HILReadEncoderTimebase_o1 = 0.0;
    q_qube_bal_lqr_B.HILReadEncoderTimebase_o2 = 0.0;
    q_qube_bal_lqr_B.Pendulumcountstorad = 0.0;
    q_qube_bal_lqr_B.MathFunction = 0.0;
    q_qube_bal_lqr_B.Bias = 0.0;
    q_qube_bal_lqr_B.alpha = 0.0;
    q_qube_bal_lqr_B.SignalGenerator = 0.0;
    q_qube_bal_lqr_B.Gain = 0.0;
    q_qube_bal_lqr_B.Gain1 = 0.0;
    q_qube_bal_lqr_B.Armcountstorad = 0.0;
    q_qube_bal_lqr_B.theta_dot = 0.0;
    q_qube_bal_lqr_B.alpha_dot = 0.0;
    q_qube_bal_lqr_B.EnableBalanceControlSwitch = 0.0;
    q_qube_bal_lqr_B.ForveCCW = 0.0;
    q_qube_bal_lqr_B.Gain_i = 0.0;
    q_qube_bal_lqr_B.Gain_b[0] = 0.0;
    q_qube_bal_lqr_B.Gain_b[1] = 0.0;
    q_qube_bal_lqr_B.Abs = 0.0;
    q_qube_bal_lqr_B.Abs1 = 0.0;
    q_qube_bal_lqr_B.DiscreteTimeIntegrator = 0.0;
    q_qube_bal_lqr_B.DataTypeConversion = 0.0;
    q_qube_bal_lqr_B.ConverttoVector[0] = 0.0;
    q_qube_bal_lqr_B.ConverttoVector[1] = 0.0;
    q_qube_bal_lqr_B.ConverttoVector[2] = 0.0;
    q_qube_bal_lqr_B.ConverttoVector[3] = 0.0;
    q_qube_bal_lqr_B.Sum[0] = 0.0;
    q_qube_bal_lqr_B.Sum[1] = 0.0;
    q_qube_bal_lqr_B.Sum[2] = 0.0;
    q_qube_bal_lqr_B.Sum[3] = 0.0;
    q_qube_bal_lqr_B.uKx = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&q_qube_bal_lqr_X, 0,
                  sizeof(X_q_qube_bal_lqr_T));
  }

  /* states (dwork) */
  (void) memset((void *)&q_qube_bal_lqr_DW, 0,
                sizeof(DW_q_qube_bal_lqr_T));
  q_qube_bal_lqr_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  q_qube_bal_lqr_DW.HILInitialize_AOVoltages[0] = 0.0;
  q_qube_bal_lqr_DW.HILInitialize_AOVoltages[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    q_qube_bal_lqr_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: q_qube_bal_lqr/HIL Initialize (hil_initialize_block) */
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
                      &q_qube_bal_lqr_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_qube_bal_lqr_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(q_qube_bal_lqr_DW.HILInitialize_Card,
      "d0=pwm;d1=pwm;led=auto;update_rate=normal;decimation=1", 55);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_qube_bal_lqr_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(q_qube_bal_lqr_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_qube_bal_lqr_M, _rt_error_message);
      return;
    }

    if (!is_switching) {
      result = hil_set_analog_output_ranges(q_qube_bal_lqr_DW.HILInitialize_Card,
        analog_output_channels, 2U,
        analog_output_minimums, analog_output_maximums);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube_bal_lqr_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_write_analog(q_qube_bal_lqr_DW.HILInitialize_Card,
        analog_output_channels, 2U, initial_analog_outputs);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube_bal_lqr_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_quadrature_mode
        (q_qube_bal_lqr_DW.HILInitialize_Card, encoder_input_channels, 2U,
         (t_encoder_quadrature_mode *) encoder_quadrature);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube_bal_lqr_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_counts(q_qube_bal_lqr_DW.HILInitialize_Card,
        encoder_input_channels, 2U, initial_encoder_counts);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube_bal_lqr_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: q_qube_bal_lqr/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(q_qube_bal_lqr_DW.HILInitialize_Card,
      q_qube_bal_lqr_P.HILReadEncoderTimebase_samples_,
      q_qube_bal_lqr_P.HILReadEncoderTimebase_channels, 2,
      &q_qube_bal_lqr_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_qube_bal_lqr_M, _rt_error_message);
    }
  }

  /* InitializeConditions for TransferFcn: '<S7>/theta_dot' */
  q_qube_bal_lqr_X.theta_dot_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S7>/alpha_dot' */
  q_qube_bal_lqr_X.alpha_dot_CSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
  q_qube_bal_lqr_DW.DiscreteTimeIntegrator_DSTATE =
    q_qube_bal_lqr_P.DiscreteTimeIntegrator_IC;
  q_qube_bal_lqr_DW.DiscreteTimeIntegrator_PrevRese = 2;
}

/* Model terminate function */
void q_qube_bal_lqr_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: q_qube_bal_lqr/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    static const t_uint analog_output_channels[2U] = {
      0
      , 1
    };

    hil_task_stop_all(q_qube_bal_lqr_DW.HILInitialize_Card);
    hil_monitor_stop_all(q_qube_bal_lqr_DW.HILInitialize_Card);
    is_switching = false;
    if ((q_qube_bal_lqr_P.HILInitialize_set_analog_outp_d && !is_switching) ||
        (q_qube_bal_lqr_P.HILInitialize_set_analog_output && is_switching)) {
      q_qube_bal_lqr_DW.HILInitialize_AOVoltages[0] =
        q_qube_bal_lqr_P.HILInitialize_final_analog_outp;
      q_qube_bal_lqr_DW.HILInitialize_AOVoltages[1] =
        q_qube_bal_lqr_P.HILInitialize_final_analog_outp;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(q_qube_bal_lqr_DW.HILInitialize_Card,
        analog_output_channels, num_final_analog_outputs,
        &q_qube_bal_lqr_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube_bal_lqr_M, _rt_error_message);
      }
    }

    hil_task_delete_all(q_qube_bal_lqr_DW.HILInitialize_Card);
    hil_monitor_delete_all(q_qube_bal_lqr_DW.HILInitialize_Card);
    hil_close(q_qube_bal_lqr_DW.HILInitialize_Card);
    q_qube_bal_lqr_DW.HILInitialize_Card = NULL;
  }
}
