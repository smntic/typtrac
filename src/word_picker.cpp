#include "word_picker.h"
#include "languages/english1k.h"
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
    biases = std::vector<double>(ENGLISH1K_SIZE, 1);
}

void WordPicker::update_biases(std::shared_ptr<PairTimes> pair_times) {
    for (int i = 0; i < ENGLISH1K_SIZE; i++) {
        biases[i] = 1.0 + pair_times->get_word_time(ENGLISH1K[i]) / strlen(ENGLISH1K[i]);
    }
}

std::string WordPicker::random_word() {
    std::vector<int> indices(ENGLISH1K_SIZE);
    std::iota(indices.begin(), indices.end(), 0);

    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return biases[a] > biases[b];
    });

    for (int i = 0; i < ENGLISH1K_SIZE; i++) {
        double cur = (double)rand() / RAND_MAX;
        if (cur < 0.5) {
            return ENGLISH1K[indices[i]];
        }
    }

    return ENGLISH1K[indices[ENGLISH1K_SIZE - 1]];
}

