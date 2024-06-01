#include "type_box.h"

void TypeBox::custom_init() {
    focusable = true;
}

void TypeBox::custom_render() {
    mvwprintw(win.get(), 0, 0, "%s", text.c_str());
}

void TypeBox::custom_update_rect(int rows, int cols) {
    this->height = rows;
    this->width = cols - 2 * PADDING;
    this->start_y = 0;
    this->start_x = PADDING;
}

void TypeBox::custom_handle_input(std::shared_ptr<InputEvent> event) {
    // if (event.type == InputEventType::CHARACTER) {
    //     text += event.character;
    // } else if (event.type == InputEventType::KEY) {
    //     if (event.key == Key::BACKSPACE) {
    //         if (!text.empty()) {
    //             text.pop_back();
    //         }
    //     }
    // }
}

void TypeBox::set_text(const std::string &text) {
    this->text = text;
}

