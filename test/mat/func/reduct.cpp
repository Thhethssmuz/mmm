#include <unittest.hpp>
#include <mmm.hpp>

namespace {

  auto trs1 = UnitTest("matrix reduction function takeRows (1)", +[] {
    mat3 m = mat3(1, 4, 7, 2, 5, 8, 3, 6, 9);

    mat3 n = takeRows<3>(m);
    if (n != m) return false;

    mat3x2 o = takeRows<2>(m);
    if (o != mat3x2(1, 4, 2, 5, 3, 6)) return false;

    vec3 v = takeRows<1>(m);
    if (v != vec3(1, 2, 3)) return false;

    v = takeRows<1>(o);
    if (v != vec3(1, 2, 3)) return false;

    return true;
  });
  auto trs2 = UnitTest("matrix reduction function takeRows (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

    mat2x4 n = takeRows<4>(m);
    if (m != n) return false;

    mat2x3 o = takeRows<3>(m);
    if (o != mat2x3(1, 2, 3, 5, 6, 7)) return false;

    mat2 p = takeRows<2>(m);
    if (p != mat2(1, 2, 5, 6)) return false;

    vec2 v = takeRows<1>(m);
    if (v != vec2(1, 5)) return false;

    vec2 u = takeRows<1>(p);
    if (u != v) return false;

    return true;
  });

  auto drs1 = UnitTest("matrix reduction function dropRows (1)", +[] {
    mat4 m = mat4(1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 16);

    mat4 n = dropRows<0>(m);
    if (n != m) return false;

    mat4x3 o = dropRows<1>(m);
    if (o != mat4x3(5, 9, 13, 6, 10, 14, 7, 11, 15, 8, 12, 16)) return false;

    mat4x2 p = dropRows<2>(m);
    if (p != mat4x2(9, 13, 10, 14, 11, 15, 12, 16)) return false;

    vec4 v = dropRows<3>(m);
    if (v != vec4(13, 14, 15, 16)) return false;

    vec4 u = dropRows<1>(p);
    if (u != v) return false;

    return true;
  });
  auto drs2 = UnitTest("matrix reduction function dropRows (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

    mat2x4 n = dropRows<0>(m);
    if (n != m) return false;

    mat2x3 o = dropRows<1>(m);
    if (o != mat2x3(2, 3, 4, 6, 7, 8)) return false;

    mat2 p = dropRows<2>(m);
    if (p != mat2(3, 4, 7, 8)) return false;

    vec2 v = dropRows<3>(m);
    if (v != vec2(4, 8)) return false;

    vec2 u = dropRows<1>(p);
    if (u != v) return false;

    return true;
  });

  auto tcs1 = UnitTest("matrix reduction function takeColumns (1)", +[] {
    mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    mat4 n = takeColumns<4>(m);
    if (n != m) return false;

    mat3x4 o = takeColumns<3>(m);
    if (o != mat3x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)) return false;

    mat2x4 p = takeColumns<2>(m);
    if (p != mat2x4(1, 2, 3, 4, 5, 6, 7, 8)) return false;

    vec4 v = takeColumns<1>(m);
    if (v != vec4(1, 2, 3, 4)) return false;

    vec4 u = takeColumns<1>(p);
    if (u != v) return false;

    return true;
  });
  auto tcs2 = UnitTest("matrix reduction function takeColumns (2)", +[] {
    mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    mat4x2 n = takeColumns<4>(m);
    if (m != n) return false;

    mat3x2 o = takeColumns<3>(m);
    if (o != mat3x2(1, 2, 3, 4, 5, 6)) return false;

    mat2 p = takeColumns<2>(m);
    if (p != mat2(1, 2, 3, 4)) return false;

    vec2 v = takeColumns<1>(m);
    if (v != vec2(1, 2)) return false;

    vec2 u = takeColumns<1>(p);
    if (u != v) return false;

    return true;
  });

  auto dcs1 = UnitTest("matrix reduction function dropColumns (1)", +[] {
    mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    mat4 n = dropColumns<0>(m);
    if (n != m) return false;

    mat3x4 o = dropColumns<1>(m);
    if (o != mat3x4(5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)) return false;

    mat2x4 p = dropColumns<2>(m);
    if (p != mat2x4(9, 10, 11, 12, 13, 14, 15, 16)) return false;

    vec4 v = dropColumns<3>(m);
    if (v != vec4(13, 14, 15, 16)) return false;

    vec4 u = dropColumns<1>(p);
    if (u != v) return false;

    return true;
  });
  auto dcs2 = UnitTest("matrix reduction function dropColumns (2)", +[] {
    mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    mat4x2 n = dropColumns<0>(m);
    if (m != n) return false;

    mat3x2 o = dropColumns<1>(m);
    if (o != mat3x2(3, 4, 5, 6, 7, 8)) return false;

    mat2 p = dropColumns<2>(m);
    if (p != mat2(5, 6, 7, 8)) return false;

    vec2 v = dropColumns<3>(m);
    if (v != vec2(7, 8)) return false;

    vec2 u = dropColumns<1>(p);
    if (u != v) return false;

    return true;
  });
}
