#include <string>
#include <vector>
#include <unordered_set>
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
  double getArea() const;
  // расчет координат прямоугольника
  // расчет пересечения с другим прямоугольником
  bool intersection(const Rectangle& other) const;
  // расчет вхождения в контейнер
  bool packingCheck_axesX(const Container& container) const;
  bool packingCheck_axesY(const Container& container) const;
  // расчет возможности упаковки в контейнер размером (w, h)
  // возвращает теоретическую возможность упаковки
  bool compatible(const Container& container) const;
  // расчет возможности контейнера принять прямоугольник исходя из площади
  bool insertAreaAvailable(const Container& container) const;
  // строка с данными
  void print() const;
  // добавить координаты вершин в unordered_set
  void addCorners(
      std::unordered_set<double>& xSet,
      std::unordered_set<double>& ySet);
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
