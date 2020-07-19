#ifndef TOPOLOGY_HPP
#define TOPOLOGY_HPP

#include "Graph.hpp"
using namespace std;

int FindNoPrevNode(Graph& g, vector<bool>& node_not_in_graph){
    //找到没有前驱的节点
    vector<bool> flag = node_not_in_graph;
    for(int i=0;i<g.vertex_num;i++){
        if(node_not_in_graph[i])
            continue;
        GNode& node = g.vertexes[i];
        for(auto it=node.connect.begin();it!=node.connect.end();it++)
            flag[FindNodeIdx(g, it->dst_node->name)] = true;
    }
    int begin_idx = -1;
    for(int i=0;i<flag.size();i++)
        if(!flag[i]){
            begin_idx = i;
            break;
        }
    if(begin_idx==-1)
        throw runtime_error("graph has circle");
    //将这个节点从图中删去
    node_not_in_graph[begin_idx] = true;
    return begin_idx;
}

bool IsGraphEmpty(vector<bool>& node_not_in_graph){
    for(bool b : node_not_in_graph)
        if(!b)
            return false;
    return true;
}

void ToplogySort(Graph& g){
    vector<bool> node_not_in_graph(g.vertex_num, false);
    while(!IsGraphEmpty(node_not_in_graph)){
        cout<<g.vertexes[FindNoPrevNode(g, node_not_in_graph)].name<<"->";
    }
    cout<<"end";
}

#endif
