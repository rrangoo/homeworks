#include "Container.h"
#include "Car.h"
#include "Bus.h"
#include "Truck.h"

// Инициализация.
void Container::Init(int *size) {
    vehicles = new Vehicle *[*size];
    len = 0;
}

// Очистка контейнера.
void Container::Clear() {
    for (int i = 0; i < len; ++i) {
        delete vehicles[i];
    }
    delete vehicles;
    len = 0;
}

// Ввод содержимого контейнера из файла.
void Container::In(FILE *file, int size) {
    int result, number_type;
    while (len < size) {
        result = 1;
        if (fscanf(file, "%d", &number_type) == EOF) {
            return;
        }
        switch (number_type) {
            case 1:
                vehicles[len] = new Car();
                break;
            case 2:
                vehicles[len] = new Bus();
                break;
            case 3:
                vehicles[len] = new Truck();
                break;
            default:
                result = 0;
        }

        result = (result) ? vehicles[len]->In(file) : 0;

        if (result == 1) {
            len++;
        } else if (result == 2) {
            return;
        } else {
            delete vehicles[len];
        }
    }
}

// Случайный ввод.
void Container::InRnd(int size) {
    while(len < size) {
        switch (rand() % 3) {
            case 0: vehicles[len] = new Car(); break;
            case 1: vehicles[len] = new Bus(); break;
            case 2: vehicles[len] = new Truck(); break;
        }
        vehicles[len++]->InRnd();
    }
}

// Вывод содержимого.
void Container::Out(FILE *file) {
    fprintf(file, "Size = %d.\n", len);
    for(int i = 0; i < len; i++) {
        fprintf(file, "%d: ", i);
        vehicles[i]->Out(file);
    }
}

void Container::siftDown(Vehicle **arr, int root, int bottom) {
    int maxChild; // индекс максимального потомка
    int done = 0; // флаг того, что куча сформирована
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)    // если мы в последнем ряду,
            maxChild = root * 2;    // запоминаем левый потомок
            // иначе запоминаем больший потомок из двух
        else if (vehicles[root * 2]->max_distance() > vehicles[root * 2 + 1]->max_distance())
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // если элемент вершины меньше максимального потомка
        if (vehicles[root]->max_distance() < vehicles[maxChild]->max_distance())
        {
            Vehicle *temp = vehicles[root]; // меняем их местами
            vehicles[root] = vehicles[maxChild];
            vehicles[maxChild] = temp;
            root = maxChild;
        }
        else // иначе
            done = 1; // пирамида сформирована
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void Container::HeapSort()
{
    // Формируем нижний ряд пирамиды
    for (int i = (len / 2); i >= 0; i--)
        siftDown(vehicles, i, len - 1);
    // Просеиваем через пирамиду остальные элементы
    for (int i = len - 1; i >= 1; i--)
    {
        Vehicle *temp = vehicles[0];
        vehicles[0] = vehicles[i];
        vehicles[i] = temp;
        siftDown(vehicles, 0, i - 1);
    }
}


