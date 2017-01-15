#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto ami = UnitTest("affine matrices - identity", +[] {

    if (mat2::identity != mat2(1,0, 0,1)) return false;
    if (mat3::identity != mat3(1,0,0, 0,1,0, 0,0,1)) return false;
    if (mat4::identity != mat4(1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1)) return false;

    if (identity<float, 2>() != mat2(1,0, 0,1)) return false;
    if (identity<float, 3>() != mat3(1,0,0, 0,1,0, 0,0,1)) return false;
    if (identity<float, 4>() != mat4(1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1)) return false;

    return true;
  });

  auto amt = UnitTest("affine matrices - translate", +[] {
    mat4 t1 = translate(1.f, 2.f, 3.f);
    mat4 t2 = translate(vec3(3, 2, 1));

    if (t1 != mat4(1,0,0,1, 0,1,0,2, 0,0,1,3, 0,0,0,1)) return false;
    if (t2 != mat4(1,0,0,3, 0,1,0,2, 0,0,1,1, 0,0,0,1)) return false;

    return true;
  });

  auto amr = UnitTest("affine matrices - rotate", +[] {
    mat4 rx = rotate_x(45.f);
    mat4 ry = rotate_y(45.f);
    mat4 rz = rotate_z(45.f);

    if (length(rx[0] - vec4(1, 0, 0, 0)) > 0.0001) return false;
    if (length(rx[1] - vec4(0, 0.7071, -0.7071, 0)) > 0.0001) return false;
    if (length(rx[2] - vec4(0, 0.7071, 0.7071, 0)) > 0.0001) return false;
    if (length(rx[3] - vec4(0, 0, 0, 1)) > 0.0001) return false;

    if (length(ry[0] - vec4(0.7071, 0, 0.7071, 0)) > 0.0001) return false;
    if (length(ry[1] - vec4(0, 1, 0, 0)) > 0.0001) return false;
    if (length(ry[2] - vec4(-0.7071, 0, 0.7071, 0)) > 0.0001) return false;
    if (length(ry[3] - vec4(0, 0, 0, 1)) > 0.0001) return false;

    if (length(rz[0] - vec4(0.7071, -0.7071, 0, 0)) > 0.0001) return false;
    if (length(rz[1] - vec4(0.7071, 0.7071, 0, 0)) > 0.0001) return false;
    if (length(rz[2] - vec4(0, 0, 1, 0)) > 0.0001) return false;
    if (length(rz[3] - vec4(0, 0, 0, 1)) > 0.0001) return false;

    return true;
  });

  auto ams = UnitTest("affine matrices - scale", +[] {
    mat4 s = scale(2.f, 3.f, 4.f);

    if (s != mat4(2,0,0,0, 0,3,0,0, 0,0,4,0, 0,0,0,1)) return false;

    return true;
  });
}
