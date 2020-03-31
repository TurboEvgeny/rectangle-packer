#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include "Rectangle.h"
#include "Container.h"
#define MAX_RECTANGLES_NUMBER 100

class WorkData
{
public:
  WorkData()
  {
    // нам известно максимально допустимое количество элементов
    // поэтому смело резервируем
    rectangles.reserve(MAX_RECTANGLES_NUMBER);
  }

  ~WorkData()
  {
  }

  void readInput()
  {
    int iteration = 0;
    bool dataExists = true;
    const double eps = 1e-10;
    while (dataExists)
    {
      double w = 0.0;
      double h = 0.0;
      scanf("%lf,%lf", &w, &h);
      // проверяем - корректны ли данные
      // (если некорректные - завершаем цикл)
      dataExists = (fabs(w) >=  eps) && (fabs(h) >= eps);
      if (dataExists)
      {
	// первая строчка - размер контейнера
	if (iteration == 0)
	{
	  pContainer = std::make_unique<Container>(w, h);
	}
	// остальные - размеры прямоугольников
	else
	{
	  rectangles.emplace_back(std::make_unique<Rectangle>(w, h));
	}
	iteration++;
      }
    }      
  }
  void print()
  {
    if (pContainer != nullptr)
    {
      std::cout << "container param" << std::endl;
      std::cout << "w=" << pContainer->getWidth();
      std::cout << "h=" << pContainer->getHeight() << std::endl;
    }
    for (auto const& item : rectangles)
    {
      std::cout << "rectangle param" << std::endl;
      std::cout << item->getString() << std::endl;
    }
  }
private:
  // объявляем контейнер
  std::unique_ptr <Container> pContainer;
  // хранилище данных о прямоугольниках
  std::vector <std::unique_ptr <Rectangle>> rectangles;
};
int main()
{
  WorkData data;
  data.readInput();
  data.print();
  return 0;
}
