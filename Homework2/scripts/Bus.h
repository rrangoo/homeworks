
#ifndef HOMEWORK_1_BUS_H
#define HOMEWORK_1_BUS_H
#include "Vehicle.h"

class Bus : public Vehicle{
private:
    short seats;
public:

    Bus(){
        seats = 0;
    }
// Ввод параметров машины из файла.
    void in(std::ifstream &input) override;

// Случайный ввод параметров машины.
    void inRnd() override;

// Вывод параметров машины в форматируемый поток.
    void out(std::ofstream &output) override;
};

#endif //HOMEWORK_1_BUS_H
