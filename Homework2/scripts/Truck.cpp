#include "Truck.h"

// Ввод параметров машины.
void Truck::in(std::ifstream &input) {
    input >> gaz >> waste >> carry;
}

// Случайное заполнение параметров.
void Truck::inRnd() {
    gaz = rand() % 100 + 1;
    waste = (rand() % 100) * 0.01 + rand() % 99 + 1;
    carry = rand() % 300 + 1;
}

// Вывод параметров в форматируемый поток.
void Truck::out(std::ofstream &output) {
    output << "Truck: "
           << "gaz: " << gaz
           << " waste: " << waste
           << " speed: " << carry
           << " distance " << compareValue() << "\n";
}