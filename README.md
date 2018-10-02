# twodee
This is a cross platform game engine, written in C++ and using the SDL library.



## Dependancy Installation
So far the only dependancy is SDL2.
### Linux 
```
sudo apt-get install libsdl2-dev
```
-or-
```
sudo pacman -S sdl2
```
### Windows
#### Install Mingw 
http://mingw.org/

(mingw-get-setup.exe)

Select and install the GNU C++ Compiler

Add C:\mingw\bin to PATH

#### SDL for windows (MINGW)
https://www.libsdl.org/release/SDL2-devel-2.0.8-mingw.tar.gz

#### Copy SDL2 include folder (32bit only)
i686-w64-mingw32\include\SDL2 -> C:\MinGW\include\

#### Copy all lib files (32bit only)
i686-w64-mingw32\lib\* -> C:\MinGW\lib

#### Copy dll to ./bin directory (32bit only)
i686-w64-mingw32\bin\SDL2.dll -> <project path>/bin

#### Copy mingw dll to ./bin directory
C:\mingw\binlibstdc++-6.dll -> <project path>/bin
### Compile (linux)
Use the make file located in the project directory
```
./make
```
-or-
```
g++ ./src/*.cpp -o ./bin/twodee -lSDL2
```

### Compile (Windows)
```
g++ ./src/*.cpp -o ./bin/twodee -lmingw32 -lSDL2main -lSDL2
```
