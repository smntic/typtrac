#include "word_picker.h"
#include "languages/english1k.h"
#include <time.h>

WordPicker::WordPicker() {
    init_biases();
    init_random();
}

void WordPicker::init_random() {
    srand(time(nullptr));
}

void WordPicker::init_biases() {
    biases = std::vector<int>(ENGLISH1K_SIZE, 1);
}

std::string WordPicker::random_word() {
    int sum = 0;
    for (int bias : biases) {
        sum += bias;
    }
    int random_index = std::rand() % sum;
    int index = 0;
    while (random_index >= biases[index]) {
        random_index -= biases[index];
        index++;
    }
    return ENGLISH1K[index];
}

