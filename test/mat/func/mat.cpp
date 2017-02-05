#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto mcm1 = UnitTest("matrix function matrixCompMult (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat2 n = mat2(2, 3, 4, 5);

    if (matrixCompMult(m, n) != mat2(2, 6, 12, 20)) return false;
    if (matrixCompMult(n, m) != mat2(2, 6, 12, 20)) return false;

    return true;
  });
  auto mcm2 = UnitTest("matrix function matrixCompMult (2)", +[] {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 n = mat3(2, 3, 4, 5, 6, 7, 8, 9, 10);

    if (matrixCompMult(m, n) != mat3(2, 6, 12, 20, 30, 42, 56, 72, 90)) return false;
    if (matrixCompMult(n, m) != mat3(2, 6, 12, 20, 30, 42, 56, 72, 90)) return false;

    return true;
  });

  auto op1 = UnitTest("matrix function outerProduct (1)", +[] {
    vec2 v = vec2(1, 2);
    vec3 u = vec3(1, 2, 3);
    vec4 t = vec4(1, 2, 3, 4);

    if (outerProduct(1, v) != vec2(1, 2)) return false;
    if (outerProduct(v, 2) != vec2(2, 4)) return false;

    if (outerProduct(3, u) != vec3(3, 6, 9)) return false;
    if (outerProduct(u, 4) != vec3(4, 8, 12)) return false;

    if (outerProduct(5, t) != vec4(5, 10, 15, 20)) return false;
    if (outerProduct(t, 6) != vec4(6, 12, 18, 24)) return false;

    return true;
  });
  auto op2 = UnitTest("matrix function outerProduct (2)", +[] {
    vec2 v = vec2(1, 2);
    vec3 u = vec3(3, 4, 5);
    vec4 t = vec4(6, 7, 8, 9);

    if (outerProduct(v, u) != mat3x2(3, 4, 5, 6, 8, 10)) return false;
    if (outerProduct(u, v) != mat2x3(3, 6, 4, 8, 5, 10)) return false;

    if (outerProduct(v, t) != mat4x2(6, 7, 8, 9, 12, 14, 16, 18)) return false;
    if (outerProduct(t, v) != mat2x4(6, 12, 7, 14, 8, 16, 9, 18)) return false;

    if (outerProduct(u, t) != mat4x3(18, 21, 24, 27, 24, 28, 32, 36, 30, 35, 40, 45)) return false;
    if (outerProduct(t, u) != mat3x4(18, 24, 30, 21, 28, 35, 24, 32, 40, 27, 36, 45)) return false;

    return true;
  });

  auto trans1 = UnitTest("matrix function transpose (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (transpose(m) != mat2(1, 3, 2, 4)) return false;
    if (transpose(n) != mat3(1, 4, 7,2, 5, 8,3, 6, 9)) return false;
    if (transpose(o) != mat4(1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 16)) return false;

    return true;
  });
  auto trans2 = UnitTest("matrix function transpose (2)", +[] {
    mat2x4 m = mat2x4(1,2,3,4,5,6,7,8);
    mat4x2 n = mat4x2(1,2,3,4,5,6,7,8);

    if (transpose(m) != mat4x2(1, 3, 5, 7, 2, 4, 6, 8)) return false;
    if (transpose(n) != mat2x4(1, 5, 2, 6, 3, 7, 4, 8)) return false;

    return true;
  });

  auto det1 = UnitTest("matrix function determinant (1)", +[] {

    if (determinant(mat2(0, -2, 1, 1)) != 2) return false;
    if (determinant(mat2(2, -2, 0, 1)) != 2) return false;
    if (determinant(mat2(2, 0, 0, 1)) != 2) return false;

    if (determinant(mat2(0, 2, 1, 1)) != -2) return false;
    if (determinant(mat2(3, 2, 0, 1)) != 3) return false;
    if (determinant(mat2(3, 0, 0, 1)) != 3) return false;

    if (determinant(mat2(0, 2, 0, -2)) != 0) return false;
    if (determinant(mat2(3, 2, 2, -2)) != -10) return false;
    if (determinant(mat2(3, 0, 2, 0)) != 0) return false;

    return true;
  });
  auto det2 = UnitTest("matrix function determinant (2)", +[] {
    mat2 m = mat2(1, 0, 0, 1);
    mat3 n = mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);
    mat4 o = mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

    if (determinant(m) != 1) return false;
    if (determinant(n) != 1) return false;
    if (determinant(o) != 1) return false;

    return true;
  });

  auto cof1 = UnitTest("matrix function cofactor (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);

    if (cofactor<0, 0>(m) != 4) return false;
    if (cofactor<0, 1>(m) != -3) return false;
    if (cofactor<1, 0>(m) != -2) return false;
    if (cofactor<1, 1>(m) != 1) return false;

    return true;
  });
  auto cof2 = UnitTest("matrix function cofactor (2)", +[] {
    mat3 m = mat3(3, 0, 2, 2, 0, -2, 0, 1, 1);

    if (cofactor<0, 0>(m) != 2) return false;
    if (cofactor<0, 1>(m) != -2) return false;
    if (cofactor<0, 2>(m) != 2) return false;
    if (cofactor<1, 0>(m) != 2) return false;
    if (cofactor<1, 1>(m) != 3) return false;
    if (cofactor<1, 2>(m) != -3) return false;
    if (cofactor<2, 0>(m) != 0) return false;
    if (cofactor<2, 1>(m) != 10) return false;
    if (cofactor<2, 2>(m) != 0) return false;

    return true;
  });

  auto cofs1 = UnitTest("matrix function cofactors (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (cofactors(m) != mat2(4, -3, -2, 1)) return false;
    if (cofactors(n) != mat3(-3, 6, -3, 6, -12, 6, -3, 6, -3)) return false;
    if (cofactors(o) != mat4(0)) return false;

    return true;
  });
  auto cofs2 = UnitTest("matrix function cofactors (2)", +[] {
    mat3 m = mat3(3, 0, 2, 2, 0, -2, 0, 1, 1);
    mat4 n = mat4(1, -2, 3, 0, 5, 8, -1, 1, 2, 1, 1, 1, 1, 1, 1, 1);

    if (cofactors(m) != mat3(2, -2, 2, 2, 3, -3, 0, 10, 0)) return false;
    if (cofactors(n) != mat4(0, -2, -7, 9, 0, -3, -2, 5, -17, 14, 15, -12, 17, -11, -13, -10)) return false;

    return true;
  });

  auto adj1 = UnitTest("matrix function adjugate (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(3, 0, 2, 2, 0, -2, 0, 1, 1);
    mat4 o = mat4(1, -2, 3, 0, 5, 8, -1, 1, 2, 1, 1, 1, 1, 1, 1, 1);

    if (adjugate(m) != mat2(4, -2, -3, 1)) return false;
    if (adjugate(n) != mat3(2, 2, 0, -2, 3, 10, 2, -3, 0)) return false;
    if (adjugate(o) != mat4(0, 0, -17, 17, -2, -3, 14, -11, -7, -2, 15, -13, 9, 5, -12, -10)) return false;

    return true;
  });

  auto inv = UnitTest("matrix function inverse", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 t = mat3(1, 0, 2, 0, 1, 2, 0, 0, 1);
    mat4 s = mat4(2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1);

    if (inverse(m) != mat2(-2, 1, 1.5, -0.5)) return false;
    if (inverse(t) != mat3(1, 0, -2, 0, 1, -2, 0, 0, 1)) return false;
    if (inverse(s) != mat4(0.5, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1)) return false;

    return true;
  });
}
