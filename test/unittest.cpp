#include "unittest.hpp"
#include <iostream>

int UnitTest::tests  = 0;
int UnitTest::passed = 0;

void run_test (bool (*f)(), const char* id) {
  bool b = false;

  try {
    b = f();
  } catch (std::exception& e) {
    std::cout << "test: '" << id << "' threw an exception!" << std::endl;
    std::cout << e.what() << std::endl;
  } catch (const std::string& e) {
    std::cout << "test: '" << id << "' threw an exception!" << std::endl;
    std::cout << e << std::endl;
  } catch (const char* e) {
    std::cout << "test: '" << id << "' threw an exception!" << std::endl;
    std::cout << e << std::endl;
  } catch (...) {
    std::cout << "test: '" << id << "' threw an exception!" << std::endl;
  }

  UnitTest::tests += 1;
  UnitTest::passed += b;
  if (!b)
    std::cout << "test: '" << id << "' failed!" << std::endl;
}

UnitTest::UnitTest (bool (*f)()) {
  run_test(f, "unnamed");
}
UnitTest::UnitTest (bool (*f)(), const char* id) {
  run_test(f, id);
}
UnitTest::UnitTest (const char* id, bool (*f)()) {
  run_test(f, id);
}

void UnitTest::print_statistics () {
  std::cout << std::endl << "test: " << UnitTest::passed <<  "/"
            << UnitTest::tests << " passed" << std::endl;
  int r = UnitTest::tests - UnitTest::passed;

  if (r == 1)
    std::cout << "test: " << r << " test failed!" << std::endl;
  else if (r > 1)
    std::cout << "test: " << r << " tests failed!" << std::endl;
}
