#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

int sum(int a, int b);

void test_sum_positive_numbers(void) {
    CU_ASSERT(sum(2, 3) == 5);
}

void test_sum_negative_numbers(void) {
    CU_ASSERT(sum(-2, -3) == -5);
}

void test_sum_positive_and_negative(void) {
    CU_ASSERT(sum(5, -3) == 2);
}

void test_sum_with_zero(void) {
    CU_ASSERT(sum(0, 7) == 7);
}

int main(void) {
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite suite = CU_add_suite("Sum_Test_Suite", 0, 0);
    if (NULL == suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(suite, "test of sum(2, 3)", test_sum_positive_numbers)) ||
        (NULL == CU_add_test(suite, "test of sum(-2, -3)", test_sum_negative_numbers)) ||
        (NULL == CU_add_test(suite, "test of sum(5, -3)", test_sum_positive_and_negative)) ||
        (NULL == CU_add_test(suite, "test of sum(0, 7)", test_sum_with_zero))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    CU_cleanup_registry();
    return CU_get_error();
}
