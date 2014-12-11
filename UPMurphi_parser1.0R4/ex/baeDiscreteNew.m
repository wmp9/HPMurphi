type
	 real_type: real(7,7);

	pattern : Enum {spiral91,smalllawn66,smalllawn67,smalllawn68,smalllawn69,smalllawn70,smalllawn71,smalllawn72,smalllawn73,smalllawn74,largelawn78,largelawn79,largelawn80,largelawn81,largelawn82,largelawn83,largelawn84,largelawn87,largelawn88,largelawn75,patrol76,patrol77};
	waypoint : Enum {origin,pp76se,pp77se,ll78s,ll78e,ll79s,ll79e,ll80s,ll80e,ll81s,ll81e,ll82s,ll82e,ll83s,ll83e,ll84s,ll84e,ll87s,ll87e,ll88s,ll88e,s91s,s91e,sl66s,sl66e,sl67s,sl67e,sl68s,sl68e,sl69s,sl69e,sl70s,sl70e,sl71s,sl71e,sl72s,sl72e,sl73s,sl73e,sl74s,sl74e,ll75s,ll75e};

const 
	 T:1;


var 
	all_event_true: boolean;
	distance[pddlname:distance;] : Array [waypoint] of Array [waypoint] of  real_type;
	reward[pddlname:reward;] :  real_type;
	rewardof[pddlname:rewardof;] : Array [pattern] of  real_type;
	timefor[pddlname:timefor;] : Array [pattern] of  real_type;
	fly_clock_started : Array [waypoint] of Array [waypoint] of  boolean ;
	fly_clock : Array [waypoint] of Array [waypoint] of  real_type ;
	dopattern_clock_started : Array [waypoint] of Array [waypoint] of Array [pattern] of  boolean ;
	dopattern_clock : Array [waypoint] of Array [waypoint] of Array [pattern] of  real_type ;


	at[pddlname:at;] : Array [waypoint] of  boolean;
	active[pddlname:active;] : Array [pattern] of  boolean;
	beginat[pddlname:beginat;] : Array [waypoint] of Array [pattern] of  boolean;
	endat[pddlname:endat;] : Array [waypoint] of Array [pattern] of  boolean;


-- External function declaration 

externfun increase_reward_duraction_end_dopattern(reward : real_type ; rewardof : real_type ; ): real_type "ex/baeDiscreteNew.h" ;
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





procedure process_fly( from : waypoint; wto : waypoint);
BEGIN
	 IF (fly_clock_started[from][wto]) THEN 
		 fly_clock[from][wto]:= fly_clock[from][wto] + T ;
	 ENDIF;

END;
procedure process_dopattern( from : waypoint; wto : waypoint; p : pattern);
BEGIN
	 IF (dopattern_clock_started[from][wto][p]) THEN 
		 dopattern_clock[from][wto][p]:= dopattern_clock[from][wto][p] + T ;
	 ENDIF;

END;
function event_fly_failure( from : waypoint; wto : waypoint) : boolean; 
BEGIN
	 IF (fly_clock_started[from][wto])& !((true) ) THEN 
		 fly_clock[from][wto]:= fly_clock[from][wto]+ T ;
		 all_event_true := false ;
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;
function event_dopattern_failure( from : waypoint; wto : waypoint; p : pattern) : boolean; 
BEGIN
	 IF (dopattern_clock_started[from][wto][p])& !((true)   ) THEN 
		 dopattern_clock[from][wto][p]:= dopattern_clock[from][wto][p]+ T ;
		 all_event_true := false ;
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;


procedure event_check();
 var -- local vars declaration 
   event_triggered : boolean;
   event_fly_failure_triggered :  Array [waypoint] of  Array [waypoint] of  boolean;
   event_dopattern_failure_triggered :  Array [waypoint] of  Array [waypoint] of  Array [pattern] of  boolean;
BEGIN
 event_triggered := true;
   for from : waypoint do 
     for wto : waypoint do 
           event_fly_failure_triggered[from][wto] := false;
           END;END; -- close for
   for from : waypoint do 
     for wto : waypoint do 
       for p : pattern do 
               event_dopattern_failure_triggered[from][wto][p] := false;
               END;END;END; -- close for
while (event_triggered) do 
 event_triggered := false;
       for from : waypoint do 
         for wto : waypoint do 
           if(! event_fly_failure_triggered[from][wto]) then 
           event_fly_failure_triggered[from][wto] := event_fly_failure(from,wto);
           event_triggered := event_triggered | event_fly_failure_triggered[from][wto]; 
           endif;
END;END; -- close for
         for from : waypoint do 
           for wto : waypoint do 
             for p : pattern do 
               if(! event_dopattern_failure_triggered[from][wto][p]) then 
               event_dopattern_failure_triggered[from][wto][p] := event_dopattern_failure(from,wto,p);
               event_triggered := event_triggered | event_dopattern_failure_triggered[from][wto][p]; 
               endif;
END;END;END; -- close for
END; -- close while loop 
END;



procedure apply_continuous_change();
 var -- local vars declaration 
   process_updated : boolean;
 end_while : boolean;   process_fly_enabled :  Array [waypoint] of  Array [waypoint] of  boolean;
   process_dopattern_enabled :  Array [waypoint] of  Array [waypoint] of  Array [pattern] of  boolean;
BEGIN
 process_updated := false; end_while := false;
   for from : waypoint do 
     for wto : waypoint do 
           process_fly_enabled[from][wto] := false;
           END;END; -- close for
   for from : waypoint do 
     for wto : waypoint do 
       for p : pattern do 
               process_dopattern_enabled[from][wto][p] := false;
               END;END;END; -- close for
while (!end_while) do 
        for from : waypoint do 
         for wto : waypoint do 
           if ((true)  & fly_clock_started[from][wto] &  !process_fly_enabled[from][wto]) then
           process_updated := true;
           process_fly(from,wto);
           process_fly_enabled[from][wto] := true;
           endif;
END;END; -- close for
         for from : waypoint do 
           for wto : waypoint do 
             for p : pattern do 
               if ((true)    & dopattern_clock_started[from][wto][p] &  !process_dopattern_enabled[from][wto][p]) then
               process_updated := true;
               process_dopattern(from,wto,p);
               process_dopattern_enabled[from][wto][p] := true;
               endif;
END;END;END; -- close for
IF (!process_updated) then
	 end_while:=true;
 else process_updated:=false;
endif;END; -- close while loop 
END;



ruleset from:waypoint do 
 ruleset wto:waypoint do 
 durative_start rule " fly_start " 
( !fly_clock_started[from][wto]) & (at[from]) & (!(=[from][wto])) & all_event_true ==> 
pddlname: " fly"; 
BEGIN
fly_clock_started[from][wto]:= true;
at[from]:= false; 

END; 
END; 
END; 



ruleset from:waypoint do 
 ruleset wto:waypoint do 
 durative_end rule " fly_end " 
( fly_clock_started[from][wto]) & (( fly_clock[from][wto]) = (distance[from][wto]))   & all_event_true ==> 
pddlname: " fly"; 
BEGIN
fly_clock_started[from][wto]:= false;
fly_clock[from][wto]:= 0.0;
at[wto]:= true; 

END; 
END; 
END; 




ruleset from:waypoint do 
 ruleset wto:waypoint do 
 ruleset p:pattern do 
 durative_start rule " dopattern_start " 
( !dopattern_clock_started[from][wto][p]) & (beginat[from][p]) & (endat[wto][p]) & (at[from])  & all_event_true ==> 
pddlname: " dopattern"; 
BEGIN
dopattern_clock_started[from][wto][p]:= true;
at[from]:= false; 

END; 
END; 
END; 
END; 



ruleset from:waypoint do 
 ruleset wto:waypoint do 
 ruleset p:pattern do 
 durative_end rule " dopattern_end " 
( dopattern_clock_started[from][wto][p]) & (( dopattern_clock[from][wto][p]) = (timefor[p]))    & (active[p]) & all_event_true ==> 
pddlname: " dopattern"; 
BEGIN
dopattern_clock_started[from][wto][p]:= false;
dopattern_clock[from][wto][p]:= 0.0;
reward := increase_reward_duraction_end_dopattern(reward , rewardof[p]  );
at[wto]:= true; 

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
at[origin]:= true; 
beginat[pp76se][patrol76]:= true; 
endat[pp76se][patrol76]:= true; 
beginat[pp77se][patrol77]:= true; 
endat[pp77se][patrol77]:= true; 
beginat[ll78s][largelawn78]:= true; 
endat[ll78e][largelawn78]:= true; 
beginat[ll79s][largelawn79]:= true; 
endat[ll79e][largelawn79]:= true; 
beginat[ll80s][largelawn80]:= true; 
endat[ll80e][largelawn80]:= true; 
beginat[ll81s][largelawn81]:= true; 
endat[ll81e][largelawn81]:= true; 
beginat[ll82s][largelawn82]:= true; 
endat[ll82e][largelawn82]:= true; 
beginat[ll83s][largelawn83]:= true; 
endat[ll83e][largelawn83]:= true; 
beginat[ll84s][largelawn84]:= true; 
endat[ll84e][largelawn84]:= true; 
beginat[ll87s][largelawn87]:= true; 
endat[ll87e][largelawn87]:= true; 
beginat[ll88s][largelawn88]:= true; 
endat[ll88e][largelawn88]:= true; 
beginat[s91s][spiral91]:= true; 
endat[s91e][spiral91]:= true; 
beginat[sl66s][smalllawn66]:= true; 
endat[sl66e][smalllawn66]:= true; 
beginat[sl67s][smalllawn67]:= true; 
endat[sl67e][smalllawn67]:= true; 
beginat[sl68s][smalllawn68]:= true; 
endat[sl68e][smalllawn68]:= true; 
beginat[sl69s][smalllawn69]:= true; 
endat[sl69e][smalllawn69]:= true; 
beginat[sl70s][smalllawn70]:= true; 
endat[sl70e][smalllawn70]:= true; 
beginat[sl71s][smalllawn71]:= true; 
endat[sl71e][smalllawn71]:= true; 
beginat[sl72s][smalllawn72]:= true; 
endat[sl72e][smalllawn72]:= true; 
beginat[sl73s][smalllawn73]:= true; 
endat[sl73e][smalllawn73]:= true; 
beginat[sl74s][smalllawn74]:= true; 
endat[sl74e][smalllawn74]:= true; 
beginat[ll75s][largelawn75]:= true; 
endat[ll75e][largelawn75]:= true; 
reward := 0.0000;
rewardof[patrol76] := 235.00;
timefor[patrol76] := 308.00;
distance[origin][pp76se] := 38.000;
distance[pp76se][pp77se] := 156.00;
distance[pp76se][ll78s] := 21.000;
distance[pp76se][ll79s] := 79.000;
distance[pp76se][ll80s] := 124.00;
distance[pp76se][ll81s] := 83.000;
distance[pp76se][ll82s] := 21.000;
distance[pp76se][ll83s] := 79.000;
distance[pp76se][ll84s] := 124.00;
distance[pp76se][ll87s] := 81.000;
distance[pp76se][ll88s] := 126.00;
distance[pp76se][s91s] := 291.00;
distance[pp76se][sl66s] := 316.00;
distance[pp76se][sl67s] := 357.00;
distance[pp76se][sl68s] := 374.00;
distance[pp76se][sl69s] := 303.00;
distance[pp76se][sl70s] := 425.00;
distance[pp76se][sl71s] := 395.00;
distance[pp76se][sl72s] := 437.00;
distance[pp76se][sl73s] := 406.00;
distance[pp76se][sl74s] := 493.00;
distance[pp76se][ll75s] := 652.00;
rewardof[patrol77] := 131.00;
timefor[patrol77] := 266.00;
distance[origin][pp77se] := 154.00;
distance[pp77se][pp76se] := 156.00;
distance[pp77se][ll78s] := 135.00;
distance[pp77se][ll79s] := 77.000;
distance[pp77se][ll80s] := 60.000;
distance[pp77se][ll81s] := 139.00;
distance[pp77se][ll82s] := 135.00;
distance[pp77se][ll83s] := 77.000;
distance[pp77se][ll84s] := 60.000;
distance[pp77se][ll87s] := 75.000;
distance[pp77se][ll88s] := 61.000;
distance[pp77se][s91s] := 156.00;
distance[pp77se][sl66s] := 191.00;
distance[pp77se][sl67s] := 203.00;
distance[pp77se][sl68s] := 219.00;
distance[pp77se][sl69s] := 188.00;
distance[pp77se][sl70s] := 270.00;
distance[pp77se][sl71s] := 262.00;
distance[pp77se][sl72s] := 320.00;
distance[pp77se][sl73s] := 321.00;
distance[pp77se][sl74s] := 384.00;
distance[pp77se][ll75s] := 503.00;
rewardof[largelawn78] := 67.000;
timefor[largelawn78] := 250.00;
distance[origin][ll78s] := 30.000;
distance[ll78e][pp76se] := 76.000;
distance[ll78e][pp77se] := 80.000;
distance[ll78e][ll79s] := 3.0000;
distance[ll78e][ll80s] := 51.000;
distance[ll78e][ll81s] := 125.00;
distance[ll78e][ll82s] := 56.000;
distance[ll78e][ll83s] := 3.0000;
distance[ll78e][ll84s] := 51.000;
distance[ll78e][ll87s] := 5.0000;
distance[ll78e][ll88s] := 53.000;
distance[ll78e][s91s] := 219.00;
distance[ll78e][sl66s] := 250.00;
distance[ll78e][sl67s] := 282.00;
distance[ll78e][sl68s] := 298.00;
distance[ll78e][sl69s] := 239.00;
distance[ll78e][sl70s] := 349.00;
distance[ll78e][sl71s] := 326.00;
distance[ll78e][sl72s] := 374.00;
distance[ll78e][sl73s] := 356.00;
distance[ll78e][sl74s] := 438.00;
distance[ll78e][ll75s] := 580.00;
rewardof[largelawn79] := 36.000;
timefor[largelawn79] := 199.00;
distance[origin][ll79s] := 86.000;
distance[ll79e][pp76se] := 121.00;
distance[ll79e][pp77se] := 56.000;
distance[ll79e][ll78s] := 100.00;
distance[ll79e][ll80s] := 6.0000;
distance[ll79e][ll81s] := 84.000;
distance[ll79e][ll82s] := 100.00;
distance[ll79e][ll83s] := 44.000;
distance[ll79e][ll84s] := 6.0000;
distance[ll79e][ll87s] := 44.000;
distance[ll79e][ll88s] := 8.0000;
distance[ll79e][s91s] := 174.00;
distance[ll79e][sl66s] := 203.00;
distance[ll79e][sl67s] := 245.00;
distance[ll79e][sl68s] := 275.00;
distance[ll79e][sl69s] := 240.00;
distance[ll79e][sl70s] := 325.00;
distance[ll79e][sl71s] := 318.00;
distance[ll79e][sl72s] := 373.00;
distance[ll79e][sl73s] := 368.00;
distance[ll79e][sl74s] := 391.00;
distance[ll79e][ll75s] := 535.00;
rewardof[largelawn80] := 49.000;
timefor[largelawn80] := 207.00;
distance[origin][ll80s] := 95.000;
distance[ll80e][pp76se] := 83.000;
distance[ll80e][pp77se] := 106.00;
distance[ll80e][ll78s] := 66.000;
distance[ll80e][ll79s] := 91.000;
distance[ll80e][ll81s] := 34.000;
distance[ll80e][ll82s] := 66.000;
distance[ll80e][ll83s] := 91.000;
distance[ll80e][ll84s] := 46.000;
distance[ll80e][ll87s] := 91.000;
distance[ll80e][ll88s] := 46.000;
distance[ll80e][s91s] := 209.00;
distance[ll80e][sl66s] := 233.00;
distance[ll80e][sl67s] := 282.00;
distance[ll80e][sl68s] := 321.00;
distance[ll80e][sl69s] := 290.00;
distance[ll80e][sl70s] := 370.00;
distance[ll80e][sl71s] := 368.00;
distance[ll80e][sl72s] := 423.00;
distance[ll80e][sl73s] := 418.00;
distance[ll80e][sl74s] := 410.00;
distance[ll80e][ll75s] := 572.00;
rewardof[largelawn81] := 288.00;
timefor[largelawn81] := 266.00;
distance[origin][ll81s] := 46.000;
distance[ll81e][pp76se] := 33.000;
distance[ll81e][pp77se] := 171.00;
distance[ll81e][ll78s] := 38.000;
distance[ll81e][ll79s] := 94.000;
distance[ll81e][ll80s] := 115.00;
distance[ll81e][ll82s] := 38.000;
distance[ll81e][ll83s] := 94.000;
distance[ll81e][ll84s] := 115.00;
distance[ll81e][ll87s] := 96.000;
distance[ll81e][ll88s] := 116.00;
distance[ll81e][s91s] := 280.00;
distance[ll81e][sl66s] := 304.00;
distance[ll81e][sl67s] := 352.00;
distance[ll81e][sl68s] := 389.00;
distance[ll81e][sl69s] := 325.00;
distance[ll81e][sl70s] := 439.00;
distance[ll81e][sl71s] := 415.00;
distance[ll81e][sl72s] := 460.00;
distance[ll81e][sl73s] := 433.00;
distance[ll81e][sl74s] := 477.00;
distance[ll81e][ll75s] := 641.00;
rewardof[largelawn82] := 67.000;
timefor[largelawn82] := 250.00;
distance[origin][ll82s] := 30.000;
distance[ll82e][pp76se] := 76.000;
distance[ll82e][pp77se] := 80.000;
distance[ll82e][ll78s] := 56.000;
distance[ll82e][ll79s] := 3.0000;
distance[ll82e][ll80s] := 51.000;
distance[ll82e][ll81s] := 125.00;
distance[ll82e][ll83s] := 3.0000;
distance[ll82e][ll84s] := 51.000;
distance[ll82e][ll87s] := 5.0000;
distance[ll82e][ll88s] := 53.000;
distance[ll82e][s91s] := 219.00;
distance[ll82e][sl66s] := 250.00;
distance[ll82e][sl67s] := 282.00;
distance[ll82e][sl68s] := 298.00;
distance[ll82e][sl69s] := 239.00;
distance[ll82e][sl70s] := 349.00;
distance[ll82e][sl71s] := 326.00;
distance[ll82e][sl72s] := 374.00;
distance[ll82e][sl73s] := 356.00;
distance[ll82e][sl74s] := 438.00;
distance[ll82e][ll75s] := 580.00;
rewardof[largelawn83] := 36.000;
timefor[largelawn83] := 199.00;
distance[origin][ll83s] := 86.000;
distance[ll83e][pp76se] := 121.00;
distance[ll83e][pp77se] := 56.000;
distance[ll83e][ll78s] := 100.00;
distance[ll83e][ll79s] := 44.000;
distance[ll83e][ll80s] := 6.0000;
distance[ll83e][ll81s] := 84.000;
distance[ll83e][ll82s] := 100.00;
distance[ll83e][ll84s] := 6.0000;
distance[ll83e][ll87s] := 44.000;
distance[ll83e][ll88s] := 8.0000;
distance[ll83e][s91s] := 174.00;
distance[ll83e][sl66s] := 203.00;
distance[ll83e][sl67s] := 245.00;
distance[ll83e][sl68s] := 275.00;
distance[ll83e][sl69s] := 240.00;
distance[ll83e][sl70s] := 325.00;
distance[ll83e][sl71s] := 318.00;
distance[ll83e][sl72s] := 373.00;
distance[ll83e][sl73s] := 368.00;
distance[ll83e][sl74s] := 391.00;
distance[ll83e][ll75s] := 535.00;
rewardof[largelawn84] := 49.000;
timefor[largelawn84] := 207.00;
distance[origin][ll84s] := 95.000;
distance[ll84e][pp76se] := 83.000;
distance[ll84e][pp77se] := 106.00;
distance[ll84e][ll78s] := 66.000;
distance[ll84e][ll79s] := 91.000;
distance[ll84e][ll80s] := 46.000;
distance[ll84e][ll81s] := 34.000;
distance[ll84e][ll82s] := 66.000;
distance[ll84e][ll83s] := 91.000;
distance[ll84e][ll87s] := 91.000;
distance[ll84e][ll88s] := 46.000;
distance[ll84e][s91s] := 209.00;
distance[ll84e][sl66s] := 233.00;
distance[ll84e][sl67s] := 282.00;
distance[ll84e][sl68s] := 321.00;
distance[ll84e][sl69s] := 290.00;
distance[ll84e][sl70s] := 370.00;
distance[ll84e][sl71s] := 368.00;
distance[ll84e][sl72s] := 423.00;
distance[ll84e][sl73s] := 418.00;
distance[ll84e][sl74s] := 410.00;
distance[ll84e][ll75s] := 572.00;
rewardof[largelawn87] := 58.000;
timefor[largelawn87] := 319.00;
distance[origin][ll87s] := 88.000;
distance[ll87e][pp76se] := 121.00;
distance[ll87e][pp77se] := 54.000;
distance[ll87e][ll78s] := 101.00;
distance[ll87e][ll79s] := 44.000;
distance[ll87e][ll80s] := 8.0000;
distance[ll87e][ll81s] := 86.000;
distance[ll87e][ll82s] := 101.00;
distance[ll87e][ll83s] := 44.000;
distance[ll87e][ll84s] := 8.0000;
distance[ll87e][ll88s] := 9.0000;
distance[ll87e][s91s] := 173.00;
distance[ll87e][sl66s] := 203.00;
distance[ll87e][sl67s] := 244.00;
distance[ll87e][sl68s] := 272.00;
distance[ll87e][sl69s] := 238.00;
distance[ll87e][sl70s] := 323.00;
distance[ll87e][sl71s] := 316.00;
distance[ll87e][sl72s] := 371.00;
distance[ll87e][sl73s] := 366.00;
distance[ll87e][sl74s] := 391.00;
distance[ll87e][ll75s] := 534.00;
rewardof[largelawn88] := 77.000;
timefor[largelawn88] := 331.00;
distance[origin][ll88s] := 95.000;
distance[ll88e][pp76se] := 85.000;
distance[ll88e][pp77se] := 106.00;
distance[ll88e][ll78s] := 68.000;
distance[ll88e][ll79s] := 91.000;
distance[ll88e][ll80s] := 46.000;
distance[ll88e][ll81s] := 34.000;
distance[ll88e][ll82s] := 68.000;
distance[ll88e][ll83s] := 91.000;
distance[ll88e][ll84s] := 46.000;
distance[ll88e][ll87s] := 91.000;
distance[ll88e][s91s] := 208.00;
distance[ll88e][sl66s] := 232.00;
distance[ll88e][sl67s] := 281.00;
distance[ll88e][sl68s] := 321.00;
distance[ll88e][sl69s] := 290.00;
distance[ll88e][sl70s] := 370.00;
distance[ll88e][sl71s] := 368.00;
distance[ll88e][sl72s] := 423.00;
distance[ll88e][sl73s] := 418.00;
distance[ll88e][sl74s] := 408.00;
distance[ll88e][ll75s] := 571.00;
rewardof[spiral91] := 381.00;
timefor[spiral91] := 1099.0;
distance[origin][s91s] := 260.00;
distance[s91e][pp76se] := 288.00;
distance[s91e][pp77se] := 176.00;
distance[s91e][ll78s] := 271.00;
distance[s91e][ll79s] := 226.00;
distance[s91e][ll80s] := 179.00;
distance[s91e][ll81s] := 220.00;
distance[s91e][ll82s] := 271.00;
distance[s91e][ll83s] := 226.00;
distance[s91e][ll84s] := 179.00;
distance[s91e][ll87s] := 226.00;
distance[s91e][ll88s] := 177.00;
distance[s91e][sl66s] := 40.000;
distance[s91e][sl67s] := 128.00;
distance[s91e][sl68s] := 221.00;
distance[s91e][sl69s] := 309.00;
distance[s91e][sl70s] := 250.00;
distance[s91e][sl71s] := 340.00;
distance[s91e][sl72s] := 414.00;
distance[s91e][sl73s] := 451.00;
distance[s91e][sl74s] := 209.00;
distance[s91e][ll75s] := 519.00;
rewardof[smalllawn66] := 138.00;
timefor[smalllawn66] := 374.00;
distance[origin][sl66s] := 285.00;
distance[sl66e][pp76se] := 245.00;
distance[sl66e][pp77se] := 122.00;
distance[sl66e][ll78s] := 228.00;
distance[sl66e][ll79s] := 176.00;
distance[sl66e][ll80s] := 130.00;
distance[sl66e][ll81s] := 183.00;
distance[sl66e][ll82s] := 228.00;
distance[sl66e][ll83s] := 176.00;
distance[sl66e][ll84s] := 130.00;
distance[sl66e][ll87s] := 175.00;
distance[sl66e][ll88s] := 129.00;
distance[sl66e][s91s] := 49.000;
distance[sl66e][sl67s] := 129.00;
distance[sl66e][sl68s] := 202.00;
distance[sl66e][sl69s] := 264.00;
distance[sl66e][sl70s] := 240.00;
distance[sl66e][sl71s] := 305.00;
distance[sl66e][sl72s] := 376.00;
distance[sl66e][sl73s] := 405.00;
distance[sl66e][sl74s] := 262.00;
distance[sl66e][ll75s] := 469.00;
rewardof[smalllawn67] := 240.00;
timefor[smalllawn67] := 401.00;
distance[origin][sl67s] := 332.00;
distance[sl67e][pp76se] := 275.00;
distance[sl67e][pp77se] := 121.00;
distance[sl67e][ll78s] := 255.00;
distance[sl67e][ll79s] := 197.00;
distance[sl67e][ll80s] := 161.00;
distance[sl67e][ll81s] := 224.00;
distance[sl67e][ll82s] := 255.00;
distance[sl67e][ll83s] := 197.00;
distance[sl67e][ll84s] := 161.00;
distance[sl67e][ll87s] := 195.00;
distance[sl67e][ll88s] := 159.00;
distance[sl67e][s91s] := 44.000;
distance[sl67e][sl66s] := 83.000;
distance[sl67e][sl68s] := 140.00;
distance[sl67e][sl69s] := 214.00;
distance[sl67e][sl70s] := 182.00;
distance[sl67e][sl71s] := 246.00;
distance[sl67e][sl72s] := 318.00;
distance[sl67e][sl73s] := 356.00;
distance[sl67e][sl74s] := 277.00;
distance[sl67e][ll75s] := 450.00;
rewardof[smalllawn68] := 135.00;
timefor[smalllawn68] := 399.00;
distance[origin][sl68s] := 369.00;
distance[sl68e][pp76se] := 289.00;
distance[sl68e][pp77se] := 133.00;
distance[sl68e][ll78s] := 268.00;
distance[sl68e][ll79s] := 210.00;
distance[sl68e][ll80s] := 193.00;
distance[sl68e][ll81s] := 269.00;
distance[sl68e][ll82s] := 268.00;
distance[sl68e][ll83s] := 210.00;
distance[sl68e][ll84s] := 193.00;
distance[sl68e][ll87s] := 208.00;
distance[sl68e][ll88s] := 194.00;
distance[sl68e][s91s] := 115.00;
distance[sl68e][sl66s] := 151.00;
distance[sl68e][sl67s] := 104.00;
distance[sl68e][sl69s] := 146.00;
distance[sl68e][sl70s] := 137.00;
distance[sl68e][sl71s] := 170.00;
distance[sl68e][sl72s] := 242.00;
distance[sl68e][sl73s] := 285.00;
distance[sl68e][sl74s] := 332.00;
distance[sl68e][ll75s] := 505.00;
rewardof[smalllawn69] := 165.00;
timefor[smalllawn69] := 323.00;
distance[origin][sl69s] := 316.00;
distance[sl69e][pp76se] := 252.00;
distance[sl69e][pp77se] := 131.00;
distance[sl69e][ll78s] := 236.00;
distance[sl69e][ll79s] := 183.00;
distance[sl69e][ll80s] := 188.00;
distance[sl69e][ll81s] := 267.00;
distance[sl69e][ll82s] := 236.00;
distance[sl69e][ll83s] := 183.00;
distance[sl69e][ll84s] := 188.00;
distance[sl69e][ll87s] := 181.00;
distance[sl69e][ll88s] := 189.00;
distance[sl69e][s91s] := 213.00;
distance[sl69e][sl66s] := 253.00;
distance[sl69e][sl67s] := 217.00;
distance[sl69e][sl68s] := 167.00;
distance[sl69e][sl70s] := 216.00;
distance[sl69e][sl71s] := 143.00;
distance[sl69e][sl72s] := 191.00;
distance[sl69e][sl73s] := 195.00;
distance[sl69e][sl74s] := 443.00;
distance[sl69e][ll75s] := 577.00;
rewardof[smalllawn70] := 194.00;
timefor[smalllawn70] := 513.00;
distance[origin][sl70s] := 419.00;
distance[sl70e][pp76se] := 340.00;
distance[sl70e][pp77se] := 184.00;
distance[sl70e][ll78s] := 319.00;
distance[sl70e][ll79s] := 261.00;
distance[sl70e][ll80s] := 244.00;
distance[sl70e][ll81s] := 320.00;
distance[sl70e][ll82s] := 319.00;
distance[sl70e][ll83s] := 261.00;
distance[sl70e][ll84s] := 244.00;
distance[sl70e][ll87s] := 259.00;
distance[sl70e][ll88s] := 245.00;
distance[sl70e][s91s] := 141.00;
distance[sl70e][sl66s] := 170.00;
distance[sl70e][sl67s] := 96.000;
distance[sl70e][sl68s] := 34.000;
distance[sl70e][sl69s] := 157.00;
distance[sl70e][sl71s] := 148.00;
distance[sl70e][sl72s] := 223.00;
distance[sl70e][sl73s] := 283.00;
distance[sl70e][sl74s] := 329.00;
distance[sl70e][ll75s] := 550.00;
rewardof[smalllawn71] := 243.00;
timefor[smalllawn71] := 622.00;
distance[origin][sl71s] := 406.00;
distance[sl71e][pp76se] := 320.00;
distance[sl71e][pp77se] := 179.00;
distance[sl71e][ll78s] := 302.00;
distance[sl71e][ll79s] := 246.00;
distance[sl71e][ll80s] := 240.00;
distance[sl71e][ll81s] := 319.00;
distance[sl71e][ll82s] := 302.00;
distance[sl71e][ll83s] := 246.00;
distance[sl71e][ll84s] := 240.00;
distance[sl71e][ll87s] := 244.00;
distance[sl71e][ll88s] := 240.00;
distance[sl71e][s91s] := 205.00;
distance[sl71e][sl66s] := 240.00;
distance[sl71e][sl67s] := 180.00;
distance[sl71e][sl68s] := 102.00;
distance[sl71e][sl69s] := 71.000;
distance[sl71e][sl70s] := 145.00;
distance[sl71e][sl72s] := 154.00;
distance[sl71e][sl73s] := 198.00;
distance[sl71e][sl74s] := 413.00;
distance[sl71e][ll75s] := 587.00;
rewardof[smalllawn72] := 166.00;
timefor[smalllawn72] := 526.00;
distance[origin][sl72s] := 451.00;
distance[sl72e][pp76se] := 373.00;
distance[sl72e][pp77se] := 249.00;
distance[sl72e][ll78s] := 357.00;
distance[sl72e][ll79s] := 305.00;
distance[sl72e][ll80s] := 309.00;
distance[sl72e][ll81s] := 387.00;
distance[sl72e][ll82s] := 357.00;
distance[sl72e][ll83s] := 305.00;
distance[sl72e][ll84s] := 309.00;
distance[sl72e][ll87s] := 303.00;
distance[sl72e][ll88s] := 310.00;
distance[sl72e][s91s] := 289.00;
distance[sl72e][sl66s] := 324.00;
distance[sl72e][sl67s] := 258.00;
distance[sl72e][sl68s] := 164.00;
distance[sl72e][sl69s] := 71.000;
distance[sl72e][sl70s] := 191.00;
distance[sl72e][sl71s] := 36.000;
distance[sl72e][sl73s] := 124.00;
distance[sl72e][sl74s] := 491.00;
distance[sl72e][ll75s] := 670.00;
rewardof[smalllawn73] := 95.000;
timefor[smalllawn73] := 266.00;
distance[origin][sl73s] := 425.00;
distance[sl73e][pp76se] := 350.00;
distance[sl73e][pp77se] := 265.00;
distance[sl73e][ll78s] := 339.00;
distance[sl73e][ll79s] := 298.00;
distance[sl73e][ll80s] := 317.00;
distance[sl73e][ll81s] := 395.00;
distance[sl73e][ll82s] := 339.00;
distance[sl73e][ll83s] := 298.00;
distance[sl73e][ll84s] := 317.00;
distance[sl73e][ll87s] := 296.00;
distance[sl73e][ll88s] := 319.00;
distance[sl73e][s91s] := 350.00;
distance[sl73e][sl66s] := 389.00;
distance[sl73e][sl67s] := 338.00;
distance[sl73e][sl68s] := 256.00;
distance[sl73e][sl69s] := 93.000;
distance[sl73e][sl70s] := 290.00;
distance[sl73e][sl71s] := 137.00;
distance[sl73e][sl72s] := 117.00;
distance[sl73e][sl74s] := 571.00;
distance[sl73e][ll75s] := 717.00;
rewardof[smalllawn74] := 134.00;
timefor[smalllawn74] := 333.00;
distance[origin][sl74s] := 459.00;
distance[sl74e][pp76se] := 422.00;
distance[sl74e][pp77se] := 316.00;
distance[sl74e][ll78s] := 405.00;
distance[sl74e][ll79s] := 365.00;
distance[sl74e][ll80s] := 317.00;
distance[sl74e][ll81s] := 347.00;
distance[sl74e][ll82s] := 405.00;
distance[sl74e][ll83s] := 365.00;
distance[sl74e][ll84s] := 317.00;
distance[sl74e][ll87s] := 365.00;
distance[sl74e][ll88s] := 315.00;
distance[sl74e][s91s] := 173.00;
distance[sl74e][sl66s] := 133.00;
distance[sl74e][sl67s] := 189.00;
distance[sl74e][sl68s] := 292.00;
distance[sl74e][sl69s] := 425.00;
distance[sl74e][sl70s] := 298.00;
distance[sl74e][sl71s] := 431.00;
distance[sl74e][sl72s] := 507.00;
distance[sl74e][sl73s] := 562.00;
distance[sl74e][ll75s] := 651.00;
rewardof[largelawn75] := 291.00;
timefor[largelawn75] := 1600.0;
distance[origin][ll75s] := 621.00;
distance[ll75e][pp76se] := 454.00;
distance[ll75e][pp77se] := 303.00;
distance[ll75e][ll78s] := 435.00;
distance[ll75e][ll79s] := 378.00;
distance[ll75e][ll80s] := 335.00;
distance[ll75e][ll81s] := 394.00;
distance[ll75e][ll82s] := 435.00;
distance[ll75e][ll83s] := 378.00;
distance[ll75e][ll84s] := 335.00;
distance[ll75e][ll87s] := 377.00;
distance[ll75e][ll88s] := 333.00;
distance[ll75e][s91s] := 163.00;
distance[ll75e][sl66s] := 146.00;
distance[ll75e][sl67s] := 102.00;
distance[ll75e][sl68s] := 169.00;
distance[ll75e][sl69s] := 336.00;
distance[ll75e][sl70s] := 154.00;
distance[ll75e][sl71s] := 310.00;
distance[ll75e][sl72s] := 383.00;
distance[ll75e][sl73s] := 457.00;
distance[ll75e][sl74s] := 174.00;

-- durative action "dopattern" clock initialization
 for from : waypoint do 
   for wto : waypoint do 
     for p : pattern do 
       dopattern_clock_started[from][wto][p]:= false;
      dopattern_clock[from][wto][p]:= 0.0;
END; END; END; -- for ends

-- durative action "fly" clock initialization
 for from : waypoint do 
   for wto : waypoint do 
     fly_clock_started[from][wto]:= false;
    fly_clock[from][wto]:= 0.0;
END; END; -- for ends

all_event_true := true;
END; -- close startstate

goal "enjoy" 
 ((( reward) >= (1.0000))); 

invariant "todo bien" 
 all_event_true;
metric: maximize;


