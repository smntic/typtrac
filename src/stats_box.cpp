#include "stats_box.h"
#include "color.h"

void StatsBox::custom_init() {
    text_format = "WPM: %d CPM: %d Accuracy: %d%%";
}

void StatsBox::custom_update() {
    int size = snprintf(nullptr, 0, text_format.c_str(), wpm, cpm, accuracy) + 1;
    std::unique_ptr<char[]> buf(new char[size]);
    std::snprintf(buf.get(), size, text_format.c_str(), wpm, cpm, accuracy);
    stats_text = std::string(buf.get(), buf.get() + size -1);
}

void StatsBox::custom_render() {
    wattron(win.get(), COLOR_PAIR(Color::STATS_TEXT));
    mvwprintw(win.get(), 0, 0, "%s", stats_text.c_str());

    wclrtoeol(win.get());
}

void StatsBox::custom_update_rect(int rows, int cols) {
    width = cols;
    height = 1;
    start_x = 0;
    start_y = rows - height;
}

void StatsBox::set_stats(double wpm, double cpm, double accuracy) {
    this->wpm = wpm;
    this->cpm = cpm;
    this->accuracy = accuracy * 100.0;
}

