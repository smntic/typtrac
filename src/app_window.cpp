#include "app_window.h"

void AppWindow::custom_init() {
    type_window = std::make_shared<TypeWindow>();
    add_child(type_window);

    type_window->init();
}

void AppWindow::custom_update_rect(int rows, int cols) {
    start_y = start_x = 2;
    height = rows - 4, width = cols - 4;
}

