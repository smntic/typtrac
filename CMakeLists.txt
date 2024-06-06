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

set(CMAKE_INSTALL_PREFIX /usr/local)

set(BIN_DIR bin)
set(DATA_DIR share/typtrac)

install(TARGETS typtrac DESTINATION ${BIN_DIR})
install(FILES assets/language.txt DESTINATION ${DATA_DIR})

