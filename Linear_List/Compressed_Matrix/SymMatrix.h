//行优先对称矩阵,仅存储下三角部分
#ifndef SYMMATRIX
#define SYMMATRIX
#include <stdio.h>

typedef int ElemType;

typedef struct{
    ElemType* datas;
    int len;    //对称矩阵的行列一样，都为len
}SymMatrix;

void InitMatrix(SymMatrix* m, int len){
    int totle_len = (1+len)*len/2;
    m->datas = (ElemType*)malloc(sizeof(ElemType)*totle_len);
    m->len = len;
}

void SetElement(SymMatrix* m, int row, int col, ElemType e){
    //如果行大于列，按照对称矩阵性质，寻找(row, col)的元素就相当于寻找(col, row)的元素
    if(row>col){
        int tmp = row;
        row = col;
        col = tmp;
    }
    m->datas[(row*row+row)/2+col] = e;
}

ElemType GetElement(SymMatrix* m, int row, int col){
    if(row>col){
        int tmp = row;
        row = col;
        col = tmp;
    }
    return m->datas[(row*row+row)/2+col];
}

void DestroyMatrix(SymMatrix* m){
    free(m->datas);
    m->datas = NULL;
    m->len = 0;
}

void PrintMatrix(SymMatrix* m){
    for(int i=0;i<m->len;i++){
        for(int j=0;j<m->len;j++)
            printf("%3d", GetElement(m, i, j));
        printf("\n");
    }
}

#endif

