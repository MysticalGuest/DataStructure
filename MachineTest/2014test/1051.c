#include <stdio.h>
#include <stdlib.h>

int wage()
{
    int year, wage;
    printf("��ֱ����빤�䣨1~100���͹��ʣ�100~5000��!\n");
    scanf("%d%d", &year, &wage);
    //printf("�����year��%d��wage��%d\n", year, wage);
    if(year>=20){
        if(wage>2000)
            wage+=200;
        else
            wage+=180;
    }
    else{
        if(wage>1500)
            wage+=150;
        else
            wage+=120;
    }
    printf("%d", wage);
    return 0;
}
