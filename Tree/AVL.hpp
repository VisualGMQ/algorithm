#ifndef AVL_HPP
#define AVL_HPP

#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

using ElemType = int;

typedef struct AVLNode{
    ElemType data;
    AVLNode* left;
    AVLNode* right;
    AVLNode* parent;    //多定义一个父节点，方便操作
}*AVLTree;

void InitAVL(AVLTree* t){
    *t = nullptr;
}

int GetTreeHeight(AVLTree t){
    if(t){
        int left = GetTreeHeight(t->left);
        int right = GetTreeHeight(t->right);
        return (left>right?left:right) + 1;
    }
    return 1;
}

int BalanceFactor(AVLTree t){
    int left = GetTreeHeight(t->left),
        right = GetTreeHeight(t->right);
    return abs(left-right);
}


bool IsBalance(AVLTree t){
    return BalanceFactor(t)<=1;
}

void RightRotate(AVLNode* node){
    AVLNode* parent = node->parent,
            *left = node->left,
            *lright = left->right;
    node->left = lright;
    lright->parent = node;
    left->right = node;
    node->parent = left;
    left->parent = parent;
    if(parent){
        if(parent->left==node)
            parent->left = left;
        else 
            parent->right = left;
    }
}

void LeftRotation(AVLNode* node){
    AVLNode* parent = node->parent,
            *right = node->right,
            *rleft = right->left;
    node->right = rleft;
    rleft->parent = node;
    right->left = node;
    node->parent = right;
    right->parent = parent;
    if(parent){
        if(parent->left==node)
            parent->left = right;
        else 
            parent->right = right;
    }
}

//这里的node都是指为旋转轴的节点

void LL(AVLNode* node){
    RightRotate(node);
}

void LR(AVLNode* node){
    AVLNode* parent = node->parent;
    LeftRotation(node);
    RightRotate(parent);
}

void RR(AVLNode* node){
    LeftRotation(node);
}

void RL(AVLNode* node){
    AVLNode* parent = node->parent;
    RightRotate(node);
    LeftRotation(parent);
}

void Balance(AVLNode* t){
    AVLNode* axis = t->parent;
    if(!IsBalance(axis)){
        if(axis->left==t){
            if(t->left){  //是LL情况
                LL(axis);
            }else{  //是LR情况
                LR(axis);
            }
        }else{  
            if(t->left)   //是RL情况
                RL(axis);
            else    //是RR情况
                RR(axis);
        }
    }
}

void ToBalance(AVLTree t){
    if(!t)
        return;
    if(!IsBalance(t))
        Balance(t);
    else{
        ToBalance(t->left);
        ToBalance(t->right);
    }
}

void Insert(AVLTree* t, ElemType e){
    //如果只有一个节点，直接插入
    if(*t==nullptr){
        AVLNode* node = new AVLNode;
        node->parent = node->left = node->right = nullptr;
        node->data = e;
        *t = node;
        return;
    }
    //和搜索树一样的插入方法
    AVLNode* node = *t,
            *parent = node;
    while(node){
        parent = node;
        if(e<node->data)
            node = node->left;
        else
            node = node->right;
    }
    AVLNode* newnode = new AVLNode;
    newnode->data = e;
    newnode->right = newnode->left = nullptr;
    newnode->parent = parent;
    if(e<parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;

    int balanceFactor = BalanceFactor(parent);
	if(balanceFactor>1 && BalanceFactor(parent->left)>0){
		//右旋LL
		LL(parent);
        return;
	}
	if(balanceFactor<-1 && BalanceFactor(parent->right)<0){
		//左旋RR
		RR(parent);
        return;
	}
	//LR
	if(balanceFactor>1 && BalanceFactor(parent->left)<0){
        LR(parent);
        return;
	}
	//RL
	if(balanceFactor<-1 && BalanceFactor(parent->right)>0){
        RL(parent);
        return;
	}
}

void PreOrder(AVLTree t){
    if(t){
        cout<<t->data<<" ";
        PreOrder(t->left);
        PreOrder(t->right);
    }
}

void InOrder(AVLTree t){
    if(t){
        InOrder(t->left);
        cout<<t->data<<" ";
        InOrder(t->right);
    }
}

void DestroyAVL(AVLTree t){
    if(t){
        DestroyAVL(t->left);
        DestroyAVL(t->right);
        delete t;
    }
}

#endif

