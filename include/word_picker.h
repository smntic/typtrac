#ifndef TYPTRAC_RANDOM_H
#define TYPTRAC_RANDOM_H

#include <string>
#include <vector>

class WordPicker {
public:
    WordPicker();
    ~WordPicker() = default;

    // void update_biases(); // TODO: update the biases based on past mistakes

    std::string random_word();

private:
    void init_biases();
    void init_random();

    // NOTE: each word gets a bias indicating its relative probability
    // higher bias means higher probability
    std::vector<int> biases;
};

#endif //TYPTRAC_RANDOM_H
