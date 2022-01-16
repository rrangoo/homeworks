#include "Container.h"

// Отчистка данных.
Container::~Container() {
    for (int i = 0; i < length; i++) {
        delete data[i];
    }
    delete data;
    length = 0;
}

// Ввод данных в поток.
void Container::in(std::ifstream &input) {
    int type;
    while (!input.eof()) {
        input >> type;
        switch (type) {
            case 0:
                data[length] = new Car();
                break;
            case 1:
                data[length] = new Bus();
                break;
            case 2:
                data[length] = new Truck();
                break;
        }
        data[length]->in(input);
        length++;
    }
}

// Ввод случайных данных в форматируемый поток.
void Container::inRnd(int size) {
    while (length < size) {
        int type = rand() % 3;

        switch (type) {
            case 0:
                data[length] = new Car();
                break;
            case 1:
                data[length] = new Bus();
                break;
            case 2:
                data[length] = new Truck();
                break;
        }

        data[length]->inRnd();

        if (data[length] != nullptr) {
            length++;
        }
    }
}

// Вывод данных.
void Container::out(std::ofstream &output) {
    output << "Container contains " << length << " elements.\n";
    for (int i = 0; i < length; i++) {
        output << i << ": ";
        data[i]->out(output);
    }
}

// Реализация сортировки.
// Меняем местами элементы.
template<typename T>
void swap(T &a, T &b) {
    T temp(std::move(a));
    a = std::move(b);
    b = std::move(temp);
}
// Определяем индексы.
void Container::Heapify(int x, int y) {
    int largest = y;
    int l = 2 * y + 1;
    int r = 2 * y + 2;

    if (l < x && data[l]->compareValue() > data[largest]->compareValue())largest = l;
    if (r < x && data[r]->compareValue() > data[largest]->compareValue())largest = r;

    if (largest != y) {
        swap(data[y], data[largest]);
        Heapify(x, largest);
    }
}
// Сортировка.
void Container::HeapSort() {
    int n = length;
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(data[0], data[i]);
        Heapify(i, 0);
    }
}
