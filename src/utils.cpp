#include "utils.h"
#include <chrono>

double Utils::get_seconds() {
    auto now = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(now.time_since_epoch()).count();
}

