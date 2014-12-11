type
	 real_type: real(5,5);

	pattern : Enum {spiral1,spiral2,smalllawn6};
	waypoint : Enum {origin,s1s,s1e,s2s,s2e,sl6s,sl6e};
	orientation : Enum {o1,o2,o3};

const 
	 T:1;


var 
	all_event_true: boolean;
	award[pddlname:award;] : Array [pattern] of  real_type;
	distance[pddlname:distance;] : Array [waypoint] of Array [waypoint] of  real_type;
	penalty[pddlname:penalty;] : Array [pattern] of  real_type;
	reward[pddlname:reward;] :  real_type;
	rewardof[pddlname:rewardof;] : Array [pattern] of  real_type;
	timefor[pddlname:timefor;] : Array [pattern] of  real_type;
	fly_clock_started : Array [waypoint] of Array [waypoint] of  boolean ;
	fly_clock : Array [waypoint] of Array [waypoint] of  real_type ;
	dospiral_clock_started : Array [waypoint] of Array [waypoint] of Array [pattern] of Array [orientation] of  boolean ;
	dospiral_clock : Array [waypoint] of Array [waypoint] of Array [pattern] of Array [orientation] of  real_type ;
	dosmalllawnmower_clock_started : Array [waypoint] of Array [waypoint] of Array [pattern] of Array [orientation] of  boolean ;
	dosmalllawnmower_clock : Array [waypoint] of Array [waypoint] of Array [pattern] of Array [orientation] of  real_type ;


	updated[pddlname:updated;] : Array [pattern] of Array [orientation] of  boolean;
	at[pddlname:at;] : Array [waypoint] of  boolean;
	active[pddlname:active;] : Array [pattern] of  boolean;
	beginat[pddlname:beginat;] : Array [waypoint] of Array [pattern] of  boolean;
	endat[pddlname:endat;] : Array [waypoint] of Array [pattern] of  boolean;
	oriented[pddlname:oriented;] : Array [pattern] of Array [orientation] of  boolean;
	searched[pddlname:searched;] : Array [pattern] of  boolean;


-- External function declaration 

externfun increase_reward_duraction_end_dospiral(reward : real_type ; rewardof : real_type ; ): real_type "uav1_3.h" ;
externfun increase_reward_duraction_end_dosmalllawnmower(reward : real_type ; rewardof : real_type ; ): real_type ;
procedure set_updated( p : pattern ; o : orientation ;  value : boolean);
BEGIN
	updated[p][o] := value;
END;

function get_updated( p : pattern ; o : orientation): boolean;
BEGIN
	return 	updated[p][o];
END;

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

procedure set_oriented( p : pattern ; o : orientation ;  value : boolean);
BEGIN
	oriented[p][o] := value;
END;

function get_oriented( p : pattern ; o : orientation): boolean;
BEGIN
	return 	oriented[p][o];
END;

procedure set_searched( p : pattern ;  value : boolean);
BEGIN
	searched[p] := value;
END;

function get_searched( p : pattern): boolean;
BEGIN
	return 	searched[p];
END;







procedure process_fly( from : waypoint; tto : waypoint);
BEGIN
	 IF (fly_clock_started[from][tto]) THEN 
		 fly_clock[from][tto]:= fly_clock[from][tto] + T ;
	 ENDIF;

END;
procedure process_dospiral( from : waypoint; tto : waypoint; p : pattern; o : orientation);
BEGIN
	 IF (dospiral_clock_started[from][tto][p][o]) THEN 
		 dospiral_clock[from][tto][p][o]:= dospiral_clock[from][tto][p][o] + T ;
	 ENDIF;

END;
procedure process_dosmalllawnmower( from : waypoint; tto : waypoint; p : pattern; o : orientation);
BEGIN
	 IF (dosmalllawnmower_clock_started[from][tto][p][o]) THEN 
		 dosmalllawnmower_clock[from][tto][p][o]:= dosmalllawnmower_clock[from][tto][p][o] + T ;
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
function event_dospiral_failure( from : waypoint; tto : waypoint; p : pattern; o : orientation) : boolean; 
BEGIN
	 IF (dospiral_clock_started[from][tto][p][o])& !((true)     ) THEN 
		 dospiral_clock[from][tto][p][o]:= dospiral_clock[from][tto][p][o]+ T ;
		 all_event_true := false ;
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;
function event_dosmalllawnmower_failure( from : waypoint; tto : waypoint; p : pattern; o : orientation) : boolean; 
BEGIN
	 IF (dosmalllawnmower_clock_started[from][tto][p][o])& !((true)     ) THEN 
		 dosmalllawnmower_clock[from][tto][p][o]:= dosmalllawnmower_clock[from][tto][p][o]+ T ;
		 all_event_true := false ;
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;
function updatereward (p : pattern ; o : orientation) : boolean; 
BEGIN
IF ((updated[p][o])) THEN 
updated[p][o]:= false; 


		 return true; 
 	 ELSE return false;
	 ENDIF;

END;



procedure event_check();
 var -- local vars declaration 
   event_triggered : boolean;
   updatereward_triggered :  Array [pattern] of  Array [orientation] of  boolean;
   event_fly_failure_triggered :  Array [waypoint] of  Array [waypoint] of  boolean;
   event_dospiral_failure_triggered :  Array [waypoint] of  Array [waypoint] of  Array [pattern] of  Array [orientation] of  boolean;
   event_dosmalllawnmower_failure_triggered :  Array [waypoint] of  Array [waypoint] of  Array [pattern] of  Array [orientation] of  boolean;
BEGIN
 event_triggered := true;
   for p : pattern do 
     for o : orientation do 
           updatereward_triggered[p][o] := false;
           END;END; -- close for
   for from : waypoint do 
     for tto : waypoint do 
           event_fly_failure_triggered[from][tto] := false;
           END;END; -- close for
   for from : waypoint do 
     for tto : waypoint do 
       for p : pattern do 
         for o : orientation do 
                   event_dospiral_failure_triggered[from][tto][p][o] := false;
                   END;END;END;END; -- close for
   for from : waypoint do 
     for tto : waypoint do 
       for p : pattern do 
         for o : orientation do 
                   event_dosmalllawnmower_failure_triggered[from][tto][p][o] := false;
                   END;END;END;END; -- close for
while (event_triggered) do 
 event_triggered := false;
       for p : pattern do 
         for o : orientation do 
           if(! updatereward_triggered[p][o]) then 
           updatereward_triggered[p][o] := updatereward(p,o);
           event_triggered := event_triggered | updatereward_triggered[p][o]; 
           endif;
END;END; -- close for
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
                 for o : orientation do 
                   if(! event_dospiral_failure_triggered[from][tto][p][o]) then 
                   event_dospiral_failure_triggered[from][tto][p][o] := event_dospiral_failure(from,tto,p,o);
                   event_triggered := event_triggered | event_dospiral_failure_triggered[from][tto][p][o]; 
                   endif;
END;END;END;END; -- close for
           for from : waypoint do 
             for tto : waypoint do 
               for p : pattern do 
                 for o : orientation do 
                   if(! event_dosmalllawnmower_failure_triggered[from][tto][p][o]) then 
                   event_dosmalllawnmower_failure_triggered[from][tto][p][o] := event_dosmalllawnmower_failure(from,tto,p,o);
                   event_triggered := event_triggered | event_dosmalllawnmower_failure_triggered[from][tto][p][o]; 
                   endif;
END;END;END;END; -- close for
END; -- close while loop 
END;



procedure apply_continuous_change();
 var -- local vars declaration 
   process_updated : boolean;
 end_while : boolean;   process_fly_enabled :  Array [waypoint] of  Array [waypoint] of  boolean;
   process_dospiral_enabled :  Array [waypoint] of  Array [waypoint] of  Array [pattern] of  Array [orientation] of  boolean;
   process_dosmalllawnmower_enabled :  Array [waypoint] of  Array [waypoint] of  Array [pattern] of  Array [orientation] of  boolean;
BEGIN
 process_updated := false; end_while := false;
   for from : waypoint do 
     for tto : waypoint do 
           process_fly_enabled[from][tto] := false;
           END;END; -- close for
   for from : waypoint do 
     for tto : waypoint do 
       for p : pattern do 
         for o : orientation do 
                   process_dospiral_enabled[from][tto][p][o] := false;
                   END;END;END;END; -- close for
   for from : waypoint do 
     for tto : waypoint do 
       for p : pattern do 
         for o : orientation do 
                   process_dosmalllawnmower_enabled[from][tto][p][o] := false;
                   END;END;END;END; -- close for
while (!end_while) do 
        for from : waypoint do 
         for tto : waypoint do 
           if ((true)  & fly_clock_started[from][tto] &  !process_fly_enabled[from][tto]) then
           process_updated := true;
           process_fly(from,tto);
           process_fly_enabled[from][tto] := true;
           endif;
END;END; -- close for
           for from : waypoint do 
             for tto : waypoint do 
               for p : pattern do 
                 for o : orientation do 
                   if ((true)      & dospiral_clock_started[from][tto][p][o] &  !process_dospiral_enabled[from][tto][p][o]) then
                   process_updated := true;
                   process_dospiral(from,tto,p,o);
                   process_dospiral_enabled[from][tto][p][o] := true;
                   endif;
END;END;END;END; -- close for
           for from : waypoint do 
             for tto : waypoint do 
               for p : pattern do 
                 for o : orientation do 
                   if ((true)      & dosmalllawnmower_clock_started[from][tto][p][o] &  !process_dosmalllawnmower_enabled[from][tto][p][o]) then
                   process_updated := true;
                   process_dosmalllawnmower(from,tto,p,o);
                   process_dosmalllawnmower_enabled[from][tto][p][o] := true;
                   endif;
END;END;END;END; -- close for
IF (!process_updated) then
	 end_while:=true;
 else process_updated:=false;
endif;END; -- close while loop 
END;



ruleset from:waypoint do 
 ruleset tto:waypoint do 
 durative_start rule " fly_start " 
( !fly_clock_started[from][tto]) & (at[from]) & (!((from) = (tto))) & all_event_true ==> 
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
( fly_clock_started[from][tto]) & (( fly_clock[from][tto]) = (distance[from][tto]))   & all_event_true ==> 
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
 ruleset o:orientation do 
 durative_start rule " dospiral_start " 
( !dospiral_clock_started[from][tto][p][o]) & (beginat[from][p]) & (endat[tto][p]) & (oriented[p][o]) & (at[from])  & (!(searched[p])) & all_event_true ==> 
pddlname: " dospiral"; 
BEGIN
dospiral_clock_started[from][tto][p][o]:= true;
searched[p]:= true; 
at[from]:= false; 

END; 
END; 
END; 
END; 
END; 



ruleset from:waypoint do 
 ruleset tto:waypoint do 
 ruleset p:pattern do 
 ruleset o:orientation do 
 durative_end rule " dospiral_end " 
( dospiral_clock_started[from][tto][p][o]) & (( dospiral_clock[from][tto][p][o]) = (timefor[p]))     & (active[p])  & all_event_true ==> 
pddlname: " dospiral"; 
BEGIN
dospiral_clock_started[from][tto][p][o]:= false;
dospiral_clock[from][tto][p][o]:= 0.0;
updated[p][o]:= true; 
reward := increase_reward_duraction_end_dospiral(reward , rewardof[p]  );
at[tto]:= true; 

END; 
END; 
END; 
END; 
END; 




ruleset from:waypoint do 
 ruleset tto:waypoint do 
 ruleset p:pattern do 
 ruleset o:orientation do 
 durative_start rule " dosmalllawnmower_start " 
( !dosmalllawnmower_clock_started[from][tto][p][o]) & (beginat[from][p]) & (endat[tto][p]) & (oriented[p][o]) & (at[from])  & (!(searched[p])) & all_event_true ==> 
pddlname: " dosmalllawnmower"; 
BEGIN
dosmalllawnmower_clock_started[from][tto][p][o]:= true;
searched[p]:= true; 
at[from]:= false; 

END; 
END; 
END; 
END; 
END; 



ruleset from:waypoint do 
 ruleset tto:waypoint do 
 ruleset p:pattern do 
 ruleset o:orientation do 
 durative_end rule " dosmalllawnmower_end " 
( dosmalllawnmower_clock_started[from][tto][p][o]) & (( dosmalllawnmower_clock[from][tto][p][o]) = (timefor[p]))     & (active[p])  & all_event_true ==> 
pddlname: " dosmalllawnmower"; 
BEGIN
dosmalllawnmower_clock_started[from][tto][p][o]:= false;
dosmalllawnmower_clock[from][tto][p][o]:= 0.0;
updated[p][o]:= true; 
reward := increase_reward_duraction_end_dosmalllawnmower(reward , rewardof[p]  );
at[tto]:= true; 

END; 
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
for p : pattern do 
  for o : orientation do 
    set_updated(p,o, false);
END; END;  -- close for
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
   for p : pattern do 
     for o : orientation do 
       set_oriented(p,o, false);
END; END;  -- close for
   for p : pattern do 
     set_searched(p, false);
END;  -- close for
   reward := 0.0 ;

   for p : pattern do 
     rewardof[p] := 0.0 ;
END;  -- close for
   for p : pattern do 
     timefor[p] := 0.0 ;
END;  -- close for
   for w1 : waypoint do 
     for w2 : waypoint do 
       distance[w1][w2] := 0.0 ;
END; END;  -- close for
   for p : pattern do 
     penalty[p] := 0.0 ;
END;  -- close for
   for p : pattern do 
     award[p] := 0.0 ;
END;  -- close for
at[origin]:= true; 
beginat[s1s][spiral1]:= true; 
endat[s1e][spiral1]:= true; 
oriented[spiral1][o1]:= true; 
beginat[s2s][spiral2]:= true; 
endat[s2e][spiral2]:= true; 
oriented[spiral2][o1]:= true; 
beginat[sl6s][smalllawn6]:= true; 
endat[sl6e][smalllawn6]:= true; 
oriented[smalllawn6][o2]:= true; 
reward := 0.00;
rewardof[spiral1] := 6.06E+03;
timefor[spiral1] := 299.;
penalty[spiral1] := 2.00E+03;
award[spiral1] := 2.00E+03;
distance[origin][s1s] := 41.0;
distance[s1e][s2s] := 132.;
distance[s1e][sl6s] := 289.;
rewardof[spiral2] := 106.;
timefor[spiral2] := 299.;
penalty[spiral2] := 100.;
award[spiral2] := 100.;
distance[origin][s2s] := 119.;
distance[s2e][s1s] := 107.;
distance[s2e][sl6s] := 235.;
rewardof[smalllawn6] := 151.;
timefor[smalllawn6] := 440.;
penalty[smalllawn6] := 100.;
award[smalllawn6] := 100.;
distance[origin][sl6s] := 335.;
distance[sl6e][s1s] := 216.;
distance[sl6e][s2s] := 185.;

-- durative action "dosmalllawnmower" clock initialization
 for from : waypoint do 
   for tto : waypoint do 
     for p : pattern do 
       for o : orientation do 
         dosmalllawnmower_clock_started[from][tto][p][o]:= false;
        dosmalllawnmower_clock[from][tto][p][o]:= 0.0;
END; END; END; END; -- for ends

-- durative action "dospiral" clock initialization
 for from : waypoint do 
   for tto : waypoint do 
     for p : pattern do 
       for o : orientation do 
         dospiral_clock_started[from][tto][p][o]:= false;
        dospiral_clock[from][tto][p][o]:= 0.0;
END; END; END; END; -- for ends

-- durative action "fly" clock initialization
 for from : waypoint do 
   for tto : waypoint do 
     fly_clock_started[from][tto]:= false;
    fly_clock[from][tto]:= 0.0;
END; END; -- for ends

all_event_true := true;
END; -- close startstate

goal "enjoy" 
 ((( reward) >= (1.00))); 

invariant "ttodo bien" 
 all_event_true;
metric: maximize;


