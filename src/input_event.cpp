#include "input_event.h"

#include "window.h"

InputEvent::InputEvent(int keycode)
    : m_keycode(keycode), m_consumed(false) {}

void InputEvent::consume() {
    m_consumed = true;
}

bool InputEvent::consumed() const  {
    return m_consumed;
}

int InputEvent::keycode() const {
    return m_keycode;
}

