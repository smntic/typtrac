#include "app_window.h"
#include <string>

void AppWindow::custom_init() {
    type_box = std::make_shared<TypeBox>();
    add_child(type_box);

    type_box->init();
}

void AppWindow::custom_update() {
    // type_box->set_text("This is very cool");
}

void AppWindow::custom_update_rect(int rows, int cols) {
    start_y = start_x = 2;
    height = rows - 4, width = cols - 4;
}

void AppWindow::custom_handle_input(std::shared_ptr<InputEvent> event) {
    // get the character from event.keycode
    std::string text;
    text += event->keycode();
    type_box->set_text(text);
    event->consume();
}

