#include "pair_timer.h"
#include <chrono>

void PairTimer::set_pair_times(std::shared_ptr<PairTimes> pair_times) {
    this->pair_times = pair_times;
}

void PairTimer::begin(char first, char second) {
    start_seconds = get_seconds();
}

void PairTimer::end(char first, char second) {
    double end_seconds = get_seconds();
    double elapsed_seconds = end_seconds - start_seconds;
    pair_times->update_time(first, second, elapsed_seconds);
}

double PairTimer::get_seconds() const { // TODO: this is the same as in type_stats.cpp -> refactor into utils.cpp
    auto now = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(now.time_since_epoch()).count();
}

