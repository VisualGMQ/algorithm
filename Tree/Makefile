DEBUG=-g
objs=t_binarytree.out t_question1.out t_question2.out t_bst.out t_halfmantree.out t_avltree.out

all:${objs}


t_binarytree.out:t_binarytree.cpp BinaryTree.hpp
	$(CXX) $< -o $@ ${DEBUG} -std=c++11
t_question1.out:t_question1.cpp BinaryTree.hpp
	$(CXX) $< -o $@ ${DEBUG} -std=c++11
t_question2.out:t_question2.cpp BinaryTree.hpp
	$(CXX) $< -o $@ ${DEBUG} -std=c++11
t_bst.out:t_bst.cpp BST.hpp
	$(CXX) $< -o $@ ${DEBUG} -std=c++11
t_halfmantree.out:t_halfmantree.cpp HalfManTree.hpp
	$(CXX) $< -o $@ ${DEBUG} -std=c++11
t_avltree.out:t_avltree.cpp AVL.hpp
	$(CXX) $< -o $@ ${DEBUG} -std=c++11

.PHONY:clean
clean:
	-rm *.out
	-rm -rf *.dSYM
