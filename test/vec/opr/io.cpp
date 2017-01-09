#include <unittest.hpp>
#include <mmm.hpp>
#include <sstream>

namespace {
  using namespace mmm;

  auto stream = UnitTest("vector io operator <<", +[]() {
    ivec4 v = ivec4(-1, 0, 1, 2);
    vec4 u = vec4(0, 0.5f, 1, 1.5f);

    std::stringstream ss;
    ss << v << u;

    std::string printed = ss.str();
    std::string expected = "[-1, 0, 1, 2][0, 0.5, 1, 1.5]";

    return printed == expected;
  });
}
