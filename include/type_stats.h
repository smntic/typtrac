#ifndef TYPTRAC_TYPE_STATS_H
#define TYPTRAC_TYPE_STATS_H

#include <string>

class TypeStats {
public:
    TypeStats();
    ~TypeStats() = default;
    
    void update(const std::string &typed_text, const std::string &wrong_text, const std::string &untyped_text);

    double get_wpm() const;
    double get_cpm() const;
    double get_accuracy() const;

private:
    std::string prev_typed_text, prev_wrong_text, prev_untyped_text;
    double wpm, cpm, accuracy;
    int total_words, total_chars, total_errors;
    double start_seconds;

    double get_seconds() const;
};

#endif //TYPTRAC_TYPE_STATS_H
