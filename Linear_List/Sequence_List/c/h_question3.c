//p20 2013统考真题
//这个题目说的很玄乎，其实就是一句话：找到数组A中重复次数大于n/2的数字，没有返回-1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* A = NULL;
int n = 0;

void Input(){
    printf("input n:");
    scanf("%d", &n);
    A = (int*)malloc(sizeof(int)*n);
    printf("input A:");
    for(int i=0;i<n;i++)
        scanf("%d", &A[i]);
}

//这个算法可能只能一个一个看了。从第一个元素开始，依次统计此元素在A中出现的次数。
int FindMajorNumber(){
    for(int i=0;i<n;i++){
        int count = 1;
        for(int j=i+1;j<n;j++){
            if(A[j]==A[i])
                count++;
        }
        if(count>n/2)
            return A[i];
        else
            count = 1;
    }
    return -1;
}

void Free(){
    free(A);
}

int main(int argc, char** argv){
    Input();
    printf("major number:%d\n", FindMajorNumber());
    Free();
    return 0;
}

