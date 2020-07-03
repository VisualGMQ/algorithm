//按照书上的写法，循环队列必须必原定的大小多1，以方便判断队列是否满了
//也就是说如果数组有11个元素，队列最大长度只能到10
//因为rear是指向队尾元素的下一位的，所以如果队满了，那么rear==front。这个判断条件同时也是队空的情况，所以就没有办法分清满和空的区别
//所以要多加一个空间，并用(rear+1)%MAX_SIZE==front的方式判满
#ifndef CIRCLE_QUEUE
#define CIRCLE_QUEUE
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
//为了测试循环队列的特性，将最大值改小了
#define MAX_SIZE 11

typedef int ElemType;

typedef struct{
    ElemType data[MAX_SIZE];
    int front, rear;
}CircleQueue;

void InitQueue(CircleQueue* Q){
    Q->front = Q->rear = 0;
}

bool IsFull(CircleQueue* Q){
    return Q->front==(Q->rear+1)%MAX_SIZE;
}

bool EnQueue(CircleQueue* Q, ElemType e){
    if(IsFull(Q))
        return false;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1)%MAX_SIZE;
    return true;
}

bool Empty(CircleQueue* Q){
    return Q->front==Q->rear;
}

ElemType DeQueue(CircleQueue* Q){
    if(Empty(Q))
        return false;
    ElemType data = Q->data[Q->front];
    Q->front = (Q->front+1)%MAX_SIZE;
    return data;
}

void DestroyQueue(CircleQueue* Q){
    Q->front = Q->rear = 0;
}

void PrintQueue(CircleQueue* Q){
    int head = Q->front;
    printf("[");
    while(head!=Q->rear){
        printf("%3d", Q->data[head]);
        head = (head+1)%MAX_SIZE;
    }
    printf("]\n");
}

#endif
