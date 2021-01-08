# bin_PROGRAMS = buf
lib_LTLIBRARIES = libbuf.la

buf_LDADD = libbuf.la

if COND_GCOV
	CFLAGS += -fprofile-arcs -ftest-coverage -O0 -g
endif

gcov:
	gcov .libs/libbuf -t -j -k
