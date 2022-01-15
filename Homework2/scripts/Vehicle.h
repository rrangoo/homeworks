#ifndef TASK2_VEHICLE_H
#define TASK2_VEHICLE_H

#include "stdio.h"
#include "stdlib.h"

// Родительский класс всех транспортных средств.
class Vehicle {
protected:
    // Емкость бензобака в литрах.
    int gaz_tank = 0;

    // Расход топлива на 100км в литрах.
    double waste = 0;

public:
    // Расчет максимально возможного расстояния, которое может проехать автомобиль.
    virtual double max_distance() = 0;

    // Вывод в файл.
    virtual bool Out(FILE *file) = 0;
    // Ввод из файла.
    virtual int In(FILE *file) = 0;
    // Ввод случайных полей.
    virtual bool InRnd() = 0;
};

#endif //TASK2_VEHICLE_H