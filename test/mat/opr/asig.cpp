#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto m_add = UnitTest("matrix assignment operator +=", +[] {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 n = mat3(0, 0, 0, 1, 1, 1, 2, 2, 2);

    m += 1;
    if (m != mat3(2, 3, 4, 5, 6, 7, 8, 9, 10)) return false;

    m += 2.0;
    if (m != mat3(4, 5, 6, 7, 8, 9, 10, 11, 12)) return false;

    m += n;
    if (m != mat3(4, 5, 6, 8, 9, 10, 12, 13, 14)) return false;

    return true;
  });

  auto m_sub = UnitTest("matrix assignment operator -=", +[] {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 n = mat3(0, 0, 0, 1, 1, 1, 2, 2, 2);

    m -= 1;
    if (m != mat3(0, 1, 2, 3, 4, 5, 6, 7, 8)) return false;

    m -= 2.0;
    if (m != mat3(-2, -1, 0, 1, 2, 3, 4, 5, 6)) return false;

    m -= n;
    if (m != mat3(-2, -1, 0, 0, 1, 2, 2, 3, 4)) return false;

    return true;
  });

  auto m_mult = UnitTest("matrix assignment operator *=", +[] {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 n = mat3(1, 0, 0, 0, 1, 0, 2, 2, 1);

    m *= 2;
    if (m != mat3(2, 4, 6, 8, 10, 12, 14, 16, 18)) return false;

    m *= 2.0;
    if (m != mat3(4, 8, 12, 16, 20, 24, 28, 32, 36)) return false;

    m *= n;
    if (m != mat3(4, 8, 12, 16, 20, 24, 68, 88, 108)) return false;

    return true;
  });

  auto m_div = UnitTest("matrix assignment operator /=", +[] {
    mat3 m = mat3(4, 8, 12, 16, 20, 24, 56, 64, 72);
    mat3 n = mat3(-1, -1, -1, 1, 1, 1, 2, 2, 2);

    m /= 2;
    if (m != mat3(2, 4, 6, 8, 10, 12, 28, 32, 36)) return false;

    m /= 2.0;
    if (m != mat3(1, 2, 3, 4, 5, 6, 14, 16, 18)) return false;

    m /= n;
    if (m != mat3(-1, -2, -3, 4, 5, 6, 7, 8, 9)) return false;

    return true;
  });
}
