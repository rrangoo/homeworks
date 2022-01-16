#include "Car.h"

// Ввод параметров машины.
void Car::in(std::ifstream &input) {
    input >> gaz >> waste >> speed;
}

// Случайное заполнение параметров.
void Car::inRnd() {
    gaz = rand() % 100 + 1;
    waste = (rand() % 100) * 0.01 + rand() % 99 + 1;
    speed = rand() % 300 + 1;
}

// Вывод параметров в форматируемый поток.
void Car::out(std::ofstream &output) {
    output << "Car: "
           << "gaz: " << gaz
           << " waste: " << waste
           << " speed: " << speed
           << " distance " << compareValue() << "\n";
}