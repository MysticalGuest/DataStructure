#include <stdio.h>
#include <stdlib.h>

int mininum()
{
    int num1, num2, num3, min;
    printf("�ֱ�����3��������\n");
    scanf("%d%d%d", &num1, &num2, &num3);
    min=num1<num2?num1:num2; // ��num1��num2�н�С��������min��
    min=min<num3?min:num3; // ��min��num3�н�С��������min��
    printf("%d", min);
    return 0;
}
