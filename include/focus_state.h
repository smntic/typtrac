#ifndef TYPTRAC_FOCUS_STATE_H
#define TYPTRAC_FOCUS_STATE_H

#include "window.h"
#include <vector>

class FocusState {
public:
    FocusState();
    ~FocusState() = default;

    void handle_focus_input(std::shared_ptr<InputEvent> event);
    void handle_input(std::shared_ptr<InputEvent> event);

    void add_focusable_window(std::shared_ptr<Window> window);
    void add_focusable_window(std::vector<std::shared_ptr<Window>> window);
    void remove_focusable_window(std::shared_ptr<Window> window);

private:
    std::vector<std::shared_ptr<Window>> focusable_windows;
    size_t focus_index;

    void cycle_focus();
};

#endif //TYPTRAC_FOCUS_STATE_H
