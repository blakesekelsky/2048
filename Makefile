binary:
	clang++ -stdlib=libc++ src/Game.cpp src/main.cpp -lSDL2 -o bin/main

run: binary
	./bin/main