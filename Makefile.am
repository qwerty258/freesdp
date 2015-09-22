## Process this file with automake to produce Makefile.in
## (Developed for automake 1.5)
AUTOMAKE_OPTIONS = config/ansi2knr dist-bzip2

EXTRA_DIST = reconfig TODO  \
	freesdp.lsm.make.in freesdp.lsm.make \
	freesdp.spec.in freesdp.spec

#config/depcomp
#config/config.guess config/config.sub \
#	config/install-sh config/ltmain.sh config/missing \
#	config/mkinstalldirs acconfig.h

# for old versions of `make'
@SET_MAKE@

SUBDIRS = src doc demo 
DIST_SUBDIRS = config demo doc m4 src

# Build freesdp.lsm from freesdp.lsm.make
lsm:   	@PACKAGE@-@VERSION@.tar.gz @PACKAGE@-@VERSION@.tar.bz2
	sed -e 's/@LSM_DATE_I@/$(shell date -I)/' -e 's/@TAR_GZ_SIZE@/$(shell du -k @PACKAGE@-@VERSION@.tar.gz | cut -f1)/' -e 's/@TAR_BZ2_SIZE@/$(shell du -k @PACKAGE@-@VERSION@.tar.bz2 | cut -f1)/' <$(top_srcdir)/@PACKAGE@.lsm.make >@PACKAGE@.lsm
