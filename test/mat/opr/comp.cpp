#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto m_lt = UnitTest("matrix operator <", +[] {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 n = mat3(0, 1, 2, 3, 4, 5, 6, 7, 8);

    if (!(0 < m)) return false;
    if (!(m < 10)) return false;
    if (!(n < m)) return false;

    return true;
  });

  auto m_le = UnitTest("matrix operator <=", +[] {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 n = mat3(0, 2, 3, 3, 5, 5, 6, 8, 8);

    if (!(1 <= m)) return false;
    if (!(m <= 9)) return false;
    if (!(n <= m)) return false;

    return true;
  });

  auto m_ge = UnitTest("matrix operator >=", +[] {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 n = mat3(0, 2, 3, 3, 5, 5, 6, 8, 8);

    if (!(9 >= m)) return false;
    if (!(m >= 1)) return false;
    if (!(m >= n)) return false;

    return true;
  });

  auto m_gt = UnitTest("matrix operator >", +[] {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 n = mat3(0, 1, 2, 3, 4, 5, 6, 7, 8);

    if (!(10 > m)) return false;
    if (!(m > 0)) return false;
    if (!(m > n)) return false;

    return true;
  });

  auto m_eq = UnitTest("matrix operator ==", +[] {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 o = mat3(3, 3, 3, 3, 3, 3, 3, 3, 3);

    if (!(3 == o)) return false;
    if (!(o == 3)) return false;
    if (!(m == n)) return false;

    return true;
  });

  auto m_ne = UnitTest("matrix operator !=", +[] {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 n = mat3(9, 8, 7, 6, 5, 4, 3, 2, 1);

    if (!(0 != m)) return false;
    if (!(m != 3)) return false;
    if (!(m != n)) return false;

    return true;
  });
}
