#ifndef TYPTRAC_PAIR_TIMER_H
#define TYPTRAC_PAIR_TIMER_H

#include "pair_times.h"
#include <memory>

class PairTimer {
public:
    PairTimer() = default;
    ~PairTimer() = default;

    void set_pair_times(std::shared_ptr<PairTimes> pair_times);

    void begin(char first, char second);
    void end(char first, char second);

private:
    std::shared_ptr<PairTimes> pair_times;
    double start_seconds;

    double get_seconds() const;
};

#endif //TYPTRAC_PAIR_TIMER_H
