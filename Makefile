binary:
	clang++ -stdlib=libc++ src/main.cpp -o bin/main

run: binary
	./bin/main