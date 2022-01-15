#include "Truck.h"

// Ввод параметров грузовика.
void in(Truck &truck, std::ifstream &input) {
    input >> truck.gaz >> truck.waste >> truck.carry;
}

// Случайное заполнение параметров.
void inRnd(Truck &truck) {
    truck.gaz = rand() % 100 + 1;
    truck.waste = (rand() % 100) * 0.01 + rand() % 99 + 1;
    truck.carry = rand() % 5000 + 1;
}

// Вывод параметров в форматируемый поток.
void out(Truck &truck, std::ofstream &output) {
    output << "Truck: "
           << "gaz: " << truck.gaz
           << " waste: " << truck.waste
           << " carry: " << truck.carry
           << " distance: " << distance(truck);
}


// Параматр для сравнения.
double distance(Truck &truck) {
    return truck.gaz / truck.waste * 100;
}
