set(SOURCES
    main.cpp
)

set(INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

add_executable(typtrac ${SOURCES})

target_include_directories(typtrac PRIVATE ${INCLUDE_DIRS})

target_link_libraries(typtrac PRIVATE ncurses)

