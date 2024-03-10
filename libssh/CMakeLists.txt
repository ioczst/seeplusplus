cmake_minimum_required(VERSION 3.10)

project(demo)

file (GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

find_package(libssh CONFIG REQUIRED)

add_executable(demo ${SOURCE_FILES})
target_link_libraries(demo PRIVATE ssh)