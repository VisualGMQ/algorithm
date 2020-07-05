#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(int argc, char** argv){
    Stack s;
    InitStack(&s);
    printf("push 2, 4, 1, 3\n");
    Push(&s, 2);
    Push(&s, 4);
    Push(&s, 1);
    Push(&s, 3);
    PrintStack(&s);
    printf("pop 2 elements:\n");
    printf("pop %d\n", Pop(&s));
    printf("pop %d\n", Pop(&s));
    PrintStack(&s);
    printf("now top element is %d\n", GetTop(&s));
    DestroyStack(&s);
    return 0;
}

