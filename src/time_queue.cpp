#include "time_queue.h"

TimeQueue::TimeQueue(double max_duration)
    : max_duration(max_duration) {}

void TimeQueue::start(double time) {
    start_time = time;
}

void TimeQueue::add(double time) {
    queue.push(time);
}

void TimeQueue::add(double time, int times) {
    for (int i = 0; i < times; i++) {
        add(time);
    }
}

void TimeQueue::update(double time) {
    while (queue.size() > 0 && time - queue.front() > max_duration) {
        queue.pop();
    }

    start_time = std::max(start_time, time - max_duration);
    last_time = time;
}

int TimeQueue::query() {
    return queue.size();
}

double TimeQueue::get_duration() const {
    return std::min(max_duration, last_time - start_time);
}

