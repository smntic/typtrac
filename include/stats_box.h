#ifndef TYPTRAC_STATS_BOX_H
#define TYPTRAC_STATS_BOX_H

#include "window.h"
#include <string>

class StatsBox : public Window {
private:
    void custom_init() override;
    void custom_update() override;
    void custom_render() override;
    void custom_update_rect(int rows, int cols) override;

public:
    void set_stats(double wpm, double cpm, double accuracy);

private:
    int wpm, cpm, accuracy;
    std::string text_format;
    std::string stats_text;
};

#endif //TYPTRAC_STATS_BOX_H
