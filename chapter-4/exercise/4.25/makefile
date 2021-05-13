#test.o: test.c splaytree.h queue.h
#test1.o: test1.c splaytree.h queue.h
#splaytree.o: splaytree.c splaytree.h queue.h
#queue.o: queue.c queue.h splaytree.h




vpath %.c ./
vpath %.h ./
object=$(patsubst %.c,%.o,$(wildcard *.c))

all:a.out a1.out
.PHONY:all
a.out:test.o splaytree.o queue.o
	cc -o a.out test.o splaytree.o queue.o

a1.out:test1.o splaytree.o queue.o
	cc -o a1.out test1.o splaytree.o queue.o



$(object):queue.h splaytree.h


.PHONY:cleanall cleanexecute cleanobject
cleanall:cleanexecute cleanobject
cleanexecute:
	rm *.out
cleanobject:
	rm $(object)
