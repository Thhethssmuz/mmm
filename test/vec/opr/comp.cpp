#include <unittest.hpp>
#include <mmm.hpp>

namespace {

  auto v_lt = UnitTest("vector operator <", +[]() {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(2, 3, 4);

    if (!(v < 4)) return false;
    if (!(0 < v)) return false;

    if (!(v < u)) return false;
    if (!(v.zyx < u.zyx)) return false;

    bool b = (v < u) == all(lessThan(v, u));

    return b;
  });

  auto v_le = UnitTest("vector operator <=", +[]() {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(2, 2, 3);

    if (!(v <= 3)) return false;
    if (!(1 <= v)) return false;

    if (!(v <= u)) return false;
    if (!(v.zyx <= u.zyx)) return false;

    bool b = (v <= u) == all(lessThanEqual(v, u));

    return b;
  });

  auto v_ge = UnitTest("vector operator >=", +[]() {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(1, 1, 2);

    if (!(v >= 1)) return false;
    if (!(3 >= v)) return false;

    if (!(v >= u)) return false;
    if (!(v.zyx >= u.zyx)) return false;

    bool b = (v >= u) == all(greaterThanEqual(v, u));

    return b;
  });

  auto v_gt = UnitTest("vector operator >", +[]() {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(0, 1, 2);

    if (!(v > 0)) return false;
    if (!(4 > v)) return false;

    if (!(v > u)) return false;
    if (!(v.zyx > u.zyx)) return false;

    bool b = (v > u) == all(greaterThan(v, u));

    return b;
  });

  auto v_eq = UnitTest("vector operator ==", +[]() {
    ivec2 v = ivec2(1, 2);
    ivec2 u = ivec2(1, 2);
    ivec2 t = ivec2(3, 3);

    if (!(t == 3)) return false;
    if (!(3 == t)) return false;

    if (!(v == u)) return false;
    if (!(v.yx == u.yx)) return false;

    bool b = (v == u) == all(equal(v, u));

    return b;
  });

  auto v_ne = UnitTest("vector operator !=", +[]() {
    ivec2 v = ivec2(1, 2);
    ivec2 u = ivec2(2, 3);
    ivec2 t = ivec2(4, 3);

    if (!(t != 0)) return false;
    if (!(0 != t)) return false;

    if (!(v != u)) return false;
    if (!(u != t)) return false;
    if (!(v.yx != u.yx)) return false;

    bool b = (v != u) == all(notEqual(v, u));

    return b;
  });
}
