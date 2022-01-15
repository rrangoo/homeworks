#include "Bus.h"

// Расчет максимально возможного расстояния, которое может проехать автомобиль.
double Bus::max_distance() {
    return gaz_tank / waste * 100;
}

// Вывод в файл.
bool Bus::Out(FILE *file) {
    fprintf(file, "Bus: gaz tank = %d, waste = %f, max seats = %d, max distance = %f\n", gaz_tank, waste, max_seats, max_distance());
    return true;
}

// Ввод из файла.
int Bus::In(FILE *file) {
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

    if ((max_seats = atoi(buffer3)) <= 0 && (max_seats = atoi(buffer3)) > 30) {
        return 0;
    }
    return 1;
}

// Ввод случайных полей.
bool Bus::InRnd() {
    // Рандомная генерация от 1 до 30.
    max_seats = rand() % 30 + 1;
    gaz_tank = rand() % 50 + 1;
    waste = rand() % 20 + 1;
    return true;
}