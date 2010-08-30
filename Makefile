# Makefile for Project Euler

# Command options
SHELL = /bin/sh

# Compiler options
CC = gcc
CFLAGS = -std=c99 -Wall -g

# Library name and version information
utils = peutils
dylibmajorversion = 1
dylibminorversion = 0
dylibcurrversion = $(dylibmajorversion).$(dylibminorversion)
dylibcompatversion = 1.0


# Targets
dylib: lib$(utils).$(dylibmajorversion).dylib

lib$(utils).$(dylibmajorversion).dylib: $(utils).c $(utils).h
	$(CC) $(CFLAGS) -fvisibility=hidden -dynamiclib -o $@ \
	    -current_version $(dylibcurrversion) \
	    -compatibility_version $(dylibcompatversion) \
	    $<

clean:
	-rm -fR *.dylib *.dSYM

info:
	@echo "Compiler:\n\t$$($(CC) --version | head -n 1)"



# Phony targets
.PHONY: clean dylib info

# Set suffix list explicitly
.SUFFIXES:
.SUFFIXES: .c
