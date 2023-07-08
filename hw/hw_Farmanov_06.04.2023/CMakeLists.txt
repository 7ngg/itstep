cmake_minimum_required(VERSION 3.0.0)
project(hw_Farmanov_06.04.2023 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(output hw_Farmanov_06.04.2023.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
