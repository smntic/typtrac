#include "type_stats.h"
#include <algorithm>
#include <chrono>

TypeStats::TypeStats() {
    start_seconds = get_seconds();
}

void TypeStats::update(const std::string &typed_text, const std::string &wrong_text, const std::string &untyped_text) {
    if (wrong_text.size() > prev_wrong_text.size()) {
        total_errors += wrong_text.size() - prev_wrong_text.size();
    }

    int cur_chars = typed_text.size();
    int cur_words = std::count(typed_text.begin(), typed_text.end(), ' ');

    total_chars = std::max(cur_chars, total_chars);
    total_words = std::max(cur_words, total_words);

    double seconds = get_seconds();
    double elapsed = seconds - start_seconds;

    wpm = total_words / elapsed * 60.0;
    cpm = total_chars / elapsed * 60.0;
    accuracy = std::max(0.0, 1 - (double)total_errors / total_chars);

    prev_typed_text = typed_text;
    prev_wrong_text = wrong_text;
    prev_untyped_text = untyped_text;
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

