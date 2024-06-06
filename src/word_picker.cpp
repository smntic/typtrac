#include "word_picker.h"
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <time.h>

WordPicker::WordPicker() 
    : gen(rd()) {
    init_biases();
    init_random();
}

void WordPicker::init_random() {
    srand(time(nullptr));
}

void WordPicker::init_biases() {
    biases = std::vector<double>(language.size(), 1);
}

void WordPicker::update_biases(std::shared_ptr<PairTimes> pair_times) {
    for (int i = 0; i < language.size(); i++) {
        double type_time = pair_times->get_word_time(language.get_word(i));
        double length = language.get_word(i).size();
        biases[i] = type_time / length;
    }
}

std::string WordPicker::random_word() {
    std::vector<int> indices(language.size());
    std::iota(indices.begin(), indices.end(), 0);

    std::shuffle(indices.begin(), indices.end(), gen);

    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return biases[a] > biases[b];
    });

    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    for (int i = 0; i < language.size(); i++) {
        double cur = distribution(gen);
        if (cur < 0.5) {
            return language.get_word(indices[i]);
        }
    }

    return language.get_word(indices[language.size() - 1]);
}

