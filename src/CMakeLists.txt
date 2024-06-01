set(SOURCES
    main.cpp
    app.cpp
    app_window.cpp
    window.cpp
    type_box.cpp
    input.cpp
    input_event.cpp
    focus_state.cpp
)

set(INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

add_executable(typtrac ${SOURCES})

target_include_directories(typtrac PRIVATE ${INCLUDE_DIRS})

target_link_libraries(typtrac PRIVATE ncurses)

