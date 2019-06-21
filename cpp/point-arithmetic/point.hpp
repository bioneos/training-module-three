#ifndef POINT_H
#define POINT_H

#include <ostream>

class Point
{
private:
  double x;
  double y;
public:
  Point();
  Point(double x, double y);

  friend Point operator-(const Point& point);
  friend Point operator+(const Point& a, const Point& b);
  friend Point operator-(const Point& a, const Point& b);
  friend Point operator*(const Point& point, double scalar);
  friend Point operator/(const Point& point, double divisor);

  friend bool operator==(const Point& a, const Point& b);
  friend bool operator!=(const Point& a, const Point& b);

  Point& operator+=(const Point& other);
  Point& operator-=(const Point& other);
  Point& operator*=(double scalar);
  Point& operator/=(double divisor);

  double getX() const;
  double getY() const;
  Point& setX(double x);
  Point& setY(double y);

  friend std::ostream& operator<<(std::ostream& ostream, const Point& point);
};

#endif
