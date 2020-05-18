#include<stdio.h>
#include<math.h>
#include<Windows.h>

void main(){
	float s, a, b, c;
	printf("Please input three lengths of the triangle:\n");

	scanf("%f%f%f",&a,&b,&c);

	if( a+b > c && a+c > b && b+c>a ){
		s=(a+b+c) / 2;
		printf("The area of this triangle is %.2f\n", sqrt(s * (s-a) * (s-b) * (s-c)) );	
	}
	else
		printf("ERROR!\n");

	system("pause");
}


/*
#include<stdio.h>
#include<math.h>
#include<Windows.h>

void main(){
	float a, b, c, area, s;

	printf("请输入三角形的三条边长:\n");
	printf("a=");
	scanf("%f",&a);
	printf("b=");
	scanf("%f",&b);
	printf("c=");
	scanf("%f",&c);

	if((a+b > c) && (a+c > b) && (b+c > a)){
		s = (a+b+c) / 2;
		area = sqrt(s * (s-a) * (s-b) * (s-c));
		printf("三角形的面积为%.2f\n",area);
	}
	else
		printf("Date Error!!!\n");

	system("pause");
}
*/


/*
#include<stdio.h>
#include<math.h>
#include<Windows.h>

void main(){
	int a, b, c;
	float area, s;

	printf("请输入三角形的三条边长:\n");
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	printf("c=");
	scanf("%d",&c);

	if((a+b > c) && (a+c > b) && (b+c > a)){
		s = (a+b+c) / 2.0;   //如果这里的2.0写成2，当输入三边为2,3,4时 程序出错!!
		area = sqrt(s*(s-a)*(s-b)*(s-c));
		printf("三角形的面积为%.2f\n",area);
	}
	else
		printf("Date Error!!!\n");

	system("pause");
}
*/
