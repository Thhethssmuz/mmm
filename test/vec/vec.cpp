#include <unittest.hpp>
#include <mmm.hpp>

namespace {

  auto constructors_1 = UnitTest("vector constructors 1", +[] {
    vec4 v;
    vec4 u(0);
    vec4 t{0};
    vec4 s = vec4();
    vec4 r = vec4(0);

    if (v != u) return false;
    if (u != t) return false;
    if (t != s) return false;
    if (s != r) return false;
    if (r != 0) return false;

    return true;
  });
  auto constructors_2 = UnitTest("vector constructors 2", +[] {
    vec2 v = vec2(3, 4);
    vec3 u = vec3(2, v);
    vec4 t = vec4(1, u);

    if (t != vec4(1, 2, 3, 4)) return false;

    return true;
  });
  auto constructors_3 = UnitTest("vector constructors 3", +[] {
    vec2 v = vec2(1, 2);
    vec2 u = vec2(3, 4);
    vec4 t = vec4(v, u);

    vec<10> s = vec<10>(0, t, u + 2, v + 6, 9);

    if (s != vec<10>(0, 1, 2, 3, 4, 5, 6, 7, 8, 9)) return false;

    return true;
  });
  auto constructors_4 = UnitTest("vector constructors 4", +[] {
    vec4 v = vec4(8, 7, 6, 1);
    vec4 u = vec4(2, 3, 5, 4);
    vec4 t = vec4(12, 10, 11, 13);
    vec4 s = vec4(0);

    vec<15> r = vec<15>(s.x, v.w, u.xywz, v.zyx, 9, t.yzxw, 14);

    if (r != vec<15>(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14))
      return false;

    return true;
  });

  auto index = UnitTest("vector index", +[] {
    vec4 v = vec4(1, 2, 3, 4);

    float& x = v[0];
    x = 0;
    if (v[0] != 0) return false;

    float y = v[1];
    y = 73;
    if (v[1] != 2) return false;

    v[2] = 12;
    if (v[2] != 12) return false;

    v.data[3] = -1;
    if (v[3] != -1) return false;

    return true;
  });

  auto array_cast = UnitTest("vector array_cast", +[] {
    ivec4 v = ivec4(8, 7, 6, 5);
    int* i = v;

    if (i[0] != 8 and i[1] != 7 and i[2] != 6 and i[3] != 5) return false;

    return true;
  });

  auto swiz_elems = UnitTest("vector swizzleElems", +[] {
    ivec<9> v = ivec<9>(0, 1, 2, 10, 11, 12, 20, 21, 22);

    ivec3 u = v.swizzleElems<3, 4, 5>() += 100;
    if (u != ivec3(110, 111, 112)) return false;
    if (v != ivec<9>(0, 1, 2, 110, 111, 112, 20, 21, 22)) return false;

    return true;
  });
  auto swiz_range1 = UnitTest("vector swizzleRange positive", +[] {
    ivec<9> v = ivec<9>(0, 1, 2, 10, 11, 12, 20, 21, 22);

    auto& u = v.swizzleRange<3, 5>();
    if (u != ivec3(10, 11, 12)) return false;

    u += 100;
    if (u != ivec3(110, 111, 112)) return false;

    if (v != ivec<9>(0, 1, 2, 110, 111, 112, 20, 21, 22)) return false;

    return true;
  });
  auto swiz_range2 = UnitTest("vector swizzleRange negative", +[] {
    ivec<9> v = ivec<9>(0, 1, 2, 10, 11, 12, 20, 21, 22);

    auto& u = v.swizzleRange<5, 3>();
    if (u != ivec3(12, 11, 10)) return false;

    u += 100;
    if (u != ivec3(112, 111, 110)) return false;

    if (v != ivec<9>(0, 1, 2, 110, 111, 112, 20, 21, 22)) return false;

    return true;
  });
}
