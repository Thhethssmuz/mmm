#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("vector reduction function sum", "[vec][red]") {

  SECTION("vec2") {
    vec2 v = vec2(1, 2);
    REQUIRE(sum(v) == Approx(3));
    REQUIRE(sum(v.xy) == Approx(3));
  }

  SECTION("vec3") {
    vec3 v = vec3(3, 4, 5);
    REQUIRE(sum(v) == Approx(12));
    REQUIRE(sum(v.xyz) == Approx(12));
  }

  SECTION("vec4") {
    vec4 v = vec4(6, 7, 8, 9);
    REQUIRE(sum(v) == Approx(30));
    REQUIRE(sum(v.xyzw) == Approx(30));
  }
}

TEST_CASE("vector reduction function product", "[vec][red]") {

  SECTION("vec2") {
    vec2 v = vec2(1, 2);
    REQUIRE(product(v) == Approx(2));
    REQUIRE(product(v.xy) == Approx(2));
  }

  SECTION("vec3") {
    vec3 v = vec3(3, 4, 5);
    REQUIRE(product(v) == Approx(60));
    REQUIRE(product(v.xyz) == Approx(60));
  }

  SECTION("vec4") {
    vec4 v = vec4(6, 7, 8, 9);
    REQUIRE(product(v) == Approx(3024));
    REQUIRE(product(v.xyzw) == Approx(3024));
  }
}

TEST_CASE("vector reduction function take", "[vec][red]") {

  SECTION("vec2") {
    vec2 v = vec2(1, 2);
    REQUIRE(take<1>(v) == 1);
    REQUIRE(take<1>(v.xy) == 1);
    REQUIRE(take<2>(v) == vec2(1, 2));
    REQUIRE(take<2>(v.xy) == vec2(1, 2));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);
    REQUIRE(take<1>(v) == 1);
    REQUIRE(take<1>(v.xyz) == 1);
    REQUIRE(take<2>(v) == vec2(1, 2));
    REQUIRE(take<2>(v.xyz) == vec2(1, 2));
    REQUIRE(take<3>(v) == vec3(1, 2, 3));
    REQUIRE(take<3>(v.xyz) == vec3(1, 2, 3));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);
    REQUIRE(take<1>(v) == 1);
    REQUIRE(take<1>(v.yx) == 2);
    REQUIRE(take<2>(v) == vec2(1, 2));
    REQUIRE(take<2>(v.xyz) == vec2(1, 2));
    REQUIRE(take<3>(v) == vec3(1, 2, 3));
    REQUIRE(take<3>(v.xyzw) == vec3(1, 2, 3));
    REQUIRE(take<4>(v) == vec4(1, 2, 3, 4));
    REQUIRE(take<4>(v.xyzw) == vec4(1, 2, 3, 4));
  }
}

TEST_CASE("vector reduction function drop", "[vec][red]") {

  SECTION("vec2") {
    vec2 v = vec2(1, 2);
    REQUIRE(drop<0>(v) == vec2(1, 2));
    REQUIRE(drop<0>(v.xy) == vec2(1, 2));
    REQUIRE(drop<1>(v) == 2);
    REQUIRE(drop<1>(v.xy) == 2);
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);
    REQUIRE(drop<0>(v) == vec3(1, 2, 3));
    REQUIRE(drop<0>(v.xyz) == vec3(1, 2, 3));
    REQUIRE(drop<1>(v) == vec2(2, 3));
    REQUIRE(drop<1>(v.xyz) == vec2(2, 3));
    REQUIRE(drop<2>(v) == 3);
    REQUIRE(drop<2>(v.xyz) == 3);
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);
    REQUIRE(drop<0>(v) == vec4(1, 2, 3, 4));
    REQUIRE(drop<0>(v.xyzw) == vec4(1, 2, 3, 4));
    REQUIRE(drop<1>(v) == vec3(2, 3, 4));
    REQUIRE(drop<1>(v.xyzw) == vec3(2, 3, 4));
    REQUIRE(drop<2>(v) == vec2(3, 4));
    REQUIRE(drop<2>(v.xyzw) == vec2(3, 4));
    REQUIRE(drop<3>(v) == 4);
    REQUIRE(drop<3>(v.xyzw) == 4);
  }
}
