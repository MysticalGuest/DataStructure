#include<stdio.h>
#include<Windows.h>

void main()
{
	float num1, num2, consequence;
	char character;
  // 这是个运算器，请输入你要计算的数学表达式
	printf("This is an operator, please enter the mathematical expression you want to calculate: \n");
	scanf("%f%c%f", &num1, &character, &num2);
	if(character=='+'){
		consequence = num1+num2;
		printf("The calculation result is %.2f\n", consequence);
	}
	else if(character=='-'){
		consequence = num1-num2;
		printf("The calculation result is %.2f\n", consequence);
	}
	else if(character=='*'){
		consequence = num1*num2;
		printf("The calculation result is %.2f\n", consequence);
	}
	else if(character=='/'){
		if( num2==0 )
      // 除数不能为零!!!请重新打开程序
			printf("Error!!! The divisor cannot be zero !!! Please reopen the program.\n");
		else{
			consequence = num1/num2;
			printf("The calculation result is %.2f\n", consequence);
		}
	}
	else
		printf("Error!!!\n");

    system("pause");
}
