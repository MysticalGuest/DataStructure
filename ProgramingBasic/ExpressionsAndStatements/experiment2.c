#include<stdio.h>
#include<math.h>
#include<Windows.h>

void main(){
	int n=1;
	double x, sum=0, t;

	printf("Please input x=");
	scanf("%lf",&x);

	sum=x;
	t=x;
  // 计算级数
	while(fabs(t) >= 1e-8){
		t = t * (-1) * x * x / ((n+1) * (n+2));
		n = n+2;
		sum=sum+t;		
	}
	printf("Sum is %.2f\n",sum);
  
  system("pause");
}