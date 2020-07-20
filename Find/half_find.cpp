//折半查找只能用在排好序的数组上面
#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];

void Input(){
    cout<<"please input 10 integers in increasing order:";
    for(int i=0;i<10;i++)
        cin>>arr[i];
}

int HalfFind(){
    cout<<"you want to find:";
    int num;
    cin>>num;

    int i = 0, j = 10;
    while(i<=j){
        int middle = (i+j)/2;
        if(arr[middle]==num)
            return middle;
        if(arr[middle]<num)
            i = middle+1;
        else
            j = middle-1;
    }
    return -1;
}

int main(int argc, char** argv){
    Input();
    int idx = HalfFind();
    if(idx==-1)
        cout<<"don't have this value"<<endl;
    else
        cout<<"in position "<<idx<<endl;
    return 0;
}
