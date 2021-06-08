var
x0, y1, i, z, n: integer;
begin
readln(n);
y1:=1;
z:=1;
for i:=3 to n do
begin
z:=y1+z;
y1:=z-y1;
end;
writeln(z);
end.
