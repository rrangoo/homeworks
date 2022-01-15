#include "Vehicle.h"

// Содержит описание класса "Легковой автомобиль".
class Truck: public Vehicle{
private:
    // Грузоподъемность.
    int max_weight;

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
