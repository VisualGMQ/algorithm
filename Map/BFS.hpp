#ifndef BFS_HPP
#define BFS_HPP
#include "Graph.hpp"
#include <queue>
using namespace std;

void BFS(Graph& g){
    queue<int> q;   
    q.push(0);
    vector<bool> flag_list(g.vertex_num, false);    //用于标志节是否已经遍历的列表
    while(!q.empty()){
        int& node_idx = q.front();
        q.pop();
        if(!flag_list[node_idx]){
            cout<<g.vertexes[node_idx].name<<" ";
            flag_list[node_idx] = true;
            for(auto it=g.vertexes[node_idx].connect.begin();it!=g.vertexes[node_idx].connect.end();it++){
                int idx = FindNodeIdx(g, it->dst_node->name);
                q.push(idx);
            }
        }
    }
    cout<<endl;
}

#endif

