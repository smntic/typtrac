#include "pair_timer.h"
#include "utils.h"

void PairTimer::set_pair_times(std::shared_ptr<PairTimes> pair_times) {
    this->pair_times = pair_times;
}

void PairTimer::begin(char first, char second) {
    start_seconds = Utils::get_seconds();
}

void PairTimer::end(char first, char second) {
    double end_seconds = Utils::get_seconds();
    double elapsed_seconds = end_seconds - start_seconds;
    pair_times->update_time(first, second, elapsed_seconds);
}

