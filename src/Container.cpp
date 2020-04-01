#include "Container.h"
#include "Rectangle.h"

Container::Container(double w, double h):
  width(w),
  height(h),
  availableArea(this->getArea())
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

double Container::getAvailableArea() const
{
  return this->availableArea;
}

// добавить прямоугольник в хранилище
bool Container::insertRectangle(Rectangle* pRectangle)
{
  // сначала проверяем на вхождение в контейнер
  if (!pRectangle->packingCheck(*this))
  {
    return false;
  }
  // потом начинаем проверять на пересечения 
  for (auto iter : rectangles)
  {
    if (iter->intersection(*pRectangle))
    {
      return false;
    }
  }
  // если пересечений нет - добавляем прямоугольник в список
  rectangles.emplace_back(pRectangle);
  this->availableArea -= pRectangle->getArea();
  return true;
}

void Container::print(int id) const
{
    for (auto iter : rectangles)
    {
        std::cout << id << ",";
        iter->print();
        std::cout << std::endl;
    }
}
