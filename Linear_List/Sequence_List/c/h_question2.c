//这个算法的本质就是走一步看一步，通过反复比较S1和S2的内容最后得到中位数。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* S1 = NULL, *S2 = NULL;
int L = 0;

void Input(){
    printf("please input L:");
    scanf("%d", &L);
    S1 = (int*)malloc(sizeof(int)*L);
    S2 = (int*)malloc(sizeof(int)*L);
    printf("input S1:");
    for(int i=0;i<L;i++)
        scanf("%d", &S1[i]);
    printf("input S2:");
    for(int i=0;i<L;i++)
        scanf("%d", &S2[i]);
}

/*
时间复杂度：O(L)
空间复杂度：O(L) = O(1)
 */
int FindMiddle(){
    int* p[2];
    p[0] = S1;
    p[1] = S2;
    int i = *S1<*S2?0:1;    //i初值指向首元素较小的数组
    for(int j=0;j<L-1;j++){
        if( *(p[i]+1)-(*p[i]) < (*p[1-i])-(*p[i]) ){    //这里是判断当前值和下一个值的差是否小于当前值和另一个数值当前值的差,也就是说比较是当前数组的下一个数组的值更靠近当前值，还是另一个数组的值更靠近当前值。
            p[i]++; //如果是当前数组的下一个值更靠近，直接跳到下一个元素
        }else{  //否则切换到另一个数组
            p[i]++;
            i = 1-i;
        }
    }
    return *p[i];
}

void Free(){
    free(S1);
    free(S2);
}

int main(int argc, char** argv){
    Input(); 
    printf("middle:%d\n", FindMiddle());
    Free();
    return 0;
}

