#ifndef TYPTRAC_DATA_H
#define TYPTRAC_DATA_H

#include <string>

class AppData {
public:
    static std::string path(const std::string &relative_path);
    static bool exists(const std::string &relative_path);

private:
    static void ensure_parents(const std::string &file_path);
};

#endif //TYPTRAC_DATA_H
