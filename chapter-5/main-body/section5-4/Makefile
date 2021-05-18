LDLIBS=-lm
test:test.o hashquad.o
hashquad.o: hashquad.c hashquad.h
test.o: test.c hashquad.h

clean:
	rm -f test test.o hashquad.o
