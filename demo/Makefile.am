## Process this file with automake to produce Makefile.in
AUTOMAKE_OPTIONS = no-dependencies config/ansi2knr

EXTRA_DIST = README *.sdp

AM_CFLAGS = @WARNING_FLAGS@ -I$(top_srcdir)/src

noinst_PROGRAMS = parsedemo formatdemo modifydemo

parsedemo_SOURCES = parsedemo.c
parsedemo_LDFLAGS = ../src/libfreesdp.la

formatdemo_SOURCES = formatdemo.c
formatdemo_LDFLAGS = ../src/libfreesdp.la

modifydemo_SOURCES = modifydemo.c
modifydemo_LDFLAGS = ../src/libfreesdp.la
