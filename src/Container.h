// класс данных о контейнере
// (чтобы не завязываться на специфичном классе Rectangle)
class Container
{
 public:
  Container(double w, double h);
  // площадь контейнера
  double getArea() const;
  // высота контейнера
  double getHeight() const;
  // длина контейнера
  double getWidth() const;
 private:
  // параметры контейнера
  double width;
  double height;
};
