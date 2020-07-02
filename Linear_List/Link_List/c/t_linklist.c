#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int main(int argc, char** argv){
    LinkList L;
    printf("init list\n");
    //初始化列表
    InitList(&L);
    PrintList(L);
    //插入5个元素
    printf("insert 5 elements\n");
    ListInsert(&L, 0, 3);   //头插法
    ListInsert(&L, 1, 4);   //尾插法
    ListInsert(&L, 1, 2);   //在中间插入
    ListInsert(&L, 1, 1);   //在中间插入
    ListInsert(&L, 2, 8);   //在中间插入
    PrintList(L);
    //使用递归方式打印
    printf("use recursive way to print:\n");
    PrintList2(L);
    printf("\n");
    //打印出当前长度
    printf("List length:%d\n", Length(L));
    //得到第二个节点的值
    printf("the node at pos 2:%d\n", GetElem(L, 2));
    //得到元素8所在的位置
    printf("the 8's position:%d\n", LocateElem(L, 8));
    //删除头部节点
    printf("delete head\n");
    ListDelete(&L, 0, NULL);
    PrintList(L);
    //删除尾部节点
    printf("delete tail\n");
    ListDelete(&L, Length(L)-1, NULL);
    PrintList(L);
    //删除中间节点
    printf("delete node at pos 2\n");
    ListDelete(&L, 2, NULL);
    PrintList(L);
    //删除链表
    printf("delete linklist\n");
    DestroyList(&L);
    PrintList(L);
    printf("the linklist is empty?%s\n", Empty(L)?"Yes":"No");
    return 0;
}

