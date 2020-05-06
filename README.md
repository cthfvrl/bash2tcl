# bash2tcl
A Bash to Tcl compiler.
## Installation
Run `make` in the `bash2tcl` directory. This will create an executable called `bash2tcl`.
### Dependencies
* g++
* Flex
* Bison
## Usage
Input is read from `stdin`, output is written to `stdout`. For example, to compile the `while.sh` test file and write the generated Tcl code to `while.tcl` execute the following in the `bash2tcl` directory:
```bash
./bash2tcl <test/while.sh >while.tcl
```
Run `make test` to run all tests.
