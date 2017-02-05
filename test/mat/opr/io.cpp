#include <unittest.hpp>
#include <mmm.hpp>
#include <sstream>

namespace {
  using namespace mmm;

  auto stream1 = UnitTest("matrix io operator << (1)", +[] {
    mat3 m = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);

    std::stringstream ss;
    ss << m;

    std::string printed = ss.str();
    std::string expected = "[[1, 2, 3], [4, 5, 6], [7, 8, 9]]";

    return printed == expected;
  });
  auto stream2 = UnitTest("matrix io operator << (2)", +[] {
    mat2x4 m = mat2x4(1, 2, 3, 4, 5, 6, 7, 8);

    std::stringstream ss;
    ss << m;

    std::string printed = ss.str();
    std::string expected = "[[1, 2], [3, 4], [5, 6], [7, 8]]";

    return printed == expected;
  });
  auto stream3 = UnitTest("matrix io operator << (3)", +[] {
    mat4x2 m = mat4x2(1, 2, 3, 4, 5, 6, 7, 8);

    std::stringstream ss;
    ss << m;

    std::string printed = ss.str();
    std::string expected = "[[1, 2, 3, 4], [5, 6, 7, 8]]";

    return printed == expected;
  });
}
