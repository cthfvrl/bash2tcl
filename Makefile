FILES:=src/*.cpp
INCLUDE:=include
FLAGS:=-std=c++17
OUT:=bash2tcl

build:
	flex -o src/scanner.cpp src/scanner.l
	bison -o src/parser.cpp src/parser.y
	g++ -O3 $(FLAGS) $(FILES) -I$(INCLUDE) -o $(OUT)

debug:
	g++ -g -no-pie $(FLAGS) $(FILES) -o $(OUT)	

test:
	echo test/* | xargs -n 1 ./$(OUT) 

clean:
	rm -rf scanner.cpp
	rm -rf parser.cpp parser.hpp location.hh position.hh stack.hh
	rm -rf $(OUT)
