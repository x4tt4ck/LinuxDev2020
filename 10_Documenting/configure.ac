#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([numg], [1.1], [phild@01ab.wiki])
AM_INIT_AUTOMAKE([foreign])
DX_INIT_DOXYGEN([numg])
AC_CONFIG_SRCDIR([numg.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

AC_CONFIG_FILES([Makefile Doxyfile])
AC_OUTPUT
