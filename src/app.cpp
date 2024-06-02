#include "app.h"
#include "color.h"
#include <ncurses.h>

App::App() {
    // TODO: this as well (see below)
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, true);

    // TODO: separate this into a function
    start_color();
    use_default_colors(); // https://stackoverflow.com/questions/2403399/ncurses-transparent-console-background
    assume_default_colors(-1, -1);
    Color::init_pairs();

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

        // TODO: clear on SIGWINCH
        // window->clear();
        window->update();

        if (rows != prev_rows || cols != prev_cols) {
            prev_rows = rows;
            prev_cols = cols;
            window->update_rect(rows, cols);
        }

        window->render();
        refresh();
        window->refresh();
        input->get_input();
    }

    endwin();
}
