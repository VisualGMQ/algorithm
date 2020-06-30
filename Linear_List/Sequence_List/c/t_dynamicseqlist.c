#include <stdio.h>
#include <stdlib.h>
#include "DynamicSeqList.h"

int main(int argc, char** argv){
    DynamicSeqList L;
    //初始化列表
    InitList(&L);
    //插入元素,头插法
    for(int i=0;i<5;i++)
        ListInsert(&L, 1, i);
    printf("inserted 5 elements:\n");
    PrintList(&L);
    //在尾部插入元素
    ListInsert(&L, Length(&L)+1, 6);
    printf("inserted 6 at tail:\n");
    PrintList(&L);
    //查找元素4所在位置
    printf("find element 4's pos:%d\n", LocateElem(&L, 4));
    //找到位置4所在的元素
    printf("find element at position 4:%d\n", GetElem(&L, 4));
    //删除中间元素
    printf("delete element at position 3\n");
    ListDelete(&L, 3, NULL);
    PrintList(&L);
    //删除头元素
    printf("delete head\n");
    ListDelete(&L, 1, NULL);
    PrintList(&L);
    //删除尾元素
    printf("delete tail\n");
    ListDelete(&L, Length(&L), NULL);
    PrintList(&L);

    //删除列表
    printf("delete list\n");
    DestroyList(&L);
    PrintList(&L);
    return 0;
}

