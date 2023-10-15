cmake_minimum_required(VERSION 3.10)
project(app)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_executable(app main.cpp)
target_link_libraries(app sfml-graphics sfml-window sfml-system)
