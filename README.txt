# SDL2
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

/cb-linux
CodeBlocksIDE files to be used in Linux to produce Linux apps (notably with support for libSDL2)

/cb-mswindows
CodeBlocksIDE files to be used in Microsoft Windows to produce Microsoft Windows apps (notably with support for libSDL2)

/mingw-linux
Shell scripts to be used in Linux to produce Microsoft Windows apps, via MinGW (notably with support for libSDL2)

/sh-linux
Shell scripts to be used in Linux to produce Linux apps, via GCC (notably with support for libSDL2)

/sh-mswindows
Shell scripts to be used in Microsoft Windows to produce Microsoft Windows apps, via GCC/MinGW/MSYS (notably with support for libSDL2)
