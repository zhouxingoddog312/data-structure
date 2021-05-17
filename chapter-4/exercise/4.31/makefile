objects=balancetree.o queue.o tree.o
ifeq "$(origin CC)" "default"
link=$(CC) -o $@ $^ -lm
endif
$(basename $(firstword $(objects))).out:$(objects)
	$(link)

$(objects):$(wordlist 2,3,$(objects:.o=.h))
	cc -c -o $@ $(addsuffix .c,$(basename $@))

.PHONY:clean

clean:
	-rm -f $(basename $(word 1,$(objects))).out $(objects)
