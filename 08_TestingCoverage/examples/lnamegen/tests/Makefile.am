TESTS = systest.sh stest errors
check_PROGRAMS = stest errors
CFLAGS = @CHECK_CFLAGS@ -I../src
LDADD = $(top_builddir)/src/libnamegen.la @CHECK_LIBS@

.ts.c:
	checkmk $< > $@
