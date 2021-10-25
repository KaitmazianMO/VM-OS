cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME Main)
project(${PROJECT_NAME})


find_program(CALNG_FORMAT clang-format)
if(CALNG_FORMAT)
    file(GLOB_RECURSE SOURCES *.cpp *.hpp) #list of all cpp and hpp files
    list(FILTER SOURCES EXCLUDE REGEX "${PROJECT_SOURCE_DIR}/build/" ) #remove cpp and hpp from build
    add_custom_target(
        clangformat
        COMMAND 
        clang-format -style=file -i ${SOURCES}
        )
endif()

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(StackLib)

target_link_libraries(${PROJECT_NAME} Stack)