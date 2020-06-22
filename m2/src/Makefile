#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple makefile to run an executable using MSP432 or Host system
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file without linking
#      <FILE>.i - Builds <FILE>.i preprocessor file
#      <FILE>.d - Builds <FILE>.d dependency file
#      <FILE>.asm - Builds <FILE>.asm assembly file
#      build - Builds and links all source files and displays size 
#      all -  Same as build
#      compile_all - Compiles all object files without linking
#      clean - Removes all generated files
#
#
# Platform Overrides:
# 	CPU - ARM Cortex Architecture (cortex-m4, none)
# 	ARCH - ARM Architecture (thumb, none)
# 	SPECS - Specs file given to linker (specs.nosys, none)
#	CC -  Compiler (arm-none-eabi-gcc, gcc)
#	SIZE - Flag to find size of output executable (arm-none-eabi-size, size)     
#	DUMP - Flag to produce assemby file (arm-none-eabi-objdump, objdump)
#	CFLAGFS - Flag for platform override (-DMSP432, DHOST)
#
#
#------------------------------------------------------------------------------
include sources.mk

ifeq ($(PLATFORM), MSP432)

	#Platform Specific Flags
    LINKER_FILE = -T ../msp432p401r.lds

	# Architectures Specific Flags
    CPU = cortex-m4
    ARCH = thumb
    SPECS = nosys.specs

	# Compiler Flags and Defines
    CC = ~/.local/opt/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-gcc
    LD = ~/.local/opt/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-ld
    DUMP = ~/.local/opt/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-objdump
    SIZE = ~/.local/opt/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-size -Btx
    CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -DMSP432

endif

ifeq ($(PLATFORM), HOST)

	# Compiler flags and defines
    CC = gcc
    CFLAGS = -DHOST
    LD = -ld
    DUMP = objdump
    SIZE = size -Btx

endif

GEN_FLAGS = -Wall -Werror -g -O0 -std=c99
LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE)
CPPFLAGS = $(INCLUDES) $(GEN_FLAGS)
TARGET = c1m2

OBJS = $(SOURCES:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

%.i : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -E $< -o $@

%.d : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -M $< -o $@

%.asm : %.o
	$(DUMP) --disassemble $< > $@

%.asm : %.out
	$(DUMP) --disassemble $< > $@ 

.PHONY: build all compile_all clean

build: all

all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

compile_all: $(OBJS) 
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) -c 
	
clean:
	rm -f *.i *.o *.asm *.d \
		  *.out *.map
