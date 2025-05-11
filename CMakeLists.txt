cmake_minimum_required(VERSION 3.31)
project(sfml3Jurney)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)

#add_executable(${PROJECT_NAME} src/bar.cpp)
#target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Network SFML::Graphics SFML::Window SFML::Audio SFML::System)
# include_directories(${SFML_INCLUDE_DIR})

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

foreach(FILE ${SOURCES})
    get_filename_component(BINNAME ${FILE} NAME_WE)
    add_executable(${BINNAME} ${FILE})
    target_link_libraries(${BINNAME} PRIVATE SFML::Network SFML::Graphics SFML::Window SFML::Audio SFML::System)
endforeach(FILE)
