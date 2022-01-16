
#ifndef HOMEWORK_1_TRUCK_H
#define HOMEWORK_1_TRUCK_H
#include "Vehicle.h"

class Truck : public Vehicle{
private:
    short carry;
public:

    Truck(){
        carry = 0;
    }
// Ввод параметров машины из файла.
    void in(std::ifstream &input) override;

// Случайный ввод параметров машины.
    void inRnd() override;

// Вывод параметров машины в форматируемый поток.
    void out(std::ofstream &output) override;
};

#endif //HOMEWORK_1_TRUCK_H
