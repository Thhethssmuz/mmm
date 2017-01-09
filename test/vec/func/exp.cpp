#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto v_pow = UnitTest("vector exponential function pow", +[]() {
    vec4 v = vec4(1, 2, 3, 4);

    if (pow(v, 2) != vec4(1, 4, 9, 16)) return false;
    if (pow(2.l, v) != vec4(2, 4, 8, 16)) return false;

    if (pow(v.wzyx, 2) != vec4(16, 9, 4, 1)) return false;
    if (pow(2.f, v.wzyx) != vec4(16, 8, 4, 2)) return false;

    if (pow(v, v) != vec4(1, 4, 27, 256)) return false;
    if (pow(v.wzyx, v.wzyx) != vec4(256, 27, 4, 1)) return false;

    return true;
  });

  auto v_exp = UnitTest("vector exponential function exp", +[]() {
    vec2 v = vec2(1, 2);

    if (abs(exp(v) - vec2(2.71828, 7.38906)) > 0.0001) return false;
    if (abs(exp(v.yx) - vec2(7.38906, 2.71828)) > 0.0001) return false;

    return true;
  });

  auto v_log = UnitTest("vector exponential function log", +[]() {
    vec2 v = vec2(1, 2);

    if (abs(log(v) - vec2(0, 0.693147)) > 0.0001) return false;
    if (abs(log(v.yx) - vec2(0.693147, 0)) > 0.0001) return false;

    return true;
  });

  auto v_exp2 = UnitTest("vector exponential function exp2", +[]() {
    vec4 v = vec4(1, 2, 3, 4);

    if (abs(exp2(v) - vec4(2, 4, 8, 16)) > 0.00001) return false;
    if (abs(exp2(v.wzyx) - vec4(16, 8, 4, 2)) > 0.00001) return false;

    return true;
  });

  auto v_log2 = UnitTest("vector exponential function log2", +[]() {
    vec4 v = vec4(2, 4, 8, 16);

    if (abs(log2(v) - vec4(1, 2, 3, 4)) > 0.00001) return false;
    if (abs(log2(v.wzyx) - vec4(4, 3, 2, 1)) > 0.00001) return false;

    return true;
  });

  auto v_sqrt = UnitTest("vector exponential function sqrt", +[]() {
    vec4 v = vec4(4, 9, 16, 25);

    if (abs(sqrt(v) - vec4(2, 3, 4, 5)) > 0.00001) return false;
    if (abs(sqrt(v.wzyx) - vec4(5, 4, 3, 2)) > 0.00001) return false;

    return true;
  });

  auto v_isqrt = UnitTest("vector exponential function inversesqrt", +[]() {
    vec4 v = vec4(4, 9, 16, 25);
    vec4 r = vec4(1.f / 2.f, 1.f / 3.f, 1.f / 4.f, 1.f / 5.f);

    if (abs(inversesqrt(v) - r) > 0.00001) return false;
    if (abs(inversesqrt(v.wzyx) - r.wzyx) > 0.00001) return false;

    return true;
  });
}
