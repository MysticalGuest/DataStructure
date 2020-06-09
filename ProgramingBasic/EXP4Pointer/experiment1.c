#include<stdio.h>
#include<Windows.h>

void swap(float *num1, float *num2){
	float temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
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
	swap(&a, &b);
	printf("a=%f, b=%f\n", a, b);

  system("pause");
}