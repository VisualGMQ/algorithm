DEBUG=-g
objs:t_string.out kmp.out

all:${objs}


t_string.out:t_string.c String.h
	$(CC) $< -o $@ -std=c99
kmp.out:kmp.c
	$(CC) $< -o $@ ${DEBUG} -std=c99

.PHONY:clean
clean:
	-rm *.out
	-rm -rf *.dSYM
