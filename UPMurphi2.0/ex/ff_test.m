type
	integer: -1000..1000;

var 
	x : boolean;
	y : boolean;
	z : boolean;
	p : boolean;
	q : boolean;
	r : boolean;
	h_n : integer;
	g_n : integer;
	f_n : integer;


action rule " a_1 " 
(!p & !q) ==> 
BEGIN
r := true;
END;


action rule " a_2 " 
(!p & r) ==> 
BEGIN
q := true;
END;

action rule " a_3 " 
(q) ==> 
BEGIN
p := true;
END;

action rule " a_4 " 
(p & q & r) ==> 
BEGIN
z := true;
END;

action rule " a_5 " 
(z & p) ==> 
BEGIN
y := true;
z := false;
END;

action rule " a_6 "
(y & z) ==>
BEGIN
x:= true;
END;

startstate "start" 
BEGIN 
x := false;
y := false;
z := false;
p := false;
q := false;
r := false;
h_n := 0;
g_n := 0;
f_n := h_n + g_n;
END;

goal "enjoy" 
( x = true );



