#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("affine matrix - identity", "[mat][affine]") {

  SECTION("function") {
    REQUIRE((identity<float, 2, 2>()) == mat2x2(1, 0, 0, 1));
    REQUIRE((identity<float, 2, 3>()) == mat2x3(1, 0, 0, 1, 0, 0));
    REQUIRE((identity<float, 2, 4>()) == mat2x4(1, 0, 0, 1, 0, 0, 0, 0));

    REQUIRE((identity<float, 3, 2>()) == mat3x2(1, 0, 0, 0, 1, 0));
    REQUIRE((identity<float, 3, 3>()) == mat3x3(1, 0, 0, 0, 1, 0, 0, 0, 1));
    REQUIRE((identity<float, 3, 4>()) == mat3x4(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0));

    REQUIRE((identity<float, 4, 2>()) == mat4x2(1, 0, 0, 0, 0, 1, 0, 0));
    REQUIRE((identity<float, 4, 3>()) == mat4x3(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0));
    REQUIRE((identity<float, 4, 4>()) == mat4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1));
  }

  SECTION("static") {
    REQUIRE(mat2::identity == mat2(1, 0, 0, 1));
    REQUIRE(mat3::identity == mat3(1, 0, 0, 0, 1, 0, 0, 0, 1));
    REQUIRE(mat4::identity == mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1));
  }
}

TEST_CASE("affine matrix - translate", "[mat][affine]") {

  mat4 t1 = translate(1.f, 2.f, 3.f);
  mat4 t2 = translate(vec3(3, 2, 1));

  REQUIRE(t1 == mat4(1, 0, 0, 1, 0, 1, 0, 2, 0, 0, 1, 3, 0, 0, 0, 1));
  REQUIRE(t2 == mat4(1, 0, 0, 3, 0, 1, 0, 2, 0, 0, 1, 1, 0, 0, 0, 1));
}

TEST_CASE("affine matrix - rotate", "[mat][affine]") {

  SECTION("x") {
    mat4 m = rotate_x(45.f);

    REQUIRE(m[0][0] == Approx(1));
    REQUIRE(m[0][1] == Approx(0));
    REQUIRE(m[0][2] == Approx(0));
    REQUIRE(m[0][3] == Approx(0));

    REQUIRE(m[1][0] == Approx(0));
    REQUIRE(m[1][1] == Approx(0.7071));
    REQUIRE(m[1][2] == Approx(-0.7071));
    REQUIRE(m[1][3] == Approx(0));

    REQUIRE(m[2][0] == Approx(0));
    REQUIRE(m[2][1] == Approx(0.7071));
    REQUIRE(m[2][2] == Approx(0.7071));
    REQUIRE(m[2][3] == Approx(0));

    REQUIRE(m[3][0] == Approx(0));
    REQUIRE(m[3][1] == Approx(0));
    REQUIRE(m[3][2] == Approx(0));
    REQUIRE(m[3][3] == Approx(1));
  }

  SECTION("y") {
    mat4 m = rotate_y(45.f);

    REQUIRE(m[0][0] == Approx(0.7071));
    REQUIRE(m[0][1] == Approx(0));
    REQUIRE(m[0][2] == Approx(0.7071));
    REQUIRE(m[0][3] == Approx(0));

    REQUIRE(m[1][0] == Approx(0));
    REQUIRE(m[1][1] == Approx(1));
    REQUIRE(m[1][2] == Approx(0));
    REQUIRE(m[1][3] == Approx(0));

    REQUIRE(m[2][0] == Approx(-0.7071));
    REQUIRE(m[2][1] == Approx(0));
    REQUIRE(m[2][2] == Approx(0.7071));
    REQUIRE(m[2][3] == Approx(0));

    REQUIRE(m[3][0] == Approx(0));
    REQUIRE(m[3][1] == Approx(0));
    REQUIRE(m[3][2] == Approx(0));
    REQUIRE(m[3][3] == Approx(1));
  }

  SECTION("z") {
    mat4 m = rotate_z(45.f);

    REQUIRE(m[0][0] == Approx(0.7071));
    REQUIRE(m[0][1] == Approx(-0.7071));
    REQUIRE(m[0][2] == Approx(0));
    REQUIRE(m[0][3] == Approx(0));

    REQUIRE(m[1][0] == Approx(0.7071));
    REQUIRE(m[1][1] == Approx(0.7071));
    REQUIRE(m[1][2] == Approx(0));
    REQUIRE(m[1][3] == Approx(0));

    REQUIRE(m[2][0] == Approx(0));
    REQUIRE(m[2][1] == Approx(0));
    REQUIRE(m[2][2] == Approx(1));
    REQUIRE(m[2][3] == Approx(0));

    REQUIRE(m[3][0] == Approx(0));
    REQUIRE(m[3][1] == Approx(0));
    REQUIRE(m[3][2] == Approx(0));
    REQUIRE(m[3][3] == Approx(1));
  }
}

TEST_CASE("affine matrix - scale", "[mat][affine]") {

  mat4 s = scale(2.f, 3.f, 4.f);

  REQUIRE(s == mat4(2,0,0,0, 0,3,0,0, 0,0,4,0, 0,0,0,1));
}
