#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto s_abs = UnitTest("scalar common function abs", +[]() {
    if (abs(8) != 8) return false;
    if (abs(-8) != 8) return false;
    if (abs(-8.f) != 8) return false;
    if (abs(-8.0) != 8) return false;
    if (abs(-8.l) != 8) return false;

    return true;
  });
  auto v_abs = UnitTest("vector common function abs", +[]() {
    vec4 v = vec4(0, 1, -2, -3);

    if (abs(v) != vec4(0, 1, 2, 3)) return false;
    if (abs(v.wzyx) != vec4(3, 2, 1, 0)) return false;

    return true;
  });

  auto s_sign = UnitTest("scalar common function sign", +[]() {
    if (sign(0) != 0) return false;
    if (sign(0.f) != 0) return false;

    if (sign(234) != 1) return false;
    if (sign(0.1f) != 1) return false;

    if (sign(-23) != -1) return false;
    if (sign(-0.01l) != -1) return false;

    return true;
  });
  auto v_sign = UnitTest("vector common function sign", +[]() {
    vec4 v = vec4(0, 0.1, -0.2, -3);

    if (sign(v) != vec4(0, 1, -1, -1)) return false;
    if (sign(v.wzyx) != vec4(-1, -1, 1, 0)) return false;

    return true;
  });

  auto s_floor = UnitTest("scalar common function floor", +[]() {
    if (floor(0.5) != 0) return false;
    if (floor(0) != 0) return false;
    if (floor(-0.5) != -1) return false;

    return true;
  });
  auto v_floor = UnitTest("vector common function floor", +[]() {
    vec3 v = vec3(0.5, 0, -0.5);

    if (floor(v) != vec3(0, 0, -1)) return false;
    if (floor(v.zyx) != vec3(-1, 0, 0)) return false;

    return true;
  });

  auto s_ceil = UnitTest("scalar common function ceil", +[]() {
    if (ceil(0.5) != 1) return false;
    if (ceil(0) != 0) return false;
    if (ceil(-0.5) != 0) return false;

    return true;
  });
  auto v_ceil = UnitTest("vector common function ceil", +[]() {
    vec3 v = vec3(0.5, 0, -0.5);

    if (ceil(v) != vec3(1, 0, 0)) return false;
    if (ceil(v.zyx) != vec3(0, 0, 1)) return false;

    return true;
  });

  auto s_fract = UnitTest("scalar common function fract", +[]() {
    if (fract(1) != 0) return false;
    if (fract(1.5) != 0.5) return false;
    if (fract(-1.2) != 0.8) return false;

    if (fract(0) != 0) return false;

    return true;
  });
  auto v_fract = UnitTest("vector common function fract", +[]() {
    dvec3 v = dvec3(1, 1.5, -1.2);

    if (fract(v) != dvec3(0, 0.5, 0.8)) return false;
    if (fract(v.zyx) != dvec3(0.8, 0.5, 0)) return false;

    return true;
  });

  auto s_mod = UnitTest("scalar common function mod", +[]() {
    if (mod(9, 4) != 1) return false;
    if (mod(9.f, 4) != 1) return false;
    if (mod(9.0, 4.0f) != 1) return false;

    if (mod(-9, 4) != 3) return false;
    if (mod(-9.f, 4) != 3) return false;
    if (mod(-9.0, 4.0f) != 3) return false;

    if (mod(9, -4) != -3) return false;
    if (mod(9.f, -4) != -3) return false;
    if (mod(9.0, -4.0f) != -3) return false;

    if (mod(-9, -4) != -1) return false;
    if (mod(-9.f, -4) != -1) return false;
    if (mod(-9.0, -4.0f) != -1) return false;

    return true;
  });
  auto v_mod = UnitTest("vector common function mod", +[]() {
    ivec2 v = ivec2(9, -9);
    ivec2 u = ivec2(4, -4);

    if (mod(v, 4.0f) != ivec2(1, 3)) return false;
    if (mod(-9, u) != ivec2(3, -1)) return false;

    if (mod(v.xx, 4.f) != 1) return false;
    if (mod(9.f, u.xx) != 1) return false;

    if (mod(v, u) != ivec2(1, -1)) return false;
    if (mod(v.yx, u.yx) != ivec2(-1, 1)) return false;

    return true;
  });

  auto s_min = UnitTest("scalar common function min", +[]() {
    if (min(9, 4) != 4) return false;
    if (min(9.f, 4) != 4) return false;
    if (min(4.f, 9.0) != 4) return false;

    vec2 v = vec2(1, 2);

    if (min(0, v.x) != 0) return false;
    if (min(2, v.x) != 1) return false;

    if (min(1, v.y) != 1) return false;
    if (min(3, v.y) != 2) return false;

    return true;
  });
  auto v_min = UnitTest("vector common function min", +[]() {
    vec3 v = vec3(2, 4, 6);
    vec3 u = vec3(2, 8, 2);

    if (min(v, 4) != vec3(2, 4, 4)) return false;
    if (min(4, v) != vec3(2, 4, 4)) return false;
    if (min(v, u) != vec3(2, 4, 2)) return false;

    if (min(u.xyy, 4) != vec3(2, 4, 4)) return false;
    if (min(4, u.xyy) != vec3(2, 4, 4)) return false;
    if (min(v.zzz, u.xyy) != vec3(2, 6, 6)) return false;


    return true;
  });

  auto s_max = UnitTest("scalar common function max", +[]() {
    if (max(9, 4) != 9) return false;
    if (max(9.f, 4) != 9) return false;
    if (max(4.f, 9.0) != 9) return false;

    vec2 v = vec2(1, 2);

    if (max(0, v.x) != 1) return false;
    if (max(2, v.x) != 2) return false;

    if (max(1, v.y) != 2) return false;
    if (max(3, v.y) != 3) return false;

    return true;
  });
  auto v_max = UnitTest("vector common function max", +[]() {
    vec3 v = vec3(2, 4, 6);
    vec3 u = vec3(2, 8, 2);

    if (max(v, 4) != vec3(4, 4, 6)) return false;
    if (max(4, v) != vec3(4, 4, 6)) return false;
    if (max(v, u) != vec3(2, 8, 6)) return false;

    if (max(u.xyy, 4) != vec3(4, 8, 8)) return false;
    if (max(4, u.xyy) != vec3(4, 8, 8)) return false;
    if (max(v.zzz, u.xyy) != vec3(6, 8, 8)) return false;

    return true;
  });

  auto s_clamp = UnitTest("scalar common function clamp", +[]() {
    if (clamp(50, 0, 100) != 50) return false;
    if (clamp(-50.f, 0, 100) != 0) return false;
    if (clamp(250, 0.f, 100) != 100) return false;
    if (clamp(50, -100, -50.f) != -50) return false;

    return true;
  });
  auto v_clamp = UnitTest("vector common function clamp", +[]() {
    ivec4 v = ivec4(-50, 25, 50, 150);
    ivec4 l = ivec4(-25, 0, 25, 50);
    ivec4 h = ivec4(50, 75, 100, 125);

    if (clamp(v, 0, 100) != ivec4(0, 25, 50, 100)) return false;
    if (clamp(v.xxzw, 0.f, 100.l) != ivec4(0, 0, 50, 100)) return false;

    if (clamp(v, l, h) != ivec4(-25, 25, 50, 125)) return false;
    if (clamp(v.xy, l.xy, h.xy) != ivec2(-25, 25)) return false;

    return true;
  });

  auto s_mix = UnitTest("scalar common function mix", +[]() {
    if (mix(0, 4, 0.5) != 2) return false;
    if (mix(0, 4.f, 0) != 0) return false;
    if (mix(0.l, 4, 1) != 4) return false;
    if (mix(-1.0, 3.0, 0.5) != 1) return false;

    return true;
  });
  auto v_mix = UnitTest("vector common function mix", +[]() {
    vec4 v = vec4(1, 2, 3, 4);
    vec4 u = vec4(5, 6, 7, 8);
    vec4 a = vec4(0, 0.5, 0.5, 1);

    if (mix(v, u, 0.5) != vec4(3, 4, 5, 6)) return false;
    if (mix(v, u, a) != vec4(1, 4, 5, 8)) return false;

    if (mix(v.wzyx, u.wzyx, 0.5) != vec4(6, 5, 4, 3)) return false;
    if (mix(v.wzyx, u.wzyx, a.wzyx) != vec4(8, 5, 4, 1)) return false;

    return true;
  });

  auto s_step = UnitTest("scalar common function step", +[]() {
    if (step(2, 1) != 0) return false;
    if (step(2, 2.f) != 1) return false;
    if (step(2.f, 3.l) != 1) return false;

    return true;
  });
  auto v_step = UnitTest("vector common function step", +[]() {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(2, 2, 2);

    if (step(v, 2) != vec3(1, 1, 0)) return false;
    if (step(2, v) != vec3(0, 1, 1)) return false;

    if (step(v.zyx, 2.l) != vec3(0, 1, 1)) return false;
    if (step(2.0, v.zyx) != vec3(1, 1, 0)) return false;

    if (step(v, u) != vec3(1, 1, 0)) return false;
    if (step(v.zyx, u) != vec3(0, 1, 1)) return false;

    return true;
  });
}
