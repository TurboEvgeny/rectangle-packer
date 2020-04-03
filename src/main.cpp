#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include <algorithm>
#include <cmath>
#include "Rectangle.h"
#include "Container.h"
#define MAX_RECTANGLES_NUMBER 100

class WorkData
{
public:
    WorkData():
        containerH(0.0),
        containerW(0.0)
    {
      // нам известно максимально допустимое количество элементов
      // поэтому смело резервируем
      rectangles.reserve(MAX_RECTANGLES_NUMBER);
    }

    ~WorkData()
    {
    }

    std::vector<double> getTurningAngles()
    {
        const double pi = 3.141592653589793238462643383279;
        return { 0.0, pi / 2.0, pi / 4.0 , 3.0 * pi / 4.0 };
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
            // прописываем ограничение на максимальное количество прямоугольников
            if (dataExists && (iteration <= MAX_RECTANGLES_NUMBER))
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
    // функция размеещения объекта в контейнере
    bool insertItemToContainer(Container* pContainer, Rectangle* pRectangle)
    {
        // если доступной площади нет - сразу выходим
        if (!pRectangle->insertAreaAvailable(*pContainer))
        {
          return false;
        }
        // узнаем доступные начальные координаты для размещения объекта
        // (это вершины объектов, которые находятся внутри контейнера + 
        // нулевая координата контейнера)
        for (auto x_coord : pContainer->getCorners_x())
        {
            for (auto y_coord : pContainer->getCorners_y())
            {
                // пробуем все углы из списка
                for (auto angle : this->getTurningAngles())
                {
                    pRectangle->setCoordinates(x_coord, y_coord, angle);
                    // если не проходим по размеру - переходим к следующему варианту
                    if (!pRectangle->packingCheck_axesX(*pContainer) ||
                        !pRectangle->packingCheck_axesY(*pContainer))
                    {
                        continue;
                    }
                    // пробуем добавить в контейнер - если все хрошо, 
                    // то выходим из функции
                    if (pContainer->insertRectangle(pRectangle))
                    {
                        return true;
                    }
                }
            }
        }
        // не удалось - выдаем соответсвующий результат 
        return false;
    }
    void packContainers()
    {
        // первым дело сортируем прямоугольники по площади
        // так как начинать вставку лучше с самых мелких
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
            // вставляем лишь в последний контейнер
            // так как фигуры мы вставлем по возрастанию площади
            // если фигура с меньше площадью не вставилась, 
            // то значит и у нас вероятно не получится
            if (!insertion && (containers.size() > 0))
            {
                auto containerIter = containers.begin();
                while (!insertion && (containerIter != containers.end()))
                {
                    Container* pContainer = containerIter->get();
                    // если элемент не влезет в контейнер - просто пропускаем его
                    // (вдруг контейнеры будут разной формы)
                    if (pRectangle->compatible(*pContainer))
                    {
                        insertion =
                            insertItemToContainer(pContainer, pRectangle.get());
                    }
                    ++containerIter;
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
    return 0;
}
