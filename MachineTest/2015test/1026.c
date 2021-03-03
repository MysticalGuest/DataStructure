#include <stdio.h>
#include <stdlib.h>

int mininum()
{
    int num1, num2, num3, min;
    printf("分别输入3个整数：\n");
    scanf("%d%d%d", &num1, &num2, &num3);
    min=num1<num2?num1:num2; // 将num1和num2中较小的数存在min中
    min=min<num3?min:num3; // 将min和num3中较小的数存在min中
    printf("%d", min);
    return 0;
}
