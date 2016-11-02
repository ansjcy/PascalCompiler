program testArray;
var a: array [0..5] of integer; b: integer;  i: integer;
begin
b:=0;
for i := 0 to 5 do a[i] := i;
for i := 0 to 5 do b := b + a[i];
for i := 0 to 5 do writeln(a[i]);
writeln("sum of array=");
writeln(b);
end.
