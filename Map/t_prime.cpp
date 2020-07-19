#include "Graph.hpp"
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
    AddNDEdge(g, "a", "b", 1);
    AddNDEdge(g, "a", "d", 3);
    AddNDEdge(g, "b", "e", 4);
    AddNDEdge(g, "c", "e", 6);
    AddNDEdge(g, "c", "f", 7);
    AddNDEdge(g, "d", "c", 5);
    AddNDEdge(g, "f", "b", 8);
    cout<<"Graph:"<<endl;
    PrintGraph(g);
    cout<<endl;
    cout<<"Prime:";
    Prime(g);
    return 0;
}
