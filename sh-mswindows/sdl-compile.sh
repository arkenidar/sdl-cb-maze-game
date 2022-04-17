# https://www.msys2.org
# https://www.msys2.org/#installation
# https://www.mingw-w64.org/ for GCC and shell (this is a shell script)

gcc ../*.c -mwindows -Ix86_64-w64-mingw32/include -Lx86_64-w64-mingw32/lib -lSDL2 -o sdl-app.exe 
