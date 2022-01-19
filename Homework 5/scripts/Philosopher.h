#ifndef HOMEWORK_5_PHILOSOPHER_H
#define HOMEWORK_5_PHILOSOPHER_H

#include <string>
#include "thread"
#include "chrono"
#include "Waiter.h"

class Philosopher {
private:
    std::string name;
    Waiter *waiter;
    int id;
    int counter;

public:
    explicit Philosopher(std::string name, Waiter *waiter, int id);

    void Run();

    void thinking();
    void take_right();
    void take_left();
    void eat();

    std::string get_name();
};

#endif //HOMEWORK_5_PHILOSOPHER_H
