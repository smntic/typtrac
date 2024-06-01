#ifndef TYPTRAC_APP_H
#define TYPTRAC_APP_H

#include "app_window.h"
#include "input.h"
#include <memory>

class App {
public:
    App();
    ~App() = default;

    void run();
private:
    std::shared_ptr<AppWindow> window;
    std::shared_ptr<FocusState> focus_state;
    std::unique_ptr<Input> input;

    bool running;

    int prev_rows, prev_cols;
};

#endif //TYPTRAC_APP_H
