#include<stdio.h>
#include<Windows.h>

void main()
{
	char ch1[4]={'h','o','m','e'},ch2[4]={'w','o','r','k'},mystrcat[8];
	int i,j,k=0;;
    for(i=0;i<4;i++)
		mystrcat[k++]=ch1[i];
	for(j=0;j<4;j++)
		mystrcat[k++]=ch2[j];
	for(i=0;i<8;i++)
		printf("%c",mystrcat[i]);
	printf("\n");

	system("pause");
}