CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(TEST)

file(GLOB_RECURSE SRC_FILES ./src/*.cpp)

add_executable(output
    ./hw_Farmanov_04.25.2023.cpp
    ${SRC_FILES}
)

target_include_directories(output PUBLIC ./include)

