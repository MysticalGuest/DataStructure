#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct{
    float data[SIZE];
    int top;
}NStack;

typedef struct{
    char data[SIZE];
    int top;
}CStack;

float compute(char exp[]){
    char num[10]; // ��ȡ����
    NStack ns;
    ns.top=-1
    CStack cs;
    cs.top=-1;
    int flag=0; // û�г���С����
    for(int i=0; exp[i]!='\0'; i++){ // �����ַ���
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){

        }
        if(exp[i+1]!='\0'){ // ����С���Ͷ�λ��
            while(exp[i+1]!='+'&&exp[i+1]!='-'&&exp[i+1]!='*'&&exp[i+1]!='/'){ //��λ����С��
                if(exp[])
            }
        }
    }
}

int calculator()
{
    int n;
    float result[SIZE]; // ������м�����
    char exp[SIZE];
    printf("����������:\n");
    scanf("%d", &n);
    fflush(stdin);
    printf("������ʽ:\n");
    for(int i=0; i<n; i++){
        gets(exp);
        result[i]=compute(exp);
    }
    for(int i=0; i<n; i++){
        printf("%.2f\n", result[i]);
    }
    return 0;
}
