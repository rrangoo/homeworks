#ifndef HOMEWORK_5_WAITER_H
#define HOMEWORK_5_WAITER_H

#include "deque"
#include "vector"
#include "Fork.h"

class Waiter {
private:
    std::vector<Fork *> forks;

public:
    explicit Waiter(std::vector<Fork *> forks);
    bool is_possible(int id);
    void take_right(int id);
    void take_left(int id);
    void release(int id);
};


#endif //HOMEWORK_5_WAITER_H
