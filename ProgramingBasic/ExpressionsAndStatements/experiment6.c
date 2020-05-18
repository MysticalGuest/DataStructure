#include<stdio.h>
#include<math.h>
#include<Windows.h>

void main()
{
	int a, b, c, d, e, f, g, h, i, j, sum;

	printf("Please enter ten positive integers: \n");
	scanf("%d%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);

	while((a<0) || (b<0) || (c<0) || (d<0) ||(e<0) || (f<0) || (g<0) || (h<0) || (i<0) || (j<0)){
		printf("The input value has a negative number, please enter ten more integers: ");
		scanf("%d%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);
	}	
	if((a>0) && (b>0) && (c>0) && (d>0) && (e>0) && (f>0) && (g>0) && (h>0) && (i>0) && (j>0)){
		sum = a+b+c+d+e+f+g+h+i+j;
		printf("The sum of these ten numbers is %d.\n",sum);
	}
  system("pause");
}