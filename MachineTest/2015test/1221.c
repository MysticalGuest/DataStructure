#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int word()
{
    char sentence[SIZE];
    int num=0;
    printf("请输入一行句子：\n");
    //scanf("%s", &sentence);
    gets(sentence);
    for(int i=0; sentence[i]!='\0'; i++){
        if(sentence[i]==' ') // 以空格的个数带表单词数
            num++;
    }
    printf("%d\n", num);
    return 0;
}
