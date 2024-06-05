#ifndef TYPTRAC_COLOR_H
#define TYPTRAC_COLOR_H

class Color {
public:
    static void init();

    enum Pair {
        TYPED_TEXT = 1,
        WRONG_TEXT,
        CURRENT_TEXT,
        UNTYPED_TEXT,
        STATS_TEXT,
    };

private:
    static void init_defaults();
    static void init_pairs();
};

#endif //TYPTRAC_COLOR_H
