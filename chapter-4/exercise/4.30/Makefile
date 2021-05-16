ifndef $(objects)
	objects=test.o avltree.o queue.o
endif
define compile
cc -o $@ $^
endef
a.out:$(objects)
	$(compile)
%.d:%.c
	@set -e;rm -f $@;cc -MM $<>$@.$$$$;sed 's,\($*\).o[ :]*,\1.o $@ : ,g' <$@.$$$$>$@;rm -f $@.$$$$

include $(objects:%.o=%.d)
.PHONY:cleanall clean.d cleanobjects

cleanall:clean.d cleanobjects
	-rm -f a.out
clean.d:
	-rm -f *.d
cleanobjects:
	-rm -f *.o
