#include <stdio.h>
#include <stdlib.h>
#include "SymMatrix.h"

int main(int argc, char** argv){
    SymMatrix m;
    InitMatrix(&m, 3);

    SetElement(&m, 0, 1, 1);
    SetElement(&m, 1, 0, 2);
    SetElement(&m, 1, 1, 3);
    SetElement(&m, 1, 2, 4);


    printf("Get row:2, col:1 element:%d\n", GetElement(&m, 2, 1));
    PrintMatrix(&m);

    DestroyMatrix(&m);
    return 0;
}

