cmake_minimum_required(VERSION 3.16)

project(libLRC)

# libLRC

add_library(LRC SHARED src/Lyrics.cpp)

target_include_directories(LRC PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#end

# LRC_test

add_executable(LRC_test examples/Main.cpp)

target_include_directories(LRC_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(LRC_test LRC)

#end