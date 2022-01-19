#include "Fork.h"

Fork::Fork() {
    this->is_free = true;
}

bool Fork::free() {
    return this->is_free;
}

void Fork::busy() {
    is_free = false;
    mtx.lock();
}

void Fork::release() {
    is_free = true;
    mtx.unlock();
}


