cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME Main)
project (${PROJECT_NAME})

file(GLOB_RECURSE SOURCES *.cpp *.h *.hpp ${PROJECT_SOURCE_DIR}/build/.*)
list(FILTER SOURCES EXCLUDE REGEX "${PROJECT_SOURCE_DIR}/build/" )
add_custom_target(
    clangformat
    COMMAND 
    clang-format -style=file -i ${SOURCES}
    )

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(StackLib)

target_link_libraries(${PROJECT_NAME} Stack)