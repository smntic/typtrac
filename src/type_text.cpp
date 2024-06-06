#include "type_text.h"
#include <algorithm>

TypeText::TypeText() 
    : furthest_pos(-1) {
    pair_timer = std::make_shared<PairTimer>();
    pair_times = std::make_shared<PairTimes>();

    pair_timer->set_pair_times(pair_times);
    update_text();
}

void TypeText::type_char(char ch) {
    if (wrong_text.empty() && !untyped_text.empty() && ch == untyped_text[0]) {
        typed_text += ch;
        untyped_text = untyped_text.substr(1);

        int pos = (int)typed_text.size() - 1;
        if (pos > furthest_pos) {
            furthest_pos = pos;
            update_pair_timer();
        }
    
        if (ch == ' ') {
            update_text();
        }
    } else {
        wrong_text += ch;
    }
}

void TypeText::delete_char() {
    if (!wrong_text.empty()) {
        wrong_text.pop_back();
    } else if (!typed_text.empty()) {
        untyped_text = typed_text.back() + untyped_text;
        typed_text.pop_back();
    }
}

void TypeText::update_text() {
    int untyped_words = std::count(untyped_text.begin(), untyped_text.end(), ' ');
    word_picker.update_biases(pair_times);

    while (untyped_words < WORDS_AHEAD) {
        generate_word();
        untyped_words++;
    }
}

void TypeText::generate_word() {
    add_word(word_picker.random_word());
}

void TypeText::add_word(std::string word) {
    untyped_text += word + ' ';
}

void TypeText::update_pair_timer() {
    char furthest_char = get_char(furthest_pos);
    char next_char = get_char(furthest_pos + 1);

    if (furthest_pos > 0) {
        char prev_char = get_char(furthest_pos - 1);
        pair_timer->end(prev_char, furthest_char);
    }
    pair_timer->begin(furthest_char, next_char);
}

char TypeText::get_char(int pos) const {
    return pos < typed_text.size() ? typed_text[pos] : untyped_text[pos - typed_text.size()];
}

std::string TypeText::get_typed() const {
    return typed_text;
}

std::string TypeText::get_wrong() const {
    return wrong_text;
}

std::string TypeText::get_untyped() const {
    return untyped_text;
}

