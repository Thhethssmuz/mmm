#include <sstream>
#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("vector io operator <<", "[vec][io]") {

  std::stringstream ss;

  SECTION("vec2") {
    ss << ivec2(0);
    REQUIRE(ss.str() == "[0, 0]");
  }

  SECTION("vec3") {
    ss << vec3(1, 2, 3);
    REQUIRE(ss.str() == "[1, 2, 3]");
  }

  SECTION("vec4") {
    ss << bvec4(0, 0, 1, 1);
    REQUIRE(ss.str() == "[0, 0, 1, 1]");
  }
}
