# sudo apt-get install mingw-w64 ## for : x86_64-w64-mingw32-gcc

x86_64-w64-mingw32-gcc ../*.c -Ix86_64-w64-mingw32/include -Lx86_64-w64-mingw32/lib -lSDL2 -o sdl-app.exe 
