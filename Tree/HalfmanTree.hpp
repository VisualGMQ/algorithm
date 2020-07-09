#ifndef HALFMANTREE_HPP
#define HALFMANTREE_HPP

#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

typedef struct HMNode{
    HMNode* left;
    HMNode* right;
    int weight;
}*HMTree;

//得到vector中最小的元素
HMNode* GetMinumElem(vector<HMNode*>& v){
    int idx = 0;
    int min = INT_MAX;
    HMNode* ret_node = nullptr;
    for(int i=0;i<v.size();i++){
        if(v[i]->weight<min){
            min = v[i]->weight;
            ret_node = v[i];
            idx = i;
        }
    }
    v.erase(v.begin()+idx);
    return ret_node;
}

HMTree CreateHMTree(int weights[], int len){
    //如果只有一个节点，那就直接生成包含 这一个节点的树
    if(len==1){
        HMNode* node = new HMNode;
        node->weight = weights[0];
        node->left = node->right = 0;
        return node;
    }

    vector<HMNode*> list(len);
    //将元素放入list中
    for(int i=0;i<len;i++){
        HMNode* node = new HMNode;
        node->weight = weights[i];
        node->left = node->right = nullptr;
        list[i] = node;
    }
    while(list.size()>1){
        HMNode* n1, *n2;
        n1 = GetMinumElem(list);
        n2 = GetMinumElem(list);
        HMNode* parent = new HMNode;
        parent->weight = n1->weight+n2->weight;
        parent->left = n1;
        parent->right = n2; 
        list.push_back(parent);
    }
    return list[0];
}

void PreOrder(HMTree t){
    if(t){
        cout<<t->weight<<" ";
        PreOrder(t->left);
        PreOrder(t->right);
    }
}

void InOrder(HMTree t){
    if(t){
        InOrder(t->left);
        cout<<t->weight<<" ";
        InOrder(t->right);
    }
}

void DestroyHMTree(HMTree t){
    if(t){
        DestroyHMTree(t->left);
        DestroyHMTree(t->right);
        delete t;
    }
}

#endif
