#ifndef TYPTRAC_WINDOW_H
#define TYPTRAC_WINDOW_H

#include "input_event.h"
#include <ncurses.h>
#include <memory>
#include <vector>

class Window {
public:
    Window() = default;
    ~Window() = default;

    void init(WINDOW *parent = nullptr); // is this really the only way?

    void clear();
    void update();
    void render();
    void refresh();

    void update_rect(int rows, int cols);
    void update_origin(int y, int x);

    void add_child(std::shared_ptr<Window> child);
    void remove_child(std::shared_ptr<Window> child);

    void set_parent(std::shared_ptr<Window> parent);
    void remove_parent();

    void handle_input(std::shared_ptr<InputEvent> event);

    std::vector<std::shared_ptr<Window>> get_focusable_windows();

private:
    struct WinDelete {
        void operator()(WINDOW* win) const {
            delwin(win);
        }
    };
    
    std::vector<std::shared_ptr<Window>> children;
    std::shared_ptr<Window> parent;
    int origin_y, origin_x;

    void set_defaults();

    void create_window(WINDOW *parent);

    virtual void custom_init() {};

    virtual void custom_clear() {};
    virtual void custom_update() {};
    virtual void custom_render() {};
    virtual void custom_refresh() {};

    virtual void custom_update_rect(int rows, int cols);

    virtual void custom_handle_input(std::shared_ptr<InputEvent> event) {};

    void get_focusable_windows(std::vector<std::shared_ptr<Window>> &focusable_windows);

protected:
    std::unique_ptr<WINDOW, WinDelete> win;
    int height, width, start_y, start_x;
    bool focusable;
};

#endif //TYPTRAC_WINDOW_H
