program testFunProc;
    var a, b: integer;
    c: char;ss: string;
    procedure proc(a: integer);
    begin
        case (a) of
            1:writeln("correct!");
            2:writeln("not correct!!");
            end;
    end;

    function func(a: integer; b: integer):char;
    begin
        b:=a+b;
        case (b) of
            2:func := '?';
            3:func := '!';
        end;
    end;

begin
    a := 1;
    b := 2;
    proc(a);
    c := func(a, b);
    write(c);
end.
