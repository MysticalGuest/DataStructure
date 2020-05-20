#include<stdio.h>
#include<Windows.h>

float factorial(long int n);

void main()
{    long int n;
     printf("请输入一个整数，程序将为你计算其阶乘!\n");
     printf("n=");
     scanf("%d",&n);
	 //if(n<0)                                        //两种方法，两种函数，此处取第一个函数
	        //printf("Date Error!\n");
	 //else
		 factorial(n);
	 //printf("%d!=%lf\n",n,factorial(n));
	 system("pause");
}

float factorial(long int n)
{  
     double m;
	 if(n<0)
	 {
		 printf("Date Error!\n");
	     return 1;
	 }
	 else if(n==0||n==1)
	 {
		 printf("%d!=1\n",n);
	     return 1;
	 }
     else
	 {
		 int a;
	     a=n;
		 m=n*factorial(--n);
	     printf("%d!=%lf\n",a,m);
		 return m;                               //每次必须有返回值，否则程序出错
	 }
}

//float factorial(long int n)
//{  
//     double m;
//     if(n==0||n==1)
//         return 1;
//     else
//	   m=n*factorial(--n);
//	   return m;
//}
