#include <unittest.hpp>
#include <mmm.hpp>

namespace {

  auto swiz_add1 = UnitTest("swizzle assignment operator += (1)", +[]() {
    ivec4 v = ivec4(0, 1, 2, 3);

    v.x += 1;
    v.xy += 1;
    v.zyx += 1;
    v.xwzy += 1;

    if (v != 4) return false;

    return true;
  });
  auto swiz_add2 = UnitTest("swizzle assignment operator += (2)", +[]() {
    ivec4 v = ivec4(4);

    v.xy += ivec2(2, 1);
    v.yzw += ivec3(1, 2, 3);
    v.xyzw += ivec4(-1, 0, 1, 1);

    if (v != ivec4(5, 6, 7, 8)) return false;

    return true;
  });
  auto swiz_add3 = UnitTest("swizzle assignment operator += (3)", +[]() {
    ivec4 v = ivec4(5, 6, 7, 8);

    v.x += 1;
    v.yy += 1;
    v.zzz += 1;
    v.wwww += 1;

    if (v != ivec4(6, 8, 10, 12)) return false;

    return true;
  });
  auto swiz_add4 = UnitTest("swizzle assignment operator += (4)", +[]() {
    ivec4 v = ivec4(6, 8, 10, 12);

    v.x += v.x;
    v.yx += v.xy;
    v.zyx += v.xyz;
    v.wzyx += v.xyzw;

    if (v != ivec4(42, 70, 70, 42)) return false;

    return true;
  });

  auto swiz_sub1 = UnitTest("swizzle assignment operator -= (1)", +[]() {
    ivec4 v = ivec4(3, 2, 1, 0);

    v.x -= 1;
    v.xy -= 1;
    v.zyx -= 1;
    v.xwzy -= 1;

    if (v != -1) return false;

    return true;
  });
  auto swiz_sub2 = UnitTest("swizzle assignment operator -= (2)", +[]() {
    ivec4 v = ivec4(-1);

    v.xy -= ivec2(2, 1);
    v.yzw -= ivec3(1, 2, 3);
    v.xyzw -= ivec4(-1, 0, 1, 1);

    if (v != ivec4(-2, -3, -4, -5)) return false;

    return true;
  });
  auto swiz_sub3 = UnitTest("swizzle assignment operator -= (3)", +[]() {
    ivec4 v = ivec4(-2, -3, -4, -5);

    v.x -= 1;
    v.yy -= 1;
    v.zzz -= 1;
    v.wwww -= 1;

    if (v != ivec4(-3, -5, -7, -9)) return false;

    return true;
  });
  auto swiz_sub4 = UnitTest("swizzle assignment operator -= (4)", +[]() {
    ivec4 v = ivec4(-3, -5, -7, -9);

    v.x -= v.x;
    v.yx -= v.xy;
    v.zyx -= v.xyz;
    v.wzyx -= v.xyzw;

    if (v != ivec4(21, 12, -12, -21)) return false;

    return true;
  });

  auto swiz_mult1 = UnitTest("swizzle assignment operator *= (1)", +[]() {
    ivec4 v = ivec4(1, 2, 4, 8);

    v.x *= 2;
    v.xy *= 2;
    v.zyx *= 2;
    v.xwzy *= 2;

    if (v != 16) return false;

    return true;
  });
  auto swiz_mult2 = UnitTest("swizzle assignment operator *= (2)", +[]() {
    ivec4 v = ivec4(16);

    v.xy *= ivec2(4, 2);
    v.yzw *= ivec3(2, 4, 8);
    v.xyzw *= ivec4(1, 2, 4, 4);

    if (v != ivec4(64, 128, 256, 512)) return false;

    return true;
  });
  auto swiz_mult3 = UnitTest("swizzle assignment operator *= (3)", +[]() {
    ivec4 v = ivec4(64, 128, 256, 512);

    v.w *= 2;
    v.zz *= 2;
    v.yyy *= 2;
    v.xxxx *= 2;

    if (v != 1024) return false;

    return true;
  });
  auto swiz_mult4 = UnitTest("swizzle assignment operator *= (4)", +[]() {
    ivec4 v = ivec4(2);

    v.x *= v.x;
    v.yx *= v.xy;
    v.zyx *= v.xyz;
    v.wzyx *= v.xyzw;

    if (v != ivec4(32, 1024, 1024, 32)) return false;

    return true;
  });

  auto swiz_div1 = UnitTest("swizzle assignment operator /= (1)", +[]() {
    ivec4 v = ivec4(16);

    v.x /= 2;
    v.xy /= 2;
    v.zyx /= 2;
    v.xwzy /= 2;

    if (v != ivec4(1, 2, 4, 8)) return false;

    return true;
  });
  auto swiz_div2 = UnitTest("swizzle assignment operator /= (2)", +[]() {
    ivec4 v = ivec4(64, 128, 256, 512);

    v.xy /= ivec2(4, 2);
    v.yzw /= ivec3(2, 4, 8);
    v.xyzw /= ivec4(1, 2, 4, 4);

    if (v != 16) return false;

    return true;
  });
  auto swiz_div3 = UnitTest("swizzle assignment operator /= (3)", +[]() {
    ivec4 v = ivec4(1024);

    v.w /= 2;
    v.zz /= 2;
    v.yyy /= 2;
    v.xxxx /= 2;

    if (v != ivec4(64, 128, 256, 512)) return false;

    return true;
  });
  auto swiz_div4 = UnitTest("swizzle assignment operator /= (4)", +[]() {
    ivec4 v = ivec4(1024);
    ivec4 u = ivec4(2, 4, 8, 16);

    v.xyzw /= u.wzyx;
    v.yzw /= u.zyx;
    v.zw /= u.yx;
    v.w /= u.x;

    if (v != ivec4(64, 16, 16, 64)) return false;

    return true;
  });

  auto swiz_asig1 = UnitTest("swizzle assignment operator = (1)", +[]() {
    ivec4 v = ivec4(16);

    v.x = 1;
    if (v != ivec4(1, 16, 16, 16)) return false;

    v.xy = 2;
    if (v != ivec4(2, 2, 16, 16)) return false;

    v.zyx = 3;
    if (v != ivec4(3, 3, 3, 16)) return false;

    v.xwzy = 4;
    if (v != 4) return false;

    return true;
  });
  auto swiz_asig2 = UnitTest("swizzle assignment operator = (2)", +[]() {
    ivec4 v = ivec4(0);

    v.xy = ivec2(1, 2);
    if (v != ivec4(1, 2, 0, 0)) return false;

    v.yzw = ivec3(1);
    if (v != 1) return false;

    v.xyzw = ivec4(1, 2, 3, 4);
    if (v != ivec4(1, 2, 3, 4)) return false;

    return true;
  });
  auto swiz_asig3 = UnitTest("swizzle assignment operator = (3)", +[]() {
    ivec4 v = ivec4(1024);

    v.w = 2;
    v.zz = 2;
    v.yyy = 2;
    v.xxxx = 2;

    if (v != 2) return false;

    return true;
  });
  auto swiz_asig4 = UnitTest("swizzle assignment operator = (4)", +[]() {
    ivec4 v = ivec4(1, 2, 3, 4);
    ivec4 u = ivec4(5, 6, 7, 8);

    v.x = u.x;
    if (v != ivec4(5, 2, 3, 4)) return false;

    v.xy = u.xy;
    if (v != ivec4(5, 6, 3, 4)) return false;

    v.xyz = u.xyz;
    if (v != ivec4(5, 6, 7, 4)) return false;

    v.xyzw = u.wzyx;
    if (v != ivec4(8, 7, 6, 5)) return false;

    return true;
  });
}
