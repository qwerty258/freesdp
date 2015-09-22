## Process this file with automake to produce Makefile.in
## (Developed for automake 1.5)

# for old versions of `make'
@SET_MAKE@

AM_CFLAGS = @WARNING_FLAGS@
AM_LDFLAGS = -version-info @LT_VERSION@ -release @LT_RELEASE@

# libfreesdp = libfreesdpp (parser) + libfreesdpf (formatter)
lib_LTLIBRARIES =  libfreesdpc.la libfreesdpp.la libfreesdpf.la libfreesdp.la

# priv.h, parserpriv.h and formatterpriv.h must not be installed,
# but must be distributed

libfreesdpc_la_SOURCES = common.c errorlist.c priv.h

libfreesdpp_la_SOURCES = parser.c parserpriv.h
libfreesdpp_la_LDFLAGS = libfreesdpc.la

libfreesdpf_la_SOURCES = formatter.c formatterpriv.h
libfreesdpf_la_LDFLAGS = libfreesdpc.la

libfreesdp_la_SOURCES =
libfreesdp_la_LDFLAGS = libfreesdpp.la libfreesdpf.la


libfreesdpincludedir = $(includedir)/freesdp

libfreesdpinclude_HEADERS = freesdp/freesdp.h freesdp/common.h \
	 freesdp/parser.h freesdp/formatter.h 
