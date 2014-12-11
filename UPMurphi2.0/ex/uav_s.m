type
	 real_type: real(10,10);
	 integer: -100000..100000;

	pattern : Enum {spiral1,spiral2,spiral3};
	waypoint : Enum {origin,s1s,s1e,s2s,s2e,s3s,s3e};

const 
	 T:1;


var 
	h_n : integer;
	g_n : integer;
	f_n : integer;
	all_event_true: boolean;
	distance[pddlname:distance;] : Array [waypoint] of Array [waypoint] of  real_type;
	reward[pddlname:reward;] :  real_type;
	rewardof[pddlname:rewardof;] : Array [pattern] of  real_type;
	timefor[pddlname:timefor;] : Array [pattern] of  real_type;
	fly_clock_started : Array [waypoint] of Array [waypoint] of  boolean ;
	fly_clock : Array [waypoint] of Array [waypoint] of  real_type ;
	dospiral_clock_started : Array [waypoint] of Array [waypoint] of Array [pattern] of  boolean ;
	dospiral_clock : Array [waypoint] of Array [waypoint] of Array [pattern] of  real_type ;


	at[pddlname:at;] : Array [waypoint] of  boolean;
	active[pddlname:active;] : Array [pattern] of  boolean;
	beginat[pddlname:beginat;] : Array [waypoint] of Array [pattern] of  boolean;
	endat[pddlname:endat;] : Array [waypoint] of Array [pattern] of  boolean;


-- External function declaration 

externfun increase_reward_duraction_end_dospiral(reward : real_type ; rewardof : real_type ; ): real_type "uav_s.h" ;
procedure set_at( p : waypoint ;  value : boolean);
BEGIN
	at[p] := value;
END;

function get_at( p : waypoint): boolean;
BEGIN
	return 	at[p];
END;

procedure set_active( p : pattern ;  value : boolean);
BEGIN
	active[p] := value;
END;

function get_active( p : pattern): boolean;
BEGIN
	return 	active[p];
END;

procedure set_beginat( w : waypoint ; p : pattern ;  value : boolean);
BEGIN
	beginat[w][p] := value;
END;

function get_beginat( w : waypoint ; p : pattern): boolean;
BEGIN
	return 	beginat[w][p];
END;

procedure set_endat( w : waypoint ; p : pattern ;  value : boolean);
BEGIN
	endat[w][p] := value;
END;

function get_endat( w : waypoint ; p : pattern): boolean;
BEGIN
	return 	endat[w][p];
END;





procedure process_fly( from : waypoint; tto : waypoint);
BEGIN
	 IF (fly_clock_started[from][tto]) THEN 
		 fly_clock[from][tto]:= fly_clock[from][tto] + T ;
	 ENDIF;

END;
procedure process_dospiral( from : waypoint; tto : waypoint; p : pattern);
BEGIN
	 IF (dospiral_clock_started[from][tto][p]) THEN 
		 dospiral_clock[from][tto][p]:= dospiral_clock[from][tto][p] + T ;
	 ENDIF;

END;
function event_fly_failure( from : waypoint; tto : waypoint) : boolean; 
BEGIN
	 IF (fly_clock_started[from][tto])& !((true) ) THEN 
		 fly_clock[from][tto]:= fly_clock[from][tto]+ T ;
		 all_event_true := false ;
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;
function event_dospiral_failure( from : waypoint; tto : waypoint; p : pattern) : boolean; 
BEGIN
	 IF (dospiral_clock_started[from][tto][p])& !((true)   ) THEN 
		 dospiral_clock[from][tto][p]:= dospiral_clock[from][tto][p]+ T ;
		 all_event_true := false ;
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;


procedure event_check();
 var -- local vars declaration 
   event_triggered : boolean;
   event_fly_failure_triggered :  Array [waypoint] of  Array [waypoint] of  boolean;
   event_dospiral_failure_triggered :  Array [waypoint] of  Array [waypoint] of  Array [pattern] of  boolean;
BEGIN
 event_triggered := true;
   for from : waypoint do 
     for tto : waypoint do 
           event_fly_failure_triggered[from][tto] := false;
           END;END; -- close for
   for from : waypoint do 
     for tto : waypoint do 
       for p : pattern do 
               event_dospiral_failure_triggered[from][tto][p] := false;
               END;END;END; -- close for
while (event_triggered) do 
 event_triggered := false;
       for from : waypoint do 
         for tto : waypoint do 
           if(! event_fly_failure_triggered[from][tto]) then 
           event_fly_failure_triggered[from][tto] := event_fly_failure(from,tto);
           event_triggered := event_triggered | event_fly_failure_triggered[from][tto]; 
           endif;
END;END; -- close for
         for from : waypoint do 
           for tto : waypoint do 
             for p : pattern do 
               if(! event_dospiral_failure_triggered[from][tto][p]) then 
               event_dospiral_failure_triggered[from][tto][p] := event_dospiral_failure(from,tto,p);
               event_triggered := event_triggered | event_dospiral_failure_triggered[from][tto][p]; 
               endif;
END;END;END; -- close for
END; -- close while loop 
if ( (T >= 169) & (T <= 528) & (!(get_active(spiral1))) ) then
set_active(spiral1, true);
endif;
if ( (T > 528) & (get_active(spiral1)) ) then
set_active(spiral1, false);
endif; 
if ( (T >= 595) & (T <= 1583) & (!(get_active(spiral2))) ) then
set_active(spiral2, true);
endif;
if ( (T > 1583) & (get_active(spiral2)) ) then
set_active(spiral2, false);
endif; 
if ( (T >= 2009) & (T <= 2809) & (!(get_active(spiral3))) ) then
set_active(spiral3, true);
endif;
if ( (T > 2809) & (get_active(spiral3)) ) then
set_active(spiral3, false);
endif; 
END;



procedure apply_continuous_change();
 var -- local vars declaration 
   process_updated : boolean;
 end_while : boolean;   process_fly_enabled :  Array [waypoint] of  Array [waypoint] of  boolean;
   process_dospiral_enabled :  Array [waypoint] of  Array [waypoint] of  Array [pattern] of  boolean;
BEGIN
 process_updated := false; end_while := false;
   for from : waypoint do 
     for tto : waypoint do 
           process_fly_enabled[from][tto] := false;
           END;END; -- close for
   for from : waypoint do 
     for tto : waypoint do 
       for p : pattern do 
               process_dospiral_enabled[from][tto][p] := false;
               END;END;END; -- close for
while (!end_while) do 
        for from : waypoint do 
         for tto : waypoint do 
           if ((true)  & fly_clock_started[from][tto] & !process_fly_enabled[from][tto]) then
           process_updated := true;
           process_fly(from,tto);
           process_fly_enabled[from][tto] := true;
           endif;
END;END; -- close for
         for from : waypoint do 
           for tto : waypoint do 
             for p : pattern do 
               if ((true)    & dospiral_clock_started[from][tto][p] & !process_dospiral_enabled[from][tto][p]) then
               process_updated := true;
               process_dospiral(from,tto,p);
               process_dospiral_enabled[from][tto][p] := true;
               endif;
END;END;END; -- close for
IF (!process_updated) then
	 end_while:=true;
 else process_updated:=false;
endif;END; -- close while loop 
END;



ruleset from:waypoint do 
 ruleset tto:waypoint do 
 durative_start rule " fly_start " 
( !fly_clock_started[from][tto]) & (at[from]) & (!((from)=(tto))) & all_event_true ==> 
pddlname: " fly"; 
BEGIN
fly_clock_started[from][tto]:= true;
at[from]:= false; 

END; 
END; 
END; 



ruleset from:waypoint do 
 ruleset tto:waypoint do 
 durative_end rule " fly_end " 
( fly_clock_started[from][tto]) & (( fly_clock[from][tto]) = (distance[from][tto])) & all_event_true ==> 
pddlname: " fly"; 
BEGIN
fly_clock_started[from][tto]:= false;
fly_clock[from][tto]:= 0.0;
at[tto]:= true; 

END; 
END; 
END; 




ruleset from:waypoint do 
 ruleset tto:waypoint do 
 ruleset p:pattern do 
 durative_start rule " dospiral_start " 
( !dospiral_clock_started[from][tto][p]) & (beginat[from][p]) & (endat[tto][p]) & (at[from])  & all_event_true ==> 
pddlname: " dospiral"; 
BEGIN
dospiral_clock_started[from][tto][p]:= true;
at[from]:= false; 

END; 
END; 
END; 
END; 



ruleset from:waypoint do 
 ruleset tto:waypoint do 
 ruleset p:pattern do 
 durative_end rule " dospiral_end " 
( dospiral_clock_started[from][tto][p]) & (( dospiral_clock[from][tto][p]) = (timefor[p])) & (active[p]) & all_event_true ==> 
pddlname: " dospiral"; 
BEGIN
dospiral_clock_started[from][tto][p]:= false;
dospiral_clock[from][tto][p]:= 0.0;
reward := increase_reward_duraction_end_dospiral(reward , rewardof[p]  );
at[tto]:= true; 

END; 
END; 
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
for p : waypoint do 
  set_at(p, false);
END;  -- close for
   for p : pattern do 
     set_active(p, false);
END;  -- close for
   for w : waypoint do 
     for p : pattern do 
       set_beginat(w,p, false);
END; END;  -- close for
   for w : waypoint do 
     for p : pattern do 
       set_endat(w,p, false);
END; END;  -- close for
   reward := 0.0 ;

   for p : pattern do 
     rewardof[p] := 0.0 ;
END;  -- close for
   for p : pattern do 
     timefor[p] := 0.0 ;
END;  -- close for
   for p1 : waypoint do 
     for p2 : waypoint do 
       distance[p1][p2] := 0.0 ;
END; END;  -- close for

h_n := 0;
g_n := 0;
f_n := 0;
at[origin]:= true; 
beginat[s1s][spiral1]:= true; 
endat[s1e][spiral1]:= true; 
beginat[s2s][spiral2]:= true; 
endat[s2e][spiral2]:= true; 
beginat[s3s][spiral3]:= true; 
endat[s3e][spiral3]:= true; 
reward := 0.0000000;
rewardof[spiral1] := 1542.0000;
timefor[spiral1] := 299.00000;
distance[origin][s1s] := 29.000000;
distance[s1e][s2s] := 76.000000;
distance[s1e][s3s] := 295.00000;
rewardof[spiral2] := 96.000000;
timefor[spiral2] := 299.00000;
distance[origin][s2s] := 121.00000;
distance[s2e][s1s] := 112.00000;
distance[s2e][s3s] := 372.00000;
rewardof[spiral3] := 163.00000;
timefor[spiral3] := 299.00000;
distance[origin][s3s] := 231.00000;
distance[s3e][s1s] := 238.00000;
distance[s3e][s2s] := 211.00000;

-- durative action "dospiral" clock initialization
 for from : waypoint do 
   for tto : waypoint do 
     for p : pattern do 
       dospiral_clock_started[from][tto][p]:= false;
      dospiral_clock[from][tto][p]:= 0.0;
END; END; END; -- for ends

-- durative action "fly" clock initialization
 for from : waypoint do 
   for tto : waypoint do 
     fly_clock_started[from][tto]:= false;
    fly_clock[from][tto]:= 0.0;
END; END; -- for ends

all_event_true := true;
END; -- close startstate

goal "enjoy" 
 ((( reward) >= (1.0000000))); 

invariant "todo bien" 
 all_event_true;
metric: minimize;


