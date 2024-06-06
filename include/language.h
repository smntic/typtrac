#ifndef TYPTRAC_LANGUAGE_H
#define TYPTRAC_LANGUAGE_H

#include <string>
#include <vector>

class Language {
public:
    Language();
    ~Language() = default;

    std::string get_word(int index);
    int size() const;

private:
    const std::string DEFAULT_PATH = "/usr/local/share/typtrac/language.txt";

    void load();
    void copy_default();

    std::string language_path;
    std::vector<std::string> words;
};

#endif //TYPTRAC_LANGUAGE_H
