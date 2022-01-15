
#ifndef HOMEWORK_1_CONTEINER_H
#define HOMEWORK_1_CONTEINER_H
#include <fstream>
#include "Vehicle.h"

struct Container {
    int length;
    Vehicle *data[10000];
};

// Очистка контейнера от элементов (освобождение памяти).
void clear(Container &container);

// Ввод содержимого контейнера из указанного потока.
void in(Container &container, std::ifstream &input);

// Случайный ввод содержимого контейнера.
void inRnd(Container &container, int size);

// Вывод содержимого контейнера в указанный поток.
void out(Container &container, std::ofstream &output);


// Метод для перемещения ссылок.
void swap(Vehicle *a, Vehicle *b);

// Сортировка.
void heapSort(Container &container, int n);

#endif //HOMEWORK_1_CONTEINER_H
