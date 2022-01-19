#ifndef HOMEWORK_5_FORK_H
#define HOMEWORK_5_FORK_H
#include "mutex"

class Fork {
private:
    std::mutex mtx;
    bool is_free;

public:
    Fork();
    bool free();

    void busy();
    void release();
};


#endif //HOMEWORK_5_FORK_H
