#include <iostream>
#include "BinaryTree.hpp"
using namespace std;
BinTree t = nullptr;

/*
创造一颗这样的树
      1
     / \
    3   2
   / \  |\
  6   0 8 4
 /     \  |
9       5 7
*/
void CreateTree(){
    BinNode** nodes;
    nodes = new BinNode*[10];
    for(int i=0;i<10;i++)
        nodes[i] = new BinNode[10];
    AssignNode(nodes[1], 1, nodes[3], nodes[2]);
    AssignNode(nodes[3], 3, nodes[6], nodes[0]);
    AssignNode(nodes[2], 2, nodes[8], nodes[4]);
    AssignNode(nodes[6], 6, nodes[9], nullptr);
    AssignNode(nodes[0], 0, nullptr, nodes[5]);
    AssignNode(nodes[8], 8, nullptr, nullptr);
    AssignNode(nodes[4], 4, nodes[7], nullptr);
    AssignNode(nodes[9], 9, nullptr, nullptr);
    AssignNode(nodes[5], 5, nullptr, nullptr);
    AssignNode(nodes[7], 7, nullptr, nullptr);
    t = nodes[1];
    delete[] nodes;
}

int main(int argc, char** argv){
    CreateTree();

    cout<<"preorder visit:"<<endl;
    PreOrder(t);
    cout<<endl;
    cout<<"inorder visit:"<<endl;
    InOrder(t);
    cout<<endl;
    cout<<"postorder visit:"<<endl;
    PostOrder(t);
    cout<<endl;
    cout<<"level visit:"<<endl;
    LevelOrder(t);
    cout<<endl;
    cout<<"have "<<NodeNumber(t)<<" nodes"<<endl;
    cout<<"have "<<Layer(t)<<" layers"<<endl;

    DestroyTree(t);
    return 0;
}

