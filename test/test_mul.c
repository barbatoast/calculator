#include "unity.h"
#include "mul.h"

#include "Mockadd.h"
#include "Mocksub.h"

void setUp(void) {
    /* set stuff up here */
}

void tearDown(void) {
    /* clean stuff up here */
}

void test_mul_1_2(void) {
    add_ExpectAndReturn(0, 1, 1);
    add_ExpectAndReturn(0, 1, 1);
    add_ExpectAndReturn(1, 1, 2);
    add_ExpectAndReturn(1, 1, 2);

    /* test stuff */
    TEST_ASSERT_EQUAL_INT(mul(1, 2), 2);
}

void test_mul_2_3(void) {
    add_ExpectAndReturn(0, 2, 2);
    add_ExpectAndReturn(0, 1, 1);
    add_ExpectAndReturn(2, 2, 4);
    add_ExpectAndReturn(1, 1, 2);
    add_ExpectAndReturn(4, 2, 6);
    add_ExpectAndReturn(2, 1, 3);

    /* test stuff */
    TEST_ASSERT_EQUAL_INT(mul(2, 3), 6);
}

void test_mul_neg_3_4(void) {
    sub_ExpectAndReturn(0, -3, 3);
    add_ExpectAndReturn(0, 3, 3);
    add_ExpectAndReturn(0, 1, 1);
    add_ExpectAndReturn(3, 3, 6);
    add_ExpectAndReturn(1, 1, 2);
    add_ExpectAndReturn(6, 3, 9);
    add_ExpectAndReturn(2, 1, 3);
    add_ExpectAndReturn(9, 3, 12);
    add_ExpectAndReturn(3, 1, 4);
    sub_ExpectAndReturn(0, 12, -12);

    /* test stuff */
    TEST_ASSERT_EQUAL_INT(mul(-3, 4), -12);
}

void test_mul_4_neg_5(void) {
    sub_ExpectAndReturn(0, -5, 5);
    add_ExpectAndReturn(0, 4, 4);
    add_ExpectAndReturn(0, 1, 1);
    add_ExpectAndReturn(4, 4, 8);
    add_ExpectAndReturn(1, 1, 2);
    add_ExpectAndReturn(8, 4, 12);
    add_ExpectAndReturn(2, 1, 3);
    add_ExpectAndReturn(12, 4, 16);
    add_ExpectAndReturn(3, 1, 4);
    add_ExpectAndReturn(16, 4, 20);
    add_ExpectAndReturn(4, 1, 5);
    sub_ExpectAndReturn(0, 20, -20);

    /* test stuff */
    TEST_ASSERT_EQUAL_INT(mul(4, -5), -20);
}

void test_mul_neg_5_neg_6(void) {
    sub_ExpectAndReturn(0, -5, 5);
    sub_ExpectAndReturn(0, -6, 6);
    add_ExpectAndReturn(0, 5, 5);
    add_ExpectAndReturn(0, 1, 1);
    add_ExpectAndReturn(5, 5, 10);
    add_ExpectAndReturn(1, 1, 2);
    add_ExpectAndReturn(10, 5, 15);
    add_ExpectAndReturn(2, 1, 3);
    add_ExpectAndReturn(15, 5, 20);
    add_ExpectAndReturn(3, 1, 4);
    add_ExpectAndReturn(20, 5, 25);
    add_ExpectAndReturn(4, 1, 5);
    add_ExpectAndReturn(25, 5, 30);
    add_ExpectAndReturn(5, 1, 6);

    /* test stuff */
    TEST_ASSERT_EQUAL_INT(mul(-5, -6), 30);
}

/* not needed when using generate_test_runner.rb */
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_mul_1_2);
    RUN_TEST(test_mul_2_3);
    RUN_TEST(test_mul_neg_3_4);
    RUN_TEST(test_mul_4_neg_5);
    RUN_TEST(test_mul_neg_5_neg_6);
    return UNITY_END();
}
