#include "HalfmanTree.hpp"
#define MAX_LEN 4

int weights[MAX_LEN];
HMTree t;

void Input(){
    cout<<"please input "<<MAX_LEN<<" weights"<<endl;
    for(int i=0;i<MAX_LEN;i++)
        cin>>weights[i];
    t = CreateHMTree(weights, MAX_LEN);
}

int main(int argc, char** argv){
    Input();
    cout<<"preorder travel:"<<endl;
    PreOrder(t);
    cout<<endl;
    cout<<"inorder travel:"<<endl;
    InOrder(t);
    cout<<endl;
    DestroyHMTree(t);
    return 0;
}
