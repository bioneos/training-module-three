#include "point.hpp"

Point::Point():
x{0}, y{0} {}

Point::Point(double x, double y):
x{x}, y{y} {}

Point operator-(const Point& point)
{
  return Point(-point.x, -point.y);
}

Point operator+(const Point& a, const Point& b)
{
  return Point(a.x + a.y, b.x + b.y);
}

Point operator-(const Point& a, const Point& b)
{
  return Point(a.x - a.y, b.x - b.y);
}

Point operator*(const Point& point, double scalar)
{
  return Point(point.x * scalar, point.y * scalar);
}

Point operator/(const Point& point, double divisor)
{
  return Point(point.x / divisor, point.y / divisor);
}

bool operator==(const Point& a, const Point& b)
{
  return a.x == b.x && a.y == b.y;
}

bool operator!=(const Point& a, const Point& b)
{
  return !(a == b);
}

Point& Point::operator+=(const Point& other)
{
  *this = *this + other;
  return *this;
}

Point& Point::operator-=(const Point& other)
{
  *this = *this - other;
  return *this;
}

Point& Point::operator*=(double scalar)
{
  *this = *this * scalar;
  return *this;
}

Point& Point::operator/=(double divisor)
{
  *this = *this / divisor;
  return *this;
}

double Point::getX() const
{
  return x;
}

double Point::getY() const
{
  return y;
}

Point& Point::setX(double x)
{
  this->x = x;
  return *this;
}

Point& Point::setY(double y)
{
  this->y = y;
  return *this;
}

std::ostream& operator<<(std::ostream& ostream, const Point& point)
{
  ostream << "(" << point.x << ", " << point.y << ")";
  return ostream;
}
