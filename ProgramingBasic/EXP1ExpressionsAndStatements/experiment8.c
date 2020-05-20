#include<stdio.h>
#include<math.h>
#include<Windows.h>

void main() {
	int a=100, b, c, d, i;
  // 所有的“水仙花数”有
	printf("All \"narcissus numbers\" have: ");           
	while(a < 1000){
		b = a / 100;
		c = (a - b * 100) / 10;
    d = a % 10;
		i = b*b*b + c*c*c + d*d*d;
		if(a==i){
      printf("%d,", a);
      a++;
    }
		else
			a++;
	}
	printf("\n");

  system("pause");
}
		