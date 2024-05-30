cmake_minimum_required(VERSION 3.21)

project(typtrac
    VERSION
        0.1
    DESCRIPTION
        "Typing practice program"
    LANGUAGES
        C
        CXX
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

