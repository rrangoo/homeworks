#include "Vehicle.h"

// Простейший контейнер.
class Container {
private:
    // Длинна контейнера.
    int len;

    // Массив транспортных средств.
    Vehicle **vehicles;
public:
    // Инициализация контейнера.
    void Init(int *size);

    // Удаление контейнера.
    void Clear();

    // Ввод содержимого.
    void In(FILE *file, int size);

    // Случайный ввод.
    void InRnd(int size);

    // Вывод содержимого.
    void Out(FILE *file);


    void siftDown(Vehicle **arr, int root, int bottom);

    // Сортировка.
    void HeapSort();
};
