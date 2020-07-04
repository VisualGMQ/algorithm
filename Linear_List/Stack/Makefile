DEBUG=-g

objs=t_stack.out t_queue.out t_circlequeue.out a_parenthesis_match.out a_poland_expression.out

all:${objs}

t_stack.out:t_stack.c
	$(CC) $^ -o $@ ${DEBUG} -std=c99
t_queue.out:t_queue.c
	$(CC) $^ -o $@ ${DEBUG} -std=c99
t_circlequeue.out:t_circlequeue.c
	$(CC) $^ -o $@ ${DEBUG} -std=c99
a_parenthesis_match.out:a_parenthesis_match.c
	$(CC) $^ -o $@ ${DEBUG} -std=c99
a_poland_expression.out:a_poland_expression.c
	$(CC) $^ -o $@ ${DEBUG} -std=c99

.PHONY:clean
clean:
	rm *.out
