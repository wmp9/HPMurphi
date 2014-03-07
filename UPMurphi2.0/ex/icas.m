type
	real_type: real(4,10);
	--real_fuel: real(7,10);
	real_fuel: 0..18000;
const 
	T:1.0;
	rho:0.1; --kg/m^3 is about 1/12 of the Earth, 0.1 kg/m^3  
	m:71.73; -- Kg
	g:380.0; -- cm/s^2
	h:0; 
	A:2.5; -- m^2
	Crr: 50; 
	Cd: 25;
	mu: 0.8;
	Voltage: 10.0; --Volts
	restart_energy_cost : 40;
	--cooling_constant: 10;
	cooling_total_time: 5;
	g_c: 25; -- Watt;
	g_s: 10; -- Watt
	distance_to_reach: 200; -- cm
	min_distance_to_cool: 120; -- stops and cools down after each meter 
	v_max:10; -- cm/s

var 
	engineblown_value : boolean;
	running_value : boolean;
	cooling_value : boolean;
	cooling_prepare: boolean;
	restarting: boolean;
	cooling_time: 0..10;
	--cooling_complete: boolean;
	a : real_type; 
	d : real_type;
	f : real_fuel; -- energy is in Coulomb (C)
	v : real_type;
	
  externfun update1_v (a:real_type ; c:real_type) : real_type "icas_lib.h";
  externfun update2_v (a:real_type ; c:real_type) : real_type;
  externfun update_d (a:real_type; b:real_type; c:real_type) : real_type;
  externfun update_f(rho:real_type ; v:real_type ; m:real_type ; g:real_type ; a:real_type ; h:real_type; f:real_fuel):real_fuel;
  externfun update_cooling(f:real_fuel;g:real_type;v:real_type;m:real_type):real_fuel;
  externfun update_f_at_startup(rho:real_type ; v:real_type ; m:real_type ; g:real_type ; a:real_type ; h:real_type; f:real_fuel):real_fuel;

  function inRange():boolean;
  begin
  	return (a>= -6 & a<= 5  & v>=0.0 & d>=0.0 ); -- [-a_min+380*mu , a_max+380*mu] con a_min=-5 e a_max=5 (i valori sono conformi al fatto che v_max=5 cm/s)
  end;




procedure dynamic_check();
var a_old:real_type;
    v_old:real_type;
    d_old:real_type;
    f_old:real_fuel;
    cooling_value_old:boolean;
    cooling_prepare_old: boolean;	
    restarting_old: boolean;
    --cooling_complete_old: boolean;
    cooling_time_old: 0..10;

BEGIN
a_old := a;
v_old := v;
d_old := d;
f_old := f;
cooling_value_old:=cooling_value;
cooling_prepare_old:= cooling_prepare;	
restarting_old:= restarting_old;
--cooling_complete_old:= cooling_complete_old;
cooling_time_old:= cooling_time;


--cooling_check()
--IF ((running_value) & d_old >= min_distance_to_cool & !cooling_complete_old) THEN
IF ((running_value) & d_old >= min_distance_to_cool & cooling_time_old = 0) THEN  
	cooling_prepare := true; 
ENDIF ; 


-- cooling_phase energy update;
IF (cooling_value_old & cooling_time_old <= cooling_total_time) THEN
	f:= update_cooling(f_old,g,v_old,m);
ENDIF;

--moving();
IF ((running_value)) THEN 
	d := update_d(d_old,v_old,a);
	v := update1_v(v_old,a);
	IF (!cooling_value_old) THEN  -- this happens only when NOT in cooling phase
		f := update_f(rho,v_old,m,g,a,h,f_old);
	ENDIF;

ENDIF ;



-- end of cooling_phase;
IF (cooling_value_old & cooling_time_old = cooling_total_time) THEN
	running_value:=true;
	cooling_value:=false;
	--cooling_complete := true;
	restarting := true; -- forces a restart phase
ENDIF;


--engineexplode();
IF ((running_value) & v_old > v_max) THEN 
	engineblown_value:= true; 	
	running_value:= false; 
	a := 0.0;
ENDIF ; 

--start cooling;
IF (v >= 0.0 & v <= 1.0 & cooling_prepare) THEN
	a := 0.0;
	v := 0.0;
	cooling_prepare:= false;
	cooling_value:= true;
ENDIF;


END;


action rule " accelerate " 
(running_value & inRange() & !cooling_value & !cooling_prepare & !restarting) ==> 
BEGIN
running_value:= true;
a := a + 1.5;
dynamic_check(); 


END;

action rule " decelerate " 
(running_value & inRange() & !cooling_value & !restarting) ==> 
BEGIN
running_value:= true; 
a := a - 1.5;
dynamic_check();
END;

action rule " costant " 
(running_value & inRange() & !cooling_value & !cooling_prepare & !restarting) ==> 
BEGIN
dynamic_check();
END;


rule " cooling " 
(running_value & inRange() & cooling_value & !cooling_prepare) ==> 
BEGIN
IF (v=0.0 & a = 0.0) THEN
	cooling_time := cooling_time +1;
ENDIF;
dynamic_check();
END;

rule " restart after cooling "
(running_value & inRange() & cooling_time = cooling_total_time & restarting) ==> 
BEGIN
f:= update_cooling(f,g,v,m);
a := 0;
v := 0.0;
restarting := false;
END;


startstate "start" 
 BEGIN 
running_value:= true; 
cooling_value := false;
engineblown_value:= false; 
d := 0.00;
a := 0.0; -- 3.8 * mu with mu = 0.8 dynamic friction coefficient wheel/ground
v := 0.00;
f := 18000; -- in Coulomb, starting from 5Amph. C=5*3600/2 since we assume to start as 50% of the full charge
cooling_prepare:= false;
cooling_time := 0;
restarting:= false;
--cooling_complete := false;
END;

goal "enjoy" 
( d >= (distance_to_reach) & !engineblown_value &  f>=17926 & v>=0.0 & v<=0.1 & cooling_time = cooling_total_time);

metric: minimize;
