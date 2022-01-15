
#ifndef HOMEWORK_1_VEHICLE_H
#define HOMEWORK_1_VEHICLE_H

#include "Bus.h"
#include "Car.h"
#include "Truck.h"

struct Vehicle{
    enum key {
        BUS = 0,
        TRUCK = 1,
        CAR = 2
    };

    Bus bus;
    Truck truck;
    Car car;

    key typeOfVehicle;
};

// Ввод обобщения транспорта.
Vehicle *in(std::ifstream &input);

// Случайный ввод обобщения транспорта.
Vehicle *inRnd();

// Вывод обобщения транспорта.
void out(Vehicle &vehicle, std::ofstream &output);


// Параметр сортировки.
double compareValue(Vehicle &vehicle);


#endif //HOMEWORK_1_VEHICLE_H
