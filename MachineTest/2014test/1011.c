#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsPrime(int n){
    for(int i=2; i<=sqrt(n); i++)
        if(n%i==0){
            return 0;
        }
    return 1;
}

int prime()
{
    int num;
    printf("������һ��������\n");
    scanf("%d", &num);
    if(IsPrime(num)){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}
