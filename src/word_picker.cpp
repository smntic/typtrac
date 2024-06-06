#include "word_picker.h"
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <time.h>

WordPicker::WordPicker() {
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
        biases[i] = 1.0 + pair_times->get_word_time(language.get_word(i)) / language.get_word(i).size();
    }
}

std::string WordPicker::random_word() {
    std::vector<int> indices(language.size());
    std::iota(indices.begin(), indices.end(), 0);

    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return biases[a] > biases[b];
    });

    for (int i = 0; i < language.size(); i++) {
        double cur = (double)rand() / RAND_MAX;
        if (cur < 0.5) {
            return language.get_word(indices[i]);
        }
    }

    return language.get_word(indices[language.size() - 1]);
}

