DEBUG=-g

objs:t_matrix.out t_symmatrix.out t_sparsematrix.out

all:${objs}

t_matrix.out:t_matrix.c
	$(CC) $^ -o $@ ${DEBUG} -std=c99
t_symmatrix.out:t_symmatrix.c
	$(CC) $^ -o $@ ${DEBUG} -std=c99
t_sparsematrix.out:t_sparsematrix.c
	$(CC) $^ -o $@ ${DEBUG} -std=c99

.PHONY:clean
clean:
	-rm *.dSYM
	-rm *.out
