cmake_minimum_required(VERSION 3.16)
project(fm)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

file(GLOB_RECURSE src src/*.cpp)

# Linking nana
if (WIN32)
    find_package(unofficial-nana CONFIG REQUIRED)
elseif (UNIX)
    find_package(nana CONFIG REQUIRED)
endif ()
add_executable(fm ${src})
if (WIN32)
    target_link_libraries(fm PRIVATE unofficial::nana::nana)
elseif (UNIX)
    target_link_libraries(fm PRIVATE nana::nana)
endif ()