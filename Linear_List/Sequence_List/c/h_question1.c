//p20 2010统考真题
//设计思想：使用顺序表结构，循环左移n位其实就是删除头结点并将其插入尾部n次。这个过程可以简化为将头部删除并直接在尾部放置头部数据n次
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n = 0;
int p = 0;
int* array = NULL;

void Input(){
    printf("please input n:");
    scanf("%d", &n);
    array = (int*)malloc(sizeof(int)*n);
    printf("please input n integers:");
    for(int i=0;i<n;i++)
        scanf("%d", &array[i]);
    printf("please input p:");
    scanf("%d", &p);
}

/*
第一种解法:循环删除n次头部并且将删除的头部放到末尾。
空间复度：O(1) 
时间复杂度：O(np)
*/
void Rol1(){
    for(int i=0;i<p;i++){
        int head = array[0];
        for(int j=0;j<n-1;j++)
            array[j] = array[j+1];
        array[n-1] =  head;
    }
}

/*
第二种解法：将前p个数字保存下来，然后一次性平移p个长度，再将数据附着到末尾
空间复杂度：O(p)
时间复杂度：O(n)

在真正实践的时候，如果数据量比较小的话，这个方法其实比Rol1要慢，因为创建新数组的malloc函数是很耗时间的函数。而且创建之后还要free。
在p较小的情况下重复使用这个函数和Rol1函数，可以很明显发现malloc所带来的性能差距。
*/
void Rol2(){
    int* tmp_arr = (int*)malloc(sizeof(int)*p);
    memcpy(tmp_arr, array, sizeof(int)*p);
    for(int i=0;i<n-p;i++)
        array[i] = array[i+p];
    for(int i=n-p;i<n;i++){
        array[i] = tmp_arr[i-(n-p)];
    }
    free(tmp_arr);
}

void Print(){
    for(int i=0;i<n;i++)
        printf("%2d", array[i]);
    printf("\n");
}

void Free(){
    free(array);
}

int main(int argc, char** argv){
    //输入数据并初始化数组
    Input();
    //循环左移
    Rol2();
    //打印结果
    Print();
    //回收内存
    Free();
    return 0;
}

