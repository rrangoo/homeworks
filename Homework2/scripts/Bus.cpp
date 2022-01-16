#include "Bus.h"

// Ввод параметров машины.
void Bus::in(std::ifstream &input) {
    input >> gaz >> waste >> seats;
}

// Случайное заполнение параметров.
void Bus::inRnd() {
    gaz = rand() % 100 + 1;
    waste = (rand() % 100) * 0.01 + rand() % 99 + 1;
    seats = rand() % 300 + 1;
}

// Вывод параметров в форматируемый поток.
void Bus::out(std::ofstream &output) {
    output << "Bus: "
           << "gaz: " << gaz
           << " waste: " << waste
           << " speed: " << seats
           << " distance " << compareValue() << "\n";
}