#include <stdio.h>
#include <stdlib.h>

#define SIZE 255

int string_replace()
{
    char a[SIZE], b[SIZE], c[SIZE];
    int star, end; // ��¼b��a�г��ֵ���ʼ�±�
    printf("��ֱ�����3���ַ�����\n");
    gets(a);
    gets(b);
    gets(c);
    for(int i=0; i<strlen(a); i++)

    printf("%s\n", a);
    printf("%s\n", b);
    printf("%s\n", c);
    return 0;
}
