#include "unity.h"
#include "add.h"

void setUp(void) {
    /* set stuff up here */
}

void tearDown(void) {
    /* clean stuff up here */
}

void test_add(void) {
    /* test stuff */
    TEST_ASSERT_EQUAL_INT(add(1, 2), 3);
}

/* not needed when using generate_test_runner.rb */
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add);
    return UNITY_END();
}
