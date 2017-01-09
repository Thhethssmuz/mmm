#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto s_radians = UnitTest("scalar trigonometric function radians", +[]() {
    if (abs(radians(90) - 1.5708) > 0.0001) return false;
    if (abs(radians(90.f) - 1.5708) > 0.0001) return false;
    if (abs(radians(90.0) - 1.5708) > 0.0001) return false;
    if (abs(radians(90.l) - 1.5708) > 0.0001) return false;

    return true;
  });
  auto v_radians = UnitTest("vector trigonometric function radians", +[]() {
    vec2 v = vec2(90, 180);

    if (abs(radians(v) - vec2(1.5708, 0.785398)) > 0.0001) return false;
    if (abs(radians(v.yx) - vec2(0.785398, 1.5708)) > 0.0001) return false;

    if (abs(degrees(radians(v)) - v) > 0.0001) return false;

    return true;
  });

  auto s_degrees = UnitTest("scalar trigonometric function degrees", +[]() {
    if (abs(degrees(1) - 57.2958) > 0.0001) return false;
    if (abs(degrees(1.f) - 57.2958) > 0.0001) return false;
    if (abs(degrees(1.0) - 57.2958) > 0.0001) return false;
    if (abs(degrees(1.l) - 57.2958) > 0.0001) return false;

    return true;
  });
  auto v_degrees = UnitTest("vector trigonometric function degrees", +[]() {
    vec2 v = vec2(1, 2);

    if (abs(degrees(v) - vec2(57.2958, 114.592)) > 0.0001) return false;
    if (abs(degrees(v.yx) - vec2(114.592, 57.2958)) > 0.0001) return false;

    if (abs(radians(degrees(v)) - v) > 0.0001) return false;

    return true;
  });

  auto v_sin = UnitTest("vector trigonometric function sin", +[]() {
    vec3 v = radians(vec3(45, 0, -45));

    if (abs(asin(sin(v)) - v) > 0.0001) return false;
    if (abs(asin(sin(v.zyx)) - v.zyx) > 0.0001) return false;

    return true;
  });

  auto v_cos = UnitTest("vector trigonometric function cos", +[]() {
    vec3 v = radians(vec3(45, 0, -45));

    if (abs(asin(cos(v)) - v) > 0.0001) return false;
    if (abs(asin(cos(v.zyx)) - v.zyx) > 0.0001) return false;

    return true;
  });

  auto v_tan = UnitTest("vector trigonometric function tan", +[]() {
    vec3 v = radians(vec3(45, 0, -45));

    if (abs(asin(tan(v)) - v) > 0.0001) return false;
    if (abs(asin(tan(v.zyx)) - v.zyx) > 0.0001) return false;

    return true;
  });

  auto s_atan2 = UnitTest("scalar trigonometric function atan2", +[]() {
    if (abs(atan(0, 0)) > 0.0001) return false;
    if (abs(atan(0, 1.f)) > 0.0001) return false;
    if (abs(atan(1.f, 0) - radians(90)) > 0.0001) return false;
    if (abs(atan(1.l, 1.f) - radians(45)) > 0.0001) return false;

    return true;
  });
  auto v_atan2 = UnitTest("vector trigonometric function atan2", +[]() {
    vec2 v = vec2(1, 0);
    vec3 r = vec3(90, 45, 0);

    if (degrees(atan(0, v)) != 0) return false;
    if (degrees(atan(v, 0)) != r.xz) return false;
    if (degrees(atan(v.xx, v.xy)) != r.yx) return false;

    return true;
  });
}
