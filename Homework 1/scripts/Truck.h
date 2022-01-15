
#ifndef HOMEWORK_1_TRUCK_H
#define HOMEWORK_1_TRUCK_H
#include "fstream"

struct Truck {
    int carry;
    int gaz;
    double waste;
};

// Ввод параметров грузовика из файла.
void in(Truck &truck, std::ifstream &input);

// Случайный ввод параметров грузовика.
void inRnd(Truck &truck);

// Вывод параметров грузовика в форматируемый поток.
void out(Truck &truck, std::ofstream &output);


// Максимальное расстояние которое может пройти транспотное средство.
double distance(Truck &truck);


#endif //HOMEWORK_1_TRUCK_H
