#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "sum.h"

void test_add_numbers(void) {
    CU_ASSERT_EQUAL(add_numbers(0, 0), 0);
    CU_ASSERT_EQUAL(add_numbers(1, 1), 2);
    CU_ASSERT_EQUAL(add_numbers(-1, 1), 0);
    CU_ASSERT_EQUAL(add_numbers(-5, 5), 0);
    CU_ASSERT_EQUAL(add_numbers(-5, -5), -10);
    CU_ASSERT_EQUAL(add_numbers(100, 200), 300);
}

int main(void) {
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }
    CU_pSuite pSuite = CU_add_suite("TestSuite_Sum", 0, 0);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test of add_numbers()", test_add_numbers)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
