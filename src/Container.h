// класс данных о контейнере
// (чтобы не завязываться на специфичном классе Rectangle)
class Container
{
 public:
  Container() {}
  Container(double w, double h);
  // площадь контейнера
  double getArea();
  // высота контейнера
  double getHeight();
  // длина контейнера
  double getWidth();
 private:
  // параметры контейнера
  double width;
  double height;
};
