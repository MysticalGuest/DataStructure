#include <stdio.h>
#include <stdlib.h>

int simple_calculation()
{
    int first_num, second_num;
    printf("请分别输入两个整数：\n");
    scanf("%d%d", &first_num, &second_num);
    if(first_num>0)
        printf("%d", second_num);
    else
        printf("%d", first_num+second_num);
    return 0;
}
