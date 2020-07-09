#include <iostream>
#include "BST.hpp"
using namespace std;

int main(int argc, char** argv){
    BinTree t = NULL;
    cout<<"you want add how many elements?";
    int n;
    cin>>n;
    cout<<"input your elements:";
    for(int i=0;i<n;i++){
        ElemType e;
        cin>>e;
        AddElement(&t, e);
    }

    cout<<"preorder visit:"<<endl;
    PreOrder(t);
    cout<<endl;
    cout<<"inorder visit:"<<endl;
    InOrder(t);
    cout<<endl;
    cout<<"postorder visit:"<<endl;
    PostOrder(t);
    cout<<endl;

    cout<<"please input the element you want to find:";
    int elem;
    cin>>elem;
    BinNode* node = FindElement(&t, elem);
    cout<<(node?"Found":"Not Found")<<endl;

    cout<<"delete an element:";
    cin>>elem;
    DelElement(&t, elem);

    cout<<"preorder visit:"<<endl;
    PreOrder(t);
    cout<<endl;
    cout<<"inorder visit:"<<endl;
    InOrder(t);
    cout<<endl;
    cout<<"postorder visit:"<<endl;
    PostOrder(t);
    cout<<endl;

    DestroyTree(t);
    return 0;
}

