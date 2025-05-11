cmake_minimum_required(VERSION 3.20)
project(sfml3Jurney)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML REQUIRED)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/firstStep/*.cpp)

foreach(FILE ${SOURCES})
    get_filename_component(BINNAME ${FILE} NAME_WE)
    add_executable(${BINNAME} ${FILE})
    target_link_libraries(${BINNAME} PRIVATE sfml-graphics sfml-window sfml-system)
endforeach(FILE)
