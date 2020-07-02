//P43 22题
//思想：和书上答案一样
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

LinkList str1 = NULL;
LinkList str2 = NULL;

void PrintListByChar(LinkList L){
    printf("\"");
    while(L){
        printf("%c", L->data);
        L = L->next;
    }
    printf("\";\n");
}

void Init(){
    InitList(&str1);
    InitList(&str2);
    ListInsert(&str1, 0, 'g');
    ListInsert(&str1, 0, 'n');
    ListInsert(&str1, 0, 'i');
    ListInsert(&str1, 0, 'd');
    ListInsert(&str1, 0, 'a');
    ListInsert(&str1, 0, 'o');
    ListInsert(&str1, 0, 'l');
    PrintListByChar(str1);

    Node* node = str1;
    for(int i=0;i<4;i++)
        node = node->next;

    ListInsert(&str2, 0, 'e');
    ListInsert(&str2, 0, 'b');
    //将链表串成题目所给样式
    str2->next->next = node;
    PrintListByChar(str2);
}

void FindCommonNode(){
    int len1 = Length(str1);
    int len2 = Length(str2);
    Node* p1 = str1, *p2 = str2;
    int distance = abs(len2-len1);
    if(len1<len2)
        for(int i=0;i<distance;i++)
            p2 = p2->next;
    else if(len2<len1)
        for(int i=0;i<distance;i++)
            p1 = p1->next;
    int count = 0;
    while(p1!=p2){
        p1 = p1->next;
        p2 = p2->next;
        count++;
    }
    printf("common node pos:%d\n", count+distance);
}

void Free(){
    DestroyList(&str1);
    DestroyList(&str2);
}

int main(int argc, char** argv){
    Init();
    FindCommonNode();
    //这里直接释放的话会报错，因为释放了已经释放的内存。所以就不释放了，反正都考试时候也不用写这部分代码。
    //Free();
    return 0;
}

