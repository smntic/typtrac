#ifndef TYPTRAC_PAIR_TIMES_H
#define TYPTRAC_PAIR_TIMES_H

#include <map>
#include <string>

class PairTimes {
public:
    PairTimes();
    ~PairTimes() = default;

    void update_time(char first, char second, double seconds);
    double get_time(char first, char second);

    double get_word_time(const std::string &word);

private:
    std::map<std::pair<char, char>, double> times;
    double average_time;
};

#endif //TYPTRAC_PAIR_TIMES_H
