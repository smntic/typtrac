#ifndef TYPTRAC_APP_WINDOW_H
#define TYPTRAC_APP_WINDOW_H

#include "window.h"
#include "type_box.h"

class AppWindow : public Window {
private:
    void custom_init() override;
    void custom_update() override;
    void custom_update_rect(int rows, int cols) override;

    std::shared_ptr<TypeBox> type_box;
};


#endif //TYPTRAC_APP_WINDOW_H
