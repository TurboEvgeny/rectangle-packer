#include <string>
#include <vector>
#include "MyVector.h"

enum RectangleCorners
{
 RECTANGLE_LEFT_DOWN = 0,
 RECTANGLE_LEFT_UP,
 RECTANGLE_RIGHT_UP,
 RECTANGLE_RIGHT_DOWN,
 RECTANGLE_CORNERS
};

// forward-declaration for Container class
// (используется для проверки пересечения)
class Container;

class Rectangle
{
 public:
  Rectangle(double w, double h);
  ~Rectangle() {}
  // установка координат
  void setCoordinates(double x0, double y0, double ang);
  // расчет площади
  double getArea();
  // расчет координат прямоугольника
  // расчет пересечения с другим прямоугольником
  bool intersection(const Rectangle& other);
  // расчет вхождения в контейнер
  bool packingCheck(const Container& container);
  // расчет возможности упаковки в контейнер размером (w, h)
  // возвращает возможность упаковки
  bool compatible(const Container& container);
  // строка с данными
  std::string getString();

 private:
  //! длина прямоугольника
  double width;
  //! высота прямоугольника
  double height;
  //! угол поворота, рад
  double angleRad;
  //! координаты точек
  MyVector coord[RECTANGLE_CORNERS];
};
