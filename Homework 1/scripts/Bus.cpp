#include "Bus.h"

// Ввод параметров автобуса.
void in(Bus &bus, std::ifstream &input) {
    input >> bus.gaz >> bus.waste >> bus.seats;
}

// Случайное заполнение параметров.
void inRnd(Bus &bus) {
    bus.gaz = rand() % 100 + 1;
    bus.waste = (rand() % 100) * 0.01 + rand() % 99 + 1;
    bus.seats = rand() % 40 + 1;
}

// Вывод параметров в форматируемый поток.
void out(Bus &bus, std::ofstream &output) {
    output << "Bus: "
    << "gaz: " << bus.gaz
    << " waste: " << bus.waste
    << " seats: " << bus.seats
    << " distance: " << distance(bus);
}

// Параматр для сравнения.
double distance(Bus &bus) {
    return bus.gaz / bus.waste;
}
