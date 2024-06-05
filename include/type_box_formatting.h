#ifndef TYPTRAC_TYPE_BOX_FORMATTING_H
#define TYPTRAC_TYPE_BOX_FORMATTING_H

#include <string>
#include <vector>

class TypeBoxFormatting {
public:
    static void format(std::string &typed_text, std::string &wrong_text, std::string &untyped_text, int width);

    static void format_wrong_text(std::string &wrong_text);

    static void wrap_text(std::string &typed_text, std::string &wrong_text, std::string &untyped_text, int width);
    static size_t which_text_to_write(std::vector<std::string> &texts, int pos);
    static size_t which_text_to_delete(std::vector<std::string> &wrapped_texts);
    static int current_word_length(const std::string &total_text, int pos);
};

#endif //TYPTRAC_TYPE_BOX_FORMATTING_H
