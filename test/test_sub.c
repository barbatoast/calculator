#include "unity.h"
#include "sub.h"

void setUp(void) {
    /* set stuff up here */
}

void tearDown(void) {
    /* clean stuff up here */
}

void test_sub(void) {
    /* test stuff */
    TEST_ASSERT_EQUAL_INT(sub(1, 2), -1);
}

/* not needed when using generate_test_runner.rb */
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_sub);
    return UNITY_END();
}
