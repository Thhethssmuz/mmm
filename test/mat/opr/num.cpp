#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto sm_add1 = UnitTest("scalar matrix operator + (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (1 + m != mat2(2, 3, 4, 5)) return false;
    if (2.f + m != mat2(3, 4, 5, 6)) return false;
    if (3.0 + m != mat2(4, 5, 6, 7)) return false;

    if (4 + n != mat3(5, 6, 7, 8, 9, 10, 11, 12, 13)) return false;
    if (5.f + n != mat3(6, 7, 8, 9, 10, 11, 12, 13, 14)) return false;
    if (6.0 + n != mat3(7, 8, 9, 10, 11, 12, 13, 14, 15)) return false;

    if (7 + o != mat4(8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23)) return false;
    if (8.f + o != mat4(9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24)) return false;
    if (9.0 + o != mat4(10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25)) return false;

    return true;
  });
  auto sm_add2 = UnitTest("scalar matrix operator + (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    if (1 + m != mat2x4(2, 3, 4, 5, 6, 7, 8, 9)) return false;
    if (2.f + m != mat2x4(3, 4, 5, 6, 7, 8, 9, 10)) return false;
    if (3.0 + m != mat2x4(4, 5, 6, 7, 8, 9, 10, 11)) return false;

    if (4 + n != mat4x2(5, 6, 7, 8, 9, 10, 11, 12)) return false;
    if (5.f + n != mat4x2(6, 7, 8, 9, 10, 11, 12, 13)) return false;
    if (6.0 + n != mat4x2(7, 8, 9, 10, 11, 12, 13, 14)) return false;

    return true;
  });
  auto ms_add1 = UnitTest("matrix scalar operator + (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (m + 1 != mat2(2, 3, 4, 5)) return false;
    if (m + 2.f  != mat2(3, 4, 5, 6)) return false;
    if (m + 3.0  != mat2(4, 5, 6, 7)) return false;

    if (n + 4 != mat3(5, 6, 7, 8, 9, 10, 11, 12, 13)) return false;
    if (n + 5.f != mat3(6, 7, 8, 9, 10, 11, 12, 13, 14)) return false;
    if (n + 6.0 != mat3(7, 8, 9, 10, 11, 12, 13, 14, 15)) return false;

    if (o + 7 != mat4(8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23)) return false;
    if (o + 8.f != mat4(9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24)) return false;
    if (o + 9.0 != mat4(10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25)) return false;

    return true;
  });
  auto ms_add2 = UnitTest("matrix scalar operator + (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    if (m + 1 != mat2x4(2, 3, 4, 5, 6, 7, 8, 9)) return false;
    if (m + 2.f != mat2x4(3, 4, 5, 6, 7, 8, 9, 10)) return false;
    if (m + 3.0 != mat2x4(4, 5, 6, 7, 8, 9, 10, 11)) return false;

    if (n + 4 != mat4x2(5, 6, 7, 8, 9, 10, 11, 12)) return false;
    if (n + 5.f != mat4x2(6, 7, 8, 9, 10, 11, 12, 13)) return false;
    if (n + 6.0 != mat4x2(7, 8, 9, 10, 11, 12, 13, 14)) return false;

    return true;
  });
  auto mm_add1 = UnitTest("matrix matrix operator + (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat2 n = mat2(4, 3, 2, 1);
    mat2 i = mat2(1, 0, 0, 1);

    if (m + m != mat2(2, 4, 6, 8)) return false;
    if (n + n != mat2(8, 6, 4, 2)) return false;
    if (i + i != mat2(2, 0, 0, 2)) return false;

    if (m + n != mat2(5, 5, 5, 5)) return false;
    if (n + m != mat2(5, 5, 5, 5)) return false;

    if (m + i != mat2(2, 2, 3, 5)) return false;
    if (i + m != mat2(2, 2, 3, 5)) return false;

    if (n + i != mat2(5, 3, 2, 2)) return false;
    if (i + n != mat2(5, 3, 2, 2)) return false;

    return true;
  });
  auto mm_add2 = UnitTest("matrix matrix operator + (2)", +[] {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 n = mat3(9, 8, 7, 6, 5, 4, 3, 2, 1);
    mat3 i = mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);

    if (m + m != mat3(2, 4, 6, 8, 10, 12, 14, 16, 18)) return false;
    if (n + n != mat3(18, 16, 14, 12, 10, 8, 6, 4, 2)) return false;
    if (i + i != mat3(2, 0, 0, 0, 2, 0, 0, 0, 2)) return false;

    if (m + n != 10) return false;
    if (n + m != 10) return false;

    if (m + i != mat3(2, 2, 3, 4, 6, 6, 7, 8, 10)) return false;
    if (i + m != mat3(2, 2, 3, 4, 6, 6, 7, 8, 10)) return false;

    if (n + i != mat3(10, 8, 7, 6, 6, 4, 3, 2, 2)) return false;
    if (i + n != mat3(10, 8, 7, 6, 6, 4, 3, 2, 2)) return false;

    return true;
  });
  auto mm_add3 = UnitTest("matrix matrix operator + (3)", +[] {
    mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    mat4 n = mat4(16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
    mat4 i = mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

    if (m + m != mat4(2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32)) return false;
    if (n + n != mat4(32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2)) return false;
    if (i + i != mat4(2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2)) return false;

    if (m + n != 17) return false;
    if (n + m != 17) return false;

    if (m + i != mat4(2, 2, 3, 4, 5, 7, 7, 8, 9, 10, 12, 12, 13, 14, 15, 17)) return false;
    if (i + m != mat4(2, 2, 3, 4, 5, 7, 7, 8, 9, 10, 12, 12, 13, 14, 15, 17)) return false;

    if (n + i != mat4(17, 15, 14, 13, 12, 12, 10, 9, 8, 7, 7, 5, 4, 3, 2, 2)) return false;
    if (i + n != mat4(17, 15, 14, 13, 12, 12, 10, 9, 8, 7, 7, 5, 4, 3, 2, 2)) return false;

    return true;
  });

  auto sm_sub1 = UnitTest("scalar matrix operator - (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (1 - m != mat2(0, -1, -2, -3)) return false;
    if (2.f - m != mat2(1, 0, -1, -2)) return false;
    if (3.0 - m != mat2(2, 1, 0, -1)) return false;

    if (4 - n != mat3(3, 2, 1, 0, -1, -2, -3, -4, -5)) return false;
    if (5.f - n != mat3(4, 3, 2, 1, 0, -1, -2, -3, -4)) return false;
    if (6.0 - n != mat3(5, 4, 3, 2, 1, 0, -1, -2, -3)) return false;

    if (7 - o != mat4(6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9)) return false;
    if (8.f - o != mat4(7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8)) return false;
    if (9.0 - o != mat4(8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7)) return false;

    return true;
  });
  auto sm_sub2 = UnitTest("scalar matrix operator - (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    if (1 - m != mat2x4(0, -1, -2, -3, -4, -5, -6, -7)) return false;
    if (2.f - m != mat2x4(1, 0, -1, -2, -3, -4, -5, -6)) return false;
    if (3.0 - m != mat2x4(2, 1, 0, -1, -2, -3, -4, -5)) return false;

    if (4 - n != mat4x2(3, 2, 1, 0, -1, -2, -3, -4)) return false;
    if (5.f - n != mat4x2(4, 3, 2, 1, 0, -1, -2, -3)) return false;
    if (6.0 - n != mat4x2(5, 4, 3, 2, 1, 0, -1, -2)) return false;

    return true;
  });
  auto ms_sub1 = UnitTest("matrix scalar operator - (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (m - 1 != mat2(0, 1, 2, 3)) return false;
    if (m - 2.f  != mat2(-1, 0, 1, 2)) return false;
    if (m - 3.0  != mat2(-2, -1, 0, 1)) return false;

    if (n - 4 != mat3(-3, -2, -1, 0, 1, 2, 3, 4, 5)) return false;
    if (n - 5.f != mat3(-4, -3, -2, -1, 0, 1, 2, 3, 4)) return false;
    if (n - 6.0 != mat3(-5, -4, -3, -2, -1, 0, 1, 2, 3)) return false;

    if (o - 7 != mat4(-6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9)) return false;
    if (o - 8.f != mat4(-7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8)) return false;
    if (o - 9.0 != mat4(-8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7)) return false;

    return true;
  });
  auto ms_sub2 = UnitTest("matrix scalar operator - (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    if (m - 1 != mat2x4(0, 1, 2, 3, 4, 5, 6, 7)) return false;
    if (m - 2.f != mat2x4(-1, 0, 1, 2, 3, 4, 5, 6)) return false;
    if (m - 3.0 != mat2x4(-2, -1, 0, 1, 2, 3, 4, 5)) return false;

    if (n - 4 != mat4x2(-3, -2, -1, 0, 1, 2, 3, 4)) return false;
    if (n - 5.f != mat4x2(-4, -3, -2, -1, 0, 1, 2, 3)) return false;
    if (n - 6.0 != mat4x2(-5, -4, -3, -2, -1, 0, 1, 2)) return false;

    return true;
  });
  auto mm_sub1 = UnitTest("matrix matrix operator - (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat2 n = mat2(4, 3, 2, 1);
    mat2 i = mat2(1, 0, 0, 1);

    if (m - m != mat2(0, 0, 0, 0)) return false;
    if (n - n != mat2(0, 0, 0, 0)) return false;
    if (i - i != mat2(0, 0, 0, 0)) return false;

    if (m - n != mat2(-3, -1, 1, 3)) return false;
    if (n - m != mat2(3, 1, -1, -3)) return false;

    if (m - i != mat2(0, 2, 3, 3)) return false;
    if (i - m != mat2(0, -2, -3, -3)) return false;

    if (n - i != mat2(3, 3, 2, 0)) return false;
    if (i - n != mat2(-3, -3, -2, 0)) return false;

    return true;
  });
  auto mm_sub2 = UnitTest("matrix matrix operator - (2)", +[] {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 n = mat3(9, 8, 7, 6, 5, 4, 3, 2, 1);
    mat3 i = mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);

    if (m - m != 0) return false;
    if (n - n != 0) return false;
    if (i - i != 0) return false;

    if (m - n != mat3(-8, -6, -4, -2, 0, 2, 4, 6, 8)) return false;
    if (n - m != mat3(8, 6, 4, 2, 0, -2, -4, -6, -8)) return false;

    if (m - i != mat3(0, 2, 3, 4, 4, 6, 7, 8, 8)) return false;
    if (i - m != mat3(0, -2, -3, -4, -4, -6, -7, -8, -8)) return false;

    if (n - i != mat3(8, 8, 7, 6, 4, 4, 3, 2, 0)) return false;
    if (i - n != mat3(-8, -8, -7, -6, -4, -4, -3, -2, 0)) return false;

    return true;
  });
  auto mm_sub3 = UnitTest("matrix matrix operator - (3)", +[] {
    mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    mat4 n = mat4(16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
    mat4 i = mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

    if (m - m != 0) return false;
    if (n - n != 0) return false;
    if (i - i != 0) return false;

    if (m - n != mat4(-15, -13, -11, -9, -7, -5, -3, -1, 1, 3, 5, 7, 9, 11, 13, 15)) return false;
    if (n - m != mat4(15, 13, 11, 9, 7, 5, 3, 1, -1, -3, -5, -7, -9, -11, -13, -15)) return false;

    if (m - i != mat4(0, 2, 3, 4, 5, 5, 7, 8, 9, 10, 10, 12, 13, 14, 15, 15)) return false;
    if (i - m != mat4(0, -2, -3, -4, -5, -5, -7, -8, -9, -10, -10, -12, -13, -14, -15, -15)) return false;

    if (n - i != mat4(15, 15, 14, 13, 12, 10, 10, 9, 8, 7, 5, 5, 4, 3, 2, 0)) return false;
    if (i - n != mat4(-15, -15, -14, -13, -12, -10, -10, -9, -8, -7, -5, -5, -4, -3, -2, 0)) return false;

    return true;
  });

  auto sm_mult1 = UnitTest("scalar matrix operator * (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (1 * m != mat2(1, 2, 3, 4)) return false;
    if (2.f * m != mat2(2, 4, 6, 8)) return false;
    if (3.0 * m != mat2(3, 6, 9, 12)) return false;

    if (4 * n != mat3(4, 8, 12, 16, 20, 24, 28, 32, 36)) return false;
    if (5.f * n != mat3(5, 10, 15, 20, 25, 30, 35, 40, 45)) return false;
    if (6.0 * n != mat3(6, 12, 18, 24, 30, 36, 42, 48, 54)) return false;

    if (7 * o != mat4(7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112)) return false;
    if (8.f * o != mat4(8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128)) return false;
    if (9.0 * o != mat4(9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99, 108, 117, 126, 135, 144)) return false;

    return true;
  });
  auto sm_mult2 = UnitTest("scalar matrix operator * (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    if (1 * m != mat2x4(1, 2, 3, 4, 5, 6, 7, 8)) return false;
    if (2.f * m != mat2x4(2, 4, 6, 8, 10, 12, 14, 16)) return false;
    if (3.0 * m != mat2x4(3, 6, 9, 12, 15, 18, 21, 24)) return false;

    if (4 * n != mat4x2(4, 8, 12, 16, 20, 24, 28, 32)) return false;
    if (5.f * n != mat4x2(5, 10, 15, 20, 25, 30, 35, 40)) return false;
    if (6.0 * n != mat4x2(6, 12, 18, 24, 30, 36, 42, 48)) return false;

    return true;
  });
  auto ms_mult1 = UnitTest("matrix scalar operator * (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (m * 1 != mat2(1, 2, 3, 4)) return false;
    if (m * 2.f  != mat2(2, 4, 6, 8)) return false;
    if (m * 3.0  != mat2(3, 6, 9, 12)) return false;

    if (n * 4 != mat3(4, 8, 12, 16, 20, 24, 28, 32, 36)) return false;
    if (n * 5.f != mat3(5, 10, 15, 20, 25, 30, 35, 40, 45)) return false;
    if (n * 6.0 != mat3(6, 12, 18, 24, 30, 36, 42, 48, 54)) return false;

    if (o * 7 != mat4(7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112)) return false;
    if (o * 8.f != mat4(8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128)) return false;
    if (o * 9.0 != mat4(9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99, 108, 117, 126, 135, 144)) return false;

    return true;
  });
  auto ms_mult2 = UnitTest("matrix scalar operator * (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    if (m * 1 != mat2x4(1, 2, 3, 4, 5, 6, 7, 8)) return false;
    if (m * 2.f != mat2x4(2, 4, 6, 8, 10, 12, 14, 16)) return false;
    if (m * 3.0 != mat2x4(3, 6, 9, 12, 15, 18, 21, 24)) return false;

    if (n * 4 != mat4x2(4, 8, 12, 16, 20, 24, 28, 32)) return false;
    if (n * 5.f != mat4x2(5, 10, 15, 20, 25, 30, 35, 40)) return false;
    if (n * 6.0 != mat4x2(6, 12, 18, 24, 30, 36, 42, 48)) return false;

    return true;
  });
  auto vm_mult1 = UnitTest("vector matrix operator * (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    vec2 v = vec2(1, 2);
    vec3 u = vec3(1, 2, 3);
    vec4 t = vec4(1, 2, 3, 4);

    if (v * m != vec2(7, 10)) return false;
    if (v.yx * m != vec2(5, 8)) return false;

    if (u * n != vec3(30, 36, 42)) return false;
    if (u.zyx * n != vec3(18, 24, 30)) return false;

    if (t * o != vec4(90, 100, 110, 120)) return false;
    if (t.wzyx * o != vec4(50, 60, 70, 80)) return false;

    return true;
  });
  auto vm_mult2 = UnitTest("vector matrix operator * (2)", +[] {
    vec4 v = vec4(1, 2, 3, 4);

    if (v.xy * mat2x2(1, 2, 3, 4) != vec2(7, 10)) return false;
    if (v.xy * mat3x2(1, 2, 3, 4, 5, 6) != vec3(9, 12, 15)) return false;
    if (v.xy * mat4x2(1, 2, 3, 4, 5, 6, 7, 8) != vec4(11, 14, 17, 20)) return false;

    if (v.xyz * mat2x3(1, 2, 3, 4, 5, 6) != vec2(22, 28)) return false;
    if (v.xyz * mat3x3(1, 2, 3, 4, 5, 6, 7, 8, 9) != vec3(30, 36, 42)) return false;
    if (v.xyz * mat4x3(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) != vec4(38, 44, 50, 56)) return false;

    if (v * mat2x4(1, 2, 3, 4, 5, 6, 7, 8) != vec2(50, 60)) return false;
    if (v * mat3x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) != vec3(70, 80, 90)) return false;
    if (v * mat4x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16) != vec4(90, 100, 110, 120)) return false;

    return true;
  });
  auto mv_mult1 = UnitTest("matrix vector operator * (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    vec2 v = vec2(1, 2);
    vec3 u = vec3(1, 2, 3);
    vec4 t = vec4(1, 2, 3, 4);

    if (m * v != vec2(5, 11)) return false;
    if (m * v.yx != vec2(4, 10)) return false;

    if (n * u != vec3(14, 32, 50)) return false;
    if (n * u.zyx != vec3(10, 28, 46)) return false;

    if (o * t != vec4(30, 70, 110, 150)) return false;
    if (o * t.wzyx != vec4(20, 60, 100, 140)) return false;

    return true;
  });
  auto mv_mult2 = UnitTest("matrix vector operator * (2)", +[] {
    vec4 v = vec4(1, 2, 3, 4);

    if (mat2x2(1, 2, 3, 4) * v.xy != vec2(5, 11)) return false;
    if (mat2x3(1, 2, 3, 4, 5, 6) * v.xy != vec3(5, 11, 17)) return false;
    if (mat2x4(1, 2, 3, 4, 5, 6, 7, 8) * v.xy != vec4(5, 11, 17, 23)) return false;

    if (mat3x2(1, 2, 3, 4, 5, 6) * v.xyz != vec2(14, 32)) return false;
    if (mat3x3(1, 2, 3, 4, 5, 6, 7, 8, 9) * v.xyz != vec3(14, 32, 50)) return false;
    if (mat3x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) * v.xyz != vec4(14, 32, 50, 68)) return false;

    if (mat4x2(1, 2, 3, 4, 5, 6, 7, 8) * v != vec2(30, 70)) return false;
    if (mat4x3(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) * v != vec3(30, 70, 110)) return false;
    if (mat4x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16) * v != vec4(30, 70, 110, 150)) return false;

    return true;
  });
  auto mm_mult1 = UnitTest("matrix matrix operator * (1)", +[] {
    mat2x2 m22 = mat2x2(1, 2, 3, 4);
    mat2x3 m23 = mat2x3(1, 2, 3, 4, 5, 6);
    mat2x4 m24 = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

    mat3x2 m32 = mat3x2(1, 2, 3, 4, 5, 6);
    mat3x3 m33 = mat3x3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3x4 m34 = mat3x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);

    mat4x2 m42 = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x3 m43 = mat4x3(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
    mat4x4 m44 = mat4x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);


    if (m22 * m22 != mat2x2(7, 10, 15, 22)) return false;
    if (m22 * m32 != mat3x2(9, 12, 15, 19, 26, 33)) return false;
    if (m22 * m42 != mat4x2(11, 14, 17, 20, 23, 30, 37, 44)) return false;

    if (m23 * m22 != mat2x3(7, 10, 15, 22, 23, 34)) return false;
    if (m23 * m32 != mat3x3(9, 12, 15, 19, 26, 33, 29, 40, 51)) return false;
    if (m23 * m42 != mat4x3(11, 14, 17, 20, 23, 30, 37, 44, 35, 46, 57, 68)) return false;

    if (m24 * m22 != mat2x4(7, 10, 15, 22, 23, 34, 31, 46)) return false;
    if (m24 * m32 != mat3x4(9, 12, 15, 19, 26, 33, 29, 40, 51, 39, 54, 69)) return false;
    if (m24 * m42 != mat4x4(11, 14, 17, 20, 23, 30, 37, 44, 35, 46, 57, 68, 47, 62, 77, 92)) return false;


    if (m32 * m23 != mat2x2(22, 28, 49, 64)) return false;
    if (m32 * m33 != mat3x2(30, 36, 42, 66, 81, 96)) return false;
    if (m32 * m43 != mat4x2(38, 44, 50, 56, 83, 98, 113, 128)) return false;

    if (m33 * m23 != mat2x3(22, 28, 49, 64, 76, 100)) return false;
    if (m33 * m33 != mat3x3(30, 36, 42, 66, 81, 96, 102, 126, 150)) return false;
    if (m33 * m43 != mat4x3(38, 44, 50, 56, 83, 98, 113, 128, 128, 152, 176, 200)) return false;

    if (m34 * m23 != mat2x4(22, 28, 49, 64, 76, 100, 103, 136)) return false;
    if (m34 * m33 != mat3x4(30, 36, 42, 66, 81, 96, 102, 126, 150, 138, 171, 204)) return false;
    if (m34 * m43 != mat4x4(38, 44, 50, 56, 83, 98, 113, 128, 128, 152, 176, 200, 173, 206, 239, 272)) return false;


    if (m42 * m24 != mat2x2(50, 60, 114, 140)) return false;
    if (m42 * m34 != mat3x2(70, 80, 90, 158, 184, 210)) return false;
    if (m42 * m44 != mat4x2(90, 100, 110, 120, 202, 228, 254, 280)) return false;

    if (m43 * m24 != mat2x3(50, 60, 114, 140, 178, 220)) return false;
    if (m43 * m34 != mat3x3(70, 80, 90, 158, 184, 210, 246, 288, 330)) return false;
    if (m43 * m44 != mat4x3(90, 100, 110, 120, 202, 228, 254, 280, 314, 356, 398, 440)) return false;

    if (m44 * m24 != mat2x4(50, 60, 114, 140, 178, 220, 242, 300)) return false;
    if (m44 * m34 != mat3x4(70, 80, 90, 158, 184, 210, 246, 288, 330, 334, 392, 450)) return false;
    if (m44 * m44 != mat4x4(90, 100, 110, 120, 202, 228, 254, 280, 314, 356, 398, 440, 426, 484, 542, 600)) return false;


    return true;
  });
  auto mm_mult2 = UnitTest("matrix matrix operator * (2)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat2 n = mat2(-2, 1, 1.5, -0.5);
    mat2 i = mat2(1, 0, 0, 1);

    if (m * i != m) return false;
    if (n * i != n) return false;
    if (m * n != i) return false;
    if (n * m != i) return false;

    return true;
  });
  auto mm_mult3 = UnitTest("matrix matrix operator * (3)", +[] {
    mat4 t = mat4(1, 0, 0, 2, 0, 1, 0, 2, 0, 0, 1, 0, 0, 0, 0, 1);
    mat4 s = mat4(3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1);

    if (t * s != mat4(3, 0, 0, 2, 0, 3, 0, 2, 0, 0, 3, 0, 0, 0, 0, 1)) return false;
    if (s * t != mat4(3, 0, 0, 6, 0, 3, 0, 6, 0, 0, 3, 0, 0, 0, 0, 1)) return false;

    return true;
  });

  auto sm_div1 = UnitTest("scalar matrix operator / (1)", +[] {
    mat2 m = mat2(1, 0.5, 0.25, 0.125);

    if (1 / m != mat2(1, 2, 4, 8)) return false;
    if (2.f / m != mat2(2, 4, 8, 16)) return false;
    if (3.0 / m != mat2(3, 6, 12, 24)) return false;

    return true;
  });
  auto sm_div2 = UnitTest("scalar matrix operator / (2)", +[] {
    mat2x3 m = mat2x3(1.0, 0.8, 0.5, 0.4, 0.2, 0.1);
    mat3x2 n = mat3x2(1.0, 0.8, 0.5, 0.4, 0.2, 0.1);

    if (1 / m != mat2x3(1, 1.25, 2, 2.5, 5, 10)) return false;
    if (2.f / m != mat2x3(2, 2.5, 4, 5, 10, 20)) return false;
    if (3.f / m != mat2x3(3, 3.75, 6, 7.5, 15, 30)) return false;

    if (1 / n != mat3x2(1, 1.25, 2, 2.5, 5, 10)) return false;
    if (2.f / n != mat3x2(2, 2.5, 4, 5, 10, 20)) return false;
    if (3.f / n != mat3x2(3, 3.75, 6, 7.5, 15, 30)) return false;

    return true;
  });
  auto ms_div1 = UnitTest("matrix scalar operator / (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);

    if (mat2(1, 2, 3, 4) / 1 != m) return false;
    if (mat2(2, 4, 6, 8) / 2.f != m) return false;
    if (mat2(3, 6, 9, 12) / 3.0 != m) return false;

    return true;
  });
  auto ms_div2 = UnitTest("matrix scalar operator / (2)", +[] {
    mat2x3 m = mat2x3(1, 2, 3, 4, 5, 6);
    mat3x2 n = mat3x2(1, 2, 3, 4, 5, 6);

    if (mat2x3(1, 2, 3, 4, 5, 6) / 1 != m) return false;
    if (mat2x3(2, 4, 6, 8, 10, 12) / 2.f != m) return false;
    if (mat2x3(3, 6, 9, 12, 15, 18) / 3.f != m) return false;

    if (mat3x2(1, 2, 3, 4, 5, 6) / 1 != n) return false;
    if (mat3x2(2, 4, 6, 8, 10, 12) / 2.f != n) return false;
    if (mat3x2(3, 6, 9, 12, 15, 18) / 3.f != n) return false;

    return true;
  });
  auto mm_div1 = UnitTest("matrix matrix operator / (1)", +[] {
    mat2 m = mat2(8, 4, 2, 1);
    mat2 n = mat2(0.5, 0.5, 0.25, 0.25);

    if (m / m != mat2(1, 1, 1, 1)) return false;
    if (n / n != mat2(1, 1, 1, 1)) return false;

    if (m / n != mat2(16, 8, 8, 4)) return false;
    if (n / m != mat2(0.0625, 0.125, 0.125, 0.25)) return false;

    return true;
  });
}
