//P151 19题
//思路：思路很简单，就是深度遍历树，在遍历的时候记录下走过的路径长度，最后沿着树返回即可
#include <iostream>
#include "BinaryTree.hpp"
using namespace std;

BinTree t;

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

int getWPL(BinNode* n, int sum){
    if(!n->left && !n->right){
        return sum+n->data;
    }
    int n1 = 0, n2 = 0;
    if(n->left)
        n1 = getWPL(n->left, n->data+sum);
    if(n->right)
        n2 = getWPL(n->right, n->data+sum);
    return n1+n2;

}

int GetWPL(BinTree t){
    return getWPL(t, 0);
}

int main(int argc, char** argv){
    CreateTree();
    cout<<GetWPL(t)<<endl;
    DestroyTree(t);
    return 0;
}

