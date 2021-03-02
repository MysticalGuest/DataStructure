#include <stdio.h>
#include <stdlib.h>

int wage()
{
    int year, wage;
    printf("请分别输入工龄（1~100）和工资（100~5000）!\n");
    scanf("%d%d", &year, &wage);
    //printf("输入的year是%d，wage是%d\n", year, wage);
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
