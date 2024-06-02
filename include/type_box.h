#ifndef TYPTRAC_TYPE_BOX_H
#define TYPTRAC_TYPE_BOX_H

#include "window.h"
#include <string>

class TypeBox : public Window {
private:
    void custom_render() override;

public:
    void print_text(int offset, const std::string &text);
    void set_text(const std::string &typed_text, const std::string &wrong_text, const std::string &untyped_text);

private:
    std::string typed_text, wrong_text, untyped_text;

    int get_row(int pos);
    int get_col(int pos);
};

#endif //TYPTRAC_TYPE_BOX_H
