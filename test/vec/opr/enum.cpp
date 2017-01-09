#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto succ = UnitTest("vector enumeration operator ++", +[]() {
    ivec4 v = ivec4(1, 2, 3, 4);

    if (++v != ivec4(2, 3, 4, 5)) return false;
    if (v != ivec4(2, 3, 4, 5)) return false;

    if (v++ != ivec4(2, 3, 4, 5)) return false;
    if (v != ivec4(3, 4, 5, 6)) return false;

    return true;
  });

  auto pred = UnitTest("vector enumeration operator --", +[]() {
    ivec4 v = ivec4(3, 4, 5, 6);

    if (--v != ivec4(2, 3, 4, 5)) return false;
    if (v != ivec4(2, 3, 4, 5)) return false;

    if (v-- != ivec4(2, 3, 4, 5)) return false;
    if (v != ivec4(1, 2, 3, 4)) return false;

    return true;
  });
}
