//注：链表的所有操作（除了InitList和Empty）都可以用递归。这里有些方式用递归得多写一个函数，就不写了
//有些单链表的第一个元素存储着链表的长度，但是这里的不这样实现，所有的节点都表示元素,链表长度动态计算。
#ifndef LINK_LIST
#define LINK_LIST

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node* next;
}Node, *LinkList;

bool InitList(LinkList* L){
    if(!L)  //如果L是空指针
        return false;
    *L = NULL;  //初始化链表，什么也不用做
    return true;
}

int Length(LinkList L){
    if(!L)  //如果走到了链表末尾
        return 0;   //返回1
    return 1+Length(L->next);   //不然返回剩余链表的长度(1代表这个节点的长度，算一个)
}

int LocateElem(LinkList L, ElemType e){
    int pos = 0;
    while(L){
        if(L->data==e) 
            return pos;
        L = L->next;
        pos++;
    }
    return -1;  //如果找不到返回-1
}

ElemType GetElem(LinkList L, int i){
    while(i!=0){
        if(L){
            L = L->next;
            i--;
        }else
            assert(0);  //如果找不到直接报错吧，我也想不到要返回啥了
    }
    return L->data;
}

//如果Length的递归形式看不懂的话，可以考虑看看这个非递归的方式
int Length2(LinkList L){
    Node* node = L;
    int len = 0;
    while(node){
        len++;
        node = node->next;
    }
    return len;
}

bool ListInsert(LinkList* L, int i, ElemType e){
    Node* node = *L; 
    Node* prev_node = NULL; //node的前一个节点
    while(i!=0){
        if(!node)
            return false;   //如果在还没遍历到第i个节点的时候就找到NULL了，说明i超出了长度，直接返回false
        prev_node = node;
        node = node->next;
        i--;
    }
    //分配内存给新节点
    Node* newnode = (Node*)malloc(sizeof(Node));
    //将新节点插入
    newnode->data = e;
    newnode->next = node;
    if(prev_node)   //如果node的前节点不是NULL，代表不是在首部插入
        prev_node->next = newnode;
    else
        *L = newnode;   //否则说明是头插法，要更换链表头 
    return true;
}

//和ListInsert类似
bool ListDelete(LinkList* L, int i, ElemType* e){
    Node* node = *L;
    Node* prev_node = NULL;
    while(i!=0){
        if(!node)
            return false;
        prev_node = node;
        node = node->next;
        i--;
    }
    if(prev_node)
        prev_node->next = node->next;
    else
        *L = node->next;
    if(e)   //如果e不是NULL，表示我们需要被删除节点的值
        *e = node->data;
    free(node);
    return true;
}

void PrintList(LinkList L){
    Node* node = L;
    printf("[");
    while(node!=NULL){
        printf("%3d", node->data);
        node = node->next;
    }
    printf("]\n");
}

//这儿也有个递归方式的PrintList
void PrintList2(LinkList L){
    if(L){
        printf("%3d", L->data);
        PrintList2(L->next);
    }
}

bool Empty(LinkList L){
    return !L;
}

void DestroyList(LinkList* L){
    if(!L)  //如果L是空指针，直接报错
        assert(0);
    Node* node = *L;
    *L = NULL;
    while(node){
        Node* cur_node = node;
        node = node->next;
        free(cur_node);
    }
}

//同理也可以写出递归式的
void DestroyList2(LinkList* L){
    if(!L)
        assert(0);
    if(*L){
        Node* n = *L;
        *L = NULL;
        DestroyList2(&n->next);
        free(n);
    }   
}

#endif
