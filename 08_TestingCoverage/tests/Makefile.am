TESTS = init_free
check_PROGRAMS = init_free
CFLAGS = @CHECK_CFLAGS@ -I../src
LDADD = $(top_builddir)/src/libbuf.la @CHECK_LIBS@

.ts.c:
	checkmk $< > $@
