all=0
passed=0
for file in test/*
do 
    all=$((all+1))
    b=`bash $file`
    if ./$1 < $file >& __tmp
    then 
        if t=`tclsh < __tmp 2>__tmperr`
        then
            if [ "$b" == "$t" ]
            then
                echo $file: ok
                passed=$((passed+1))
            else
                echo $file: different output 
                #diff <(echo "$b") <(echo "$t")
            fi
        else
            echo $file: tclsh error
            cat __tmperr
        fi
    else
        echo $file: `cat < __tmp`
    fi
    rm __tmp __tmperr
done
echo Passed $passed tests out of $all