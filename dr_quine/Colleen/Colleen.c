/*
this is an awesome comment
*/

#include <stdio.h>

int ret0(){return 0;}

int main()
{
/*
but this is an useless comment
*/
char eol='\n', qt='"', esc='\\';
char* str="/*%cthis is an awesome comment%c*/%c%c#include <stdio.h>%c%cint ret0(){return 0;}%c%cint main()%c{%c/*%cbut this is an useless comment%c*/%cchar eol='%cn', qt='%c', esc='%c%c';%cchar* str=%c%s%c;%cprintf(str, eol, eol, eol, eol, eol, eol, eol, eol, eol, eol, eol, eol, eol, esc, qt, esc ,esc, eol, qt, str, qt, eol, eol, eol, eol);%creturn ret0();%c}%c";
printf(str, eol, eol, eol, eol, eol, eol, eol, eol, eol, eol, eol, eol, eol, esc, qt, esc ,esc, eol, qt, str, qt, eol, eol, eol, eol);
return ret0();
}
