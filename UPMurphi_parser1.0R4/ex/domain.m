type
	 real_type: real(3,3);

	block : Enum {b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16,b17,b18,b19,b20,b21,b22,b23,b24,b25,b26,b27,b28,b29,b30,b31,b32,b33,b34,b35,b36,b37,b38,b39,b40,b41,b42,b43,b44,b45,b46,b47,b48,b49,b50};

const 
	 T:1;


var 
	all_event_true: boolean;
	fun[pddlname:fun;] :  real_type;


	on[pddlname:on;] : Array [block] of Array [block] of  boolean;
	ontable[pddlname:ontable;] : Array [block] of  boolean;
	clear[pddlname:clear;] : Array [block] of  boolean;
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

procedure set_clear( x : block ;  value : boolean);
BEGIN
	clear[x] := value;
END;

function get_clear( x : block): boolean;
BEGIN
	return 	clear[x];
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




procedure event_check();
 var -- local vars declaration 
   event_triggered : boolean;
BEGIN
 event_triggered := true;
while (event_triggered) do 
 event_triggered := false;
END; -- close while loop 
END;



procedure apply_continuous_change();
 var -- local vars declaration 
   process_updated : boolean;
 end_while : boolean;BEGIN
 process_updated := false; end_while := false;
while (!end_while) do 
 IF (!process_updated) then
	 end_while:=true;
 else process_updated:=false;
endif;END; -- close while loop 
END;

ruleset x:block do 
 action rule " pick-up " 
(clear[x]) & (ontable[x]) & (handempty) ==> 
pddlname: " pick-up"; 
BEGIN
holding[x]:= true; 
ontable[x]:= false; 
clear[x]:= false; 
handempty:= false; 

END; 
END;

ruleset x:block do 
 action rule " put-down " 
holding[x] ==> 
pddlname: " put-down"; 
BEGIN
clear[x]:= true; 
handempty:= true; 
ontable[x]:= true; 
holding[x]:= false; 

END; 
END;

ruleset x:block do 
 ruleset y:block do 
 action rule " stack " 
(holding[x]) & (clear[y]) ==> 
pddlname: " stack"; 
BEGIN
clear[x]:= true; 
handempty:= true; 
on[x][y]:= true; 
holding[x]:= false; 
clear[y]:= false; 

END; 
END; 
END;

ruleset x:block do 
 ruleset y:block do 
 action rule " unstack " 
(on[x][y]) & (clear[x]) & (handempty) ==> 
pddlname: " unstack"; 
BEGIN
holding[x]:= true; 
clear[y]:= true; 
clear[x]:= false; 
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
     set_clear(x, false);
END;  -- close for
   set_handempty(false);

   for x : block do 
     set_holding(x, false);
END;  -- close for
   fun := 0.0 ;

handempty:= true; 
on[b1][b48]:= true; 
on[b2][b33]:= true; 
on[b3][b41]:= true; 
on[b4][b37]:= true; 
on[b5][b45]:= true; 
on[b6][b16]:= true; 
on[b7][b31]:= true; 
on[b8][b28]:= true; 
on[b9][b49]:= true; 
on[b10][b34]:= true; 
on[b11][b15]:= true; 
on[b12][b17]:= true; 
on[b13][b20]:= true; 
on[b14][b2]:= true; 
on[b15][b44]:= true; 
on[b16][b5]:= true; 
on[b17][b32]:= true; 
on[b18][b50]:= true; 
on[b19][b30]:= true; 
on[b20][b22]:= true; 
on[b21][b27]:= true; 
on[b22][b38]:= true; 
on[b23][b11]:= true; 
ontable[b24]:= true; 
on[b25][b46]:= true; 
ontable[b26]:= true; 
on[b27][b40]:= true; 
on[b28][b43]:= true; 
on[b29][b19]:= true; 
on[b30][b39]:= true; 
on[b31][b29]:= true; 
ontable[b32]:= true; 
ontable[b33]:= true; 
on[b34][b14]:= true; 
on[b35][b36]:= true; 
ontable[b36]:= true; 
on[b37][b8]:= true; 
on[b38][b9]:= true; 
on[b39][b18]:= true; 
on[b40][b3]:= true; 
on[b41][b35]:= true; 
on[b42][b4]:= true; 
on[b43][b24]:= true; 
on[b44][b26]:= true; 
on[b45][b47]:= true; 
on[b46][b42]:= true; 
on[b47][b1]:= true; 
on[b48][b21]:= true; 
on[b49][b25]:= true; 
on[b50][b6]:= true; 
clear[b7]:= true; 
clear[b10]:= true; 
clear[b12]:= true; 
clear[b13]:= true; 
clear[b23]:= true; 
all_event_true := true;
END; -- close startstate

goal "enjoy" 
 (on[b1][b33]) & (on[b3][b40]) & (on[b4][b46]) & (on[b5][b21]) & (on[b6][b17]) & (on[b7][b37]) & (on[b8][b15]) & (on[b9][b41]) & (on[b10][b26]) & (on[b11][b23]) & (on[b12][b25]) & (on[b13][b47]) & (on[b14][b20]) & (on[b15][b19]) & (on[b16][b31]) & (on[b17][b39]) & (on[b18][b50]) & (on[b19][b1]) & (on[b20][b45]) & (on[b21][b11]) & (on[b23][b43]) & (on[b25][b42]) & (on[b26][b36]) & (on[b27][b35]) & (on[b28][b29]) & (on[b29][b44]) & (on[b30][b8]) & (on[b31][b9]) & (on[b32][b6]) & (on[b33][b10]) & (on[b34][b14]) & (on[b35][b2]) & (on[b36][b7]) & (on[b37][b32]) & (on[b38][b28]) & (on[b40][b24]) & (on[b41][b38]) & (on[b42][b34]) & (on[b43][b12]) & (on[b44][b49]) & (on[b45][b4]) & (on[b46][b18]) & (on[b47][b30]) & (on[b48][b22]) & (on[b50][b13]); 

invariant "todo bien" 
 all_event_true;
metric: minimize;


