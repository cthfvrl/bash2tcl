FILES:=lex.yy.c parser.tab.c
FLAGS:=-std=c++17
OUT:=bash2tcl

build:
	flex src/scanner.l 
	bison -d src/parser.y
	g++ -O3 $(FLAGS) $(FILES) -o $(OUT)

debug:
	g++ -g -no-pie $(FLAGS) $(FILES) -o $(OUT)	

test:
	echo test/* | xargs -n 1 ./$(OUT) 

clean:
	rm $(FILES) parser.tab.h
	rm $(OUT)
