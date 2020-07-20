objs=linearfind.out halffind.out

all:${objs}

linearfind.out:linear_find.cpp
	$(CXX) $^ -o $@ -std=c++11
halffind.out:half_find.cpp
	$(CXX) $^ -o $@ -std=c++11

.PHONY:clean
clean:
	-rm *.out
	-rm -rf *.dSYM
