#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include <algorithm>
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
       this->containerW = w;
       this->containerH = h;
       containers.emplace_back(std::make_unique<Container>(w, h));
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
  bool insertItemToContainer(Container* pContainer, Rectangle* pRectangle)
  {
    // если доступной площади нет - сразу выходим
    if (!pRectangle->insertAreaAvailable(*pContainer))
    {
      return false;
    }
    // в ином случае итеративно пытаемся вставить элемент
    // задаем шаг сдвига
    const double dStep = 0.1;
    // начальные точки
    double xInit = 0.0;
    double yInit = 0.0;
    double angleInit = 0.0;
    for (double coordX=xInit ; coordX < pContainer->getWidth() ; coordX+=dStep)
    {
      for (double coordY=yInit; coordY < pContainer->getHeight(); coordY+=dStep)
      {
        pRectangle->setCoordinates(coordX, coordY, angleInit);
        bool result = pContainer->insertRectangle(pRectangle);
        if (result)
        {
          return true;
        }
      }
    }
    // не удалось - выдаем соответсвующий результат 
    return false;
  }
  void packContainers()
  {
    // первым дело сортируем прямоугольники по площади
    // так как начинать вставку лучше с самых крупных
    std::sort(rectangles.begin(), rectangles.end(),
      [](const auto& lhs, const auto& rhs)
      {
         return lhs->getArea() > rhs->getArea();
      });
    // начинаем перебирать прямоугольники
    for (auto& pRectangle : rectangles)
    {
      bool insertion = false;
      auto containersIter = containers.begin();
      while (!insertion && (containersIter != containers.end()))
      {
        Container* pContainer = containersIter->get();
        // если элемент не влезет в контейнер - просто пропускаем его
     // (вдруг контейнеры будут разной формы)
        if (!pRectangle->compatible(*pContainer))
        {
       break;
        }
        else
        {       
          insertion =
         insertItemToContainer(pContainer, pRectangle.get());
       ++containersIter;
        }
      }
      // если не смогли вставить в существующие контейнеры -
      // создаем новый и вставляем в него
      if (!insertion)
      {
        containers.emplace_back(
        std::make_unique<Container>(containerW, containerH));
        bool insertOk = false;
        Container* pNewContainer = containers.back().get();
        // проверяем на совместимость с дефолтным новым контейнером
        if (pRectangle->compatible(*pNewContainer))
        {
           insertOk = insertItemToContainer(pNewContainer, pRectangle.get());
        }
        // не подошел - удаляем контейнер
        if (!insertOk)
        {
          containers.pop_back();
        }
      }
    }
  }
  void print()
  {
    std::cout << containers.size() << ",";
    std::cout << containerW << "," << containerH << std::endl;
    int id = 0;
    for (auto & item : containers)
    {
        item->print(id);
        id++;
    }
  }
private:
  // объявляем контейнер
  std::vector<std::unique_ptr <Container>> containers;
  // хранилище данных о прямоугольниках
  std::vector <std::unique_ptr <Rectangle>> rectangles;
  // размеры контейнера
  double containerW;
  double containerH;
};
int main()
{
  WorkData data;
  data.readInput();
  data.packContainers();
  data.print();
  int a = 4;
  std::cin >> a;
  return 0;
}
