#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "point.hpp"

TEST_CASE("point-arithmetic") 
{
  Point p1;
  REQUIRE(p1.getX() == 0);
  REQUIRE(p1.getY() == 0);
  REQUIRE(p1 == Point(0, 0));
  REQUIRE(p1 != Point(1, 0));
  REQUIRE(p1 != Point(1, 1));

  Point p2(1, 1);
  p1 += p2;
  REQUIRE(p1 != Point(0, 0));
  REQUIRE(p1 == Point(1, 1));

  REQUIRE(-p1 == p2 - Point(2, 2));
  p1 *= 4;
  REQUIRE(p1 == Point(4, 4));
  REQUIRE(p1 - p2 == Point(3, 3));

  p2 /= 0.5;
  REQUIRE(p2 == Point(2, 2));
  Point p3(p1 / 4);
  REQUIRE(p3 - Point(1, 1) == Point());

  p3 += Point(0, 10);
  REQUIRE(p3 == Point(1, 11));
}
