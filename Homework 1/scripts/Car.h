
#ifndef HOMEWORK_1_CAR_H
#define HOMEWORK_1_CAR_H
#include "fstream"

struct Car {
    short speed;
    int gaz;
    double waste;
};

// Ввод параметров машины из файла.
void in(Car &car, std::ifstream &input);

// Случайный ввод параметров машины.
void inRnd(Car &car);

// Вывод параметров машины в форматируемый поток.
void out(Car &car, std::ofstream &output);


// Максимальное расстояние которое может пройти транспотное средство.
double distance(Car &car);

#endif //HOMEWORK_1_CAR_H
