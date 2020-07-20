#include <iostream>
using namespace std;

int arr[10];

void Input(){
    cout<<"please input 10 integers:";
    for(int i=0;i<10;i++)
        cin>>arr[i];
}

int LinearFind(){
    cout<<"you want to find:";
    int num;
    cin>>num;
    for(int i=0;i<10;i++)
        if(arr[i]==num)
            return i;        
    return -1;
}

int main(int argc, char** argv){
    Input();
    int idx = LinearFind();
    if(idx==-1)
        cout<<"don't have this value"<<endl;
    else
        cout<<"in position "<<idx<<endl;
    return 0;
}
