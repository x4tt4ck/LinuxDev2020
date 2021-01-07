#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([InteractivRE], [1.0], [phild@01ab.wiki])
AC_CONFIG_SRCDIR([./src])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AM_INIT_AUTOMAKE

# Checks for libraries.
AC_CHECK_LIB([ncursesw], [initscr], [], AC_MSG_ERROR([Curses is needed]))
AC_CHECK_LIB([pcre2-8], [pcre2_compile], [], AC_MSG_ERROR([LPCRE2 is needed]))

# Checks for header files.
AC_CHECK_HEADERS([ncurses.h], [] AC_MSG_ERROR([No ncurses.h found]))


# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
