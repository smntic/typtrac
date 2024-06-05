#ifndef TYPTRAC_TIME_QUEUE_H
#define TYPTRAC_TIME_QUEUE_H

#include <queue>

class TimeQueue {
public:
    TimeQueue(double duration);
    ~TimeQueue() = default;

    void start(double time);

    void add(double time);
    void add(double time, int times);
    void update(double time);
    int query();

    double get_duration() const;

private:
    std::queue<double> queue;
    double max_duration;
    double last_time;
    double start_time;
};

#endif //TYPTRAC_TIME_QUEUE_H
