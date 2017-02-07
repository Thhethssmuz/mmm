#include <catch.hpp>
#include <mmm.hpp>

using namespace mmm;

TEST_CASE("vector exponential function pow", "[vec][exp]") {

  SECTION("scalar") {
    REQUIRE(pow(0, 2) == 0);
    REQUIRE(pow(1.f, 2) == 1);
    REQUIRE(pow(2.0, 2) == 4);
    REQUIRE(pow(4.l, 2) == 16);
  }

  SECTION("vec2") {
    vec2 v = vec2(0, 1);

    REQUIRE(pow(v, 2) == vec2(0, 1));
    REQUIRE(pow(2, v) == vec2(1, 2));

    REQUIRE(pow(v.xy, 2) == vec2(0, 1));
    REQUIRE(pow(2, v.xy) == vec2(1, 2));

    REQUIRE(pow(v, v) == vec2(1, 1));
    REQUIRE(pow(v.xy, v.xy) == vec2(1, 1));
  }

  SECTION("vec3") {
    vec3 v = vec3(0, 1, 2);

    REQUIRE(pow(v, 2) == vec3(0, 1, 4));
    REQUIRE(pow(2, v) == vec3(1, 2, 4));

    REQUIRE(pow(v.xyz, 2) == vec3(0, 1, 4));
    REQUIRE(pow(2, v.xyz) == vec3(1, 2, 4));

    REQUIRE(pow(v, v) == vec3(1, 1, 4));
    REQUIRE(pow(v.xyz, v.xyz) == vec3(1, 1, 4));
  }

  SECTION("vec4") {
    vec4 v = vec4(0, 1, 2, 4);

    REQUIRE(pow(v, 2) == vec4(0, 1, 4, 16));
    REQUIRE(pow(2, v) == vec4(1, 2, 4, 16));

    REQUIRE(pow(v.xyzw, 2) == vec4(0, 1, 4, 16));
    REQUIRE(pow(2, v.xyzw) == vec4(1, 2, 4, 16));

    REQUIRE(pow(v, v) == vec4(1, 1, 4, 256));
    REQUIRE(pow(v.xyzw, v.xyzw) == vec4(1, 1, 4, 256));
  }
}

TEST_CASE("vector exponential function exp", "[vec][exp]") {

  SECTION("scalar") {
    REQUIRE(exp(0) == Approx(1));
    REQUIRE(exp(1) == Approx(2.71828));
    REQUIRE(exp(2.f) == Approx(7.38906));
    REQUIRE(exp(-1.0) == Approx(0.367879));
  }

  SECTION("vec2") {
    vec2 v = exp(vec2(0, 1));
    REQUIRE(v[0] == Approx(1));
    REQUIRE(v[1] == Approx(2.71828));
  }

  SECTION("vec3") {
    vec3 v = exp(vec3(0, 1, 2));
    REQUIRE(v[0] == Approx(1));
    REQUIRE(v[1] == Approx(2.71828));
    REQUIRE(v[2] == Approx(7.38906));
  }

  SECTION("vec4") {
    vec4 v = exp(vec4(0, 1, 2, -1));
    REQUIRE(v[0] == Approx(1));
    REQUIRE(v[1] == Approx(2.71828));
    REQUIRE(v[2] == Approx(7.38906));
    REQUIRE(v[3] == Approx(0.367879));
  }
}

TEST_CASE("vector exponential function log", "[vec][exp]") {

  SECTION("scalar") {
    REQUIRE(log(1) == Approx(0));
    REQUIRE(log(2) == Approx(0.69315));
    REQUIRE(log(3.f) == Approx(1.09861));
    REQUIRE(log(4.0) == Approx(1.38629));
  }

  SECTION("vec2") {
    vec2 v = log(vec2(1, 2));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(0.69315));
  }

  SECTION("vec3") {
    vec3 v = log(vec3(1, 2, 3));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(0.69315));
    REQUIRE(v[2] == Approx(1.09861));
  }

  SECTION("vec4") {
    vec4 v = log(vec4(1, 2, 3, 4));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(0.69315));
    REQUIRE(v[2] == Approx(1.09861));
    REQUIRE(v[3] == Approx(1.38629));
  }
}

TEST_CASE("vector exponential function exp2", "[vec][exp]") {

  SECTION("scalar") {
    REQUIRE(exp2(0) == Approx(1));
    REQUIRE(exp2(1) == Approx(2));
    REQUIRE(exp2(2.f) == Approx(4));
    REQUIRE(exp2(-1.0) == Approx(0.5));
  }

  SECTION("vec2") {
    vec2 v = exp2(vec2(0, 1));
    REQUIRE(v[0] == Approx(1));
    REQUIRE(v[1] == Approx(2));
  }

  SECTION("vec3") {
    vec3 v = exp2(vec3(0, 1, 2));
    REQUIRE(v[0] == Approx(1));
    REQUIRE(v[1] == Approx(2));
    REQUIRE(v[2] == Approx(4));
  }

  SECTION("vec4") {
    vec4 v = exp2(vec4(0, 1, 2, -1));
    REQUIRE(v[0] == Approx(1));
    REQUIRE(v[1] == Approx(2));
    REQUIRE(v[2] == Approx(4));
    REQUIRE(v[3] == Approx(0.5));
  }
}

TEST_CASE("vector exponential function log2", "[vec][exp]") {

  SECTION("scalar") {
    REQUIRE(log2(1) == Approx(0));
    REQUIRE(log2(2) == Approx(1));
    REQUIRE(log2(3.f) == Approx(1.58496));
    REQUIRE(log2(4.0) == Approx(2));
  }

  SECTION("vec2") {
    vec2 v = log2(vec2(1, 2));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(1));
  }

  SECTION("vec3") {
    vec3 v = log2(vec3(1, 2, 3));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(1));
    REQUIRE(v[2] == Approx(1.58496));
  }

  SECTION("vec4") {
    vec4 v = log2(vec4(1, 2, 3, 4));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(1));
    REQUIRE(v[2] == Approx(1.58496));
    REQUIRE(v[3] == Approx(2));
  }
}

TEST_CASE("vector exponential function sqrt", "[vec][exp]") {

  SECTION("scalar") {
    REQUIRE(sqrt(0) == Approx(0));
    REQUIRE(sqrt(1) == Approx(1));
    REQUIRE(sqrt(2.f) == Approx(1.41421));
    REQUIRE(sqrt(3.0) == Approx(1.73205));
  }

  SECTION("vec2") {
    vec2 v = sqrt(vec2(0, 1));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(1));
  }

  SECTION("vec3") {
    vec3 v = sqrt(vec3(0, 1, 2));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(1));
    REQUIRE(v[2] == Approx(1.41421));
  }

  SECTION("vec4") {
    vec4 v = sqrt(vec4(0, 1, 2, 3));
    REQUIRE(v[0] == Approx(0));
    REQUIRE(v[1] == Approx(1));
    REQUIRE(v[2] == Approx(1.41421));
    REQUIRE(v[3] == Approx(1.73205));
  }
}

TEST_CASE("vector exponential function inversesqrt", "[vec][exp]") {

  SECTION("scalar") {
    REQUIRE(inversesqrt(1) == Approx(1));
    REQUIRE(inversesqrt(2) == Approx(0.70711));
    REQUIRE(inversesqrt(3.f) == Approx(0.57735));
    REQUIRE(inversesqrt(4.0) == Approx(0.5));
  }

  SECTION("vec2") {
    vec2 v = inversesqrt(vec2(1, 2));
    REQUIRE(v[0] == Approx(1));
    REQUIRE(v[1] == Approx(0.70711));
  }

  SECTION("vec3") {
    vec3 v = inversesqrt(vec3(1, 2, 3));
    REQUIRE(v[0] == Approx(1));
    REQUIRE(v[1] == Approx(0.70711));
    REQUIRE(v[2] == Approx(0.57735));
  }

  SECTION("vec4") {
    vec4 v = inversesqrt(vec4(1, 2, 3, 4));
    REQUIRE(v[0] == Approx(1));
    REQUIRE(v[1] == Approx(0.70711));
    REQUIRE(v[2] == Approx(0.57735));
    REQUIRE(v[3] == Approx(0.5));
  }
}
