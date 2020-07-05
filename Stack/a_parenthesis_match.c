//括号匹配应用
//思想：很简单，将括号按次序压入栈，如果栈中存在和压入栈中相匹配的括号，就弹出这一对括号。重复上述步骤，直到括号全部压栈。如果此时栈里还有括号，表示存在未匹配到的括号。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include "Stack.h"
#define STRING_MAX_LEN 64

char Parenthesis[STRING_MAX_LEN] = {0};
int Len = 0;

void Input(){
    printf("please input some Parenthsis:");
    scanf("%s", Parenthesis);
    Len = strlen(Parenthesis);
}

bool IsMatch(){
    Stack s;
    InitStack(&s);
    int i = 0;
    while(i!=Len){
        int cur_c = Parenthesis[i];
        int c = GetTop(&s);
        if(!StackEmpty(&s)){
            if(c=='(' && cur_c==')')
                Pop(&s);
            else if(c=='[' && cur_c==']')
                Pop(&s);
            else if(c=='{' && cur_c=='}')
                Pop(&s);
            else if(c=='<' && cur_c=='>') 
                Pop(&s);
            else
                Push(&s, cur_c);
        }else{
            Push(&s, cur_c);
        }
        i++;
    }
    bool result = false;
    if(StackEmpty(&s))
        result = true;
    DestroyStack(&s);
    return result;
}

int main(int argc, char** argv){
    Input();
    printf("the parenthesis are matched?%s", IsMatch()?"Yes":"No");
    return 0;
}

