#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("matrix function matrixCompMult", "[mat]") {

  SECTION("mat2") {
    mat2 m = mat2(1, 2, 3, 4);
    mat2 n = mat2(2, 3, 4, 5);

    REQUIRE(matrixCompMult(m, n) == mat2(2, 6, 12, 20));
    REQUIRE(matrixCompMult(n, m) == mat2(2, 6, 12, 20));
  }

  SECTION("mat3") {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 n = mat3(2, 3, 4, 5, 6, 7, 8, 9, 10);

    REQUIRE(matrixCompMult(m, n) == mat3(2, 6, 12, 20, 30, 42, 56, 72, 90));
    REQUIRE(matrixCompMult(n, m) == mat3(2, 6, 12, 20, 30, 42, 56, 72, 90));
  }
}

TEST_CASE("matrix function outerProduct", "[mat]") {

  SECTION("scalar vector") {
    vec2 v = vec2(1, 2);
    vec3 u = vec3(1, 2, 3);
    vec4 t = vec4(1, 2, 3, 4);

    REQUIRE(outerProduct(1, v) == vec2(1, 2));
    REQUIRE(outerProduct(3, u) == vec3(3, 6, 9));
    REQUIRE(outerProduct(5, t) == vec4(5, 10, 15, 20));
  }

  SECTION("vector scalar") {
    vec2 v = vec2(1, 2);
    vec3 u = vec3(1, 2, 3);
    vec4 t = vec4(1, 2, 3, 4);

    REQUIRE(outerProduct(v, 2) == vec2(2, 4));
    REQUIRE(outerProduct(u, 4) == vec3(4, 8, 12));
    REQUIRE(outerProduct(t, 6) == vec4(6, 12, 18, 24));
  }

  SECTION("vector vector") {
    vec2 v = vec2(1, 2);
    vec3 u = vec3(3, 4, 5);
    vec4 t = vec4(6, 7, 8, 9);

    REQUIRE(outerProduct(v, u) == mat3x2(3, 4, 5, 6, 8, 10));
    REQUIRE(outerProduct(u, v) == mat2x3(3, 6, 4, 8, 5, 10));

    REQUIRE(outerProduct(v, t) == mat4x2(6, 7, 8, 9, 12, 14, 16, 18));
    REQUIRE(outerProduct(t, v) == mat2x4(6, 12, 7, 14, 8, 16, 9, 18));

    REQUIRE(outerProduct(u, t) == mat4x3(18, 21, 24, 27, 24, 28, 32, 36, 30, 35, 40, 45));
    REQUIRE(outerProduct(t, u) == mat3x4(18, 24, 30, 21, 28, 35, 24, 32, 40, 27, 36, 45));
  }
}

TEST_CASE("matrix function transpose", "[mat]") {

  SECTION("mat2") {
    mat2 m = mat2(1, 2, 3, 4);
    REQUIRE(transpose(m) == mat2(1, 3, 2, 4));
  }

  SECTION("mat3") {
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    REQUIRE(transpose(n) == mat3(1, 4, 7,2, 5, 8,3, 6, 9));
  }

  SECTION("mat4") {
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    REQUIRE(transpose(o) == mat4(1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 16));
  }

  SECTION("mat2x4") {
    mat2x4 m = mat2x4(1,2,3,4,5,6,7,8);
    REQUIRE(transpose(m) == mat4x2(1, 3, 5, 7, 2, 4, 6, 8));
  }

  SECTION("mat4x2") {
    mat4x2 n = mat4x2(1,2,3,4,5,6,7,8);
    REQUIRE(transpose(n) == mat2x4(1, 5, 2, 6, 3, 7, 4, 8));
  }
}

TEST_CASE("matrix function determinant", "[mat]") {

  SECTION("mat2") {
    REQUIRE(determinant(mat2(0, -2, 1, 1)) == 2);
    REQUIRE(determinant(mat2(2, -2, 0, 1)) == 2);
    REQUIRE(determinant(mat2(2, 0, 0, 1)) == 2);

    REQUIRE(determinant(mat2(0, 2, 1, 1)) == -2);
    REQUIRE(determinant(mat2(3, 2, 0, 1)) == 3);
    REQUIRE(determinant(mat2(3, 0, 0, 1)) == 3);

    REQUIRE(determinant(mat2(0, 2, 0, -2)) == 0);
    REQUIRE(determinant(mat2(3, 2, 2, -2)) == -10);
    REQUIRE(determinant(mat2(3, 0, 2, 0)) == 0);
  }

  SECTION("identity") {
    mat2 m = mat2(1, 0, 0, 1);
    mat3 n = mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);
    mat4 o = mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

    REQUIRE(determinant(m) == 1);
    REQUIRE(determinant(n) == 1);
    REQUIRE(determinant(o) == 1);
  }
}

TEST_CASE("matrix function cofactor", "[mat]") {

  SECTION("mat2") {
    mat2 m = mat2(1, 2, 3, 4);

    REQUIRE((cofactor<0, 0>(m)) == 4);
    REQUIRE((cofactor<0, 1>(m)) == -3);
    REQUIRE((cofactor<1, 0>(m)) == -2);
    REQUIRE((cofactor<1, 1>(m)) == 1);
  }

  SECTION("mat3") {
    mat3 m = mat3(3, 0, 2, 2, 0, -2, 0, 1, 1);

    REQUIRE((cofactor<0, 0>(m)) == 2);
    REQUIRE((cofactor<0, 1>(m)) == -2);
    REQUIRE((cofactor<0, 2>(m)) == 2);
    REQUIRE((cofactor<1, 0>(m)) == 2);
    REQUIRE((cofactor<1, 1>(m)) == 3);
    REQUIRE((cofactor<1, 2>(m)) == -3);
    REQUIRE((cofactor<2, 0>(m)) == 0);
    REQUIRE((cofactor<2, 1>(m)) == 10);
    REQUIRE((cofactor<2, 2>(m)) == 0);
  }
}

TEST_CASE("matrix function cofactors", "[mat]") {

  SECTION("mat2") {
    mat2 m = mat2(1, 2, 3, 4);

    REQUIRE(cofactors(m) == mat2(4, -3, -2, 1));
  }

  SECTION("mat3") {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 n = mat3(3, 0, 2, 2, 0, -2, 0, 1, 1);

    REQUIRE(cofactors(m) == mat3(-3, 6, -3, 6, -12, 6, -3, 6, -3));
    REQUIRE(cofactors(n) == mat3(2, -2, 2, 2, 3, -3, 0, 10, 0));
  }

  SECTION("mat4") {
    mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    mat4 n = mat4(1, -2, 3, 0, 5, 8, -1, 1, 2, 1, 1, 1, 1, 1, 1, 1);

    REQUIRE(cofactors(m) == mat4(0));
    REQUIRE(cofactors(n) == mat4(0, -2, -7, 9, 0, -3, -2, 5, -17, 14, 15, -12, 17, -11, -13, -10));
  }
}

TEST_CASE("matrix function adjugate", "[mat]") {

  mat2 m = mat2(1, 2, 3, 4);
  mat3 n = mat3(3, 0, 2, 2, 0, -2, 0, 1, 1);
  mat4 o = mat4(1, -2, 3, 0, 5, 8, -1, 1, 2, 1, 1, 1, 1, 1, 1, 1);

  REQUIRE(adjugate(m) == mat2(4, -2, -3, 1));
  REQUIRE(adjugate(n) == mat3(2, 2, 0, -2, 3, 10, 2, -3, 0));
  REQUIRE(adjugate(o) == mat4(0, 0, -17, 17, -2, -3, 14, -11, -7, -2, 15, -13, 9, 5, -12, -10));
}

TEST_CASE("matrix function inverse", "[mat]") {

  mat2 m = mat2(1, 2, 3, 4);
  mat3 t = mat3(1, 0, 2, 0, 1, 2, 0, 0, 1);
  mat4 s = mat4(2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1);

  REQUIRE(inverse(m) == mat2(-2, 1, 1.5, -0.5));
  REQUIRE(inverse(t) == mat3(1, 0, -2, 0, 1, -2, 0, 0, 1));
  REQUIRE(inverse(s) == mat4(0.5, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1));
}
