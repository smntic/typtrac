#include "app.h"
#include "terminal.h"
#include "color.h"
#include <ncurses.h>

App::App() {
    Terminal::init();
    Color::init();

    window = std::make_unique<AppWindow>();
    window->init();

    focus_state = std::make_shared<FocusState>();
    focus_state->add_focusable_window(window->get_focusable_windows());

    input = std::make_unique<Input>();
    input->set_focus_state(focus_state);
}

void App::run() {
    running = true;
    while (running) {
        int rows, cols;
        getmaxyx(stdscr, rows, cols);

        if (rows != prev_rows || cols != prev_cols) {
            prev_rows = rows;
            prev_cols = cols;
            window->update_rect(rows, cols);
        }

        window->update();

        window->render();
        window->refresh();

        input->get_input();
    }

    endwin();
}
