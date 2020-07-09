//P151 20题
//思路：送分题，学过编译原理的都知道这就是执行语法分析树的过程。思路很简单，中序遍历树，在遍历到左节点后输出左括号，右节点后输出右括号即可
#include <iostream>
#include "BinaryTree.hpp"
using namespace std;

BinTree t;

/*
创造一颗这样的树
      *
     / \
    +   /
   / \  |\
  -   - c -
 /     \  |
a       b e

对应算式((-a)+(-b))*(c/(-e))
*/
void CreateTree(){
    BinNode** nodes;
    nodes = new BinNode*[10];
    for(int i=0;i<10;i++)
        nodes[i] = new BinNode[10];
    AssignNode(nodes[1], '*', nodes[3], nodes[2]);
    AssignNode(nodes[3], '+', nodes[6], nodes[0]);
    AssignNode(nodes[2], '/', nodes[8], nodes[4]);
    AssignNode(nodes[6], '-', nodes[9], nullptr);
    AssignNode(nodes[0], '-', nullptr, nodes[5]);
    AssignNode(nodes[8], 'c', nullptr, nullptr);
    AssignNode(nodes[4], '-', nodes[7], nullptr);
    AssignNode(nodes[9], 'a', nullptr, nullptr);
    AssignNode(nodes[5], 'b', nullptr, nullptr);
    AssignNode(nodes[7], 'e', nullptr, nullptr);
    t = nodes[1];
    delete[] nodes;
}

void PrintExpression(BinNode* n){
    //如果是叶子节点，代表这个节点是变量，直接输出
    if(!n->left && !n->right){
        cout<<n->data;
        return;
    }
    //如果有两个孩子，代表是双参数操作符，那么先输出左孩子，然后是自己，然后是右孩子，并且加上括号
    if(n->left && n->right){
        cout<<"(";
        PrintExpression(n->left);
        cout<<(char)n->data;
        PrintExpression(n->right);
        cout<<")";
    }else if(n->left){  //如果只有一个孩子，代表是单参数操作符，那么先输出自己，再输出孩子，并且加上括号
        cout<<"("<<(char)n->data;
        PrintExpression(n->left);
        cout<<")";
    }else if(n->right){
        cout<<"("<<(char)n->data;
        PrintExpression(n->right);
        cout<<")";
    }

}

int main(int argc, char** argv){
    CreateTree();
    PrintExpression(t);
    DestroyTree(t);
    return 0;
}
