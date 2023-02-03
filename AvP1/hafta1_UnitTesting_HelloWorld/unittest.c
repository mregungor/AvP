#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

int add(int a, int b) {
  return a + b;
}

void test_add(void) {
  CU_ASSERT_EQUAL(add(1, 2), 3);
  CU_ASSERT_EQUAL(add(0, 0), 0);
  CU_ASSERT_EQUAL(add(-1, -1), -2);
}

int main() {
  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("add_suite", 0, 0);
  CU_add_test(suite, "test_add", test_add);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return 0;
}