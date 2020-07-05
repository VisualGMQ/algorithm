//采用十字链表实现的稀疏矩阵(本质上是十字链表中存储着矩阵元素，所以这里结构体就不命名为矩阵了)
//有关十字链表的知识点见这里：http://data.biancheng.net/view/186.html
//参考网页中并没有给出释放链表内存的方法。但是释放内存也很简单：按行释放或者按列释放。
//以按行释放为例：将每一行看做一个单独的链表（不要管节点的down属性），然后使用链表的删除删除每一行的链表即可。
//最后再删除chead元素。
#ifndef SPARSEMATRIX
#define SPARSEMATRIX
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef int ElemType;

typedef struct OLNode{
    int row;
    int col;
    ElemType data;
    struct OLNode* right;
    struct OLNode* down;
}OLNode;

typedef struct{
    OLNode* rhead;
    OLNode* chead;
    int row;    //rhead的长度
    int col;    //chead的长度
    int count;  //元素个数
}CrossList;

void InitCrossList(CrossList* l, int row, int col){
    l->rhead = (OLNode*)malloc(sizeof(OLNode)*row+1);
    l->chead = (OLNode*)malloc(sizeof(OLNode)*col+1);
    l->row = row;
    l->col = col;
    l->count = 0;
    for(int i=0;i<row+1;i++){
        l->rhead[i].right = l->rhead[i].down= NULL;
        l->rhead[i].row = i;
        l->rhead[i].col = -2;
    }
    for(int i=0;i<col+1;i++){
        l->chead[i].right = l->chead[i].down= NULL;
        l->chead[i].col = i;
        l->chead[i].row = -2;
    }       
}

void InsertElement(CrossList* l, int row, int col, ElemType e){
    OLNode* prev_row_node = &l->rhead[row],
            *prev_col_node = &l->chead[col],
            *row_node = prev_row_node->right,
            *col_node = prev_col_node->down;
    while(row_node!=NULL && row_node->col<col){
        prev_row_node = row_node;
        row_node = row_node->right;
    }
    OLNode* newnode = NULL;
    if(row_node==NULL || row_node->col!=col){
        newnode = (OLNode*)malloc(sizeof(OLNode));
        newnode->row = row;
        newnode->col = col;
        newnode->data = e;
        prev_row_node->right = newnode;
        newnode->right = row_node;
        l->rhead[row].data = -1;
    }else{
        row_node->data = e;
        return;
    }
    while(col_node!=NULL && col_node->row<row){
        prev_col_node = col_node;
        col_node = col_node->down;
    }
    prev_col_node->down = newnode;
    newnode->down = col_node;
    l->chead[col].data = -1;
}

ElemType GetElement(CrossList* l, int row, int col){
    OLNode* row_node = &l->rhead[row];
    while(row_node!=NULL && row_node->col<col)
        row_node = row_node->right;
    if(row_node==NULL)
        return 0;
    if(row_node->col==col)
        return row_node->data;
    return 0;
}

void DestroyNode(OLNode* n){
    if(n!=NULL){
        DestroyNode(n->right);
        free(n);
    }
}

void DestroyCrossList(CrossList* l){
    for(int i=0;i<l->row;i++)
        DestroyNode(l->rhead[i].right);
    free(l->rhead);
    free(l->chead);
}

void PrintCrossList(CrossList* l){
    for(int i=0;i<l->row;i++){
        for(int j=0;j<l->col;j++)
            printf("%3d", GetElement(l, i, j));
        printf("\n");
    }
}

#endif
