## Process this file with automake to produce Makefile.in
AUTOMAKE_OPTIONS = no-dependencies config/ansi2knr

EXTRA_DIST = README rfc2sdps

AM_CFLAGS = @WARNING_FLAGS@ -I$(top_srcdir)/src

noinst_PROGRAMS = torture

torture_SOURCES = torture.c
torture_LDFLAGS = ../src/libfreesdp.la
