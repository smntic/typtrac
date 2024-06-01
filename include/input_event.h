#ifndef TYPTRAC_INPUT_EVENT_H
#define TYPTRAC_INPUT_EVENT_H

class InputEvent {
public:
    InputEvent(int keycode);
    ~InputEvent() = default;

    void consume();
    [[nodiscard]] bool consumed() const;
    [[nodiscard]] int keycode() const;

private:
    int m_keycode;
    bool m_consumed;
};

#endif //TYPTRAC_INPUT_EVENT_H
