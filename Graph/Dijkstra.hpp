//算法介绍：https://www.luogu.com.cn/blog/little-sun/dijkstra
#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include "Graph.hpp"
using namespace std;

void _dijkstra_recursion(Graph& g, int curnode_idx, vector<int>& len_list, vector<bool>& flag_list){
    if(flag_list[curnode_idx])
        return;
    flag_list[curnode_idx] = true;
    GNode& node = g.vertexes[curnode_idx];
    for(auto it=node.connect.begin();it!=node.connect.end();it++){
        int idx = FindNodeIdx(g, it->dst_node->name);
        if(len_list[idx]>len_list[curnode_idx]+it->weight)
            len_list[idx] = len_list[curnode_idx]+it->weight;
    }
    for(auto it=node.connect.begin();it!=node.connect.end();it++){
        int idx = FindNodeIdx(g, it->dst_node->name);
        _dijkstra_recursion(g, idx, len_list, flag_list);
    }
}

vector<int> Dijkstra(Graph& g, int node_idx){
    vector<int> len_list(g.vertex_num, INT_MAX);
    vector<bool> flag_list(g.vertex_num, false);
    len_list[node_idx] = 0;
    _dijkstra_recursion(g, node_idx, len_list, flag_list);
    return len_list;
}

#endif

