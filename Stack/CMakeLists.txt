cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME TheStack)
project(${PROJECT_NAME})

find_program(CLANG_FORMAT clang-format)
if(CLANG_FORMAT)
    file(GLOB_RECURSE SOURCES *.cpp *.hpp) #list of all cpp and hpp files
    list(FILTER SOURCES EXCLUDE REGEX "${PROJECT_SOURCE_DIR}/build/" ) #remove cpp and hpp from build
    add_custom_target(
        clangformat
        COMMAND 
        clang-format -style=file -i ${SOURCES}
        )
endif()

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_subdirectory(Test)