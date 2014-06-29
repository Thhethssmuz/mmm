#include <unittest.hpp>
#include <mmm.hpp>

namespace {

  auto sm_add = UnitTest("scalar matrix operator +", +[] {
    mat2x3 m = mat2x3(1, 2, 3, 2, 3, 4);
    mat3x3 n = mat3x3(1, 2, 3, 2, 3, 4, 3, 4, 5);
    mat4x3 o = mat4x3(1, 2, 3, 2, 3, 4, 3, 4, 5, 4, 5, 6);

    if (1 + m != mat2x3(2, 3, 4, 3, 4, 5)) return false;
    if (1.f + n != mat3x3(2, 3, 4, 3, 4, 5, 4, 5, 6)) return false;
    if (1.0 + o != mat4x3(2, 3, 4, 3, 4, 5, 4, 5, 6, 5, 6, 7)) return false;

    return true;
  });
  auto ms_add = UnitTest("matrix scalar operator +", +[] {
    mat2x3 m = mat2x3(1, 2, 3, 2, 3, 4);
    mat3x3 n = mat3x3(1, 2, 3, 2, 3, 4, 3, 4, 5);
    mat4x3 o = mat4x3(1, 2, 3, 2, 3, 4, 3, 4, 5, 4, 5, 6);

    if (m + 1 != mat2x3(2, 3, 4, 3, 4, 5)) return false;
    if (n + 1.f != mat3x3(2, 3, 4, 3, 4, 5, 4, 5, 6)) return false;
    if (o + 1.0 != mat4x3(2, 3, 4, 3, 4, 5, 4, 5, 6, 5, 6, 7)) return false;

    return true;
  });
  auto mm_add = UnitTest("matrix matrix operator +", +[] {
    mat3 m = mat3(1, 2, 3, 2, 3, 4, 3, 4, 5);
    mat3 n = mat3(5, 4, 3, 4, 3, 2, 3, 2, 1);

    if (m + n != 6) return false;

    if (m + m != m * 2) return false;

    return true;
  });

  auto m_neg = UnitTest("matrix operator -", +[] {
    mat3 n = mat3(1, 2, 3, 2, 3, 4, 3, 4, 5);

    if (-n != mat3(-1, -2, -3, -2, -3, -4, -3, -4, -5)) return false;

    return true;
  });
  auto sm_sub = UnitTest("scalar matrix operator -", +[] {
    mat2x3 m = mat2x3(1, 2, 3, 2, 3, 4);
    mat3x3 n = mat3x3(1, 2, 3, 2, 3, 4, 3, 4, 5);
    mat4x3 o = mat4x3(1, 2, 3, 2, 3, 4, 3, 4, 5, 4, 5, 6);

    if (7 - m != mat2x3(6, 5, 4, 5, 4, 3)) return false;
    if (7.f - n != mat3x3(6, 5, 4, 5, 4, 3, 4, 3, 2)) return false;
    if (7.0 - o != mat4x3(6, 5, 4, 5, 4, 3, 4, 3, 2, 3, 2, 1)) return false;

    return true;
  });
  auto ms_sub = UnitTest("matrix scalar operator -", +[] {
    mat2x3 m = mat2x3(1, 2, 3, 2, 3, 4);
    mat3x3 n = mat3x3(1, 2, 3, 2, 3, 4, 3, 4, 5);
    mat4x3 o = mat4x3(1, 2, 3, 2, 3, 4, 3, 4, 5, 4, 5, 6);

    if (m - 1 != mat2x3(0, 1, 2, 1, 2, 3)) return false;
    if (n - 1.f != mat3x3(0, 1, 2, 1, 2, 3, 2, 3, 4)) return false;
    if (o - 1.0 != mat4x3(0, 1, 2, 1, 2, 3, 2, 3, 4, 3, 4, 5)) return false;

    return true;
  });
  auto mm_sub = UnitTest("matrix matrix operator -", +[] {
    mat3 m = mat3(1, 2, 3, 2, 3, 4, 3, 4, 5);
    mat3 n = mat3(5, 4, 3, 4, 3, 2, 3, 2, 1);

    if (m - n != mat3(-4, -2, 0, -2, 0, 2, 0, 2, 4)) return false;

    if (m - m != 0) return false;

    return true;
  });

  auto sm_mult = UnitTest("scalar matrix operator *", +[] {
    mat2x3 m = mat2x3(1, 2, 3, 2, 3, 4);
    mat3x3 n = mat3x3(1, 2, 3, 2, 3, 4, 3, 4, 5);
    mat4x3 o = mat4x3(1, 2, 3, 2, 3, 4, 3, 4, 5, 4, 5, 6);

    if (2 * m != mat2x3(2, 4, 6, 4, 6, 8)) return false;
    if (2.f * n != mat3x3(2, 4, 6, 4, 6, 8, 6, 8, 10)) return false;
    if (2.0 * o != mat4x3(2, 4, 6, 4, 6, 8, 6, 8, 10, 8, 10, 12)) return false;

    return true;
  });
  auto ms_mult = UnitTest("matrix scalar operator *", +[] {
    mat2x3 m = mat2x3(1, 2, 3, 2, 3, 4);
    mat3x3 n = mat3x3(1, 2, 3, 2, 3, 4, 3, 4, 5);
    mat4x3 o = mat4x3(1, 2, 3, 2, 3, 4, 3, 4, 5, 4, 5, 6);

    if (m * 2 != mat2x3(2, 4, 6, 4, 6, 8)) return false;
    if (n * 2.f != mat3x3(2, 4, 6, 4, 6, 8, 6, 8, 10)) return false;
    if (o * 2.0 != mat4x3(2, 4, 6, 4, 6, 8, 6, 8, 10, 8, 10, 12)) return false;

    return true;
  });
  auto vm_mult = UnitTest("vector matrix operator *", +[] {
    mat2x3 m = mat2x3(1, 2, 3, 2, 3, 4);
    mat3x3 n = mat3x3(1, 2, 3, 2, 3, 4, 3, 4, 5);
    mat4x3 o = mat4x3(1, 2, 3, 2, 3, 4, 3, 4, 5, 4, 5, 6);

    vec3 v = vec3(1, 2, 3);

    if (v * m != vec2(14, 20)) return false;
    if (v * n != vec3(14, 20, 26)) return false;
    if (v * o != vec4(14, 20, 26, 32)) return false;

    if (v.zyx * m != vec2(10, 16)) return false;
    if (v.zyx * n != vec3(10, 16, 22)) return false;
    if (v.zyx * o != vec4(10, 16, 22, 28)) return false;

    return true;
  });
  auto mv_mult = UnitTest("matrix vector operator *", +[] {
    mat3x2 m = mat3x2(1, 2, 2, 3, 3, 4);
    mat3x3 n = mat3x3(1, 2, 3, 2, 3, 4, 3, 4, 5);
    mat3x4 o = mat3x4(1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6);

    vec3 v = vec3(1, 2, 3);

    if (m * v != vec2(14, 20)) return false;
    if (n * v != vec3(14, 20, 26)) return false;
    if (o * v != vec4(14, 20, 26, 32)) return false;

    if (m * v.zyx != vec2(10, 16)) return false;
    if (n * v.zyx != vec3(10, 16, 22)) return false;
    if (o * v.zyx != vec4(10, 16, 22, 28)) return false;

    return true;
  });
  auto mm_mult = UnitTest("matrix matrix operator *", +[] {
    mat3x2 m = mat3x2(1, 2, 2, 3, 3, 4);
    mat3x3 n = mat3x3(1, 2, 3, 2, 3, 4, 3, 4, 5);
    mat3x4 o = mat3x4(1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6);

    mat2x3 a = mat2x3(1, 2, 3, 2, 3, 4);
    mat3x3 b = mat3x3(1, 2, 3, 2, 3, 4, 3, 4, 5);
    mat4x3 c = mat4x3(1, 2, 3, 2, 3, 4, 3, 4, 5, 4, 5, 6);

    if (m * a != mat2x2(14, 20, 20, 29)) return false;
    if (m * b != mat3x2(14, 20, 20, 29, 26, 38)) return false;
    if (m * c != mat4x2(14, 20, 20, 29, 26, 38, 32, 47)) return false;

    if (n * a != mat2x3(14, 20, 26, 20, 29, 38)) return false;
    if (n * b != mat3x3(14, 20, 26, 20, 29, 38, 26, 38, 50)) return false;
    if (n * c != mat4x3(14, 20, 26, 20, 29, 38, 26, 38, 50, 32, 47, 62))
      return false;

    if (o * a != mat2x4(14, 20, 26, 32, 20, 29, 38, 47)) return false;
    if (o * b != mat3x4(14, 20, 26, 32, 20, 29, 38, 47, 26, 38, 50, 62))
      return false;
    if (o * c !=
        mat4x4(14, 20, 26, 32, 20, 29, 38, 47, 26, 38, 50, 62, 32, 47, 62, 77))
      return false;

    return true;
  });

  auto sm_div = UnitTest("scalar matrix operator /", +[] {
    mat2x3 m = mat2x3(1, 2, 3, 2, 3, 4);
    mat3x3 n = mat3x3(1, 2, 3, 2, 3, 4, 3, 4, 5);
    mat4x3 o = mat4x3(1, 2, 3, 2, 3, 4, 3, 4, 5, 4, 5, 6);

    if (12 / m != mat2x3(12, 6, 4, 6, 4, 3)) return false;
    if (12.f / n != mat3x3(12, 6, 4, 6, 4, 3, 4, 3, 2.4)) return false;
    if (12.0 / o != mat4x3(12, 6, 4, 6, 4, 3, 4, 3, 2.4, 3, 2.4, 2))
      return false;

    return true;
  });
  auto ms_div = UnitTest("matrix scalar operator /", +[] {
    mat2x3 m = mat2x3(2, 4, 6, 4, 6, 8);
    mat3x3 n = mat3x3(2, 4, 6, 4, 6, 8, 6, 8, 10);
    mat4x3 o = mat4x3(2, 4, 6, 4, 6, 8, 6, 8, 10, 8, 10, 12);

    if (m / 2 != mat2x3(1, 2, 3, 2, 3, 4)) return false;
    if (n / 2.f != mat3x3(1, 2, 3, 2, 3, 4, 3, 4, 5)) return false;
    if (o / 2.0 != mat4x3(1, 2, 3, 2, 3, 4, 3, 4, 5, 4, 5, 6)) return false;

    return true;
  });
  auto mm_div = UnitTest("matrix matrix operator /", +[] {
    mat3 m = mat3(2, 4, 6, 4, 6, 8, 6, 8, 10);
    mat3 n = mat3(1, 2, 3, 2, 3, 4, 3, 4, 5);

    if (m / n != 2) return false;
    if (m / m != 1) return false;
    if ((m * 2) / 2 != m) return false;

    return true;
  });
}
