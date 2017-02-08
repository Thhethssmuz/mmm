#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("matrix assignment operator +=", "[mat][asig]") {

  SECTION("scalar") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);

      m += 1;
      REQUIRE(m == mat2(2, 3, 4, 5));
      m += 1.f;
      REQUIRE(m == mat2(3, 4, 5, 6));
      m += 1.0;
      REQUIRE(m == mat2(4, 5, 6, 7));
    }

    SECTION("mat3") {
      mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

      m += 4;
      REQUIRE(m == mat3(5, 6, 7, 8, 9, 10, 11, 12, 13));
      m += 1.f;
      REQUIRE(m == mat3(6, 7, 8, 9, 10, 11, 12, 13, 14));
      m += 1.0;
      REQUIRE(m == mat3(7, 8, 9, 10, 11, 12, 13, 14, 15));
    }

    SECTION("mat4") {
      mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

      m += 7;
      REQUIRE(m == mat4(8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23));
      m += 1.f;
      REQUIRE(m == mat4(9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24));
      m += 1.0;
      REQUIRE(m == mat4(10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25));
    }

    SECTION("mat2x4") {
      mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

      m += 1;
      REQUIRE(m == mat2x4(2, 3, 4, 5, 6, 7, 8, 9));
      m += 1.f;
      REQUIRE(m == mat2x4(3, 4, 5, 6, 7, 8, 9, 10));
      m += 1.0;
      REQUIRE(m == mat2x4(4, 5, 6, 7, 8, 9, 10, 11));
    }

    SECTION("mat4x2") {
      mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

      m += 4;
      REQUIRE(m == mat4x2(5, 6, 7, 8, 9, 10, 11, 12));
      m += 1.f;
      REQUIRE(m == mat4x2(6, 7, 8, 9, 10, 11, 12, 13));
      m += 1.0;
      REQUIRE(m == mat4x2(7, 8, 9, 10, 11, 12, 13, 14));
    }
  }

  SECTION("matrix") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);
      mat2 n = mat2(4, 3, 2, 1);
      mat2 i = mat2(1, 0, 0, 1);

      m += m;
      REQUIRE(m == mat2(2, 4, 6, 8));
      n += n;
      REQUIRE(n == mat2(8, 6, 4, 2));
      i += i;
      REQUIRE(i == mat2(2, 0, 0, 2));
    }

    SECTION("mat3") {
      mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
      mat3 n = mat3(9, 8, 7, 6, 5, 4, 3, 2, 1);

      m += n;
      REQUIRE(m == 10);
    }

    SECTION("mat4") {
      mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
      mat4 n = mat4(16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
      mat4 i = mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

      m += i;
      REQUIRE(m == mat4(2, 2, 3, 4, 5, 7, 7, 8, 9, 10, 12, 12, 13, 14, 15, 17));

      i += n;
      REQUIRE(i == mat4(17, 15, 14, 13, 12, 12, 10, 9, 8, 7, 7, 5, 4, 3, 2, 2));
    }
  }
}

TEST_CASE("matrix assignment operator -=", "[mat][asig]") {

  SECTION("scalar") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);

      m -= 1;
      REQUIRE(m == mat2(0, 1, 2, 3));
      m -= 1.f;
      REQUIRE(m == mat2(-1, 0, 1, 2));
      m -= 1.0;
      REQUIRE(m == mat2(-2, -1, 0, 1));
    }

    SECTION("mat3") {
      mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

      m -= 4;
      REQUIRE(m == mat3(-3, -2, -1, 0, 1, 2, 3, 4, 5));
      m -= 1.f;
      REQUIRE(m == mat3(-4, -3, -2, -1, 0, 1, 2, 3, 4));
      m -= 1.0;
      REQUIRE(m == mat3(-5, -4, -3, -2, -1, 0, 1, 2, 3));
    }

    SECTION("mat4") {
      mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

      m -= 7;
      REQUIRE(m == mat4(-6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
      m -= 1.f;
      REQUIRE(m == mat4(-7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8));
      m -= 1.0;
      REQUIRE(m == mat4(-8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7));
    }

    SECTION("mat2x4") {
      mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

      m -= 1;
      REQUIRE(m == mat2x4(0, 1, 2, 3, 4, 5, 6, 7));
      m -= 1.f;
      REQUIRE(m == mat2x4(-1, 0, 1, 2, 3, 4, 5, 6));
      m -= 1.f;
      REQUIRE(m == mat2x4(-2, -1, 0, 1, 2, 3, 4, 5));
    }

    SECTION("mat4x2") {
      mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

      m -= 4;
      REQUIRE(m == mat4x2(-3, -2, -1, 0, 1, 2, 3, 4));
      m -= 1.f;
      REQUIRE(m == mat4x2(-4, -3, -2, -1, 0, 1, 2, 3));
      m -= 1.0;
      REQUIRE(m == mat4x2(-5, -4, -3, -2, -1, 0, 1, 2));
    }
  }

  SECTION("matrix") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);
      mat2 n = mat2(4, 3, 2, 1);
      mat2 i = mat2(1, 0, 0, 1);

      m -= m;
      REQUIRE(m == mat2(0, 0, 0, 0));
      n -= n;
      REQUIRE(n == mat2(0, 0, 0, 0));
      i -= i;
      REQUIRE(i == mat2(0, 0, 0, 0));
    }

    SECTION("mat3") {
      mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
      mat3 n = mat3(9, 8, 7, 6, 5, 4, 3, 2, 1);

      m -= n;
      REQUIRE(m == mat3(-8, -6, -4, -2, 0, 2, 4, 6, 8));
    }

    SECTION("mat4") {
      mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
      mat4 n = mat4(16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
      mat4 i = mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

      m -= i;
      REQUIRE(m == mat4(0, 2, 3, 4, 5, 5, 7, 8, 9, 10, 10, 12, 13, 14, 15, 15));

      i -= n;
      REQUIRE(i == mat4(-15, -15, -14, -13, -12, -10, -10, -9, -8, -7, -5, -5, -4, -3, -2, 0));
    }
  }
}

TEST_CASE("matrix assignment operator *=", "[mat][asig]") {

  SECTION("scalar") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);

      m *= 1;
      REQUIRE(m == mat2(1, 2, 3, 4));
      m *= 2.f;
      REQUIRE(m == mat2(2, 4, 6, 8));
    }

    SECTION("mat3") {
      mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

      m *= 1;
      REQUIRE(m == mat3(1, 2, 3, 4, 5, 6, 7, 8, 9));
      m *= 4.0;
      REQUIRE(m == mat3(4, 8, 12, 16, 20, 24, 28, 32, 36));
    }

    SECTION("mat4") {
      mat4 m = mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

      m *= 1.f;
      REQUIRE(m == mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16));
      m *= 7;
      REQUIRE(m == mat4(7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112));
    }

    SECTION("mat2x4") {
      mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

      m *= 1;
      REQUIRE(m == mat2x4(1, 2, 3, 4, 5, 6, 7, 8));
      m *= 2.f;
      REQUIRE(m == mat2x4(2, 4, 6, 8, 10, 12, 14, 16));
    }

    SECTION("mat4x2") {
      mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

      m *= 1;
      REQUIRE(m == mat4x2(1, 2, 3, 4, 5, 6, 7, 8));
      m *= 4.0;
      REQUIRE(m == mat4x2(4, 8, 12, 16, 20, 24, 28, 32));
    }
  }

  SECTION("matrix") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);
      mat2 n = mat2(-2, 1, 1.5, -0.5);
      mat2 i = mat2(1, 0, 0, 1);

      m *= n;
      REQUIRE(m == i);
    }

    SECTION("mat3") {
      mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

      m *= m;
      REQUIRE(m == mat3(30, 36, 42, 66, 81, 96, 102, 126, 150));
    }

    SECTION("mat4") {
      mat4 t1 = mat4(1, 0, 0, 2, 0, 1, 0, 2, 0, 0, 1, 0, 0, 0, 0, 1);
      mat4 t2 = t1;
      mat4 s1 = mat4(3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1);
      mat4 s2 = s1;

      t1 *= s1;
      REQUIRE(t1 == mat4(3, 0, 0, 2, 0, 3, 0, 2, 0, 0, 3, 0, 0, 0, 0, 1));

      s2 *= t2;
      REQUIRE(s2 == mat4(3, 0, 0, 6, 0, 3, 0, 6, 0, 0, 3, 0, 0, 0, 0, 1));
    }
  }
}

TEST_CASE("matrix assignment operator /=", "[mat][asig]") {

  SECTION("scalar") {

    SECTION("mat2") {
      mat2 m = mat2(1, 2, 3, 4);
      mat2 t;

      t = mat2(1, 2, 3, 4);
      t /= 1;
      REQUIRE(t == m);

      t = mat2(2, 4, 6, 8);
      t /= 2.f;
      REQUIRE(t == m);

      t = mat2(3, 6, 9, 12);
      t /= 3.0;
      REQUIRE(t == m);
    }
  }
}
