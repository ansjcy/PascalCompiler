program Testcase;
var a, b:integer;
begin
    a:=3;
	case (a) of
    1:b:=1;
	2:b:=2;
	3:b:=3;
	4:b:=4;
	end;
writeln("b=");
writeln(b);
end.
