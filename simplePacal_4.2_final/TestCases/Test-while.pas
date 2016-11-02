program testWhile;
var a,b:integer;
begin
a:=1;
b:=0;
while b < 3 do
begin
a := a*2;
b := b+1;
end
writeln(a);
end.
