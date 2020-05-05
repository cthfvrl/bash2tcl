for file in test/*
do 
    b=`bash $file`
    if ./$1 < $file >& __tmp
    then 
        if t=`tclsh < __tmp 2>__tmperr`
        then
            if [ "$b" == "$t" ]
            then
                echo $file: ok
            else
                echo $file: different output 
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