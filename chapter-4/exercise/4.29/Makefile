#test-for-makerandomtree.o: test-for-makerandomtree.c tree.h queue.h
#tree.o: tree.c tree.h queue.h
#queue.o: queue.c queue.h tree.h



define compile
$(CC) -o $@ $^
endef
objects:=tree.o queue.o
libs:=$(objects:.o=.h)
objects+=test-for-makerandomtree.o
a.out:$(objects)
	$(compile)

$(objects):$(libs)
.PHONY:clean

clean:
	-rm -f a.out *.o
