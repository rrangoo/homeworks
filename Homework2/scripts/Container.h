
#ifndef HOMEWORK_1_CONTEINER_H
#define HOMEWORK_1_CONTEINER_H
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Truck.h"

class Container {
    int length;
    Vehicle **data;

public:

	Container(){
		data = new Vehicle *[10000];
	}
    // Очистка контейнера от элементов (освобождение памяти).
    ~Container();

// Ввод содержимого контейнера из указанного потока.
    void in(std::ifstream &input);

// Случайный ввод содержимого контейнера.
    void inRnd(int size);

// Вывод содержимого контейнера в указанный поток.
    void out(std::ofstream &output);

    void Heapify(int n, int i);

// Сортировка.
    void HeapSort();

};
#endif //HOMEWORK_1_CONTEINER_H
