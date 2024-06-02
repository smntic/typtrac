#ifndef TYPTRAC_TYPE_BOX_H
#define TYPTRAC_TYPE_BOX_H

#include "window.h"
#include <string>

class TypeBox : public Window {
private:
    void custom_render() override;
    void custom_update_rect(int rows, int cols) override;

public:
    void set_text(const std::string &typed_text, const std::string &wrong_text, const std::string &untyped_text);

private:
    const int PADDING = 2;
    std::string typed_text, wrong_text, untyped_text;
};

#endif //TYPTRAC_TYPE_BOX_H
