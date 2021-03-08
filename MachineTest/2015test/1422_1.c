#include <stdio.h>
#include <stdlib.h>

int binary_printf(){
    int a,b,k,i;
    int remainder[30];
    while(1){
        //定义了一个remainder数组，用来收集短除法除得的余数，栈倒序输出。
        printf("请输入一个十进制数:  ");
        scanf("%d",&a);
        k=0;
        while(a!=0){
            b=a/2;
            k++;
            remainder[k]=a-b*2;
            a=a/2;
        };
        printf("转换成二进制数是:  ");
        for (i=k; i>=1; i--)
        {
            printf("%d",remainder[i]);
        }
        printf("\n\n");
    }
    return 0;
}

/*
    在C语言中，打印16进制可以使用printf的%x格式。
    打印二进制数并没有现成的格式数值，只能自行编写函数打印。
    以下是一个打印二进制值的函数，通过位操作，逐位判断二进制值，并输出对应的值。
    默认高位0不输出。
*/
void print_bin(int n)
{
    int l = sizeof(n)*8; //总位数。
    int i=n;
    if(i == 0){
         printf("0");
         return;
    }
    for(i = l-1; i >= 0; i --) //略去高位0.
    {
        if(n&(1<<i)) break;
    }

    for(;i>=0; i --)
        printf("%d", (n&(1<<i)) != 0);
}
