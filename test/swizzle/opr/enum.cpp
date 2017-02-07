#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("swizzle enumeration operator ++", "[vec][enum]") {

  ivec2 v2 = ivec2(1, 2);
  ivec3 v3 = ivec3(1, 2, 3);
  ivec4 v4 = ivec4(1, 2, 3, 4);

  SECTION("swizzle1 post") {
    REQUIRE(++v2.x == 2);
    REQUIRE(v2 == ivec2(2, 2));

    REQUIRE(++v3.x == 2);
    REQUIRE(v3 == ivec3(2, 2, 3));

    REQUIRE(++v4.x == 2);
    REQUIRE(v4 == ivec4(2, 2, 3, 4));
  }
  SECTION("swizzle1 post") {
    REQUIRE(v2.x++ == 1);
    REQUIRE(v2 == ivec2(2, 2));

    REQUIRE(v3.x++ == 1);
    REQUIRE(v3 == ivec3(2, 2, 3));

    REQUIRE(v4.x++ == 1);
    REQUIRE(v4 == ivec4(2, 2, 3, 4));
  }

  SECTION("swizzle2 pre") {
    REQUIRE(++v2.xy == ivec2(2, 3));
    REQUIRE(v2 == ivec2(2, 3));

    REQUIRE(++v3.xy == ivec2(2, 3));
    REQUIRE(v3 == ivec3(2, 3, 3));

    REQUIRE(++v4.xy == ivec2(2, 3));
    REQUIRE(v4 == ivec4(2, 3, 3, 4));
  }
  SECTION("swizzle2 post") {
    REQUIRE(v2.xy++ == ivec2(1, 2));
    REQUIRE(v2 == ivec2(2, 3));

    REQUIRE(v3.xy++ == ivec2(1, 2));
    REQUIRE(v3 == ivec3(2, 3, 3));

    REQUIRE(v4.xy++ == ivec2(1, 2));
    REQUIRE(v4 == ivec4(2, 3, 3, 4));
  }

  SECTION("swizzle3 pre") {
    REQUIRE(++v2.xyy == ivec3(2, 4, 4));
    REQUIRE(v2 == ivec2(2, 4));

    REQUIRE(++v3.xyz == ivec3(2, 3, 4));
    REQUIRE(v3 == ivec3(2, 3, 4));

    REQUIRE(++v4.xyz == ivec3(2, 3, 4));
    REQUIRE(v4 == ivec4(2, 3, 4, 4));
  }
  SECTION("swizzle3 post") {
    REQUIRE(v2.xyy++ == ivec3(1, 2, 2));
    REQUIRE(v2 == ivec2(2, 4));

    REQUIRE(v3.xyz++ == ivec3(1, 2, 3));
    REQUIRE(v3 == ivec3(2, 3, 4));

    REQUIRE(v4.xyz++ == ivec3(1, 2, 3));
    REQUIRE(v4 == ivec4(2, 3, 4, 4));
  }

  SECTION("swizzle4 pre") {
    REQUIRE(++v2.xyyy == ivec4(2, 5, 5, 5));
    REQUIRE(v2 == ivec2(2, 5));

    REQUIRE(++v3.xyzz == ivec4(2, 3, 5, 5));
    REQUIRE(v3 == ivec3(2, 3, 5));

    REQUIRE(++v4.xyzw == ivec4(2, 3, 4, 5));
    REQUIRE(v4 == ivec4(2, 3, 4, 5));
  }
  SECTION("swizzle4 post") {
    REQUIRE(v2.xyyy++ == ivec4(1, 2, 2, 2));
    REQUIRE(v2 == ivec2(2, 5));

    REQUIRE(v3.xyzz++ == ivec4(1, 2, 3, 3));
    REQUIRE(v3 == ivec3(2, 3, 5));

    REQUIRE(v4.xyzw++ == ivec4(1, 2, 3, 4));
    REQUIRE(v4 == ivec4(2, 3, 4, 5));
  }
}

TEST_CASE("swizzle enumeration operator --", "[vec][enum]") {

  ivec2 v2 = ivec2(1, 2);
  ivec3 v3 = ivec3(1, 2, 3);
  ivec4 v4 = ivec4(1, 2, 3, 4);

  SECTION("swizzle1 post") {
    REQUIRE(--v2.x == 0);
    REQUIRE(v2 == ivec2(0, 2));

    REQUIRE(--v3.x == 0);
    REQUIRE(v3 == ivec3(0, 2, 3));

    REQUIRE(--v4.x == 0);
    REQUIRE(v4 == ivec4(0, 2, 3, 4));
  }
  SECTION("swizzle1 post") {
    REQUIRE(v2.x-- == 1);
    REQUIRE(v2 == ivec2(0, 2));

    REQUIRE(v3.x-- == 1);
    REQUIRE(v3 == ivec3(0, 2, 3));

    REQUIRE(v4.x-- == 1);
    REQUIRE(v4 == ivec4(0, 2, 3, 4));
  }

  SECTION("swizzle2 pre") {
    REQUIRE(--v2.xy == ivec2(0, 1));
    REQUIRE(v2 == ivec2(0, 1));

    REQUIRE(--v3.xy == ivec2(0, 1));
    REQUIRE(v3 == ivec3(0, 1, 3));

    REQUIRE(--v4.xy == ivec2(0, 1));
    REQUIRE(v4 == ivec4(0, 1, 3, 4));
  }
  SECTION("swizzle2 post") {
    REQUIRE(v2.xy-- == ivec2(1, 2));
    REQUIRE(v2 == ivec2(0, 1));

    REQUIRE(v3.xy-- == ivec2(1, 2));
    REQUIRE(v3 == ivec3(0, 1, 3));

    REQUIRE(v4.xy-- == ivec2(1, 2));
    REQUIRE(v4 == ivec4(0, 1, 3, 4));
  }

  SECTION("swizzle3 pre") {
    REQUIRE(--v2.xyy == ivec3(0, 0, 0));
    REQUIRE(v2 == ivec2(0, 0));

    REQUIRE(--v3.xyz == ivec3(0, 1, 2));
    REQUIRE(v3 == ivec3(0, 1, 2));

    REQUIRE(--v4.xyz == ivec3(0, 1, 2));
    REQUIRE(v4 == ivec4(0, 1, 2, 4));
  }
  SECTION("swizzle3 post") {
    REQUIRE(v2.xyy-- == ivec3(1, 2, 2));
    REQUIRE(v2 == ivec2(0, 0));

    REQUIRE(v3.xyz-- == ivec3(1, 2, 3));
    REQUIRE(v3 == ivec3(0, 1, 2));

    REQUIRE(v4.xyz-- == ivec3(1, 2, 3));
    REQUIRE(v4 == ivec4(0, 1, 2, 4));
  }

  SECTION("swizzle4 pre") {
    REQUIRE(--v2.xyyy == ivec4(0, -1, -1, -1));
    REQUIRE(v2 == ivec2(0, -1));

    REQUIRE(--v3.xyzz == ivec4(0, 1, 1, 1));
    REQUIRE(v3 == ivec3(0, 1, 1));

    REQUIRE(--v4.xyzw == ivec4(0, 1, 2, 3));
    REQUIRE(v4 == ivec4(0, 1, 2, 3));
  }
  SECTION("swizzle4 post") {
    REQUIRE(v2.xyyy-- == ivec4(1, 2, 2, 2));
    REQUIRE(v2 == ivec2(0, -1));

    REQUIRE(v3.xyzz-- == ivec4(1, 2, 3, 3));
    REQUIRE(v3 == ivec3(0, 1, 1));

    REQUIRE(v4.xyzw-- == ivec4(1, 2, 3, 4));
    REQUIRE(v4 == ivec4(0, 1, 2, 3));
  }
}
