#include <unittest.hpp>
#include <mmm.hpp>

namespace {

  auto v_sum = UnitTest("vector reduction function sum", +[]() {
    vec4 v = vec4(1, 2, 3, 4);
    ivec4 u = ivec4(1, 2, 3, 4);
    dvec4 t = dvec4(1, 2, 3, 4);

    if (sum(v) != 10 and sum(v.wzyx) != 10) return false;
    if (sum(u) != 10 and sum(u.wzyx) != 10) return false;
    if (sum(t) != 10 and sum(t.wzyx) != 10) return false;

    return true;
  });

  auto v_product = UnitTest("vector reduction function product", +[]() {
    vec4 v = vec4(1, 2, 3, 4);
    ivec4 u = ivec4(1, 2, 3, 4);
    dvec4 t = dvec4(1, 2, 3, 4);

    if (product(v) != 24 and product(v.wzyx) != 24) return false;
    if (product(u) != 24 and product(u.wzyx) != 24) return false;
    if (product(t) != 24 and product(t.wzyx) != 24) return false;

    return true;
  });

  auto v_take = UnitTest("vector reduction function take", +[]() {
    vec<6> v = vec<6>(1, 2, 3, 4, 5, 6);

    float x = take<1>(v);
    if (x != 1) return false;

    vec2 u = take<2>(v);
    if (u != vec2(1, 2)) return false;

    vec3 t = take<3>(v);
    if (t != vec3(1, 2, 3)) return false;

    vec4 s = take<4>(v.xyzw);
    if (s != vec4(1, 2, 3, 4)) return false;

    vec<5> r = take<5>(v);
    if (r != vec<5>(1, 2, 3, 4, 5)) return false;

    vec<6> q = take<6>(v);
    if (q != vec<6>(1, 2, 3, 4, 5, 6)) return false;


    return true;
  });

  auto v_drop = UnitTest("vector reduction function drop", +[]() {
    vec<6> v = vec<6>(1, 2, 3, 4, 5, 6);

    vec<6> u = drop<0>(v);
    if (u != vec<6>(1, 2, 3, 4, 5, 6)) return false;

    vec<5> t = drop<1>(v);
    if (t != vec<5>(2, 3, 4, 5, 6)) return false;

    vec3 s = drop<3>(v);
    if (s != vec3(4, 5, 6)) return false;

    vec2 r = drop<4>(v);
    if (r != vec2(5, 6)) return false;

    vec2 q = drop<2>(v.xyzw);
    if (q != vec2(3, 4)) return false;

    float x = drop<5>(v);
    if (x != 6) return false;

    x = drop<1>(v.xy);
    if (x != 2) return false;

    return true;
  });
}
