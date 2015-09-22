Summary: FreeSDP - A SDP descriptions parser and formatter library
Name: freesdp
Version: 0.5.0b1
Release: 1
Copyright: GPL
Group: Development/Libraries
URL: http://www.nongnu.org/freesdp/
Source: http://savannah.nongnu.org/download/freesdp/freesdp.pkg/%{PACKAGE_VERSION}/freesdp-%{PACKAGE_VERSION}.tar.gz
Packager: Federico Montesino Pouzols <fedemp@altern.org>
BuildRequires:  autoconf
BuildRequires:  automake
BuildRequires:  libtool
Requires: freesdp-parser freesdp-formatter

%package common
Group: Development/Libraries
Summary: common infrastructure both FreeSDP parser and formatter

%description common
Common infrastructure for both FreeSDP parser and formatter.

%package parser
Requires: freesdp-common
Group: Development/Libraries
Summary: parser library.

%description parser
FreeSDP parser library.

%package formatter
Requires: freesdp-common
Group: Development/Libraries
Summary: formatter library.

%description formatter
FreeSDP formatter library.

%package devel
Requires: freesdp
Group: Development/Libraries
Summary: headers and link libraries

%description 
FreeSDP is a stand-alone free C library that provides a complete set
of functions to parse and fetch the information multimedia session
descriptions formatted in SDP enclose. It can also format SDP
descriptions from the session parameters. SDP is the Session
Description Protocol from the IETF (see RFC 2327 and
draft-ietf-mmusic-sdp-new). FreeSDP does not only implement the base
SDP specification, but also a number of extensions.  

%description devel 
This package includes documentation, header files, and static link
libraries for building applications that use FreeSDP.

%prep
%setup -n freesdp-%{PACKAGE_VERSION}
./configure --prefix=%{_prefix}

%build
uname -a | grep SMP && make -j 2 || make

%install
make prefix=$RPM_BUILD_ROOT/%{_prefix} \
	mandir=$RPM_BUILD_ROOT/%{_mandir} \
	infodir=$RPM_BUILD_ROOT/%{_infodir} install

%files
%defattr(-,root,root,0755)
%{_prefix}/lib/libfreesdp.so*

%files common
%defattr(-,root,root,0755)
%doc AUTHORS COPYING README
%{_prefix}/lib/libfreesdpc.so*

%files parser
%defattr(-,root,root,0755)
%{_prefix}/lib/libfreesdpp.so*

%files formatter
%defattr(-,root,root,0755)
%{_prefix}/lib/libfreesdpf.so*

%files devel
%defattr(-,root,root,0755)
%doc NEWS TODO ChangeLog doc/refman/html/
%{_prefix}/lib/libfreesdp*.a
%{_prefix}/include/freesdp/freesdp.h
%{_prefix}/include/freesdp/parser.h
%{_prefix}/include/freesdp/formatter.h
%{_prefix}/include/freesdp/common.h
%{_infodir}/freesdp*info*

%clean

%post
/sbin/ldconfig -n ${exec_prefix}/lib

%postun
/sbin/ldconfig -n ${exec_prefix}/lib

%changelog
*  Thr Jul 03 2003 Federico Montesino Pouzols <fedemp@altern.org> 0.4.4-1
- added BuildRequire lines.
*  Sat Nov 24 2002 Federico Montesino Pouzols <fedemp@altern.org> 0.3.1-1
- first version
