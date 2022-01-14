
#ifndef HOMEWORK_1_BUS_H
#define HOMEWORK_1_BUS_H
#include "fstream"

struct Bus {
    short seats;
    int gaz;
    double waste;
};

// Ввод параметров автобуса из файла.
void in(Bus &bus, std::ifstream &input);

// Случайный ввод параметров автобуса.
void inRnd(Bus &bus);

// Вывод параметров автобуса в форматируемый поток.
void out(Bus &bus, std::ofstream &output);

// Максимальное расстояние которое может пройти транспотное средство.
double distance(Bus &bus);

#endif //HOMEWORK_1_BUS_H
