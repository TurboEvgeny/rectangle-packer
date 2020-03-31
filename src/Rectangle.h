#include <string>
class Rectangle
{
 public:
  Rectangle(double w, double h);
  ~Rectangle() {}
  double getArea();
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
  //! координаты базовой точки (левый нижний угол)
  double x0;
  double y0;
  //! угол поворота, рад
  double angleRad;
  
};
