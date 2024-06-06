#include "app_data.h"
#include <filesystem>
#include <stdexcept>

std::string AppData::path(const std::string &relative_path) {
    std::string data_path;
    if (std::getenv("XDG_DATA_HOME")) {
        data_path = std::string(std::getenv("XDG_DATA_HOME"));
    } else {
        data_path = std::string(std::getenv("HOME")) + "/.local/share";
    }
    std::string file_path = data_path + "/typtrac/" + relative_path;

    ensure_parents(file_path);
    return file_path;
}

bool AppData::exists(const std::string &relative_path) {
    std::string file_path = path(relative_path);
    return std::filesystem::exists(file_path);
}

void AppData::ensure_parents(const std::string &file_path) {
    try {
        std::filesystem::path dir_path = std::filesystem::path(file_path).parent_path();
        std::filesystem::create_directories(dir_path);
    } catch (const std::filesystem::filesystem_error &e) {
        throw std::runtime_error("Failed to create directories: " + std::string(e.what()));
    }
}
