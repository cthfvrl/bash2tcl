FILES:=src/main.cpp
FLAGS:=-std=c++17

build:
	g++ -O3 $(FLAGS) $(FILES) -o run

debug:
	g++ -g -no-pie $(FLAGS) $(FILES) -o run	

test:
	echo test/* | xargs -n 1 ./run 

build_and_test: build test