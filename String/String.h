//串的定长顺序存储，动态的一个道理
//Index()函数不实现，另有文件实现KMP算法。
#ifndef MY_STRING
#define MY_STRING
#define MAX_LEN 50
#include <stdbool.h>
#include <stdio.h>

typedef struct{
    char ch[MAX_LEN];
    int length;
}String;

void StrAssign(String* s, const char* chars){
    int i = 0;
    for(;chars[i]!='\0';i++)
        s->ch[i] = chars[i];
    s->length = i;
}

//对应C语言库里面的strcpy()
void StrCopy(String* dst, String* src){
    int i = 0;
    while(i<src->length){
        dst->ch[i] = src->ch[i];
        i++;
    }
    dst->length = src->length;
}

bool StrEmpty(String* dst){
    return dst->length==0;
}

//对应C语言库的strlen()
int StrLength(String* s){
    return s->length;
}

//类似于类库的strstr()
String SubString(String* src, int pos, int len){
    String s;
    for(int i=0;pos<=len;pos++,i++)
        s.ch[i] = src->ch[pos];
    s.length = len;
    return s;
}

//对应库中的strcat()
void Concat(String* ret, String* s1, String* s2){
    StrCopy(ret, s1);
    int i = ret->length;
    for(int j=0;j<s2->length;j++,i++)
        ret->ch[i] = s2->ch[j];
    ret->length = s1->length+s2->length;
}

void ClearString(String* s){
    s->length = 0;
}

void PrintString(String* s){
    for(int i=0;i<s->length;i++)
        printf("%c", s->ch[i]);
    printf("\n");
}

#endif
