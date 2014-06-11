type
	 real_type: real(3,3);
	 integer: -1000..1000;

	block : Enum {b1, b2, b3, b4, b5, b6, b7, b8};

const 
	 T:1;


var 

	fun[pddlname:fun;] :  real_type;
	h_n : integer;
	g_n : integer;
	f_n : integer;


	on[pddlname:on;] : Array [block] of Array [block] of  boolean;
	ontable[pddlname:ontable;] : Array [block] of  boolean;
	isclear[pddlname:isclear;] : Array [block] of  boolean;
	handempty[pddlname:handempty;] :  boolean;
	holding[pddlname:holding;] : Array [block] of  boolean;


-- External function declaration 

procedure set_on( x : block ; y : block ;  value : boolean);
BEGIN
	on[x][y] := value;
END;

function get_on( x : block ; y : block): boolean;
BEGIN
	return 	on[x][y];
END;

procedure set_ontable( x : block ;  value : boolean);
BEGIN
	ontable[x] := value;
END;

function get_ontable( x : block): boolean;
BEGIN
	return 	ontable[x];
END;

procedure set_isclear( x : block ;  value : boolean);
BEGIN
	isclear[x] := value;
END;

function get_isclear( x : block): boolean;
BEGIN
	return 	isclear[x];
END;

procedure set_handempty(  value : boolean);
BEGIN
	handempty := value;
END;

function get_handempty(): boolean;
BEGIN
	return 	handempty;
END;

procedure set_holding( x : block ;  value : boolean);
BEGIN
	holding[x] := value;
END;

function get_holding( x : block): boolean;
BEGIN
	return 	holding[x];
END;




ruleset x:block do 
 action rule " pick-up " 
(isclear[x]) & (ontable[x]) & (handempty) ==> 
pddlname: " pick-up"; 
BEGIN
holding[x]:= true; 
ontable[x]:= false; 
isclear[x]:= false; 
handempty:= false; 

END; 
END;

ruleset x:block do 
 action rule " put-down " 
holding[x] ==> 
pddlname: " put-down"; 
BEGIN
isclear[x]:= true; 
handempty:= true; 
ontable[x]:= true; 
holding[x]:= false; 

END; 
END;

ruleset x:block do 
 ruleset y:block do 
 action rule " stack " 
(holding[x]) & (isclear[y]) ==> 
pddlname: " stack"; 
BEGIN
isclear[x]:= true; 
handempty:= true; 
on[x][y]:= true; 
holding[x]:= false; 
isclear[y]:= false; 

END; 
END; 
END;

ruleset x:block do 
 ruleset y:block do 
 action rule " unstack " 
(on[x][y]) & (isclear[x]) & (handempty) ==> 
pddlname: " unstack"; 
BEGIN
holding[x]:= true; 
isclear[y]:= true; 
isclear[x]:= false; 
handempty:= false; 
on[x][y]:= false; 

END; 
END; 
END;

clock rule " time passing " 
 (true) ==> 
BEGIN 
 	 
END;


startstate "start" 
BEGIN 
for x : block do 
  for y : block do 
    set_on(x,y, false);
END; END;  -- close for
   for x : block do 
     set_ontable(x, false);
END;  -- close for
   for x : block do 
     set_isclear(x, false);
END;  -- close for
   set_handempty(false);

   for x : block do 
     set_holding(x, false);
END;  -- close for
   fun := 0.0 ;

isclear[b1]:= true;
isclear[b7]:= true;
ontable[b4]:= true;
ontable[b8]:= true; 
on[b1][b6]:= true;
on[b2][b5]:= true;
on[b3][b2]:= true;
on[b5][b4]:= true;
on[b6][b3]:= true;
on[b7][b8]:= true;
handempty:= true; 
h_n := 0;
g_n := 0;
f_n := h_n + g_n;
END; -- close startstate

goal "enjoy" 
 (on[b1][b6]) & (on[b3][b1]) & (on[b4][b3]) & (on[b5][b8]) & (on[b6][b7]) & (on[b7][b5]); 


metric: minimize;


