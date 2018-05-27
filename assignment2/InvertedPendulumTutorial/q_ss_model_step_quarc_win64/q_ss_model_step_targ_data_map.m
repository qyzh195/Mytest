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
    ;% Auto data (q_ss_model_step_P)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% q_ss_model_step_P.A
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_ss_model_step_P.B
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 16;
	
	  ;% q_ss_model_step_P.C
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 20;
	
	  ;% q_ss_model_step_P.StallMonitor_control_threshold
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 28;
	
	  ;% q_ss_model_step_P.StallMonitor_duration_s
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 29;
	
	  ;% q_ss_model_step_P.HILInitialize_final_analog_outp
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 30;
	
	  ;% q_ss_model_step_P.StallMonitor_motion_threshold
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 31;
	
	  ;% q_ss_model_step_P.HILInitialize_set_other_outputs
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 32;
	
	  ;% q_ss_model_step_P.HILInitialize_set_other_outpu_o
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 33;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_ss_model_step_P.HILReadEncoderTimebase_clock
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% q_ss_model_step_P.HILReadEncoderTimebase_channels
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_ss_model_step_P.HILWriteAnalog_channels
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 2;
	
	  ;% q_ss_model_step_P.HILReadEncoderTimebase_samples_
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_ss_model_step_P.StopwithMessage_message_icon
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% q_ss_model_step_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_ss_model_step_P.HILInitialize_set_analog_output
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_ss_model_step_P.HILInitialize_set_analog_outp_e
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_ss_model_step_P.HILInitialize_set_digital_outpu
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_ss_model_step_P.HILInitialize_set_digital_out_d
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_ss_model_step_P.HILInitialize_set_pwm_outputs_a
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_ss_model_step_P.HILInitialize_set_pwm_outputs_n
	  section.data(7).logicalSrcIdx = 20;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% q_ss_model_step_P.SignalGenerator_Amplitude
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_ss_model_step_P.SignalGenerator_Frequency
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_ss_model_step_P.AmplitudeV_Gain
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_ss_model_step_P.Pendulumcountstorad_Gain
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_ss_model_step_P.StateSpaceModel_X0
	  section.data(5).logicalSrcIdx = 25;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_ss_model_step_P.RotaryArmcountstorad_Gain
	  section.data(6).logicalSrcIdx = 26;
	  section.data(6).dtTransOffset = 8;
	
	  ;% q_ss_model_step_P.TransferFcn_A
	  section.data(7).logicalSrcIdx = 27;
	  section.data(7).dtTransOffset = 9;
	
	  ;% q_ss_model_step_P.TransferFcn_C
	  section.data(8).logicalSrcIdx = 28;
	  section.data(8).dtTransOffset = 10;
	
	  ;% q_ss_model_step_P.TransferFcn_D
	  section.data(9).logicalSrcIdx = 29;
	  section.data(9).dtTransOffset = 11;
	
	  ;% q_ss_model_step_P.DiscreteTimeIntegrator_gainval
	  section.data(10).logicalSrcIdx = 30;
	  section.data(10).dtTransOffset = 12;
	
	  ;% q_ss_model_step_P.DiscreteTimeIntegrator_IC
	  section.data(11).logicalSrcIdx = 31;
	  section.data(11).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% q_ss_model_step_P.HILReadEncoderTimebase_Active
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_ss_model_step_P.HILWriteAnalog_Active
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_ss_model_step_P.Constant_Value
	  section.data(3).logicalSrcIdx = 34;
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
    nTotSects     = 2;
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
    ;% Auto data (q_ss_model_step_B)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% q_ss_model_step_B.AmplitudeV
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_ss_model_step_B.Pendulumcountstorad
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_ss_model_step_B.StateSpaceModel
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_ss_model_step_B.RotaryArmcountstorad
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% q_ss_model_step_B.TransferFcn
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_ss_model_step_B.RelationalOperator2
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
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
    sectIdxOffset = 2;
    
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
    ;% Auto data (q_ss_model_step_DW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% q_ss_model_step_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_ss_model_step_DW.HILInitialize_AOVoltages
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_ss_model_step_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_ss_model_step_DW.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% q_ss_model_step_DW.HILWriteAnalog_PWORK
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_ss_model_step_DW.PendulumAnglerad_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_ss_model_step_DW.RotaryArmAnglerad_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% q_ss_model_step_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_ss_model_step_DW.HILReadEncoderTimebase_Buffer
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_ss_model_step_DW.DiscreteTimeIntegrator_PrevRese
	  section.data(1).logicalSrcIdx = 9;
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


  targMap.checksum0 = 2656204316;
  targMap.checksum1 = 1674601428;
  targMap.checksum2 = 393453125;
  targMap.checksum3 = 722645006;

