# Native side of the Android APK build. SDL2 source is placed in SDL/ by
# android/setup-sdl.sh (not tracked in git). The game library must be named
# "main": SDLActivity.getLibraries() loads {"SDL2", "main"}.
cmake_minimum_required(VERSION 3.20)
project(mazegame C)

add_subdirectory(SDL)

add_library(main SHARED ${CMAKE_CURRENT_SOURCE_DIR}/../../../main-sdl.c)
# APP_ANDROID_APK enables the APK-only paths in main-sdl.c (SDL_main include,
# AssetManager-relative asset paths, immersive fullscreen). See the comment in
# main-sdl.c for why this is a dedicated macro and not __ANDROID__.
target_compile_definitions(main PRIVATE APP_ANDROID_APK)
target_link_libraries(main SDL2 m)
