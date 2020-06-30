#ifndef DYNAMIC_SEQLIST
#define DYNAMIC_SEQLIST

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#define INIT_SIZE 10
#define INC_SIZE 5
typedef int ElemType;

typedef struct{
    ElemType* data;
    int length;
    int max_size;
}DynamicSeqList;

bool InitList(DynamicSeqList* L){
    L->data= (ElemType*)malloc(sizeof(ElemType)*INIT_SIZE);
    if(!L->data)
        return false;
    L->length = 0;
    L->max_size = INIT_SIZE;
    return true;
}

int Length(DynamicSeqList* L){
    return L->length;
}

int LocateElem(DynamicSeqList* L, ElemType e){
    for(int i=0;i<Length(L);i++)
        if(L->data[i]==e)
            return i+1;
    return 0;
}

ElemType GetElem(DynamicSeqList* L, int i){
    if(!L || i<1 || i>Length(L))
        assert(0);  //如果出错直接停止程序
    return L->data[i-1];
}

bool ListInsert(DynamicSeqList* L, int i, ElemType e){
    if(!L || i<1 || i>L->length+1)
        return false;
    if(Length(L)==L->max_size){
        int new_size = L->max_size+INC_SIZE;
        ElemType* newdatas = (ElemType*)malloc(sizeof(ElemType)*new_size);
        memcpy(newdatas, L->data, sizeof(ElemType)*Length(L));
        free(L->data);
        L->data = newdatas;
        L->max_size = new_size;
    }
    for(int j=Length(L);j>=i;j--)
        L->data[j] = L->data[j-1];
    L->data[i-1] = e;
    L->length++;
    return true;
}

bool ListDelete(DynamicSeqList* L, int i, ElemType* e){
    if(!L|| i<1 || i>L->length || L->length==0)
        return false;
    for(int j=i-1;j<Length(L)-1;j++)
        L->data[j] = L->data[j+1];
    L->length--;
    return true;
}

bool PrintList(DynamicSeqList* L){
    if(!L)
        return false;
    printf("max size:%d length:%d\t[", L->max_size, Length(L));
    for(int i=0;i<L->length;i++)
        printf("%3d", L->data[i]);
    printf("]\n");
    return true;
}

bool Empty(DynamicSeqList* L){
    return Length(L)==0;
}

bool DestroyList(DynamicSeqList* L){
    if(!L)
        return false;
    free(L->data);
    L->length = 0;
    L->max_size = 0;
    return true;
}

#endif
