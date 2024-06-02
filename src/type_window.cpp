#include "type_window.h"

void TypeWindow::custom_init() {
    focusable = true;

    type_box = std::make_shared<TypeBox>();
    add_child(type_box);

    type_box->init();

    type_text = std::make_shared<TypeText>();
    type_text->set_text("this is a test of the cool thing i just made");
}

void TypeWindow::custom_update() {
    std::string typed_text = type_text->get_typed();
    std::string wrong_text = type_text->get_wrong();
    std::string untyped_text = type_text->get_untyped();
    type_box->set_text(typed_text, wrong_text, untyped_text);

    // int wpm = type_stats->get_wpm();
    // int cpm = type_stats->get_cpm();
    // int accuracy = type_stats->get_accuracy();
    // stats_box->set_stats(wpm, cpm, accuracy);
}

void TypeWindow::custom_handle_input(std::shared_ptr<InputEvent> event) {
    if (event->keycode() == KEY_BACKSPACE) {
        delete_char();
    } else {
        type_char((char)event->keycode());
    }
}

void TypeWindow::type_char(char ch) {
    type_text->type_char(ch);
}

void TypeWindow::delete_char() {
    type_text->delete_char();
}

