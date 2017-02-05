#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto apr1 = UnitTest("matrix enlargement function appendRow (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

    if (appendRow(m, vec2(5, 6)) != mat2x3(1, 2, 3, 4, 5, 6)) return false;
    if (appendRow(n, vec3(10, 11, 12)) != mat3x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)) return false;

    return true;
  });
  auto apr2 = UnitTest("matrix enlargement function appendRow (2)", +[] {
    mat2x3 m = mat2x3(1, 2, 3, 4, 5, 6);
    mat3x2 n = mat3x2(1, 2, 3, 4, 5, 6);

    if (appendRow(m, vec2(7, 8)) != mat2x4(1, 2, 3, 4, 5, 6, 7, 8)) return false;
    if (appendRow(n, vec3(7, 8, 9)) != mat3x3(1, 2, 3, 4, 5, 6, 7, 8, 9)) return false;

    return true;
  });

  auto apc1 = UnitTest("matrix enlargement function appendColumn (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

    if (appendColumn(m, vec2(5, 6)) != mat3x2(1, 2, 5, 3, 4, 6)) return false;
    if (appendColumn(n, vec3(10, 11, 12)) != mat4x3(1, 2, 3, 10, 4, 5, 6, 11, 7, 8, 9, 12)) return false;

    return true;
  });
  auto apc2 = UnitTest("matrix enlargement function appendColumn (2)", +[] {
    mat2x3 m = mat2x3(1, 2, 3, 4, 5, 6);
    mat3x2 n = mat3x2(1, 2, 3, 4, 5, 6);

    if (appendColumn(m, vec3(7, 8, 9)) != mat3x3(1, 2, 7, 3, 4, 8, 5, 6, 9)) return false;
    if (appendColumn(n, vec2(7, 8)) != mat4x2(1, 2, 3, 7, 4, 5, 6, 8)) return false;

    return true;
  });
}
