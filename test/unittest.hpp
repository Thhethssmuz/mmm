#ifndef test_unittest_hpp
#define test_unittest_hpp

struct UnitTest {
  static int tests;
  static int passed;

  UnitTest (bool (*f)());
  UnitTest (bool (*f)(), const char* id);
  UnitTest (const char* id, bool (*f)());

  static void print_statistics ();
};

#endif