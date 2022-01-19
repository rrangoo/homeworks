
#include <iostream>
#include "Philosopher.h"

Philosopher::Philosopher(std::string name, Waiter *waiter, int id) {
    this->name = name;
    this->waiter = waiter;
    this->id = id;
    this->counter = 0;
}

void Philosopher::Run() {
    for (int i = 0; i < 5; ++i) {
        thinking();
        take_right();
        take_left();
        eat();
        ++counter;
    }
}

void Philosopher::take_right() {
    std::cout << this->name << ": I've tried to take right fork...\n";

    while (!waiter->is_possible(id)){

    }

    waiter->take_right(id);

    std::cout << this->name << ": I've taken right fork...\n";
}

void Philosopher::thinking() {
    std::cout << this->name << ": I'm thinking...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds((rand() % 3 + 1) * 1000));
}

void Philosopher::take_left() {
    std::cout << this->name << ": I'm taking left fork...\n";
    waiter->take_left(id);
}

void Philosopher::eat() {
    std::cout << this->name << ": I'm eating...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds((rand() % 3 + 1) * 1000));
    std::cout << this->name << ": I'm finish... [" << counter + 1 << "/5]\n";
    waiter->release(id);
}

std::string Philosopher::get_name() {
    return name;
}

