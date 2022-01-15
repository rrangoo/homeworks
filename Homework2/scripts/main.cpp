#include <iostream>
#include "time.h"
#include "string.h"
#include "stdlib.h"
#include <sys/stat.h>
#include "Container.h"

// Вывод при некорректных аргументах при запуске.
void error() {
    printf("incorrect qualifier value!\n  Waited:\n     command -f infile outfile01 outfile02\n");
    printf("  Or:\n     command -n number outfile01 outfile02\n");
}

//
bool isFile(char *argv[], int *size) {
    if (!strcmp(argv[1], "-f")) { return true; }
    else if (!strcmp(argv[1], "-n")) { *size = atoi(argv[2]); }
    return false;
}

int main(int argc, char *argv[]) {

    // начало отсчета времени.
    unsigned int start_time =  clock();

    if (argc != 5) {
        error();
        return 1;
    }
    printf("Start. . .\n");

    int size;
    FILE *file;

    printf("Generating file pathes. . .\n");

    // Путь к файлу с тестами.
    const char *test_file;

    printf("File pathes created.\n");

    printf("Container creating. . .\n");

    // Создаем новый контейнер.
    Container *container = new Container();

    printf("Container created.\n");

    // Проверяем тип ввода данных.
    if (isFile(argv, &size)) {

        test_file = argv[2];
        // Если ввод с файла.
        struct stat buffer;

        // Проверка файла.
        if (stat(test_file, &buffer)) {
            printf("Invalid file name!\n");
            return 4;
        }

        // Считываем данные из файла.
        file = fopen(test_file, "r");
        fscanf(file, "%d", &size);

        // проыеряем данные на корректность
        if ((size < 1) || (size > 10000)) {
            printf("incorrect number of figures = %d. Set 0 < x <= 10000\n", size);
            return 3;
        }

        // Инициализируем массив.
        container->Init(&size);

        // Считываем данные.
        container->In(file, size);
        fclose(file);

    } else {
        // Иначе генерируем рандомные тесты.

        // Проверяем корректность аргументов.
        if (!strcmp(argv[1], "-f") && !strcmp(argv[1], "-n")) {
            error();
            return 2;
        }

        // Инициализируем массив.
        container->Init(&size);

        // Используем системные часы в качестве сида для рандомайзера.
        srand((unsigned int) (time(0)));

        // Заполнение контейнера.
        container->InRnd(size);
    }

    // Выводим размер.
    printf("size = %d\n", size);

    // Записываем результат в файл.
    file = fopen(argv[3], "w+");
    container->Out(file);
    fclose(file);

    // Сортируем и записываем результаты.
    file = fopen(argv[4], "w+");

    container->HeapSort();

    container->Out(file);
    fprintf(file, "\n");
    fclose(file);

    // Очищаем контейнер.
    delete container;

    // Конец отсчета времени.
    unsigned int end_time = clock();

    printf("Finish (%f) ms", clock()/1000000.0); // время работы программы
    return 0;
}
