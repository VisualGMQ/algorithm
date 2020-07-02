DEBUG=-g

all:t_linklist.out t_staticlinklist.out h_question1.out h_question2.out h_question3.out h_question4.out


t_linklist.out:LinkList.h t_linklist.c
	$(CC) t_linklist.c -o $@ ${DEBUG} -std=c99
t_staticlinklist.out:StaticLinkList.h t_staticlinklist.c
	$(CC) t_staticlinklist.c -o $@ ${DEBUG} -std=c99
h_question1.out:LinkList.h h_question1.c
	$(CC) h_question1.c -o $@ ${DEBUG} -std=c99
h_question2.out:LinkList.h h_question2.c
	$(CC) h_question2.c -o $@ ${DEBUG} -std=c99
h_question3.out:LinkList.h h_question3.c
	$(CC) h_question3.c -o $@ ${DEBUG} -std=c99
h_question4.out:LinkList.h h_question4.c
	$(CC) h_question4.c -o $@ ${DEBUG} -std=c99

.PHONY:clean
clean:
	rm *.out
	rm -rf *.dSYM
