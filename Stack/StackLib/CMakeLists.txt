cmake_minimum_required(VERSION 3.16)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_library(
    Stack SHARED
    Stack.h
    Stack.cpp
    Stack_impl.hpp
)
