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
    std::string typed_text, wrong_text, untyped_text;

    void update_text();

    void print_texts();
    void print_text(int offset, const std::string &text);
    void print_cursor(int offset);

    void update_rows_cols();
    void update_row_offset();
    int get_row(int pos);
    int get_col(int pos);

    std::vector<int> rows, cols;
    int row_offset = 0;
};

#endif //TYPTRAC_TYPE_BOX_H
