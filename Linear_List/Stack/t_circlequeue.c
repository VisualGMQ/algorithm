#include <stdio.h>
#include <stdlib.h>
#include "CircleQueue.h"

int main(int argc, char** argv){
    CircleQueue q;
    InitQueue(&q);
    printf("enqueue 1-10:\n");
    for(int i=1;i<=10;i++)
        EnQueue(&q, i);
    PrintQueue(&q);
    printf("front:%d, rear:%d\n", q.front, q.rear);
    printf("dequeue 2 elements:\n");
    printf("dequeue %d\n", DeQueue(&q));
    printf("dequeue %d\n", DeQueue(&q));
    printf("front:%d, rear:%d\n", q.front, q.rear);
    printf("add 11, 12\n");
    EnQueue(&q, 11);
    EnQueue(&q, 12);
    PrintQueue(&q);
    printf("front:%d, rear:%d\n", q.front, q.rear);
    DestroyQueue(&q);
    return 0;
}

