# Makefile for Project Euler 

# Command options
SHELL = /bin/sh

# Compiler options
CC = gcc
CFLAGS = -std=c99 -Wall -g

# Name of utility library
utils = peutils


# Targets
clean:
	-rm -fR *.dylib *.dSYM

info:
	@echo "Compiler:\n\t$$($(CC) --version | head -n 1)"

lib: lib$(utils).dylib

lib$(utils).dylib: $(utils).c
	$(CC) $(CFLAGS) -dynamiclib -o $@ $^



# Phony targets
.PHONY: clean info lib

# Set suffix list explicitly
.SUFFIXES:
.SUFFIXES: .c .o
