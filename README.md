# bash2tcl
A Bash to Tcl compiler.
## Installation
Run `make` in the `bash2tcl` directory.  
### Dependencies
* g++
* Flex
* Bison
## Usage
Input is read from `stdin`, output is written to `stdout`. For example, to compile the `while.sh` test in the `bash2tcl` directory execute:
```bash
./bash2tcl <test/while.sh
```
Run `make test` to run all tests.
