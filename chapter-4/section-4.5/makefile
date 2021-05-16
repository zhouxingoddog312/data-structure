objects=test.o splaytree.o queue.o
sources=test.c splaytree.c queue.c

a.out:$(objects)
	@echo "开始编译执行文件"
	$(CC) -o a.out $(objects)

include $(sources:.c=.d)
%.d:%.c
	@echo "生成.d文件"
	@set -e;rm -f $@;\
$(CC) -MM $<>$@.$$$$;\
sed 's,\($*\).o[ :]*,\1.o $@ :,g'<$@.$$$$>$@;\
rm -f $@.$$$$

.PHONY:clean
clean:
	@echo "删除所有执行文件、目标文件和.d文件"
	rm -f a.out $(objects) $(sources:.c=.d)
