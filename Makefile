dev_binary:
	mkdir -p bin
	clang++ -stdlib=libc++ src/Board.cpp src/Game.cpp src/main.cpp -lSDL2 -lSDL2_ttf -o bin/main

run_dev: dev_binary
	./bin/main

cmake:
	mkdir -p build/assets
	cd build && cp ../assets/MouldyCheeseRegular.ttf assets/ && cmake .. && make

run: cmake
	./build/2048