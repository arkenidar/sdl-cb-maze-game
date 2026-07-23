# SDL2 software library, Simple Direct-Media Layer: foundation layer for graphical apps, portable also across various computer systems.

Cross-platform "SDL2" C API. GNU GCC &amp; GNU Makefile for Windows also. VSCode files for Task (compile with Make) and Debug (GDB debugger in VSCode, e.g. breakpoints are considered).

## marketplace.visualstudio.com

C/C++ for Visual Studio Code: <br>
https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools

Make support and task provider: Extension to run Makefile tasks from VS Code <br>
https://marketplace.visualstudio.com/items?itemName=carlos-algms.make-task-provider

## MSYS with MinGW (Windows)

- install MSYS to `C:\msys64` https://www.msys2.org/#installation
- update pacman package manager `pacman -Syu`
- install package gcc compiler: `pacman -S mingw-w64-x86_64-toolchain`
- install package gdb debugger: `pacman -S mingw-w64-x86_64-gdb`
- install package make build: `pacman -S mingw-w64-x86_64-make`
- add to System \ Advanced settings \ Environment Variables \ PATH
    * `C:\msys64\mingw64\bin`
    * `C:\msys64\usr\bin`

## Needed Libraries for MSYS with MinGW (Windows) 

- install package SDL2 library: `pacman -S mingw-w64-x86_64-SDL2`

***

# sdl-cb
mainly tests for "codeblocks.org" IDE projects (C language use of libSDL2 API, as an example is provided)

- /cb-linux
CodeBlocksIDE files to be used in Linux to produce Linux apps (notably with support for libSDL2)

- /cb-mswindows
CodeBlocksIDE files to be used in Microsoft Windows to produce Microsoft Windows apps (notably with support for libSDL2)

- /mingw-linux
Shell scripts to be used in Linux to produce Microsoft Windows apps, via MinGW (notably with support for libSDL2)

- /sh-linux
Shell scripts to be used in Linux to produce Linux apps, via GCC (notably with support for libSDL2)

- /sh-mswindows
Shell scripts to be used in Microsoft Windows to produce Microsoft Windows apps, via GCC/MinGW/MSYS (notably with support for libSDL2)

***

# Android notes (Termux, CXXDroid, APK)

Building in **Termux** or **CXXDroid** works with the normal commands (e.g. `cc *.c $(sdl2-config --cflags --libs)`): those produce ordinary executables, even though their clang defines `__ANDROID__`.

Android-APK-only code in `main-sdl.c` (loading assets through SDL RWops from the APK, immersive fullscreen) is gated on the macro `APP_ANDROID_APK`, **not** on `__ANDROID__` — Termux/CXXDroid also define `__ANDROID__` but their SDL2 has no Android JNI glue, so APK-only SDL calls would fail to link there. No build in this repository defines `APP_ANDROID_APK`; a future Android APK project must compile this source with `-DAPP_ANDROID_APK` (e.g. `target_compile_definitions(... APP_ANDROID_APK)` in its CMakeLists) to enable those paths.
