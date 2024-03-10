cmake_minimum_required(VERSION 3.10)
project(example LANGUAGES C)

set(SDL2_PATH "${CMAKE_SOURCE_DIR}/3rdparty/SDL2")

add_subdirectory(3rdparty/SDL2)

include_directories(${SDL2_PATH}/include)
set(SOURCE_FILES src/main.c)

add_executable(main ${SOURCE_FILES})

target_link_libraries(main PRIVATE SDL2::SDL2main  SDL2::SDL2)

add_custom_command(TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL2>
        $<TARGET_FILE_DIR:main>
)
