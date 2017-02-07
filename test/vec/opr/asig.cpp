#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("vector assignment operator +=", "[vec][asig]") {

  vec2 v2 = vec2(1, 2);
  vec3 v3 = vec3(1, 2, 3);
  vec4 v4 = vec4(1, 2, 3, 4);

  vec2 u2 = vec2(2, 3);
  vec3 u3 = vec3(2, 3, 4);
  vec4 u4 = vec4(2, 3, 4, 5);

  SECTION("vec2") {

    v2 += 1;
    REQUIRE(v2 == vec2(2, 3));

    v2 += 2.f;
    REQUIRE(v2 == vec2(4, 5));

    v2 += 3.0;
    REQUIRE(v2 == vec2(7, 8));

    v2 += 4.l;
    REQUIRE(v2 == vec2(11, 12));

    v2 += u2;
    REQUIRE(v2 == vec2(13, 15));

    v2 += u2.yx;
    REQUIRE(v2 == vec2(16, 17));
  }

  SECTION("vec3") {

    v3 += 1;
    REQUIRE(v3 == vec3(2, 3, 4));

    v3 += 2.f;
    REQUIRE(v3 == vec3(4, 5, 6));

    v3 += 3.0;
    REQUIRE(v3 == vec3(7, 8, 9));

    v3 += 4.l;
    REQUIRE(v3 == vec3(11, 12, 13));

    v3 += u3;
    REQUIRE(v3 == vec3(13, 15, 17));

    v3 += u3.zyx;
    REQUIRE(v3 == vec3(17, 18, 19));
  }

  SECTION("vec4") {

    v4 += 1;
    REQUIRE(v4 == vec4(2, 3, 4, 5));

    v4 += 2.f;
    REQUIRE(v4 == vec4(4, 5, 6, 7));

    v4 += 3.0;
    REQUIRE(v4 == vec4(7, 8, 9, 10));

    v4 += 4.l;
    REQUIRE(v4 == vec4(11, 12, 13, 14));

    v4 += u4;
    REQUIRE(v4 == vec4(13, 15, 17, 19));

    v4 += u4.wzyx;
    REQUIRE(v4 == vec4(18, 19, 20, 21));
  }
}

TEST_CASE("vector assignment operator -=", "[vec][asig]") {

  vec2 v2 = vec2(1, 2);
  vec3 v3 = vec3(1, 2, 3);
  vec4 v4 = vec4(1, 2, 3, 4);

  vec2 u2 = vec2(2, 3);
  vec3 u3 = vec3(2, 3, 4);
  vec4 u4 = vec4(2, 3, 4, 5);

  SECTION("vec2") {

    v2 -= 1;
    REQUIRE(v2 == vec2(0, 1));

    v2 -= 2.f;
    REQUIRE(v2 == vec2(-2, -1));

    v2 -= 3.0;
    REQUIRE(v2 == vec2(-5, -4));

    v2 -= 4.l;
    REQUIRE(v2 == vec2(-9, -8));

    v2 -= u2;
    REQUIRE(v2 == vec2(-11, -11));

    v2 -= u2.yx;
    REQUIRE(v2 == vec2(-14, -13));
  }

  SECTION("vec3") {

    v3 -= 1;
    REQUIRE(v3 == vec3(0, 1, 2));

    v3 -= 2.f;
    REQUIRE(v3 == vec3(-2, -1, 0));

    v3 -= 3.0;
    REQUIRE(v3 == vec3(-5, -4, -3));

    v3 -= 4.l;
    REQUIRE(v3 == vec3(-9, -8, -7));

    v3 -= u3;
    REQUIRE(v3 == vec3(-11, -11, -11));

    v3 -= u3.zyx;
    REQUIRE(v3 == vec3(-15, -14, -13));
  }

  SECTION("vec4") {

    v4 -= 1;
    REQUIRE(v4 == vec4(0, 1, 2, 3));

    v4 -= 2.f;
    REQUIRE(v4 == vec4(-2, -1, 0, 1));

    v4 -= 3.0;
    REQUIRE(v4 == vec4(-5, -4, -3, -2));

    v4 -= 4.l;
    REQUIRE(v4 == vec4(-9, -8, -7, -6));

    v4 -= u4;
    REQUIRE(v4 == vec4(-11, -11, -11, -11));

    v4 -= u4.wzyx;
    REQUIRE(v4 == vec4(-16, -15, -14, -13));
  }
}

TEST_CASE("vector assignment operator *=", "[vec][asig]") {

  vec2 v2 = vec2(1, 2);
  vec3 v3 = vec3(1, 2, 3);
  vec4 v4 = vec4(1, 2, 3, 4);

  vec2 u2 = vec2(2, 3);
  vec3 u3 = vec3(2, 3, 4);
  vec4 u4 = vec4(2, 3, 4, 5);

  SECTION("vec2") {

    v2 *= 1;
    REQUIRE(v2 == vec2(1, 2));

    v2 *= 2.f;
    REQUIRE(v2 == vec2(2, 4));

    v2 *= 3.0;
    REQUIRE(v2 == vec2(6, 12));

    v2 *= 4.l;
    REQUIRE(v2 == vec2(24, 48));

    v2 *= u2;
    REQUIRE(v2 == vec2(48, 144));

    v2 *= u2.yx;
    REQUIRE(v2 == vec2(144, 288));
  }

  SECTION("vec3") {

    v3 *= 1;
    REQUIRE(v3 == vec3(1, 2, 3));

    v3 *= 2.f;
    REQUIRE(v3 == vec3(2, 4, 6));

    v3 *= 3.0;
    REQUIRE(v3 == vec3(6, 12, 18));

    v3 *= 4.l;
    REQUIRE(v3 == vec3(24, 48, 72));

    v3 *= u3;
    REQUIRE(v3 == vec3(48, 144, 288));

    v3 *= u3.zyx;
    REQUIRE(v3 == vec3(192, 432, 576));
  }

  SECTION("vec4") {

    v4 *= 1;
    REQUIRE(v4 == vec4(1, 2, 3, 4));

    v4 *= 2.f;
    REQUIRE(v4 == vec4(2, 4, 6, 8));

    v4 *= 3.0;
    REQUIRE(v4 == vec4(6, 12, 18, 24));

    v4 *= 4.l;
    REQUIRE(v4 == vec4(24, 48, 72, 96));

    v4 *= u4;
    REQUIRE(v4 == vec4(48, 144, 288, 480));

    v4 *= u4.wzyx;
    REQUIRE(v4 == vec4(240, 576, 864, 960));
  }
}

TEST_CASE("vector assignment operator /=", "[vec][asig]") {

  vec2 v2 = vec2(144, 288);
  vec3 v3 = vec3(192, 432, 576);
  vec4 v4 = vec4(240, 576, 864, 960);

  vec2 u2 = vec2(2, 3);
  vec3 u3 = vec3(2, 3, 4);
  vec4 u4 = vec4(2, 3, 4, 5);

  SECTION("vec2") {

    v2 /= 1;
    REQUIRE(v2 == vec2(144, 288));

    v2 /= 2.f;
    REQUIRE(v2 == vec2(72, 144));

    v2 /= 3.0;
    REQUIRE(v2 == vec2(24, 48));

    v2 /= 4.l;
    REQUIRE(v2 == vec2(6, 12));

    v2 /= u2;
    REQUIRE(v2 == vec2(3, 4));

    v2 /= u2.yx;
    REQUIRE(v2 == vec2(1, 2));
  }

  SECTION("vec3") {

    v3 /= 1;
    REQUIRE(v3 == vec3(192, 432, 576));

    v3 /= 2.f;
    REQUIRE(v3 == vec3(96, 216, 288));

    v3 /= 3.0;
    REQUIRE(v3 == vec3(32, 72, 96));

    v3 /= 4.l;
    REQUIRE(v3 == vec3(8, 18, 24));

    v3 /= u3;
    REQUIRE(v3 == vec3(4, 6, 6));

    v3 /= u3.zyx;
    REQUIRE(v3 == vec3(1, 2, 3));
  }

  SECTION("vec4") {

    v4 /= 1;
    REQUIRE(v4 == vec4(240, 576, 864, 960));

    v4 /= 2.f;
    REQUIRE(v4 == vec4(120, 288, 432, 480));

    v4 /= 3.0;
    REQUIRE(v4 == vec4(40, 96, 144, 160));

    v4 /= 4.l;
    REQUIRE(v4 == vec4(10, 24, 36, 40));

    v4 /= u4;
    REQUIRE(v4 == vec4(5, 8, 9, 8));

    v4 /= u4.wzyx;
    REQUIRE(v4 == vec4(1, 2, 3, 4));
  }
}

TEST_CASE("vector assignment operator =", "[vec][asig]") {

  vec2 v2 = vec2(1, 2);
  vec3 v3 = vec3(1, 2, 3);
  vec4 v4 = vec4(1, 2, 3, 4);

  vec2 u2 = vec2(2, 3);
  vec3 u3 = vec3(2, 3, 4);
  vec4 u4 = vec4(2, 3, 4, 5);

  // Should this be allowed?
  // SECTION("scalar") {
  //   v2 = 1;
  //   v3 = 2.f;
  //   v4 = 3.0;
  //   REQUIRE(v2 == vec2(1, 1));
  //   REQUIRE(v3 == vec3(2, 2, 2));
  //   REQUIRE(v4 == vec4(3, 3, 3, 3));
  // }

  SECTION("vec") {
    v2 = vec2(1);
    v3 = vec3(1, 2, 3);
    v4 = u4;

    REQUIRE(v2 == vec2(1, 1));
    REQUIRE(v3 == vec3(1, 2, 3));
    REQUIRE(v4 == vec4(2, 3, 4, 5));
  }

  SECTION("swizzle") {
    v2 = u2.xy;
    v3 = u3.zyx;
    v4 = u3.xyzz;

    REQUIRE(v2 == vec2(2, 3));
    REQUIRE(v3 == vec3(4, 3, 2));
    REQUIRE(v4 == vec4(2, 3, 4, 4));
  }
}
