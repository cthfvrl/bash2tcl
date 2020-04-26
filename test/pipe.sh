echo abc | grep a
echo de | grep a
for val in aaa bbb; do
    if echo $val | grep a; then echo yes; else echo no; fi
done