#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int string_statistics()
{
    char s[SIZE];
    int a=0; // ��ʾӢ����ĸ�ĸ���
    int b=0; // ��ʾ�ո�ĸ���
    int c=0; // ��ʾ���ֵĸ���
    int d=0; // ��ʾ�����ַ��ĸ���
    printf("������һ���ַ���\n");
    /*
    �������ǣ�
    �������ַ�����i love you
    ��������i

    ���ǿ�����������ǡ�i love you�����������ֻ�С�i����
    ԭ����ϵͳ���ո���Ϊ�����ַ���֮��ķָ�����
    Ҳ����˵��ֻҪһ���á��ո�ϵͳ����Ϊ��ǰ���ַ����Ѿ�������
    ���������������һ���ַ���������ֻ�Ὣ�ո�֮ǰ���ַ����洢������õ��ַ������С�
    */
    //scanf("%s", s); // ���Բ���scanf,��gets()
    gets(s);
    for(int i=0; i<strlen(s); i++){
        printf("%c\n", s[i]);
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
            a++;
        else if(s[i]==' ') // �ո��ʾ
            b++;
        else if(s[i]>='0'&&s[i]<='9')
            c++;
        else
            d++;
    }
    printf("%d %d %d %d\n", a, b, c, d);
    return 0;
}
