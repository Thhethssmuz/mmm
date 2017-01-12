#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto v_add = UnitTest("vector operator +", +[]() {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(4, 8, 12);

    if (2 + v != vec3(3, 4, 5)) return false;
    if (v + 2 != vec3(3, 4, 5)) return false;

    if (v.y + u != vec3(6, 10, 14)) return false;
    if (u + v.y != vec3(6, 10, 14)) return false;

    if (v + u != vec3(5, 10, 15)) return false;
    if (v.zyx + u.zyx != vec3(15, 10, 5)) return false;

    return true;
  });

  auto v_sub = UnitTest("vector operator -", +[]() {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(4, 8, 12);

    if (-v != vec3(-1, -2, -3)) return false;
    if (-v.zyx != vec3(-3, -2, -1)) return false;

    if (2 - v != vec3(1, 0, -1)) return false;
    if (v - 2 != vec3(-1, 0, 1)) return false;

    if (v.z - v != vec3(2, 1, 0)) return false;
    if (v - v.z != vec3(-2, -1, 0)) return false;

    if (u - v != vec3(3, 6, 9)) return false;
    if (u.zyx - v.zyx != vec3(9, 6, 3)) return false;

    return true;
  });

  auto v_mult = UnitTest("vector operator *", +[]() {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(4, 8, 12);

    if (2 * v != vec3(2, 4, 6)) return false;
    if (v * 2 != vec3(2, 4, 6)) return false;

    if (v.x * u != vec3(4, 8, 12)) return false;
    if (u * v.x != vec3(4, 8, 12)) return false;

    if (v * u != vec3(4, 16, 36)) return false;
    if (v.zyx * u.zyx != vec3(36, 16, 4)) return false;

    return true;
  });

  auto v_div = UnitTest("vector operator /", +[]() {
    vec3 v = vec3(2, 4, 8);
    vec3 u = vec3(1, 2, 4);

    if (2 / u != vec3(2, 1, 2 / 4.f)) return false;
    if (v / 2 != vec3(1, 2, 4)) return false;

    if (v.x / u != vec3(2, 1, 0.5f)) return false;
    if (v / u.y != vec3(1, 2, 4)) return false;

    if (v / u != vec3(2, 2, 2)) return false;
    if (v.zyx / u.zyx != vec3(2, 2, 2)) return false;

    return true;
  });
}
