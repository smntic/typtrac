#include "window.h"
#include <algorithm>

void Window::init(WINDOW *parent) {
    set_defaults();
    create_window(parent);
    custom_init();
}

void Window::set_defaults() {
    focusable = false;
    height = width = start_y = start_x = origin_y = origin_x = 0;
}

void Window::create_window(WINDOW *parent) {
    if (parent) {
        win = std::unique_ptr<WINDOW, WinDelete>(subwin(parent, height, width, start_y, start_x));
    } else {
        win = std::unique_ptr<WINDOW, WinDelete>(newwin(height, width, start_y, start_x));
    }
}

void Window::clear() {
    wclear(win.get());
    for (auto &child : children) {
        child->clear();
    }
    custom_clear();
}

void Window::update() {
    for (auto &child : children) {
        child->update();
    }
    custom_update();
}

void Window::render() {
    for (auto &child : children) {
        child->render();
    }
    // box(win.get(), '*', '*'); // for debugging purposes
    custom_render();
}

void Window::refresh() {
    wrefresh(win.get());
    for (auto &child : children) {
        child->refresh();
    }
    custom_refresh();
}

void Window::update_rect(int rows, int cols) {
    custom_update_rect(rows, cols);
    wresize(win.get(), height, width);
    mvwin(win.get(), origin_y + start_y, origin_x + start_x);
    for (auto &child : children) {
        child->update_origin(origin_y + start_y, origin_x + start_x);
        child->update_rect(height, width);
    }
}

void Window::custom_update_rect(int rows, int cols) {
    height = rows;
    width = cols;
}

void Window::update_origin(int y, int x) {
    origin_y = y, origin_x = x;
}

void Window::add_child(std::shared_ptr<Window> child) {
    children.push_back(child);
    child->set_parent(std::shared_ptr<Window>(this));
}

void Window::remove_child(std::shared_ptr<Window> child) {
    auto child_iterator = std::find(children.begin(), children.end(), child);
    children.erase(child_iterator);
    child->remove_parent();
}

void Window::set_parent(std::shared_ptr<Window> parent) {
    this->parent = parent;
}

void Window::remove_parent() {
    set_parent(nullptr);
}

void Window::handle_input(std::shared_ptr<InputEvent> event) {
    // the custom handler can consume the event
    custom_handle_input(event);

    // otherwise the event propagates up the hierarchy
    if (!event->consumed() && parent) {
        parent->handle_input(event);
    }
}

std::vector<std::shared_ptr<Window>> Window::get_focusable_windows() {
    std::vector<std::shared_ptr<Window>> focusable_windows;
    get_focusable_windows(focusable_windows);
    return focusable_windows;
}

void Window::get_focusable_windows(std::vector<std::shared_ptr<Window>> &focusable_windows) {
    if (focusable) {
        focusable_windows.push_back(std::shared_ptr<Window>(this));
    }

    for (auto &child : children) {
        child->get_focusable_windows(focusable_windows);
    }
}

