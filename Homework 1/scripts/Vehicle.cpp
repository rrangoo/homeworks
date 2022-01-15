#include "Vehicle.h"

// Ввод обобщения растения.
Vehicle *in(std::ifstream &input) {
    Vehicle *vehicle = new Vehicle;

    int typeOfVehicle;
    input >> typeOfVehicle;

    switch (typeOfVehicle) {
        case 0:
            vehicle->typeOfVehicle = Vehicle::CAR;
            in(vehicle->car, input);
            return vehicle;
        case 1:
            vehicle->typeOfVehicle = Vehicle::BUS;
            in(vehicle->bus, input);
            return vehicle;
        case 2:
            vehicle->typeOfVehicle = Vehicle::TRUCK;
            in(vehicle->truck, input);
            return vehicle;
        default:
            return nullptr;
    }
}

// Случайный ввод обобщения растения.
Vehicle *inRnd() {
    Vehicle *vehicle = new Vehicle;
    int typeOfVehicle = std::rand() % 3;

    switch (typeOfVehicle) {
        case 0:
            vehicle->typeOfVehicle = Vehicle::CAR;
            inRnd(vehicle->car);
            return vehicle;
        case 1:
            vehicle->typeOfVehicle = Vehicle::BUS;
            inRnd(vehicle->bus);
            return vehicle;
        case 2:
            vehicle->typeOfVehicle = Vehicle::TRUCK;
            inRnd(vehicle->truck);
            return vehicle;
        default:
            return nullptr;

    }
}

// Вывод обобщения растения.
void out(Vehicle &vehicle, std::ofstream &output) {
    switch (vehicle.typeOfVehicle) {
        case Vehicle::BUS:
            out(vehicle.bus, output);
            break;
        case Vehicle::CAR:
            out(vehicle.car, output);
            break;
        case Vehicle::TRUCK:
            out(vehicle.truck, output);
            break;
        default:
            output << "incorrect type of vehicle!\n";
    }
    output << "\n";
}


// Параметр сортировки.
double compareValue(Vehicle &vehicle) {
    switch (vehicle.typeOfVehicle) {
        case Vehicle::BUS:
            return distance(vehicle.bus);
        case Vehicle::CAR:
            return distance(vehicle.car);
        case Vehicle::TRUCK:
            return distance(vehicle.truck);
        default:
            return -1;
    }
}
