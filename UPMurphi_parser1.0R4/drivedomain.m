type
	 real_type: real(7,7);

	vehicle : Enum {car};
	location : Enum {start,tend};

const 
	 T:0.001;


var 
	all_event_true: boolean;
	distance[pddlname:distance;] : Array [location] of Array [location] of  real_type;
	maxspeed[pddlname:maxspeed;] : Array [vehicle] of  real_type;
	speed[pddlname:speed;] : Array [vehicle] of  real_type;
	traveltime[pddlname:traveltime;] : Array [vehicle] of  real_type;
	accelerate_clock_started : Array [vehicle] of  boolean ;
	accelerate_clock : Array [vehicle] of  real_type ;


	at[pddlname:at;] : Array [vehicle] of Array [location] of  boolean;


-- External function declaration 

externfun increase_speed_duraction_end_accelerate(speed : real_type ; accelerate_clock : real_type ; ): real_type "drivedomain.h" ;
externfun increase_traveltime_action_drive(traveltime : real_type ; distance : real_type ; speed : real_type ; ): real_type ;
procedure set_at( v : vehicle ; l : location ;  value : boolean);
BEGIN
	at[v][l] := value;
END;

function get_at( v : vehicle ; l : location): boolean;
BEGIN
	return 	at[v][l];
END;





procedure process_accelerate( v : vehicle);
BEGIN
	 IF (accelerate_clock_started[v]) THEN 
		 accelerate_clock[v]:= accelerate_clock[v] + T ;
	 ENDIF;

END;
function event_accelerate_failure( v : vehicle) : boolean; 
BEGIN
	 IF (accelerate_clock_started[v])THEN 
		 accelerate_clock[v]:= accelerate_clock[v]+ T ;
		 all_event_true := false ;
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;


procedure event_check();
 var -- local vars declaration 
   event_triggered : boolean;
   event_accelerate_failure_triggered :  Array [vehicle] of  boolean;
BEGIN
 event_triggered := true;
   for v : vehicle do 
       event_accelerate_failure_triggered[v] := false;
       END; -- close for
while (event_triggered) do 
 event_triggered := false;
     for v : vehicle do 
       if(! event_accelerate_failure_triggered[v]) then 
       event_accelerate_failure_triggered[v] := event_accelerate_failure(v);
       event_triggered := event_triggered | event_accelerate_failure_triggered[v]; 
       endif;
END; -- close for
END; -- close while loop 
END;



procedure apply_continuous_change();
 var -- local vars declaration 
   process_updated : boolean;
 end_while : boolean;   process_accelerate_enabled :  Array [vehicle] of  boolean;
BEGIN
 process_updated := false; end_while := false;
   for v : vehicle do 
       process_accelerate_enabled[v] := false;
       END; -- close for
while (!end_while) do 
      for v : vehicle do 
       if ( & accelerate_clock_started[v] &  !process_accelerate_enabled[v]) then
       process_updated := true;
       process_accelerate(v);
       process_accelerate_enabled[v] := true;
       endif;
END; -- close for
IF (!process_updated) then
	 end_while:=true;
 else process_updated:=false;
endif;END; -- close while loop 
END;



ruleset v:vehicle do 
 durative_start rule " accelerate_start " 
( !accelerate_clock_started[v]) & all_event_true ==> 
pddlname: " accelerate"; 
BEGIN
accelerate_clock_started[v]:= true;

END; 
END; 



ruleset v:vehicle do 
 durative_end rule " accelerate_end " 
( accelerate_clock_started[v]) & (( accelerate_clock[v]) <= ((maxspeed[v]) - (speed[v]))) & all_event_true ==> 
pddlname: " accelerate"; 
BEGIN
accelerate_clock_started[v]:= false;
accelerate_clock[v]:= 0.0;
speed[v] := increase_speed_duraction_end_accelerate(speed[v] , accelerate_clock[v]  );

END; 
END; 


ruleset v:vehicle do 
 ruleset p:location do 
 ruleset l:location do 
 action rule " drive " 
(at[v][p]) & ((( speed[v]) > (0.0000))) ==> 
pddlname: " drive"; 
BEGIN
at[v][l]:= true; 
at[v][p]:= false; 
traveltime[v] := increase_traveltime_action_drive(traveltime[v] , distance[p][l] , speed[v]  );

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
for v : vehicle do 
  for l : location do 
    set_at(v,l, false);
END; END;  -- close for
   for v : vehicle do 
     maxspeed[v] := 0.0 ;
END;  -- close for
   for v : vehicle do 
     speed[v] := 0.0 ;
END;  -- close for
   for v : vehicle do 
     traveltime[v] := 0.0 ;
END;  -- close for
   for p : location do 
     for l : location do 
       distance[p][l] := 0.0 ;
END; END;  -- close for
at[car][start]:= true; 
speed[car] := 0.0000;
maxspeed[car] := 10.000;
traveltime[car] := 0.0000;
distance[start][tend] := 100.00;

-- durative action "accelerate" clock initialization
 for v : vehicle do 
   accelerate_clock_started[v]:= false;
  accelerate_clock[v]:= 0.0;
END; -- for ends

all_event_true := true;
END; -- close startstate

goal "enjoy" 
 (at[car][tend]) & ((( traveltime[car]) >= (20.000))); 

invariant "todo bien" 
 all_event_true;
metric: minimize;


