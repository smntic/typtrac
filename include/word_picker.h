#ifndef TYPTRAC_RANDOM_H
#define TYPTRAC_RANDOM_H

#include "pair_times.h"
#include "language.h"
#include <memory>
#include <random>
#include <vector>

class WordPicker {
public:
    WordPicker();
    ~WordPicker() = default;

    void update_biases(std::shared_ptr<PairTimes> pair_times);

    std::string random_word();

private:
    Language language;

    void init_biases();
    void init_random();

    std::random_device rd;
    std::mt19937 gen;

    // NOTE: each word gets a bias indicating its relative probability
    // higher bias means higher probability
    std::vector<double> biases;
};

#endif //TYPTRAC_RANDOM_H
