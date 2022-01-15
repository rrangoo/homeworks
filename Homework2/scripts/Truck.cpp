#include "Truck.h"

// Расчет максимально возможного расстояния, которое может проехать автомобиль.
double Truck::max_distance() {
    return gaz_tank / waste * 100;
}

// Вывод в файл.
bool Truck::Out(FILE *file) {
    fprintf(file, "Truck: gaz tank = %d, waste = %f, max weight = %d, max distance = %f\n", gaz_tank, waste, max_weight, max_distance());
    return true;
}

// Ввод из файла.
int Truck::In(FILE *file) {
    char buffer1[100], buffer2[100], buffer3[100];
    if (fscanf(file, "%s%s%s", buffer1, buffer2, buffer3) == EOF) {
        return 2;
    }
    if ((gaz_tank = atoi(buffer1)) < 1 && (gaz_tank = atoi(buffer1)) > 50) {
        return 0;
    }

    if ((waste = atoi(buffer2)) < 1 && (waste = atoi(buffer2)) > 20) {
        return 0;
    }

    if ((max_weight = atoi(buffer3)) < 0 && (max_weight = atoi(buffer3)) > 1000) {
        return 0;
    }
    return 1;
}

// Ввод случайных полей.
bool Truck::InRnd() {
    // Рандомная генерация от 1 до 1000.
    max_weight = rand() % 1000 + 1;
    gaz_tank = rand() % 50 + 1;
    waste = rand() % 20 + 1;
    return true;
}
