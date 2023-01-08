Compiler
=========

GRAMMAR
--------

* statement_list -> statement . statement_list*
* statement -> expression . semicolon
* expression -> operand . operator . operand
* operand -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 
* operator -> + | - | * | /

Compile the compiler code to get the mini-compiler
---------------------------------------------------

* Run make command
    make

- This will give the executable compiler "minicomp"

Compile a sample program
-------------------------

* Generate executable for sample program "example.mini"

    - Below command will give assembly program "example_mini.s" of the sample program "example.mini" of mini language 
        
        cat template_start.s <(cat example.mini | ./minicomp) template_end.s > example_mini.s

    - Compile the assembly program and generate mini language program executable "example_mini"

        gcc -o example_mini example_mini.s

    - Run the mini language executable

        ./example_mini