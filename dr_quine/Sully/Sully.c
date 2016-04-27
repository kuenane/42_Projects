#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
int i = 5;
char eol='\n', qt='"', esc='\\', percent='%';
char* str="#include <stdio.h>%c#include <stdlib.h>%c#include <string.h>%c%cint main(int ac, char **av)%c{%cint i = %d;%cchar eol='%cn', qt='%c', esc='%c%c', percent='%c';%cchar* str=%c%s%c;%cif (!strcmp(%c./Sully%c, av[0])) ++i;%cchar filename[20], execname[20], cmd[80];%csprintf(execname, %cSully_%cd%c, --i);%csprintf(filename, %c%cs.c%c, execname);%cFILE *fd=fopen(filename,%cw%c);%cif (fd)%c{%cfprintf(fd, str, eol, eol, eol, eol, eol, eol, i, eol, esc, qt, esc, esc, percent, eol, qt, str, qt, eol, qt, qt, eol, eol, qt, percent, qt, eol, qt, percent, qt, eol, qt, qt, eol, eol, eol, eol, eol, qt, percent, percent, qt, eol, eol, qt, percent, qt, eol ,eol, eol, qt, esc, qt, eol, eol ,eol, eol, eol);%cfclose(fd);%csprintf(cmd, %cclang -Wall -Werror -Wextra %cs -o %cs%c, filename, execname);%csystem(cmd);%cif (i > 0) { sprintf(cmd, %c./%cs%c, execname); system(cmd); }%c}%celse%cprintf(%cerror%cn%c);%c(void)ac;%creturn (0);%c}%c";
if (!strcmp("./Sully", av[0])) ++i;
char filename[20], execname[20], cmd[80];
sprintf(execname, "Sully_%d", --i);
sprintf(filename, "%s.c", execname);
FILE *fd=fopen(filename,"w");
if (fd)
{
fprintf(fd, str, eol, eol, eol, eol, eol, eol, i, eol, esc, qt, esc, esc, percent, eol, qt, str, qt, eol, qt, qt, eol, eol, qt, percent, qt, eol, qt, percent, qt, eol, qt, qt, eol, eol, eol, eol, eol, qt, percent, percent, qt, eol, eol, qt, percent, qt, eol ,eol, eol, qt, esc, qt, eol, eol ,eol, eol, eol);
fclose(fd);
sprintf(cmd, "clang -Wall -Werror -Wextra %s -o %s", filename, execname);
system(cmd);
if (i > 0) { sprintf(cmd, "./%s", execname); system(cmd); }
}
else
printf("error\n");
(void)ac;
return (0);
}
