cmake_minimum_required(VERSION 3.10)

project(imguiApp)

set(IMGUI_PATH libs/imgui)
file(GLOB IMGUI_SOURCE_FILES ${IMGUI_PATH}/imgui*.cpp)

link_directories(${CMAKE_SOURCE_DIR}/libs/glfw/lib-vc2010-64)
include_directories(${PROJECT_NAME} PRIVATE ${IMGUI_PATH} ${IMGUI_PATH}/backends libs/glfw/include)

add_executable(${PROJECT_NAME} src/main.cpp ${IMGUI_PATH}/backends/imgui_impl_glfw.cpp ${IMGUI_PATH}/backends/imgui_impl_opengl3.cpp ${IMGUI_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} glfw3 opengl32)
