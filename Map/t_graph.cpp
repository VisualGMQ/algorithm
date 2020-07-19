#include "Graph.hpp"
#include "BFS.hpp"
#include "DFS.hpp"
#include "Prime.hpp"
#include <iostream>
using namespace std;

int main(int argc, char** argv){
    Graph g;
    g = CreateDGraph();
    InsertVertex(g, "a");
    InsertVertex(g, "b");
    InsertVertex(g, "c");
    InsertVertex(g, "d");
    InsertVertex(g, "e");
    InsertVertex(g, "f");
    AddEdge(g, "a", "b", 1);
    AddEdge(g, "a", "d", 3);
    AddEdge(g, "b", "a", 2);
    AddEdge(g, "b", "e", 4);
    AddEdge(g, "c", "e", 6);
    AddEdge(g, "c", "f", 7);
    AddEdge(g, "d", "c", 5);
    AddEdge(g, "f", "b", 8);
    cout<<"Graph:"<<endl;
    PrintGraph(g);
    cout<<endl<<"BFS:"<<endl;
    BFS(g);
    cout<<endl<<"DFS:"<<endl;
    DFS(g);
    return 0;
}
