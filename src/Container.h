#include <list>
#include <unordered_set>
// класс данных о контейнере
// (чтобы не завязываться на специфичном классе Rectangle)
class Rectangle; 
class Container
{
 public:
  Container(double w, double h);
  // удаляем конструктор копирования
  //(ибо каждый контейнер уникальный - нет смысла копировать
  Container(const Container& c) = delete;
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
  // хранилиoе координат вершин
  std::unordered_set<double> corners_x;
  std::unordered_set<double> corners_y;
  // параметры контейнера
  double width;
  double height;
  // доступная площадь
  double availableArea;
};
