#include <unittest.hpp>

int main() {
  UnitTest::print_statistics();
  int r = UnitTest::tests - UnitTest::passed;
  return r > 0 ? 1 : 0;
}
