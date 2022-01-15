#include "Car.h"

// Реализация функций для легкового автомобиля.

// Расчет максимально возможного расстояния, которое может проехать автомобиль.
double Car::max_distance() {
    return gaz_tank / waste * 100;
}

// Вывод в файл.
bool Car::Out(FILE *file) {
    fprintf(file, "Car: gaz tank = %d, waste = %f, max speed = %hd, max distance = %f\n", gaz_tank, waste, max_speed, max_distance());
    return true;
}

// Ввод из файла.
int Car::In(FILE *file) {
    char buffer1[100], buffer2[100], buffer3[100];
    if (fscanf(file, "%s%s%s", buffer1, buffer2, buffer3) == EOF) {
        return 2;
    }
    if ((gaz_tank = atoi(buffer1)) <= 0 && (gaz_tank = atoi(buffer1)) > 50) {
        return 0;
    }

    if ((waste = atoi(buffer2)) <= 0 && (waste = atoi(buffer2)) > 20) {
        return 0;
    }

    if ((max_speed = atoi(buffer3)) <= 0 && (max_speed = atoi(buffer3)) > 300) {
        return 0;
    }
    return 1;
}

// Ввод случайных полей.
bool Car::InRnd() {
    // Рандомная генерация от 1 до 300.
    max_speed = rand() % 300 + 1;
    gaz_tank = rand() % 50 + 1;
    waste = rand() % 20 + 1;
    return true;
}
