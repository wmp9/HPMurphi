type
	 real_type: real(12,12);

	equipment : Enum {unit1};

const 
	 T:1;


var 
	all_event_true: boolean;
	a_rate[pddlname:a_rate;] :  real_type;
	b_rate[pddlname:b_rate;] :  real_type;
	c_rate[pddlname:c_rate;] :  real_type;
	charge_rate[pddlname:charge_rate;] :  real_type;
	d_rate[pddlname:d_rate;] :  real_type;
	dawn[pddlname:dawn;] :  real_type;
	daytime[pddlname:daytime;] :  real_type;
	demand[pddlname:demand;] :  real_type;
	dusk[pddlname:dusk;] :  real_type;
	fullprepare_durtime[pddlname:fullprepare_durtime;] :  real_type;
	heater_rate[pddlname:heater_rate;] :  real_type;
	obs1_rate[pddlname:obs1_rate;] :  real_type;
	obs2_rate[pddlname:obs2_rate;] :  real_type;
	observe1_durtime[pddlname:observe1_durtime;] :  real_type;
	observe2_durtime[pddlname:observe2_durtime;] :  real_type;
	prepareobs1_durtime[pddlname:prepareobs1_durtime;] :  real_type;
	prepareobs2_durtime[pddlname:prepareobs2_durtime;] :  real_type;
	safelevel[pddlname:safelevel;] :  real_type;
	soc[pddlname:soc;] :  real_type;
	solar_const[pddlname:solar_const;] :  real_type;
	supply[pddlname:supply;] :  real_type;
	fullprepare_clock_started : Array [equipment] of  boolean ;
	fullprepare_clock : Array [equipment] of  real_type ;
	prepareobs1_clock_started : Array [equipment] of  boolean ;
	prepareobs1_clock : Array [equipment] of  real_type ;
	prepareobs2_clock_started : Array [equipment] of  boolean ;
	prepareobs2_clock : Array [equipment] of  real_type ;
	observe1_clock_started : Array [equipment] of  boolean ;
	observe1_clock : Array [equipment] of  real_type ;
	observe2_clock_started : Array [equipment] of  boolean ;
	observe2_clock : Array [equipment] of  real_type ;


	day[pddlname:day;] :  boolean;
	commsopen[pddlname:commsopen;] :  boolean;
	readyforobs1[pddlname:readyforobs1;] :  boolean;
	readyforobs2[pddlname:readyforobs2;] :  boolean;
	gotobs1[pddlname:gotobs1;] :  boolean;
	gotobs2[pddlname:gotobs2;] :  boolean;
	available[pddlname:available;] : Array [equipment] of  boolean;


-- External function declaration 

externfun increase_soc_process_charging(soc : real_type ; T : real_type ; supply : real_type ; demand : real_type ; charge_rate : real_type ; ): real_type "ex/planetary_lander.h" ;
externfun decrease_soc_process_discharging(soc : real_type ; T : real_type ; demand : real_type ; supply : real_type ; ): real_type ;
externfun increase_daytime_process_generating(daytime : real_type ; T : real_type ; ): real_type ;
externfun increase_supply_process_generating(supply : real_type ; T : real_type ; solar_const : real_type ; daytime : real_type ; ): real_type ;
externfun decrease_soc_process_night_operations(soc : real_type ; T : real_type ; heater_rate : real_type ; ): real_type ;
externfun increase_daytime_process_night_operations(daytime : real_type ; T : real_type ; ): real_type ;
externfun assign_daytime_event_nightfall(dawn : real_type ; ): real_type ;
externfun decrease_demand_duraction_end_fullprepare(demand : real_type ; a_rate : real_type ; ): real_type ;
externfun increase_demand_duraction_start_fullprepare(demand : real_type ; a_rate : real_type ; ): real_type ;
externfun decrease_demand_duraction_end_prepareobs1(demand : real_type ; b_rate : real_type ; ): real_type ;
externfun increase_demand_duraction_start_prepareobs1(demand : real_type ; b_rate : real_type ; ): real_type ;
externfun decrease_demand_duraction_end_prepareobs2(demand : real_type ; c_rate : real_type ; ): real_type ;
externfun increase_demand_duraction_start_prepareobs2(demand : real_type ; c_rate : real_type ; ): real_type ;
externfun decrease_demand_duraction_end_observe1(demand : real_type ; obs1_rate : real_type ; ): real_type ;
externfun increase_demand_duraction_start_observe1(demand : real_type ; obs1_rate : real_type ; ): real_type ;
externfun decrease_demand_duraction_end_observe2(demand : real_type ; obs2_rate : real_type ; ): real_type ;
externfun increase_demand_duraction_start_observe2(demand : real_type ; obs2_rate : real_type ; ): real_type ;
procedure set_day(  value : boolean);
BEGIN
	day := value;
END;

function get_day(): boolean;
BEGIN
	return 	day;
END;

procedure set_commsopen(  value : boolean);
BEGIN
	commsopen := value;
END;

function get_commsopen(): boolean;
BEGIN
	return 	commsopen;
END;

procedure set_readyforobs1(  value : boolean);
BEGIN
	readyforobs1 := value;
END;

function get_readyforobs1(): boolean;
BEGIN
	return 	readyforobs1;
END;

procedure set_readyforobs2(  value : boolean);
BEGIN
	readyforobs2 := value;
END;

function get_readyforobs2(): boolean;
BEGIN
	return 	readyforobs2;
END;

procedure set_gotobs1(  value : boolean);
BEGIN
	gotobs1 := value;
END;

function get_gotobs1(): boolean;
BEGIN
	return 	gotobs1;
END;

procedure set_gotobs2(  value : boolean);
BEGIN
	gotobs2 := value;
END;

function get_gotobs2(): boolean;
BEGIN
	return 	gotobs2;
END;

procedure set_available( e : equipment ;  value : boolean);
BEGIN
	available[e] := value;
END;

function get_available( e : equipment): boolean;
BEGIN
	return 	available[e];
END;






















procedure process_fullprepare( e : equipment);
BEGIN
	 IF (fullprepare_clock_started[e]) THEN 
		 fullprepare_clock[e]:= fullprepare_clock[e] + T ;
	 ENDIF;

END;
procedure process_prepareobs1( e : equipment);
BEGIN
	 IF (prepareobs1_clock_started[e]) THEN 
		 prepareobs1_clock[e]:= prepareobs1_clock[e] + T ;
	 ENDIF;

END;
procedure process_prepareobs2( e : equipment);
BEGIN
	 IF (prepareobs2_clock_started[e]) THEN 
		 prepareobs2_clock[e]:= prepareobs2_clock[e] + T ;
	 ENDIF;

END;
procedure process_observe1( e : equipment);
BEGIN
	 IF (observe1_clock_started[e]) THEN 
		 observe1_clock[e]:= observe1_clock[e] + T ;
	 ENDIF;

END;
procedure process_observe2( e : equipment);
BEGIN
	 IF (observe2_clock_started[e]) THEN 
		 observe2_clock[e]:= observe2_clock[e] + T ;
	 ENDIF;

END;
function event_fullprepare_failure( e : equipment) : boolean; 
BEGIN
	 IF (fullprepare_clock_started[e])& !((true) & ((( soc) > (safelevel)))) THEN 
		 fullprepare_clock[e]:= fullprepare_clock[e]+ T ;
		 all_event_true := false ;
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;
function event_prepareobs1_failure( e : equipment) : boolean; 
BEGIN
	 IF (prepareobs1_clock_started[e])& !((true) & ((( soc) > (safelevel)))) THEN 
		 prepareobs1_clock[e]:= prepareobs1_clock[e]+ T ;
		 all_event_true := false ;
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;
function event_prepareobs2_failure( e : equipment) : boolean; 
BEGIN
	 IF (prepareobs2_clock_started[e])& !((true) & ((( soc) > (safelevel)))) THEN 
		 prepareobs2_clock[e]:= prepareobs2_clock[e]+ T ;
		 all_event_true := false ;
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;
function event_observe1_failure( e : equipment) : boolean; 
BEGIN
	 IF (observe1_clock_started[e])& !((true)  & ((( soc) > (safelevel))) & (!(commsopen))) THEN 
		 observe1_clock[e]:= observe1_clock[e]+ T ;
		 all_event_true := false ;
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;
function event_observe2_failure( e : equipment) : boolean; 
BEGIN
	 IF (observe2_clock_started[e])& !((true)  & ((( soc) > (safelevel))) & (!(commsopen))) THEN 
		 observe2_clock[e]:= observe2_clock[e]+ T ;
		 all_event_true := false ;
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;
procedure charging (); 
BEGIN
IF (((( demand) < (supply))) & (day)) THEN 
soc := increase_soc_process_charging(soc , T , supply , demand , charge_rate  );

ENDIF ; 

END;

procedure discharging (); 
BEGIN
IF ((( demand) > (supply))) THEN 
soc := decrease_soc_process_discharging(soc , T , demand , supply  );

ENDIF ; 

END;

procedure generating (); 
BEGIN
IF (day) THEN 
daytime := increase_daytime_process_generating(daytime , T  );
supply := increase_supply_process_generating(supply , T , solar_const , daytime  );

ENDIF ; 

END;

procedure night_operations (); 
BEGIN
IF (!(day)) THEN 
soc := decrease_soc_process_night_operations(soc , T , heater_rate  );
daytime := increase_daytime_process_night_operations(daytime , T  );

ENDIF ; 

END;

function nightfall () : boolean; 
BEGIN
IF ((day) & ((( daytime) >= (dusk)))) THEN 
day:= false; 
daytime := assign_daytime_event_nightfall(dawn  );
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;

function daybreak () : boolean; 
BEGIN
IF ((!(day)) & ((( daytime) >= (0.000000000)))) THEN 
day:= true; 
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;



procedure event_check();
 var -- local vars declaration 
   event_triggered : boolean;
   nightfall_triggered :  boolean;
   daybreak_triggered :  boolean;
   event_fullprepare_failure_triggered :  Array [equipment] of  boolean;
   event_prepareobs1_failure_triggered :  Array [equipment] of  boolean;
   event_prepareobs2_failure_triggered :  Array [equipment] of  boolean;
   event_observe1_failure_triggered :  Array [equipment] of  boolean;
   event_observe2_failure_triggered :  Array [equipment] of  boolean;
BEGIN
 event_triggered := true;
   nightfall_triggered := false;
   daybreak_triggered := false;
   for e : equipment do 
       event_fullprepare_failure_triggered[e] := false;
       END; -- close for
   for e : equipment do 
       event_prepareobs1_failure_triggered[e] := false;
       END; -- close for
   for e : equipment do 
       event_prepareobs2_failure_triggered[e] := false;
       END; -- close for
   for e : equipment do 
       event_observe1_failure_triggered[e] := false;
       END; -- close for
   for e : equipment do 
       event_observe2_failure_triggered[e] := false;
       END; -- close for
while (event_triggered) do 
 event_triggered := false;
   if(! nightfall_triggered) then 
   nightfall_triggered := nightfall();
   event_triggered := event_triggered | nightfall_triggered; 
   endif;

   if(! daybreak_triggered) then 
   daybreak_triggered := daybreak();
   event_triggered := event_triggered | daybreak_triggered; 
   endif;

     for e : equipment do 
       if(! event_fullprepare_failure_triggered[e]) then 
       event_fullprepare_failure_triggered[e] := event_fullprepare_failure(e);
       event_triggered := event_triggered | event_fullprepare_failure_triggered[e]; 
       endif;
END; -- close for
     for e : equipment do 
       if(! event_prepareobs1_failure_triggered[e]) then 
       event_prepareobs1_failure_triggered[e] := event_prepareobs1_failure(e);
       event_triggered := event_triggered | event_prepareobs1_failure_triggered[e]; 
       endif;
END; -- close for
     for e : equipment do 
       if(! event_prepareobs2_failure_triggered[e]) then 
       event_prepareobs2_failure_triggered[e] := event_prepareobs2_failure(e);
       event_triggered := event_triggered | event_prepareobs2_failure_triggered[e]; 
       endif;
END; -- close for
     for e : equipment do 
       if(! event_observe1_failure_triggered[e]) then 
       event_observe1_failure_triggered[e] := event_observe1_failure(e);
       event_triggered := event_triggered | event_observe1_failure_triggered[e]; 
       endif;
END; -- close for
     for e : equipment do 
       if(! event_observe2_failure_triggered[e]) then 
       event_observe2_failure_triggered[e] := event_observe2_failure(e);
       event_triggered := event_triggered | event_observe2_failure_triggered[e]; 
       endif;
END; -- close for
END; -- close while loop 
END;



procedure apply_continuous_change();
 var -- local vars declaration 
   process_updated : boolean;
 end_while : boolean;   charging_enabled :  boolean;
   discharging_enabled :  boolean;
   generating_enabled :  boolean;
   night_operations_enabled :  boolean;
   process_fullprepare_enabled :  Array [equipment] of  boolean;
   process_prepareobs1_enabled :  Array [equipment] of  boolean;
   process_prepareobs2_enabled :  Array [equipment] of  boolean;
   process_observe1_enabled :  Array [equipment] of  boolean;
   process_observe2_enabled :  Array [equipment] of  boolean;
BEGIN
 process_updated := false; end_while := false;
   charging_enabled := false;
   discharging_enabled := false;
   generating_enabled := false;
   night_operations_enabled := false;
   for e : equipment do 
       process_fullprepare_enabled[e] := false;
       END; -- close for
   for e : equipment do 
       process_prepareobs1_enabled[e] := false;
       END; -- close for
   for e : equipment do 
       process_prepareobs2_enabled[e] := false;
       END; -- close for
   for e : equipment do 
       process_observe1_enabled[e] := false;
       END; -- close for
   for e : equipment do 
       process_observe2_enabled[e] := false;
       END; -- close for
while (!end_while) do 
    if (((( demand) < (supply))) & (day) &  !charging_enabled) then
   process_updated := true;
   charging();
   charging_enabled := true;
   endif;

   if ((( demand) > (supply)) &  !discharging_enabled) then
   process_updated := true;
   discharging();
   discharging_enabled := true;
   endif;

   if (day &  !generating_enabled) then
   process_updated := true;
   generating();
   generating_enabled := true;
   endif;

   if (!(day) &  !night_operations_enabled) then
   process_updated := true;
   night_operations();
   night_operations_enabled := true;
   endif;

     for e : equipment do 
       if ((true)  & fullprepare_clock_started[e] &  !process_fullprepare_enabled[e]) then
       process_updated := true;
       process_fullprepare(e);
       process_fullprepare_enabled[e] := true;
       endif;
END; -- close for
     for e : equipment do 
       if ((true)  & prepareobs1_clock_started[e] &  !process_prepareobs1_enabled[e]) then
       process_updated := true;
       process_prepareobs1(e);
       process_prepareobs1_enabled[e] := true;
       endif;
END; -- close for
     for e : equipment do 
       if ((true)  & prepareobs2_clock_started[e] &  !process_prepareobs2_enabled[e]) then
       process_updated := true;
       process_prepareobs2(e);
       process_prepareobs2_enabled[e] := true;
       endif;
END; -- close for
     for e : equipment do 
       if ((true)    & observe1_clock_started[e] &  !process_observe1_enabled[e]) then
       process_updated := true;
       process_observe1(e);
       process_observe1_enabled[e] := true;
       endif;
END; -- close for
     for e : equipment do 
       if ((true)    & observe2_clock_started[e] &  !process_observe2_enabled[e]) then
       process_updated := true;
       process_observe2(e);
       process_observe2_enabled[e] := true;
       endif;
END; -- close for
IF (!process_updated) then
	 end_while:=true;
 else process_updated:=false;
endif;END; -- close while loop 
END;



ruleset e:equipment do 
 durative_start rule " fullprepare_start " 
( !fullprepare_clock_started[e]) & (available[e])  & all_event_true ==> 
pddlname: " fullprepare"; 
BEGIN
fullprepare_clock_started[e]:= true;
demand := increase_demand_duraction_start_fullprepare(demand , a_rate  );
available[e]:= false; 

END; 
END; 



ruleset e:equipment do 
 durative_end rule " fullprepare_end " 
( fullprepare_clock_started[e]) & (( fullprepare_clock[e]) = (fullprepare_durtime))   & all_event_true ==> 
pddlname: " fullprepare"; 
BEGIN
fullprepare_clock_started[e]:= false;
fullprepare_clock[e]:= 0.0;
readyforobs2:= true; 
readyforobs1:= true; 
demand := decrease_demand_duraction_end_fullprepare(demand , a_rate  );
available[e]:= true; 

END; 
END; 




ruleset e:equipment do 
 durative_start rule " prepareobs1_start " 
( !prepareobs1_clock_started[e]) & (available[e])  & all_event_true ==> 
pddlname: " prepareobs1"; 
BEGIN
prepareobs1_clock_started[e]:= true;
demand := increase_demand_duraction_start_prepareobs1(demand , b_rate  );
available[e]:= false; 

END; 
END; 



ruleset e:equipment do 
 durative_end rule " prepareobs1_end " 
( prepareobs1_clock_started[e]) & (( prepareobs1_clock[e]) = (prepareobs1_durtime))   & all_event_true ==> 
pddlname: " prepareobs1"; 
BEGIN
prepareobs1_clock_started[e]:= false;
prepareobs1_clock[e]:= 0.0;
readyforobs1:= true; 
demand := decrease_demand_duraction_end_prepareobs1(demand , b_rate  );
available[e]:= true; 

END; 
END; 




ruleset e:equipment do 
 durative_start rule " prepareobs2_start " 
( !prepareobs2_clock_started[e]) & (available[e])  & all_event_true ==> 
pddlname: " prepareobs2"; 
BEGIN
prepareobs2_clock_started[e]:= true;
demand := increase_demand_duraction_start_prepareobs2(demand , c_rate  );
available[e]:= false; 

END; 
END; 



ruleset e:equipment do 
 durative_end rule " prepareobs2_end " 
( prepareobs2_clock_started[e]) & (( prepareobs2_clock[e]) = (prepareobs2_durtime))   & all_event_true ==> 
pddlname: " prepareobs2"; 
BEGIN
prepareobs2_clock_started[e]:= false;
prepareobs2_clock[e]:= 0.0;
readyforobs2:= true; 
demand := decrease_demand_duraction_end_prepareobs2(demand , c_rate  );
available[e]:= true; 

END; 
END; 




ruleset e:equipment do 
 durative_start rule " observe1_start " 
( !observe1_clock_started[e]) & (available[e]) & (readyforobs1)   & all_event_true ==> 
pddlname: " observe1"; 
BEGIN
observe1_clock_started[e]:= true;
demand := increase_demand_duraction_start_observe1(demand , obs1_rate  );
available[e]:= false; 

END; 
END; 



ruleset e:equipment do 
 durative_end rule " observe1_end " 
( observe1_clock_started[e]) & (( observe1_clock[e]) = (observe1_durtime))     & all_event_true ==> 
pddlname: " observe1"; 
BEGIN
observe1_clock_started[e]:= false;
observe1_clock[e]:= 0.0;
gotobs1:= true; 
readyforobs1:= false; 
demand := decrease_demand_duraction_end_observe1(demand , obs1_rate  );
available[e]:= true; 

END; 
END; 




ruleset e:equipment do 
 durative_start rule " observe2_start " 
( !observe2_clock_started[e]) & (available[e]) & (readyforobs2)   & all_event_true ==> 
pddlname: " observe2"; 
BEGIN
observe2_clock_started[e]:= true;
demand := increase_demand_duraction_start_observe2(demand , obs2_rate  );
available[e]:= false; 

END; 
END; 



ruleset e:equipment do 
 durative_end rule " observe2_end " 
( observe2_clock_started[e]) & (( observe2_clock[e]) = (observe2_durtime))     & all_event_true ==> 
pddlname: " observe2"; 
BEGIN
observe2_clock_started[e]:= false;
observe2_clock[e]:= 0.0;
gotobs2:= true; 
readyforobs2:= false; 
demand := decrease_demand_duraction_end_observe2(demand , obs2_rate  );
available[e]:= true; 

END; 
END; 


clock rule " time passing " 
 (true) ==> 
BEGIN 
 	 event_check();
	 apply_continuous_change(); 
END;


startstate "start" 
BEGIN 
set_day(false);

   set_commsopen(false);

   set_readyforobs1(false);

   set_readyforobs2(false);

   set_gotobs1(false);

   set_gotobs2(false);

   for e : equipment do 
     set_available(e, false);
END;  -- close for
   demand := 0.0 ;

   supply := 0.0 ;

   soc := 0.0 ;

   charge_rate := 0.0 ;

   daytime := 0.0 ;

   heater_rate := 0.0 ;

   dusk := 0.0 ;

   dawn := 0.0 ;

   fullprepare_durtime := 0.0 ;

   prepareobs1_durtime := 0.0 ;

   prepareobs2_durtime := 0.0 ;

   observe1_durtime := 0.0 ;

   observe2_durtime := 0.0 ;

   obs1_rate := 0.0 ;

   obs2_rate := 0.0 ;

   a_rate := 0.0 ;

   b_rate := 0.0 ;

   c_rate := 0.0 ;

   d_rate := 0.0 ;

   safelevel := 0.0 ;

   solar_const := 0.0 ;

available[unit1]:= true; 
day:= true; 
gotobs1:= false; 
gotobs2:= false; 
readyforobs1:= false; 
readyforobs2:= false; 
a_rate := 4.000000000;
b_rate := 2.000000000;
c_rate := 2.500000000;
d_rate := 1.500000000;
obs1_rate := 4.000000000;
obs2_rate := 5.000000000;
fullprepare_durtime := 3.000000000;
observe1_durtime := 7.000000000;
observe2_durtime := 8.000000000;
prepareobs1_durtime := 1.000000000;
prepareobs2_durtime := 2.000000000;
demand := 0.000000000;
supply := 0.000000000;
soc := 93.00000000;
charge_rate := 0.009500000000;
daytime := 4.000000000;
heater_rate := 15.10000000;
dusk := 9.000000000;
dawn := 3.000000000;
safelevel := 15.00000000;
solar_const := 0.03000000000;

-- durative action "fullprepare" clock initialization
 for e : equipment do 
   fullprepare_clock_started[e]:= false;
  fullprepare_clock[e]:= 0.0;
END; -- for ends

-- durative action "observe1" clock initialization
 for e : equipment do 
   observe1_clock_started[e]:= false;
  observe1_clock[e]:= 0.0;
END; -- for ends

-- durative action "observe2" clock initialization
 for e : equipment do 
   observe2_clock_started[e]:= false;
  observe2_clock[e]:= 0.0;
END; -- for ends

-- durative action "prepareobs1" clock initialization
 for e : equipment do 
   prepareobs1_clock_started[e]:= false;
  prepareobs1_clock[e]:= 0.0;
END; -- for ends

-- durative action "prepareobs2" clock initialization
 for e : equipment do 
   prepareobs2_clock_started[e]:= false;
  prepareobs2_clock[e]:= 0.0;
END; -- for ends

all_event_true := true;
END; -- close startstate

goal "enjoy" 
 (gotobs1) & (gotobs2); 

invariant "todo bien" 
 all_event_true;
metric: minimize;


