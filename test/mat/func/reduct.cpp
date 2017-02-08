#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("matrix reduction function takeRow", "[mat][red]") {

  SECTION("mat2") {
    mat2 m = mat2(1, 2, 3, 4);

    REQUIRE(takeRow<0>(m) == vec2(1, 2));
    REQUIRE(takeRow<1>(m) == vec2(3, 4));
  }

  SECTION("mat3") {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

    REQUIRE(takeRow<0>(m) == vec3(1, 2, 3));
    REQUIRE(takeRow<1>(m) == vec3(4, 5, 6));
    REQUIRE(takeRow<2>(m) == vec3(7, 8, 9));
  }

  SECTION("mat4") {
    mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    REQUIRE(takeRow<0>(m) == vec4(1, 2, 3, 4));
    REQUIRE(takeRow<1>(m) == vec4(5, 6, 7, 8));
    REQUIRE(takeRow<2>(m) == vec4(9, 10, 11, 12));
    REQUIRE(takeRow<3>(m) == vec4(13, 14, 15, 16));
  }

  SECTION("mat2x4") {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

    REQUIRE(takeRow<0>(m) == vec2(1, 2));
    REQUIRE(takeRow<1>(m) == vec2(3, 4));
    REQUIRE(takeRow<2>(m) == vec2(5, 6));
    REQUIRE(takeRow<3>(m) == vec2(7, 8));
  }

  SECTION("mat4x2") {
    mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    REQUIRE(takeRow<0>(m) == vec4(1, 2, 3, 4));
    REQUIRE(takeRow<1>(m) == vec4(5, 6, 7, 8));
  }
}

TEST_CASE("matrix reduction function takeRows", "[mat][red]") {

  SECTION("mat2") {
    mat2 m = mat2(1, 2, 3, 4);

    REQUIRE(takeRows<1>(m) == vec2(1, 2));
    REQUIRE(takeRows<2>(m) == mat2(1, 2, 3, 4));
  }

  SECTION("mat3") {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

    REQUIRE(takeRows<1>(m) == vec3(1, 2, 3));
    REQUIRE(takeRows<2>(m) == mat3x2(1, 2, 3, 4, 5, 6));
    REQUIRE(takeRows<3>(m) == mat3(1, 2, 3, 4, 5, 6, 7, 8, 9));
  }

  SECTION("mat4") {
    mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    REQUIRE(takeRows<1>(m) == vec4(1, 2, 3, 4));
    REQUIRE(takeRows<2>(m) == mat4x2(1, 2, 3, 4, 5, 6, 7, 8));
    REQUIRE(takeRows<3>(m) == mat4x3(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12));
    REQUIRE(takeRows<4>(m) == mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16));
  }

  SECTION("mat2x4") {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

    REQUIRE(takeRows<1>(m) == vec2(1, 2));
    REQUIRE(takeRows<2>(m) == mat2(1, 2, 3, 4));
    REQUIRE(takeRows<3>(m) == mat2x3(1, 2, 3, 4, 5, 6));
    REQUIRE(takeRows<4>(m) == mat2x4(1, 2, 3, 4, 5, 6, 7, 8));
  }

  SECTION("mat4x2") {
    mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    REQUIRE(takeRows<1>(m) == vec4(1, 2, 3, 4));
    REQUIRE(takeRows<2>(m) == mat4x2(1, 2, 3, 4, 5, 6, 7, 8));
  }
}

TEST_CASE("matrix reduction function dropRow", "[mat][red]") {

  SECTION("mat2") {
    mat2 m = mat2(1, 2, 3, 4);

    REQUIRE(dropRow<0>(m) == vec2(3, 4));
    REQUIRE(dropRow<1>(m) == vec2(1, 2));
  }

  SECTION("mat3") {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

    REQUIRE(dropRow<0>(m) == mat3x2(4, 5, 6, 7, 8, 9));
    REQUIRE(dropRow<1>(m) == mat3x2(1, 2, 3, 7, 8, 9));
    REQUIRE(dropRow<2>(m) == mat3x2(1, 2, 3, 4, 5, 6));
  }

  SECTION("mat4") {
    mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    REQUIRE(dropRow<0>(m) == mat4x3(5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16));
    REQUIRE(dropRow<1>(m) == mat4x3(1, 2, 3, 4, 9, 10, 11, 12, 13, 14, 15, 16));
    REQUIRE(dropRow<2>(m) == mat4x3(1, 2, 3, 4, 5, 6, 7, 8, 13, 14, 15, 16));
    REQUIRE(dropRow<3>(m) == mat4x3(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12));
  }

  SECTION("mat2x4") {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

    REQUIRE(dropRow<0>(m) == mat2x3(3, 4, 5, 6, 7, 8));
    REQUIRE(dropRow<1>(m) == mat2x3(1, 2, 5, 6, 7, 8));
    REQUIRE(dropRow<2>(m) == mat2x3(1, 2, 3, 4, 7, 8));
    REQUIRE(dropRow<3>(m) == mat2x3(1, 2, 3, 4, 5, 6));
  }

  SECTION("mat4x2") {
    mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    REQUIRE(dropRow<0>(m) == vec4(5, 6, 7, 8));
    REQUIRE(dropRow<1>(m) == vec4(1, 2, 3, 4));
  }
}

TEST_CASE("matrix reduction function dropRows", "[mat][red]") {

  SECTION("mat2") {
    mat2 m = mat2(1, 2, 3, 4);

    REQUIRE(dropRows<0>(m) == mat2(1, 2, 3, 4));
    REQUIRE(dropRows<1>(m) == vec2(3, 4));
  }

  SECTION("mat3") {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

    REQUIRE(dropRows<0>(m) == mat3(1, 2, 3, 4, 5, 6, 7, 8, 9));
    REQUIRE(dropRows<1>(m) == mat3x2(4, 5, 6, 7, 8, 9));
    REQUIRE(dropRows<2>(m) == vec3(7, 8, 9));
  }

  SECTION("mat4") {
    mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    REQUIRE(dropRows<0>(m) == mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16));
    REQUIRE(dropRows<1>(m) == mat4x3(5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16));
    REQUIRE(dropRows<2>(m) == mat4x2(9, 10, 11, 12, 13, 14, 15, 16));
    REQUIRE(dropRows<3>(m) == vec4(13, 14, 15, 16));
  }

  SECTION("mat2x4") {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

    REQUIRE(dropRows<0>(m) == mat2x4(1, 2, 3, 4, 5, 6, 7, 8));
    REQUIRE(dropRows<1>(m) == mat2x3(3, 4, 5, 6, 7, 8));
    REQUIRE(dropRows<2>(m) == mat2(5, 6, 7, 8));
    REQUIRE(dropRows<3>(m) == vec2(7, 8));
  }

  SECTION("mat4x2") {
    mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    REQUIRE(dropRows<0>(m) == mat4x2(1, 2, 3, 4, 5, 6, 7, 8));
    REQUIRE(dropRows<1>(m) == vec4(5, 6, 7, 8));
  }
}

TEST_CASE("matrix reduction function takeColumn", "[mat][red]") {

  SECTION("mat2") {
    mat2 m = mat2(1, 2, 3, 4);

    REQUIRE(takeColumn<0>(m) == vec2(1, 3));
    REQUIRE(takeColumn<1>(m) == vec2(2, 4));
  }

  SECTION("mat3") {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

    REQUIRE(takeColumn<0>(m) == vec3(1, 4, 7));
    REQUIRE(takeColumn<1>(m) == vec3(2, 5, 8));
    REQUIRE(takeColumn<2>(m) == vec3(3, 6, 9));
  }

  SECTION("mat4") {
    mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    REQUIRE(takeColumn<0>(m) == vec4(1, 5, 9, 13));
    REQUIRE(takeColumn<1>(m) == vec4(2, 6, 10, 14));
    REQUIRE(takeColumn<2>(m) == vec4(3, 7, 11, 15));
    REQUIRE(takeColumn<3>(m) == vec4(4, 8, 12, 16));
  }

  SECTION("mat2x4") {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

    REQUIRE(takeColumn<0>(m) == vec4(1, 3, 5, 7));
    REQUIRE(takeColumn<1>(m) == vec4(2, 4, 6, 8));
  }

  SECTION("mat4x2") {
    mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    REQUIRE(takeColumn<0>(m) == vec2(1, 5));
    REQUIRE(takeColumn<1>(m) == vec2(2, 6));
    REQUIRE(takeColumn<2>(m) == vec2(3, 7));
    REQUIRE(takeColumn<3>(m) == vec2(4, 8));
  }
}

TEST_CASE("matrix reduction function takeColumns", "[mat][red]") {

  SECTION("mat2") {
    mat2 m = mat2(1, 2, 3, 4);

    REQUIRE(takeColumns<1>(m) == vec2(1, 3));
    REQUIRE(takeColumns<2>(m) == mat2(1, 2, 3, 4));
  }

  SECTION("mat3") {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

    REQUIRE(takeColumns<1>(m) == vec3(1, 4, 7));
    REQUIRE(takeColumns<2>(m) == mat2x3(1, 2, 4, 5, 7, 8));
    REQUIRE(takeColumns<3>(m) == mat3(1, 2, 3, 4, 5, 6, 7, 8, 9));
  }

  SECTION("mat4") {
    mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    REQUIRE(takeColumns<1>(m) == vec4(1, 5, 9, 13));
    REQUIRE(takeColumns<2>(m) == mat2x4(1, 2, 5, 6, 9, 10, 13, 14));
    REQUIRE(takeColumns<3>(m) == mat3x4(1, 2, 3, 5, 6, 7, 9, 10, 11, 13, 14, 15));
    REQUIRE(takeColumns<4>(m) == mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16));
  }

  SECTION("mat2x4") {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

    REQUIRE(takeColumns<1>(m) == vec4(1, 3, 5, 7));
    REQUIRE(takeColumns<2>(m) == mat2x4(1, 2, 3, 4, 5, 6, 7, 8));
  }

  SECTION("mat4x2") {
    mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    REQUIRE(takeColumns<1>(m) == vec2(1, 5));
    REQUIRE(takeColumns<2>(m) == mat2(1, 2, 5, 6));
    REQUIRE(takeColumns<3>(m) == mat3x2(1, 2, 3, 5, 6, 7));
    REQUIRE(takeColumns<4>(m) == mat4x2(1, 2, 3, 4, 5, 6, 7, 8));
  }
}

TEST_CASE("matrix reduction function dropColumn", "[mat][red]") {

  SECTION("mat2") {
    mat2 m = mat2(1, 2, 3, 4);

    REQUIRE(dropColumn<0>(m) == vec2(2, 4));
    REQUIRE(dropColumn<1>(m) == vec2(1, 3));
  }

  SECTION("mat3") {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

    REQUIRE(dropColumn<0>(m) == mat2x3(2, 3, 5, 6, 8, 9));
    REQUIRE(dropColumn<1>(m) == mat2x3(1, 3, 4, 6, 7, 9));
    REQUIRE(dropColumn<2>(m) == mat2x3(1, 2, 4, 5, 7, 8));
  }

  SECTION("mat4") {
    mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    REQUIRE(dropColumn<0>(m) == mat3x4(2, 3, 4, 6, 7, 8, 10, 11, 12, 14, 15, 16));
    REQUIRE(dropColumn<1>(m) == mat3x4(1, 3, 4, 5, 7, 8, 9, 11, 12, 13, 15, 16));
    REQUIRE(dropColumn<2>(m) == mat3x4(1, 2, 4, 5, 6, 8, 9, 10, 12, 13, 14, 16));
    REQUIRE(dropColumn<3>(m) == mat3x4(1, 2, 3, 5, 6, 7, 9, 10, 11, 13, 14, 15));
  }

  SECTION("mat2x4") {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

    REQUIRE(dropColumn<0>(m) == vec4(2, 4, 6, 8));
    REQUIRE(dropColumn<1>(m) == vec4(1, 3, 5, 7));
  }

  SECTION("mat4x2") {
    mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    REQUIRE(dropColumn<0>(m) == mat3x2(2, 3, 4, 6, 7, 8));
    REQUIRE(dropColumn<1>(m) == mat3x2(1, 3, 4, 5, 7, 8));
    REQUIRE(dropColumn<2>(m) == mat3x2(1, 2, 4, 5, 6, 8));
    REQUIRE(dropColumn<3>(m) == mat3x2(1, 2, 3, 5, 6, 7));
  }
}

TEST_CASE("matrix reduction function dropColumns", "[mat][red]") {

  SECTION("mat2") {
    mat2 m = mat2(1, 2, 3, 4);

    REQUIRE(dropColumns<0>(m) == mat2(1, 2, 3, 4));
    REQUIRE(dropColumns<1>(m) == vec2(2, 4));
  }

  SECTION("mat3") {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

    REQUIRE(dropColumns<0>(m) == mat3(1, 2, 3, 4, 5, 6, 7, 8, 9));
    REQUIRE(dropColumns<1>(m) == mat2x3(2, 3, 5, 6, 8, 9));
    REQUIRE(dropColumns<2>(m) == vec3(3, 6, 9));
  }

  SECTION("mat4") {
    mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    REQUIRE(dropColumns<0>(m) == mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16));
    REQUIRE(dropColumns<1>(m) == mat3x4(2, 3, 4, 6, 7, 8, 10, 11, 12, 14, 15, 16));
    REQUIRE(dropColumns<2>(m) == mat2x4(3, 4, 7, 8, 11, 12, 15, 16));
    REQUIRE(dropColumns<3>(m) == vec4(4, 8, 12, 16));
  }

  SECTION("mat2x4") {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

    REQUIRE(dropColumns<0>(m) == mat2x4(1, 2, 3, 4, 5, 6, 7, 8));
    REQUIRE(dropColumns<1>(m) == vec4(2, 4, 6, 8));
  }

  SECTION("mat4x2") {
    mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    REQUIRE(dropColumns<0>(m) == mat4x2(1, 2, 3, 4, 5, 6, 7, 8));
    REQUIRE(dropColumns<1>(m) == mat3x2(2, 3, 4, 6, 7, 8));
    REQUIRE(dropColumns<2>(m) == mat2(3, 4, 7, 8));
    REQUIRE(dropColumns<3>(m) == vec2(4, 8));
  }
}
