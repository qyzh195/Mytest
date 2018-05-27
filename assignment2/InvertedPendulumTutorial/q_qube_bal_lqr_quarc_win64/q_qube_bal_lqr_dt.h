/*
 * q_qube_bal_lqr_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_card),
  sizeof(t_task)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_card",
  "t_task"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&q_qube_bal_lqr_B.HILReadEncoderTimebase_o1), 0, 0, 30 },

  { (char_T *)(&q_qube_bal_lqr_B.Compare), 3, 0, 1 },

  { (char_T *)(&q_qube_bal_lqr_B.RelationalOperator1), 8, 0, 6 }
  ,

  { (char_T *)(&q_qube_bal_lqr_DW.DiscreteTimeIntegrator_DSTATE), 0, 0, 3 },

  { (char_T *)(&q_qube_bal_lqr_DW.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&q_qube_bal_lqr_DW.HILReadEncoderTimebase_Task), 15, 0, 1 },

  { (char_T *)(&q_qube_bal_lqr_DW.HILWriteAnalog_PWORK), 11, 0, 7 },

  { (char_T *)(&q_qube_bal_lqr_DW.HILInitialize_ClockModes), 6, 0, 3 },

  { (char_T *)(&q_qube_bal_lqr_DW.DiscreteTimeIntegrator_PrevRese), 2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&q_qube_bal_lqr_P.K[0]), 0, 0, 11 },

  { (char_T *)(&q_qube_bal_lqr_P.HILReadEncoderTimebase_clock), 6, 0, 1 },

  { (char_T *)(&q_qube_bal_lqr_P.HILReadEncoderTimebase_channels[0]), 7, 0, 4 },

  { (char_T *)(&q_qube_bal_lqr_P.StopwithMessage_message_icon), 2, 0, 1 },

  { (char_T *)(&q_qube_bal_lqr_P.HILInitialize_active), 8, 0, 7 },

  { (char_T *)(&q_qube_bal_lqr_P.ConverttoVector_Gain[0]), 0, 0, 24 },

  { (char_T *)(&q_qube_bal_lqr_P.HILReadEncoderTimebase_Active), 8, 0, 3 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] q_qube_bal_lqr_dt.h */
