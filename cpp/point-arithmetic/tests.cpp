#include "point.hpp"

#include <iostream>

using namespace std;

struct Tests
{
  unsigned int passed = 0;
  unsigned int total = 0;

  void require(bool assertion)
  {
    ++total;
    if (assertion)
    {
      ++passed;
    }
  }

  bool wereSuccessful()
  {
    return passed == total;
  }
};

int main()
{
  Tests tests;

  Point p1;
  tests.require(p1.getX() == 0);
  tests.require(p1.getY() == 0);
  tests.require(p1 == Point(0, 0));
  tests.require(p1 != Point(1, 0));
  tests.require(p1 != Point(1, 1));

  Point p2(1, 1);
  p1 += p2;
  tests.require(p1 != Point(0, 0));
  tests.require(p1 == Point(1, 1));

  tests.require(-p1 == p2 - Point(2, 2));
  p1 *= 4;
  tests.require(p1 == Point(4, 4));
  tests.require(p1 - p2 == Point(3, 3));

  p2 /= 0.5;
  tests.require(p2 == Point(2, 2));
  Point p3(p1 / 4);
  tests.require(p3 - Point(1, 1) == Point());

  p3 += Point(0, 10);
  tests.require(p3 == Point(1, 11));
  
  if (tests.wereSuccessful())
  {
    cout << tests.passed << " out of " << tests.total << " tests passed. Success!" << endl;
    return 0;
  }
  else
  {
    cerr << tests.passed << " out of " << tests.total << " tests passed. Try again." << endl;
    return -1;
  }
}
