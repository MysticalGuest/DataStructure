#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsPrime(int n);

int sieve()
{
    int a, b;
    printf("请分别输入两个整数：\n");
    scanf("%d%d", &a, &b);
    for(int i=a; i<=b; i++){
        if(IsPrime(i)){
            printf("%d\n", i);
        }
    }

    return 0;
}
