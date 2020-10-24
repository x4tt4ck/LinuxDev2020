LDFLAGS=-static
CFLAGS=-Wall
LDLIBS=-lm
GENERATS=*.o prog README*

all: prog README.md

%.md:	%.dat
	sed "s/DATE/`date`/g" < $< >$@

README.dat:
	echo "[DATE] - Build completed successfully" > $@;

prog:	prog.o fun.o
	cc $(LDFLAGS) $(LDLIBS) prog.o fun.o -o prog

clean:
	rm -rf $(GENERATS)
