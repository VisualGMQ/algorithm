//注：静态链表的编写方法并不是书上讲的那么简单。具体请见这篇博客：
//https://www.cnblogs.com/rookiefly/p/3447982.html
#ifndef STATIC_LINKLIST
#define STATIC_LINKLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_SIZE 50

typedef int ElemType;

typedef struct{
    ElemType data;
    int next;
}SLinkList[MAX_SIZE];

//实现自己的malloc和free函数
int mallocNode(SLinkList L){
    int pos = L[0].next;
    if(pos==0)
        return false;
    L[0].next = L[pos].next;
    return pos;
}

void freeNode(SLinkList L, int i){
    L[i].next = L[0].next;
    L[0].next = i;
}

bool InitList(SLinkList L){
    for(int i=0;i<MAX_SIZE-2;i++)
        L[i].next = i+1;
    //指向头结点的节点，赋值为0表示现在是空的
    L[MAX_SIZE-1].next = 0;
    //备用链表的最后一个节点为0
    L[MAX_SIZE-2].next = 0;
    return true;
}

int GetElem(SLinkList L, int i){
    int node = L[MAX_SIZE-1].next;
    while(i!=0){
        if(node==0)
            assert(0);
        node = L[node].next;
        i--;
    }
    return L[node].data;
}

//这个函数就直接返回节点在数组中的索引了，而不是在链表中的第几个节点
int LocateElem(SLinkList L, ElemType e){
    int node = L[MAX_SIZE-1].next;
    while(node!=0){
        if(L[node].data==e)
            return node;
        node = L[node].next;
    }
    return false;
}

bool ListInsert(SLinkList L, int i, ElemType e){
    int node = L[MAX_SIZE-1].next;
    int new_node = mallocNode(L);
    int prev_node = -1;
    if(new_node==-1)
        return false;
    while(i!=0){
        if(node==0)
            return false;
        prev_node = node;
        node = L[node].next;
        i--;
    }
    L[new_node].data = e;
    if(prev_node==-1){ //头插法
        L[new_node].next = 0;
        L[MAX_SIZE-1].next = new_node;
        return true;
    }
    //非头插法
    L[new_node].next = node;
    L[prev_node].next = new_node;
    return true;
}

bool ListDelete(SLinkList L, int i, ElemType* e){
    int node = L[MAX_SIZE-1].next;
    int prev_node = -1;
    while(i!=0){
        if(node==0)
            return false;
        prev_node = node;
        node = L[node].next;
        i--;
    }
    if(prev_node==-1){  //删除的是头结点
        L[MAX_SIZE-1].next = L[node].next;
        L[node].next = L[0].next;
        L[0].next = node;
        return true;
    }
    //删除的非头结点
    L[prev_node].next = L[node].next;
    L[node].next = L[0].next;
    L[0].next = node;
    return true;
}

bool Empty(SLinkList L){
    return L[MAX_SIZE-1].next==0;
}

void PrintList(SLinkList L){
    int node = L[MAX_SIZE-1].next;
    printf("[");
    while(node!=0){
        printf("%3d", L[node].data);
        node = L[node].next;
    }
    printf("]\n");
}

int Length(SLinkList L){
    int node = L[MAX_SIZE-1].next;
    int count = 0;
    while(node!=0){
        count++;
        node = L[node].next;
    }
    return count;
}

void DestroyList(SLinkList L){
    for(int i=0;i<MAX_SIZE-2;i++)
        L[i].next = i+1;
    L[MAX_SIZE-1].next = 0;
    L[MAX_SIZE-2].next = 0;
}

#endif
