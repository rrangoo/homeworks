#include "Waiter.h"

Waiter::Waiter(std::vector<Fork *> forks) {
    this->forks = std::move(forks);
}

bool Waiter::is_possible(int id) {
    return forks[(id + 1) % 5]->free() && forks[id]->free();
}

void Waiter::take_right(int id) {
    forks[(id + 1) % 5]->busy();
}

void Waiter::take_left(int id) {
    forks[id]->busy();
}

void Waiter::release(int id) {
    forks[(id + 1) % 5]->release();
    forks[id]->release();
}
