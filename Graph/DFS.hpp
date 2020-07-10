//DFS理论上也可以使用非递归方式（需要使用栈），但是栈里面需要存储两个元素：此时遍历的节点和这个节点现在被遍历的子节点。所以这里直接使用递归更方便。
#ifndef DFS_HPP
#define DFS_HPP
#include "Graph.hpp"

void _dfs_recursion(Graph& g, int node_idx, vector<bool>& flag_list){
    if(!flag_list[node_idx]){
        flag_list[node_idx] = true;
        cout<<g.vertexes[node_idx].name<<" ";
        for(auto it=g.vertexes[node_idx].connect.begin();it!=g.vertexes[node_idx].connect.end();it++){
            _dfs_recursion(g, FindNodeIdx(g, it->dst_node->name), flag_list);
        }
    }
}

void DFS(Graph& g){
    vector<bool> flag_list(g.vertex_num, false);
    _dfs_recursion(g, 0, flag_list);
    cout<<endl;
}

#endif

