#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto tr1 = UnitTest("matrix reduction function takeRow (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (takeRow<0>(m) != vec2(1, 2)) return false;
    if (takeRow<1>(m) != vec2(3, 4)) return false;

    if (takeRow<0>(n) != vec3(1, 2, 3)) return false;
    if (takeRow<1>(n) != vec3(4, 5, 6)) return false;
    if (takeRow<2>(n) != vec3(7, 8, 9)) return false;

    if (takeRow<0>(o) != vec4(1, 2, 3, 4)) return false;
    if (takeRow<1>(o) != vec4(5, 6, 7, 8)) return false;
    if (takeRow<2>(o) != vec4(9, 10, 11, 12)) return false;
    if (takeRow<3>(o) != vec4(13, 14, 15, 16)) return false;

    return true;
  });
  auto tr2 = UnitTest("matrix reduction function takeRow (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    if (takeRow<0>(m) != vec2(1, 2)) return false;
    if (takeRow<1>(m) != vec2(3, 4)) return false;
    if (takeRow<2>(m) != vec2(5, 6)) return false;
    if (takeRow<3>(m) != vec2(7, 8)) return false;

    if (takeRow<0>(n) != vec4(1, 2, 3, 4)) return false;
    if (takeRow<1>(n) != vec4(5, 6, 7, 8)) return false;

    return true;
  });

  auto trs1 = UnitTest("matrix reduction function takeRows (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (takeRows<1>(m) != vec2(1, 2)) return false;
    if (takeRows<2>(m) != mat2(1, 2, 3, 4)) return false;

    if (takeRows<1>(n) != vec3(1, 2, 3)) return false;
    if (takeRows<2>(n) != mat3x2(1, 2, 3, 4, 5, 6)) return false;
    if (takeRows<3>(n) != mat3(1, 2, 3, 4, 5, 6, 7, 8, 9)) return false;

    if (takeRows<1>(o) != vec4(1, 2, 3, 4)) return false;
    if (takeRows<2>(o) != mat4x2(1, 2, 3, 4, 5, 6, 7, 8)) return false;
    if (takeRows<3>(o) != mat4x3(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)) return false;
    if (takeRows<4>(o) != mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)) return false;

    return true;
  });
  auto trs2 = UnitTest("matrix reduction function takeRows (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    if (takeRows<1>(m) != vec2(1, 2)) return false;
    if (takeRows<2>(m) != mat2(1, 2, 3, 4)) return false;
    if (takeRows<3>(m) != mat2x3(1, 2, 3, 4, 5, 6)) return false;
    if (takeRows<4>(m) != mat2x4(1, 2, 3, 4, 5, 6, 7, 8)) return false;

    if (takeRows<1>(n) != vec4(1, 2, 3, 4)) return false;
    if (takeRows<2>(n) != mat4x2(1, 2, 3, 4, 5, 6, 7, 8)) return false;

    return true;
  });

  auto dr1 = UnitTest("matrix reduction function dropRow (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (dropRow<0>(m) != vec2(3, 4)) return false;
    if (dropRow<1>(m) != vec2(1, 2)) return false;

    if (dropRow<0>(n) != mat3x2(4, 5, 6, 7, 8, 9)) return false;
    if (dropRow<1>(n) != mat3x2(1, 2, 3, 7, 8, 9)) return false;
    if (dropRow<2>(n) != mat3x2(1, 2, 3, 4, 5, 6)) return false;

    if (dropRow<0>(o) != mat4x3(5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)) return false;
    if (dropRow<1>(o) != mat4x3(1, 2, 3, 4, 9, 10, 11, 12, 13, 14, 15, 16)) return false;
    if (dropRow<2>(o) != mat4x3(1, 2, 3, 4, 5, 6, 7, 8, 13, 14, 15, 16)) return false;
    if (dropRow<3>(o) != mat4x3(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)) return false;

    return true;
  });
  auto dr2 = UnitTest("matrix reduction function dropRow (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    if (dropRow<0>(m) != mat2x3(3, 4, 5, 6, 7, 8)) return false;
    if (dropRow<1>(m) != mat2x3(1, 2, 5, 6, 7, 8)) return false;
    if (dropRow<2>(m) != mat2x3(1, 2, 3, 4, 7, 8)) return false;
    if (dropRow<3>(m) != mat2x3(1, 2, 3, 4, 5, 6)) return false;

    if (dropRow<0>(n) != vec4(5, 6, 7, 8)) return false;
    if (dropRow<1>(n) != vec4(1, 2, 3, 4)) return false;

    return true;
  });

  auto drs1 = UnitTest("matrix reduction function dropRows (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (dropRows<0>(m) != mat2(1, 2, 3, 4)) return false;
    if (dropRows<1>(m) != vec2(3, 4)) return false;

    if (dropRows<0>(n) != mat3(1, 2, 3, 4, 5, 6, 7, 8, 9)) return false;
    if (dropRows<1>(n) != mat3x2(4, 5, 6, 7, 8, 9)) return false;
    if (dropRows<2>(n) != vec3(7, 8, 9)) return false;

    if (dropRows<0>(o) != mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)) return false;
    if (dropRows<1>(o) != mat4x3(5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)) return false;
    if (dropRows<2>(o) != mat4x2(9, 10, 11, 12, 13, 14, 15, 16)) return false;
    if (dropRows<3>(o) != vec4(13, 14, 15, 16)) return false;

    return true;
  });
  auto drs2 = UnitTest("matrix reduction function dropRows (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    if (dropRows<0>(m) != mat2x4(1, 2, 3, 4, 5, 6, 7, 8)) return false;
    if (dropRows<1>(m) != mat2x3(3, 4, 5, 6, 7, 8)) return false;
    if (dropRows<2>(m) != mat2(5, 6, 7, 8)) return false;
    if (dropRows<3>(m) != vec2(7, 8)) return false;

    if (dropRows<0>(n) != mat4x2(1, 2, 3, 4, 5, 6, 7, 8)) return false;
    if (dropRows<1>(n) != vec4(5, 6, 7, 8)) return false;

    return true;
  });

  auto tc1 = UnitTest("matrix reduction function takeColumn (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (takeColumn<0>(m) != vec2(1, 3)) return false;
    if (takeColumn<1>(m) != vec2(2, 4)) return false;

    if (takeColumn<0>(n) != vec3(1, 4, 7)) return false;
    if (takeColumn<1>(n) != vec3(2, 5, 8)) return false;
    if (takeColumn<2>(n) != vec3(3, 6, 9)) return false;

    if (takeColumn<0>(o) != vec4(1, 5, 9, 13)) return false;
    if (takeColumn<1>(o) != vec4(2, 6, 10, 14)) return false;
    if (takeColumn<2>(o) != vec4(3, 7, 11, 15)) return false;
    if (takeColumn<3>(o) != vec4(4, 8, 12, 16)) return false;

    return true;
  });
  auto tc2 = UnitTest("matrix reduction function takeColumn (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    if (takeColumn<0>(m) != vec4(1, 3, 5, 7)) return false;
    if (takeColumn<1>(m) != vec4(2, 4, 6, 8)) return false;

    if (takeColumn<0>(n) != vec2(1, 5)) return false;
    if (takeColumn<1>(n) != vec2(2, 6)) return false;
    if (takeColumn<2>(n) != vec2(3, 7)) return false;
    if (takeColumn<3>(n) != vec2(4, 8)) return false;

    return true;
  });

  auto tcs1 = UnitTest("matrix reduction function takeColumns (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (takeColumns<1>(m) != vec2(1, 3)) return false;
    if (takeColumns<2>(m) != mat2(1, 2, 3, 4)) return false;

    if (takeColumns<1>(n) != vec3(1, 4, 7)) return false;
    if (takeColumns<2>(n) != mat2x3(1, 2, 4, 5, 7, 8)) return false;
    if (takeColumns<3>(n) != mat3(1, 2, 3, 4, 5, 6, 7, 8, 9)) return false;

    if (takeColumns<1>(o) != vec4(1, 5, 9, 13)) return false;
    if (takeColumns<2>(o) != mat2x4(1, 2, 5, 6, 9, 10, 13, 14)) return false;
    if (takeColumns<3>(o) != mat3x4(1, 2, 3, 5, 6, 7, 9, 10, 11, 13, 14, 15)) return false;
    if (takeColumns<4>(o) != mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)) return false;

    return true;
  });
  auto tcs2 = UnitTest("matrix reduction function takeColumns (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    if (takeColumns<1>(m) != vec4(1, 3, 5, 7)) return false;
    if (takeColumns<2>(m) != mat2x4(1, 2, 3, 4, 5, 6, 7, 8)) return false;

    if (takeColumns<1>(n) != vec2(1, 5)) return false;
    if (takeColumns<2>(n) != mat2(1, 2, 5, 6)) return false;
    if (takeColumns<3>(n) != mat3x2(1, 2, 3, 5, 6, 7)) return false;
    if (takeColumns<4>(n) != mat4x2(1, 2, 3, 4, 5, 6, 7, 8)) return false;

    return true;
  });

  auto dc1 = UnitTest("matrix reduction function dropColumn (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (dropColumn<0>(m) != vec2(2, 4)) return false;
    if (dropColumn<1>(m) != vec2(1, 3)) return false;

    if (dropColumn<0>(n) != mat2x3(2, 3, 5, 6, 8, 9)) return false;
    if (dropColumn<1>(n) != mat2x3(1, 3, 4, 6, 7, 9)) return false;
    if (dropColumn<2>(n) != mat2x3(1, 2, 4, 5, 7, 8)) return false;

    if (dropColumn<0>(o) != mat3x4(2, 3, 4, 6, 7, 8, 10, 11, 12, 14, 15, 16)) return false;
    if (dropColumn<1>(o) != mat3x4(1, 3, 4, 5, 7, 8, 9, 11, 12, 13, 15, 16)) return false;
    if (dropColumn<2>(o) != mat3x4(1, 2, 4, 5, 6, 8, 9, 10, 12, 13, 14, 16)) return false;
    if (dropColumn<3>(o) != mat3x4(1, 2, 3, 5, 6, 7, 9, 10, 11, 13, 14, 15)) return false;

    return true;
  });
  auto dc2 = UnitTest("matrix reduction function dropColumn (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    if (dropColumn<0>(m) != vec4(2, 4, 6, 8)) return false;
    if (dropColumn<1>(m) != vec4(1, 3, 5, 7)) return false;

    if (dropColumn<0>(n) != mat3x2(2, 3, 4, 6, 7, 8)) return false;
    if (dropColumn<1>(n) != mat3x2(1, 3, 4, 5, 7, 8)) return false;
    if (dropColumn<2>(n) != mat3x2(1, 2, 4, 5, 6, 8)) return false;
    if (dropColumn<3>(n) != mat3x2(1, 2, 3, 5, 6, 7)) return false;

    return true;
  });

  auto dcs1 = UnitTest("matrix reduction function dropColumns (1)", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (dropColumns<0>(m) != mat2(1, 2, 3, 4)) return false;
    if (dropColumns<1>(m) != vec2(2, 4)) return false;

    if (dropColumns<0>(n) != mat3(1, 2, 3, 4, 5, 6, 7, 8, 9)) return false;
    if (dropColumns<1>(n) != mat2x3(2, 3, 5, 6, 8, 9)) return false;
    if (dropColumns<2>(n) != vec3(3, 6, 9)) return false;

    if (dropColumns<0>(o) != mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)) return false;
    if (dropColumns<1>(o) != mat3x4(2, 3, 4, 6, 7, 8, 10, 11, 12, 14, 15, 16)) return false;
    if (dropColumns<2>(o) != mat2x4(3, 4, 7, 8, 11, 12, 15, 16)) return false;
    if (dropColumns<3>(o) != vec4(4, 8, 12, 16)) return false;

    return true;
  });
  auto dcs2 = UnitTest("matrix reduction function dropColumns (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    mat4x2 n = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    if (dropColumns<0>(m) != mat2x4(1, 2, 3, 4, 5, 6, 7, 8)) return false;
    if (dropColumns<1>(m) != vec4(2, 4, 6, 8)) return false;

    if (dropColumns<0>(n) != mat4x2(1, 2, 3, 4, 5, 6, 7, 8)) return false;
    if (dropColumns<1>(n) != mat3x2(2, 3, 4, 6, 7, 8)) return false;
    if (dropColumns<2>(n) != mat2(3, 4, 7, 8)) return false;
    if (dropColumns<3>(n) != vec2(4, 8)) return false;

    return true;
  });
}
