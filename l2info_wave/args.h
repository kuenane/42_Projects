#ifndef __ARGS_H__
#define __ARGS_H__

// includes
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
//

// struct
    typedef struct   option_s
    {
        const char* keyword;
    
        enum
        {
            OptVoid,
            OptInt,
            OptString,
            OptFloat
        } spec;

        union
        {
            void (*opt_str)(const char*);
            void (*opt_int)(int);
            void (*opt_float)(float);
            void (*opt_void)();
        } fct;

        struct option_s* next;

    }               option_t;
//

// functions
    option_t* opt_str(option_t* l, const char* kw, void(*f)(const char *));
    option_t* opt_int(option_t* l, const char* kw, void(*f)(int));
    option_t* opt_float(option_t* l, const char* kw, void(*f)(float));
    option_t* opt_void(option_t* l, const char* kw, void(*f)());
    void opt_delete(option_t* l);
    void process_arguments(option_t* l, int ac, char **av);
//

#endif
