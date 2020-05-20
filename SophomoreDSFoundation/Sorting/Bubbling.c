#include<stdio.h>
void main()
{
	int i,j,a[5],max,temp;
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	for(i=5;i>0;i--)
		for(j=0;j<i-1;j++)
			if(a[j+1]<a[j])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
    for(i=0;i<5;i++)
		printf("%5d",a[i]);
	printf("\n");

}