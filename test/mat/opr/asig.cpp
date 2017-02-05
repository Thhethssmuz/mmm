#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto ms_add1 = UnitTest("matrix scalar assignment operator += (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    m += 1;
    if (m != mat2(2, 3, 4, 5)) return false;
    m += 1.f;
    if (m != mat2(3, 4, 5, 6)) return false;
    m += 1.0;
    if (m != mat2(4, 5, 6, 7)) return false;

    n += 4;
    if (n != mat3(5, 6, 7, 8, 9, 10, 11, 12, 13)) return false;
    n += 1.f;
    if (n != mat3(6, 7, 8, 9, 10, 11, 12, 13, 14)) return false;
    n += 1.0;
    if (n != mat3(7, 8, 9, 10, 11, 12, 13, 14, 15)) return false;

    o += 7;
    if (o != mat4(8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23)) return false;
    o += 1.f;
    if (o != mat4(9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24)) return false;
    o += 1.0;
    if (o != mat4(10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25)) return false;

    return true;
  });
  auto ms_add2 = UnitTest("matrix scalar assignment operator += (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    m += 1;
    if (m != mat2x4(2, 3, 4, 5, 6, 7, 8, 9)) return false;
    m += 1.f;
    if (m != mat2x4(3, 4, 5, 6, 7, 8, 9, 10)) return false;
    m += 1.0;
    if (m != mat2x4(4, 5, 6, 7, 8, 9, 10, 11)) return false;

    n += 4;
    if (n != mat4x2(5, 6, 7, 8, 9, 10, 11, 12)) return false;
    n += 1.f;
    if (n != mat4x2(6, 7, 8, 9, 10, 11, 12, 13)) return false;
    n += 1.0;
    if (n != mat4x2(7, 8, 9, 10, 11, 12, 13, 14)) return false;

    return true;
  });
  auto mm_add1 = UnitTest("matrix matrix assignment operator += (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat2 n = mat2(4, 3, 2, 1);
    mat2 i = mat2(1, 0, 0, 1);

    m += m;
    if (m != mat2(2, 4, 6, 8)) return false;
    n += n;
    if (n != mat2(8, 6, 4, 2)) return false;
    i += i;
    if (i != mat2(2, 0, 0, 2)) return false;

    return true;
  });
  auto mm_add2 = UnitTest("matrix matrix assignment operator += (2)", +[] {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 n = mat3(9, 8, 7, 6, 5, 4, 3, 2, 1);

    m += n;
    if (m != 10) return false;

    return true;
  });
  auto mm_add3 = UnitTest("matrix matrix assignment operator += (3)", +[] {
    mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    mat4 n = mat4(16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
    mat4 i = mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

    m += i;
    if (m != mat4(2, 2, 3, 4, 5, 7, 7, 8, 9, 10, 12, 12, 13, 14, 15, 17)) return false;

    i += n;
    if (i != mat4(17, 15, 14, 13, 12, 12, 10, 9, 8, 7, 7, 5, 4, 3, 2, 2)) return false;

    return true;
  });

  auto ms_sub1 = UnitTest("matrix scalar assignment operator -= (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    m -= 1;
    if (m != mat2(0, 1, 2, 3)) return false;
    m -= 1.f;
    if (m != mat2(-1, 0, 1, 2)) return false;
    m -= 1.0;
    if (m != mat2(-2, -1, 0, 1)) return false;

    n -= 4;
    if (n != mat3(-3, -2, -1, 0, 1, 2, 3, 4, 5)) return false;
    n -= 1.f;
    if (n != mat3(-4, -3, -2, -1, 0, 1, 2, 3, 4)) return false;
    n -= 1.0;
    if (n != mat3(-5, -4, -3, -2, -1, 0, 1, 2, 3)) return false;

    o -= 7;
    if (o != mat4(-6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9)) return false;
    o -= 1.f;
    if (o != mat4(-7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8)) return false;
    o -= 1.0;
    if (o != mat4(-8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7)) return false;

    return true;
  });
  auto ms_sub2 = UnitTest("matrix scalar assignment operator -= (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    m -= 1;
    if (m != mat2x4(0, 1, 2, 3, 4, 5, 6, 7)) return false;
    m -= 1.f;
    if (m != mat2x4(-1, 0, 1, 2, 3, 4, 5, 6)) return false;
    m -= 1.f;
    if (m != mat2x4(-2, -1, 0, 1, 2, 3, 4, 5)) return false;

    n -= 4;
    if (n != mat4x2(-3, -2, -1, 0, 1, 2, 3, 4)) return false;
    n -= 1.f;
    if (n != mat4x2(-4, -3, -2, -1, 0, 1, 2, 3)) return false;
    n -= 1.0;
    if (n != mat4x2(-5, -4, -3, -2, -1, 0, 1, 2)) return false;

    return true;
  });
  auto mm_sub1 = UnitTest("matrix matrix assignment operator -= (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat2 n = mat2(4, 3, 2, 1);
    mat2 i = mat2(1, 0, 0, 1);

    m -= m;
    if (m != mat2(0, 0, 0, 0)) return false;
    n -= n;
    if (n != mat2(0, 0, 0, 0)) return false;
    i -= i;
    if (i != mat2(0, 0, 0, 0)) return false;

    return true;
  });
  auto mm_sub2 = UnitTest("matrix matrix assignment operator -= (2)", +[] {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 n = mat3(9, 8, 7, 6, 5, 4, 3, 2, 1);

    m -= n;
    if (m != mat3(-8, -6, -4, -2, 0, 2, 4, 6, 8)) return false;

    return true;
  });
  auto mm_sub3 = UnitTest("matrix matrix assignment operator -= (3)", +[] {
    mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    mat4 n = mat4(16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
    mat4 i = mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

    m -= i;
    if (m != mat4(0, 2, 3, 4, 5, 5, 7, 8, 9, 10, 10, 12, 13, 14, 15, 15)) return false;

    i -= n;
    if (i != mat4(-15, -15, -14, -13, -12, -10, -10, -9, -8, -7, -5, -5, -4, -3, -2, 0)) return false;

    return true;
  });

  auto ms_mult1 = UnitTest("matrix scalar assignment operator *= (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    m *= 1;
    if (m != mat2(1, 2, 3, 4)) return false;
    m *= 2.f;
    if (m != mat2(2, 4, 6, 8)) return false;

    n *= 1;
    if (n != mat3(1, 2, 3, 4, 5, 6, 7, 8, 9)) return false;
    n *= 4.0;
    if (n != mat3(4, 8, 12, 16, 20, 24, 28, 32, 36)) return false;

    o *= 1.f;
    if (o != mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)) return false;
    o *= 7;
    if (o != mat4(7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112)) return false;

    return true;
  });
  auto ms_mult2 = UnitTest("matrix scalar assignment operator *= (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    m *= 1;
    if (m != mat2x4(1, 2, 3, 4, 5, 6, 7, 8)) return false;
    m *= 2.f;
    if (m != mat2x4(2, 4, 6, 8, 10, 12, 14, 16)) return false;

    n *= 1;
    if (n != mat4x2(1, 2, 3, 4, 5, 6, 7, 8)) return false;
    n *= 4.0;
    if (n != mat4x2(4, 8, 12, 16, 20, 24, 28, 32)) return false;

    return true;
  });
  auto mm_mult1 = UnitTest("matrix matrix assignment operator *= (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    m *= m;
    if (m != mat2(7, 10, 15, 22)) return false;

    n *= n;
    if (n != mat3(30, 36, 42, 66, 81, 96, 102, 126, 150)) return false;

    o *= o;
    if (o != mat4x4(90, 100, 110, 120, 202, 228, 254, 280, 314, 356, 398, 440, 426, 484, 542, 600)) return false;

    return true;
  });
  auto mm_mult2 = UnitTest("matrix matrix assignment operator *= (2)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat2 n = mat2(-2, 1, 1.5, -0.5);
    mat2 i = mat2(1, 0, 0, 1);

    m *= n;
    if (m != i) return false;

    return true;
  });
  auto mm_mult3 = UnitTest("matrix matrix assignment operator *= (3)", +[] {
    mat4 t1 = mat4(1, 0, 0, 2, 0, 1, 0, 2, 0, 0, 1, 0, 0, 0, 0, 1);
    mat4 t2 = t1;
    mat4 s1 = mat4(3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1);
    mat4 s2 = s1;

    t1 *= s1;
    if (t1 != mat4(3, 0, 0, 2, 0, 3, 0, 2, 0, 0, 3, 0, 0, 0, 0, 1)) return false;

    s2 *= t2;
    if (s2 != mat4(3, 0, 0, 6, 0, 3, 0, 6, 0, 0, 3, 0, 0, 0, 0, 1)) return false;

    return true;
  });

  auto ms_div1 = UnitTest("matrix scalar assignment operator /= (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat2 t;

    t = mat2(1, 2, 3, 4);
    t /= 1;
    if (t != m) return false;

    t = mat2(2, 4, 6, 8);
    t /= 2.f;
    if (t != m) return false;

    t = mat2(3, 6, 9, 12);
    t /= 3.0;
    if (t != m) return false;

    return true;
  });
}
