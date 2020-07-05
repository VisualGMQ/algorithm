#include <stdio.h>
#include <stdlib.h>
#include "String.h"

int main(int argc, char** argv){
    String s;
    StrAssign(&s, "hello world.");
    PrintString(&s);
    printf("string is empty?%s\n", StrEmpty(&s)?"Yes":"No");
    printf("the sub string from 0 to 3 of 'hello world' is:\n");
    String tmp = SubString(&s, 0, 3);
    PrintString(&tmp);
    printf("concat s and tmp\n");
    String concat;
    Concat(&concat, &s, &tmp);
    PrintString(&concat);
    printf("clear string s\n");
    ClearString(&s);
    printf("string is empty?%s\n", StrEmpty(&s)?"Yes":"No");
    return 0;
}

