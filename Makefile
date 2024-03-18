binary:
	clang++ -stdlib=libc++ src/Board.cpp src/Game.cpp src/main.cpp -lSDL2 -lSDL2_ttf -o bin/main

run: binary
	./bin/main