/* Production model for solution at a given concentration: cyclic process (assumes preparation has been previously executed) */

const 
	-- scenario-independent constants
	LEVEL_B1_MAX : 21.05; -- 8000 cm^3 / 380 cm^2 = 21.0526315789
	LEVEL_B2_MAX : 15.78; -- 6000 cm^3 / 380 cm^2 = 15.7894736842
	LEVEL_B3_MAX : 18.42; -- 7000 cm^3 / 380 cm^2 = 18.4210526316
	LEVEL_B4_MAX : 36.84; -- 14000 cm^3 / 380 cm^2 = 36.8421052632
	LEVEL_B5_MAX : 18.42; -- 7000 cm^3 / 380 cm^2 = 18.4210526316
	LEVEL_B6_MAX : 15.78; -- 6000 cm^3 / 380 cm^2 = 15.7894736842
	LEVEL_B7_MAX : 21.05; -- 8000 cm^3 / 380 cm^2 = 21.0526315789
	
	LEVEL_B5_SAFETY : 8.00; -- "An Abstract Model of VHS Case Study 1 (Experimental Batch Plant)" par. 2.2.5 pag. 15
	
	-- scenario-dependent constants
	START_LEVEL_B1 : 13.15;
	START_LEVEL_B2 : 15.78;
	START_CONCENTRATION_B1 : 5;
	
	CONCENTRATION_MAX : 5;
	CONCENTRATION_TARGET : 3.0;
	
	
	STEP_TIME : 10;
	
type
	interval_time : 0..10000;
	real_type : real(4,10);

/* State variables: 44 booleans, 14 reals, 1 integer */
var
	/* 'FALSE' colsed valve; 'TRUE' open valve */
	valve_1 : boolean;
	valve_2 : boolean;
	valve_3 : boolean;
	valve_4 : boolean;
	valve_5 : boolean;
	valve_6 : boolean;
	valve_7 : boolean;
	valve_8 : boolean;
	valve_9 : boolean;
	valve_10 : boolean;
	valve_11 : boolean;
	valve_12 : boolean;
	valve_13 : boolean;
	valve_14 : boolean;
	valve_15 : boolean;
	valve_16 : boolean;
	valve_17 : boolean;
	valve_18 : boolean;
	valve_19 : boolean;
	valve_20 : boolean;
	valve_21 : boolean;
	valve_22 : boolean;
	valve_23 : boolean;
	valve_24 : boolean;
	valve_25 : boolean;
	valve_26 : boolean;
	valve_27 : boolean;
	valve_28 : boolean;
	valve_29 : boolean;
	LEVEL_TARGET : real_type;
	/* 'FALSE' pump switched off; 'TRUE' pump switched on */
	pump_1 : boolean;
	pump_2 : boolean;
	
	/* 'FALSE' heater switched off; 'TRUE' heater switched on */
	heater_5 : boolean;
	
	c_1 : real_type;
	c_2 : real_type;
	c_3 : real_type;
	c_5 : real_type;

	T_5 : real_type;
	T_6 : real_type;
	T_7 : real_type;
	
	level_b1 : real_type;
	level_b2 : real_type;
	level_b3 : real_type;
	level_b3_recycle : real_type;
	level_b4 : real_type;
	level_b5 : real_type;
	level_b6 : real_type;
	level_b7 : real_type;

	time : interval_time;
	isGoal_part : boolean;
	isGoal_final : boolean;

	/* 'TRUE' is the system satisfies all the properties, 'FALSE' otherwise */
	systemProperties : boolean; -- in planetary.m corrisponde a "all_event_true"
	
	/* 'TRUE' when a (scenario dependent) "sub-goal", has been reached */
	filling_b3_done : boolean;
	concentration_reached : boolean;
	get_production_done : boolean;
	filling_b4_done : boolean;
	filling_b5_done : boolean;
	high_concentration_reached : boolean;
	filling_b7_done : boolean;
	filling_b1_done : boolean;
	filling_b2_done : boolean;	
	cooled_b6 : boolean;
	cooled_b7 : boolean;
	
/* External functions in "equations.c" */
/* Cyclic process */

/* B1 -> B3 */
externfun cyclic_level_b1_b3(level_b1 : real_type; step_time : interval_time) : real_type "equations.c";

/* Dilution B2 -> B3 */
externfun cyclic_level_b2_b3(level_b2 : real_type; step_time : interval_time) : real_type;

externfun cyclic_concentration_b3_in_b2(c_3 : real_type; c_2 : real_type; level_b2 : real_type; level_b3 : real_type; step_time : interval_time) : real_type;

/* B3 -> B4 */
externfun cyclic_level_b3_b4(level_b3 : real_type; step_time : interval_time) : real_type;

/* B4 -> B5 */
externfun cyclic_level_b4_b5(level_b4 : real_type; step_time : interval_time) : real_type;

/* Heating until  boiling temperature */
externfun cyclic_temperature_b5(T_5 : real_type; level_b5 : real_type; step_time : interval_time) : real_type;

/* Evaporation */
externfun cyclic_level_b5_out_b6(level_b5 : real_type; step_time : interval_time) : real_type;
externfun cyclic_level_b6_in_b5(level_b6 : real_type; step_time : interval_time) : real_type;

/* Non si dovrebbe usare: le equazioni precedenti sono diverse: pare che il liquido che esce non sia uguale a quello che entra in questo caso */
externfun cyclic_level_b5_b6(level_b5 : real_type; step_time : interval_time) : real_type;

externfun cyclic_concentration_b5(c_5 : real_type; level_b5 : real_type; step_time : interval_time) : real_type;
externfun cyclic_temperature_b_5(T_5 : real_type; step_time : interval_time) : real_type;

/* B5 -> B7 */
externfun cyclic_level_b5_b7(level_b5 : real_type; step_time : interval_time) : real_type;

/* Cooling in B7 */
externfun cyclic_temperature_b7(T_7 : real_type; level_b7 : real_type; step_time : interval_time) : real_type;

/* B7 -> B1 */
externfun cyclic_level_b7_b1(level_b7 : real_type; step_time : interval_time) : real_type;

/* Cooling in B6 */
externfun cyclic_temperature_b6(T_6 : real_type; level_b6 : real_type; step_time : interval_time) : real_type;

/* B6 -> B2 */
externfun cyclic_level_b6_b2(level_b6 : real_type; step_time : interval_time) : real_type;


/* Invariantis see the paper "An Abstract Model of VHS Case Study 1 (Experimental Batch Plant)", sect. 3 "The Properties" pag. 28 */

procedure heater_5_failure();
begin
	if (heater_5 = TRUE & !(valve_12 = FALSE & valve_15 = FALSE & valve_16 = FALSE) |
		heater_5 = TRUE & !(valve_13 = TRUE) --|
		--heater_5 = TRUE & !(level_b5 >= LEVEL_B5_SAFETY)
	) then 
		systemProperties := FALSE;
	endif;
end;

procedure cooling_failure();
begin
	if (valve_13 = TRUE & valve_17 = TRUE & valve_29 = TRUE) then
		systemProperties := FALSE;
	endif;
end;

procedure flow_b1_failure();
begin
	if (valve_3 = TRUE & valve_8 = TRUE) then
		systemProperties := FALSE;
	endif;
end;

procedure flow_b2_failure();
begin
	if ((valve_6 = TRUE | valve_7 = TRUE) & (valve_9 = TRUE)) then
		systemProperties := FALSE;
	endif;
end;

procedure flow_b3_failure();
begin
	if ((valve_8 = TRUE | valve_9 = TRUE) & (valve_10 = TRUE | valve_11 = TRUE)) then
		systemProperties := FALSE;
	endif;
end;

procedure flow_b4_failure();
begin
	if (valve_11 = TRUE & valve_12 = TRUE) then
		systemProperties := FALSE;
	endif;
end;

procedure flow_b5_failure();
begin
	if ((valve_12 = TRUE & (valve_15 = TRUE | valve_16 = TRUE))) then
		systemProperties := FALSE;
	endif;
end;

procedure flow_b6_failure();
begin
	if (((valve_13 & valve_14 = TRUE)  & (valve_19 = TRUE | valve_20 = TRUE | valve_27 = TRUE))) then -- DA CONTROLLARE anche valve_13 deve essere chiusa?
		systemProperties := FALSE;
	endif;
end;

procedure flow_b7_failure();
begin
	if (valve_15 = TRUE & valve_18 = TRUE) then
		systemProperties := FALSE;
	endif;
end;

procedure level_b1_failure();
begin
	if (level_b1 < 0 | level_b1 > LEVEL_B1_MAX) then
		systemProperties := FALSE;
	endif;
end;

procedure level_b2_failure();
begin
	if (level_b2 < 0 | level_b2 > LEVEL_B2_MAX) then
		systemProperties := FALSE;
	endif;
end;

procedure level_b3_failure();
begin
	if (level_b3 < 0 | level_b3 > LEVEL_B3_MAX) then
		systemProperties := FALSE;
	endif;
end;

procedure level_b4_failure();
begin
	if (level_b4 < 0 | level_b4 > LEVEL_B4_MAX) then
		systemProperties := FALSE;
	endif;
end;

procedure level_b5_failure();
begin
	if (level_b5 < 0 | level_b5 > LEVEL_B5_MAX) then
		systemProperties := FALSE;
	endif;
end;

procedure level_b6_failure();
begin
	if (level_b6 < 0 | level_b6 > LEVEL_B6_MAX) then
		systemProperties := FALSE;
	endif;
end;

procedure level_b7_failure();
begin
	if (level_b7 < 0 | level_b7 > LEVEL_B7_MAX) then
		systemProperties := FALSE;
	endif;
end;

procedure pump_1_failure();
begin
	if (pump_1 = TRUE & !((valve_22 = TRUE & valve_26 = TRUE) |
						 (valve_22 = TRUE & valve_1 = TRUE & valve_3 = TRUE) |
						 (valve_10 = TRUE & valve_23 = TRUE & valve_22 = TRUE & valve_1 = TRUE & valve_3 = TRUE) |
						 (valve_20 = TRUE & valve_21 = TRUE & valve_23 = TRUE & valve_22 = TRUE & valve_1 = TRUE & valve_2 = TRUE & valve_4 = TRUE & valve_6 = TRUE) |
						 (valve_18 = TRUE & valve_23 = TRUE & valve_22 = TRUE & valve_1 = TRUE & valve_3 = TRUE) |
						 (valve_10 = TRUE & valve_23 = TRUE & valve_22 = TRUE & valve_1 = TRUE & valve_2 = TRUE & valve_4 = TRUE & valve_5 = TRUE & valve_28 = TRUE) |
						 (valve_19 = TRUE & valve_23 = TRUE & valve_22 = TRUE & valve_1 = TRUE & valve_2 = TRUE & valve_4 = TRUE & valve_5 = TRUE & valve_28 = TRUE))) then
		systemProperties := FALSE;
	endif;
end;

procedure pump_2_failure();
begin
	if (pump_2 = TRUE & !((valve_25 = TRUE & valve_28 = TRUE) |
						  (valve_25 = TRUE & valve_5 = TRUE & valve_6 = TRUE) |
						  (valve_25 = TRUE & valve_5 = TRUE & valve_4 = TRUE & valve_2 = TRUE & valve_1 = TRUE & valve_3 = TRUE))) then
		systemProperties := FALSE;
	endif;
end;

/* End invarianti */


/* Check the system properties (invariants) */
procedure dynamic_check();
begin
	heater_5_failure();
	cooling_failure();
	
	flow_b1_failure();
	flow_b2_failure();
	flow_b3_failure();
	flow_b4_failure();
	flow_b5_failure();
	flow_b6_failure();
	flow_b7_failure();
	
	level_b1_failure();
	level_b2_failure();
	level_b3_failure();
	level_b4_failure();
	level_b5_failure();
	level_b6_failure();
	level_b7_failure();
	
	pump_1_failure();
	pump_2_failure();
	
end;

/* Safety conditions (see the paper "An Abstract Model of VHS Case Study 1 (Experimental Batch Plant)" sect. 3 pag. 28) */
function IsSafety() : boolean;
begin
	return (valve_1 = FALSE &
			valve_2 = FALSE &
			valve_3 = FALSE &
			valve_4 = FALSE &
			valve_5 = FALSE &
			valve_6 = FALSE &
			valve_7 = FALSE &
			valve_8 = FALSE &
			valve_9 = FALSE &
			valve_10 = FALSE &
			valve_11 = FALSE &
			valve_12 = FALSE &
			valve_13 = FALSE &
			valve_14 = FALSE &
			valve_15 = FALSE &
			valve_16 = FALSE &
			valve_17 = FALSE &
			valve_18 = FALSE &
			valve_19 = FALSE &
			valve_20 = FALSE &
			valve_21 = FALSE &
			valve_22 = FALSE &
			valve_23 = FALSE &
			valve_24 = FALSE &
			valve_25 = FALSE &
			valve_26 = FALSE &
			valve_27 = FALSE &
			valve_28 = FALSE &
			valve_29 = FALSE &
			pump_1 = FALSE &
			pump_2 = FALSE);
end;

function IsOK() : boolean;
begin
	if(systemProperties = FALSE) then
		return FALSE;
	endif;
	if (filling_b1_done = TRUE & filling_b2_done = TRUE & concentration_reached = TRUE & isGoal_part = TRUE & IsSafety()) then
		isGoal_final := TRUE;
		return FALSE;
	else
		if(concentration_reached = TRUE & filling_b3_done = TRUE & valve_11 = FALSE & filling_b4_done = FALSE & level_b3 < LEVEL_TARGET) then
			return FALSE;
		else
			if(concentration_reached = TRUE & filling_b3_done = TRUE & valve_11 = FALSE & filling_b4_done = FALSE & level_b3 >= LEVEL_TARGET) then
				isGoal_part := TRUE;
			endif;
			return TRUE;
		endif;		
	endif;
end;

/* Derive the new state */

procedure compute_new_state();
var 	
	temp_c_1 : real_type;
	temp_c_2 : real_type;
	temp_c_3 : real_type;
	temp_c_5 : real_type;
	
	temp_T_5 : real_type;
	temp_T_6 : real_type;
	temp_T_7 : real_type;
	
	temp_level_b1 : real_type;
	temp_level_b2 : real_type;
	temp_level_b3 : real_type;
	temp_level_b4 : real_type;
	temp_level_b5 : real_type;
	temp_level_b6 : real_type;
	temp_level_b7 : real_type;

	temp_flow : real_type;
	
begin
	temp_level_b1 := level_b1;
	temp_level_b2 := level_b2;
	temp_level_b3 := level_b3; 
	temp_level_b4 := level_b4;
	temp_level_b5 := level_b5;
	temp_level_b6 := level_b6;
	temp_level_b7 := level_b7;
	
	temp_c_1 := c_1;
	temp_c_2 := c_2;
	temp_c_3 := c_3;
	temp_c_5 := c_5;
	
	temp_T_5 := T_5;
	temp_T_6 := T_6;
	temp_T_7 := T_7;
	
	temp_flow := 0;
	
	/* Cyclic phase */
	
	-- B1 -> B3
	if(valve_8 = TRUE) then
		temp_flow := cyclic_level_b1_b3(level_b1, STEP_TIME);
		if(temp_flow >= level_b1) then
			temp_level_b1 := 0;
			temp_level_b3 := level_b3 + level_b1;
		else
			temp_level_b1 := level_b1 - temp_flow;
			temp_level_b3 := level_b3 + temp_flow;
		endif;
		temp_c_3 := c_1;
	endif;
	
	-- B2 -> B3
	if(valve_9 = TRUE) then
		temp_flow := cyclic_level_b2_b3(level_b2, STEP_TIME);
		if(temp_flow >= level_b2) then
			temp_level_b2 := 0;
			temp_level_b3 := level_b3 + level_b2;
		else
			temp_level_b2 := level_b2 - temp_flow;
			temp_level_b3 := level_b3 + temp_flow;
		endif;
		temp_c_3 := cyclic_concentration_b3_in_b2(c_3, c_2, level_b2, level_b2, STEP_TIME);
	endif;
	
	-- B3 -> OUT
	if(valve_10 = TRUE & valve_19 = TRUE & valve_27) then
		temp_flow := STEP_TIME * 0.2; -- DA MODIFICARE
		if(temp_flow >= level_b3) then
			temp_level_b3 := 0;
		else
			temp_level_b3 := level_b3 - temp_flow;
		endif;
	endif;
	
	-- B3 -> B4
	if(valve_11 = TRUE) then
		temp_flow := cyclic_level_b3_b4(level_b3, STEP_TIME);
		if(temp_flow >= level_b3) then
			temp_level_b3 := 0;
			temp_level_b4 := level_b4 + level_b3;
		else
			temp_level_b3 := level_b3 - temp_flow;
			temp_level_b4 := level_b4 + temp_flow;
		endif;
	endif;
	
	-- B4 -> B5
	if(valve_12 = TRUE) then
		temp_flow := cyclic_level_b4_b5(level_b4, STEP_TIME);
		if(temp_flow >= level_b4) then
			temp_level_b4 := 0;
			temp_level_b5 := level_b5 + level_b4;
		else
			temp_level_b4 := level_b4 - temp_flow;
			temp_level_b5 := level_b5 + temp_flow;
		endif;	
	endif;
	
	-- B5 -> B7
	if(valve_15 = TRUE) then
		temp_T_7 := T_5;
		temp_flow := cyclic_level_b5_b7(level_b5, STEP_TIME);
		if(temp_flow >= level_b5) then
			temp_level_b5 := 0;
			temp_level_b7 := level_b7 + level_b5;
		else
			temp_level_b5 := level_b5 - temp_flow;
			temp_level_b7 := level_b7 + temp_flow;
		endif;		
		
	endif;

	-- Heating until boiling temperature
	if(heater_5 = TRUE & T_5 < 100.0) then
		temp_T_5 := cyclic_temperature_b5(T_5, level_b5, STEP_TIME);
	endif;
	
	-- Evaporation
	if(T_5 >= 100.0 & heater_5 = TRUE) then
		temp_level_b5 := cyclic_level_b5_out_b6(level_b5, STEP_TIME);
		temp_level_b6 := cyclic_level_b6_in_b5(level_b6, STEP_TIME);
		temp_c_5 := cyclic_concentration_b5(c_5, level_b5, STEP_TIME);
	endif;
	
	if(T_5 >= 100 & heater_5 = TRUE) then
		temp_T_5 := cyclic_temperature_b_5(T_5, STEP_TIME);
	endif;
	
	-- B7 -> B1
	if(pump_1 = TRUE & valve_18 = TRUE & valve_23 =TRUE & valve_22 & valve_1 = TRUE & valve_3 = TRUE) then
		temp_flow := cyclic_level_b7_b1(level_b7, STEP_TIME);
		if(temp_flow >= level_b7) then
			temp_level_b7 := 0;
			temp_level_b1 := level_b1 + level_b7;
		else
			temp_level_b7 := level_b7 - temp_flow;
			temp_level_b1 := level_b1 + temp_flow;
		endif;
	endif;
	
	-- B6 -> B2
	if(pump_2 = TRUE & valve_20 = TRUE & valve_24 = TRUE & valve_25 = TRUE & valve_5 = TRUE & valve_6 = TRUE) then
		temp_flow := cyclic_level_b6_b2(level_b6, STEP_TIME);
		if(temp_flow >= level_b6) then
			temp_level_b6 := 0;
			temp_level_b2 := level_b2 + level_b6;
		else
			temp_level_b6 := level_b6 - temp_flow;
			temp_level_b2 := level_b2 + temp_flow;
		endif;
	endif;
	
	-- Cooling B6
	if(valve_29 = TRUE) then
		temp_T_6 := cyclic_temperature_b6(T_6, level_b6, STEP_TIME);
	endif;
	
	-- Cooling B7
	if(valve_17 = TRUE) then
		temp_T_7 := cyclic_temperature_b7(T_7, level_b7, STEP_TIME);
	endif;
	
	if (IsOK()) then
		level_b1 := temp_level_b1;
		level_b2 := temp_level_b2;
		level_b3 := temp_level_b3; 
		level_b4 := temp_level_b4;
		level_b5 := temp_level_b5;
		level_b6 := temp_level_b6;
		level_b7 := temp_level_b7;
		c_1 := temp_c_1;
		c_2 := temp_c_2;
		c_3 := temp_c_3;
		c_5 := temp_c_5;
	
		T_5 := temp_T_5;
		T_6 := temp_T_6;
		T_7 := temp_T_7;
		
		time := time + STEP_TIME;
	endif;
end;

/* Initial state: see the paper "An Abstract Model of VHS Case Study 1 (Experimental Batch Plant)", sect. 3 "The Properties" pag. 28 */
/* For the initial tank levels and solution concentrations see the paper "Description of case study CS1 "Experimental Batch Plant"", sect. 3 pag. 3 */
startstate "startstate 0 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 4.0 ;
 end;
 startstate "startstate 1 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 4.26 ;
 end;
 startstate "startstate 2 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 4.52 ;
 end;
 startstate "startstate 3 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 4.78 ;
 end;
 startstate "startstate 4 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 5.04 ;
 end;
 startstate "startstate 5 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 5.3 ;
 end;
 startstate "startstate 6 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 5.56 ;
 end;
 startstate "startstate 7 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 5.82 ;
 end;
 startstate "startstate 8 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 6.08 ;
 end;
 startstate "startstate 9 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 6.34 ;
 end;
 startstate "startstate 10 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 6.6 ;
 end;
 startstate "startstate 11 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 6.86 ;
 end;
 startstate "startstate 12 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 7.12 ;
 end;
 startstate "startstate 13 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 7.38 ;
 end;
 startstate "startstate 14 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 7.64 ;
 end;
 startstate "startstate 15 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 7.9 ;
 end;
 startstate "startstate 16 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 8.16 ;
 end;
 startstate "startstate 17 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 8.42 ;
 end;
 startstate "startstate 18 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 8.68 ;
 end;
 startstate "startstate 19 " valve_1 := FALSE;
 valve_2 := FALSE;
  valve_3 := FALSE;
 valve_4 := FALSE;
 valve_5 := FALSE;
 valve_6 := FALSE;
 valve_7 := FALSE;
 valve_8 := FALSE;
 valve_9 := FALSE;
 valve_10 := FALSE;
 valve_11 := FALSE;
 valve_12 := FALSE;
 valve_13 := FALSE;
 valve_14 := FALSE;
 valve_15 := FALSE;
 valve_16 := FALSE;
 valve_17 := FALSE;
 valve_18 := FALSE;
 valve_19 := FALSE;
 valve_20 := FALSE;
 valve_21 := FALSE;
 valve_22 := FALSE;
 valve_23 := FALSE;
 valve_24 := FALSE;
 valve_25 := FALSE;
 valve_26 := FALSE;
 valve_27 := FALSE;
 valve_28 := FALSE;
 valve_29 := FALSE;
  filling_b3_done := FALSE;
 concentration_reached := FALSE;
 get_production_done := FALSE;
 filling_b4_done := FALSE;
 filling_b5_done := FALSE;
 high_concentration_reached := FALSE;
 filling_b7_done := FALSE;
 cooled_b6 := FALSE;
 cooled_b7 := FALSE;
 filling_b1_done := FALSE;
 filling_b2_done := FALSE;
 pump_1 := FALSE;
 pump_2 := FALSE;
 heater_5 := FALSE;
  c_1 := START_CONCENTRATION_B1;
 c_2 := 0;
 c_3 := 0;
 c_5 := 0;
  T_5 := 25;
 T_6 := 25;
 T_7 := 25;
  level_b1 := START_LEVEL_B1;
 level_b2 := START_LEVEL_B2;
 level_b3 := 0;
 level_b3_recycle := 0;
 level_b4 := 0;
 level_b5 := 0;
 level_b6 := 0;
 level_b7 := 0;
  time := 0;
 isGoal_part := FALSE;
 isGoal_final := FALSE;
 systemProperties := TRUE;
 LEVEL_TARGET := 8.94 ;
 end;
 
 

rule "controller_valve_8_open" (valve_8 = FALSE & level_b3 = 0.0 & level_b1 > 0.0 & filling_b3_done = FALSE           & valve_3 = FALSE & valve_10 = FALSE & valve_11 = FALSE) ==> -- inizia la parte invariante
begin
	dynamic_check();
	valve_8 := TRUE;
	compute_new_state();
end;

rule "controller_valve_8_close" (valve_8 = TRUE) ==> --level_b3 > LEVEL_TARGET_MIN & 
begin
	dynamic_check();
	valve_8 := FALSE;
	filling_b3_done := TRUE;
	compute_new_state();
end;

rule "controller_valve_9_open" (valve_9 = FALSE & filling_b3_done = TRUE & concentration_reached = FALSE           & valve_6 = FALSE & valve_7 = FALSE & valve_10 = FALSE & valve_11 = FALSE) ==> -- inizia la parte invariante
begin
	dynamic_check();
	valve_9 := TRUE;
	compute_new_state();
end;

rule "controller_valve_9_close" (level_b3 >= LEVEL_TARGET & c_3 <= CONCENTRATION_TARGET & valve_9 = TRUE) ==>
begin
	dynamic_check();
	valve_9 := FALSE;
	concentration_reached := TRUE;
	level_b3_recycle := level_b3 - LEVEL_TARGET;
	compute_new_state();
end;

/* START RULES ADDED TO PARTIALLY EMPTY TANK 3 */

rule "controller_valve_10_open" (get_production_done = FALSE & filling_b3_done = TRUE & level_b3 >= LEVEL_TARGET & concentration_reached = TRUE & valve_10 = FALSE & valve_19 = FALSE & valve_27 = FALSE & get_production_done = FALSE           & valve_8 = FALSE & valve_9 = FALSE & valve_12 = FALSE) ==>
begin
	dynamic_check();
	valve_10 := TRUE;
	valve_19 := TRUE;
	valve_27 := TRUE;
	compute_new_state()
end;

rule "controller_valve_10_close" (valve_10 = TRUE & valve_19 = TRUE & valve_27 = TRUE & level_b3 <= level_b3_recycle)  ==>
begin
	dynamic_check();
	valve_10 := FALSE;
	valve_19 := FALSE;
	valve_27 := FALSE;
	get_production_done := TRUE;
	compute_new_state()
end;



rule "controller_valve_11_open" (get_production_done = TRUE & valve_11 = FALSE & filling_b4_done = FALSE           & valve_8 = FALSE & valve_9 = FALSE & valve_12 = FALSE) ==> -- inizia la parte invariante
begin
	dynamic_check();
	valve_11 := TRUE;
	compute_new_state();
end;

/* END RULES ADDED TO PARTIALLY EMPTY TANK 3 */

rule "controller_valve_11_close" (level_b3 = 0.0 & valve_11 = TRUE) ==>
begin
	dynamic_check();
	valve_11 := FALSE;
	filling_b4_done := TRUE;
	compute_new_state();
end;

rule "controller_valve_12_open" (valve_12 = FALSE & filling_b4_done = TRUE & filling_b5_done = FALSE           & valve_11 = FALSE & valve_15 = FALSE & valve_16 = FALSE) ==> -- inizia la parte invariante
begin
	dynamic_check();
	valve_12 := TRUE;
	c_5 := c_3;
	compute_new_state();
end;

rule "controller_valve_12_close" (level_b4 = 0.0 & valve_12 = TRUE) ==>
begin
	dynamic_check();
	valve_12 := FALSE;
	filling_b5_done := TRUE;
	compute_new_state();
end;

rule "controller_valve_15_open" (high_concentration_reached = TRUE &  valve_15 = FALSE & filling_b7_done = FALSE & heater_5 = FALSE           & valve_12 = FALSE & valve_18 = FALSE) ==> -- inizia la parte invariante
begin
	dynamic_check();
	valve_15 := TRUE;
	compute_new_state();
end;

rule "controller_valve_15_close" (level_b5 = 0.0 & valve_15 = TRUE) ==>
begin
	dynamic_check();
	valve_15 := FALSE;
	T_5 := 25.0;
	filling_b7_done := TRUE;
	compute_new_state();
end;

rule "controller_valve_17_open" (filling_b7_done = TRUE & cooled_b7 = FALSE & valve_17 = FALSE          & (valve_13 = FALSE | valve_29 = FALSE)) ==> -- inizia la parte invariante
begin
	dynamic_check();
	valve_17 := TRUE;
	compute_new_state();
end;

rule "controller_valve_17_close" (T_7 <= 25.0 & valve_17 = TRUE) ==>
begin
	dynamic_check();
	valve_17 := FALSE;
	cooled_b7 := TRUE;
	compute_new_state();
end;

rule "controller_valve_29_open" (high_concentration_reached = TRUE & heater_5 = FALSE & level_b6 > 0 & cooled_b6 = FALSE & valve_29 = FALSE          & (valve_13 = FALSE | valve_17 = FALSE)) ==> -- inizia la parte invariante
begin
	dynamic_check();
	valve_29 := TRUE;
	compute_new_state();
end;

rule "controller_valve_29_close" (T_6 <= 25.0 & valve_29 = TRUE) ==>
begin
	dynamic_check();
	valve_29 := FALSE;
	cooled_b6 := TRUE;
	compute_new_state();
end;

rule "group_valve_open_pump_1_on" (cooled_b7 = TRUE & pump_1 = FALSE & level_b7 > 0 & valve_15 = FALSE) ==>
begin
	dynamic_check();
	valve_1 := TRUE;
	valve_3 := TRUE;
	valve_18 := TRUE;
	valve_22 := TRUE;
	valve_23 := TRUE;
	pump_1 := TRUE;
	compute_new_state();
end;

rule "group_valve_close_pump_1_off" (level_b7 = 0.0 & valve_1 = TRUE & valve_3 = TRUE & valve_18 = TRUE & valve_22 = TRUE & valve_23 =TRUE) ==>
begin
	dynamic_check();
	valve_1 := FALSE;
	valve_3 := FALSE;
	valve_18 := FALSE;
	valve_22 := FALSE;
	valve_23 := FALSE;
	pump_1 := FALSE;
	filling_b1_done := TRUE;
	T_7 := 25.0;
	compute_new_state();
end;

rule "group_valve_open_pump_2_on" (cooled_b6 = TRUE & pump_2 = FALSE & level_b6 > 0 & high_concentration_reached = TRUE) ==>
begin
	dynamic_check();
	valve_5 := TRUE;
	valve_6 := TRUE;
	valve_20 := TRUE;
	valve_24 := TRUE;
	valve_25 := TRUE;
	pump_2 := TRUE;
	compute_new_state();
end;

rule "group_valve_close_pump_2_off" (level_b6 = 0.0 & pump_2 = TRUE & valve_5 = TRUE & valve_6 = TRUE & valve_20 = TRUE & valve_24 = TRUE & valve_25 =TRUE) ==>
begin
	dynamic_check();
	valve_5 := FALSE;
	valve_6 := FALSE;
	valve_20 := FALSE;
	valve_24 := FALSE;
	valve_25 := FALSE;
	pump_2 := FALSE;
	filling_b2_done := TRUE;
	T_6 := 25.0;
	compute_new_state();
end;

rule "group_controller_heater_on_valve_13_open" (heater_5 = FALSE & valve_13 = FALSE & filling_b5_done = TRUE & high_concentration_reached = FALSE           & level_b5 > LEVEL_B5_SAFETY & valve_12 = FALSE & valve_15 = FALSE & valve_16 = FALSE &  (valve_17 = FALSE | valve_29 = FALSE)) ==> -- inizia la parte invariante
begin
	dynamic_check();
	valve_13 := TRUE;
	heater_5 := TRUE;
	compute_new_state();
end;

rule "group_controller_heater_off_valve_13_close" (c_5 >= CONCENTRATION_MAX & valve_13 = TRUE & heater_5 = TRUE) ==> -- c_5 >= CONCENTRATION_MAX &
begin
	dynamic_check();
	heater_5 := FALSE;
	valve_13 := FALSE;
	high_concentration_reached := TRUE;
	T_6 := 99; -- DA CONTROLLARE
	compute_new_state();
end;



rule "wait_filling_b3" (valve_8 = TRUE & level_b1 > 0) ==> --level_b3 <= LEVEL_TARGET_MIN & 
begin
	dynamic_check();
	compute_new_state();
end;

rule "wait_diluition_b3" (c_3 >= CONCENTRATION_TARGET & valve_9 = TRUE & level_b2 > 0) ==>
begin
	dynamic_check();
	compute_new_state();
end;

/* START RULES ADDED TO PARTIALLY EMPTY TANK 3 */

rule "wait_empting_b3" (valve_10 = TRUE & valve_19 = TRUE & valve_27 = TRUE) ==>
begin
	dynamic_check();
	compute_new_state();
end;

/* END RULES ADDED TO PARTIALLY EMPTY TANK 3 */

rule "wait_filling_b4" (valve_11 = TRUE & level_b3 > 0) ==>
begin
	dynamic_check();
	compute_new_state();
end;

rule "wait_filling_b5" (valve_12 = TRUE & level_b4 > 0) ==>
begin
	dynamic_check();
	compute_new_state();
end;

rule "wait_evaporation_b5" (heater_5 = TRUE & valve_13 = TRUE & c_5 < CONCENTRATION_MAX) ==>
begin
	dynamic_check();
	compute_new_state();
end;

rule "wait_filling_b7" (valve_15 = TRUE & level_b5 > 0) ==>
begin
	dynamic_check();
	compute_new_state();
end;

rule "wait_cooling_b7" (T_7 > 25.0 & valve_17 = TRUE) ==>
begin
	dynamic_check();
	compute_new_state();
end;

rule "wait_cooling_b6" (T_6 > 25.0 & valve_29 = TRUE) ==>
begin
	dynamic_check();
	compute_new_state();
end;

rule "wait_filling_b1" (level_b7 > 0 & valve_18 = TRUE & valve_23 = TRUE & valve_22 = TRUE & valve_1 = TRUE & valve_3 = TRUE & pump_1 = TRUE) ==>
begin
	dynamic_check();
	compute_new_state();
end;

rule "wait_filling_b2" (level_b6 > 0 & valve_20 = TRUE & valve_24 = TRUE & valve_25 = TRUE & valve_5 = TRUE & valve_6 = TRUE & pump_2 = TRUE) ==>
begin
	dynamic_check();
	compute_new_state();
end;

/* Goal */

goal "goal"
	(isGoal_final = TRUE & systemProperties = TRUE);

--invariant "everything going right"(systemProperties);

metric: minimize;


	
/* End Goal */
