#Mac OS - run the following command to compile: make game

game:
	g++ src/*.cpp -o bin/twodee -I include -L lib -l SDL2-2.0.0

#Compile line for Windows - run 'make gameWin' to compile.
gameWin:
	g++ src/*.cpp -o ./bin/twodee -lmingw32 -lSDL2main -lSDL2 -lSDL2_image