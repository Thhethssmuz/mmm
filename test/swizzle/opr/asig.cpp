#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("swizzle assignment operator +=", "[vec][asig]") {

  vec2 v2 = vec2(1, 2);
  vec3 v3 = vec3(1, 2, 3);
  vec4 v4 = vec4(1, 2, 3, 4);

  vec2 u2 = vec2(1, 2);
  vec3 u3 = vec3(1, 2, 3);
  vec4 u4 = vec4(1, 2, 3, 4);

  SECTION("swizzle1") {
    v2.x += 1;
    v3.x += 1;
    v4.x += u4.x;
    REQUIRE(v2 == vec2(2, 2));
    REQUIRE(v3 == vec3(2, 2, 3));
    REQUIRE(v4 == vec4(2, 2, 3, 4));
  }

  SECTION("swizzle2") {
    v2.xy += 1;
    v3.xy += u2;
    v4.xy += u4.xy;
    REQUIRE(v2 == vec2(2, 3));
    REQUIRE(v3 == vec3(2, 4, 3));
    REQUIRE(v4 == vec4(2, 4, 3, 4));
  }

  SECTION("swizzle3") {
    v2.xyy += 1;
    v3.xyz += u3;
    v4.xyz += u4.xyz;
    REQUIRE(v2 == vec2(2, 4));
    REQUIRE(v3 == vec3(2, 4, 6));
    REQUIRE(v4 == vec4(2, 4, 6, 4));
  }

  SECTION("swizzle4") {
    v2.xyyy += 1;
    v3.xyzz += u4;
    v4.xyzw += u4.xyzw;
    REQUIRE(v2 == vec2(2, 5));
    REQUIRE(v3 == vec3(2, 4, 10));
    REQUIRE(v4 == vec4(2, 4, 6, 8));
  }
}

TEST_CASE("swizzle assignment operator -=", "[vec][asig]") {

  vec2 v2 = vec2(1, 2);
  vec3 v3 = vec3(1, 2, 3);
  vec4 v4 = vec4(1, 2, 3, 4);

  vec2 u2 = vec2(1, 2);
  vec3 u3 = vec3(1, 2, 3);
  vec4 u4 = vec4(1, 2, 3, 4);

  SECTION("swizzle1") {
    v2.x -= 1;
    v3.x -= 1;
    v4.x -= u4.x;
    REQUIRE(v2 == vec2(0, 2));
    REQUIRE(v3 == vec3(0, 2, 3));
    REQUIRE(v4 == vec4(0, 2, 3, 4));
  }

  SECTION("swizzle2") {
    v2.xy -= 1;
    v3.xy -= u2;
    v4.xy -= u4.xy;
    REQUIRE(v2 == vec2(0, 1));
    REQUIRE(v3 == vec3(0, 0, 3));
    REQUIRE(v4 == vec4(0, 0, 3, 4));
  }

  SECTION("swizzle3") {
    v2.xyy -= 1;
    v3.xyz -= u3;
    v4.xyz -= u4.xyz;
    REQUIRE(v2 == vec2(0, 0));
    REQUIRE(v3 == vec3(0, 0, 0));
    REQUIRE(v4 == vec4(0, 0, 0, 4));
  }

  SECTION("swizzle4") {
    v2.xyyy -= 1;
    v3.xyzz -= u4;
    v4.xyzw -= u4.xyzw;
    REQUIRE(v2 == vec2(0, -1));
    REQUIRE(v3 == vec3(0, 0, -4));
    REQUIRE(v4 == vec4(0, 0, 0, 0));
  }
}

TEST_CASE("swizzle assignment operator *=", "[vec][asig]") {

  vec2 v2 = vec2(1, 2);
  vec3 v3 = vec3(1, 2, 3);
  vec4 v4 = vec4(1, 2, 3, 4);

  vec2 u2 = vec2(1, 2);
  vec3 u3 = vec3(1, 2, 3);
  vec4 u4 = vec4(1, 2, 3, 4);

  SECTION("swizzle1") {
    v2.x *= 2;
    v3.x *= 2;
    v4.x *= u4.x;
    REQUIRE(v2 == vec2(2, 2));
    REQUIRE(v3 == vec3(2, 2, 3));
    REQUIRE(v4 == vec4(1, 2, 3, 4));
  }

  SECTION("swizzle2") {
    v2.xy *= 2;
    v3.xy *= u2;
    v4.xy *= u4.xy;
    REQUIRE(v2 == vec2(2, 4));
    REQUIRE(v3 == vec3(1, 4, 3));
    REQUIRE(v4 == vec4(1, 4, 3, 4));
  }

  SECTION("swizzle3") {
    v2.xyy *= 2;
    v3.xyz *= u3;
    v4.xyz *= u4.xyz;
    REQUIRE(v2 == vec2(2, 8));
    REQUIRE(v3 == vec3(1, 4, 9));
    REQUIRE(v4 == vec4(1, 4, 9, 4));
  }

  SECTION("swizzle4") {
    v2.xyyy *= 2;
    v3.xyzz *= u4;
    v4.xyzw *= u4.xyzw;
    REQUIRE(v2 == vec2(2, 16));
    REQUIRE(v3 == vec3(1, 4, 36));
    REQUIRE(v4 == vec4(1, 4, 9, 16));
  }
}

TEST_CASE("swizzle assignment operator /=", "[vec][asig]") {

  vec2 v2 = vec2(4, 8);
  vec3 v3 = vec3(4, 8, 16);
  vec4 v4 = vec4(4, 8, 16, 32);

  vec2 u2 = vec2(1, 2);
  vec3 u3 = vec3(1, 2, 4);
  vec4 u4 = vec4(1, 2, 4, 8);

  SECTION("swizzle1") {
    v2.x /= 2;
    v3.x /= 2;
    v4.x /= u4.x;
    REQUIRE(v2 == vec2(2, 8));
    REQUIRE(v3 == vec3(2, 8, 16));
    REQUIRE(v4 == vec4(4, 8, 16, 32));
  }

  SECTION("swizzle2") {
    v2.xy /= 2;
    v3.xy /= u2;
    v4.xy /= u4.xy;
    REQUIRE(v2 == vec2(2, 4));
    REQUIRE(v3 == vec3(4, 4, 16));
    REQUIRE(v4 == vec4(4, 4, 16, 32));
  }

  SECTION("swizzle3") {
    v2.xyy /= 2;
    v3.xyz /= u3;
    v4.xyz /= u4.xyz;
    REQUIRE(v2 == vec2(2, 2));
    REQUIRE(v3 == vec3(4, 4, 4));
    REQUIRE(v4 == vec4(4, 4, 4, 32));
  }

  SECTION("swizzle4") {
    v2.xyyy /= 2;
    v3.xyzz /= u4;
    v4.xyzw /= u4.xyzw;
    REQUIRE(v2 == vec2(2, 1));
    REQUIRE(v3 == vec3(4, 4, 0.5));
    REQUIRE(v4 == vec4(4, 4, 4, 4));
  }
}

TEST_CASE("swizzle assignment operator =", "[vec][asig]") {

  vec2 v2 = vec2(1, 2);
  vec3 v3 = vec3(1, 2, 3);
  vec4 v4 = vec4(1, 2, 3, 4);

  vec2 u2 = vec2(5, 6);
  vec3 u3 = vec3(5, 6, 7);
  vec4 u4 = vec4(5, 6, 7, 8);

  SECTION("swizzle1") {
    v2.x = 0;
    v3.x = 0;
    v4.x = u4.x;
    REQUIRE(v2 == vec2(0, 2));
    REQUIRE(v3 == vec3(0, 2, 3));
    REQUIRE(v4 == vec4(5, 2, 3, 4));
  }

  SECTION("swizzle2") {
    v2.xy = 0;
    v3.xy = u2;
    v4.xy = u4.xy;
    REQUIRE(v2 == vec2(0, 0));
    REQUIRE(v3 == vec3(5, 6, 3));
    REQUIRE(v4 == vec4(5, 6, 3, 4));
  }

  SECTION("swizzle3") {
    v2.xyy = 0;
    v3.xyz = u3;
    v4.xyz = u4.xyz;
    REQUIRE(v2 == vec2(0, 0));
    REQUIRE(v3 == vec3(5, 6, 7));
    REQUIRE(v4 == vec4(5, 6, 7, 4));
  }

  SECTION("swizzle4") {
    v2.xyyy = 0;
    v3.xyzz = u4;
    v4.xyzw = u4.xyzw;
    REQUIRE(v2 == vec2(0, 0));
    REQUIRE(v3 == vec3(5, 6, 8));
    REQUIRE(v4 == vec4(5, 6, 7, 8));
  }
}
