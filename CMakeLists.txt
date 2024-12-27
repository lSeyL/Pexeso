cmake_minimum_required(VERSION 3.27)
project(Pexeso)

set(CMAKE_CXX_STANDARD 17)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/SFML-2.6.2/lib/cmake/SFML)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
find_package(SFML COMPONENTS system window graphics network main REQUIRED)


add_executable(Pexeso main.cpp
        UI/Window.cpp
        UI/Button.cpp
        UI/HeaderLogo.cpp)
target_link_libraries(Pexeso sfml-system sfml-window sfml-graphics sfml-network sfml-main pthread)
