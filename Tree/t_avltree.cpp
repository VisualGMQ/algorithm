#include "AVL.hpp"
#define MAX_LEN 10

AVLTree t = nullptr;

void Input(){
    cout<<"please input 10 elements"<<endl;
    int n;
    for(int i=0;i<MAX_LEN;i++){
        cin>>n;
        Insert(&t, n);
    }
}

int main(int argc, char** argv){
    Input();
    cout<<"Preorder:"<<endl;
    PreOrder(t);
    cout<<endl;
    cout<<"InOrder:"<<endl;
    InOrder(t);
    cout<<endl;
    DestroyAVL(t);
    return 0;
}

