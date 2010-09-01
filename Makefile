# Makefile for Project Euler

# Command options
SHELL = /bin/sh

# Compiler options
CC = clang
CFLAGS = -std=c99 -O0 -Wall -g

# Library name and version information
utils = peutils
dylibmajorversion = 1
dylibminorversion = 0
dylibcurrversion = $(dylibmajorversion).$(dylibminorversion)
dylibcompatversion = 1.0


# Targets
dylib: lib$(utils).$(dylibmajorversion).dylib

lib$(utils).$(dylibmajorversion).dylib: $(utils).c $(utils).h
	$(CC) $(CFLAGS) -o $@ $< \
	    -dynamiclib \
	    -current_version $(dylibcurrversion) \
	    -compatibility_version $(dylibcompatversion) \
	    -fvisibility=hidden

clean:
	-rm -fR *.dylib *.dSYM



# Phony targets
.PHONY: clean dylib info

# Set suffix list explicitly
.SUFFIXES:
.SUFFIXES: .c
