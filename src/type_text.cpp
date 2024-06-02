#include "type_text.h"

void TypeText::set_text(const std::string &text) {
    typed_text = "";
    wrong_text = "";
    untyped_text = text;
}

void TypeText::type_char(char ch) {
    if (wrong_text.empty() && !untyped_text.empty() && ch == untyped_text[0]) {
        typed_text += ch;
        untyped_text = untyped_text.substr(1);
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

std::string TypeText::get_typed() const {
    return typed_text;
}

std::string TypeText::get_wrong() const {
    return wrong_text;
}

std::string TypeText::get_untyped() const {
    return untyped_text;
}

