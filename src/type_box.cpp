#include "type_box.h"
#include "color.h"

void TypeBox::custom_render() {
    int wrong_text_offset = (int)typed_text.length();
    int untyped_text_offset = wrong_text_offset + (int)wrong_text.length();

    wattron(win.get(), COLOR_PAIR(Color::TYPED_TEXT));
    print_text(0, typed_text);
    wattron(win.get(), COLOR_PAIR(Color::WRONG_TEXT));
    print_text(wrong_text_offset, wrong_text);
    wattron(win.get(), COLOR_PAIR(Color::UNTYPED_TEXT));
    print_text(untyped_text_offset, untyped_text);

    printf("%d\n", (int)typed_text.length());
}

void TypeBox::print_text(int offset, const std::string &text) {
    const int CHUNK_SIZE = 512; // INFO: mvwprintw can print 512 bytes at a time
    int chunk_offset = 0;
    for (size_t i = 0; i < text.size(); i += CHUNK_SIZE) {
        std::string chunk = text.substr(i, CHUNK_SIZE);
        int pos = offset + chunk_offset;
        mvwprintw(win.get(), get_row(pos), get_col(pos), "%s", chunk.c_str());
        chunk_offset += CHUNK_SIZE;
    }
}

void TypeBox::set_text(const std::string &typed_text, const std::string &wrong_text, const std::string &untyped_text) {
    this->typed_text = typed_text;
    this->wrong_text = wrong_text;
    this->untyped_text = untyped_text;
}

int TypeBox::get_row(int pos) {
    return pos / width;
}

int TypeBox::get_col(int pos) {
    return pos % width;
}

