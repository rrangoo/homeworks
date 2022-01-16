
#ifndef HOMEWORK_1_CAR_H
#define HOMEWORK_1_CAR_H
#include "Vehicle.h"

class Car : public Vehicle{
private:
    short speed;

public:

    Car(){
        speed = 0;
    }
// Ввод параметров машины из файла.
    void in(std::ifstream &input) override;

// Случайный ввод параметров машины.
    void inRnd() override;

// Вывод параметров машины в форматируемый поток.
    void out(std::ofstream &output) override;
};

#endif //HOMEWORK_1_CAR_H
