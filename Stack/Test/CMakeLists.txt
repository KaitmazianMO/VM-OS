cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME unit_test)
project(${PROJECT_NAME})

include(GoogleTest)

add_compile_options(-Wall -Wextra -pedantic -Werror -O0)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} Stack GTest::GTest GTest::Main)