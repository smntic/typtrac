#include "type_box.h"

void TypeBox::custom_render() {
    mvwprintw(win.get(), 0, 0, "%s", text.c_str());
}

void TypeBox::custom_update_rect(int rows, int cols) {
    this->height = rows;
    this->width = cols - 2 * PADDING;
    this->start_y = 0;
    this->start_x = PADDING;
}

void TypeBox::set_text(const std::string &text) {
    this->text = text;
}

