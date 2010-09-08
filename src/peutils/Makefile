# Sub-makefile for Project Euler utility library.
# AUTHOR: Lawrence Velazquez

# Must be called recursively from master makefile.
ifeq ($(MAKELEVEL), 0)
$(error Must run this makefile from master makefile)
endif

SHELL := /bin/sh

# Library name and version information
dylib_major_version := 1
dylib_minor_version := 0
dylib_micro_version := 0
dylib_current_version := \
        $(dylib_major_version).$(dylib_minor_version).$(dylib_micro_version)
dylib_compat_version = 1.0.0

# Library destination
dylib := $(libdir)/libProjEuler.$(dylib_major_version).dylib

$(dylib): projeuler.c projeuler.h
	$(CC) $(CPPFLAGS) $(LDFLAGS) $(ALL_CFLAGS) $< \
	    -dynamiclib -o $@ \
	    -current_version $(dylib_current_version) \
	    -compatibility_version $(dylib_compat_version) \
	    -fvisibility=hidden && \
	ln -fs $@ $(libdir)/libProjEuler.dylib

# Clear suffix list, since no implicit rules are used.
.SUFFIXES: