#ifndef TYPTRAC_APP_H
#define TYPTRAC_APP_H

#include "app_window.h"
#include <memory>

class App {
public:
    App();
    ~App() = default;

    void run();
private:
    std::unique_ptr<AppWindow> window;
    bool running;
};

#endif //TYPTRAC_APP_H
