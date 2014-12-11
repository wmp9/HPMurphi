type
	 real_type: real(13,13);
	 integer: -1000..1000;


const 
	 T:0.01;


var 
	h_n : integer;
	g_n : integer;
	f_n : integer;
	capacitance[pddlname:capacitance;] :  real_type;
	resistance[pddlname:resistance;] :  real_type;
	ringtime[pddlname:ringtime;] :  real_type;


	windowclosed[pddlname:windowclosed;] :  boolean;
	windowopen[pddlname:windowopen;] :  boolean;
	magnetoperational[pddlname:magnetoperational;] :  boolean;
	freshair[pddlname:freshair;] :  boolean;
	circuit[pddlname:circuit;] :  boolean;
	alarmdisabled[pddlname:alarmdisabled;] :  boolean;
	alarmenabled[pddlname:alarmenabled;] :  boolean;
	voltage[pddlname:voltage;] :  boolean;
	ringing[pddlname:ringing;] :  boolean;
	almostawake[pddlname:almostawake;] :  boolean;
	deeplyasleep[pddlname:deeplyasleep;] :  boolean;
	awake[pddlname:awake;] :  boolean;


-- External function declaration 

externfun increase_ringtime_process_ring(ringtime : real_type ; T : real_type ; ): real_type "sb1.h" ;
externfun increase_capacitance_process_chargecapacitor(capacitance : real_type ; T : real_type ; resistance : real_type ; ): real_type ;
procedure set_windowclosed(  value : boolean);
BEGIN
	windowclosed := value;
END;

function get_windowclosed(): boolean;
BEGIN
	return 	windowclosed;
END;

procedure set_windowopen(  value : boolean);
BEGIN
	windowopen := value;
END;

function get_windowopen(): boolean;
BEGIN
	return 	windowopen;
END;

procedure set_magnetoperational(  value : boolean);
BEGIN
	magnetoperational := value;
END;

function get_magnetoperational(): boolean;
BEGIN
	return 	magnetoperational;
END;

procedure set_freshair(  value : boolean);
BEGIN
	freshair := value;
END;

function get_freshair(): boolean;
BEGIN
	return 	freshair;
END;

procedure set_circuit(  value : boolean);
BEGIN
	circuit := value;
END;

function get_circuit(): boolean;
BEGIN
	return 	circuit;
END;

procedure set_alarmdisabled(  value : boolean);
BEGIN
	alarmdisabled := value;
END;

function get_alarmdisabled(): boolean;
BEGIN
	return 	alarmdisabled;
END;

procedure set_alarmenabled(  value : boolean);
BEGIN
	alarmenabled := value;
END;

function get_alarmenabled(): boolean;
BEGIN
	return 	alarmenabled;
END;

procedure set_voltage(  value : boolean);
BEGIN
	voltage := value;
END;

function get_voltage(): boolean;
BEGIN
	return 	voltage;
END;

procedure set_ringing(  value : boolean);
BEGIN
	ringing := value;
END;

function get_ringing(): boolean;
BEGIN
	return 	ringing;
END;

procedure set_almostawake(  value : boolean);
BEGIN
	almostawake := value;
END;

function get_almostawake(): boolean;
BEGIN
	return 	almostawake;
END;

procedure set_deeplyasleep(  value : boolean);
BEGIN
	deeplyasleep := value;
END;

function get_deeplyasleep(): boolean;
BEGIN
	return 	deeplyasleep;
END;

procedure set_awake(  value : boolean);
BEGIN
	awake := value;
END;

function get_awake(): boolean;
BEGIN
	return 	awake;
END;




function makecircuit () : boolean; 
BEGIN
IF ((!(magnetoperational)) & (!(circuit))) THEN 
circuit:= true; 
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;

function alarmtriggered () : boolean; 
BEGIN
IF ((circuit) & (alarmdisabled) & (voltage)) THEN 
alarmenabled:= true; 
ringing:= true; 
alarmdisabled:= false; 
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;

function voltageavailable () : boolean; 
BEGIN
IF ((( capacitance) >= (5.0000000000))) THEN 
voltage:= true; 
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;

procedure ring (); 
BEGIN
IF (ringing) THEN 
ringtime := increase_ringtime_process_ring(ringtime , T  );

ENDIF ; 

END;

function rouseprincess () : boolean; 
BEGIN
IF ((ringing) & ((( ringtime) >= (10.000000000))) & (deeplyasleep)) THEN 
almostawake:= true; 
deeplyasleep:= false; 
		 return true; 
 	 ELSE return false;
	 ENDIF;

END;

procedure chargecapacitor (); 
BEGIN
IF ((circuit) & (!(voltage))) THEN 
capacitance := increase_capacitance_process_chargecapacitor(capacitance , T , resistance  );

ENDIF ; 

END;



procedure event_check();
 var -- local vars declaration 
   event_triggered : boolean;
   makecircuit_triggered :  boolean;
   alarmtriggered_triggered :  boolean;
   voltageavailable_triggered :  boolean;
   rouseprincess_triggered :  boolean;
BEGIN
 event_triggered := true;
   makecircuit_triggered := false;
   alarmtriggered_triggered := false;
   voltageavailable_triggered := false;
   rouseprincess_triggered := false;
while (event_triggered) do 
 event_triggered := false;
   if(! makecircuit_triggered) then 
   makecircuit_triggered := makecircuit();
   event_triggered := event_triggered | makecircuit_triggered; 
   endif;

   if(! alarmtriggered_triggered) then 
   alarmtriggered_triggered := alarmtriggered();
   event_triggered := event_triggered | alarmtriggered_triggered; 
   endif;

   if(! voltageavailable_triggered) then 
   voltageavailable_triggered := voltageavailable();
   event_triggered := event_triggered | voltageavailable_triggered; 
   endif;

   if(! rouseprincess_triggered) then 
   rouseprincess_triggered := rouseprincess();
   event_triggered := event_triggered | rouseprincess_triggered; 
   endif;

END; -- close while loop 
END;



procedure apply_continuous_change();
 var -- local vars declaration 
   process_updated : boolean;
 end_while : boolean;   ring_enabled :  boolean;
   chargecapacitor_enabled :  boolean;
BEGIN
 process_updated := false; end_while := false;
   ring_enabled := false;
   chargecapacitor_enabled := false;
while (!end_while) do 
    if (ringing &  !ring_enabled) then
   process_updated := true;
   ring();
   ring_enabled := true;
   endif;

   if ((circuit) & (!(voltage)) &  !chargecapacitor_enabled) then
   process_updated := true;
   chargecapacitor();
   chargecapacitor_enabled := true;
   endif;

IF (!process_updated) then
	 end_while:=true;
 else process_updated:=false;
endif;END; -- close while loop 
END;

action rule " openwindow " 
(windowclosed) & (magnetoperational) ==> 
pddlname: " openwindow"; 
BEGIN
windowopen:= true; 
freshair:= true; 
magnetoperational:= false; 
windowclosed:= false; 

END;

action rule " closewindow " 
(windowopen) & (!(magnetoperational)) ==> 
pddlname: " closewindow"; 
BEGIN
magnetoperational:= true; 
windowclosed:= true; 
windowopen:= false; 

END;

action rule " kiss " 
almostawake ==> 
pddlname: " kiss"; 
BEGIN
awake:= true; 
almostawake:= false; 

END;

clock rule " time passing " 
 (true) ==> 
BEGIN 
 	 event_check();
	 apply_continuous_change(); 
END;


startstate "start" 
BEGIN 
set_windowclosed(false);

   set_windowopen(false);

   set_magnetoperational(false);

   set_freshair(false);

   set_circuit(false);

   set_alarmdisabled(false);

   set_alarmenabled(false);

   set_voltage(false);

   set_ringing(false);

   set_almostawake(false);

   set_deeplyasleep(false);

   set_awake(false);

   capacitance := 0.0 ;

   resistance := 0.0 ;

   ringtime := 0.0 ;

windowclosed:= true; 
magnetoperational:= true; 
alarmdisabled:= true; 
deeplyasleep:= true; 
capacitance := 0.0000000000;
resistance := 2.0000000000;
ringtime := 0.0000000000;
END; -- close startstate

goal "enjoy" 
 (freshair) & (deeplyasleep); 

metric: minimize;


