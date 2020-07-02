//P43 23题
//思想：和书上一样，这里的辅助数组使用哈希表（数组的下标代表出现的数字，如果为1代表出现了这个数字，为0代表没出现）
//一般来说，如果题目不要求空间尽可能小，就需要考虑用哈希表加快查找速度（因为哈希表的查找是最快的，之要一个单位时间即可）
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

LinkList L;
int n;
int *hash = NULL;   //哈希表

void Input(){
    InitList(&L);
    printf("plese input n:");
    scanf("%d", &n);
    hash = (int*)malloc(sizeof(int)*n);
    memset(hash, 0, sizeof(int)*n);
    printf("please input 10 integers( |integer|<=n ):");
    int data;
    for(int i=0;i<10;i++){
        scanf("%d", &data);
        ListInsert(&L, Length(L), data);
    }
    PrintList(L);
}

void DropSameNodeByAbs(){
    Node* node = L;
    Node* prev_node = node;
    while(node!=NULL){
        if(hash[abs(node->data)]==0){ //如果为0表示这个元素还没有出现
            hash[abs(node->data)] = 1;
            prev_node = node;
            node = node->next; 
        }else{   //如果出现了，删除当前节点
            prev_node->next = node->next;
            free(node);
            node = prev_node->next;
        }
    }
    PrintList(L);
}

void Free(){
    free(hash);
    DestroyList(&L);
}

int main(int argc, char** argv){
    Input();
    DropSameNodeByAbs();
    Free();
    return 0;
}

