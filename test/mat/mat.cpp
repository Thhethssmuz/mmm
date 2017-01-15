#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto constructors_1 = UnitTest("matrix constructors 1", +[] {
    mat4 m;
    mat4 n(0);
    mat4 o{0};
    mat4 p = mat4();
    mat4 q = mat4(0);

    if (m != n) return false;
    if (n != o) return false;
    if (o != p) return false;
    if (p != q) return false;
    if (q != 0) return false;

    return true;
  });
  auto constructors_2 = UnitTest("matrix constructors 2", +[] {
    mat2x4 m = mat2x4(3, 7, 11, 15, 4, 8, 12, 16);
    mat3x4 n = mat3x4(vec4(2, 6, 10, 14), m);
    mat4x4 o = mat4x4(vec4(1, 5, 9, 13), n);

    mat4 p = mat4(1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 16);

    if (o != p) return false;

    return true;
  });
  auto constructors_3 = UnitTest("matrix constructors 3", +[] {
    vec2 v = vec2(1, 2);
    vec4 u = vec4(5, 6, 7, 8);
    vec4 t = vec4(3, 4, 11, 10);
    vec4 s = vec4(14, 16, 15, 17);

    mat4 m = mat4(v, t.xy, u, 9, t.wz, 12, 13, s.xzy);
    mat4 n = mat4(v, t.xy, u, 9, t.wz, 12, 13, s.xzyw);

    mat4 o = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    if (m != o) return false;
    if (n != o) return false;

    return true;
  });
  auto constructors_4 = UnitTest("matrix constructors 4", +[] {
    vec2 v = vec2(1, 2);
    vec2 u = vec2(3, 4);

    mat2 m = mat2(v, u);
    if (m != mat2(1, 2, 3, 4)) return false;

    m = mat2(v.xy, u.xy);
    if (m != mat2(1, 2, 3, 4)) return false;

    m = mat2(u.x, u.x, u.yyyy);
    if (m != mat2(3, 3, 4, 4)) return false;

    m = mat2(1, 1, 2, 2, 2);
    if (m != mat2(1, 1, 2, 2)) return false;

    m = mat2(vec4(v, u));
    if (m != mat2(1, 2, 3, 4)) return false;

    return true;
  });

  auto t_array = UnitTest("matrix operator T*", +[] {
    mat2 m = mat2(1, 2, 3, 4);
    float* xs = m;

    if (xs[0] != 1) return false;
    if (xs[1] != 2) return false;
    if (xs[2] != 3) return false;
    if (xs[3] != 4) return false;

    return true;
  });
}
