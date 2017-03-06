#include <args.h>

const option_t* NOOPTION=NULL;

static option_t* get_new_opt(option_t* l, const char* kw, int sp)
{
    option_t* m     = (option_t*)malloc(sizeof(option_t));
    m->keyword      = kw;
    m->spec         = sp;
    m->next         = l;
    return (m);
}

option_t* opt_str(option_t* l, const char* kw, void(*f)(const char *))
{
    option_t* m = get_new_opt(l, kw, OptString);
    m->fct.opt_str  = f;
    return (m);
}

option_t* opt_int(option_t* l, const char* kw, void(*f)(int))
{
    option_t* m = get_new_opt(l, kw, OptInt);
    m->fct.opt_int  = f;
    return (m);
}

option_t* opt_float(option_t* l, const char* kw, void(*f)(float))
{
    option_t* m = get_new_opt(l, kw, OptFloat);
    m->fct.opt_float  = f;
    return (m);
}

option_t* opt_void(option_t* l, const char* kw, void(*f)())
{
    option_t* m = get_new_opt(l, kw, OptVoid);
    m->fct.opt_void  = f;
    return (m);
}

void opt_delete(option_t* l)
{
    if (l)
        free(l);
}
 
void process_arguments(option_t* l, int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
    {
//printf("[DBG] curAv='%s' curOpt=''"
        for (option_t* it = l; it; it = it->next)
        {
            if (!strcmp(av[i], it->keyword))
            {
                if (it->spec != OptVoid && i == ac-1)
                {
                    printf("missing argument for option '%s'\n", av[i]);
                    exit(1);
                }
                if (it->spec == OptInt)
                    it->fct.opt_int(atoi(av[++i]));
                else if (it->spec == OptFloat)
                    it->fct.opt_float((float)atof(av[++i]));
                else if (it->spec == OptString)
                    it->fct.opt_str(av[++i]);
                else if (it->spec == OptVoid)
                    it->fct.opt_void();
                break;
            }
        }
    }
}
