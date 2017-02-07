#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("vector geometric function length", "[vec][geo]") {

  SECTION("scalar") {
    REQUIRE(length(0) == 0);
    REQUIRE(length(1) == 1);
    REQUIRE(length(2.f) == 2);
    REQUIRE(length(-1.0) == 1);
  }

  SECTION("vec2") {
    vec2 v = vec2(3, 4);
    REQUIRE(length(v) == Approx(5));
    REQUIRE(length(v.xy) == Approx(5));
  }

  SECTION("vec3") {
    vec3 v = vec3(3, 4, 5);
    REQUIRE(length(v) == Approx(7.07107));
    REQUIRE(length(v.xyz) == Approx(7.07107));
  }

  SECTION("vec4") {
    vec4 v = vec4(3, 4, 5, 6);
    REQUIRE(length(v) == Approx(9.27362));
    REQUIRE(length(v.xyzw) == Approx(9.27362));
  }
}

TEST_CASE("vector geometric function distance", "[vec][geo]") {

  SECTION("scalar") {
    REQUIRE(distance(0, 1) == Approx(1));
    REQUIRE(distance(2, 1) == Approx(1));
    REQUIRE(distance(1.f, 3) == Approx(2));
    REQUIRE(distance(-1.0, 2.f) == Approx(3));
  }

  SECTION("vec2") {
    vec2 v = vec2(1, 2);
    vec2 u = vec2(3, 4);

    REQUIRE(distance(v, u) == Approx(2.82843));
    REQUIRE(distance(v.xy, u.xy) == Approx(2.82843));
  }

  SECTION("vec3") {
    vec3 v = vec3(0, 2, 1);
    vec3 u = vec3(1, 1, 3);

    REQUIRE(distance(v, u) == Approx(2.44949));
    REQUIRE(distance(v.xyz, u.xyz) == Approx(2.44949));
  }

  SECTION("vec4") {
    vec4 v = vec4(0, 2, 1, -1);
    vec4 u = vec4(1, 1, 3, 2);

    REQUIRE(distance(v, u) == Approx(3.87298));
    REQUIRE(distance(v.xyzw, u.xyzw) == Approx(3.87298));
  }
}

TEST_CASE("vector geometric function dot", "[vec][geo]") {

  SECTION("scalar") {
    REQUIRE(dot(1, 2) == Approx(2));
    REQUIRE(dot(3, 4) == Approx(12));
    REQUIRE(dot(5.f, 6) == Approx(30));
    REQUIRE(dot(7.0, 8) == Approx(56));
  }

  SECTION("vec2") {
    vec2 v = vec2(1, 2);
    vec2 u = vec2(3, 4);

    REQUIRE(dot(v, u) == Approx(11));
    REQUIRE(dot(v.xy, u.xy) == Approx(11));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(4, 5, 6);

    REQUIRE(dot(v, u) == Approx(32));
    REQUIRE(dot(v.xyz, u.xyz) == Approx(32));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);
    vec4 u = vec4(5, 6, 7, 8);

    REQUIRE(dot(v, u) == Approx(70));
    REQUIRE(dot(v.xyzw, u.xyzw) == Approx(70));
  }
}

TEST_CASE("vector geometric function cross", "[vec][geo]") {

  vec3 v = vec3(1, 2, 3);
  vec3 u = vec3(3, 2, 1);

  REQUIRE(cross(v, u) == vec3(-4, 8, -4));
  REQUIRE(cross(u, v) == vec3(4, -8, 4));

  REQUIRE(cross(v.xyz, u.xyz) == vec3(-4, 8, -4));
  REQUIRE(cross(u.xyz, v.xyz) == vec3(4, -8, 4));
}

TEST_CASE("vector geometric function normalize", "[vec][geo]") {

  SECTION("scalar") {
    REQUIRE(normalize(0) == 1);
    REQUIRE(normalize(1) == 1);
    REQUIRE(normalize(2.f) == 1);
    REQUIRE(normalize(3.0) == 1);
  }

  SECTION("vec2") {
    vec2 v = vec2(3, 4);
    vec2 n = normalize(v);

    REQUIRE(n[0] == Approx(0.6));
    REQUIRE(n[1] == Approx(0.8));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);
    REQUIRE(length(normalize(v)) == Approx(1));
    REQUIRE(length(normalize(v.xyz)) == Approx(1));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);
    REQUIRE(length(normalize(v)) == Approx(1));
    REQUIRE(length(normalize(v.xyzw)) == Approx(1));
    REQUIRE(length(normalize(vec4(5, 0, -5, 17))) == Approx(1));
  }
}
