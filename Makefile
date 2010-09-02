# Makefile for Project Euler

# Command options
SHELL = /bin/sh

# Compiler options
CC = clang
CFLAGS = -std=c99 -O0 -Wall -g

# Library name and version information
utils = peutils
dylib_major_version = 1
dylib_minor_version = 0
dylib_micro_version = 0
dylib_current_version = $(dylib_major_version).$(dylib_minor_version).$(dylib_micro_version)
dylib_compat_version = 1.0.0


# Targets
all: dylib

clean:
	-rm -fR *.dylib *.dSYM

dylib: lib$(utils).$(dylib_major_version).dylib

lib$(utils).$(dylib_major_version).dylib: $(utils).c $(utils).h
	$(CC) $(CFLAGS) -o $@ $< \
	    -dynamiclib \
	    -current_version $(dylib_current_version) \
	    -compatibility_version $(dylib_compat_version) \
	    -fvisibility=hidden && \
	ln -fs ./$@ ./lib$(utils).dylib

# test: $(utils)module.c
# 	$(CC) $(CFLAGS)


# Phony targets
.PHONY: all clean dylib test

# Set suffix list explicitly
.SUFFIXES:
.SUFFIXES: .c
