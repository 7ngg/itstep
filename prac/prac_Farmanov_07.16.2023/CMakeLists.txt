cmake_minimum_required(VERSION 3.25)
project(OOP)

set(CMAKE_CXX_STANDARD 23)

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${INC_DIR})

set(SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/prac_Farmanov_07.16.2023.cpp
)

add_executable(main ${SRC_FILES})

target_include_directories(main PRIVATE ${INC_DIR})