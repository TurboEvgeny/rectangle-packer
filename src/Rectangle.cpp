#include "Rectangle.h"

Rectangle::Rectangle(double w, double h):
  width(w),
  height(h),
  x0(0.0),
  y0(0.0),
  angleRad(0.0)
{
}

double Rectangle::getArea()
{
  return this->width * this->height;
}

std::string Rectangle::getString()
{
  return std::string(
   "w=" +
   std::to_string(this->width) +
   " h=" +
   std::to_string(this->height)
   );
}
