/*
J'aime les poneys
*/
#include <stdio.h>

#define FT(x) int main(){ char eol='\n', qt='"', esc='\\'; char* str="/*%cJ'aime les poneys%c*/%c#include <stdio.h>%c%c#define FT(x) int main(){ char eol='%cn', qt='%c', esc='%c%c'; char* str=%c%s%c; FILE *fd=fopen(%cGrace_kid.c%c,%cw%c); if (fd) { fprintf(fd, str, eol, eol, eol, eol, eol, esc, qt, esc, esc, qt, str, qt, qt, qt, qt, qt, qt, esc, qt, eol, eol, eol); fclose(fd); } else printf(%cerror%cn%c); return (x); }%c%cFT(0)%c"; FILE *fd=fopen("Grace_kid.c","w"); if (fd) { fprintf(fd, str, eol, eol, eol, eol, eol, esc, qt, esc, esc, qt, str, qt, qt, qt, qt, qt, qt, esc, qt, eol, eol, eol); fclose(fd); } else printf("error\n"); return (x); }

FT(0)
