DEBUG=-g
all:t_staticseqlist.out t_dynamicseqlist.out h_question1.out h_question2.out h_question3.out h_question4.out


t_staticseqlist.out:StaticSeqList.h t_staticseqlist.c
	$(CC) t_staticseqlist.c -o $@ ${DEBUG} -std=c99
t_dynamicseqlist.out:DynamicSeqList.h t_dynamicseqlist.c
	$(CC) t_dynamicseqlist.c -o $@ ${DEBUG} -std=c99
h_question1.out:h_question1.c
	$(CC) $^ -o $@ ${DEBUG}
h_question2.out:h_question2.c
	$(CC) $^ -o $@ ${DEBUG}
h_question3.out:h_question3.c
	$(CC) $^ -o $@ ${DEBUG}
h_question4.out:h_question4.c
	$(CC) $^ -o $@ ${DEBUG}

.PHONY:clean
clean:
	-rm  *.out
	-rm -rf *.dSYM
