#include <list>
// класс данных о контейнере
// (чтобы не завязываться на специфичном классе Rectangle)
class Rectangle; 
class Container
{
 public:
  Container(double w, double h);
  // площадь контейнера
  double getArea() const;
  // доступная площадь
  double getAvailableArea() const;
  // высота контейнера
  double getHeight() const;
  // длина контейнера
  double getWidth() const;
  // добавить прямоугольник в хранилище
  bool insertRectangle(Rectangle* pRectangle);
  // распечатать содержимое
  void print(int id) const;
 private:
  // хранилище прямугольников
  std::list <Rectangle*> rectangles;
  // параметры контейнера
  double width;
  double height;
  // доступная площадь
  double availableArea;
};
