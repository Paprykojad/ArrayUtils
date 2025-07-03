#include <stdio.h>
#include <StackArray/StackArray.h>
#include <headers/aliases.h>

DEFINE_STACK_ARRAY(u32)
DEFINE_STACK_ARRAY(i32)

int main() {
    printf("no siema\n");
    STACK_ARRAY_CONSTRUCTOR(u32, myarr, 3, 4)

    u32Return ret = myarr.get(&myarr, 0);

    for (u32 i = 0; i < myarr.len; i++) {
        myarr.data[i] = i;
    }

    if (ret.err != OK) {
        printf("Error: %d\n", ret.err);
    } else {
        printf("Value: %d\n", ret.val);
    }

    ret = myarr.get(&myarr, 1);

    if (ret.err != OK) {
        printf("Error: %d\n", ret.err);
    } else {
        printf("Value: %d\n", ret.val);
    }

    ret = myarr.get(&myarr, 2);

    if (ret.err != OK) {
        printf("Error: %d\n", ret.err);
    } else {
        printf("Value: %d\n", ret.val);
    }






    STACK_ARRAY_CONSTRUCTOR(i32, intarr, 3, 4)

    i32Return ret2 = intarr.get(&intarr, 0);

    for (i32 i = 0; i < intarr.len; i++) {
        intarr.data[i] = i;
    }

    if (ret2.err != OK) {
        printf("Error: %d\n", ret2.err);
    } else {
        printf("Value: %d\n", ret2.val);
    }

    ret2 = intarr.get(&intarr, 1);

    if (ret2.err != OK) {
        printf("Error: %d\n", ret2.err);
    } else {
        printf("Value: %d\n", ret2.val);
    }

    ret2 = intarr.get(&intarr, 2);

    if (ret2.err != OK) {
        printf("Error: %d\n", ret2.err);
    } else {
        printf("Value: %d\n", ret2.val);
    }
}
