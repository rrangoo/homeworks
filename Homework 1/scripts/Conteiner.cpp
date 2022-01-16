#include "Conteiner.h"

// Отчистка данных.
void clear(Container &container) {
    for (int i = 0; i < container.length; i++) {
        delete container.data[i];
    }
    container.length = 0;
}

// Ввод данных в поток.
void in(Container &container, std::ifstream &input) {
    while (!input.eof()) {
        if ((container.data[container.length] = in(input)) != nullptr) {
            container.length++;
        }
    }
}

// Ввод случайных данных в форматируемый поток.
void inRnd(Container &container, int size) {
    while (container.length < size) {
        container.data[container.length] = inRnd();
        if (container.data[container.length] != nullptr) {
            container.length++;
        }
    }
}

// Вывод данных.
void out(Container &container, std::ofstream &output) {
    output << "Container contains " << container.length << " elements.\n";
    for (int i = 0; i < container.length; i++) {
        output << i << ": ";
        out(*(container.data[i]), output);
    }
}

// Меняем местами элементы.
void swap(Vehicle *a, Vehicle *b) {
    Vehicle vehicle = *a;
    *a = *b;
    *b = vehicle;
}

// Реализация сортировки.
void heapify(Container &container, int n, int i)
{
    // Initialize largest as root.
    int largest = i;
    // Left.
    int l = 2 * i + 1;
    // Right.
    int r = 2 * i + 2;

    // If left child is larger than root.
    if (l < n && compareValue(*container.data[l]) > compareValue(*container.data[largest])) {
        largest = l;
    }

    // If right child is larger than largest so far.
    if (r < n && compareValue(*container.data[r]) > compareValue(*container.data[largest])) {
        largest = r;
    }


    // If largest is not root.
    if (largest != i) {
        swap(container.data[i], container.data[largest]);

        // Recursively heapify the affected sub-tree.
        heapify(container, n, largest);
    }
}

// Упорядочить элементы контейнера по убыванию используя сортировку с помощью «дерева» (Heap Sort).
void heapSort(Container &container, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(container, n, i);

    // One by one extract an element from heap.
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end.
        swap(container.data[0], container.data[i]);
        // Call max heapify on the reduced heap.
        heapify(container, i, 0);
    }
}
