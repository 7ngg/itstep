cmake_minimum_required(VERSION 3.1)

set(project_name "BinnaryTree")
project(${project_name})

add_compile_options(-std=c++20)

add_executable(${project_name}
    ./main.cpp,
)

