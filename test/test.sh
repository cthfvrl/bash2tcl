test -f file && cat file
echo what >file 
test -f file && cat file
rm file