#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("matrix numeric operator +", "[mat][num]") {

  SECTION("scalar matrix") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);

      REQUIRE(1 + m == mat2(2, 3, 4, 5));
      REQUIRE(2.f + m == mat2(3, 4, 5, 6));
      REQUIRE(3.0 + m == mat2(4, 5, 6, 7));
    }

    SECTION("mat3") {
      mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

      REQUIRE(4 + m == mat3(5, 6, 7, 8, 9, 10, 11, 12, 13));
      REQUIRE(5.f + m == mat3(6, 7, 8, 9, 10, 11, 12, 13, 14));
      REQUIRE(6.0 + m == mat3(7, 8, 9, 10, 11, 12, 13, 14, 15));
    }

    SECTION("mat4") {
      mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

      REQUIRE(7 + m == mat4(8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23));
      REQUIRE(8.f + m == mat4(9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24));
      REQUIRE(9.0 + m == mat4(10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25));
    }

    SECTION("mat2x4") {
      mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

      REQUIRE(1 + m == mat2x4(2, 3, 4, 5, 6, 7, 8, 9));
      REQUIRE(2.f + m == mat2x4(3, 4, 5, 6, 7, 8, 9, 10));
      REQUIRE(3.0 + m == mat2x4(4, 5, 6, 7, 8, 9, 10, 11));
    }

    SECTION("mat4x2") {
      mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

      REQUIRE(4 + m == mat4x2(5, 6, 7, 8, 9, 10, 11, 12));
      REQUIRE(5.f + m == mat4x2(6, 7, 8, 9, 10, 11, 12, 13));
      REQUIRE(6.0 + m == mat4x2(7, 8, 9, 10, 11, 12, 13, 14));
    }
  }

  SECTION("matrix scalar") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);

      REQUIRE(m + 1 == mat2(2, 3, 4, 5));
      REQUIRE(m + 2.f  == mat2(3, 4, 5, 6));
      REQUIRE(m + 3.0  == mat2(4, 5, 6, 7));
    }

    SECTION("mat3") {
      mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

      REQUIRE(m + 4 == mat3(5, 6, 7, 8, 9, 10, 11, 12, 13));
      REQUIRE(m + 5.f == mat3(6, 7, 8, 9, 10, 11, 12, 13, 14));
      REQUIRE(m + 6.0 == mat3(7, 8, 9, 10, 11, 12, 13, 14, 15));
    }

    SECTION("mat4") {
      mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

      REQUIRE(m + 7 == mat4(8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23));
      REQUIRE(m + 8.f == mat4(9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24));
      REQUIRE(m + 9.0 == mat4(10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25));
    }

    SECTION("mat2x4") {
      mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

      REQUIRE(m + 1 == mat2x4(2, 3, 4, 5, 6, 7, 8, 9));
      REQUIRE(m + 2.f == mat2x4(3, 4, 5, 6, 7, 8, 9, 10));
      REQUIRE(m + 3.0 == mat2x4(4, 5, 6, 7, 8, 9, 10, 11));
    }

    SECTION("mat4x2") {
      mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

      REQUIRE(m + 4 == mat4x2(5, 6, 7, 8, 9, 10, 11, 12));
      REQUIRE(m + 5.f == mat4x2(6, 7, 8, 9, 10, 11, 12, 13));
      REQUIRE(m + 6.0 == mat4x2(7, 8, 9, 10, 11, 12, 13, 14));
    }
  }

  SECTION("matrix matrix") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);
      mat2 n = mat2(4, 3, 2, 1);
      mat2 i = mat2(1, 0, 0, 1);

      REQUIRE(m + m == mat2(2, 4, 6, 8));
      REQUIRE(n + n == mat2(8, 6, 4, 2));
      REQUIRE(i + i == mat2(2, 0, 0, 2));

      REQUIRE(m + n == mat2(5, 5, 5, 5));
      REQUIRE(n + m == mat2(5, 5, 5, 5));

      REQUIRE(m + i == mat2(2, 2, 3, 5));
      REQUIRE(i + m == mat2(2, 2, 3, 5));

      REQUIRE(n + i == mat2(5, 3, 2, 2));
      REQUIRE(i + n == mat2(5, 3, 2, 2));
    }

    SECTION("mat3") {
      mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
      mat3 n = mat3(9, 8, 7, 6, 5, 4, 3, 2, 1);
      mat3 i = mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);

      REQUIRE(m + m == mat3(2, 4, 6, 8, 10, 12, 14, 16, 18));
      REQUIRE(n + n == mat3(18, 16, 14, 12, 10, 8, 6, 4, 2));
      REQUIRE(i + i == mat3(2, 0, 0, 0, 2, 0, 0, 0, 2));

      REQUIRE(m + n == 10);
      REQUIRE(n + m == 10);

      REQUIRE(m + i == mat3(2, 2, 3, 4, 6, 6, 7, 8, 10));
      REQUIRE(i + m == mat3(2, 2, 3, 4, 6, 6, 7, 8, 10));

      REQUIRE(n + i == mat3(10, 8, 7, 6, 6, 4, 3, 2, 2));
      REQUIRE(i + n == mat3(10, 8, 7, 6, 6, 4, 3, 2, 2));
    }

    SECTION("mat4") {
      mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
      mat4 n = mat4(16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
      mat4 i = mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

      REQUIRE(m + m == mat4(2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32));
      REQUIRE(n + n == mat4(32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2));
      REQUIRE(i + i == mat4(2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2));

      REQUIRE(m + n == 17);
      REQUIRE(n + m == 17);

      REQUIRE(m + i == mat4(2, 2, 3, 4, 5, 7, 7, 8, 9, 10, 12, 12, 13, 14, 15, 17));
      REQUIRE(i + m == mat4(2, 2, 3, 4, 5, 7, 7, 8, 9, 10, 12, 12, 13, 14, 15, 17));

      REQUIRE(n + i == mat4(17, 15, 14, 13, 12, 12, 10, 9, 8, 7, 7, 5, 4, 3, 2, 2));
      REQUIRE(i + n == mat4(17, 15, 14, 13, 12, 12, 10, 9, 8, 7, 7, 5, 4, 3, 2, 2));
    }
  }
}

TEST_CASE("matrix numeric operator -", "[mat][num]") {

  SECTION("scalar matrix") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);

      REQUIRE(1 - m == mat2(0, -1, -2, -3));
      REQUIRE(2.f - m == mat2(1, 0, -1, -2));
      REQUIRE(3.0 - m == mat2(2, 1, 0, -1));
    }

    SECTION("mat3") {
      mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

      REQUIRE(4 - m == mat3(3, 2, 1, 0, -1, -2, -3, -4, -5));
      REQUIRE(5.f - m == mat3(4, 3, 2, 1, 0, -1, -2, -3, -4));
      REQUIRE(6.0 - m == mat3(5, 4, 3, 2, 1, 0, -1, -2, -3));
    }

    SECTION("mat4") {
      mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

      REQUIRE(7 - m == mat4(6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9));
      REQUIRE(8.f - m == mat4(7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8));
      REQUIRE(9.0 - m == mat4(8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7));
    }

    SECTION("mat2x4") {
      mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

      REQUIRE(1 - m == mat2x4(0, -1, -2, -3, -4, -5, -6, -7));
      REQUIRE(2.f - m == mat2x4(1, 0, -1, -2, -3, -4, -5, -6));
      REQUIRE(3.0 - m == mat2x4(2, 1, 0, -1, -2, -3, -4, -5));
    }

    SECTION("mat4x2") {
      mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

      REQUIRE(4 - m == mat4x2(3, 2, 1, 0, -1, -2, -3, -4));
      REQUIRE(5.f - m == mat4x2(4, 3, 2, 1, 0, -1, -2, -3));
      REQUIRE(6.0 - m == mat4x2(5, 4, 3, 2, 1, 0, -1, -2));
    }
  }

  SECTION("matrix scalar") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);

      REQUIRE(m - 1 == mat2(0, 1, 2, 3));
      REQUIRE(m - 2.f  == mat2(-1, 0, 1, 2));
      REQUIRE(m - 3.0  == mat2(-2, -1, 0, 1));
    }

    SECTION("mat3") {
      mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

      REQUIRE(m - 4 == mat3(-3, -2, -1, 0, 1, 2, 3, 4, 5));
      REQUIRE(m - 5.f == mat3(-4, -3, -2, -1, 0, 1, 2, 3, 4));
      REQUIRE(m - 6.0 == mat3(-5, -4, -3, -2, -1, 0, 1, 2, 3));
    }

    SECTION("mat4") {
      mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

      REQUIRE(m - 7 == mat4(-6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
      REQUIRE(m - 8.f == mat4(-7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8));
      REQUIRE(m - 9.0 == mat4(-8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7));
    }

    SECTION("mat2x4") {
      mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

      REQUIRE(m - 1 == mat2x4(0, 1, 2, 3, 4, 5, 6, 7));
      REQUIRE(m - 2.f == mat2x4(-1, 0, 1, 2, 3, 4, 5, 6));
      REQUIRE(m - 3.0 == mat2x4(-2, -1, 0, 1, 2, 3, 4, 5));
    }

    SECTION("mat4x2") {
      mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

      REQUIRE(m - 4 == mat4x2(-3, -2, -1, 0, 1, 2, 3, 4));
      REQUIRE(m - 5.f == mat4x2(-4, -3, -2, -1, 0, 1, 2, 3));
      REQUIRE(m - 6.0 == mat4x2(-5, -4, -3, -2, -1, 0, 1, 2));
    }
  }

  SECTION("matrix matrix") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);
      mat2 n = mat2(4, 3, 2, 1);
      mat2 i = mat2(1, 0, 0, 1);

      REQUIRE(m - m == mat2(0, 0, 0, 0));
      REQUIRE(n - n == mat2(0, 0, 0, 0));
      REQUIRE(i - i == mat2(0, 0, 0, 0));

      REQUIRE(m - n == mat2(-3, -1, 1, 3));
      REQUIRE(n - m == mat2(3, 1, -1, -3));

      REQUIRE(m - i == mat2(0, 2, 3, 3));
      REQUIRE(i - m == mat2(0, -2, -3, -3));

      REQUIRE(n - i == mat2(3, 3, 2, 0));
      REQUIRE(i - n == mat2(-3, -3, -2, 0));
    }

    SECTION("mat3") {
      mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
      mat3 n = mat3(9, 8, 7, 6, 5, 4, 3, 2, 1);
      mat3 i = mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);

      REQUIRE(m - m == 0);
      REQUIRE(n - n == 0);
      REQUIRE(i - i == 0);

      REQUIRE(m - n == mat3(-8, -6, -4, -2, 0, 2, 4, 6, 8));
      REQUIRE(n - m == mat3(8, 6, 4, 2, 0, -2, -4, -6, -8));

      REQUIRE(m - i == mat3(0, 2, 3, 4, 4, 6, 7, 8, 8));
      REQUIRE(i - m == mat3(0, -2, -3, -4, -4, -6, -7, -8, -8));

      REQUIRE(n - i == mat3(8, 8, 7, 6, 4, 4, 3, 2, 0));
      REQUIRE(i - n == mat3(-8, -8, -7, -6, -4, -4, -3, -2, 0));
    }

    SECTION("mat4") {
      mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
      mat4 n = mat4(16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
      mat4 i = mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

      REQUIRE(m - m == 0);
      REQUIRE(n - n == 0);
      REQUIRE(i - i == 0);

      REQUIRE(m - n == mat4(-15, -13, -11, -9, -7, -5, -3, -1, 1, 3, 5, 7, 9, 11, 13, 15));
      REQUIRE(n - m == mat4(15, 13, 11, 9, 7, 5, 3, 1, -1, -3, -5, -7, -9, -11, -13, -15));

      REQUIRE(m - i == mat4(0, 2, 3, 4, 5, 5, 7, 8, 9, 10, 10, 12, 13, 14, 15, 15));
      REQUIRE(i - m == mat4(0, -2, -3, -4, -5, -5, -7, -8, -9, -10, -10, -12, -13, -14, -15, -15));

      REQUIRE(n - i == mat4(15, 15, 14, 13, 12, 10, 10, 9, 8, 7, 5, 5, 4, 3, 2, 0));
      REQUIRE(i - n == mat4(-15, -15, -14, -13, -12, -10, -10, -9, -8, -7, -5, -5, -4, -3, -2, 0));
    }
  }
}

TEST_CASE("matrix numeric operator *", "[mat][num]") {

  SECTION("scalar matrix") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);

      REQUIRE(1 * m == mat2(1, 2, 3, 4));
      REQUIRE(2.f * m == mat2(2, 4, 6, 8));
      REQUIRE(3.0 * m == mat2(3, 6, 9, 12));
    }

    SECTION("mat3") {
      mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

      REQUIRE(4 * m == mat3(4, 8, 12, 16, 20, 24, 28, 32, 36));
      REQUIRE(5.f * m == mat3(5, 10, 15, 20, 25, 30, 35, 40, 45));
      REQUIRE(6.0 * m == mat3(6, 12, 18, 24, 30, 36, 42, 48, 54));
    }

    SECTION("mat4") {
      mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

      REQUIRE(7 * m == mat4(7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112));
      REQUIRE(8.f * m == mat4(8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128));
      REQUIRE(9.0 * m == mat4(9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99, 108, 117, 126, 135, 144));
    }

    SECTION("mat2x4") {
      mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

      REQUIRE(1 * m == mat2x4(1, 2, 3, 4, 5, 6, 7, 8));
      REQUIRE(2.f * m == mat2x4(2, 4, 6, 8, 10, 12, 14, 16));
      REQUIRE(3.0 * m == mat2x4(3, 6, 9, 12, 15, 18, 21, 24));
    }

    SECTION("mat4x2") {
      mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

      REQUIRE(4 * m == mat4x2(4, 8, 12, 16, 20, 24, 28, 32));
      REQUIRE(5.f * m == mat4x2(5, 10, 15, 20, 25, 30, 35, 40));
      REQUIRE(6.0 * m == mat4x2(6, 12, 18, 24, 30, 36, 42, 48));
    }
  }

  SECTION("matrix scalar") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);

      REQUIRE(m * 1 == mat2(1, 2, 3, 4));
      REQUIRE(m * 2.f  == mat2(2, 4, 6, 8));
      REQUIRE(m * 3.0  == mat2(3, 6, 9, 12));
    }

    SECTION("mat3") {
      mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

      REQUIRE(m * 4 == mat3(4, 8, 12, 16, 20, 24, 28, 32, 36));
      REQUIRE(m * 5.f == mat3(5, 10, 15, 20, 25, 30, 35, 40, 45));
      REQUIRE(m * 6.0 == mat3(6, 12, 18, 24, 30, 36, 42, 48, 54));
    }

    SECTION("mat4") {
      mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

      REQUIRE(m * 7 == mat4(7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112));
      REQUIRE(m * 8.f == mat4(8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128));
      REQUIRE(m * 9.0 == mat4(9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99, 108, 117, 126, 135, 144));
    }

    SECTION("mat2x4") {
      mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

      REQUIRE(m * 1 == mat2x4(1, 2, 3, 4, 5, 6, 7, 8));
      REQUIRE(m * 2.f == mat2x4(2, 4, 6, 8, 10, 12, 14, 16));
      REQUIRE(m * 3.0 == mat2x4(3, 6, 9, 12, 15, 18, 21, 24));
    }

    SECTION("mat4x2") {
      mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

      REQUIRE(m * 4 == mat4x2(4, 8, 12, 16, 20, 24, 28, 32));
      REQUIRE(m * 5.f == mat4x2(5, 10, 15, 20, 25, 30, 35, 40));
      REQUIRE(m * 6.0 == mat4x2(6, 12, 18, 24, 30, 36, 42, 48));
    }
  }

  SECTION("vector matrix") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);
      vec2 v = vec2(1, 2);

      REQUIRE(v * m == vec2(7, 10));
      REQUIRE(v.yx * m == vec2(5, 8));
    }

    SECTION("mat3") {
      mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
      vec3 v = vec3(1, 2, 3);

      REQUIRE(v * m == vec3(30, 36, 42));
      REQUIRE(v.zyx * m == vec3(18, 24, 30));
    }

    SECTION("mat4") {
      mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
      vec4 v = vec4(1, 2, 3, 4);

      REQUIRE(v * m == vec4(90, 100, 110, 120));
      REQUIRE(v.wzyx * m == vec4(50, 60, 70, 80));
    }

    SECTION("mat<N, M>") {
      vec4 v = vec4(1, 2, 3, 4);

      REQUIRE(v.xy * mat2x2(1, 2, 3, 4) == vec2(7, 10));
      REQUIRE(v.xy * mat3x2(1, 2, 3, 4, 5, 6) == vec3(9, 12, 15));
      REQUIRE(v.xy * mat4x2(1, 2, 3, 4, 5, 6, 7, 8) == vec4(11, 14, 17, 20));

      REQUIRE(v.xyz * mat2x3(1, 2, 3, 4, 5, 6) == vec2(22, 28));
      REQUIRE(v.xyz * mat3x3(1, 2, 3, 4, 5, 6, 7, 8, 9) == vec3(30, 36, 42));
      REQUIRE(v.xyz * mat4x3(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) == vec4(38, 44, 50, 56));

      REQUIRE(v * mat2x4(1, 2, 3, 4, 5, 6, 7, 8) == vec2(50, 60));
      REQUIRE(v * mat3x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) == vec3(70, 80, 90));
      REQUIRE(v * mat4x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16) == vec4(90, 100, 110, 120));
    }
  }

  SECTION("matrix vector") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);
      vec2 v = vec2(1, 2);

      REQUIRE(m * v == vec2(5, 11));
      REQUIRE(m * v.yx == vec2(4, 10));
    }

    SECTION("mat3") {
      mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
      vec3 v = vec3(1, 2, 3);

      REQUIRE(m * v == vec3(14, 32, 50));
      REQUIRE(m * v.zyx == vec3(10, 28, 46));
    }

    SECTION("mat4") {
      mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
      vec4 v = vec4(1, 2, 3, 4);

      REQUIRE(m * v == vec4(30, 70, 110, 150));
      REQUIRE(m * v.wzyx == vec4(20, 60, 100, 140));
    }

    SECTION("mat<N, M>") {
      vec4 v = vec4(1, 2, 3, 4);

      REQUIRE(mat2x2(1, 2, 3, 4) * v.xy == vec2(5, 11));
      REQUIRE(mat2x3(1, 2, 3, 4, 5, 6) * v.xy == vec3(5, 11, 17));
      REQUIRE(mat2x4(1, 2, 3, 4, 5, 6, 7, 8) * v.xy == vec4(5, 11, 17, 23));

      REQUIRE(mat3x2(1, 2, 3, 4, 5, 6) * v.xyz == vec2(14, 32));
      REQUIRE(mat3x3(1, 2, 3, 4, 5, 6, 7, 8, 9) * v.xyz == vec3(14, 32, 50));
      REQUIRE(mat3x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) * v.xyz == vec4(14, 32, 50, 68));

      REQUIRE(mat4x2(1, 2, 3, 4, 5, 6, 7, 8) * v == vec2(30, 70));
      REQUIRE(mat4x3(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) * v == vec3(30, 70, 110));
      REQUIRE(mat4x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16) * v == vec4(30, 70, 110, 150));
    }
  }

  SECTION("matrix matrix") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);
      mat2 n = mat2(-2, 1, 1.5, -0.5);
      mat2 i = mat2(1, 0, 0, 1);

      REQUIRE(m * i == m);
      REQUIRE(n * i == n);
      REQUIRE(m * n == i);
      REQUIRE(n * m == i);
    }

    SECTION("mat4") {
      mat4 t = mat4(1, 0, 0, 2, 0, 1, 0, 2, 0, 0, 1, 0, 0, 0, 0, 1);
      mat4 s = mat4(3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1);

      REQUIRE(t * s == mat4(3, 0, 0, 2, 0, 3, 0, 2, 0, 0, 3, 0, 0, 0, 0, 1));
      REQUIRE(s * t == mat4(3, 0, 0, 6, 0, 3, 0, 6, 0, 0, 3, 0, 0, 0, 0, 1));
    }

    SECTION("mat<N, M>") {
      mat2x2 m22 = mat2x2(1, 2, 3, 4);
      mat2x3 m23 = mat2x3(1, 2, 3, 4, 5, 6);
      mat2x4 m24 = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

      mat3x2 m32 = mat3x2(1, 2, 3, 4, 5, 6);
      mat3x3 m33 = mat3x3(1, 2, 3, 4, 5, 6, 7, 8, 9);
      mat3x4 m34 = mat3x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);

      mat4x2 m42 = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);
      mat4x3 m43 = mat4x3(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
      mat4x4 m44 = mat4x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);


      REQUIRE(m22 * m22 == mat2x2(7, 10, 15, 22));
      REQUIRE(m22 * m32 == mat3x2(9, 12, 15, 19, 26, 33));
      REQUIRE(m22 * m42 == mat4x2(11, 14, 17, 20, 23, 30, 37, 44));

      REQUIRE(m23 * m22 == mat2x3(7, 10, 15, 22, 23, 34));
      REQUIRE(m23 * m32 == mat3x3(9, 12, 15, 19, 26, 33, 29, 40, 51));
      REQUIRE(m23 * m42 == mat4x3(11, 14, 17, 20, 23, 30, 37, 44, 35, 46, 57, 68));

      REQUIRE(m24 * m22 == mat2x4(7, 10, 15, 22, 23, 34, 31, 46));
      REQUIRE(m24 * m32 == mat3x4(9, 12, 15, 19, 26, 33, 29, 40, 51, 39, 54, 69));
      REQUIRE(m24 * m42 == mat4x4(11, 14, 17, 20, 23, 30, 37, 44, 35, 46, 57, 68, 47, 62, 77, 92));


      REQUIRE(m32 * m23 == mat2x2(22, 28, 49, 64));
      REQUIRE(m32 * m33 == mat3x2(30, 36, 42, 66, 81, 96));
      REQUIRE(m32 * m43 == mat4x2(38, 44, 50, 56, 83, 98, 113, 128));

      REQUIRE(m33 * m23 == mat2x3(22, 28, 49, 64, 76, 100));
      REQUIRE(m33 * m33 == mat3x3(30, 36, 42, 66, 81, 96, 102, 126, 150));
      REQUIRE(m33 * m43 == mat4x3(38, 44, 50, 56, 83, 98, 113, 128, 128, 152, 176, 200));

      REQUIRE(m34 * m23 == mat2x4(22, 28, 49, 64, 76, 100, 103, 136));
      REQUIRE(m34 * m33 == mat3x4(30, 36, 42, 66, 81, 96, 102, 126, 150, 138, 171, 204));
      REQUIRE(m34 * m43 == mat4x4(38, 44, 50, 56, 83, 98, 113, 128, 128, 152, 176, 200, 173, 206, 239, 272));


      REQUIRE(m42 * m24 == mat2x2(50, 60, 114, 140));
      REQUIRE(m42 * m34 == mat3x2(70, 80, 90, 158, 184, 210));
      REQUIRE(m42 * m44 == mat4x2(90, 100, 110, 120, 202, 228, 254, 280));

      REQUIRE(m43 * m24 == mat2x3(50, 60, 114, 140, 178, 220));
      REQUIRE(m43 * m34 == mat3x3(70, 80, 90, 158, 184, 210, 246, 288, 330));
      REQUIRE(m43 * m44 == mat4x3(90, 100, 110, 120, 202, 228, 254, 280, 314, 356, 398, 440));

      REQUIRE(m44 * m24 == mat2x4(50, 60, 114, 140, 178, 220, 242, 300));
      REQUIRE(m44 * m34 == mat3x4(70, 80, 90, 158, 184, 210, 246, 288, 330, 334, 392, 450));
      REQUIRE(m44 * m44 == mat4x4(90, 100, 110, 120, 202, 228, 254, 280, 314, 356, 398, 440, 426, 484, 542, 600));
    }
  }
}

TEST_CASE("matrix numeric operator /", "[mat][num]") {

  SECTION("scalar matrix") {

    SECTION("mat2") {
      mat2 m = mat2(1, 0.5, 0.25, 0.125);

      REQUIRE(1 / m == mat2(1, 2, 4, 8));
      REQUIRE(2.f / m == mat2(2, 4, 8, 16));
      REQUIRE(3.0 / m == mat2(3, 6, 12, 24));
    }

    SECTION("mat2x3") {
      mat2x3 m = mat2x3(1.0, 0.8, 0.5, 0.4, 0.2, 0.1);

      REQUIRE(1 / m == mat2x3(1, 1.25, 2, 2.5, 5, 10));
      REQUIRE(2.f / m == mat2x3(2, 2.5, 4, 5, 10, 20));
      REQUIRE(3.f / m == mat2x3(3, 3.75, 6, 7.5, 15, 30));
    }

    SECTION("mat3x2") {
      mat3x2 m = mat3x2(1.0, 0.8, 0.5, 0.4, 0.2, 0.1);

      REQUIRE(1 / m == mat3x2(1, 1.25, 2, 2.5, 5, 10));
      REQUIRE(2.f / m == mat3x2(2, 2.5, 4, 5, 10, 20));
      REQUIRE(3.f / m == mat3x2(3, 3.75, 6, 7.5, 15, 30));
    }
  }

  SECTION("matrix scalar") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);

      REQUIRE(mat2(1, 2, 3, 4) / 1 == m);
      REQUIRE(mat2(2, 4, 6, 8) / 2.f == m);
      REQUIRE(mat2(3, 6, 9, 12) / 3.0 == m);
    }

    SECTION("mat2x3") {
      mat2x3 m = mat2x3(1, 2, 3, 4, 5, 6);

      REQUIRE(mat2x3(1, 2, 3, 4, 5, 6) / 1 == m);
      REQUIRE(mat2x3(2, 4, 6, 8, 10, 12) / 2.f == m);
      REQUIRE(mat2x3(3, 6, 9, 12, 15, 18) / 3.f == m);
    }

    SECTION("mat3x2") {
      mat3x2 n = mat3x2(1, 2, 3, 4, 5, 6);

      REQUIRE(mat3x2(1, 2, 3, 4, 5, 6) / 1 == n);
      REQUIRE(mat3x2(2, 4, 6, 8, 10, 12) / 2.f == n);
      REQUIRE(mat3x2(3, 6, 9, 12, 15, 18) / 3.f == n);
    }
  }

  SECTION("matrix matrix") {

    SECTION("mat2") {
      mat2 m = mat2(8, 4, 2, 1);
      mat2 n = mat2(0.5, 0.5, 0.25, 0.25);

      REQUIRE(m / m == mat2(1, 1, 1, 1));
      REQUIRE(n / n == mat2(1, 1, 1, 1));

      REQUIRE(m / n == mat2(16, 8, 8, 4));
      REQUIRE(n / m == mat2(0.0625, 0.125, 0.125, 0.25));
    }
  }
}
