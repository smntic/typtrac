#include "type_stats.h"
#include <algorithm>
#include <chrono>

TypeStats::TypeStats() 
    : max_duration(MAX_DURATION), words_queue(max_duration), chars_queue(max_duration), errors_queue(max_duration) {
    double start_time = get_seconds();
    words_queue.start(start_time);
    chars_queue.start(start_time);
    errors_queue.start(start_time);
}

void TypeStats::update(const std::string &typed_text, const std::string &wrong_text, const std::string &untyped_text) {
    this->typed_text = typed_text;
    this->wrong_text = wrong_text;
    this->untyped_text = untyped_text;

    update_changes();
    update_queues();
    update_stats();
}

void TypeStats::update_changes() {
    d_words = d_chars = d_errors = 0;

    if (wrong_text.size() > prev_wrong_text.size()) {
        d_errors = (int)wrong_text.size() - prev_wrong_text.size();
    }

    int cur_chars = typed_text.size();
    int cur_words = std::count(typed_text.begin(), typed_text.end(), ' ');

    if (cur_words > total_words) {
        d_words = cur_words - total_words;
        total_words = cur_words;
    }
    if (cur_chars > total_chars) {
        d_chars = cur_chars - total_chars;
        total_chars = cur_chars;
    }
}

void TypeStats::update_queues() {
    double seconds = get_seconds();
    words_queue.update(seconds);
    chars_queue.update(seconds);
    errors_queue.update(seconds);

    words_queue.add(seconds, d_words);
    chars_queue.add(seconds, d_chars);
    errors_queue.add(seconds, d_errors);
}

void TypeStats::update_stats() {
    double cur_duration = words_queue.get_duration();
    wpm = words_queue.query() / cur_duration * 60.0;
    cpm = chars_queue.query() / cur_duration * 60.0;
    accuracy = std::max(0.0, 1 - (double)errors_queue.query() / chars_queue.query());
}

double TypeStats::get_wpm() const {
    return wpm;
}

double TypeStats::get_cpm() const {
    return cpm;
}

double TypeStats::get_accuracy() const {
    return accuracy;
}

double TypeStats::get_seconds() const {
    auto now = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(now.time_since_epoch()).count();
}

