#ifndef STATIC_SEQLIST
#define STATIC_SEQLIST

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define MAX_SIZE 50
typedef int ElemType;

typedef struct{
    ElemType data[MAX_SIZE];
    int length;
}StaticSeqList;

bool InitList(StaticSeqList* L){
    if(!L)
        return false;
    L->length = 0; 
    return true;
}

int Length(StaticSeqList* L){
    return L->length;
}

int LocateElem(StaticSeqList* L, ElemType e){
    for(int i=0;i<Length(L);i++)
        if(L->data[i]==e)
            return i+1;
    return 0;
}

ElemType GetElem(StaticSeqList* L, int i){
    if(!L || i<1 || i>Length(L))
        assert(0);  //如果出错直接停止程序
    return L->data[i-1];
}

bool ListInsert(StaticSeqList* L, int i, ElemType e){
    if(!L || i<1 || i>L->length+1 || L->length==MAX_SIZE)
        return false;
    for(int j=Length(L);j>=i;j--)
        L->data[j] = L->data[j-1];
    L->data[i-1] = e;
    L->length++;
    return true;
}

bool ListDelete(StaticSeqList* L, int i, ElemType* e){
    if(!L|| i<1 || i>L->length || L->length==0)
        return false;
    if(e)
        *e = L->data[i];
    for(int j=i-1;j<Length(L)-1;j++)
        L->data[j] = L->data[j+1];
    L->length--;
    return true;
}

bool PrintList(StaticSeqList* L){
    if(!L)
        return false;
    printf("length:%d\t[", Length(L));
    for(int i=0;i<L->length;i++)
        printf("%3d", L->data[i]);
    printf("]\n");
    return true;
}

bool Empty(StaticSeqList* L){
    return Length(L)==0;
}

bool DestroyList(StaticSeqList* L){
    if(!L)
        return false;
    L->length = 0;
    return true;
}

#endif
