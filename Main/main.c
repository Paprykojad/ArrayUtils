#include <stdio.h>
#include <StackArray/StackArray.h>
#include <headers/aliases.h>
#include <signal.h>

DEFINE_STACK_ARRAY(u32)

    u32Return get(struct u32Sarr_t* self, u32 idx) {
        if (idx < 0 || idx >= self->len) {
            raise(SIGTRAP);
            return (u32Return){
                .err = OUT_OF_RANGE
            };
        } else {
            return (u32Return) {
                .val = self->data[idx],
                .err = OK
            };
        }
    }

int main() {
    printf("no siema\n");
    STACK_ARRAY_CONSTRUCTOR(u32, myarr, 2, 4)

        u32Return ret = get(&myarr, 0);

    for (u32 i = 0; i < myarr.len; i++) {
        myarr.data[i] = i;
    }

    if (ret.err != OK) {
        printf("Error: %d\n", ret.err);
    } else {
        printf("Value: %d\n", ret.val);
    }

    ret = get(&myarr, 1);

    if (ret.err != OK) {
        printf("Error: %d\n", ret.err);
    } else {
        printf("Value: %d\n", ret.val);
    }

    ret = get(&myarr, 2);

    if (ret.err != OK) {
        printf("Error: %d\n", ret.err);
    } else {
        printf("Value: %d\n", ret.val);
    }
}
