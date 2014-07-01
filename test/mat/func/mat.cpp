#include <unittest.hpp>
#include <mmm.hpp>

namespace {

  auto mcm = UnitTest("matrix function matrixCompMult", +[] {
    mat3 m = mat3(1, 4, 7, 2, 5, 8, 3, 6, 9);
    mat3 n = mat3(2);

    mat3 o = matrixCompMult(m, n);
    if (o != mat3(2, 8, 14, 4, 10, 16, 6, 12, 18)) return false;

    return true;
  });

  auto op = UnitTest("matrix function outerProduct", +[] {
    vec3 v = vec3(1, 2, 3);
    vec2 u = vec2(2, 4);

    mat3 m = outerProduct(v, v);
    if (m != mat3(1, 2, 3, 2, 4, 6, 3, 6, 9)) return false;

    mat2x3 n = outerProduct(v, u);
    if (n != mat2x3(2, 4, 6, 4, 8, 12)) return false;

    mat3x2 o = outerProduct(u, v);
    if (o != mat3x2(2, 4, 4, 8, 6, 12)) return false;

    return true;
  });

  auto trans = UnitTest("matrix function transpose", +[] {
    mat4 m = mat4(1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 16);
    mat4x3 n = mat4x3(1, 5, 9, 2, 6, 10, 3, 7, 11, 4, 8, 12);
    mat4x2 o = mat4x2(1, 5, 2, 6, 3, 7, 4, 8);

    mat4 tm = transpose(m);
    if (tm != mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16))
      return false;

    mat3x4 tn = transpose(n);
    if (tn != mat3x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)) return false;

    mat2x4 to = transpose(o);
    if (to != mat2x4(1, 2, 3, 4, 5, 6, 7, 8)) return false;

    if (transpose(tm) != m) return false;
    if (transpose(tn) != n) return false;
    if (transpose(to) != o) return false;

    return true;
  });

  auto det1 = UnitTest("matrix function determinant (1)", +[] {
    mat2 m;

    m = mat2(1, 2, 3, 4);
    if (determinant(m) != -2) return false;

    m = mat2(3, 7, 5, 9);
    if (determinant(m) != -8) return false;

    return true;
  });
  auto det2 = UnitTest("matrix function determinant (2)", +[] {
    mat3 m;

    m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    if (determinant(m) != 0) return false;

    m = mat3(1, 0, 0, 0, 1, 0, 2, 2, 1);
    if (determinant(m) != 1) return false;

    return true;
  });
  auto det3 = UnitTest("matrix function determinant (3)", +[] {
    mat4 m;

    m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    if (determinant(m) != 0) return false;

    m = mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 3, 2, 1, 1);
    if (determinant(m) != 1) return false;

    m = mat4(4, 0, 2, 0, 0, 4, 0, 0, 2, 0, 4, 0, 1, 1, 1, 1);
    if (determinant(m) != 48) return false;

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
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

    if (cofactor<0, 0>(m) != -3) return false;
    if (cofactor<0, 1>(m) != 6) return false;
    if (cofactor<0, 2>(m) != -3) return false;
    if (cofactor<1, 0>(m) != 6) return false;
    if (cofactor<1, 1>(m) != -12) return false;
    if (cofactor<1, 2>(m) != 6) return false;
    if (cofactor<2, 0>(m) != -3) return false;
    if (cofactor<2, 1>(m) != 6) return false;
    if (cofactor<2, 2>(m) != -3) return false;

    return true;
  });

  auto cofs = UnitTest("matrix function cofactors", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

    if (cofactors(m) != mat2(4, -3, -2, 1)) return false;
    if (cofactors(n) != mat3(-3, 6, -3, 6, -12, 6, -3, 6, -3)) return false;

    return true;
  });

  auto inv = UnitTest("matrix function inverse", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 0, 0, 0, 2, 1, 2, 1, 0);

    if (inverse(m) != mat2(-2, 1, 1.5, -0.5)) return false;
    if (inverse(n) != mat3(1, 0, 0, -2, 0, 1, 4, 1, -2)) return false;

    return true;
  });
}
