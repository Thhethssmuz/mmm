#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("vector numeric operator +", "[vec][num]") {

  SECTION("vec2") {
    vec2 v = vec2(1, 2);
    vec2 u = vec2(3, 4);

    REQUIRE(1 + v == vec2(2, 3));
    REQUIRE(v + 1 == vec2(2, 3));
    REQUIRE(v + u == vec2(4, 6));
    REQUIRE(v.x + u == vec2(4, 5));
    REQUIRE(u + v.x == vec2(4, 5));
    REQUIRE(v.xy + u.xy == vec2(4, 6));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(4, 5, 6);

    REQUIRE(1 + v == vec3(2, 3, 4));
    REQUIRE(v + 1 == vec3(2, 3, 4));
    REQUIRE(v + u == vec3(5, 7, 9));
    REQUIRE(v.x + u == vec3(5, 6, 7));
    REQUIRE(u + v.x == vec3(5, 6, 7));
    REQUIRE(v.xyz + u.xyz == vec3(5, 7, 9));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);
    vec4 u = vec4(5, 6, 7, 8);

    REQUIRE(1 + v == vec4(2, 3, 4, 5));
    REQUIRE(v + 1 == vec4(2, 3, 4, 5));
    REQUIRE(v + u == vec4(6, 8, 10, 12));
    REQUIRE(v.x + u == vec4(6, 7, 8, 9));
    REQUIRE(u + v.x == vec4(6, 7, 8, 9));
    REQUIRE(v.xyzw + u.xyzw == vec4(6, 8, 10, 12));
  }
}

TEST_CASE("vector numeric operator -", "[vec][num]") {

  SECTION("vec2") {
    vec2 v = vec2(1, 2);
    vec2 u = vec2(3, 4);

    REQUIRE(1 - v == vec2(0, -1));
    REQUIRE(v - 1 == vec2(0, 1));
    REQUIRE(v - u == vec2(-2, -2));
    REQUIRE(v.x - u == vec2(-2, -3));
    REQUIRE(u - v.x == vec2(2, 3));
    REQUIRE(v.xy - u.xy == vec2(-2, -2));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(4, 5, 6);

    REQUIRE(1 - v == vec3(0, -1, -2));
    REQUIRE(v - 1 == vec3(0, 1, 2));
    REQUIRE(v - u == vec3(-3, -3, -3));
    REQUIRE(v.x - u == vec3(-3, -4, -5));
    REQUIRE(u - v.x == vec3(3, 4, 5));
    REQUIRE(v.xyz - u.xyz == vec3(-3, -3, -3));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);
    vec4 u = vec4(5, 6, 7, 8);

    REQUIRE(1 - v == vec4(0, -1, -2, -3));
    REQUIRE(v - 1 == vec4(0, 1, 2, 3));
    REQUIRE(v - u == vec4(-4, -4, -4, -4));
    REQUIRE(v.x - u == vec4(-4, -5, -6, -7));
    REQUIRE(u - v.x == vec4(4, 5, 6, 7));
    REQUIRE(v.xyzw - u.xyzw == vec4(-4, -4, -4, -4));
  }
}

TEST_CASE("vector numeric operator *", "[vec][num]") {

  SECTION("vec2") {
    vec2 v = vec2(1, 2);
    vec2 u = vec2(3, 4);

    REQUIRE(1 * v == vec2(1, 2));
    REQUIRE(v * 1 == vec2(1, 2));
    REQUIRE(v * u == vec2(3, 8));
    REQUIRE(v.x * u == vec2(3, 4));
    REQUIRE(u * v.x == vec2(3, 4));
    REQUIRE(v.xy * u.xy == vec2(3, 8));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(4, 5, 6);

    REQUIRE(1 * v == vec3(1, 2, 3));
    REQUIRE(v * 1 == vec3(1, 2, 3));
    REQUIRE(v * u == vec3(4, 10, 18));
    REQUIRE(v.x * u == vec3(4, 5, 6));
    REQUIRE(u * v.x == vec3(4, 5, 6));
    REQUIRE(v.xyz * u.xyz == vec3(4, 10, 18));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);
    vec4 u = vec4(5, 6, 7, 8);

    REQUIRE(1 * v == vec4(1, 2, 3, 4));
    REQUIRE(v * 1 == vec4(1, 2, 3, 4));
    REQUIRE(v * u == vec4(5, 12, 21, 32));
    REQUIRE(v.x * u == vec4(5, 6, 7, 8));
    REQUIRE(u * v.x == vec4(5, 6, 7, 8));
    REQUIRE(v.xyzw * u.xyzw == vec4(5, 12, 21, 32));
  }
}

TEST_CASE("vector numeric operator /", "[vec][num]") {

  SECTION("vec2") {
    vec2 v = vec2(1, 2);
    vec2 u = vec2(2, 4);

    REQUIRE(1 / v == vec2(1, 0.5));
    REQUIRE(v / 1 == vec2(1, 2));
    REQUIRE(v / u == vec2(0.5, 0.5));
    REQUIRE(v.x / u == vec2(0.5, 0.25));
    REQUIRE(u / v.x == vec2(2, 4));
    REQUIRE(v.xy / u.xy == vec2(0.5, 0.5));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 4);
    vec3 u = vec3(2, 4, 8);

    REQUIRE(1 / v == vec3(1, 0.5, 0.25));
    REQUIRE(v / 1 == vec3(1, 2, 4));
    REQUIRE(v / u == vec3(0.5, 0.5, 0.5));
    REQUIRE(v.x / u == vec3(0.5, 0.25, 0.125));
    REQUIRE(u / v.x == vec3(2, 4, 8));
    REQUIRE(v.xyz / u.xyz == vec3(0.5, 0.5, 0.5));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 4, 8);
    vec4 u = vec4(2, 4, 8, 16);

    REQUIRE(1 / v == vec4(1, 0.5, 0.25, 0.125));
    REQUIRE(v / 1 == vec4(1, 2, 4, 8));
    REQUIRE(v / u == vec4(0.5, 0.5, 0.5, 0.5));
    REQUIRE(v.x / u == vec4(0.5, 0.25, 0.125, 0.0625));
    REQUIRE(u / v.x == vec4(2, 4, 8, 16));
    REQUIRE(v.xyzw / u.xyzw == vec4(0.5, 0.5, 0.5, 0.5));
  }
}
