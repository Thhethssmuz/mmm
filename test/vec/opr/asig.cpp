#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto asig1 = UnitTest("vector assignment operator +=", +[] {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(2, 3, 4);

    v += 1;
    v += 2.f;
    v += 3.0;
    v += 4.l;
    v += u;
    v += u.zyx;

    return v == vec3(17, 18, 19);
  });

  auto asig2 = UnitTest("vector assignment operator -=", +[] {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(2, 3, 4);

    v -= 1;
    v -= 2.f;
    v -= 3.0;
    v -= 4.l;
    v -= u;
    v -= u.zyx;

    return v == vec3(-15, -14, -13);
  });

  auto asig3 = UnitTest("vector assignment operator *=", +[] {
    vec3 v = vec3(1, 2, 3);
    vec3 u = vec3(2, 3, 4);

    v *= 1;
    v *= 2.f;
    v *= 3.0;
    v *= 4.l;
    v *= u;
    v *= u.zyx;

    return v == vec3(192, 432, 576);
  });

  auto asig4 = UnitTest("vector assignment operator /=", +[] {
    vec3 v = vec3(192, 432, 576);
    vec3 u = vec3(2, 3, 4);

    v /= 1;
    v /= 2.f;
    v /= 3.0;
    v /= 4.l;
    v /= u;
    v /= u.zyx;

    return v == vec3(1, 2, 3);
  });

  auto asig5 = UnitTest("vector assignment operator =", +[] {
    vec4 v = vec4(1, 2, 3, 4);

    v = vec4(8);
    if (v != vec4(8)) return false;

    v = vec4(7, 6, 5, 4);
    if (v != vec4(7, 6, 5, 4)) return false;

    v = v.wzyx;
    if (v != vec4(4, 5, 6, 7)) return false;

    return true;
  });
}
