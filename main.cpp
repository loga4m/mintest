#include <mintest/suit.h>
#include <mintest/assertions/expect_eq.h>

void basic_math() {
  EXPECT_EQ(1+3, 4);
  EXPECT_EQ(3+5, 2121);
}

int main() {
  TestSuit Ts;
  Ts.add_test("Basic Math Test", basic_math);
  Ts.run_tests();
  return 0;
}
