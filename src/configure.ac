#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.00])
#AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AC_INIT(p2p, 0.001, remyb@hawaii.edu)
AM_INIT_AUTOMAKE(foreign -Wall)
AC_CONFIG_SRCDIR([messageheader.h])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP

AC_CONFIG_MACRO_DIR(m4)

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([strdup strtol])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
