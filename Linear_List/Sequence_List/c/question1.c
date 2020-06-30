#include <stdio.h>
#include <stdlib.h>
#include "StaticSeqList.h"
StaticSeqList L;

void Input(){
    printf("please input 5 numbers:");
    for(int i=0;i<Length(&L);i++)
        scanf("%d", L.data[i]);
}

int main(int argc, char** argv){
    InitList(&L);
    //输入5个数字
    Input();
    PrintList(&L);

    DestroyList(&L);
    return 0;
}
