#include "language.h"
#include "app_data.h"
#include <filesystem>
#include <fstream>

Language::Language() {
    language_path = AppData::path("language.txt");
    if (!AppData::exists("language.txt")) {
        copy_default();
    }
    load();
}

void Language::load() {
    std::ifstream file(language_path);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + language_path);
    }

    words.clear();
    std::string word;
    while (std::getline(file, word)) {
        words.push_back(word);
    }

    file.close();
}

void Language::copy_default() {
    try {
        std::filesystem::copy_file(DEFAULT_PATH, language_path);
    } catch (const std::filesystem::filesystem_error& e) {
        throw std::runtime_error("Failed to copy file: " + std::string(e.what()));
    }
}

std::string Language::get_word(int index) {
    return words[index];
}

int Language::size() const {
    return words.size();
}

