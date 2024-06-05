#include "app_window.h"

void AppWindow::custom_init() {
    type_window = std::make_shared<TypeWindow>();
    add_child(type_window);

    type_window->init();
}

