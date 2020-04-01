#include "Container.h"

Container::Container(double w, double h):
  width(w),
  height(h)
{
}

double Container::getArea() const
{
  return this->width * this->height;
}

double Container::getWidth() const
{
  return this->width;
}

double Container::getHeight() const
{
  return this->height;
}
