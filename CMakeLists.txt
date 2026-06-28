# cmake -S . -B build && cmake --build build && build/app

# Visual Studio Code IDE extension for CMake
# https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools

cmake_minimum_required(VERSION 3.20)
project( app VERSION 0.1 LANGUAGES C )

# Require C99 (for-loop scoped variables, // comments, mixed declarations)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB SOURCE_FILES "*.c*" )
add_executable(app ${SOURCE_FILES})

find_package( SDL2 REQUIRED )
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

### find_package( OpenGL REQUIRED )
### target_link_libraries(${PROJECT_NAME} OpenGL::GL OpenGL::GLU)

# link with libm (math library), needed e.g. in GNU/Linux setting
target_link_libraries(${PROJECT_NAME} m)
