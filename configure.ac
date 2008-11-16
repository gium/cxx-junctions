#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)

AC_INIT(cxx-junction, 0.2, guillaume@sadegh-beyki.com)
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([1.7.5 dist-bzip2 no-dist-gzip no-installinfo -Wall foreign])

# If the user didn't supplied a CXXFLAGS value,
# set an empty one to prevent autoconf to stick -O2 -g here.
test -z "$CXXFLAGS" && CXXFLAGS=

# Checks for programs.
AC_PROG_CXX
AC_LANG(C++)

dnl Check if the compiler supports variadic templates.
AC_CXX_VARIADIC_TEMPLATES

# Checks for library functions.

AC_CONFIG_FILES([Makefile gs/Makefile tests/Makefile])
AC_OUTPUT
