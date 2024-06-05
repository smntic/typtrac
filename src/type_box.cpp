#include "type_box.h"
#include "color.h"
#include "type_box_formatting.h"

void TypeBox::custom_render() {
    print_texts();
    wclrtobot(win.get());
}

void TypeBox::print_texts() {
    int wrong_text_offset = (int)typed_text.length();
    int untyped_text_offset = wrong_text_offset + (int)wrong_text.length();

    if (!typed_text.empty()) {
        wattron(win.get(), COLOR_PAIR(Color::TYPED_TEXT));
        print_text(0, typed_text);
    }

    if (!wrong_text.empty()) {
        wattron(win.get(), COLOR_PAIR(Color::WRONG_TEXT));
        print_text(wrong_text_offset, wrong_text);
    }

    if (!untyped_text.empty()) {
        // print the current character with a reverse highlight
        wattron(win.get(), COLOR_PAIR(Color::UNTYPED_TEXT));
        print_text(untyped_text_offset, untyped_text.substr(0, 1));
        print_cursor(untyped_text_offset);

        // print the remaining characters
        wattron(win.get(), COLOR_PAIR(Color::UNTYPED_TEXT));
        print_text(untyped_text_offset + 1, untyped_text.substr(1));
    }
}

void TypeBox::print_text(int offset, const std::string &text) {
    size_t i = 0;
    size_t print_pos = offset;
    while (i < text.size()) {
        size_t chunk_size = std::min((size_t)width - get_col(print_pos), text.size() - i);
        std::string chunk = text.substr(i, chunk_size);

        if (get_row(print_pos) >= 0) {
            mvwprintw(win.get(), get_row(print_pos), get_col(print_pos), "%s", chunk.c_str());
        }

        i += chunk_size;
        print_pos += chunk_size;
    }
}

void TypeBox::print_cursor(int offset) {
    int cursor_row = get_row(offset), cursor_col = get_col(offset);
    if (cursor_row >= 0) {
        mvwchgat(win.get(), cursor_row, cursor_col, 1, A_REVERSE, Color::UNTYPED_TEXT, nullptr);
    }
}

int TypeBox::get_row(int pos) {
    return rows[pos] + row_offset;
}

int TypeBox::get_col(int pos) {
    return cols[pos];
}

void TypeBox::custom_update_rect(int rows, int cols) {
    height = rows - 1;
    width = cols;
    start_y = 0;
    start_x = 0;
}

void TypeBox::set_text(const std::string &typed_text, const std::string &wrong_text, const std::string &untyped_text) {
    this->typed_text = typed_text;
    this->wrong_text = wrong_text;
    this->untyped_text = untyped_text;
    update_text();
}

void TypeBox::update_text() {
    TypeBoxFormatting::format(typed_text, wrong_text, untyped_text, width);
    update_rows_cols();
}

void TypeBox::update_rows_cols() {
    std::string total_text = typed_text + wrong_text + untyped_text;
    rows.resize(total_text.size());
    cols.resize(total_text.size());

    int row = 0, col = 0;
    for (size_t i = 0; i < total_text.size(); i++) {
        rows[i] = row;
        cols[i] = col;
        col++;
        if (col == width || total_text[i] == '\n') {
            col = 0;
            row++;
        }
    }

    update_row_offset();
}

void TypeBox::update_row_offset() {
    int cursor_row = rows[typed_text.length() + wrong_text.length()];
    if (cursor_row >= height/2-1) {
        row_offset = height/2-1 - cursor_row;
    } else {
        row_offset = 0;
    }
}

