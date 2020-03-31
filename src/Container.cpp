#include "Container.h"

Container::Container(double w, double h):
  width(w),
  height(h)
{
}

double Container::getArea()
{
  return this->width * this->height;
}

double Container::getWidth()
{
  return this->width;
}

double Container::getHeight()
{
  return this->height;
}
