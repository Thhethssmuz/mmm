#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;


TEST_CASE("matrix constructors", "[mat]") {

  SECTION("initialization") {
    mat2 m;
    mat2 n(0);
    mat2 o{0};
    mat2 p = mat2();
    mat2 q = mat2(0);

    mat2 r(1, 2, 3, 4);
    mat2 s{1, 2, 3, 4};
    // mat2 t = {1, 2, 3, 4};
    mat2 u = mat2(1, 2, 3, 4);

    REQUIRE(m == mat2(0, 0, 0, 0));
    REQUIRE(n == mat2(0, 0, 0, 0));
    REQUIRE(o == mat2(0, 0, 0, 0));
    REQUIRE(p == mat2(0, 0, 0, 0));
    REQUIRE(q == mat2(0, 0, 0, 0));

    REQUIRE(r == mat2(1, 2, 3, 4));
    REQUIRE(s == mat2(1, 2, 3, 4));
    // REQUIRE(t == mat2(1, 2, 3, 4));
    REQUIRE(u == mat2(1, 2, 3, 4));
  }

  SECTION("mat2") {
    vec2 v2 = vec2(1, 2);
    vec3 v3 = vec3(1, 2, 3);
    vec4 v4 = vec4(1, 2, 3, 4);

    REQUIRE(mat2() == mat2(0, 0, 0, 0));

    REQUIRE(mat2(0) == mat2(0, 0, 0, 0));
    REQUIRE(mat2(1) == mat2(1, 1, 1, 1));
    REQUIRE(mat2(2) == mat2(2, 2, 2, 2));

    REQUIRE(mat2(v2, v2) == mat2(1, 2, 1, 2));
    REQUIRE(mat2(v3, 0) == mat2(1, 2, 3, 0));
    REQUIRE(mat2(0, v3) == mat2(0, 1, 2, 3));
    REQUIRE(mat2(v4) == mat2(1, 2, 3, 4));

    REQUIRE(mat2(v2.x) == mat2(1, 1, 1, 1));
    REQUIRE(mat2(v2.xx, v2.yy) == mat2(1, 1, 2, 2));
    REQUIRE(mat2(v4.xyzw) == mat2(1, 2, 3, 4));
  }
}

TEST_CASE("matrix index", "[mat]") {

  mat2 m2 = mat2(1, 2, 3, 4);
  mat3 m3 = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  mat4 m4 = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

  SECTION("mat2") {
    REQUIRE(m2[0] == vec2(1, 2));
    REQUIRE(m2[1] == vec2(3, 4));

    REQUIRE(m2[0][1] == 2);
    REQUIRE(m2[1][0] == 3);

    m2[0][1] = 0;
    m2[1][0] = 1;

    REQUIRE(m2 == mat2(1, 0, 1, 4));
  }

  SECTION("mat3") {
    REQUIRE(m3[0] == vec3(1, 2, 3));
    REQUIRE(m3[1] == vec3(4, 5, 6));
    REQUIRE(m3[2] == vec3(7, 8, 9));

    REQUIRE(m3[0][2] == 3);
    REQUIRE(m3[1][1] == 5);
    REQUIRE(m3[2][0] == 7);

    m3[0][2] = 0;
    m3[1][1] = 1;
    m3[2][0] = 2;

    REQUIRE(m3 == mat3(1, 2, 0, 4, 1, 6, 2, 8, 9));
  }

  SECTION("mat4") {
    REQUIRE(m4[0] == vec4(1, 2, 3, 4));
    REQUIRE(m4[1] == vec4(5, 6, 7, 8));
    REQUIRE(m4[2] == vec4(9, 10, 11, 12));
    REQUIRE(m4[3] == vec4(13, 14, 15, 16));

    REQUIRE(m4[0][3] == 4);
    REQUIRE(m4[1][2] == 7);
    REQUIRE(m4[2][1] == 10);
    REQUIRE(m4[3][0] == 13);

    m4[0][3] = 0;
    m4[1][2] = 1;
    m4[2][1] = 2;
    m4[3][0] = 3;

    REQUIRE(m4 == mat4(1, 2, 3, 0, 5, 6, 1, 8, 9, 2, 11, 12, 3, 14, 15, 16));
  }
}

TEST_CASE("matrix cast", "[mat]") {

  mat2 m2 = mat2(1, 2, 3, 4);
  mat3 m3 = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

  SECTION("array cast") {
    float* xs = (float*)m2;
    float* ys = m3;

    REQUIRE(xs[0] == 1);
    REQUIRE(xs[1] == 2);
    REQUIRE(xs[2] == 3);
    REQUIRE(xs[3] == 4);

    REQUIRE(ys[0] == 1);
    REQUIRE(ys[1] == 2);
    REQUIRE(ys[2] == 3);
    REQUIRE(ys[3] == 4);
    REQUIRE(ys[4] == 5);
    REQUIRE(ys[5] == 6);
    REQUIRE(ys[6] == 7);
    REQUIRE(ys[7] == 8);
    REQUIRE(ys[8] == 9);
  }

  // SECTION("mat -> dmat") {
  //   dmat2 d2 = (dmat2)m2;
  //   dmat3 d3 = dmat3(m3);
  //   REQUIRE(d2 == dmat2(1, 2, 3, 4));
  //   REQUIRE(d3 == dmat3(1, 2, 3, 4, 5, 6, 7, 8, 9));
  // }
}

TEST_CASE("matrix sizeof", "[mat]") {
  REQUIRE(sizeof(tmat<float, 2, 2>) == sizeof(float[2*2]));
  REQUIRE(sizeof(tmat<float, 2, 3>) == sizeof(float[2*3]));
  REQUIRE(sizeof(tmat<float, 2, 4>) == sizeof(float[2*4]));
  REQUIRE(sizeof(tmat<float, 3, 2>) == sizeof(float[3*2]));
  REQUIRE(sizeof(tmat<float, 3, 3>) == sizeof(float[3*3]));
  REQUIRE(sizeof(tmat<float, 3, 4>) == sizeof(float[3*4]));
  REQUIRE(sizeof(tmat<float, 4, 2>) == sizeof(float[4*2]));
  REQUIRE(sizeof(tmat<float, 4, 3>) == sizeof(float[4*3]));
  REQUIRE(sizeof(tmat<float, 4, 4>) == sizeof(float[4*4]));

  REQUIRE(sizeof(tmat<float, 5, 5>) == sizeof(float[5*5]));
  REQUIRE(sizeof(tmat<float, 6, 6>) == sizeof(float[6*6]));
  REQUIRE(sizeof(tmat<float, 7, 7>) == sizeof(float[7*7]));
  REQUIRE(sizeof(tmat<float, 8, 8>) == sizeof(float[8*8]));
}
