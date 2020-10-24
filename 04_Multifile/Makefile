CFLAGS = -Wall
GENERATES = prog prog-a prog-so liboutput*
TRASH = *.o *~ o.* file*
LD_LIBRARY_PATH = .

all:	prog prog-a prog-so

liboutput_static.a: fun.o const.o
	ar -rcs $@ $^

liboutput.so: fun.o const.o
	cc -shared $^ -o $@

prog:	const.o fun.o prog.o

fun.o: fun.c
	cc -fPIC fun.c -c -o fun.o

prog-a:	prog.o liboutput_static.a
	cc -L$(LD_LIBRARY_PATH) $< -loutput_static -o $@

prog-so: prog.o liboutput.so
	cc -L$(LD_LIBRARY_PATH) $< -loutput -o $@

fun.o:	outlib.h

clean:
	rm -f $(TRASH)

distclean: clean
	rm -rf $(GENERATES)

test: test-1 test-2 test-3 clean

test-1:	prog prog-a prog-so
	./prog 2> file1
	./prog-a 2> file2
	LD_LIBRARY_PATH=`pwd` ./prog-so 2> file3
	- cmp file1 file2
	- cmp file2 file3
	- cmp file3 file1

test-2: prog prog-a prog-so
	./prog a 2>file1
	./prog-a a 2>file2
	LD_LIBRARY_PATH=`pwd` ./prog-so a 2>file3
	cmp file1 file2
	cmp file2 file3
	cmp file3 file1

test-3:	prog prog-a prog-so
	./prog a b c > file1
	./prog-a a b c > file2
	LD_LIBRARY_PATH=`pwd` ./prog-so a b c > file3
	cmp file1 file2
	cmp file2 file3
	cmp file3 file1
