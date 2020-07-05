//顺序栈的实现
//这里对于栈溢出情况我就不做错误处理了
#ifndef STACK
#define STACK
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 50

typedef int ElemType;

typedef struct{
    ElemType data[MAX_SIZE];
    int top;
}Stack;

bool InitStack(Stack* S){
    S->top = -1;
    return true;
}

bool StackEmpty(Stack* S){
    return S->top==-1;
}

void Push(Stack* S, ElemType e){
    S->data[++S->top] = e;
}

ElemType Pop(Stack* S){
    return S->data[S->top--];
}

ElemType GetTop(Stack* S){
    return S->data[S->top];
}

void DestroyStack(Stack* S){
    S->top = -1;
}

void PrintStack(Stack* S){
    int i = S->top;
    printf("[");
    while(i>=0){
        printf("%3d", S->data[i]);
        i--;
    }
    printf("]\n");
}

#endif
