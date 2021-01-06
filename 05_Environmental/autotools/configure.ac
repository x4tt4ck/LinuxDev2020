#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Key Scanner], [0.01], [phild@01ab.wiki])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([KeyScan.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([ncursesw], [initscr], [], AC_MSG_ERROR([Curses is needed]))
AC_CHECK_LIB([missing], [notfound])

# Checks for header files.
AC_CHECK_HEADER([ncurses.h], [], AC_MSG_ERROR([No ncurses.h found]))

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
