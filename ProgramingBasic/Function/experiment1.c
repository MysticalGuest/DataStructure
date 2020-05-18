#include<stdio.h>
#include<Windows.h>

void main(){
	float x,ex=1,t=1,n=1;
  // 该程序用于计算e的x次方
	printf("This program is used to calculate the power of x, please enter x= ");
	scanf("%f",&x);
	while(t>1e-8){
		t = t*x/n;
		ex = ex+t;
		n++;
	}
	printf("The calculated power of x is %f\n",ex);

  system("pause");
}

float ex(float x){
	int n = 2;
	float t=x, sum=1;
	while(t >= 1e-8){
		sum += t;
		t = t*x/n;
		n++;
	}
	return sum;
}