//万恶的KMP算法的实现
//KMP算法的通俗解释见这个视频：https://www.bilibili.com/video/BV1jb411V78H
//KMP的详细解释可以见我的博客：
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetNextArr(const char* s, int* next, int len){
    int comp1 = -1;
    int comp2 = 0;
    next[0] = -1;
    while(comp2<len-1){
        if(comp1==-1 || s[comp1]==s[comp2]){
            next[++comp2] = ++comp1;
        }else{
            comp1 = next[comp1];
        }
    }

    //输出找到的dst数组,以方便人工确认
    for(int i=0;i<len;i++)
        printf("%3d", next[i]);
    printf("\n");
}

int KMP(const char* s1, const char* s2){
    int p1 = 0, p2 = 0; 
    int len1 = strlen(s1),
        len2 = strlen(s2);
    
    int* dst = (int*)malloc(sizeof(int)*len2);

    //得到dst数组
    GetNextArr(s2, dst, len2);

    while(p2!=len2 && p1-p2+len2<=len1){   //当s2还未超出s1的长度时，进行匹配
        if(s1[p1]==s2[p2]){ //如果当前匹配的话，直接检查下一个字符
            p1++;
            p2++;
        }else{  //如果不匹配，移动p2
            if(dst[p2]==-1){
                p1++;
                p2++;
            }else
                p2 = dst[p2];
        }
    }

    free(dst);

    //如果超出则匹配失败
    if(p1-p2+len2>len1)
        return -1;
    //否则返回匹配位置
    return p1-p2;
}


int main(int argc, char** argv){
    char buffer1[64] = {0};
    char buffer2[64] = {0};
    printf("input S1:");
    scanf("%s", buffer1);
    printf("input S2:");
    scanf("%s", buffer2);
    printf("mathcing...\n");
    printf("result:%3d\n", KMP(buffer1, buffer2));
    return 0;
}

