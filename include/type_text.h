#ifndef TYPTRAC_TYPE_TEXT_H
#define TYPTRAC_TYPE_TEXT_H

#include "word_picker.h"
#include <string>

class TypeText {
public:
    TypeText();
    ~TypeText() = default;

    void type_char(char ch);
    void delete_char();

    std::string get_typed() const;
    std::string get_wrong() const;
    std::string get_untyped() const;

private:
    std::string typed_text, wrong_text, untyped_text;
    WordPicker word_picker;

    void update_text();
    void generate_word();
    void add_word(std::string word);
};

#endif //TYPTRAC_TYPE_TEXT_H
