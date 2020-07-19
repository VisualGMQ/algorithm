DEBUG=-g
objs=t_graph.out t_prime.out t_dijkstra.out t_topology.out

all:${objs}

t_graph.out:t_graph.cpp Graph.hpp DFS.hpp BFS.hpp
	$(CXX) $< -o $@ ${DEBUG} -std=c++11
t_prime.out:t_prime.cpp Prime.hpp Graph.hpp
	$(CXX) $< -o $@ ${DEBUG} -std=c++11
t_dijkstra.out:t_dijkstra.cpp Dijkstra.hpp Graph.hpp
	$(CXX) $< -o $@ ${DEBUG} -std=c++11
t_topology.out:t_topology.cpp Graph.hpp
	$(CXX) $< -o $@ ${DEBUG} -std=c++11

.PHONY:clean
clean:
	-rm  *.out
	-rm -rf *.dSYM
