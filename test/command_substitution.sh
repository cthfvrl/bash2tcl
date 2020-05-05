echo "Hello, world!" >hello.txt
A=`cat hello.txt`
echo $A
B=`for i in 1 2 3; do echo $i $i; done`
echo $B
if ((0)); then a=`echo kek`; fi