#Mac OS - run the following command to compile: ./make game

game:
	g++ src/*.cpp -o bin/twodee -I include -L lib -l SDL2-2.0.0