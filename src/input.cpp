#include "input.h"

void Input::get_input() {
    int keycode = getch();
    if (keycode == -1) return;

    if (keycode == 127) {
        keycode = KEY_BACKSPACE;
    }

    std::shared_ptr<InputEvent> event = std::make_shared<InputEvent>(keycode);
    handle_input(event);
}

void Input::set_focus_state(std::shared_ptr<FocusState> focus) {
    focus_state = focus;
}

void Input::handle_input(std::shared_ptr<InputEvent> event) {
    focus_state->handle_focus_input(event);
    focus_state->handle_input(event);
}

