#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int decimal_to_binary()
{
    int decimal, bin[SIZE], i;
    printf("请输入1个整数：\n");
    scanf("%d", &decimal);
    for(i=0; decimal!=0; i++){
        bin[i]=decimal%2;
        decimal=decimal/2;
    }
    for(int j=i-1; j>=0; j--){
        printf("%d", bin[j]);
    }
    printf("\n");
    return 0;
}
