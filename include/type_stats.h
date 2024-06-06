#ifndef TYPTRAC_TYPE_STATS_H
#define TYPTRAC_TYPE_STATS_H

#include <string>
#include "time_queue.h"

class TypeStats {
public:
    TypeStats();
    ~TypeStats() = default;
    
    void update(const std::string &typed_text, const std::string &wrong_text, const std::string &untyped_text);
    void update_changes();
    void update_queues();
    void update_stats();

    double get_wpm() const;
    double get_cpm() const;
    double get_accuracy() const;

private:
    const double MAX_DURATION = 10.0;

    std::string typed_text, wrong_text, untyped_text;
    std::string prev_typed_text, prev_wrong_text, prev_untyped_text;
    int total_words, total_chars;
    int d_words, d_chars, d_errors;
    double wpm, cpm, accuracy;
    double max_duration;

    TimeQueue words_queue, chars_queue, errors_queue;
};

#endif //TYPTRAC_TYPE_STATS_H
