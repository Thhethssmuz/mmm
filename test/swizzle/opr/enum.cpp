#include <unittest.hpp>
#include <mmm.hpp>

namespace {

  auto swiz_succ1 = UnitTest("swizzle assignment operator ++ (1)", +[]() {
    ivec4 v = ivec4(1, 2, 3, 4);

    if (++v.x != 2) return false;
    if (v != ivec4(2, 2, 3, 4)) return false;

    if (++v.xy != ivec2(3, 3)) return false;
    if (v != ivec4(3, 3, 3, 4)) return false;

    if (++v.xyz != ivec3(4, 4, 4)) return false;
    if (v != ivec4(4, 4, 4, 4)) return false;

    if (++v.xyzw != ivec4(5, 5, 5, 5)) return false;
    if (v != ivec4(5, 5, 5, 5)) return false;

    return true;
  });
  auto swiz_succ2 = UnitTest("swizzle assignment operator ++ (2)", +[]() {
    ivec4 v = ivec4(1, 2, 3, 4);

    if (v.x++ != 1) return false;
    if (v != ivec4(2, 2, 3, 4)) return false;

    if (v.xy++ != ivec2(2, 2)) return false;
    if (v != ivec4(3, 3, 3, 4)) return false;

    if (v.xyz++ != ivec3(3, 3, 3)) return false;
    if (v != ivec4(4, 4, 4, 4)) return false;

    if (v.xyzw++ != ivec4(4, 4, 4, 4)) return false;
    if (v != ivec4(5, 5, 5, 5)) return false;

    return true;
  });

  auto swiz_prev1 = UnitTest("swizzle assignment operator -- (1)", +[]() {
    ivec4 v = ivec4(5, 4, 3, 2);

    if (--v.x != 4) return false;
    if (v != ivec4(4, 4, 3, 2)) return false;

    if (--v.xy != ivec2(3, 3)) return false;
    if (v != ivec4(3, 3, 3, 2)) return false;

    if (--v.xyz != ivec3(2, 2, 2)) return false;
    if (v != ivec4(2, 2, 2, 2)) return false;

    if (--v.xyzw != ivec4(1, 1, 1, 1)) return false;
    if (v != ivec4(1, 1, 1, 1)) return false;

    return true;
  });
  auto swiz_prev2 = UnitTest("swizzle assignment operator -- (2)", +[]() {
    ivec4 v = ivec4(5, 4, 3, 2);

    if (v.x-- != 5) return false;
    if (v != ivec4(4, 4, 3, 2)) return false;

    if (v.xy-- != ivec2(4, 4)) return false;
    if (v != ivec4(3, 3, 3, 2)) return false;

    if (v.xyz-- != ivec3(3, 3, 3)) return false;
    if (v != ivec4(2, 2, 2, 2)) return false;

    if (v.xyzw-- != ivec4(2, 2, 2, 2)) return false;
    if (v != ivec4(1, 1, 1, 1)) return false;

    return true;
  });
}
