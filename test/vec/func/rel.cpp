#include <unittest.hpp>
#include <mmm.hpp>

namespace {
  using namespace mmm;

  auto s_lt = UnitTest("scalar relational function lessThan", +[]() {
    if (lessThan(4, 4)) return false;
    if (lessThan(8.f, 5)) return false;
    if (!lessThan(1.l, 9.0)) return false;

    return true;
  });
  auto v_lt = UnitTest("vector relational function lessThan", +[]() {
    ivec3 v = ivec3(1, 2, 3);
    ivec3 u = ivec3(0, 2, 4);

    bvec3 b = lessThan(v, 2);
    bvec3 c = lessThan(2.f, v);

    bvec3 d = lessThan(v, u);
    bvec3 e = lessThan(v.zyx, u);

    if (!b.x or b.y or b.z) return false;
    if (c.x or c.y or !c.z) return false;

    if (d.x or d.y or !d.z) return false;
    if (e.x or e.y or !e.z) return false;

    return true;
  });

  auto s_le = UnitTest("scalar relational function lessThanEqual", +[]() {
    if (!lessThanEqual(4, 4)) return false;
    if (lessThanEqual(8.f, 5)) return false;
    if (!lessThanEqual(1.l, 9.0)) return false;

    return true;
  });
  auto v_le = UnitTest("vector relational function lessThanEqual", +[]() {
    ivec3 v = ivec3(1, 2, 3);
    ivec3 u = ivec3(0, 2, 4);

    bvec3 b = lessThanEqual(v, 2);
    bvec3 c = lessThanEqual(2.f, v);

    bvec3 d = lessThanEqual(v, u);
    bvec3 e = lessThanEqual(v.zyx, u);

    if (!b.x or !b.y or b.z) return false;
    if (c.x or !c.y or !c.z) return false;

    if (d.x or !d.y or !d.z) return false;
    if (e.x or !e.y or !e.z) return false;

    return true;
  });

  auto s_gt = UnitTest("scalar relational function greaterThan", +[]() {
    if (greaterThan(4, 4)) return false;
    if (!greaterThan(8.f, 5)) return false;
    if (greaterThan(1.l, 9.0)) return false;

    return true;
  });
  auto v_gt = UnitTest("vector relational function greaterThan", +[]() {
    ivec3 v = ivec3(1, 2, 3);
    ivec3 u = ivec3(0, 2, 4);

    bvec3 b = greaterThan(v, 2);
    bvec3 c = greaterThan(2.f, v);

    bvec3 d = greaterThan(v, u);
    bvec3 e = greaterThan(v.zyx, u);

    if (b.x or b.y or !b.z) return false;
    if (!c.x or c.y or c.z) return false;

    if (!d.x or d.y or d.z) return false;
    if (!e.x or e.y or e.z) return false;

    return true;
  });

  auto s_ge = UnitTest("scalar relational function greaterThanEqual", +[]() {
    if (!greaterThanEqual(4, 4)) return false;
    if (!greaterThanEqual(8.f, 5)) return false;
    if (greaterThanEqual(1.l, 9.0)) return false;

    return true;
  });
  auto v_ge = UnitTest("vector relational function greaterThanEqual", +[]() {
    ivec3 v = ivec3(1, 2, 3);
    ivec3 u = ivec3(0, 2, 4);

    bvec3 b = greaterThanEqual(v, 2);
    bvec3 c = greaterThanEqual(2.f, v);

    bvec3 d = greaterThanEqual(v, u);
    bvec3 e = greaterThanEqual(v.zyx, u);

    if (b.x or !b.y or !b.z) return false;
    if (!c.x or !c.y or c.z) return false;

    if (!d.x or !d.y or d.z) return false;
    if (!e.x or !e.y or e.z) return false;

    return true;
  });

  auto s_e = UnitTest("scalar relational function equal", +[]() {
    if (!equal(4, 4)) return false;
    if (equal(8.f, 5)) return false;
    if (equal(1.l, 9.0)) return false;

    return true;
  });
  auto v_e = UnitTest("vector relational function equal", +[]() {
    ivec3 v = ivec3(1, 2, 3);
    ivec3 u = ivec3(0, 2, 4);

    bvec3 b = equal(v, 2);
    bvec3 c = equal(2.f, v);

    bvec3 d = equal(v, u);
    bvec3 e = equal(v.zyx, u);

    if (b.x or !b.y or b.z) return false;
    if (c.x or !c.y or c.z) return false;

    if (d.x or !d.y or d.z) return false;
    if (e.x or !e.y or e.z) return false;

    return true;
  });

  auto s_ne = UnitTest("scalar relational function notEqual", +[]() {
    if (notEqual(4, 4)) return false;
    if (!notEqual(8.f, 5)) return false;
    if (!notEqual(1.l, 9.0)) return false;

    return true;
  });
  auto v_ne = UnitTest("vector relational function notEqual", +[]() {
    ivec3 v = ivec3(1, 2, 3);
    ivec3 u = ivec3(0, 2, 4);

    bvec3 b = notEqual(v, 2);
    bvec3 c = notEqual(2.f, v);

    bvec3 d = notEqual(v, u);
    bvec3 e = notEqual(v.zyx, u);

    if (!b.x or b.y or !b.z) return false;
    if (!c.x or c.y or !c.z) return false;

    if (!d.x or d.y or !d.z) return false;
    if (!e.x or e.y or !e.z) return false;

    return true;
  });

  auto s_all = UnitTest("scalar relational function all", +[]() {
    if (!all(true)) return false;
    if (all(false)) return false;

    return true;
  });
  auto v_all = UnitTest("vector relational function all", +[]() {
    bvec3 v = bvec3(true, true, true);
    bvec3 u = bvec3(true, true, false);
    bvec3 t = bvec3(false, false, false);

    if (!all(v)) return false;
    if (all(u)) return false;
    if (all(t)) return false;

    return true;
  });

  auto s_any = UnitTest("scalar relational function any", +[]() {
    if (!any(true)) return false;
    if (any(false)) return false;

    return true;
  });
  auto v_any = UnitTest("vector relational function any", +[]() {
    bvec3 v = bvec3(true, true, true);
    bvec3 u = bvec3(true, true, false);
    bvec3 t = bvec3(false, false, false);

    if (!any(v)) return false;
    if (!any(u)) return false;
    if (any(t)) return false;

    return true;
  });

  auto v_not = UnitTest("vector relational function not", +[]() {
    bvec3 v = not bvec3(true, true, true);
    bvec3 u = not bvec3(true, true, false);
    bvec3 t = not bvec3(false, false, false);

    if (any(v)) return false;
    if (all(u)) return false;
    if (!all(t)) return false;

    return true;
  });
}
