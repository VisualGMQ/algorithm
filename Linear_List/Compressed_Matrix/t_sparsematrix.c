#include <stdio.h>
#include <stdlib.h>
#include "SparseMatrix.h"

int main(int argc, char** argv){
    CrossList l;
    InitCrossList(&l, 10, 10);

    InsertElement(&l, 2, 3, 1);
    InsertElement(&l, 2, 7, 2);
    InsertElement(&l, 7, 3, 3);
    InsertElement(&l, 3, 1, 4);
    InsertElement(&l, 3, 8, 5);
    InsertElement(&l, 9, 6, 6);

    PrintCrossList(&l);

    DestroyCrossList(&l);
    return 0;
}

