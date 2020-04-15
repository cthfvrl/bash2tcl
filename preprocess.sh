echo '#include "lex.yy.c"' > incl.cpp
echo '#include "parser.tab.c"' >> incl.cpp
for file in `ls src | grep '.*cpp'`; do echo "#include \"src/$file\"" >> incl.cpp; done
