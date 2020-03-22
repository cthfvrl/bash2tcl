FILES:=lex.yy.c parser.tab.c
FLAGS:=-std=c++17
OUT:=bash2tcl

.PHONY: test

all: build

build:
	flex src/scanner.l 
	bison -d src/parser.y
	g++ -O3 $(FLAGS) $(FILES) -o $(OUT)

debug:
	flex src/scanner.l 
	bison -d src/parser.y
	g++ -g -no-pie $(FLAGS) $(FILES) -o $(OUT)	

test:
	echo test/* | xargs -n 1 ./$(OUT) 

clean:
	rm $(FILES) parser.tab.h
	rm $(OUT)
