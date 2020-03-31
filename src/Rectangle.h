#include <string>
#include <vector>

enum RectangleCorners
{
 RECTANGLE_LEFT_DOWN = 0,
 RECTANGLE_LEFT_UP,
 RECTANGLE_RIGHT_UP,
 RECTANGLE_RIGHT_DOWN,
 RECTANGLE_CORNERS
};
  
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
  
  //! расчет возможности упаковки в контейнер размером (w, h)
  //! возвращает возможность упаковки
  // @arg w - длина контейнера
  // @arg h - высота контейнера
  // @arg alphaMin - указатель на значения минимального угла поворота
  // @arg alphaMax - указатель на значение максимального угла поворота 
  // (углы поворота рассчитываются от 0 до 90 градусов)
  //bool packingPossible(double w, double h, double* alphaMin, double* alphaMax);
  // строка с данными
  std::string getString();
 private:
  //! длина прямоугольника
  double width;
  //! высота прямоугольника
  double height;
  //! координаты точек
  std::pair<double, double> coord[RECTANGLE_CORNERS];
  //! угол поворота, рад
  double angleRad;
};
