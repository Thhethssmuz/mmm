#include <sstream>
#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("matrix io operator <<", "[mat][io]") {

  std::stringstream ss;

  SECTION("mat2") {
    ss << mat2(0);
    REQUIRE(ss.str() == "[[0, 0], [0, 0]]");
  }

  SECTION("mat3") {
    ss << mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    REQUIRE(ss.str() == "[[1, 2, 3], [4, 5, 6], [7, 8, 9]]");
  }

  SECTION("mat4") {
    ss << mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    REQUIRE(ss.str() == "[[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]");
  }

  SECTION("mat2x4") {
    ss << mat2x4(1, 2, 3, 4, 5, 6, 7, 8);
    REQUIRE(ss.str() == "[[1, 2], [3, 4], [5, 6], [7, 8]]");
  }

  SECTION("mat4x2") {
    ss << mat4x2(1, 2, 3, 4, 5, 6, 7, 8);
    REQUIRE(ss.str() == "[[1, 2, 3, 4], [5, 6, 7, 8]]");
  }
}
