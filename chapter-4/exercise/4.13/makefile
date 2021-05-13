a.out:test.o queue.o tree.o
	cc -o a.out test.o queue.o tree.o
test.o: test.c tree.h queue.h
tree.o: tree.c tree.h queue.h
queue.o: queue.c queue.h tree.h

clean:
	rm a.out test.o queue.o tree.o
