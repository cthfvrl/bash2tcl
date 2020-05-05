FILES:=incl.cpp
FLAGS:=-std=c++17
OUT:=bash2tcl

.PHONY: test

all: build

build:
	flex src/scanner.l 
	bison -d src/parser.y
	bash preprocess.sh
	g++ $(FLAGS) $(FILES) -o $(OUT)
	rm incl.cpp

debug:
	flex -d src/scanner.l 
	bison -dtv src/parser.y
	bash preprocess.sh
	g++ -g -no-pie $(FLAGS) $(FILES) -o $(OUT)	
	rm incl.cpp

test:
	bash run_all_tests.sh $(OUT)

clean:
	rm lex.yy.c parser.tab.c parser.tab.h parser.output
	rm $(OUT)
