#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("matrix comparison operator <", "[mat][comp]") {

  mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  mat3 n = mat3(0, 1, 2, 3, 4, 5, 6, 7, 8);

  REQUIRE(0 < m);
  REQUIRE(m < 10);
  REQUIRE(n < m);
}

TEST_CASE("matrix comparison operator <=", "[mat][comp]") {

  mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  mat3 n = mat3(0, 2, 3, 3, 5, 5, 6, 8, 8);

  REQUIRE(1 <= m);
  REQUIRE(m <= 9);
  REQUIRE(n <= m);
}

TEST_CASE("matrix comparison operator >=", "[mat][comp]") {

  mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  mat3 n = mat3(0, 2, 3, 3, 5, 5, 6, 8, 8);

  REQUIRE(9 >= m);
  REQUIRE(m >= 1);
  REQUIRE(m >= n);
}

TEST_CASE("matrix comparison operator >", "[mat][comp]") {

  mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  mat3 n = mat3(0, 1, 2, 3, 4, 5, 6, 7, 8);

  REQUIRE(10 > m);
  REQUIRE(m > 0);
  REQUIRE(m > n);
}

TEST_CASE("matrix comparison operator ==", "[mat][comp]") {

  mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  mat3 n = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  mat3 o = mat3(3, 3, 3, 3, 3, 3, 3, 3, 3);

  REQUIRE(3 == o);
  REQUIRE(o == 3);
  REQUIRE(m == n);
}

TEST_CASE("matrix comparison operator !=", "[mat][comp]") {

  mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
  mat3 n = mat3(9, 8, 7, 6, 5, 4, 3, 2, 1);

  REQUIRE(0 != m);
  REQUIRE(m != 3);
  REQUIRE(m != n);
}
