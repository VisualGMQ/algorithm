//这里采用C++编写，因为层次遍历需要队列，直接用库里面的队列了。
#ifndef BINARYTREE
#define BINARYTREE
#include <iostream>
#include <queue>
#include <exception>
#include <stdexcept>
using namespace std;

using ElemType = int;

typedef struct BinNode{
    ElemType data;
    BinNode* left;
    BinNode* right;
}*BinTree;

BinNode* CreateNode(ElemType data, BinNode* left, BinNode* right){
    BinNode* node = new BinNode;
    if(!node)   //没有足够内存分配，报错
        throw runtime_error("memory not enough");
    node->left = left;
    node->right = right;
    return node;
}

void AssignNode(BinNode* node, ElemType data, BinNode* left, BinNode* right){
    node->data = data;
    node->left =  left;
    node->right = right;
}

void VisitNode(BinNode* n){
    cout<<n->data<<" ";
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

void LevelOrder(BinTree t){
    queue<BinNode*> q;
    q.push(t);
    while(!q.empty()){
        BinNode* node = q.front();
        q.pop();
        if(node!=nullptr){
            VisitNode(node);
            q.push(node->left);
            q.push(node->right);
        }
    }
}

//这个函数来得到树中节点的个数
int NodeNumber(BinTree t){
    if(t){
        int left = NodeNumber(t->left);
        int right = NodeNumber(t->right);
        return left+right+1;
    }
    return 0;
}

//通过这个函数得到树的层
int Layer(BinTree t){
    if(t){
        int left = Layer(t->left);
        int right = Layer(t->right);
        return left>right?left:right + 1;
    }
    return 1;
}

//释放树的内存。
void DestroyTree(BinTree t){
    if(t){
        DestroyTree(t->left);
        DestroyTree(t->right);
        delete t;
    }
}

#endif
