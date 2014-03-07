-- NOTES
-- The model semantics has some differences wrt the PDDL+ version:
-- 1) predicate available_unit has been removed
-- 2) the action fullprepare_start and the pair (obs1prepare_start, obs2prepare_start) are now mutually exclusive
-- 3) each start action has a new precondition: for action prepare_obs1, the precondition is !ready_for_obs1

-- N.B. in this model, action FullPrepare costs (in energy terms) more than the sum of prepareobs1 and prepareobs2, but
-- requires less time to be executed.

type
  int_type:0..1000; 
  real_type : real(4,5);  
  
const
	T:0.1;		-- time discretization
	
	solar_const : 0.03;	-- if < 1 slows down energy loading
	safelevel : 15.0;	-- minimal percentage of battery power: below this level, the plan is aborted
	dawn : 3.0;		
	dusk : 9.0;
	heater_rate: 15.1;	-- if >1 increases the battery discharging during the night
	commsopen_deadline: 10; -- limit time (daytime) for the plan to complete (implements the PDDL+ timed initial literal)
	d_rate : 1.5;	-- not used in the original PDDL
	c_rate : 2.5;	-- "demand" cost of action prepareobs2 
	b_rate : 2.0;	-- "demand" cost of action prepareobs1 
	a_rate : 4.0;	-- "demand" cost of action fullprepare 
	obs1_rate : 4.0;
	obs2_rate : 5.0;
	observe1_durtime: 7.0;
	observe2_durtime: 7.5;
	prepareobs1_durtime:1.0;
	prepareobs2_durtime:1.5;
	fullprepare_durtime:3.2;
	charge_rate:0.0095;
var	
	
	
	observe2_clock : real_type;
	observe2_clock_started : boolean;
	observe1_clock : real_type;
	observe1_clock_started : boolean;
	prepareobs2_clock : real_type;
	prepareobs2_clock_started : boolean;
	prepareobs1_clock : real_type;
	prepareobs1_clock_started : boolean;
	fullprepare_clock : real_type;
	fullprepare_clock_started : boolean;
	daytime [pddlname: "daytime";] : real_type;
	soc [pddlname: "soc";] : real_type;
	supply [pddlname: "supply";] : real_type;
	demand [pddlname: "demand";] : real_type;
	observe_complete_value : 0..2 ;
	gotobs2_value : boolean ;
	gotobs1_value : boolean ;
	ready_value : boolean ;
	readyforobs2_value : boolean ;
	readyforobs1_value : boolean ;
	commsopen_value : boolean ;
	day_value : boolean ;
	all_event_true : boolean;
	busy: boolean;
	
	
externfun night_op_ext(a:real_type; b:real_type;c:real_type;) : real_type "planety_lib.h";
externfun generating_ext(a:real_type; b:real_type; c:real_type; d:real_type;) : real_type;
externfun discharging_ext(a:real_type; b:real_type; c:real_type; d:real_type;) : real_type;
externfun charging_ext(a:real_type; b:real_type; c:real_type; d:real_type; e:real_type;) : real_type;

function observe_complete():boolean;
	begin
	IF (observe_complete_value = 2) THEN
		return true;
	ENDIF;
	return false;
end;


procedure fail();
	begin
	IF (soc<safelevel) THEN
		all_event_true:=false;
	ENDIF;
end;

procedure set_gotobs2( value:boolean );
	begin
	gotobs2_value := value;
	end;

function gotobs2():boolean;
	begin
	return gotobs2_value;
	end;
procedure set_gotobs1( value:boolean );
	begin
	gotobs1_value := value;
	end;

function gotobs1():boolean;
	begin
	return gotobs1_value;
	end;
procedure set_ready( value:boolean );
	begin
	ready_value := value;
	end;

function ready():boolean;
	begin
	return ready_value;
	end;
procedure set_readyforobs2( value:boolean );
	begin
	readyforobs2_value := value;
	end;

function readyforobs2():boolean;
	begin
	return readyforobs2_value;
	end;
procedure set_readyforobs1( value:boolean );
	begin
	readyforobs1_value := value;
	end;

function readyforobs1():boolean;
	begin
	return readyforobs1_value;
	end;
procedure set_commsopen( value:boolean );
	begin
	commsopen_value := value;
	end;

function commsopen():boolean;
	begin
	return commsopen_value;
	end;
procedure set_day( value:boolean );
	begin
	day_value := value;
	end;

function day():boolean;
	begin
	return day_value;
	end;




procedure process_observe2();
begin
	IF ((observe2_clock_started) ) THEN 
		observe2_clock := observe2_clock + T ;
	ENDIF;
end;

procedure event_observe2_failure();
begin
	IF (  !( !commsopen() & (soc>safelevel)) & (observe2_clock_started) & (observe2_clock!=observe2_durtime) ) THEN
		 observe2_clock := observe2_durtime + T;
		 all_event_true:=false;
			ENDIF;
end;

procedure process_observe1();
begin
	IF ((observe1_clock_started) ) THEN 
		observe1_clock := observe1_clock + T ;
	ENDIF;
end;

procedure event_observe1_failure();
begin
	IF ( !( !commsopen() & (soc>safelevel)) & (observe1_clock_started) & (observe1_clock!=observe1_durtime)) THEN 
	 observe1_clock := observe1_durtime + T;
	 all_event_true:=false;
	ENDIF;
end;

procedure process_prepareobs2();
begin
	IF ((prepareobs2_clock_started) ) THEN 
		prepareobs2_clock := prepareobs2_clock + T ;
	ENDIF;
end;

procedure event_prepareobs2_failure();
begin
	IF (!(soc>safelevel) & (prepareobs2_clock_started) & (prepareobs2_clock!=prepareobs2_durtime) ) THEN 
	 prepareobs2_clock := prepareobs2_durtime + T;
	 all_event_true:=false;
			ENDIF;
end;

procedure process_prepareobs1();
begin
	IF ((prepareobs1_clock_started) ) THEN 
		prepareobs1_clock := prepareobs1_clock + T ;
	ENDIF;
end;

procedure event_prepareobs1_failure();
begin
	IF (!(soc>safelevel) & (prepareobs1_clock_started) & (prepareobs1_clock!=prepareobs1_durtime)) THEN 
	prepareobs1_clock := prepareobs1_durtime + T;
	all_event_true:=false;
			ENDIF;
end;

procedure process_fullprepare();
begin
	IF ((fullprepare_clock_started) ) THEN 
		fullprepare_clock := fullprepare_clock + T ;
	ENDIF;
end;

procedure event_fullprepare_failure();
begin
	IF (!(soc>safelevel) & (fullprepare_clock_started) & (fullprepare_clock!=fullprepare_durtime)) THEN 
	fullprepare_clock := fullprepare_durtime + T;
	all_event_true:=false;
			ENDIF;
end;

procedure daybreak();
begin
	IF (daytime>=0 & !(day()) ) THEN 
		set_day(true);
	ENDIF;
end;

procedure nightfall();
begin
	IF (daytime>=dusk & (day()) ) THEN 
		daytime := -dawn ;
		set_day(false);
	ENDIF;
end;

procedure night_operations();
begin
	IF (!(day()) ) THEN 
		daytime := daytime + T;
		soc := night_op_ext(soc,heater_rate,T);		
		--soc := soc - heater_rate*T;
	ENDIF;
end;

procedure generating();
begin
	IF ((day()) ) THEN
		--supply := supply + ((solar_const * daytime) * (((daytime * ((4 * daytime)-90) ) )+450) * T);
		--supply := supply + (( (solar_const*daytime) * ((((4*daytime)-90)*daytime)+450))	*T);		 
		supply := generating_ext(supply,solar_const,daytime,T);		
		daytime := daytime + T;
	ENDIF;
end;

procedure discharging();
begin
	IF (demand>supply ) THEN 
	 --soc := soc - (T * (demand - supply));
	soc := discharging_ext(soc,demand,supply,T);
			ENDIF;
end;

procedure charging();
begin
	IF (demand<supply & day() & soc<100) THEN 
	-- soc := soc + (T * (supply - demand) * charge_rate * (100 - soc));
	soc := charging_ext(demand,supply,soc,charge_rate,T)
			ENDIF;
	IF (soc >100) THEN
	 soc := 100;
	ENDIF;
end;

function inbound():boolean;
begin
	return (soc>=0.0 & soc<=100.0 & demand>=0.0 & supply>=0.0);
	--return true;
end;

-- MODELS THE PDDL+ TIMED INITIAL LITERAL. Requires the lander to complete the plan before daytime reaches 8
procedure timed_initial_literals();
begin
 IF (daytime >= commsopen_deadline ) THEN
 set_commsopen(true);
 ENDIF;
end;

-- events can happen at any time and have zero duration
-- processes are executed at each clock cycle, and update the state

procedure dynamic_check_riold();
 fail();
 daybreak();
 nightfall();
 generating(); 
 charging();
 discharging();
 night_operations();
 timed_initial_literals();
 process_observe2();
 event_observe2_failure();
 process_observe1();
 event_observe1_failure();
 process_prepareobs2();
 event_prepareobs2_failure();
 process_prepareobs1();
 event_prepareobs1_failure();
 process_fullprepare();
 event_fullprepare_failure();

end;


procedure dynamic_check_old();
 fail();
 timed_initial_literals();
 process_observe2();
 event_observe2_failure();
 process_observe1();
 event_observe1_failure();
 process_prepareobs2();
 event_prepareobs2_failure();
 process_prepareobs1();
 event_prepareobs1_failure();
 process_fullprepare();
 event_fullprepare_failure();
 daybreak();
 nightfall();
 night_operations();
 generating();
 discharging();
 charging();

end;


procedure fire_events();
 fail();
 daybreak();
 nightfall();

 timed_initial_literals();
 event_observe2_failure();
 event_observe1_failure();
 event_prepareobs2_failure();
 event_prepareobs1_failure();
 event_fullprepare_failure();

end;

procedure update_processes();
 generating(); 
 charging();
 discharging();
 night_operations();

 process_observe2();
 process_observe1();
 process_prepareobs2();
 process_prepareobs1();
 process_fullprepare();

end;

 startstate "99" 
 begin 
 all_event_true := true; 
 set_ready(true); 
observe2_clock_started := false; 
 observe2_clock := 0.0; 
 observe1_clock_started := false; 
 observe1_clock := 0.0; 
 prepareobs2_clock_started := false; 
 prepareobs2_clock := 0.0; 
 prepareobs1_clock_started := false; 
 prepareobs1_clock := 0.0; 
 fullprepare_clock_started := false; 
 fullprepare_clock := 0.0; 
 observe_complete_value := 0; 
 observe_complete_value:=0; 
 gotobs2_value:=false; 
 gotobs1_value:=false; 
 readyforobs2_value:=false; 
 readyforobs1_value:=false; 
 commsopen_value:=false; 
 daytime:= 4.5; 
 busy:= false; 
 set_day(true); 
 soc:= 93; 
 supply:=0; 
 demand:=0; 
 end; 
  

clock rule "time_passing"
(true & daytime>=-10 & daytime<=10 & soc>=0 & soc<=100 & inbound() & observe1_clock <= observe1_durtime &
observe2_clock <= observe2_durtime & prepareobs1_clock <= prepareobs1_durtime & prepareobs2_clock <= prepareobs2_durtime) ==>
begin
		fire_events();
		update_processes();		
end;

durative_end rule"observe2_end"
(observe2_clock_started & observe2_clock=observe2_durtime & inbound() & busy) ==> 
pddlname: "observe2";
begin
	--dynamic_check();
			fire_events();
	demand := demand - obs2_rate ;
	set_readyforobs2(false);
	set_gotobs2(true);
	observe2_clock := observe2_clock - T ;
	observe2_clock_started := false ;
	observe_complete_value := observe_complete_value + 1;
	busy := false;
	
end;

durative_start rule"observe2_start"
(readyforobs2()) & (!observe2_clock_started) & !gotobs2()& inbound() & !busy  ==> 
pddlname: "observe2";
begin
	--dynamic_check();
			fire_events();
	set_ready(false);
	demand := demand + obs2_rate ;
	observe2_clock := observe2_clock + T ;
	--observe2_clock := 0.1 ;
	observe2_clock_started := true ;
	busy := true;
	
end;

durative_end rule"observe1_end"
(observe1_clock_started & observe1_clock=observe1_durtime) & inbound() & busy ==> 
pddlname: "observe1";
begin
	--dynamic_check();
			fire_events();
	demand := demand - obs1_rate ;
	set_readyforobs1(false);
	set_gotobs1(true);
	observe1_clock := observe1_clock - T ;
	observe1_clock_started := false ;
	observe_complete_value := observe_complete_value + 1;
	busy := false;
	
end;

durative_start rule"observe1_start"
(readyforobs1()) & (!observe1_clock_started)& !gotobs1() & inbound() & !busy ==> 
pddlname: "observe1";
begin
	--dynamic_check();
			fire_events();
	set_ready(false);
	demand := demand + obs1_rate ;
	observe1_clock := observe1_clock + T ;
	--observe1_clock := 0.1 ;
	observe1_clock_started := true ;
	busy := true;
	
end;

durative_end rule"prepareobs2_end"
(prepareobs2_clock_started & prepareobs2_clock=prepareobs2_durtime & inbound() & busy) ==> 
pddlname: "prepareobs2";
begin
	--dynamic_check();
			fire_events();
	demand := demand - c_rate ;
	set_readyforobs2(true);
	prepareobs2_clock := prepareobs2_clock - T ;
	prepareobs2_clock_started := false ;
	busy := false;
	
end;

durative_start rule"prepareobs2_start"
(!prepareobs2_clock_started & !fullprepare_clock_started  & !readyforobs2() & !gotobs2() & inbound() & !busy) ==> 
pddlname: "prepareobs2";
begin
	--dynamic_check();
			fire_events();
	set_ready(false);
	demand := demand + c_rate ;
	prepareobs2_clock := prepareobs2_clock + T ;
	--prepareobs2_clock := 0.1 ;
	prepareobs2_clock_started := true ;
	busy := true;
	
end;

durative_end rule"prepareobs1_end"
(prepareobs1_clock_started & prepareobs1_clock=prepareobs1_durtime & inbound() & busy) ==> 
pddlname: "prepareobs1";
begin
	--dynamic_check();
			fire_events();
	demand := demand - b_rate ;
	set_readyforobs1(true);
	prepareobs1_clock := prepareobs1_clock - T ;
	prepareobs1_clock_started := false ;
	busy := false;
	
end;

durative_start rule"prepareobs1_start"
(!prepareobs1_clock_started & !fullprepare_clock_started  & !readyforobs1() & !gotobs1() & inbound() & !busy) ==> 
pddlname: "prepareobs1";
begin
	--dynamic_check();
			fire_events();
	set_ready(false);
	demand := demand + b_rate ;
	prepareobs1_clock := prepareobs1_clock + T ;
	--prepareobs1_clock := 0.1 ;
	prepareobs1_clock_started := true ;
	busy := true;
	
end;

durative_end rule"fullprepare_end"
(fullprepare_clock_started & fullprepare_clock=fullprepare_durtime & inbound() & busy) ==> 
pddlname: "fullprepare";
begin
	--dynamic_check();
			fire_events();
	demand := demand - a_rate ;
	set_readyforobs1(true);
	set_readyforobs2(true);
	fullprepare_clock := fullprepare_clock - T ;
	fullprepare_clock_started := false ;
	busy := false;
end;

durative_start rule"fullprepare_start"
(!fullprepare_clock_started & !prepareobs1_clock_started & !prepareobs2_clock_started  & !readyforobs1() & !readyforobs2() & inbound() & !busy) ==> 
pddlname: "fullprepare";
begin
	--dynamic_check();
			fire_events();
	set_ready(false);
	demand := demand + a_rate ;
	fullprepare_clock := fullprepare_clock + T ;
	--fullprepare_clock := 0.1 ;
	fullprepare_clock_started := true ;
	busy := true;
	
end;

invariant "everything going right"
	(all_event_true);

goal  " enjoy "
	 ( (observe_complete() & all_event_true) );

metric: minimize;
