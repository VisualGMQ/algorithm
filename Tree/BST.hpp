#ifndef BST
#define BST
#include <iostream>
using namespace std;

using ElemType = int;

typedef struct BinNode{
    ElemType data;
    BinNode* left;
    BinNode* right;
}*BinTree;

//从BinaryTree.h抄来的
BinNode* CreateNode(ElemType data, BinNode* left, BinNode* right){
    BinNode* node = new BinNode;
    if(!node)   //没有足够内存分配，报错
        throw runtime_error("memory not enough");
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}

//从BinaryTree.h抄来的
void AssignNode(BinNode* node, ElemType data, BinNode* left, BinNode* right){
    node->data = data;
    node->left =  left;
    node->right = right;
}

void AddElement(BinTree* t, ElemType n){
    if(*t==nullptr){
        *t = CreateNode(n, nullptr, nullptr);
    }else{
        BinNode* node = *t;
        BinNode* pre_n = node;
        BinNode* newnode = CreateNode(n, nullptr, nullptr);
        while(node){
            pre_n = node;
            if(n<node->data)
                node = node->left;
            else
                node = node->right;
        }
        if(n<pre_n->data)
            pre_n->left = newnode;
        else
            pre_n->right = newnode;
    }
}

void DelElement(BinTree* t, ElemType n){
    BinNode* node = *t,
        *prev_node = node;
    //首先找到节点
    while(node && node->data!=n){
        prev_node = node;
        if(n<node->data)
            node = node->left;
        else
            node = node->right;
    }
    //如果节点不存在，直接返回
    if(!node){
        cout<<"don't exists node"<<endl;
        return;
    }
    BinNode* split_node;
    //如果节点存在，将node的左节点移动到其右节点的最左节点上
    if(!node->right)
        split_node = node->left;
    else{
        split_node = node->right;
        BinNode* most_left_node = node->right;
        while(most_left_node->left)
            most_left_node = most_left_node->left;
        most_left_node->left = node->left;
    }
    //接下来看找到的节点是父节点的左节点还是右节点，并拼接节点
    if(prev_node->left->data==node->data)
        prev_node->left = split_node;
    else
        prev_node->right = split_node;
    delete node;
}


BinNode* FindElement(BinTree* t, ElemType n){
    BinNode* node = *t;
    while(node && node->data!=n){
        if(n<node->data)
            node = node->left;
        else
            node = node->right;
    }
    return node;
}

void ChangeElemt(BinTree* t, ElemType key, ElemType new_value){
    FindElement(t, key)->data = new_value;
}

//下面函数都是从BinaryTree.h中抄来的,重复利用

void VisitNode(BinNode* n){
    cout<<n->data<<' ';
}

void PreOrder(BinTree t){
    if(t){
        VisitNode(t);
        PreOrder(t->left);
        PreOrder(t->right);
    } 
}

void InOrder(BinTree t){
    if(t){
        InOrder(t->left);
        VisitNode(t);
        InOrder(t->right);
    } 
}

void PostOrder(BinTree t){
    if(t){
        PostOrder(t->left);
        PostOrder(t->right);
        VisitNode(t);
    } 
}

void DestroyTree(BinTree t){
    if(t){
        DestroyTree(t->left);
        DestroyTree(t->right);
        delete t;
    }
}

#endif

