#include "color.h"
#include <ncurses.h>

void Color::init() {
    start_color();
    init_defaults();
    init_pairs();
}

void Color::init_defaults() {
    use_default_colors();
    assume_default_colors(-1, -1);
}

void Color::init_pairs() {
    init_pair(TYPED_TEXT, COLOR_BLACK, -1);
    init_pair(WRONG_TEXT, COLOR_RED, -1);
    init_pair(UNTYPED_TEXT, -1, -1);
    init_pair(STATS_TEXT, -1, -1);
}

