#include "Topology.hpp"
using namespace std;

int main(int argc, char** argv){
    Graph g = CreateDGraph();
    InsertVertex(g, "C");
    InsertVertex(g, "C++");
    InsertVertex(g, "Java");
    InsertVertex(g, "数据结构");
    InsertVertex(g, "组成原理");
    InsertVertex(g, "离散数学");
    InsertVertex(g, "操作系统");
    InsertVertex(g, "计算机网络");
    AddEdge(g, "C", "数据结构");
    AddEdge(g, "C++", "数据结构");
    AddEdge(g, "Java", "数据结构");
    AddEdge(g, "数据结构", "组成原理");
    AddEdge(g, "组成原理", "操作系统");
    AddEdge(g, "离散数学", "计算机网络");

    ToplogySort(g);

    return 0;
}
