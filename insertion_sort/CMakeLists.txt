cmake_minimum_required(VERSION 3.14)

project(insertion_sort)

set(SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
