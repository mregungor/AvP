#include <assert.h>

void test_add(void) {
  assert(add(-1, -2) == -3);
  assert(add(1, 5) == 3);
  assert(add(0, 0) == 0);
}

int main() {
  test_add();
  return 0;
}
int add(int a, int b) {
  //Kodu buraya yaz�n�z !
}
