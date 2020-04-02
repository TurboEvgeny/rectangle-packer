#include "Container.h"
#include "Rectangle.h"

Container::Container(double w, double h):
  width(w),
  height(h),
  availableArea(this->getArea())
{
    // доступные для размещения углы
    corners_x.insert(0.0);
    corners_y.insert(0.0);
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

// выдача координат вершин 
const std::unordered_set<double>& Container::getCorners_x() const
{
    return this->corners_x;
}
const std::unordered_set<double>& Container::getCorners_y() const
{
    return this->corners_y;
}

// добавить прямоугольник в хранилище
bool Container::insertRectangle(Rectangle* pRectangle)
{
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
    // сохраняем координаты вершин
    pRectangle->addCorners(this->corners_x, this->corners_y);
    // уменьшаем доступную площадь
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
