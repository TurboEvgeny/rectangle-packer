#include "Container.h"

Container::Container(int w, int h):
  width(w),
  height(h)
{
}

int Container::getArea()
{
  return this->width * this->height;
}

int Container::getWidth()
{
  return this->width;
}

int Container::getHeight()
{
  return this->height;
}
