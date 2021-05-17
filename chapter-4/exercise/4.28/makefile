#test.o: test.c tree.h queue.h
#tree.o: tree.c tree.h queue.h
#queue.o: queue.c queue.h tree.h

objects=test.o tree.o queue.o
sources=test.c tree.c queue.c


a.out:$(objects)
	$(CC) -o a.out $(objects)
ifneq ($(MAKECMDGOALS),cleano)
include $(sources:.c=.d)
endif
%.d:%.c
	@set -e;\
	rm -f $@;\
	$(CC) -MM $<>$@.$$$$;\
	sed 's,\($*\).o[ :],\1.o $@ :,g'<$@.$$$$>$@;\
	rm -f $@.$$$$
#这里$$$$代表$$，即shell中的进程号，用进程号创建临时文件，将所有命令放在同一行即一个进程
#不要把注释和程序写在同一行，会出现诡异的bug
.PHONY : cleanall cleand cleano
cleanall : cleand cleano
	-rm ./a.out
cleand :
	-rm ./*.d
cleano :
	-rm ./*.o
