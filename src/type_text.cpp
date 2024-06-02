#include "type_text.h"
#include "languages/english1k.h" // TODO: choose a language via settings
#include <algorithm>

TypeText::TypeText() {
    update_text();
}

void TypeText::type_char(char ch) {
    if (wrong_text.empty() && !untyped_text.empty() && ch == untyped_text[0]) {
        typed_text += ch;
        untyped_text = untyped_text.substr(1);
    
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

    while (untyped_words < 5) { // TODO: magic number
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

std::string TypeText::get_typed() const {
    return typed_text;
}

std::string TypeText::get_wrong() const {
    return wrong_text;
}

std::string TypeText::get_untyped() const {
    return untyped_text;
}

