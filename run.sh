./bash2tcl <test/$1.sh >$1.tcl
echo '---Bash:---'
bash test/$1.sh
echo '---Tcl :---'
tclsh $1.tcl