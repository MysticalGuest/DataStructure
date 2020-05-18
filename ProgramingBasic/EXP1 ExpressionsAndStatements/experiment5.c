#include<stdio.h>
#include<math.h>
#include<Windows.h>

void main(){
	int m, n=2, q;

  // 判断一个数是否为素数，请输入一个整数
	printf("To determine whether a number is prime, please enter an integer m=");
	scanf("%d",&m);

  while(n < (sqrt(m)+1)){
		if( m%n == 0 )
			q=0;
		else
			q=1;
		n++;
	}
	if(q==0)
		printf("%d is not prime!\n",m);
	else
	  printf("%d is prime!\n",m);
    
  system("pause");
}