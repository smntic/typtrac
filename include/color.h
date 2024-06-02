#ifndef TYPTRAC_COLOR_H
#define TYPTRAC_COLOR_H

class Color {
public:
    static void init_pairs();

    enum Pair {
        TYPED_TEXT = 1,
        WRONG_TEXT,
        UNTYPED_TEXT,
        STATS_TEXT,
    };
};

#endif //TYPTRAC_COLOR_H
