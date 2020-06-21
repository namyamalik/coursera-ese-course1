## Author: Namya Malik  
## ECE Specialization, Course 1  
## June 2020
______________________________________________

### General
This is my submission for the weekly asssignments for the *Introduction to Embedded Systems Software and Development* course on Coursera. This course is the first course in the *Embedded Software Essentials Specialization* series.
______________________________________________

### Week 1

#### Contents
* `stats.c`: contains several functions to perform on an array (finding statistics, sorting, printing)
* `stats.h`: corresponding header file

#### Compile
`gcc stats.c`  

This produces an exectuable (`a.out`)

#### Run
`./a.out`
______________________________________________

### WEEK 2

#### Contents

#### Compile
`make build PLATFORM=HOST` for host platform target
or
`make build PLATFORM=MSP432` for MSP432 platform target
Either compilation will produce an executable named `c1m2.out`.

Note that upon completion of a build, there is also a build report of code size (using the size tool) that is outputted.

#### Run
`./c1m2.out`

The host code can run natively on your system and should output a string "aXy72_L+R". The cortex build will not be able to run natively, since it is meant to run on a separate target. If the cortex build exectuable is run, it will produce an error: "cannot execute binary file: Exec format error".

### Miscellaneous
* Ensure that the `arm-none-eabi` cross-compiler toolchain is installed and matches the location specified in Makefile
* Run `make clean` before a new build to avoid errors or corrupt .o files
