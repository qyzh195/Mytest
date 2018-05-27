  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (q_qube_bal_lqr_P)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% q_qube_bal_lqr_P.K
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube_bal_lqr_P.EnableBalanceControl_const
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 4;
	
	  ;% q_qube_bal_lqr_P.StallMonitor_control_threshold
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 5;
	
	  ;% q_qube_bal_lqr_P.StallMonitor_duration_s
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% q_qube_bal_lqr_P.HILInitialize_final_analog_outp
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 7;
	
	  ;% q_qube_bal_lqr_P.StallMonitor_motion_threshold
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% q_qube_bal_lqr_P.HILInitialize_set_other_outputs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% q_qube_bal_lqr_P.HILInitialize_set_other_outpu_k
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_qube_bal_lqr_P.HILReadEncoderTimebase_clock
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% q_qube_bal_lqr_P.HILReadEncoderTimebase_channels
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube_bal_lqr_P.HILWriteAnalog_channels
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 2;
	
	  ;% q_qube_bal_lqr_P.HILReadEncoderTimebase_samples_
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_qube_bal_lqr_P.StopwithMessage_message_icon
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% q_qube_bal_lqr_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube_bal_lqr_P.HILInitialize_set_analog_output
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_qube_bal_lqr_P.HILInitialize_set_analog_outp_d
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_qube_bal_lqr_P.HILInitialize_set_digital_outpu
	  section.data(4).logicalSrcIdx = 16;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_qube_bal_lqr_P.HILInitialize_set_digital_out_p
	  section.data(5).logicalSrcIdx = 17;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_qube_bal_lqr_P.HILInitialize_set_pwm_outputs_a
	  section.data(6).logicalSrcIdx = 18;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_qube_bal_lqr_P.HILInitialize_set_pwm_outputs_c
	  section.data(7).logicalSrcIdx = 19;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% q_qube_bal_lqr_P.ConverttoVector_Gain
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube_bal_lqr_P.Pendulumcountstorad_Gain
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 4;
	
	  ;% q_qube_bal_lqr_P.Constant1_Value
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 5;
	
	  ;% q_qube_bal_lqr_P.Bias_Bias
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 6;
	
	  ;% q_qube_bal_lqr_P.u0V_Value
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 7;
	
	  ;% q_qube_bal_lqr_P.SignalGenerator_Amplitude
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 8;
	
	  ;% q_qube_bal_lqr_P.SignalGenerator_Frequency
	  section.data(7).logicalSrcIdx = 26;
	  section.data(7).dtTransOffset = 9;
	
	  ;% q_qube_bal_lqr_P.Gain_Gain
	  section.data(8).logicalSrcIdx = 27;
	  section.data(8).dtTransOffset = 10;
	
	  ;% q_qube_bal_lqr_P.Gain1_Gain
	  section.data(9).logicalSrcIdx = 28;
	  section.data(9).dtTransOffset = 11;
	
	  ;% q_qube_bal_lqr_P.Armcountstorad_Gain
	  section.data(10).logicalSrcIdx = 29;
	  section.data(10).dtTransOffset = 12;
	
	  ;% q_qube_bal_lqr_P.theta_dot_A
	  section.data(11).logicalSrcIdx = 30;
	  section.data(11).dtTransOffset = 13;
	
	  ;% q_qube_bal_lqr_P.theta_dot_C
	  section.data(12).logicalSrcIdx = 31;
	  section.data(12).dtTransOffset = 14;
	
	  ;% q_qube_bal_lqr_P.theta_dot_D
	  section.data(13).logicalSrcIdx = 32;
	  section.data(13).dtTransOffset = 15;
	
	  ;% q_qube_bal_lqr_P.alpha_dot_A
	  section.data(14).logicalSrcIdx = 33;
	  section.data(14).dtTransOffset = 16;
	
	  ;% q_qube_bal_lqr_P.alpha_dot_C
	  section.data(15).logicalSrcIdx = 34;
	  section.data(15).dtTransOffset = 17;
	
	  ;% q_qube_bal_lqr_P.alpha_dot_D
	  section.data(16).logicalSrcIdx = 35;
	  section.data(16).dtTransOffset = 18;
	
	  ;% q_qube_bal_lqr_P.ForveCCW_Gain
	  section.data(17).logicalSrcIdx = 36;
	  section.data(17).dtTransOffset = 19;
	
	  ;% q_qube_bal_lqr_P.Gain_Gain_a
	  section.data(18).logicalSrcIdx = 37;
	  section.data(18).dtTransOffset = 20;
	
	  ;% q_qube_bal_lqr_P.Gain_Gain_ae
	  section.data(19).logicalSrcIdx = 38;
	  section.data(19).dtTransOffset = 21;
	
	  ;% q_qube_bal_lqr_P.DiscreteTimeIntegrator_gainval
	  section.data(20).logicalSrcIdx = 39;
	  section.data(20).dtTransOffset = 22;
	
	  ;% q_qube_bal_lqr_P.DiscreteTimeIntegrator_IC
	  section.data(21).logicalSrcIdx = 40;
	  section.data(21).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% q_qube_bal_lqr_P.HILReadEncoderTimebase_Active
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube_bal_lqr_P.HILWriteAnalog_Active
	  section.data(2).logicalSrcIdx = 42;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_qube_bal_lqr_P.Constant_Value
	  section.data(3).logicalSrcIdx = 43;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (q_qube_bal_lqr_B)
    ;%
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% q_qube_bal_lqr_B.HILReadEncoderTimebase_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube_bal_lqr_B.HILReadEncoderTimebase_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_qube_bal_lqr_B.Pendulumcountstorad
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_qube_bal_lqr_B.MathFunction
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_qube_bal_lqr_B.Bias
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_qube_bal_lqr_B.alpha
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_qube_bal_lqr_B.SignalGenerator
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_qube_bal_lqr_B.Gain
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_qube_bal_lqr_B.Gain1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% q_qube_bal_lqr_B.Armcountstorad
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% q_qube_bal_lqr_B.theta_dot
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% q_qube_bal_lqr_B.alpha_dot
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% q_qube_bal_lqr_B.EnableBalanceControlSwitch
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% q_qube_bal_lqr_B.ForveCCW
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% q_qube_bal_lqr_B.Gain_i
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% q_qube_bal_lqr_B.Gain_b
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% q_qube_bal_lqr_B.Abs
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 17;
	
	  ;% q_qube_bal_lqr_B.Abs1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 18;
	
	  ;% q_qube_bal_lqr_B.DiscreteTimeIntegrator
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 19;
	
	  ;% q_qube_bal_lqr_B.DataTypeConversion
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 20;
	
	  ;% q_qube_bal_lqr_B.ConverttoVector
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 21;
	
	  ;% q_qube_bal_lqr_B.Sum
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 25;
	
	  ;% q_qube_bal_lqr_B.uKx
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 29;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_qube_bal_lqr_B.Compare
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% q_qube_bal_lqr_B.RelationalOperator1
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube_bal_lqr_B.RelationalOperator
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_qube_bal_lqr_B.LogicalOperator
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_qube_bal_lqr_B.LogicalOperator1
	  section.data(4).logicalSrcIdx = 27;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_qube_bal_lqr_B.RelationalOperator2
	  section.data(5).logicalSrcIdx = 28;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_qube_bal_lqr_B.Compare_j
	  section.data(6).logicalSrcIdx = 29;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (q_qube_bal_lqr_DW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% q_qube_bal_lqr_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube_bal_lqr_DW.HILInitialize_AOVoltages
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_qube_bal_lqr_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_qube_bal_lqr_DW.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% q_qube_bal_lqr_DW.HILWriteAnalog_PWORK
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube_bal_lqr_DW.MotorVoltageV_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_qube_bal_lqr_DW.Pendulumdeg_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_qube_bal_lqr_DW.RotaryArmdeg_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_qube_bal_lqr_DW.ToWorkspace_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_qube_bal_lqr_DW.ToWorkspace1_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_qube_bal_lqr_DW.ToWorkspace2_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% q_qube_bal_lqr_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_qube_bal_lqr_DW.HILReadEncoderTimebase_Buffer
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_qube_bal_lqr_DW.DiscreteTimeIntegrator_PrevRese
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 108665077;
  targMap.checksum1 = 2047754471;
  targMap.checksum2 = 1872010138;
  targMap.checksum3 = 60185919;

