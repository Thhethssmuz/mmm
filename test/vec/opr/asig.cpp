#include <unittest.hpp>
#include <mmm.hpp>

namespace {

  auto asig1 = UnitTest("vector assignment operator +=", +[]() {
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

  auto asig2 = UnitTest("vector assignment operator -=", +[]() {
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

  auto asig3 = UnitTest("vector assignment operator *=", +[]() {
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

  auto asig4 = UnitTest("vector assignment operator /=", +[]() {
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
}
