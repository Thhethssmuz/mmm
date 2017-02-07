#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("vector common function abs", "[vec][common]") {

  SECTION("scalar") {
    REQUIRE(abs(8) == 8);
    REQUIRE(abs(-8) == 8);
    REQUIRE(abs(-8.f) == 8);
    REQUIRE(abs(-8.0) == 8);
    REQUIRE(abs(-8.l) == 8);
  }

  SECTION("vec2") {
    vec2 v = vec2(-1, 2);
    REQUIRE(abs(v) == vec2(1, 2));
    REQUIRE(abs(v.xy) == vec2(1, 2));
  }

  SECTION("vec3") {
    vec3 v = vec3(-1, 2, -3);
    REQUIRE(abs(v) == vec3(1, 2, 3));
    REQUIRE(abs(v.xyz) == vec3(1, 2, 3));
  }

  SECTION("vec4") {
    vec4 v = vec4(-1, 2, -3, 4);
    REQUIRE(abs(v) == vec4(1, 2, 3, 4));
    REQUIRE(abs(v.xyzw) == vec4(1, 2, 3, 4));
  }
}

TEST_CASE("vector common function sign", "[vec][common]") {

  SECTION("scalar") {
    REQUIRE(sign(1) == 1);
    REQUIRE(sign(0) == 0);
    REQUIRE(sign(-1) == -1);

    REQUIRE(sign(2.f) == 1);
    REQUIRE(sign(0.f) == 0);
    REQUIRE(sign(-2.f) == -1);

    REQUIRE(sign(3.0) == 1);
    REQUIRE(sign(0.0) == 0);
    REQUIRE(sign(-3.0) == -1);

    REQUIRE(sign(4.l) == 1);
    REQUIRE(sign(0.l) == 0);
    REQUIRE(sign(-4.l) == -1);
  }

  SECTION("vec2") {
    vec2 v = vec2(-1, 0);
    REQUIRE(sign(v) == vec2(-1, 0));
    REQUIRE(sign(v.xy) == vec2(-1, 0));
  }

  SECTION("vec3") {
    vec3 v = vec3(-1, 0, -3);
    REQUIRE(sign(v) == vec3(-1, 0, -1));
    REQUIRE(sign(v.xyz) == vec3(-1, 0, -1));
  }

  SECTION("vec4") {
    vec4 v = vec4(-1, 0, -3, 4);
    REQUIRE(sign(v) == vec4(-1, 0, -1, 1));
    REQUIRE(sign(v.xyzw) == vec4(-1, 0, -1, 1));
  }
}

TEST_CASE("vector common function floor", "[vec][common]") {

  SECTION("scalar") {
    REQUIRE(floor(0.5) == 0);
    REQUIRE(floor(0) == 0);
    REQUIRE(floor(-0.5) == -1);
  }

  SECTION("vec2") {
    vec2 v = vec2(0.5, 0);
    REQUIRE(floor(v) == vec2(0, 0));
    REQUIRE(floor(v.xy) == vec2(0, 0));
  }

  SECTION("vec3") {
    vec3 v = vec3(0.5, 0, -0.5);
    REQUIRE(floor(v) == vec3(0, 0, -1));
    REQUIRE(floor(v.xyz) == vec3(0, 0, -1));
  }

  SECTION("vec4") {
    vec4 v = vec4(0.5, 0, -0.5, -1.5);
    REQUIRE(floor(v) == vec4(0, 0, -1, -2));
    REQUIRE(floor(v.xyzw) == vec4(0, 0, -1, -2));
  }
}

TEST_CASE("vector common function ceil", "[vec][common]") {

  SECTION("scalar") {
    REQUIRE(ceil(0.5) == 1);
    REQUIRE(ceil(0) == 0);
    REQUIRE(ceil(-0.5) == 0);
  }

  SECTION("vec2") {
    vec2 v = vec2(0.5, 0);
    REQUIRE(ceil(v) == vec2(1, 0));
    REQUIRE(ceil(v.xy) == vec2(1, 0));
  }

  SECTION("vec3") {
    vec3 v = vec3(0.5, 0, -0.5);
    REQUIRE(ceil(v) == vec3(1, 0, 0));
    REQUIRE(ceil(v.xyz) == vec3(1, 0, 0));
  }

  SECTION("vec4") {
    vec4 v = vec4(0.5, 0, -0.5, -1.5);
    REQUIRE(ceil(v) == vec4(1, 0, 0, -1));
    REQUIRE(ceil(v.xyzw) == vec4(1, 0, 0, -1));
  }
}

TEST_CASE("vector common function fract", "[vec][common]") {

  SECTION("scalar") {
    REQUIRE(fract(0) == 0);
    REQUIRE(fract(1) == 0);
    REQUIRE(fract(1.5) == 0.5);
    REQUIRE(fract(-2.25) == 0.75);
  }

  SECTION("vec2") {
    vec2 v = vec2(1, 1.5);
    REQUIRE(fract(v) == vec2(0, 0.5));
    REQUIRE(fract(v.xy) == vec2(0, 0.5));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 1.5, -2.25);
    REQUIRE(fract(v) == vec3(0, 0.5, 0.75));
    REQUIRE(fract(v.xyz) == vec3(0, 0.5, 0.75));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 1.5, -2.25, 0);
    REQUIRE(fract(v) == vec4(0, 0.5, 0.75, 0));
    REQUIRE(fract(v.xyzw) == vec4(0, 0.5, 0.75, 0));
  }
}

TEST_CASE("vector common function mod", "[vec][common]") {

  SECTION("scalar") {
    REQUIRE(mod(9, 4) == 1);
    REQUIRE(mod(9.f, 4) == 1);
    REQUIRE(mod(9.0, 4.0f) == 1);

    REQUIRE(mod(-9, 4) == 3);
    REQUIRE(mod(-9.f, 4) == 3);
    REQUIRE(mod(-9.0, 4.0f) == 3);

    REQUIRE(mod(9, -4) == -3);
    REQUIRE(mod(9.f, -4) == -3);
    REQUIRE(mod(9.0, -4.0f) == -3);

    REQUIRE(mod(-9, -4) == -1);
    REQUIRE(mod(-9.f, -4) == -1);
    REQUIRE(mod(-9.0, -4.0f) == -1);
  }

  SECTION("vec2") {
    vec2 v = vec2(9, -9);
    vec2 u = vec2(4, -4);
    REQUIRE(mod(v, u) == vec2(1, -1));
    REQUIRE(mod(v.xy, u.xy) == vec2(1, -1));
  }

  SECTION("vec3") {
    vec3 v = vec3(9, -9, 9);
    vec3 u = vec3(4, -4, -4);
    REQUIRE(mod(v, u) == vec3(1, -1, -3));
    REQUIRE(mod(v.xyz, u.xyz) == vec3(1, -1, -3));
  }

  SECTION("vec4") {
    vec4 v = vec4(9, -9, 9, -9);
    vec4 u = vec4(4, -4, -4, 4);
    REQUIRE(mod(v, u) == vec4(1, -1, -3, 3));
    REQUIRE(mod(v.xyzw, u.xyzw) == vec4(1, -1, -3, 3));
  }
}

TEST_CASE("vector common function min", "[vec][common]") {

  SECTION("scalar") {
    vec2 v = vec2(9, 4);

    REQUIRE(min(9, 4) == 4);
    REQUIRE(min(9.f, 4) == 4);
    REQUIRE(min(4.f, 9.0) == 4);

    REQUIRE(min(v.x, 4) == 4);
    REQUIRE(min(v.y, 9) == 4);
    REQUIRE(min(4, v.x) == 4);
    REQUIRE(min(9, v.y) == 4);
  }

  SECTION("vec2") {
    vec2 v = vec2(1, 0);
    vec2 u = vec2(-1, 2);
    REQUIRE(min(v, u) == vec2(-1, 0));
    REQUIRE(min(v.xy, u.xy) == vec2(-1, 0));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 0, 3);
    vec3 u = vec3(-1, 2, 1);
    REQUIRE(min(v, u) == vec3(-1, 0, 1));
    REQUIRE(min(v.xyz, u.xyz) == vec3(-1, 0, 1));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 0, 3, 2);
    vec4 u = vec4(-1, 2, 1, 4);
    REQUIRE(min(v, u) == vec4(-1, 0, 1, 2));
    REQUIRE(min(v.xyzw, u.xyzw) == vec4(-1, 0, 1, 2));
  }
}

TEST_CASE("vector common function max", "[vec][common]") {

  SECTION("scalar") {
    vec2 v = vec2(9, 4);

    REQUIRE(max(9, 4) == 9);
    REQUIRE(max(9.f, 4) == 9);
    REQUIRE(max(4.f, 9.0) == 9);

    REQUIRE(max(v.x, 4) == 9);
    REQUIRE(max(v.y, 9) == 9);
    REQUIRE(max(4, v.x) == 9);
    REQUIRE(max(9, v.y) == 9);
  }

  SECTION("vec2") {
    vec2 v = vec2(1, 0);
    vec2 u = vec2(-1, 2);
    REQUIRE(max(v, u) == vec2(1, 2));
    REQUIRE(max(v.xy, u.xy) == vec2(1, 2));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 0, 3);
    vec3 u = vec3(-1, 2, 1);
    REQUIRE(max(v, u) == vec3(1, 2, 3));
    REQUIRE(max(v.xyz, u.xyz) == vec3(1, 2, 3));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 0, 3, 2);
    vec4 u = vec4(-1, 2, 1, 4);
    REQUIRE(max(v, u) == vec4(1, 2, 3, 4));
    REQUIRE(max(v.xyzw, u.xyzw) == vec4(1, 2, 3, 4));
  }
}

TEST_CASE("vector common function clamp", "[vec][common]") {

  SECTION("scalar") {
    REQUIRE(clamp(-1, 0, 1) == 0);
    REQUIRE(clamp(1.f, 0, 1) == 1);
    REQUIRE(clamp(4.0, 0, 1) == 1);
    REQUIRE(clamp(8.l, 0, 1) == 1);
  }

  SECTION("vec2") {
    ivec2 v = ivec2(-1, 1);
    ivec2 l = ivec2(0, 0);
    ivec2 h = ivec2(1, 2);

    REQUIRE(clamp(v, 0, 1) == ivec2(0, 1));
    REQUIRE(clamp(v.xy, 0, 1) == ivec2(0, 1));

    REQUIRE(clamp(v, l, h) == ivec2(0, 1));
    REQUIRE(clamp(v.xy, l.xy, h.xy) == ivec2(0, 1));
  }

  SECTION("vec3") {
    ivec3 v = ivec3(-1, 1, 4);
    ivec3 l = ivec3(0, 0, 0);
    ivec3 h = ivec3(1, 2, 3);

    REQUIRE(clamp(v, 0, 1) == ivec3(0, 1, 1));
    REQUIRE(clamp(v.xyz, 0, 1) == ivec3(0, 1, 1));

    REQUIRE(clamp(v, l, h) == ivec3(0, 1, 3));
    REQUIRE(clamp(v.xyz, l.xyz, h.xyz) == ivec3(0, 1, 3));
  }

  SECTION("vec4") {
    ivec4 v = ivec4(-1, 1, 4, 8);
    ivec4 l = ivec4(0, 0, 0, 0);
    ivec4 h = ivec4(1, 2, 3, 4);

    REQUIRE(clamp(v, 0, 1) == ivec4(0, 1, 1, 1));
    REQUIRE(clamp(v.xyzw, 0, 1) == ivec4(0, 1, 1, 1));

    REQUIRE(clamp(v, l, h) == ivec4(0, 1, 3, 4));
    REQUIRE(clamp(v.xyzw, l.xyzw, h.xyzw) == ivec4(0, 1, 3, 4));
  }
}

TEST_CASE("vector common function mix", "[vec][common]") {

  SECTION("scalar") {
    REQUIRE(mix(0, 4, 0.5) == 2);
    REQUIRE(mix(0, 4.f, 0) == 0);
    REQUIRE(mix(0.l, 4, 1) == 4);
    REQUIRE(mix(-1.0, 3.0, 0.5) == 1);
  }

  SECTION("vec2") {
    vec2 v = vec2(1, 2);
    vec2 u = vec2(5, 6);
    vec2 a = vec2(0, 0.5);

    REQUIRE(mix(v, u, 0.5) == vec2(3, 4));
    REQUIRE(mix(v, u, a) == vec2(1, 4));

    REQUIRE(mix(v.xy, u.xy, 0.5) == vec2(3, 4));
    REQUIRE(mix(v.xy, u.xy, a.xy) == vec2(1, 4));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(5, 6, 7);
    vec3 a = vec3(0, 0.5, 0.5);

    REQUIRE(mix(v, u, 0.5) == vec3(3, 4, 5));
    REQUIRE(mix(v, u, a) == vec3(1, 4, 5));

    REQUIRE(mix(v.xyz, u.xyz, 0.5) == vec3(3, 4, 5));
    REQUIRE(mix(v.xyz, u.xyz, a.xyz) == vec3(1, 4, 5));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);
    vec4 u = vec4(5, 6, 7, 8);
    vec4 a = vec4(0, 0.5, 0.5, 1);

    REQUIRE(mix(v, u, 0.5) == vec4(3, 4, 5, 6));
    REQUIRE(mix(v, u, a) == vec4(1, 4, 5, 8));

    REQUIRE(mix(v.xyzw, u.xyzw, 0.5) == vec4(3, 4, 5, 6));
    REQUIRE(mix(v.xyzw, u.xyzw, a.xyzw) == vec4(1, 4, 5, 8));
  }
}

TEST_CASE("vector common function step", "[vec][common]") {

  SECTION("scalar") {
    REQUIRE(step(2, 1) == 0);
    REQUIRE(step(2, 2.f) == 1);
    REQUIRE(step(2.f, 3.l) == 1);
  }

  SECTION("vec2") {
    vec2 v = vec2(1, 2);
    vec2 u = vec2(2, 2);

    REQUIRE(step(v, 2) == vec2(1, 1));
    REQUIRE(step(2, v) == vec2(0, 1));

    REQUIRE(step(v.xy, 2.f) == vec2(1, 1));
    REQUIRE(step(2.f, v.xy) == vec2(0, 1));

    REQUIRE(step(v, u) == vec2(1, 1));
    REQUIRE(step(v.xy, u.xy) == vec2(1, 1));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(2, 2, 2);

    REQUIRE(step(v, 2) == vec3(1, 1, 0));
    REQUIRE(step(2, v) == vec3(0, 1, 1));

    REQUIRE(step(v.xyz, 2.f) == vec3(1, 1, 0));
    REQUIRE(step(2.f, v.xyz) == vec3(0, 1, 1));

    REQUIRE(step(v, u) == vec3(1, 1, 0));
    REQUIRE(step(v.xyz, u.xyz) == vec3(1, 1, 0));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);
    vec4 u = vec4(2, 2, 2, 3);

    REQUIRE(step(v, 2) == vec4(1, 1, 0, 0));
    REQUIRE(step(2, v) == vec4(0, 1, 1, 1));

    REQUIRE(step(v.xyzw, 2.f) == vec4(1, 1, 0, 0));
    REQUIRE(step(2.f, v.xyzw) == vec4(0, 1, 1, 1));

    REQUIRE(step(v, u) == vec4(1, 1, 0, 0));
    REQUIRE(step(v.xyzw, u.xyzw) == vec4(1, 1, 0, 0));
  }
}
