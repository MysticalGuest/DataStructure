#include<stdio.h>
void main()
{int i,j,a=4,m=3,n=5;
	for(i=1;i<=4;i++)
	{for(j=1;j<=7;j++)
		{
			if(j>m&&j<n)
				printf("*");
			else
				printf(" ");
		}printf("\n");
		j=1;m--;n++;}
	m=1;n=7;
    for(i=1;i<=3;i++)
	{for(j=1;j<=7;j++)
		{
			if(j>m&&j<n)
				printf("*");
			else
				printf(" ");
		}printf("\n");
		j=1;m++;n--;}
}

		
