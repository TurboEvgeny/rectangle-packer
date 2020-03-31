// класс данных о контейнере
// (чтобы не завязываться на специфичном классе Rectangle)
class Container
{
 public:
  Container() {}
  Container(int w, int h);
  // площадь контейнера
  int getArea();
  // высота контейнера
  int getHeight();
  // длина контейнера
  int getWidth();
 private:
  // параметры контейнера
  int width;
  int height;
};
