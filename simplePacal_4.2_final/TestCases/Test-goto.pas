program TestGoto;
var x: integer;
begin
	goto 1;
	x := 1;
	1: x := 2;
	writeln(x);
end.
