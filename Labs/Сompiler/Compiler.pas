program Compiler;

{$APPTYPE CONSOLE}

uses
  SysUtils;

Type SetofChar=set of AnsiChar;
Const CyfrsetofChar=['0'..'9'];
Const RazdsetofChar=[' ','+','-','','',')'];

Function Culc(Var Stshortstring;RazdsetofChar)boolean;forward;

Var Stshortstring; Rboolean;

Procedure Probel(Var Stshortstring); {удаление пробелов}
  Begin   While (St'') and (St[1]=' ') do Delete(St,1,1);   End;
 
  Function Id(Var Stshortstring;RazdsetofChar)boolean; {распознаватель идентиф.}
  Var SshortString;
  Begin
    Probel(St);
    S='';
    if ((St[1]='+') or (St[1]='-')) then
      Begin
        S=S+St[1]; Delete(St,1,1);
      End;
    if St[1] in Cyfr then
       Begin
         S=S+St[1]; Delete(St,1,1);
         While (St'') and (St[1] in Cyfr) do
            Begin
              S=S+St[1]; Delete(St,1,1);
            End;
         if (St[1]='.') then
            Begin
              S=S+St[1]; Delete(St,1,1);
              if (St[1] in Cyfr) then
                Begin
                  While (St'') and (St[1] in Cyfr) do
                    Begin
                      S=S+St[1]; Delete(St,1,1);
                    End;
                  if (St[1]='E') then
                    Begin
                      S=S+St[1]; Delete(St,1,1);
                      if ((St[1]='+') or (St[1]='-') or (St[1] in Cyfr)) then
                        Begin
                          if ((St[1]='+') or (St[1]='-')) then
                            Begin
                              S=S+St[1]; Delete(St,1,1);
                            End;
                          if (St[1] in Cyfr) then
                            Begin
                              While (St'') and (St[1] in Cyfr) do
                                Begin
                                  S=S+St[1]; Delete(St,1,1);
                                End;
                              if (St='') or (St[1] in Razd) then
                                Begin
                                  Id=true;  WriteLn('Real number ',S);
                                End
                              else
                                Begin
                                  Id=false; WriteLn('Wrong symbol ',St[1],'');
                                End;
                            End
                          else
                            Begin
                              Id=false; WriteLn('Wrong symbol ',St[1],'');
                            End;
                        End
                      else
                        Begin
                          Id=false; WriteLn('Wrong symbol ',St[1],'');
                        End;
                    End
                else
                    Begin
                      Id=false; WriteLn('Wrong symbol ',St[1],'');
                    End;
                End
              else
                Begin
                   Id=false; WriteLn('Wrong symbol ',St[1],'');
                End;
            End
         else
            Begin
              Id=false; WriteLn('Wrong symbol ',St[1],'');
            End;
       End
    else
       Begin
          Id=false; WriteLn('Identifier waits...', St);
       End;
  End;

Function Mult(Var Stshortstring;RazdsetofChar)boolean;
  Var Rboolean;
  Begin
    Probel(St);
    if St[1]='(' then
      begin
        Delete(St,1,1); Probel(St);
        R=Culc(St,Razd);
        Probel(St);
        if R and (St[1]=')') then Delete(St,1,1) else R=false;
      end
    else begin R=Id(St,Razd); Probel(St); end;
    Mult=R;
  End;

Function Term(Var Stshortstring;RazdsetofChar)boolean;
  Var Rboolean;
  Begin
     R=Mult(St,Razd);
     if R then
       begin
         Probel(St);
         While ((St[1]='') or (St[1]='')) and R do
           begin
             Delete(St,1,1);
             R=Mult(St,Razd);
           end;
       end;
     Term=R;
  End;

Function Culc(Var Stshortstring;RazdsetofChar)boolean;
  Var Rboolean;
  Begin
     R=Term(St,Razd);
     if R then
       begin
         Probel(St);
         While ((St[1]='+') or (St[1]='-')) and R do
           begin
             Delete(St,1,1);
             R=Term(St,Razd);
           end;
       end;
     Culc=R;
  End;

Begin
  Writeln('Input Strings'); Readln(St);
  While (St'Exit') do
    Begin
      R=Culc(St,Razd);
      if R and (length(st)=0) then Writeln('Yes') else Writeln('No');
      Writeln('Input Strings'); Readln(St);
    End;
    readln;
End.
