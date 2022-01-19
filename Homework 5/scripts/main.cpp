#include "iostream"
#include "thread"
#include "vector"
#include "Philosopher.h"
#include "chrono"
#include "Waiter.h"
#include "Fork.h"

// Init list of philosophers.
void init_philosophers(std::vector<Philosopher *> &list, Waiter *waiter){
    std::string names[5] = {"Plato", "Kant", "Nietzsche", "Buddha", "Confucius"};

    list.resize(5);

    for (int i = 0; i < 5; ++i) {
        list[i] = new Philosopher(names[i], waiter, i);
    }
}

void init_forks(std::vector<Fork *> &list){
    list.resize(5);

    for (int i = 0; i < 5; ++i) {
        list[i] = new Fork;
    }
}

void thinking(Philosopher *philosopher){
    philosopher->Run();
}
int main(){
    std::vector<Philosopher *> philosophers;

    std::vector<Fork *> forks;
    init_forks(forks);

    std::vector<std::thread> threads;

    Waiter *waiter = new Waiter(forks);

    init_philosophers(philosophers, waiter);

    // Creating threads.
    for (Philosopher *philosopher: philosophers) {
        std::thread thread(thinking, philosopher);
        threads.push_back(std::move(thread));
    }

    // joining threads.
    for (auto & thread : threads) {
        thread.join();
    }
}