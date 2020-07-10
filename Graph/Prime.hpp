#ifndef PRIME_HPP
#define PRIME_HPP
#include "Graph.hpp"
#include <stack>
using namespace std;

void _prime_recursion(Graph& g, int node_idx, vector<int>& vertexes){
    vertexes[node_idx] = true;
    GNode& node = g.vertexes[node_idx];
    int min_weight = INT_MAX;
    int min_idx = 0;
    GEdge* edge = nullptr;
    //这一步是看这个节点的所有子节点是否被选中了
    for(auto it=node.connect.begin();it!=node.connect.end();it++){
        int idx = FindNodeIdx(g, it->dst_node->name);
        if(!vertexes[idx]){  //如果这个节点还没有被选择
            if(it->weight<min_weight){
                min_weight = it->weight;
                min_idx = idx;
                edge = &(*it);
            }
        }
    }
    if(edge){
        cout<<edge->src_node->name<<"-"<<edge->weight<<"->"<<edge->dst_node->name<<endl;
        _prime_recursion(g, min_idx, vertexes);
    }
}

int GetRemainIdx(vector<int> vertexes){
    for(int i=0;i<vertexes.size();i++)
        if(!vertexes[i])
            return i;
    return -1;
}

void Prime(Graph& g){
    vector<int> vertexes(g.vertex_num, false);
    //这里先深度遍历找到所有顶点
    _prime_recursion(g, 0, vertexes);
    //然后查漏，看看还有哪些顶点不再树里面。找到哪些顶点所连边中最短输出
    int idx = GetRemainIdx(vertexes);
    while(idx!=-1){
        int min_weight = INT_MAX;
        GEdge* edge = nullptr;
        GNode& node = g.vertexes[idx];
        for(auto it=node.connect.begin();it!=node.connect.end();it++)
            if(it->weight<min_weight){
                min_weight = it->weight;
                edge = &(*it);
            }
        vertexes[idx] = true;
        cout<<edge->src_node->name<<"-"<<edge->weight<<"->"<<edge->dst_node->name<<endl;
        idx = GetRemainIdx(vertexes);
    }
}

#endif

