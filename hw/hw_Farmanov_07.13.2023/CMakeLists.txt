cmake_minimum_required(VERSION 3.0.0)
project(hw_Farmanov_07.13.2023 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${INC_DIR})

set(SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/hw_Farmanov_07.13.2023.cpp
)

add_executable(main hw_Farmanov_07.13.2023.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
