#include "focus_state.h"
#include <algorithm>
#include <ncurses.h>

FocusState::FocusState()
    : focus_index(0) {}

void FocusState::handle_focus_input(std::shared_ptr<InputEvent> event) {
    if (event->keycode() == '\t') {
        cycle_focus();
        event->consume();
    }
}

void FocusState::handle_input(std::shared_ptr<InputEvent> event) {
    if (focusable_windows.empty()) return;
    focusable_windows[focus_index]->handle_input(event);
}

void FocusState::add_focusable_window(std::shared_ptr<Window> window) {
    focusable_windows.push_back(window);
}

void FocusState::add_focusable_window(std::vector<std::shared_ptr<Window>> window) {
    focusable_windows.insert(focusable_windows.end(), window.begin(), window.end());
}

void FocusState::remove_focusable_window(std::shared_ptr<Window> window) {
    auto window_iterator = std::find(focusable_windows.begin(), focusable_windows.end(), window);
    focusable_windows.erase(window_iterator);
}

void FocusState::cycle_focus() {
    focus_index++;
    if (focus_index >= focusable_windows.size()) {
        focus_index = 0;
    }
}

