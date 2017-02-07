#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("vector constructors", "[vec]") {

  vec2 v2 = vec2(1, 2);
  vec3 v3 = vec3(1, 2, 3);
  vec4 v4 = vec4(1, 2, 3, 4);

  SECTION("initialization") {
    vec4 v;
    vec4 u(0);
    vec4 t{0};
    vec4 s = vec4();
    vec4 r = vec4(0);

    vec4 q(1, 2, 3, 4);
    vec4 p{1, 2, 3, 4};
    vec4 o = {1, 2, 3, 4};
    vec4 n = vec4(1, 2, 3, 4);

    REQUIRE(v == vec4(0, 0, 0, 0));
    REQUIRE(u == vec4(0, 0, 0, 0));
    REQUIRE(t == vec4(0, 0, 0, 0));
    REQUIRE(s == vec4(0, 0, 0, 0));
    REQUIRE(r == vec4(0, 0, 0, 0));

    REQUIRE(q == vec4(1, 2, 3, 4));
    REQUIRE(p == vec4(1, 2, 3, 4));
    REQUIRE(o == vec4(1, 2, 3, 4));
    REQUIRE(n == vec4(1, 2, 3, 4));
  }

  SECTION("vec2") {
    REQUIRE(vec2() == vec2(0, 0));

    REQUIRE(vec2(0) == vec2(0, 0));
    REQUIRE(vec2(1) == vec2(1, 1));
    REQUIRE(vec2(2) == vec2(2, 2));

    REQUIRE(vec2(v2) == vec2(1, 2));
    REQUIRE(vec2(v3) == vec2(1, 2));
    REQUIRE(vec2(v4) == vec2(1, 2));

    REQUIRE(vec2(v2.x) == vec2(1, 1));
    REQUIRE(vec2(v2.xx) == vec2(1, 1));

    REQUIRE(vec2(v3.x) == vec2(1, 1));
    REQUIRE(vec2(v3.xy) == vec2(1, 2));
    REQUIRE(vec2(v3.xyz) == vec2(1, 2));

    REQUIRE(vec2(v4.x) == vec2(1, 1));
    REQUIRE(vec2(v4.xy) == vec2(1, 2));
    REQUIRE(vec2(v4.xyz) == vec2(1, 2));
    REQUIRE(vec2(v4.xyzw) == vec2(1, 2));
  }

  SECTION("vec3") {
    REQUIRE(vec3() == vec3(0, 0, 0));

    REQUIRE(vec3(0) == vec3(0, 0, 0));
    REQUIRE(vec3(1) == vec3(1, 1, 1));
    REQUIRE(vec3(2) == vec3(2, 2, 2));

    REQUIRE(vec3(0, v2) == vec3(0, 1, 2));
    REQUIRE(vec3(v2, 3) == vec3(1, 2, 3));
    REQUIRE(vec3(v3) == vec3(1, 2, 3));
    REQUIRE(vec3(v4) == vec3(1, 2, 3));

    REQUIRE(vec3(v2.x) == vec3(1, 1, 1));
    REQUIRE(vec3(v2.xxx) == vec3(1, 1, 1));
    REQUIRE(vec3(v2.xyy) == vec3(1, 2, 2));

    REQUIRE(vec3(v3.x) == vec3(1, 1, 1));
    REQUIRE(vec3(v3.xyz) == vec3(1, 2, 3));
    REQUIRE(vec3(v3.zyx) == vec3(3, 2, 1));

    REQUIRE(vec3(v4.x) == vec3(1, 1, 1));
    REQUIRE(vec3(v4.xyz) == vec3(1, 2, 3));
    REQUIRE(vec3(v4.xyzw) == vec3(1, 2, 3));
  }

  SECTION("vec4") {
    REQUIRE(vec4() == vec4(0, 0, 0, 0));

    REQUIRE(vec4(0) == vec4(0, 0, 0, 0));
    REQUIRE(vec4(1) == vec4(1, 1, 1, 1));
    REQUIRE(vec4(2) == vec4(2, 2, 2, 2));

    REQUIRE(vec4(-1, 0, v2) == vec4(-1, 0, 1, 2));
    REQUIRE(vec4(0, v2, 3) == vec4(0, 1, 2, 3));
    REQUIRE(vec4(v2, 3, 4) == vec4(1, 2, 3, 4));
    REQUIRE(vec4(0, v3) == vec4(0, 1, 2, 3));
    REQUIRE(vec4(v3, 4) == vec4(1, 2, 3, 4));
    REQUIRE(vec4(v4) == vec4(1, 2, 3, 4));

    REQUIRE(vec4(v2.x) == vec4(1, 1, 1, 1));
    REQUIRE(vec4(v2.xxxx) == vec4(1, 1, 1, 1));
    REQUIRE(vec4(v2.xxyy) == vec4(1, 1, 2, 2));

    REQUIRE(vec4(v3.x) == vec4(1, 1, 1, 1));
    REQUIRE(vec4(v3.xy, v3.yx) == vec4(1, 2, 2, 1));
    REQUIRE(vec4(v3.zyx, v3.x) == vec4(3, 2, 1, 1));

    REQUIRE(vec4(v4.x) == vec4(1, 1, 1, 1));
    REQUIRE(vec4(v4.xyzw) == vec4(1, 2, 3, 4));
    REQUIRE(vec4(v4.wzyx) == vec4(4, 3, 2, 1));
  }

  SECTION("vec<N>") {
    mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    REQUIRE(vec<2>(m) == vec2(1, 2));
    REQUIRE(vec<3>(1) == vec3(1, 1, 1));
    REQUIRE(vec<4>(m) == vec4(1, 2, 3, 4));
    REQUIRE(vec<5>(v2, 3, v2.yx) == vec<5>(1, 2, 3, 2, 1));
    REQUIRE(vec<6>(m) == vec<6>(1, 2, 3, 4, 5, 6));
    REQUIRE(vec<7>(v3, v4) == vec<7>(1, 2, 3, 1, 2, 3, 4));
    REQUIRE(vec<8>(m) == vec<8>(1, 2, 3, 4, 5, 6, 7, 8));
  }
}

TEST_CASE("vector index", "[vec]") {

  vec2 v2 = vec2(1, 2);
  vec3 v3 = vec3(3, 4, 5);
  vec4 v4 = vec4(6, 7, 8, 9);

  SECTION("vec2") {
    REQUIRE(v2[0] == 1);
    REQUIRE(v2[1] == 2);

    v2[0] = 0;
    v2[1] = 1;
    REQUIRE(v2 == vec2(0, 1));
  }

  SECTION("vec3") {
    REQUIRE(v3[0] == 3);
    REQUIRE(v3[1] == 4);
    REQUIRE(v3[2] == 5);

    v3[0] = 0;
    v3[1] = 1;
    v3[2] = 2;
    REQUIRE(v3 == vec3(0, 1, 2));
  }

  SECTION("vec4") {
    REQUIRE(v4[0] == 6);
    REQUIRE(v4[1] == 7);
    REQUIRE(v4[2] == 8);
    REQUIRE(v4[3] == 9);

    v4[0] = 9;
    v4[1] = 8;
    v4[2] = 7;
    v4[3] = 6;
    REQUIRE(v4 == vec4(9, 8, 7, 6));
  }
}

TEST_CASE("vector cast", "[vec]") {

  vec2 v2 = vec2(-1.5f, 0.5f);
  vec3 v3 = vec3(-1.5f, 0.5f, 1.5f);

  SECTION("array cast") {
    float* xs = (float*)v2;
    float* ys = v3;

    REQUIRE(xs[0] == -1.5);
    REQUIRE(xs[1] == 0.5);

    REQUIRE(ys[0] == -1.5);
    REQUIRE(ys[1] == 0.5);
    REQUIRE(ys[2] == 1.5);
  }

  SECTION("vec -> ivec") {
    ivec2 i2 = (ivec2)v2;
    ivec3 i3 = ivec3(v3);

    REQUIRE(i2 == ivec2(-1, 0));
    REQUIRE(i3 == ivec3(-1, 0, 1));
  }

  SECTION("vec -> uvec") {
    uvec2 u2 = (uvec2)v2;
    uvec3 u3 = uvec3(v3);

    // -1 should roll over to UINT_MAX
    REQUIRE(u2 == uvec2(-1, 0));
    REQUIRE(u3 == uvec3(-1, 0, 1));
  }

  SECTION("vec -> dvec") {
    dvec2 d2 = (dvec2)v2;
    dvec3 d3 = dvec3(v3);

    REQUIRE(d2 == dvec2(-1.5, 0.5));
    REQUIRE(d3 == dvec3(-1.5, 0.5, 1.5));
  }
}

TEST_CASE("vector sizeof", "[vec]") {
  REQUIRE(sizeof(tvec<float, 2>) == sizeof(float[2]));
  REQUIRE(sizeof(tvec<float, 3>) == sizeof(float[3]));
  REQUIRE(sizeof(tvec<float, 4>) == sizeof(float[4]));
  REQUIRE(sizeof(tvec<float, 5>) == sizeof(float[5]));
  REQUIRE(sizeof(tvec<float, 6>) == sizeof(float[6]));
  REQUIRE(sizeof(tvec<float, 7>) == sizeof(float[7]));
  REQUIRE(sizeof(tvec<float, 8>) == sizeof(float[8]));
}

/*
  // Should move the swizzle stuff to swizzle folder
  // also you should add a case for validating ivec != vec

  auto swiz_elems = UnitTest("vector swizzleElems", +[] {
    ivec<9> v = ivec<9>(0, 1, 2, 10, 11, 12, 20, 21, 22);

    ivec3 u = v.swizzleElems<3, 4, 5>() += 100;
    if (u != ivec3(110, 111, 112)) return false;
    if (v != ivec<9>(0, 1, 2, 110, 111, 112, 20, 21, 22)) return false;

    return true;
  });
  auto swiz_range1 = UnitTest("vector swizzleRange positive", +[] {
    ivec<9> v = ivec<9>(0, 1, 2, 10, 11, 12, 20, 21, 22);

    auto& u = v.swizzleRange<3, 5>();
    if (u != ivec3(10, 11, 12)) return false;

    u += 100;
    if (u != ivec3(110, 111, 112)) return false;

    if (v != ivec<9>(0, 1, 2, 110, 111, 112, 20, 21, 22)) return false;

    return true;
  });
  auto swiz_range2 = UnitTest("vector swizzleRange negative", +[] {
    ivec<9> v = ivec<9>(0, 1, 2, 10, 11, 12, 20, 21, 22);

    auto& u = v.swizzleRange<5, 3>();
    if (u != ivec3(12, 11, 10)) return false;

    u += 100;
    if (u != ivec3(112, 111, 110)) return false;

    if (v != ivec<9>(0, 1, 2, 110, 111, 112, 20, 21, 22)) return false;

    return true;
  });
}
*/
