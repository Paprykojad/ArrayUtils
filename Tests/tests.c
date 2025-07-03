#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <stdbool.h>
#include <headers/cmocka.h>


/* A test case that does nothing and succeeds. */
static void null_test_success(void **state) {
    (void) state; /* unused */
}

static void true_test1(void **state) {
    bool b = true;
    assert_true(b);
}

static void true_test2(void **state) {
    bool b = false;
    assert_true(b);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(true_test1),
        cmocka_unit_test(true_test2),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
