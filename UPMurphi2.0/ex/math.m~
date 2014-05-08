type
	integer: -1000..1000;
const 
	G : 40;

var 
	x : integer;
	h_n : integer;
	g_n : integer;
	f_n : integer;


action rule " add_1 " 
(x < 40) ==> 
BEGIN
x := x + 1;
END;


action rule " add_5 " 
(x < 40) ==> 
BEGIN
x := x + 5;
END;

action rule " add_10 " 
(x < 40) ==> 
BEGIN
x := x + 10;
END;

action rule " dec_1 " 
(x >= -2) ==> 
BEGIN
x := x - 1;
END;

action rule " dec_5 " 
(x >= -2) ==> 
BEGIN
x := x - 5;
END;

startstate "start" 
BEGIN 
x := 3;
h_n := G - x;
g_n := 0;
f_n := h_n + g_n;
END;

goal "enjoy" 
( x = G );



