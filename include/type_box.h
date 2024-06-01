#ifndef TYPTRAC_TYPE_BOX_H
#define TYPTRAC_TYPE_BOX_H

#include "input_event.h"
#include "window.h"
#include <string>

class TypeBox : public Window {
private:
    void custom_init() override;
    void custom_render() override;
    void custom_update_rect(int rows, int cols) override;
    void custom_handle_input(std::shared_ptr<InputEvent> event) override;

public:
    void set_text(const std::string &text);

private:
    const int PADDING = 2;
    std::string text;
};

#endif //TYPTRAC_TYPE_BOX_H
