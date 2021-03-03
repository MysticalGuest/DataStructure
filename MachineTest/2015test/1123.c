#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 255

int string_replace()
{
    char a[SIZE], b[SIZE], c[SIZE], temp[2*SIZE];
    int start=-1, end=-1; // 记录b在a中出现的起始下标,-1表示b没有出现在a中,输出原串a
    printf("请分别输入3个字符串：\n");
    gets(a);
    gets(b);
    gets(c);
    for(int i=0; i<strlen(a); i++){
        if(a[i]==b[0]){ // 开始匹配
            int j;
            for(j=0; j<strlen(b); j++){
                if(a[i+j]!=b[j])
                    break;
            }
            if(j==strlen(b)){ // 全部匹配成功
                start=i;end=i+j-1;
            }
        }
    }
    if(start==-1&&end==-1){ // b没有出现在a中,输出原串a
        printf("%s\n", a);
    }
    else{
        for(int i=0; i<=start; i++){
            temp[i]=a[i]; // 开始复制a中前面字符
        }
        for(int i=0; i<=strlen(c); i++){
            temp[i+start]=c[i]; // 开始复制b中的字符
        }
        int k=strlen(c)+start;
        for(int i=end+1; i<strlen(a); i++,k++){
            temp[k]=a[i]; // 开始复制a中剩余的字符
        }
        temp[k]='\0'; //定义temp[]没有初始化，导致temp末尾的值是未定义的，所以可能会出现？
        //printf("%s\n", temp);
        puts(temp);
    }
    return 0;
}
