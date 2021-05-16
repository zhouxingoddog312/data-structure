define compile
$(CC) -o $@ $^
endef
FLAGS=-g -o
objects:=btree.o test.o
a.out:$(objects)
	$(compile)
debug:$(objects)
	$(CC) ${FLAGS} debug $(objects)
$(filter btree.o,$(objects)):%.o:%.h
$(filter test.o,$(objects)):btree.h

.PHONY:cleanall cleandebug
cleanall:
	-rm -f *.o *.out debug
cleandebug:
	-rm -f debug
