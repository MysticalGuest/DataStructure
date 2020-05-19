#include <stdio.h>
#include<Windows.h>

int fun(int a){
	if(a < 2)
		printf("1");
	else{
		fun(a / 2);
		printf("%d", a%2);
	}
}
void main() {
	int a;
	// 请输入一个十进制整数,程序会将其转化为二进制数
	printf("Please enter a decimal integer, the program will convert it into a binary number: ");
	scanf("%d", &a);
  fun(a);
	printf("\n");

  system("pause");
}