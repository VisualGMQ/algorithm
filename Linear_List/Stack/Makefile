DEBUG=-g

objs=t_stack.out t_queue.out t_circlequeue.out

all:${objs}

t_stack.out:t_stack.c
	$(CC) $^ -o $@ -std=c99
t_queue.out:t_queue.c
	$(CC) $^ -o $@ -std=c99
t_circlequeue.out:t_circlequeue.c
	$(CC) $^ -o $@ -std=c99

.PHONY:clean
clean:
	rm *.out
