#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("swizzle elements", "[vec]") {

  vec<9> v = vec<9>(1, 2, 3, 4, 5, 6, 7, 8, 9);

  REQUIRE(v.swizzleElems<0>() == 1);
  REQUIRE(v.swizzleElems<1>() == 2);
  REQUIRE((v.swizzleElems<2, 3>()) == vec2(3, 4));
  REQUIRE((v.swizzleElems<4, 6>()) == vec2(5, 7));
  REQUIRE((v.swizzleElems<2, 3, 5, 7>()) == vec4(3, 4, 6, 8));
}

TEST_CASE("swizzle range", "[vec]") {

  vec<9> v = vec<9>(1, 2, 3, 4, 5, 6, 7, 8, 9);

  REQUIRE((v.swizzleRange<0, 1>()) == vec2(1, 2));
  REQUIRE((v.swizzleRange<1, 2>()) == vec2(2, 3));
  REQUIRE((v.swizzleRange<2, 4>()) == vec3(3, 4, 5));
  REQUIRE((v.swizzleRange<3, 6>()) == vec4(4, 5, 6, 7));
  REQUIRE((v.swizzleRange<6, 3>()) == vec4(7, 6, 5, 4));
}
