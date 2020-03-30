class Rectangle
{
 public:
  Rectangle();
  Rectangle(double w, double h);
  ~Rectangle() {}
  //! расчет возможности упаковки в контейнер размером (w, h)
  //! возвращает возможность упаковки
  // @arg w - длина контейнера
  // @arg h - высота контейнера
  // @arg alphaMin - указатель на значения минимального угла поворота
  // @arg alphaMax - указатель на значение максимального угла поворота 
  // (углы поворота рассчитываются от 0 до 90 градусов)
  //bool packingPossible(double w, double h, double* alphaMin, double* alphaMax);
 private:
  //! длина прямоугольника
  double width;
  //! высота прямоугольника
  double height;
};
