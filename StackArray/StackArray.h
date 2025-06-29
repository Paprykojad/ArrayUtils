#pragma once

#include <headers/aliases.h>

#define DEFINE_STACK_ARRAY(TYPE) \
    typedef struct { \
        TYPE val; \
        Error err; \
    } TYPE##Return ; \
                    \
    typedef struct TYPE##Sarr_t { \
        TYPE *data; \
        u32 len; \
        u32 cap; \
        TYPE##Return (*get)(struct TYPE##Sarr_t* self, u32 idx); \
        Error (*set)(struct TYPE##Sarr_t* self, u32 idx, TYPE data); \
        Error (*push)(struct TYPE##Sarr_t* self, TYPE data); \
        Error (*pop)(struct TYPE##Sarr_t* self); \
    } TYPE##Sarr;



#define STACK_ARRAY_CONSTRUCTOR(TYPE, NAME, LEN, CAP) \
    TYPE NAME##Data[CAP]; \
    TYPE##Sarr NAME = { \
        .data = NAME##Data, \
        .len = LEN, \
        .cap = CAP \
    };
    
