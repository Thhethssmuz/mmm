#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("matrix enlargement function appendRow", "[mat][enl]") {

  SECTION("mat2") {
    mat2 m = mat2(1, 2, 3, 4);
    REQUIRE(appendRow(m, vec2(5, 6)) == mat2x3(1, 2, 3, 4, 5, 6));
  }

  SECTION("mat3") {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    REQUIRE(appendRow(m, vec3(10, 11, 12)) == mat3x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12));
  }

  SECTION("mat2x3") {
    mat2x3 m = mat2x3(1, 2, 3, 4, 5, 6);
    REQUIRE(appendRow(m, vec2(7, 8)) == mat2x4(1, 2, 3, 4, 5, 6, 7, 8));
  }

  SECTION("mat3x2") {
    mat3x2 m = mat3x2(1, 2, 3, 4, 5, 6);
    REQUIRE(appendRow(m, vec3(7, 8, 9)) == mat3x3(1, 2, 3, 4, 5, 6, 7, 8, 9));
  }
}

TEST_CASE("matrix enlargement function appendColumn", "[mat][enl]") {

  SECTION("mat2") {
    mat2 m = mat2(1, 2, 3, 4);
    REQUIRE(appendColumn(m, vec2(5, 6)) == mat3x2(1, 2, 5, 3, 4, 6));
  }

  SECTION("mat3") {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    REQUIRE(appendColumn(m, vec3(10, 11, 12)) == mat4x3(1, 2, 3, 10, 4, 5, 6, 11, 7, 8, 9, 12));
  }

  SECTION("mat2x3") {
    mat2x3 m = mat2x3(1, 2, 3, 4, 5, 6);
    REQUIRE(appendColumn(m, vec3(7, 8, 9)) == mat3x3(1, 2, 7, 3, 4, 8, 5, 6, 9));
  }

  SECTION("mat3x2") {
    mat3x2 m = mat3x2(1, 2, 3, 4, 5, 6);
    REQUIRE(appendColumn(m, vec2(7, 8)) == mat4x2(1, 2, 3, 7, 4, 5, 6, 8));
  }
}
