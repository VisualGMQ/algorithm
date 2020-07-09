#ifndef RBT_HPP
#define RBT_HPP
#include <iostream>
using namespace std;

enum class RBTColor{
    BLACK,
    RED
};

using ElemType = int;

typedef struct RBTNode{
    ElemType data;
    RBTColor color;
    RBTNode* left;
    RBTNode* right;
    RBTNode* parent;    //这里给一个parent节点方便编程
}*RBTTree;

void InitRBT(RBTTree* t){
    *t = nullptr;
}

void LeftLeftRotate(RBTNode* node){
    
}

void LeftRightRotate(RBTNode* node){
    
}

void RightRightRotate(RBTNode* node){

}

void RightLeftRotate(RBTNode* node){

}

void DestroyRBT(RBTTree* t){
    RBTNode* node = *t;
    if(node!=nullptr){
        DestroyRBT(&node->left);
        DestroyRBT(&node->right);
        delete node;
        *t = nullptr;
    }
}


#endif

