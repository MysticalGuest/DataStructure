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
    char num[10]; // 提取数字
    NStack ns;
    ns.top=-1
    CStack cs;
    cs.top=-1;
    int flag=0; // 没有出现小数点
    for(int i=0; exp[i]!='\0'; i++){ // 处理字符串
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){

        }
        if(exp[i+1]!='\0'){ // 处理小数和多位数
            while(exp[i+1]!='+'&&exp[i+1]!='-'&&exp[i+1]!='*'&&exp[i+1]!='/'){ //多位数或小数
                if(exp[])
            }
        }
    }
}

int calculator()
{
    int n;
    float result[SIZE]; // 存放所有计算结果
    char exp[SIZE];
    printf("请输入行数:\n");
    scanf("%d", &n);
    fflush(stdin);
    printf("输入表达式:\n");
    for(int i=0; i<n; i++){
        gets(exp);
        result[i]=compute(exp);
    }
    for(int i=0; i<n; i++){
        printf("%.2f\n", result[i]);
    }
    return 0;
}
