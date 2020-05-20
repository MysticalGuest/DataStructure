#include<stdio.h>
#include<stdlib.h>

#define N 20000

void main(){
	int i,j,k,r,num[N],temp;
	for(i=0;i<N;i++){
		r=rand();
		if(r>10000)
			num[i]=r/1000;
		else if(r>1000)
			num[i]=r/100;
		else if(r>100)
			num[i]=r/10;
		else
			num[i]=r;
	}
//	for(i=0;i<N;i++)
//		printf("%d\n",num[i]);
	for(i=0;i<N;i++){
		k=i;
		for(j=i+1;j<N;j++){
			if(num[k]>num[j])
				k=j;
			if(k!=i){
				temp=num[k];
				num[k]=num[i];
				num[i]=temp;
			}
		}
	}
	for(i=0;i<N;i++)
		printf("%d\n",num[i]);
}