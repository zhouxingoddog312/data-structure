#test-for-makerandomtree.o: test-for-makerandomtree.c tree.h queue.h
#tree.o: tree.c tree.h queue.h
#queue.o: queue.c queue.h tree.h
sources:=test-for-makerandomtree.c tree.c queue.c
objects=$(sources:.c=.o)
$(basename $(firstword $(objects))):$(objects)

.PHONY:clean

clean:
	$(RM) $(basename $(filter test-%,$(sources))) $(objects)
