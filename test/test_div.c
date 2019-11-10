#include "unity.h"
#include "div.h"

#include "Mockadd.h"
#include "Mocksub.h"

void setUp(void) {
    /* set stuff up here */
}

void tearDown(void) {
    /* clean stuff up here */
}

void test_div_1_2(void) {
    sub_ExpectAndReturn(1, 2, -1);

    /* test stuff */
    TEST_ASSERT_EQUAL_INT(div(1, 2), 0);
}

void test_div_2_2(void) {
    sub_ExpectAndReturn(2, 2, 0);
    add_ExpectAndReturn(0, 1, 1);

    /* test stuff */
    TEST_ASSERT_EQUAL_INT(div(2, 2), 1);
}

void test_div_4_2(void) {
    sub_ExpectAndReturn(4, 2, 2);
    add_ExpectAndReturn(0, 1, 1);
    sub_ExpectAndReturn(2, 2, 0);
    add_ExpectAndReturn(1, 1, 2);

    /* test stuff */
    TEST_ASSERT_EQUAL_INT(div(4, 2), 2);
}

void test_div_5_2(void) {
    sub_ExpectAndReturn(5, 2, 3);
    add_ExpectAndReturn(0, 1, 1);
    sub_ExpectAndReturn(3, 2, 1);
    add_ExpectAndReturn(1, 1, 2);
    sub_ExpectAndReturn(1, 2, -1);

    /* test stuff */
    TEST_ASSERT_EQUAL_INT(div(5, 2), 2);
}

void test_div_neg_6_2(void) {
    sub_ExpectAndReturn(0, -6, 6);
    sub_ExpectAndReturn(6, 2, 4);
    add_ExpectAndReturn(0, 1, 1);
    sub_ExpectAndReturn(4, 2, 2);
    add_ExpectAndReturn(1, 1, 2);
    sub_ExpectAndReturn(2, 2, 0);
    add_ExpectAndReturn(2, 1, 3);
    sub_ExpectAndReturn(0, 3, -3);

    /* test stuff */
    TEST_ASSERT_EQUAL_INT(div(-6, 2), -3);
}

void test_div_7_neg_3(void) {
    sub_ExpectAndReturn(0, -3, 3);
    sub_ExpectAndReturn(7, 3, 4);
    add_ExpectAndReturn(0, 1, 1);
    sub_ExpectAndReturn(4, 3, 1);
    add_ExpectAndReturn(1, 1, 2);
    sub_ExpectAndReturn(1, 3, -2);
    sub_ExpectAndReturn(0, 2, -2);

    /* test stuff */
    TEST_ASSERT_EQUAL_INT(div(7, -3), -2);
}

void test_div_neg_8_neg_4(void) {
    sub_ExpectAndReturn(0, -8, 8);
    sub_ExpectAndReturn(0, -4, 4);
    sub_ExpectAndReturn(8, 4, 4);
    add_ExpectAndReturn(0, 1, 1);
    sub_ExpectAndReturn(4, 4, 0);
    add_ExpectAndReturn(1, 1, 2);

    /* test stuff */
    TEST_ASSERT_EQUAL_INT(div(-8, -4), 2);
}

/* not needed when using generate_test_runner.rb */
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_div_1_2);
    RUN_TEST(test_div_2_2);
    RUN_TEST(test_div_4_2);
    RUN_TEST(test_div_5_2);
    RUN_TEST(test_div_neg_6_2);
    RUN_TEST(test_div_7_neg_3);
    RUN_TEST(test_div_neg_8_neg_4);
    return UNITY_END();
}
