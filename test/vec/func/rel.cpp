#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("vector relational function lessThan", "[vec][rel]") {

  SECTION("scalar") {
    REQUIRE(lessThan(1, 2) == true);
    REQUIRE(lessThan(1, 1) == false);
    REQUIRE(lessThan(2, 1) == false);
    REQUIRE(lessThan(1.f, 2) == true);
    REQUIRE(lessThan(2.0, 1) == false);
  }

  SECTION("vec2") {
    vec2 v = vec2(1, 2);

    REQUIRE(lessThan(2, v) == bvec2(0, 0));
    REQUIRE(lessThan(v, 2) == bvec2(1, 0));
    REQUIRE(lessThan(2, v.xy) == bvec2(0, 0));
    REQUIRE(lessThan(v.xy, 2) == bvec2(1, 0));

    REQUIRE(lessThan(vec2(2, 2), v) == bvec2(0, 0));
    REQUIRE(lessThan(v, vec2(2, 2)) == bvec2(1, 0));
    REQUIRE(lessThan(vec2(2, 2), v.xy) == bvec2(0, 0));
    REQUIRE(lessThan(v.xy, vec2(2, 2)) == bvec2(1, 0));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);

    REQUIRE(lessThan(2, v) == bvec3(0, 0, 1));
    REQUIRE(lessThan(v, 2) == bvec3(1, 0, 0));
    REQUIRE(lessThan(2, v.xyz) == bvec3(0, 0, 1));
    REQUIRE(lessThan(v.xyz, 2) == bvec3(1, 0, 0));

    REQUIRE(lessThan(vec3(2, 2, 3), v) == bvec3(0, 0, 0));
    REQUIRE(lessThan(v, vec3(2, 2, 3)) == bvec3(1, 0, 0));
    REQUIRE(lessThan(vec3(2, 2, 3), v.xyz) == bvec3(0, 0, 0));
    REQUIRE(lessThan(v.xyz, vec3(2, 2, 3)) == bvec3(1, 0, 0));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);

    REQUIRE(lessThan(2, v) == bvec4(0, 0, 1, 1));
    REQUIRE(lessThan(v, 2) == bvec4(1, 0, 0, 0));
    REQUIRE(lessThan(2, v.xyzw) == bvec4(0, 0, 1, 1));
    REQUIRE(lessThan(v.xyzw, 2) == bvec4(1, 0, 0, 0));

    REQUIRE(lessThan(vec4(2, 2, 3, 3), v) == bvec4(0, 0, 0, 1));
    REQUIRE(lessThan(v, vec4(2, 2, 3, 3)) == bvec4(1, 0, 0, 0));
    REQUIRE(lessThan(vec4(2, 2, 3, 3), v.xyzw) == bvec4(0, 0, 0, 1));
    REQUIRE(lessThan(v.xyzw, vec4(2, 2, 3, 3)) == bvec4(1, 0, 0, 0));
  }
}

TEST_CASE("vector relational function lessThanEqual", "[vec][rel]") {

  SECTION("scalar") {
    REQUIRE(lessThanEqual(1, 2) == true);
    REQUIRE(lessThanEqual(1, 1) == true);
    REQUIRE(lessThanEqual(2, 1) == false);
    REQUIRE(lessThanEqual(1.f, 2) == true);
    REQUIRE(lessThanEqual(2.0, 1) == false);
  }

  SECTION("vec2") {
    vec2 v = vec2(1, 2);

    REQUIRE(lessThanEqual(2, v) == bvec2(0, 1));
    REQUIRE(lessThanEqual(v, 2) == bvec2(1, 1));
    REQUIRE(lessThanEqual(2, v.xy) == bvec2(0, 1));
    REQUIRE(lessThanEqual(v.xy, 2) == bvec2(1, 1));

    REQUIRE(lessThanEqual(vec2(2, 2), v) == bvec2(0, 1));
    REQUIRE(lessThanEqual(v, vec2(2, 2)) == bvec2(1, 1));
    REQUIRE(lessThanEqual(vec2(2, 2), v.xy) == bvec2(0, 1));
    REQUIRE(lessThanEqual(v.xy, vec2(2, 2)) == bvec2(1, 1));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);

    REQUIRE(lessThanEqual(2, v) == bvec3(0, 1, 1));
    REQUIRE(lessThanEqual(v, 2) == bvec3(1, 1, 0));
    REQUIRE(lessThanEqual(2, v.xyz) == bvec3(0, 1, 1));
    REQUIRE(lessThanEqual(v.xyz, 2) == bvec3(1, 1, 0));

    REQUIRE(lessThanEqual(vec3(2, 2, 3), v) == bvec3(0, 1, 1));
    REQUIRE(lessThanEqual(v, vec3(2, 2, 3)) == bvec3(1, 1, 1));
    REQUIRE(lessThanEqual(vec3(2, 2, 3), v.xyz) == bvec3(0, 1, 1));
    REQUIRE(lessThanEqual(v.xyz, vec3(2, 2, 3)) == bvec3(1, 1, 1));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);

    REQUIRE(lessThanEqual(2, v) == bvec4(0, 1, 1, 1));
    REQUIRE(lessThanEqual(v, 2) == bvec4(1, 1, 0, 0));
    REQUIRE(lessThanEqual(2, v.xyzw) == bvec4(0, 1, 1, 1));
    REQUIRE(lessThanEqual(v.xyzw, 2) == bvec4(1, 1, 0, 0));

    REQUIRE(lessThanEqual(vec4(2, 2, 3, 3), v) == bvec4(0, 1, 1, 1));
    REQUIRE(lessThanEqual(v, vec4(2, 2, 3, 3)) == bvec4(1, 1, 1, 0));
    REQUIRE(lessThanEqual(vec4(2, 2, 3, 3), v.xyzw) == bvec4(0, 1, 1, 1));
    REQUIRE(lessThanEqual(v.xyzw, vec4(2, 2, 3, 3)) == bvec4(1, 1, 1, 0));
  }
}

TEST_CASE("vector relational function greaterThan", "[vec][rel]") {

  SECTION("scalar") {
    REQUIRE(greaterThan(1, 2) == false);
    REQUIRE(greaterThan(1, 1) == false);
    REQUIRE(greaterThan(2, 1) == true);
    REQUIRE(greaterThan(1.f, 2) == false);
    REQUIRE(greaterThan(2.0, 1) == true);
  }

  SECTION("vec2") {
    vec2 v = vec2(1, 2);

    REQUIRE(greaterThan(2, v) == bvec2(1, 0));
    REQUIRE(greaterThan(v, 2) == bvec2(0, 0));
    REQUIRE(greaterThan(2, v.xy) == bvec2(1, 0));
    REQUIRE(greaterThan(v.xy, 2) == bvec2(0, 0));

    REQUIRE(greaterThan(vec2(2, 2), v) == bvec2(1, 0));
    REQUIRE(greaterThan(v, vec2(2, 2)) == bvec2(0, 0));
    REQUIRE(greaterThan(vec2(2, 2), v.xy) == bvec2(1, 0));
    REQUIRE(greaterThan(v.xy, vec2(2, 2)) == bvec2(0, 0));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);

    REQUIRE(greaterThan(2, v) == bvec3(1, 0, 0));
    REQUIRE(greaterThan(v, 2) == bvec3(0, 0, 1));
    REQUIRE(greaterThan(2, v.xyz) == bvec3(1, 0, 0));
    REQUIRE(greaterThan(v.xyz, 2) == bvec3(0, 0, 1));

    REQUIRE(greaterThan(vec3(2, 2, 3), v) == bvec3(1, 0, 0));
    REQUIRE(greaterThan(v, vec3(2, 2, 3)) == bvec3(0, 0, 0));
    REQUIRE(greaterThan(vec3(2, 2, 3), v.xyz) == bvec3(1, 0, 0));
    REQUIRE(greaterThan(v.xyz, vec3(2, 2, 3)) == bvec3(0, 0, 0));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);

    REQUIRE(greaterThan(2, v) == bvec4(1, 0, 0, 0));
    REQUIRE(greaterThan(v, 2) == bvec4(0, 0, 1, 1));
    REQUIRE(greaterThan(2, v.xyzw) == bvec4(1, 0, 0, 0));
    REQUIRE(greaterThan(v.xyzw, 2) == bvec4(0, 0, 1, 1));

    REQUIRE(greaterThan(vec4(2, 2, 3, 3), v) == bvec4(1, 0, 0, 0));
    REQUIRE(greaterThan(v, vec4(2, 2, 3, 3)) == bvec4(0, 0, 0, 1));
    REQUIRE(greaterThan(vec4(2, 2, 3, 3), v.xyzw) == bvec4(1, 0, 0, 0));
    REQUIRE(greaterThan(v.xyzw, vec4(2, 2, 3, 3)) == bvec4(0, 0, 0, 1));
  }
}

TEST_CASE("vector relational function greaterThanEqual", "[vec][rel]") {

  SECTION("scalar") {
    REQUIRE(greaterThanEqual(1, 2) == false);
    REQUIRE(greaterThanEqual(1, 1) == true);
    REQUIRE(greaterThanEqual(2, 1) == true);
    REQUIRE(greaterThanEqual(1.f, 2) == false);
    REQUIRE(greaterThanEqual(2.0, 1) == true);
  }

  SECTION("vec2") {
    vec2 v = vec2(1, 2);

    REQUIRE(greaterThanEqual(2, v) == bvec2(1, 1));
    REQUIRE(greaterThanEqual(v, 2) == bvec2(0, 1));
    REQUIRE(greaterThanEqual(2, v.xy) == bvec2(1, 1));
    REQUIRE(greaterThanEqual(v.xy, 2) == bvec2(0, 1));

    REQUIRE(greaterThanEqual(vec2(2, 2), v) == bvec2(1, 1));
    REQUIRE(greaterThanEqual(v, vec2(2, 2)) == bvec2(0, 1));
    REQUIRE(greaterThanEqual(vec2(2, 2), v.xy) == bvec2(1, 1));
    REQUIRE(greaterThanEqual(v.xy, vec2(2, 2)) == bvec2(0, 1));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);

    REQUIRE(greaterThanEqual(2, v) == bvec3(1, 1, 0));
    REQUIRE(greaterThanEqual(v, 2) == bvec3(0, 1, 1));
    REQUIRE(greaterThanEqual(2, v.xyz) == bvec3(1, 1, 0));
    REQUIRE(greaterThanEqual(v.xyz, 2) == bvec3(0, 1, 1));

    REQUIRE(greaterThanEqual(vec3(2, 2, 3), v) == bvec3(1, 1, 1));
    REQUIRE(greaterThanEqual(v, vec3(2, 2, 3)) == bvec3(0, 1, 1));
    REQUIRE(greaterThanEqual(vec3(2, 2, 3), v.xyz) == bvec3(1, 1, 1));
    REQUIRE(greaterThanEqual(v.xyz, vec3(2, 2, 3)) == bvec3(0, 1, 1));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);

    REQUIRE(greaterThanEqual(2, v) == bvec4(1, 1, 0, 0));
    REQUIRE(greaterThanEqual(v, 2) == bvec4(0, 1, 1, 1));
    REQUIRE(greaterThanEqual(2, v.xyzw) == bvec4(1, 1, 0, 0));
    REQUIRE(greaterThanEqual(v.xyzw, 2) == bvec4(0, 1, 1, 1));

    REQUIRE(greaterThanEqual(vec4(2, 2, 3, 3), v) == bvec4(1, 1, 1, 0));
    REQUIRE(greaterThanEqual(v, vec4(2, 2, 3, 3)) == bvec4(0, 1, 1, 1));
    REQUIRE(greaterThanEqual(vec4(2, 2, 3, 3), v.xyzw) == bvec4(1, 1, 1, 0));
    REQUIRE(greaterThanEqual(v.xyzw, vec4(2, 2, 3, 3)) == bvec4(0, 1, 1, 1));
  }
}

TEST_CASE("vector relational function equal", "[vec][rel]") {

  SECTION("scalar") {
    REQUIRE(equal(1, 2) == false);
    REQUIRE(equal(1, 1) == true);
    REQUIRE(equal(2, 1) == false);
    REQUIRE(equal(1.f, 2) == false);
    REQUIRE(equal(2.0, 1) == false);
  }

  SECTION("vec2") {
    vec2 v = vec2(1, 2);

    REQUIRE(equal(2, v) == bvec2(0, 1));
    REQUIRE(equal(v, 2) == bvec2(0, 1));
    REQUIRE(equal(2, v.xy) == bvec2(0, 1));
    REQUIRE(equal(v.xy, 2) == bvec2(0, 1));

    REQUIRE(equal(vec2(2, 2), v) == bvec2(0, 1));
    REQUIRE(equal(v, vec2(2, 2)) == bvec2(0, 1));
    REQUIRE(equal(vec2(2, 2), v.xy) == bvec2(0, 1));
    REQUIRE(equal(v.xy, vec2(2, 2)) == bvec2(0, 1));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);

    REQUIRE(equal(2, v) == bvec3(0, 1, 0));
    REQUIRE(equal(v, 2) == bvec3(0, 1, 0));
    REQUIRE(equal(2, v.xyz) == bvec3(0, 1, 0));
    REQUIRE(equal(v.xyz, 2) == bvec3(0, 1, 0));

    REQUIRE(equal(vec3(2, 2, 3), v) == bvec3(0, 1, 1));
    REQUIRE(equal(v, vec3(2, 2, 3)) == bvec3(0, 1, 1));
    REQUIRE(equal(vec3(2, 2, 3), v.xyz) == bvec3(0, 1, 1));
    REQUIRE(equal(v.xyz, vec3(2, 2, 3)) == bvec3(0, 1, 1));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);

    REQUIRE(equal(2, v) == bvec4(0, 1, 0, 0));
    REQUIRE(equal(v, 2) == bvec4(0, 1, 0, 0));
    REQUIRE(equal(2, v.xyzw) == bvec4(0, 1, 0, 0));
    REQUIRE(equal(v.xyzw, 2) == bvec4(0, 1, 0, 0));

    REQUIRE(equal(vec4(2, 2, 3, 3), v) == bvec4(0, 1, 1, 0));
    REQUIRE(equal(v, vec4(2, 2, 3, 3)) == bvec4(0, 1, 1, 0));
    REQUIRE(equal(vec4(2, 2, 3, 3), v.xyzw) == bvec4(0, 1, 1, 0));
    REQUIRE(equal(v.xyzw, vec4(2, 2, 3, 3)) == bvec4(0, 1, 1, 0));
  }
}

TEST_CASE("vector relational function notEqual", "[vec][rel]") {

  SECTION("scalar") {
    REQUIRE(notEqual(1, 2) == true);
    REQUIRE(notEqual(1, 1) == false);
    REQUIRE(notEqual(2, 1) == true);
    REQUIRE(notEqual(1.f, 2) == true);
    REQUIRE(notEqual(2.0, 1) == true);
  }

  SECTION("vec2") {
    vec2 v = vec2(1, 2);

    REQUIRE(notEqual(2, v) == bvec2(1, 0));
    REQUIRE(notEqual(v, 2) == bvec2(1, 0));
    REQUIRE(notEqual(2, v.xy) == bvec2(1, 0));
    REQUIRE(notEqual(v.xy, 2) == bvec2(1, 0));

    REQUIRE(notEqual(vec2(2, 2), v) == bvec2(1, 0));
    REQUIRE(notEqual(v, vec2(2, 2)) == bvec2(1, 0));
    REQUIRE(notEqual(vec2(2, 2), v.xy) == bvec2(1, 0));
    REQUIRE(notEqual(v.xy, vec2(2, 2)) == bvec2(1, 0));
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);

    REQUIRE(notEqual(2, v) == bvec3(1, 0, 1));
    REQUIRE(notEqual(v, 2) == bvec3(1, 0, 1));
    REQUIRE(notEqual(2, v.xyz) == bvec3(1, 0, 1));
    REQUIRE(notEqual(v.xyz, 2) == bvec3(1, 0, 1));

    REQUIRE(notEqual(vec3(2, 2, 3), v) == bvec3(1, 0, 0));
    REQUIRE(notEqual(v, vec3(2, 2, 3)) == bvec3(1, 0, 0));
    REQUIRE(notEqual(vec3(2, 2, 3), v.xyz) == bvec3(1, 0, 0));
    REQUIRE(notEqual(v.xyz, vec3(2, 2, 3)) == bvec3(1, 0, 0));
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);

    REQUIRE(notEqual(2, v) == bvec4(1, 0, 1, 1));
    REQUIRE(notEqual(v, 2) == bvec4(1, 0, 1, 1));
    REQUIRE(notEqual(2, v.xyzw) == bvec4(1, 0, 1, 1));
    REQUIRE(notEqual(v.xyzw, 2) == bvec4(1, 0, 1, 1));

    REQUIRE(notEqual(vec4(2, 2, 3, 3), v) == bvec4(1, 0, 0, 1));
    REQUIRE(notEqual(v, vec4(2, 2, 3, 3)) == bvec4(1, 0, 0, 1));
    REQUIRE(notEqual(vec4(2, 2, 3, 3), v.xyzw) == bvec4(1, 0, 0, 1));
    REQUIRE(notEqual(v.xyzw, vec4(2, 2, 3, 3)) == bvec4(1, 0, 0, 1));
  }
}

TEST_CASE("vector relational function all", "[vec][rel]") {

  SECTION("scalar") {
    REQUIRE(all(true) == true);
    REQUIRE(all(false) == false);
  }

  SECTION("vec2") {
    REQUIRE(all(bvec2(0, 0)) == false);
    REQUIRE(all(bvec2(0, 1)) == false);
    REQUIRE(all(bvec2(1, 1)) == true);

  }

  SECTION("vec3") {
    REQUIRE(all(bvec3(0, 0, 0)) == false);
    REQUIRE(all(bvec3(0, 1, 0)) == false);
    REQUIRE(all(bvec3(1, 1, 1)) == true);
  }

  SECTION("vec4") {
    REQUIRE(all(bvec4(0, 0, 0, 0)) == false);
    REQUIRE(all(bvec4(0, 1, 0, 1)) == false);
    REQUIRE(all(bvec4(1, 1, 1, 1)) == true);
  }
}

TEST_CASE("vector relational function any", "[vec][rel]") {

  SECTION("scalar") {
    REQUIRE(any(true) == true);
    REQUIRE(any(false) == false);
  }

  SECTION("vec2") {
    REQUIRE(any(bvec2(0, 0)) == false);
    REQUIRE(any(bvec2(0, 1)) == true);
    REQUIRE(any(bvec2(1, 1)) == true);

  }

  SECTION("vec3") {
    REQUIRE(any(bvec3(0, 0, 0)) == false);
    REQUIRE(any(bvec3(0, 1, 0)) == true);
    REQUIRE(any(bvec3(1, 1, 1)) == true);
  }

  SECTION("vec4") {
    REQUIRE(any(bvec4(0, 0, 0, 0)) == false);
    REQUIRE(any(bvec4(0, 1, 0, 1)) == true);
    REQUIRE(any(bvec4(1, 1, 1, 1)) == true);
  }
}

TEST_CASE("vector relational function not", "[vec][rel]") {

  SECTION("scalar") {
    REQUIRE(not(true) == false);
    REQUIRE(not(false) == true);
  }

  SECTION("vec2") {
    REQUIRE(not(bvec2(0, 0)) == bvec2(1, 1));
    REQUIRE(not(bvec2(0, 1)) == bvec2(1, 0));
    REQUIRE(not(bvec2(1, 1)) == bvec2(0, 0));

  }

  SECTION("vec3") {
    REQUIRE(not(bvec3(0, 0, 0)) == bvec3(1, 1, 1));
    REQUIRE(not(bvec3(0, 1, 0)) == bvec3(1, 0, 1));
    REQUIRE(not(bvec3(1, 1, 1)) == bvec3(0, 0, 0));
  }

  SECTION("vec4") {
    REQUIRE(not(bvec4(0, 0, 0, 0)) == bvec4(1, 1, 1, 1));
    REQUIRE(not(bvec4(0, 1, 0, 1)) == bvec4(1, 0, 1, 0));
    REQUIRE(not(bvec4(1, 1, 1, 1)) == bvec4(0, 0, 0, 0));
  }
}
