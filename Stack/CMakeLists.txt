cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME Main)
project (${PROJECT_NAME})

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(StackLib)

target_link_libraries(${PROJECT_NAME} Stack)