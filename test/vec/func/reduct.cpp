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
}
