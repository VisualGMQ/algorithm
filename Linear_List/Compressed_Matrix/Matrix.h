//行有限的矩阵
#ifndef MATRIX
#define MATRIX
#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef int ElemType;

typedef struct{
    ElemType* datas;    
    int col;
    int row;
}Matrix;

void InitMatrix(Matrix* m, int row, int col, ElemType init_value){
    m->datas = (ElemType*)malloc(sizeof(ElemType)*row*col);
    if(!m->datas)
        assert(0);
    m->row = row;
    m->col = col;
    for(int i=0;i<row*col;i++)
        m->datas[i] = init_value;
}

ElemType GetElement(Matrix* m, int row, int col){
    return m->datas[row*m->col+col];
}

void SetElement(Matrix* m, int row, int col, ElemType value){
    m->datas[row*m->col+col] = value;
}

void DestroyMatrix(Matrix* m){
    free(m->datas);
    m->row = m->col = 0;
}

void PrintMatrix(Matrix* m){
    for(int i=0;i<m->row;i++){
        for(int j=0;j<m->col;j++)
            printf("%3d", GetElement(m, i, j));
        printf("\n");
    }
}

#endif
