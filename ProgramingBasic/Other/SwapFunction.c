#include<stdio.h>
void swap(float a,float b);                    //声明swap函数

void main()
{    float m,n;
     printf("请输入一个实数m=");
	 scanf("%f",&m);
     //printf("\n");
	 printf("请输入一个实数n=");
	 scanf("%f",&n);
	 swap(m,n);                                //调用swap函数
	 }

void swap(float a,float b)
	 {float c;
	 c=a;
	 a=b;
	 b=c;
	 printf("m,n交换值后m=%f,n=%f\n",a,b);
	 }
