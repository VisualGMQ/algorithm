//中缀表达值转换为前缀和后缀表达式
//具体算法见这里：https://blog.csdn.net/weixin_44260779/article/details/90695746
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/signal.h>
#include "Stack.h"

char expression[128] = {0};
Stack s_value;
Stack s_opera;

void Input(){
    printf("please input a expression:");
    scanf("%s", expression);
    InitStack(&s_value);
    InitStack(&s_opera);
}

void ToSuffixExpression(){
    int i=0;
    while(expression[i]!='\0'){
        char c = expression[i];
        if(c>='a' && c<='z')
            Push(&s_value, c);
        else{
            if(StackEmpty(&s_opera) || c=='(')  //如果栈是空的或者入栈的是(，那么直接入栈
                Push(&s_opera, c);
            else if(c==')'){    //如果遇到')'，则弹出s_opera中的所有元素到s_value，直至遇见'('（左括号和右括号不用入栈）
                char top_c;
                while((top_c=Pop(&s_opera))!='('){
                    Push(&s_value, top_c);
                }
            }else if(!StackEmpty(&s_opera)){ //如果现在测操作符的优先级小于等于栈顶操作符优先级，那么栈顶操作符直接入s_value,此操作符入s_opera
                char top_c = GetTop(&s_opera);
                if(top_c=='(' || ((c=='*'||c=='/')&&(top_c=='+'||top_c=='-')))
                    Push(&s_opera, c);
                else{
                    Push(&s_value, Pop(&s_opera));
                    continue;
                }
            }
        }
        i++;
    }
    while(!StackEmpty(&s_opera))
        Push(&s_value, Pop(&s_opera));
}

void PrintPoland(){
    int n = 0;
    while(n<=s_value.top)
        printf("%c", s_value.data[n++]);
}

int main(int argc, char** argv){
    Input();
    ToSuffixExpression();
    PrintPoland();
    return 0;
}

