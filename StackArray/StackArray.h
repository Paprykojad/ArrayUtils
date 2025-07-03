#pragma once

#include <headers/aliases.h>
#include <signal.h>

#ifndef DEFINE_STACK_ARRAY
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
    TYPE##Return TYPE##Get(struct TYPE##Sarr_t* self, u32 idx) { \
        if (idx < 0 || idx >= self->len) { \
            raise(SIGTRAP); \
            return (TYPE##Return){ \
                .err = OUT_OF_RANGE \
            }; \
        } else if ( self == NULL) { \
            raise(SIGTRAP); \
            return (TYPE##Return) { \
                .err = NULL_POINTER \
            }; \
        } else { \
            return (TYPE##Return) { \
                .val = self->data[idx], \
                .err = OK \
            }; \
        } \
    } \
    Error TYPE##Set(struct TYPE##Sarr_t* self, u32 idx, TYPE data) { \
        if (idx < 0 || idx >= self->len) { \
            raise(SIGTRAP); \
            return OUT_OF_RANGE; \
        } else if (self == NULL) { \
            raise(SIGTRAP); \
            return NULL_POINTER; \
        } else { \
            self->data[idx] = data; \
            return OK; \
        } \
    } \
    Error TYPE##Push(struct TYPE##Sarr_t* self, TYPE data) { \
        if (self->len >= self->cap) {  \
            raise(SIGTRAP); \
            return OUT_OF_MEMORY; \
        } else if ( self == NULL) { \
            raise(SIGTRAP); \
            return NULL_POINTER; \
        } else { \
            self->len++; \
            self->data[(self->len)-1] = data; \
            return OK; \
        } \
    } \
    Error TYPE##Pop(struct TYPE##Sarr_t* self) { \
        if (self->len <= 0) { \
            raise(SIGTRAP); \
            return EMPTY_ARRAY; \
        } else { \
            self->len--; \
            return OK; \
        } \
    }
#endif



#define STACK_ARRAY_CONSTRUCTOR(TYPE, NAME, LEN, CAP) \
    TYPE NAME##Data[CAP]; \
    TYPE##Sarr NAME = { \
        .data = NAME##Data, \
        .len = LEN, \
        .cap = CAP, \
        .get = TYPE##Get, \
        .push = TYPE##Push, \
        .pop = TYPE##Pop \
    };
    
