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
  this->coord[RECTANGLE_LEFT_DOWN] = MyVector(x0, y0);

  this->coord[RECTANGLE_LEFT_UP] = MyVector(
    x0 - this->height*sin(ang),
    y0 + this->height*cos(ang));

  this->coord[RECTANGLE_RIGHT_UP]= MyVector(
    x0 + this->width * cos(ang) - this->height*sin(ang),
    y0 + this->width * sin(ang) + this->height*cos(ang));

  this->coord[RECTANGLE_RIGHT_DOWN] = MyVector(
    x0 + this->width * cos(ang),
    y0 + this->width * sin(ang));
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

  // проекция рассчитывается с помощью скалярного произведения
  // у прямоугольника стороны параллельны поэтому на достаточно 2 проекции
  // для каждой фигуры
  std::pair<double, double> vect[4];
  //vect[0].first = 
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
