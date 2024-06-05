#include "terminal.h"
#include <ncurses.h>

void Terminal::init() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, true);
}
