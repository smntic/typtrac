set(SOURCES
    main.cpp
    app.cpp
    app_window.cpp
    window.cpp
    type_box.cpp
    input.cpp
    input_event.cpp
    focus_state.cpp
    color.cpp
    type_window.cpp
    type_text.cpp
    type_stats.cpp
    stats_box.cpp
    word_picker.cpp
)

set(INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

add_executable(typtrac ${SOURCES})

target_include_directories(typtrac PRIVATE ${INCLUDE_DIRS})

target_link_libraries(typtrac PRIVATE ncurses)

