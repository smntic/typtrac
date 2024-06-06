#include "pair_times.h"

PairTimes::PairTimes() : average_time(0.0) {}

void PairTimes::update_time(char first, char second, double seconds) {
    average_time = (average_time + seconds) / 2.0;
    times[{first, second}] = (times[{first, second}] + seconds) / 2.0;
}

double PairTimes::get_time(char first, char second) {
    if (times.find({first, second}) == times.end()) {
        return average_time;
    }
    return times[{first, second}];
}

double PairTimes::get_word_time(const std::string &word) {
    double time = average_time;
    for (size_t i = 0; i < word.size() - 1; i++) {
        time += get_time(word[i], word[i + 1]);
    }
    return time;
}

