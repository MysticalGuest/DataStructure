#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int word()
{
    char sentence[SIZE];
    int num=0;
    printf("������һ�о��ӣ�\n");
    //scanf("%s", &sentence);
    gets(sentence);
    for(int i=0; sentence[i]!='\0'; i++){
        if(sentence[i]==' ') // �Կո�ĸ�����������
            num++;
    }
    printf("%d\n", num);
    return 0;
}
