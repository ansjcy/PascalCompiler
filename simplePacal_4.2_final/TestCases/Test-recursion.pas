program testRec;
var n:integer;
function f(n:integer):integer;
begin
     case n of
        0:f:=1;
        1:f:=2;
        3:f:=(f(n-1)+f(n-2));　
        4:f:=f(n-1)+f(n-2);　
        5:f:=f(n-1)+f(n-2);　
        6:f:=f(n-1)+f(n-2);　
        7:f:=f(n-1)+f(n-2);
        8:f:=f(n-1)+f(n-2);　
        9:f:=f(n-1)+f(n-2);　
        10: f:=f(n-1)+f(n-2);　
     end;

end;
begin
     readln(n);
     writeln(f(n))
end.
