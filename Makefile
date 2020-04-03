FILES:=lex.yy.c parser.tab.c src/*.cpp
FLAGS:=-std=c++17
OUT:=bash2tcl

.PHONY: test

all: build

build:
	flex src/scanner.l 
	bison -d src/parser.y
	g++ -O3 $(FLAGS) $(FILES) -o $(OUT)

debug:
	flex -d src/scanner.l 
	bison -dtv src/parser.y
	g++ -O3 $(FLAGS) $(FILES) -o $(OUT)	

test:
	for file in test/*; do echo $$file; ./$(OUT) < $$file; done

clean:
	rm lex.yy.c parser.tab.c parser.tab.h parser.output
	rm $(OUT)
