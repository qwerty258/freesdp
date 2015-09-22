dnl Process this file with autoconf to produce a configure script
dnl (Developed for autoconf 2.53)
AC_INIT([freesdp],[0.5.0b1],freesdp-devel@nongnu.org)
PACKAGE=freesdp
VERSION="0.5.0b1"
LT_RELEASE="0.5.0"
LT_VERSION="0:0:0"
AC_PREREQ([2.53])
AC_CONFIG_HEADERS([src/freesdp/config.h])
AC_CONFIG_SRCDIR([src/freesdp/common.h])
AC_CONFIG_AUX_DIR([config])
AC_CANONICAL_TARGET([])
AM_INIT_AUTOMAKE([$PACKAGE],[$VERSION])
AC_PROG_MAKE_SET

AC_MSG_NOTICE([Checks for programs:])
AC_PROG_CPP
AC_PROG_CC
AC_PROG_CC_STDC
AM_C_PROTOTYPES
AC_PROG_INSTALL
AM_PROG_LIBTOOL

# Flags for restrictive warnings:
if test $GCC = yes ; then
	WARNING_FLAGS="-Wall -ansi -W"
else
	WARNING_FLAGS=""
fi
AC_SUBST(WARNING_FLAGS)

AC_MSG_NOTICE([Checks for header files:])
AC_HEADER_TIME
AC_CHECK_HEADERS([sys/time.h])

AC_MSG_NOTICE([Checks for C compiler:])
AC_C_PROTOTYPES
AC_HEADER_STDC

AC_MSG_NOTICE([Checks for types:])
AC_C_CONST
AC_TYPE_SIZE_T

AC_MSG_NOTICE([Checks for C library functions:])
AC_CHECK_FUNCS([strdup strtoul strtof])
AC_FUNC_MALLOC

AC_SUBST(LT_VERSION)
AC_SUBST(LT_RELEASE)

AC_CONFIG_FILES([Makefile config/Makefile m4/Makefile src/Makefile
			  doc/Makefile demo/Makefile
			  freesdp.lsm.make freesdp.spec])
dnl tests/Makefile
AC_OUTPUT