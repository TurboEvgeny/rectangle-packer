#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle(double w, double h):
  width(w),
  height(h),
  angleRad(0.0)
{
  this->setCoordinates(0.0, 0.0, angleRad);
}

// установка координат
void Rectangle::setCoordinates(double x0, double y0, double ang)
{
  this->coord[RECTANGLE_LEFT_DOWN].first = x0;
  this->coord[RECTANGLE_LEFT_DOWN].second = y0;

  this->coord[RECTANGLE_LEFT_UP].first = x0 - this->height*sin(ang);
  this->coord[RECTANGLE_LEFT_UP].second = y0 + this->height*cos(ang);

  this->coord[RECTANGLE_RIGHT_UP].first =
    x0 + this->width * cos(ang) - this->height*sin(ang);
  this->coord[RECTANGLE_LEFT_UP].second =
    y0 + this->width * sin(ang) + this->height*cos(ang);

  this->coord[RECTANGLE_RIGHT_DOWN].first =
    x0 + this->width * cos(ang);
  this->coord[RECTANGLE_RIGHT_DOWN].second =
    y0 + this->width * sin(ang);
}

double Rectangle::getArea()
{
  return this->width * this->height;
}

// расчет пересечения с другим прямоугольником
bool Rectangle::intersection(const Rectangle& other)
{
  // критерий пересечения -
  // проецируем все точки прямоугольников на линию,
  // параллельную его всем его сторонам
  // если обнаружили отсуствие пересечения хоть на одной проекции,
  // значит пересечения нет
  other.width;
  return false;
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
