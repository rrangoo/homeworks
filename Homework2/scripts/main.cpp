#include <iostream>
#include "time.h"
#include "string.h"
#include "stdlib.h"
#include "Container.h"

int main(int argc, char *argv[]) {
    // Проверка аргументов на входе.
    if (argc != 5) {
        std::cout << "incorrect command line!\n"
                     "command <-n/-f> <number(0-10000)/input file> <unsorted file> <sorted file>\n";
        return 1;
    }

    // Начало отсчета.
    clock_t start = clock();

    // Инициализация контейнера.
    std::cout << "Init container. . .\n";
    Container *container = new Container();
    std::cout << "Init container finished!\n";

    // Ввод данных.
    if (!strcmp(argv[1], "-f")) {
        // Чтение из файла.
        std::cout << "Read from file. . .\n";
        std::ifstream input(argv[2]);
        container->in(input);
        std::cout << "Read from file finished!\n";
    } else {
        // Рандомное заполнение.
        std::cout << "Generate random items. . .\n";
        if (!strcmp(argv[1], "-n")) {
            int size = atoi(argv[2]);
            if ((size < 1) || (size > 10000)) {
                std::cout << "incorrect number of vehicles = "
                          << size
                          << ". Set 0 < number <= 10000\n";
                return 3;
            }
            container->inRnd(size);
            std::cout << "Generate random items finished!\n";
        } else {
            std::cout << "incorrect count of vehicles!\n";
            return 2;
        }
    }

    // Вывод содержимого контейнера в файл.
    std::cout << "Filling unsorted container. . .\n";
    std::ofstream unsortedOutput(argv[3]);
    unsortedOutput << "Filled container:\n";
    container->out(unsortedOutput);
    std::cout << "Unsorted container filled!\n";

    // Сортировка.
    std::cout << "Sorting. . .\n";
    container->HeapSort();
    std::cout << "Sorted!\n";

    // Вывод отсортированного списка.
    std::cout << "Filling sorted container. . .\n";
    std::ofstream sortedOutput(argv[4]);
    sortedOutput << "Sorted container:\n";
    container->out(sortedOutput);
    std::cout << "Sorted container filled!\n";

    // Очистка памяти.
    std::cout << "Clear container. . .\n";
    delete container;
    std::cout << "Clear container finished!\n";

    // Конец работы.
    clock_t end = clock();

    // Рассчет времени работы.
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time: " << seconds;

    return 0;
}
