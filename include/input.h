#ifndef TYPTRAC_INPUT_H
#define TYPTRAC_INPUT_H

#include "focus_state.h"
#include "input_event.h"
#include <memory>

class Input {
public:
    Input() = default;
    ~Input() = default;

    void get_input();
    void set_focus_state(std::shared_ptr<FocusState> focus);

private:
    void handle_input(std::shared_ptr<InputEvent> event);

    std::shared_ptr<FocusState> focus_state;
};

#endif //TYPTRAC_INPUT_H
