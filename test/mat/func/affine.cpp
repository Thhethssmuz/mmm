#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto am_id1 = UnitTest("affine matrices - identity (1)", +[] {

    if (identity<float, 2, 2>() != mat2x2(1, 0, 0, 1)) return false;
    if (identity<float, 2, 3>() != mat2x3(1, 0, 0, 1, 0, 0)) return false;
    if (identity<float, 2, 4>() != mat2x4(1, 0, 0, 1, 0, 0, 0, 0)) return false;

    if (identity<float, 3, 2>() != mat3x2(1, 0, 0, 0, 1, 0)) return false;
    if (identity<float, 3, 3>() != mat3x3(1, 0, 0, 0, 1, 0, 0, 0, 1)) return false;
    if (identity<float, 3, 4>() != mat3x4(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)) return false;

    if (identity<float, 4, 2>() != mat4x2(1, 0, 0, 0, 0, 1, 0, 0)) return false;
    if (identity<float, 4, 3>() != mat4x3(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0)) return false;
    if (identity<float, 4, 4>() != mat4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1)) return false;

    return true;
  });
  auto am_id2 = UnitTest("affine matrices - identity (2)", +[] {

    if (mat2::identity != mat2(1, 0, 0, 1)) return false;
    if (mat3::identity != mat3(1, 0, 0, 0, 1, 0, 0, 0, 1)) return false;
    if (mat4::identity != mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1)) return false;

    return true;
  });

  auto am_trans1 = UnitTest("affine matrices - translate (1)", +[] {
    mat4 t1 = translate(1.f, 2.f, 3.f);
    mat4 t2 = translate(vec3(3, 2, 1));

    if (t1 != mat4(1, 0, 0, 1, 0, 1, 0, 2, 0, 0, 1, 3, 0, 0, 0, 1)) return false;
    if (t2 != mat4(1, 0, 0, 3, 0, 1, 0, 2, 0, 0, 1, 1, 0, 0, 0, 1)) return false;

    return true;
  });

  auto am_rot1 = UnitTest("affine matrices - rotate (1)", +[] {
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

  auto am_scale1 = UnitTest("affine matrices - scale (1)", +[] {
    mat4 s = scale(2.f, 3.f, 4.f);

    if (s != mat4(2,0,0,0, 0,3,0,0, 0,0,4,0, 0,0,0,1)) return false;

    return true;
  });
}
