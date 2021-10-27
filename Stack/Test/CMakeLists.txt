enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(PROJECT_NAME unit-tests)
project(${PROJECT_NAME})

add_executable(
    ${PROJECT_NAME}
    main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    Stack
    GTest::Main
)

gtest_discover_tests(unit-tests)

