DEBUG=-g

objs=t_queue.out t_circlequeue.out

all:${objs}

t_queue.out:t_queue.c
	$(CC) $^ -o $@ ${DEBUG} -std=c99
t_circlequeue.out:t_circlequeue.c
	$(CC) $^ -o $@ ${DEBUG} -std=c99

.PHONY:clean
clean:
	-rm *.out
	-rm -rf *.dSYM
