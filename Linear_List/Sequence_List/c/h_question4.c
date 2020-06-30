//p21 2018年统考题
//这个题目比起前面三个还简单一些，题目要求是时间上尽可能少，那么就是以空间换时间，使用散列表方法即可。
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

int MinPositiveInt(){
    int max = 0;
    //先找到最大的数
    for(int i=0;i<n;i++)
        if(A[i]>max)
            max = A[i];
    int* B = (int*)malloc(sizeof(int)*(max+1)); //创建散列表
    memset(B, 0, sizeof(int)*max);
    for(int i=0;i<n;i++)
        if(A[i]>0)
            B[A[i]-1] = 1;
    for(int i=0;i<max+1;i++)
        if(B[i]==0){
            free(B);
            return i+1;
     }           
    free(B);
}

void Free(){
    free(A);
}

int main(int argc, char** argv){
    Input();
    printf("number:%d\n", MinPositiveInt());
    Free();
    return 0;
}

