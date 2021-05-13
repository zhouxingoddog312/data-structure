object=test.o avltree.o queue.o
a.out:$(object)
	cc -o a.out $(object)
test.o:avltree.h queue.h
avltree.o:avltree.h queue.h
queue.o:queue.h avltree.h

.PHONY:clean
clean:
	rm a.out $(object)
