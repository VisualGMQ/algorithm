//P44 25题
/*思想：和书上一样
 * 这道题的难点不仅仅在于想到将后半段逆置，还需要具体知道如何逆置
显然，时间复杂度是O(n)
*/
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

LinkList L;

void Input(){
    InitList(&L);
    int len;
    printf("please input list's length:");
    scanf("%d", &len);
    printf("input list:");
    int data;
    for(int i=0;i<len;i++){
        scanf("%d", &data);
        ListInsert(&L, Length(L), data);
    }
    //书上的算法是链表的头结点是多出来的节点，所以这里头插法一个-1
    ListInsert(&L, 0, -1);
    PrintList(L);
}

void ProcessList(){
    //安排好q,p指针
    Node* p = L;
    Node *q = p;
    while(q->next!=NULL){
        p = p->next;
        q = q->next;
        if(q->next!=NULL)
            q = q->next;
    }
    //开始逆置
    q = p->next;
    p->next = NULL;
    Node* r;
    while(q!=NULL){
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    //开始交替插入
    Node* s;
    s = L->next;
    q = p->next;
    p->next = NULL;
    while(q!=NULL){
        r = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q = r;
    }
    PrintList(L);
}

void Free(){
    DestroyList(&L);
}

int main(int argc, char** argv){
    Input();
    ProcessList();
    Free();
    return 0;
}

