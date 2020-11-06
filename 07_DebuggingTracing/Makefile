CFLAGS = -Wall
GENERATES = myrm.so
TRASH = file*
LD_LIBRARY_PATH = .

all: myrm.so

myrm.so: myrm.c
	cc --shared -fPIC $< -o $@ -ldl

clean:
	rm -f $(TRASH)

distclean: clean
	rm -f $(GENERATES)

test: test-real test-myrm

test-real:
	touch file fileFIX
	ls -la file*; true
	rm file*
	ls -la file*; true

test-myrm: myrm.so
	touch file fileFIX
	ls -la file*
	LD_PRELOAD=`pwd`/myrm.so rm file*; true
	ls -la file*; true
