#ifndef TYPTRAC_TYPE_TEXT_H
#define TYPTRAC_TYPE_TEXT_H

#include "word_picker.h"
#include "pair_timer.h"
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
    const int WORDS_AHEAD = 5;

    std::string typed_text, wrong_text, untyped_text;
    int furthest_pos;

    WordPicker word_picker;
    std::shared_ptr<PairTimes> pair_times;
    std::shared_ptr<PairTimer> pair_timer;

    void update_text();
    void generate_word();
    void add_word(std::string word);

    void update_pair_timer();
    char get_char(int pos) const;
};

#endif //TYPTRAC_TYPE_TEXT_H
