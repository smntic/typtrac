#ifndef TYPTRAC_TYPE_WINDOW_H
#define TYPTRAC_TYPE_WINDOW_H

#include "window.h"
#include "type_box.h"
#include "type_text.h"

class TypeWindow : public Window {
private:
    void custom_init() override;
    void custom_update() override;
    void custom_handle_input(std::shared_ptr<InputEvent> event) override;

    std::shared_ptr<TypeBox> type_box;
    std::shared_ptr<TypeText> type_text;
    // std::shared_ptr<StatsBox> stats_box; // TODO: stats box
    // std::shared_ptr<TypeStats> type_stats;

    void type_char(char ch);
    void delete_char();
};

#endif //TYPTRAC_TYPE_WINDOW_H
