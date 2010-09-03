# Sub-makefile for Project Euler utility library.
# AUTHOR: Lawrence Velazquez
#
# When this makefile is called recusively by the master makefile, the
# compiled products are placed in the destination location specified therein.
#
# When this makefile is called standalone, the compiled products are placed
# in the current directory.

SHELL := /bin/bash
CC ?= clang
CFLAGS ?= -std=c99 -O0 -Wall

# Library name and version information
lib_name := peutils
dylib_major_version := 1
dylib_minor_version := 0
dylib_micro_version := 0
dylib_current_version := \
        $(dylib_major_version).$(dylib_minor_version).$(dylib_micro_version)
dylib_compat_version = 1.0.0

# Library destination
ifeq ($(MAKELEVEL), 0)
dylib_prefix := .
else
dylib_prefix := $(dest)/$(lib)
endif
dylib := $(dylib_prefix)/lib$(lib_name).$(dylib_major_version).dylib
dylib_symlink := $(dylib_prefix)/lib$(lib_name).dylib


$(dylib): $(lib_name).c $(lib_name).h
	$(CC) $(CFLAGS) -o $@ $< \
	    -dynamiclib \
	    -current_version $(dylib_current_version) \
	    -compatibility_version $(dylib_compat_version) \
	    -fvisibility=hidden && \
	ln -fs $@ $(dylib_symlink)

# Usually only used if the makefile is used independently.
.PHONY: clean
clean:
	-rm -fR *.dylib*