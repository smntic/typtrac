#ifndef TYPTRAC_APP_WINDOW_H
#define TYPTRAC_APP_WINDOW_H

#include "window.h"
#include "type_window.h"

class AppWindow : public Window {
private:
    void custom_init() override;

    std::shared_ptr<TypeWindow> type_window;
};


#endif //TYPTRAC_APP_WINDOW_H
