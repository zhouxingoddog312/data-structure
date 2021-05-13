objects = test.o avltree.o stack.o queue.o

a.out:$(objects)
	cc -o a.out $(objects)
test.o: test.c avltree.h queue.h stack.h
	cc -c test.c
avltree.o: avltree.c avltree.h queue.h stack.h
	cc -c avltree.c
stack.o: stack.c stack.h avltree.h
	cc -c stack.c
queue.o: queue.c queue.h avltree.h
	cc -c queue.c

clean:
	rm a.out $(objects)
