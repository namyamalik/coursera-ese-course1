## Author: Namya Malik  
## June 2020

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
* `msp432p401r.lds`: linker file used for linking
* `src` folder: contains five source files (.c)
	* `Makefile`
	* `sources.mk`
	* `main.c`
	* `memory.c`
	* `interrupts_msp432p401r_gcc.c`: MSP432 specific C-file for interrupts
	* `startup_msp432p401r_gcc.c`: MSP432 specific C-file for startup
	* `system_msp432p401r.c`: MSP432 specific C-file for for system information
* `include` folder: contains the three directories of supporting header files
	* `common`: Contains common headers for both platform targets
		* `memory.h`
		* `platform.h`: gives you an interface to printf using the macro PRINTF as a mechanism to reduce the dependencies on the stdio.h library
	* `msp432`: Contains MSP432 platform headers
	* `CMSIS`: Contains ARM architecture specific headers

I only edited the `Makefile` and `sources.mk` for this assignment.

#### Compile
* Navigate to directory that contains `Makefile`  

`make build PLATFORM=HOST` for host platform target  
or  
`make build PLATFORM=MSP432` for MSP432 platform target  

* Either compilation will produce an executable named `c1m2.out`.

* Note that upon completion of a build, there is also a build report of code size (using the size tool) that is outputted.

#### Run
`./c1m2.out`

* The host code can run natively on your system and should output a string "aXy72_L+R".
* The cortex build will not be able to run natively, since it is meant to run on a separate target. If the cortex build exectuable is run, it will produce an error: "cannot execute binary file: Exec format error".

#### Miscellaneous
* Ensure that the `arm-none-eabi` cross-compiler toolchain is installed and the install location of the arm-none-eabi-* executables are included in the $PATH variable (in .bashrc). Installation instructions can be found here: 
	* https://developers.hardwario.com/firmware/toolchain-setup#setup-on-generic-linux
	* https://shantamraj.wordpress.com/2017/12/03/setting-up-arm-toolchain-on-ubuntu/
	* https://github.com/armmbed/homebrew-formulae
* Run `make clean` before a new build to avoid errors or corrupt `.o` files
______________________________________________
### WEEK 3

#### Contents
* `main.c`: main file to work with
* `misc.c`: declares some data and defines some functions
* `misc.h`: contains function declarations and macros
* `msp432p401r.lds`: linker file for the msp432

#### Compile/assemble source files without linking
`arm-none-eabi-gcc main.c misc.c`

#### Link together following the linker script specs and output map file with the link results
`arm-none-eabi-ld -Map output.map -T msp432p401r.lds -N -o output.elf main.o misc.o`

#### Clean Up
`rm -rf *.o *.map`

______________________________________________
### WEEK 4 (Final Assessment)

#### Contents
* `Makefile`
* `sources.mk`
* `msp432p401r.lds`
* src/
	* `data.c`
	* `course1.c`
	* `main.c`
	* `memory.c`
	* `stats.c`
	* `interrupts_msp432p401r_gcc.c`
    * `startup_msp432p401r_gcc.c`
    * `system_msp432p401r.c`
* include/
	* common/
		* `data.h`
		* `course1.h`
		* `memory.h`
		* `platform.h`
		* `stats.h`
	* msp432/
		* `msp432p401r.h`
		* `msp_compatibility.h`
		* `system_msp432p401r.h`
	* CMSIS/
		* `cmsis_gcc.h`
		* `core_cm4`
		* `core_cmFunc.h`
		* `core_cmInstr.h`
		* `core_cmSimd.h`

#### Compile
* Navigate to directory that contains `Makefile`  

`make build PLATFORM=HOST` for host platform target  
or  
`make build PLATFORM=MSP432` for MSP432 platform target  

* Either compilation will produce an executable named `target.out`.

* Note that upon completion of a build, there is also a build report of code size (using the size tool) that is outputted.

#### Run
`./target.out`

* The host code can run natively on your system and should call a handful of functions from `main.c`. To validate the correctness of the code, please validate that all functions report a PASS when run on the host environment.
* The cortex build will not be able to run natively, since it is meant to run on a separate target. If the cortex build exectuable is run, it will produce an error: "cannot execute binary file: Exec format error".

#### Miscellaneous
* Ensure that the `arm-none-eabi` cross-compiler toolchain is installed and the install location of the arm-none-eabi-* executables are included in the $PATH variable (in .bashrc). See Week 3 for installation instructions.
* Run `make clean` before a new build to avoid errors or corrupt `.o` files
