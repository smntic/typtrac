#include "type_box_formatting.h"

void TypeBoxFormatting::format(std::string &typed_text, std::string &wrong_text, std::string &untyped_text, int width) {
    format_wrong_text(wrong_text);
    wrap_text(typed_text, wrong_text, untyped_text, width);
}


void TypeBoxFormatting::format_wrong_text(std::string &wrong_text) {
    std::string formatted_text;
    for (auto &ch : wrong_text) {
        if (ch == ' ' || ch == '\n') {
            ch = '_';
        } 
    }
}

void TypeBoxFormatting::wrap_text(std::string &typed_text, std::string &wrong_text, std::string &untyped_text, int width) {
    std::string total_text = typed_text + wrong_text + untyped_text;
    std::vector<std::string> texts = {typed_text, wrong_text, untyped_text};
    std::vector<std::string> wrapped_texts(3);

    int col = 0;
    for (size_t i = 0; i < total_text.size(); i++) {
        int cur_word_length = current_word_length(total_text, i);

        // we hit the end of the line
        if (col == width && total_text[i] != ' ' && cur_word_length <= width) {
            // 'backspace' to start of current word
            while (i > 0 && total_text[i-1] != ' ') {
                size_t delete_index = which_text_to_delete(wrapped_texts);
                wrapped_texts[delete_index].pop_back();
                i--;
                col--;
            }
            // 'space' until the end of the line
            while (col < width) {
                size_t write_index = which_text_to_write(texts, i-1);
                wrapped_texts[write_index].push_back(' ');
                col++;
            }
            col = 0;
        } else if (col == width) {
            col = 0;
            // prevent adding a space at the start of lines
            if (total_text[i] == ' ') {
                continue;
            }
        }

        size_t write_index = which_text_to_write(texts, i);
        wrapped_texts[write_index].push_back(total_text[i]);
        col++;
    }

    typed_text = wrapped_texts[0];
    wrong_text = wrapped_texts[1];
    untyped_text = wrapped_texts[2];
}

size_t TypeBoxFormatting::which_text_to_write(std::vector<std::string> &texts, int pos) {
    for (size_t i = 0; i < texts.size(); i++) {
        pos -= texts[i].size();
        if (pos < 0) {
            return i;
        }
    }
    return texts.size() - 1;
}

size_t TypeBoxFormatting::which_text_to_delete(std::vector<std::string> &wrapped_texts) {
    for (int i = (int)wrapped_texts.size() - 1; i >= 0; i--) {
        if (!wrapped_texts[i].empty()) {
            return i;
        }
    }
    return 0;
}

int TypeBoxFormatting::current_word_length(const std::string &total_text, int pos) {
    int next_space = total_text.find(' ', pos);
    int prev_space = total_text.rfind(' ', pos);
    if (next_space == std::string::npos) {
        next_space = total_text.size();
    }
    if (prev_space == std::string::npos) {
        prev_space = 0;
    }
    return next_space - prev_space;
}

