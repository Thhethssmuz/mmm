#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("vector enumeration operator ++", "[vec][enum]") {

  ivec4 v = ivec4(1, 2, 3, 4);

  SECTION("pre") {
    ++v;
    REQUIRE(v == ivec4(2, 3, 4, 5));
    REQUIRE(++v == ivec4(3, 4, 5, 6));
    REQUIRE(v == ivec4(3, 4, 5, 6));
  }

  SECTION("post") {
    v++;
    REQUIRE(v == ivec4(2, 3, 4, 5));
    REQUIRE(v++ == ivec4(2, 3, 4, 5));
    REQUIRE(v == ivec4(3, 4, 5, 6));
  }
}

TEST_CASE("vector enumeration operator --", "[vec][enum]") {

  ivec4 v = ivec4(1, 2, 3, 4);

  SECTION("pre") {
    --v;
    REQUIRE(v == ivec4(0, 1, 2, 3));
    REQUIRE((--v == ivec4(-1, 0, 1, 2)));
    REQUIRE(v == ivec4(-1, 0, 1, 2));
  }

  SECTION("post") {
    v--;
    REQUIRE(v == ivec4(0, 1, 2, 3));
    REQUIRE(v-- == ivec4(0, 1, 2, 3));
    REQUIRE(v == ivec4(-1, 0, 1, 2));
  }
}
