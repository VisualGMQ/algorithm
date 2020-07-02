//P42 21题
//算法思想：和书上的解答一样
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

LinkList L = NULL;
int k = 100;

void Input(){
    InitList(&L);
    printf("please input 10 integer:");
    for(int i=0;i<10;i++){
        int i;
        scanf("%d", &i);
        ListInsert(&L, 0, i);
    }
    printf("list:\n");
    PrintList(L);
    while(k>=10){
        printf("please input k(<10):");
        scanf("%d", &k);
    }
}

void FindNode(){
    Node* p1 = L;
    Node* p2 = NULL;
    int count = 0;
    while(p1!=NULL){
        count++;
        p1 = p1->next;
        if(count==k+1){
            p2 = L;
        }
        if(p2!=NULL)
            p2 = p2->next;
    }
    printf("the %d node is %d\n", k, p2->data);
}

void Free(){
    DestroyList(&L);
}

int main(int argc, char** argv){
    Input();
    FindNode();
    Free();
    return 0;
}

