#include "Vehicle.h"

class Bus: public Vehicle{
private:
    // Максимальная скорость.
    short max_seats;

public:
    // Расчет максимально возможного расстояния, которое может проехать автомобиль.
    double max_distance() override;

    // Вывод в файл.
    bool Out(FILE *file) override;
    // Ввод из файла.
    int In(FILE *file) override;
    // Ввод случайных полей.
    bool InRnd() override;
};

