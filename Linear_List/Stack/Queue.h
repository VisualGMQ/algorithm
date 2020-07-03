#ifndef QUEUE
#define QUEUE
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node* next;
}Node;

typedef struct{
    Node* front;
    Node* rear;
}Queue;

bool InitQueue(Queue* Q){
    if(!Q)
        return false;
    Q->front = Q->rear = (Node*)malloc(sizeof(Node));
    Q->front->next = NULL;
    return true;
}

bool IsEmpty(Queue* Q){
    return Q->front==Q->rear;
}

void EnQueue(Queue* Q, ElemType e){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = e;    
    node->next = NULL;
    Q->rear->next = node;
    Q->rear = node;
}

ElemType DeQueue(Queue* Q){
    ElemType data = Q->front->next->data;
    Node* front = Q->front;
    Q->front = Q->front->next;
    free(front);
    return data;
}

void DestroyQueue(Queue* Q){
    Node* prev_node = Q->front;
    Node* node = Q->front;
    while(node){
        node = node->next;
        free(prev_node);
        prev_node = node;
    }
    Q->front = Q->rear = NULL;
}

void PrintQueue(Queue* Q){
    Node* node = Q->front->next;
    printf("[");
    while(node!=NULL){
        printf("%3d", node->data);
        node = node->next;
    }
    printf("]\n");
}

#endif
