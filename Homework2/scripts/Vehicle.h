
#ifndef HOMEWORK_1_VEHICLE_H
#define HOMEWORK_1_VEHICLE_H
#include "fstream"

class Vehicle {
protected:
    int gaz;
    double waste;

public:
    Vehicle(){
        gaz = 0;
        waste = 0;
    }
// Ввод обобщения транспорта.
    virtual void in(std::ifstream &input) = 0;

// Случайный ввод обобщения транспорта.
    virtual void inRnd() = 0;

// Вывод обобщения транспорта.
    virtual void out(std::ofstream &output) = 0;

// Параметр сортировки.
    double compareValue() const{
        return gaz / waste * 100;
    }
};

#endif //HOMEWORK_1_VEHICLE_H
