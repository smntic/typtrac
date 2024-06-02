#include "type_box.h"
#include "color.h"

void TypeBox::custom_render() {
    int wrong_text_offset = (int)typed_text.length();
    int untyped_text_offset = wrong_text_offset + (int)wrong_text.length();

    wattron(win.get(), COLOR_PAIR(Color::TYPED_TEXT));
    mvwprintw(win.get(), 0, 0, "%s", typed_text.c_str());
    wattron(win.get(), COLOR_PAIR(Color::WRONG_TEXT));
    mvwprintw(win.get(), 0, wrong_text_offset, "%s", wrong_text.c_str());
    wattron(win.get(), COLOR_PAIR(Color::UNTYPED_TEXT));
    mvwprintw(win.get(), 0, untyped_text_offset, "%s", untyped_text.c_str());
}

void TypeBox::custom_update_rect(int rows, int cols) {
    this->height = rows;
    this->width = cols - 2 * PADDING;
    this->start_y = 0;
    this->start_x = PADDING;
}

void TypeBox::set_text(const std::string &typed_text, const std::string &wrong_text, const std::string &untyped_text) {
    this->typed_text = typed_text;
    this->wrong_text = wrong_text;
    this->untyped_text = untyped_text;
}
