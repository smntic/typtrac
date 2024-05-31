#include "app.h"
#include <ncurses.h>

App::App() {
    initscr();
    cbreak();
    noecho();

    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    window = std::make_unique<AppWindow>();
    window->init();
}

void App::run() {
    running = true;
    while (running) {
        int rows, cols;
        getmaxyx(stdscr, rows, cols);

        window->clear();
        window->update();
        window->update_rect(rows, cols);
        window->render();
        refresh();
        window->refresh();
        getch(); // this is here for now, but will be in an input class later
    }

    endwin();
}
