cmake_minimum_required(VERSION 3.19)
project(fm)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB_RECURSE src src/*.cpp)

# Linking nana
find_package(unofficial-nana CONFIG REQUIRED)

add_executable(fm ${src})
target_link_libraries(fm PRIVATE unofficial::nana::nana)