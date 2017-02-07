#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("vector relational function radians", "[vec][rel]") {

  SECTION("scalar") {
    REQUIRE(radians(90) == Approx(1.5708));
    REQUIRE(radians(90.f) == Approx(1.5708));
    REQUIRE(radians(90.0) == Approx(1.5708));
    REQUIRE(radians(90.l) == Approx(1.5708));
  }

  SECTION("vec2") {
    vec2 v = radians(vec2(0, 45));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(0.785398));
  }

  SECTION("vec3") {
    vec3 v = radians(vec3(0, 45, 90));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(0.785398));
    REQUIRE(v[2] == Approx(1.5708));
  }

  SECTION("vec4") {
    vec4 v = radians(vec4(0, 45, 90, 180));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(0.785398));
    REQUIRE(v[2] == Approx(1.5708));
    REQUIRE(v[3] == Approx(3.14159));
  }
}

TEST_CASE("vector relational function degrees", "[vec][rel]") {

  SECTION("scalar") {
    REQUIRE(degrees(0) == Approx(0));
    REQUIRE(degrees(1.5708f) == Approx(90));
    REQUIRE(degrees(1.5708) == Approx(90));
    REQUIRE(degrees(1.5708l) == Approx(90));
  }

  SECTION("vec2") {
    vec2 v = degrees(vec2(0, 0.785398));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(45));
  }

  SECTION("vec3") {
    vec3 v = degrees(vec3(0, 0.785398, 1.5708));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(45));
    REQUIRE(v[2] == Approx(90));
  }

  SECTION("vec4") {
    vec4 v = degrees(vec4(0, 0.785398, 1.5708, 3.14159));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(45));
    REQUIRE(v[2] == Approx(90));
    REQUIRE(v[3] == Approx(180));
  }
}

TEST_CASE("vector relational function sin", "[vec][rel]") {

  SECTION("scalar") {
    REQUIRE(sin(radians(0)) == Approx(0));
    REQUIRE(sin(radians(45)) == Approx(0.70711));
    REQUIRE(sin(radians(-45.f)) == Approx(-0.70711));
    REQUIRE(sin(radians(90.0)) == Approx(1));
  }

  SECTION("vec2") {
    vec2 v = sin(radians(vec2(0, 45)));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(0.70711));
  }

  SECTION("vec3") {
    vec3 v = sin(radians(vec3(0, 45, -45)));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(0.70711));
    REQUIRE(v[2] == Approx(-0.70711));
  }

  SECTION("vec4") {
    vec4 v = sin(radians(vec4(0, 45, -45, 90)));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(0.70711));
    REQUIRE(v[2] == Approx(-0.70711));
    REQUIRE(v[3] == Approx(1));
  }
}

TEST_CASE("vector relational function cos", "[vec][rel]") {

  SECTION("scalar") {
    REQUIRE(cos(radians(0)) == Approx(1));
    REQUIRE(cos(radians(45)) == Approx(0.70711));
    REQUIRE(cos(radians(-45.f)) == Approx(0.70711));
    REQUIRE(cos(radians(90.0)) == Approx(0));
  }

  SECTION("vec2") {
    vec2 v = cos(radians(vec2(0, 45)));
    REQUIRE(v[0] == Approx(1));
    REQUIRE(v[1] == Approx(0.70711));
  }

  SECTION("vec3") {
    vec3 v = cos(radians(vec3(0, 45, -45)));
    REQUIRE(v[0] == Approx(1));
    REQUIRE(v[1] == Approx(0.70711));
    REQUIRE(v[2] == Approx(0.70711));
  }

  SECTION("vec4") {
    vec4 v = cos(radians(vec4(0, 45, -45, 90)));
    REQUIRE(v[0] == Approx(1));
    REQUIRE(v[1] == Approx(0.70711));
    REQUIRE(v[2] == Approx(0.70711));
    REQUIRE(v[3] == Approx(0));
  }
}

TEST_CASE("vector relational function tan", "[vec][rel]") {

  SECTION("scalar") {
    REQUIRE(tan(radians(0)) == Approx(0));
    REQUIRE(tan(radians(45)) == Approx(1));
    REQUIRE(tan(radians(-45.f)) == Approx(-1));
    REQUIRE(tan(radians(30.0)) == Approx(0.57735));
  }

  SECTION("vec2") {
    vec2 v = tan(radians(vec2(0, 45)));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(1));
  }

  SECTION("vec3") {
    vec3 v = tan(radians(vec3(0, 45, -45)));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(1));
    REQUIRE(v[2] == Approx(-1));
  }

  SECTION("vec4") {
    vec4 v = tan(radians(vec4(0, 45, -45, 30)));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(1));
    REQUIRE(v[2] == Approx(-1));
    REQUIRE(v[3] == Approx(0.57735));
  }
}

// asin
// acos
// atan (single argument version)

TEST_CASE("vector relational function atan", "[vec][rel]") {

  SECTION("scalar") {
    REQUIRE(atan(0, 0) == Approx(0));
    REQUIRE(atan(1, 1) == Approx(0.78540));
    REQUIRE(atan(1.f, -1) == Approx(2.35619));
    REQUIRE(atan(-1.0, 1) == Approx(-0.78540));
  }

  SECTION("vec2") {
    vec2 v = atan(vec2(0, 1), vec2(0, 1));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(0.78540));
  }

  SECTION("vec3") {
    vec3 v = atan(vec3(0, 1, 1), vec3(0, 1, -1));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(0.78540));
    REQUIRE(v[2] == Approx(2.35619));
  }

  SECTION("vec4") {
    vec4 v = atan(vec4(0, 1, 1, -1), vec4(0, 1, -1, 1));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(0.78540));
    REQUIRE(v[2] == Approx(2.35619));
    REQUIRE(v[3] == Approx(-0.78540));
  }
}
