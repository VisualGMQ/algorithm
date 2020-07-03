#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main(int argc, char** argv){
    Queue q;
    InitQueue(&q);
    printf("enqueue 1, 2, 3, 4:\n");
    EnQueue(&q, 1);
    EnQueue(&q, 2);
    EnQueue(&q, 3);
    EnQueue(&q, 4);
    PrintQueue(&q);
    printf("dequeue 2 elements:\n");
    printf("dequeue %d\n", DeQueue(&q));
    printf("dequeue %d\n", DeQueue(&q));
    PrintQueue(&q);
    DestroyQueue(&q);
    return 0;
}

