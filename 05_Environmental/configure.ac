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
AC_CHECK_LIB([pcre2-8], [pcre2_compile_8], [], AC_MSG_ERROR([LPCRE2 is needed]))

# Checks for header files.
AC_CHECK_HEADERS([ncurses.h], [], AC_MSG_ERROR([No ncurses.h found]))
AC_CHECK_HEADERS([string.h], [], AC_MSG_ERROR([No string.h found]))
AC_CHECK_HEADERS([locale.h], [], AC_MSG_ERROR([No locale.h found]))
AC_CHECK_HEADERS([pcre2.h], [], AC_MSG_ERROR([No pcre2.h found]), [
                  #define PCRE2_CODE_UNIT_WIDTH 0
                  #include <pcre2.h>
                ])

# Checks for typedefs, structures, and compiler characteristics.
AC_ARG_WITH([UTF],
            [AS_HELP_STRING([--without-UTF],
            [Compile without UTF support])],
            [with_utf="no"])

# Checks for library functions.
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
