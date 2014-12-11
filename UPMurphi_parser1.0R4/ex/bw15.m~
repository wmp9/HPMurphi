type
	 real_type: real(3,3);
	 integer: -1000..1000;

	block : Enum {b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15};

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
 	 event_check();
	 apply_continuous_change(); 
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

handempty:= true; 
on[b1][b6]:= true; 
ontable[b2]:= true; 
on[b3][b12]:= true; 
on[b4][b11]:= true; 
on[b5][b2]:= true; 
ontable[b6]:= true; 
on[b7][b14]:= true; 
on[b8][b10]:= true; 
on[b9][b15]:= true; 
ontable[b10]:= true; 
on[b11][b9]:= true; 
on[b12][b13]:= true; 
on[b13][b7]:= true; 
on[b14][b8]:= true; 
on[b15][b3]:= true; 
isclear[b1]:= true; 
isclear[b4]:= true; 
isclear[b5]:= true; 
all_event_true := true;
END; -- close startstate

goal "enjoy" 
 (on[b1][b5]) & (on[b3][b12]) & (on[b4][b13]) & (on[b5][b2]) & (on[b6][b8]) & (on[b7][b9]) & (on[b8][b15]) & (on[b9][b1]) & (on[b10][b6]) & (on[b12][b11]) & (on[b13][b10]) & (on[b14][b4]) & (on[b15][b3]); 

metric: minimize;


