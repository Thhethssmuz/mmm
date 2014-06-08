#include <unittest.hpp>
#include <mmm.hpp>

namespace {

  auto s_length = UnitTest("scalar geometric function length", +[]() {
    if (length(1) != 1) return false;
    if (length(2.f) != 2) return false;
    if (length(3.0) != 3) return false;
    if (length(4.l) != 4) return false;

    return true;
  });
  auto v_length = UnitTest("vector geometric function length", +[]() {
    vec2 v = vec2(3, 4);

    if (length(v) != 5) return false;
    if (length(v.yx) != 5) return false;

    return true;
  });

  auto s_distance = UnitTest("scalar geometric function distance", +[]() {
    if (distance(1, 2) != 1) return false;
    if (distance(2, 1) != 1) return false;
    if (distance(1.f, 3) != 2) return false;
    if (distance(3.0, 1.l) != 2) return false;

    return true;
  });
  auto v_distance = UnitTest("vector geometric function distance", +[]() {
    vec2 v = vec2(9, 11);
    vec2 u = vec2(6, 7);

    if (distance(v, u) != 5) return false;
    if (distance(u, v) != 5) return false;

    if (distance(v.yx, u.yx) != 5) return false;
    if (distance(u.yx, v.yx) != 5) return false;

    return true;
  });

  auto s_dot = UnitTest("scalar geometric function dot", +[]() {
    if (dot(2, 4) != 8) return false;
    if (dot(2.f, 4) != 8) return false;
    if (dot(2, 4.0) != 8) return false;
    if (dot(2.l, 4.l) != 8) return false;

    return true;
  });
  auto v_dot = UnitTest("vector geometric function dot", +[]() {
    ivec2 v = ivec2(2, 4);
    ivec2 u = ivec2(4, -4);

    if (dot(v, u) != -8) return false;
    if (dot(u, v) != -8) return false;

    if (dot(v.yx, u.yx) != -8) return false;
    if (dot(u.yx, v.yx) != -8) return false;

    return true;
  });

  auto v_cross = UnitTest("vector geometric function cross", +[]() {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(3, 2, 1);

    if (cross(v, u) != vec3(-4, 8, -4)) return false;
    if (cross(u, v) != vec3(4, -8, 4)) return false;

    if (cross(v.zyx, u.zyx) != vec3(4, -8, 4)) return false;
    if (cross(u.zyx, v.zyx) != vec3(-4, 8, -4)) return false;

    return true;
  });

  auto s_normalize = UnitTest("scalar geometric function normalize", +[]() {
    if (normalize(12) != 1) return false;
    if (normalize(123.f) != 1) return false;
    if (normalize(-98.0) != 1) return false;
    if (normalize(-0.1l) != 1) return false;

    return true;
  });
  auto v_normalize = UnitTest("vector geometric function normalize", +[]() {
    vec2 v = vec2(1, 0);
    vec2 u = vec2(1, 1);
    vec2 t = vec2(3, 4);

    if (normalize(v) != v) return false;
    if (normalize(v.yx) != v.yx) return false;

    if (normalize(u.yx) != normalize(u)) return false;

    if (normalize(t) != vec2(0.6, 0.8)) return false;

    return true;
  });
}
