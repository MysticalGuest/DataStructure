#include<stdio.h>
#include<Windows.h>

void swap(float num1, float num2){
	float *p1, *p2, *temp;
	p1 = &num1;
	p2 = &num2;
	temp = p1;
	p1 = p2;
	p2 = temp;
	printf("%f, %f\n", *p1, *p2);
}

void main(){
	float a, b;
  // 请输入两个实数：
	printf("Please enter two real numbers: \n");
	printf("a=");
	scanf("%f", &a);
	printf("b=");
	scanf("%f", &b);
	printf("After a and b exchange values: ");
	swap(a, b);

  system("pause");
}