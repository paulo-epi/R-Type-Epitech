project(RTYPE)
cmake_minimum_required(VERSION 3.17)
add_definitions("-std=c++17")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)

# include(FetchContent)
# FetchContent_Declare(SFML
#     GIT_REPOSITORY https://github.com/SFML/SFML.git
#     GIT_TAG 2.6.x)
# FetchContent_MakeAvailable(SFML)

add_subdirectory(client)
add_subdirectory(server)