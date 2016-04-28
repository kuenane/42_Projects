/*
J'aime les poneys
*/
#include <stdio.h>

#define zero 0

#define FCLSE(a) fclose(a)

#define FT(x) int main(){ char eol='\n', qt='"', esc='\\'; char* str="/*%cJ'aime les poneys%c*/%c#include <stdio.h>%c%c#define zero 0%c%c#define FCLSE(a) fclose(a)%c%c#define FT(x) int main(){ char eol='%cn', qt='%c', esc='%c%c'; char* str=%c%s%c; FILE *fd=fopen(%cGrace_kid.c%c,%cw%c); if (fd) { fprintf(fd, str, eol, eol, eol, eol, eol, eol, eol, eol, eol, esc, qt, esc, esc, qt, str, qt, qt, qt, qt, qt, qt, esc, qt, eol, eol, eol); FCLSE(fd); } else printf(%cerror%cn%c); return (x); }%c%cFT(zero)%c"; FILE *fd=fopen("Grace_kid.c","w"); if (fd) { fprintf(fd, str, eol, eol, eol, eol, eol, eol, eol, eol, eol, esc, qt, esc, esc, qt, str, qt, qt, qt, qt, qt, qt, esc, qt, eol, eol, eol); FCLSE(fd); } else printf("error\n"); return (x); }

FT(zero)
