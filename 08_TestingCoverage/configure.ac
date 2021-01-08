#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([bufGrow], [1], [phild@01ab.wiki])
AM_INIT_AUTOMAKE([foreign])
PKG_CHECK_MODULES([CHECK], [check])
LT_INIT([disable-static])
AC_CONFIG_SRCDIR([src/buf.h])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile src/Makefile tests/Makefile])
AC_OUTPUT
