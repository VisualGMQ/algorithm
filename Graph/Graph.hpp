//使用C++实现带权重有向图，因为C++有vector可以自动分配内存,比较方便
//采用邻接链表的方式
//效率会比较低，但是实现起来很方便
//无向图的算法和有向图一样，所以就只实现有向图。而且当两个顶点存在互通的路径的时候就变为了无向图
#ifndef GRAPH
#define GRAPH
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

struct GEdge;

struct GNode{
    string name;    //节点的名称
    list<GEdge> connect; //和节点相连的其他节点
};

struct GEdge{
    int weight;
    GNode* src_node;
    GNode* dst_node;
};

struct Graph{
    vector<GNode> vertexes;
    int vertex_num;
};

//创建一个有向图
Graph CreateDGraph(){
    Graph g;
    g.vertex_num = 0;
    return g;
}

int FindNodeIdx(Graph&g, string x){
    int idx = -1;
    while(g.vertexes[++idx].name!=x);
    if(idx>=g.vertex_num){
        idx = -1;
        cout<<"[warn] no node name "<<x<<endl;
    }
    return idx;
}

bool Adjacent(Graph& g, string x, string y){
    int idx = FindNodeIdx(g, x);
    if(idx==-1)
        return false;
    for(auto it=g.vertexes[idx].connect.begin();it!=g.vertexes[idx].connect.end();it++)
        if(it->dst_node->name==x)
            return true;
    return false;
}

vector<GNode*> Neighbors(Graph& g, string x){
    int idx = FindNodeIdx(g, x);
    if(idx==-1)
        return vector<GNode*>();
    GNode& node = g.vertexes[FindNodeIdx(g, x)];
    vector<GNode*> ret;
    for(auto it=node.connect.begin();it!=node.connect.end();it++)
        ret.push_back(it->dst_node);
    return ret;
}

void InsertVertex(Graph& g, string x){
    GNode node;
    node.connect = list<GEdge>();
    node.name = x;
    g.vertexes.push_back(node);
    g.vertex_num++;
}

void DeleteVertex(Graph& g, string x){
    int idx = FindNodeIdx(g, x);
    if(idx==-1)
        return;
    for(int i=0;i<g.vertex_num;i++){
        if(i==idx)
            continue;
        auto it = g.vertexes[i].connect.begin();
        while(it!=g.vertexes[i].connect.end()){
            if(it->dst_node->name==x){
                g.vertexes[i].connect.erase(it);
                it = g.vertexes[i].connect.begin();
            }else
                it++;
        }
    }
    g.vertexes.erase(g.vertexes.begin()+idx);
    g.vertex_num--;
}

void AddEdge(Graph& g, string x, string y, int weight = 1){
    GNode& node_x = g.vertexes[FindNodeIdx(g, x)],
            &node_y = g.vertexes[FindNodeIdx(g, y)];
    for(auto it=node_x.connect.begin();it!=node_x.connect.end();it++)
        if(it->dst_node->name==y)
            return;
    GEdge edge;
    edge.weight = weight;
    edge.src_node = &node_x;
    edge.dst_node = &node_y;
    node_x.connect.push_back(edge);
}

//增加无向边
void AddNDEdge(Graph& g, string x, string y, int weight = 1){
    AddEdge(g, x, y, weight);
    AddEdge(g, y, x, weight);
}

void RemoveEdge(Graph& g, string x, string y){
    GNode& n = g.vertexes[FindNodeIdx(g, x)];
    auto it = n.connect.begin();
    while(it!=n.connect.end()){
        if(it->dst_node->name==y){
            n.connect.erase(it);
            it = n.connect.begin();
        }
    }
}

void RemoveNDEdge(Graph& g, string x, string y){
    RemoveEdge(g, x, y);
    RemoveEdge(g, y, x);
}

GNode* FirstNeighbor(Graph& g, string x){
    GNode& node = g.vertexes[FindNodeIdx(g, x)];
    if(node.connect.empty())
        return nullptr;
    return node.connect.begin()->dst_node;
}

GNode* NextNeighbor(Graph& g, string x, string y){
    GNode& node = g.vertexes[FindNodeIdx(g, x)];
    auto it = node.connect.begin();
    while(it!=node.connect.end() && it->dst_node->name!=y)
        it++;
    if(it!=node.connect.end())
        it++;
    else
        return nullptr;
    if(it==node.connect.end())
        return nullptr;
    return it->dst_node;
}

int GetEdgeValue(Graph& g, string x, string y){
    GNode& node = g.vertexes[FindNodeIdx(g, x)];
    auto it = node.connect.begin();
    while(it!=node.connect.end() && it->dst_node->name!=y)
        it++;
    if(it!=node.connect.end())
        return it->weight;
    return -1;
}

void SetEdgeValue(Graph& g, string x, string y, int weight = 1){
    GNode& node = g.vertexes[FindNodeIdx(g, x)];
    auto it = node.connect.begin();
    while(it!=node.connect.end() && it->dst_node->name!=y)
        it++;
    if(it!=node.connect.end())
        it->weight = weight;
}

void SetNDEdgeValue(Graph& g, string x, string y, int weight = 1){
    SetEdgeValue(g, x, y, weight);
    SetEdgeValue(g, y, x, weight);
}

void PrintGraph(Graph& g){
    for(int i=0;i<g.vertex_num;i++){
        cout<<g.vertexes[i].name<<"->";
        for(auto it=g.vertexes[i].connect.begin();it!=g.vertexes[i].connect.end();it++){
            cout<<it->dst_node->name<<"("<<it->weight<<")"<<"->";
        }
        cout<<";"<<endl;
    }
}

#endif
