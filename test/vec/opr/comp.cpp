#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("vector comparison operator <", "[vec][comp]") {

  SECTION("vec2") {
    vec2 v = vec2(1, 2);
    vec2 u = vec2(2, 3);

    REQUIRE(0 < v);
    REQUIRE(1 < u);
    REQUIRE(v < 3);
    REQUIRE(u < 4);
    REQUIRE(v < u);
    REQUIRE(v.xy < u.xy);

    REQUIRE_FALSE(1 < v);
    REQUIRE_FALSE(2 < v);
    REQUIRE_FALSE(v < 2);
    REQUIRE_FALSE(u < 3);
    REQUIRE_FALSE(u.xy < v.xy);
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(2, 3, 4);

    REQUIRE(0 < v);
    REQUIRE(1 < u);
    REQUIRE(v < 4);
    REQUIRE(u < 5);
    REQUIRE(v < u);
    REQUIRE(v.xyz < u.xyz);

    REQUIRE_FALSE(1 < v);
    REQUIRE_FALSE(2 < v);
    REQUIRE_FALSE(v < 3);
    REQUIRE_FALSE(u < 4);
    REQUIRE_FALSE(u < v);
    REQUIRE_FALSE(u.xyz < v.xyz);
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);
    vec4 u = vec4(2, 3, 4, 5);

    REQUIRE(0 < v);
    REQUIRE(1 < u);
    REQUIRE(v < 5);
    REQUIRE(u < 6);
    REQUIRE(v < u);
    REQUIRE(v.xyz < u.xyz);

    REQUIRE_FALSE(1 < v);
    REQUIRE_FALSE(2 < v);
    REQUIRE_FALSE(v < 4);
    REQUIRE_FALSE(u < 5);
    REQUIRE_FALSE(u < v);
    REQUIRE_FALSE(u.xyz < v.xyz);
  }
}

TEST_CASE("vector comparison operator <=", "[vec][comp]") {

  SECTION("vec2") {
    vec2 v = vec2(1, 2);
    vec2 u = vec2(2, 3);

    REQUIRE(1 <= v);
    REQUIRE(2 <= u);
    REQUIRE(v <= 2);
    REQUIRE(u <= 3);
    REQUIRE(v <= u);
    REQUIRE(v.xy <= u.xy);

    REQUIRE_FALSE(2 <= v);
    REQUIRE_FALSE(3 <= v);
    REQUIRE_FALSE(v <= 1);
    REQUIRE_FALSE(u <= 2);
    REQUIRE_FALSE(u <= v);
    REQUIRE_FALSE(u.xy <= v.xy);
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(2, 3, 3);

    REQUIRE(1 <= v);
    REQUIRE(2 <= u);
    REQUIRE(v <= 3);
    REQUIRE(u <= 3);
    REQUIRE(v <= u);
    REQUIRE(v.xyz <= u.xyz);

    REQUIRE_FALSE(2 <= v);
    REQUIRE_FALSE(3 <= v);
    REQUIRE_FALSE(v <= 2);
    REQUIRE_FALSE(u <= 2);
    REQUIRE_FALSE(u <= v);
    REQUIRE_FALSE(u.xyz <= v.xyz);
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 2, 3, 4);
    vec4 u = vec4(2, 3, 3, 4);

    REQUIRE(1 <= v);
    REQUIRE(2 <= u);
    REQUIRE(v <= 4);
    REQUIRE(u <= 4);
    REQUIRE(v <= u);
    REQUIRE(v.xyzw <= u.xyzw);

    REQUIRE_FALSE(2 <= v);
    REQUIRE_FALSE(3 <= v);
    REQUIRE_FALSE(v <= 3);
    REQUIRE_FALSE(u <= 3);
    REQUIRE_FALSE(u <= v);
    REQUIRE_FALSE(u.xyzw <= v.xyzw);
  }
}

TEST_CASE("vector comparison operator >=", "[vec][comp]") {

  SECTION("vec2") {
    vec2 v = vec2(2, 3);
    vec2 u = vec2(1, 2);

    REQUIRE(3 >= v);
    REQUIRE(2 >= u);
    REQUIRE(v >= 2);
    REQUIRE(u >= 1);
    REQUIRE(v >= u);
    REQUIRE(v.xy >= u.xy);

    REQUIRE_FALSE(2 >= v);
    REQUIRE_FALSE(1 >= v);
    REQUIRE_FALSE(v >= 3);
    REQUIRE_FALSE(u >= 2);
    REQUIRE_FALSE(u >= v);
    REQUIRE_FALSE(u.xy >= v.xy);
  }

  SECTION("vec3") {
    vec3 v = vec3(2, 3, 3);
    vec3 u = vec3(1, 2, 3);

    REQUIRE(3 >= v);
    REQUIRE(3 >= u);
    REQUIRE(v >= 2);
    REQUIRE(u >= 1);
    REQUIRE(v >= u);

    REQUIRE_FALSE(2 >= v);
    REQUIRE_FALSE(2 >= v);
    REQUIRE_FALSE(v >= 3);
    REQUIRE_FALSE(u >= 2);
    REQUIRE_FALSE(u >= v);
  }

  SECTION("vec4") {
    vec4 v = vec4(2, 3, 3, 4);
    vec4 u = vec4(1, 2, 3, 4);

    REQUIRE(4 >= v);
    REQUIRE(4 >= u);
    REQUIRE(v >= 2);
    REQUIRE(u >= 1);
    REQUIRE(v >= u);

    REQUIRE_FALSE(3 >= v);
    REQUIRE_FALSE(3 >= v);
    REQUIRE_FALSE(v >= 3);
    REQUIRE_FALSE(u >= 3);
    REQUIRE_FALSE(u >= v);
  }
}

TEST_CASE("vector comparison operator >", "[vec][comp]") {

  SECTION("vec2") {
    vec2 v = vec2(2, 3);
    vec2 u = vec2(1, 2);

    REQUIRE(4 > v);
    REQUIRE(3 > u);
    REQUIRE(v > 1);
    REQUIRE(u > 0);
    REQUIRE(v > u);
    REQUIRE(v.xy > u.xy);

    REQUIRE_FALSE(3 > v);
    REQUIRE_FALSE(2 > v);
    REQUIRE_FALSE(v > 2);
    REQUIRE_FALSE(u > 1);
    REQUIRE_FALSE(u > v);
    REQUIRE_FALSE(u.xy > v.xy);
  }

  SECTION("vec3") {
    vec3 v = vec3(2, 3, 4);
    vec3 u = vec3(1, 2, 3);

    REQUIRE(5 > v);
    REQUIRE(4 > u);
    REQUIRE(v > 1);
    REQUIRE(u > 0);
    REQUIRE(v > u);

    REQUIRE_FALSE(4 > v);
    REQUIRE_FALSE(3 > v);
    REQUIRE_FALSE(v > 2);
    REQUIRE_FALSE(u > 1);
    REQUIRE_FALSE(u > v);
  }

  SECTION("vec4") {
    vec4 v = vec4(2, 3, 4, 5);
    vec4 u = vec4(1, 2, 3, 4);

    REQUIRE(6 > v);
    REQUIRE(5 > u);
    REQUIRE(v > 1);
    REQUIRE(u > 0);
    REQUIRE(v > u);

    REQUIRE_FALSE(5 > v);
    REQUIRE_FALSE(4 > v);
    REQUIRE_FALSE(v > 2);
    REQUIRE_FALSE(u > 1);
    REQUIRE_FALSE(u > v);
  }
}

TEST_CASE("vector comparison operator ==", "[vec][comp]") {

  SECTION("vec2") {
    vec2 v = vec2(1, 1);
    vec2 u = vec2(1, 2);
    vec2 t = vec2(1, 2);

    REQUIRE(1 == v);
    REQUIRE(v == 1);
    REQUIRE(v == v);
    REQUIRE(u == t);
    REQUIRE(t == u);
    REQUIRE(u.xx == 1);
    REQUIRE(v.xy == u.xx);
    REQUIRE(u.xy == t.xy);

    REQUIRE_FALSE(2 == v);
    REQUIRE_FALSE(v == 2);
    REQUIRE_FALSE(v == u);
    REQUIRE_FALSE(u == 1);
    REQUIRE_FALSE(u.yy == 1);
    REQUIRE_FALSE(v.xy == u.xy);
    REQUIRE_FALSE(u.xy == u.yx);
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 1, 1);
    vec3 u = vec3(1, 2, 3);
    vec3 t = vec3(1, 2, 3);

    REQUIRE(1 == v);
    REQUIRE(v == 1);
    REQUIRE(v == v);
    REQUIRE(u == t);
    REQUIRE(t == u);
    REQUIRE(u.xxx == 1);
    REQUIRE(v.xyz == u.xxx);
    REQUIRE(u.xyz == t.xyz);

    REQUIRE_FALSE(2 == v);
    REQUIRE_FALSE(v == 2);
    REQUIRE_FALSE(v == u);
    REQUIRE_FALSE(u == 1);
    REQUIRE_FALSE(u.yyy == 1);
    REQUIRE_FALSE(v.xyz == u.xyz);
    REQUIRE_FALSE(u.xyz == u.zyx);
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 1, 1, 1);
    vec4 u = vec4(1, 2, 3, 4);
    vec4 t = vec4(1, 2, 3, 4);

    REQUIRE(1 == v);
    REQUIRE(v == 1);
    REQUIRE(v == v);
    REQUIRE(u == t);
    REQUIRE(t == u);
    REQUIRE(u.xxxx == 1);
    REQUIRE(v.xyzw == u.xxxx);
    REQUIRE(u.xyzw == t.xyzw);

    REQUIRE_FALSE(2 == v);
    REQUIRE_FALSE(v == 2);
    REQUIRE_FALSE(v == u);
    REQUIRE_FALSE(u == 1);
    REQUIRE_FALSE(u.yyyy == 1);
    REQUIRE_FALSE(v.xyzw == u.xyzw);
    REQUIRE_FALSE(u.xyzw == u.wzyx);
  }

  SECTION("vec types") {
    bvec4 b = bvec4(1, 1, 1, 1);
    uvec4 u = uvec4(1, 1, 1, 1);
    ivec4 i = ivec4(1, 1, 1, 1);
    vec4  f =  vec4(1, 1, 1, 1);
    dvec4 d = dvec4(1, 1, 1, 1);

    REQUIRE(b == b);
    REQUIRE(u == u);
    REQUIRE(i == i);
    REQUIRE(f == f);
    REQUIRE(d == d);

    REQUIRE(b == 1);
    REQUIRE(u == 1);
    REQUIRE(i == 1);
    REQUIRE(f == 1);
    REQUIRE(d == 1);
  }
}

TEST_CASE("vector comparison operator !=", "[vec][comp]") {

  SECTION("vec2") {
    vec2 v = vec2(1, 1);
    vec2 u = vec2(1, 2);
    vec2 t = vec2(1, 2);

    REQUIRE(2 != v);
    REQUIRE(v != 2);
    REQUIRE(v != u);
    REQUIRE(u != 1);
    REQUIRE(u.yy != 1);
    REQUIRE(v.xy != u.xy);
    REQUIRE(u.xy != u.yx);

    REQUIRE_FALSE(1 != v);
    REQUIRE_FALSE(v != 1);
    REQUIRE_FALSE(v != v);
    REQUIRE_FALSE(u != t);
    REQUIRE_FALSE(t != u);
    REQUIRE_FALSE(u.xx != 1);
    REQUIRE_FALSE(v.xy != u.xx);
    REQUIRE_FALSE(u.xy != t.xy);
  }

  SECTION("vec3") {
    vec3 v = vec3(1, 1, 1);
    vec3 u = vec3(1, 2, 3);
    vec3 t = vec3(1, 2, 3);

    REQUIRE(2 != v);
    REQUIRE(v != 2);
    REQUIRE(v != u);
    REQUIRE(u != 1);
    REQUIRE(u.yyy != 1);
    REQUIRE(v.xyz != u.xyz);
    REQUIRE(u.xyz != u.zyx);

    REQUIRE_FALSE(1 != v);
    REQUIRE_FALSE(v != 1);
    REQUIRE_FALSE(v != v);
    REQUIRE_FALSE(u != t);
    REQUIRE_FALSE(t != u);
    REQUIRE_FALSE(u.xxx != 1);
    REQUIRE_FALSE(v.xyz != u.xxx);
    REQUIRE_FALSE(u.xyz != t.xyz);
  }

  SECTION("vec4") {
    vec4 v = vec4(1, 1, 1, 1);
    vec4 u = vec4(1, 2, 3, 4);
    vec4 t = vec4(1, 2, 3, 4);

    REQUIRE(2 != v);
    REQUIRE(v != 2);
    REQUIRE(v != u);
    REQUIRE(u != 1);
    REQUIRE(u.yyyy != 1);
    REQUIRE(v.xyzw != u.xyzw);
    REQUIRE(u.xyzw != u.wzyx);

    REQUIRE_FALSE(1 != v);
    REQUIRE_FALSE(v != 1);
    REQUIRE_FALSE(v != v);
    REQUIRE_FALSE(u != t);
    REQUIRE_FALSE(t != u);
    REQUIRE_FALSE(u.xxxx != 1);
    REQUIRE_FALSE(v.xyzw != u.xxxx);
    REQUIRE_FALSE(u.xyzw != t.xyzw);
  }

  SECTION("vec types") {
    bvec4 b = bvec4(1, 1, 1, 1);
    uvec4 u = uvec4(1, 1, 1, 1);
    ivec4 i = ivec4(1, 1, 1, 1);
    vec4  f =  vec4(1, 1, 1, 1);
    dvec4 d = dvec4(1, 1, 1, 1);

    REQUIRE_FALSE(b != b);
    REQUIRE_FALSE(u != u);
    REQUIRE_FALSE(i != i);
    REQUIRE_FALSE(f != f);
    REQUIRE_FALSE(d != d);

    REQUIRE_FALSE(b != 1);
    REQUIRE_FALSE(u != 1);
    REQUIRE_FALSE(i != 1);
    REQUIRE_FALSE(f != 1);
    REQUIRE_FALSE(d != 1);
  }
}
