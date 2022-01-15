#include "Vehicle.h"

// Содержит описание класса "Легковой автомобиль".
class Car : public Vehicle {
private:
    // Максимальная скорость.
    short max_speed;

public:
    // Расчет максимально возможного расстояния, которое может проехать автомобиль.
    virtual double max_distance() override;

    // Вывод в файл.
    bool Out(FILE *file) override;

    // Ввод из файла.
    int In(FILE *file) override;

    // Ввод случайных полей.
    bool InRnd() override;
};
