#include "Container.h"
#include "Rectangle.h"

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

// добавить прямоугольник в хранилище
bool Container::insertRectangle(Rectangle* pRectangle)
{
  // начинаем проверять на пересечения
  for (auto iter : rectangles)
  {
    if (iter->intersection(*pRectangle))
    {
      return false;
    }
  }
  // если пересечений нет - добавляем прямоугольник в список
  rectangles.emplace_back(pRectangle);
  return true;
}
