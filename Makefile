###################################
# Master makefile for Project Euler
###################################

# Export all variables to sub-makefiles
export

SHELL := /bin/sh

# Compilation options
CC := clang
CFLAGS := -std=c99 -O0 -Wall

# Install options
INSTALL := /usr/bin/install
INSTALL_PROGRAM := $(INSTALL)
INSTALL_DATA := $(INSTALL) -m 644

# Installation directories
prefix := $(CURDIR)
exec_prefix := $(prefix)
bindir := $(exec_prefix)/bin
includedir := $(prefix)/include
libdir := $(exec_prefix)/lib
srcdir := $(CURDIR)/src

# Targets
.PHONY: all
all: dylib

.PHONY: clean
clean:
	-rm -fR *.dylib *.dSYM

.PHONY: dylib
dylib:
	$(MAKE) -C $(src)/libProjEuler

# .PHONY: test
# test: $(lib_name)module.c
# 	$(CC) $(CFLAGS)


# Clear suffix list
.SUFFIXES:
