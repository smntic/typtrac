#ifndef TYPTRAC_TYPE_TEXT_H
#define TYPTRAC_TYPE_TEXT_H

#include <string>

class TypeText {
public:
    TypeText() = default;
    ~TypeText() = default;

    void set_text(const std::string &text);

    void type_char(char ch);
    void delete_char();

    std::string get_typed() const;
    std::string get_wrong() const;
    std::string get_untyped() const;

private:
    std::string typed_text, wrong_text, untyped_text;
};

#endif //TYPTRAC_TYPE_TEXT_H
