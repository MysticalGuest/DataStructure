#include <stdio.h>
#include<Windows.h>

int fun1(int a, int b){
	int result, temp, i;
	if(a < b){
		temp = a;
		a = b;
		b = temp;
	}
	for(i=b; i>0; i--){
		if((a%i==0) && (b%i==0)){
			result = i;
			break;
		}
	}
	return result;
}

int fun2(int a, int b){
	int result, temp, j;
    if(a < b){
		temp = a;
		a = b;
		b = temp;
	}
	for(j=a; j<=a*b; j++){
		if((j%a==0) && (j%b==0)){
			result = j;
			break;
		}
	}
	return result;
}

void main(){
	int m, n;
	printf("Please enter two positive integers m and n: \n");
	printf("m=");
	scanf("%d", &m);
	printf("n=");
	scanf("%d", &n);
	// 最大公约数
	printf("The greatest common divisor of %d and %d is %d\n", m, n, fun1(m, n));
	// 最小公倍数
  printf("The least common multiple of %d and %d is %d\n", m, n, fun2(m, n));
  
  system("pause");
}