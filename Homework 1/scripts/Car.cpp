#include "Car.h"

// Ввод параметров машины.
void in(Car &car, std::ifstream &input) {
    input >> car.gaz >> car.waste >> car.speed;
}

// Случайное заполнение параметров.
void inRnd(Car &car) {
    car.gaz = rand() % 100 + 1;
    car.waste = (rand() % 100) * 0.01 + rand() % 99 + 1;
    car.speed = rand() % 300 + 1;
}

// Вывод параметров в форматируемый поток.
void out(Car &car, std::ofstream &output) {
    output << "Car: "
           << "gaz: " << car.gaz
           << " waste: " << car.waste
           << " speed: " << car.speed
           << " distance " << distance(car);
}

// Параматр для сравнения.
double distance(Car &car) {
    return car.gaz / car.waste;
}
