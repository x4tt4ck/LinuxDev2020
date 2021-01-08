TESTS = init_free clear_noop push trunc_grow pop
check_PROGRAMS = init_free clear_noop push trunc_grow pop
CFLAGS = @CHECK_CFLAGS@ -I../src
LDADD = $(top_builddir)/src/libbuf.la @CHECK_LIBS@

.ts.c:
	checkmk $< > $@
