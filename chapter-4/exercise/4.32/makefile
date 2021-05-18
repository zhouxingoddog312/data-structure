#balancetree.o: balancetree.c tree.h queue.h
#queue.o: queue.c queue.h tree.h
#tree.o: tree.c tree.h queue.h
LDLIBS=-lm
balancetree:balancetree.o queue.o tree.o

.PHONY:clean

clean:
	$(RM) balancetree balancetree.o queue.o tree.o
