#pragma once

#include <headers/aliases.h>
#include <signal.h>

// #ifndef DEFINE_STACK_ARRAY
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
    } TYPE##Sarr; \
        \
    TYPE##Return TYPE##Get(struct TYPE##Sarr_t* self, TYPE idx) { \
        if (idx < 0 || idx >= self->len) { \
            raise(SIGTRAP); \
            return (TYPE##Return){ \
                .err = OUT_OF_RANGE \
            }; \
        } else { \
            return (TYPE##Return) { \
                .val = self->data[idx], \
                .err = OK \
            }; \
        } \
    }
// #endif



#define STACK_ARRAY_CONSTRUCTOR(TYPE, NAME, LEN, CAP) \
    TYPE NAME##Data[CAP]; \
    TYPE##Sarr NAME = { \
        .data = NAME##Data, \
        .len = LEN, \
        .cap = CAP, \
        .get = TYPE##Get \
    };
    
