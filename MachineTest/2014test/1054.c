#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int string_statistics()
{
    char s[SIZE];
    int a=0; // 表示英文字母的个数
    int b=0; // 表示空格的个数
    int c=0; // 表示数字的个数
    int d=0; // 表示其他字符的个数
    printf("请输入一行字符：\n");
    /*
    输出结果是：
    请输入字符串：i love you
    输出结果：i

    我们看到，输入的是“i love you”，而输出的只有“i”。
    原因是系统将空格作为输入字符串之间的分隔符。
    也就是说，只要一“敲”空格，系统就认为当前的字符串已经结束。
    接下来输入的是下一个字符串，所以只会将空格之前的字符串存储到定义好的字符数组中。
    */
    //scanf("%s", s); // 所以不用scanf,用gets()
    gets(s);
    for(int i=0; i<strlen(s); i++){
        printf("%c\n", s[i]);
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
            a++;
        else if(s[i]==' ') // 空格表示
            b++;
        else if(s[i]>='0'&&s[i]<='9')
            c++;
        else
            d++;
    }
    printf("%d %d %d %d\n", a, b, c, d);
    return 0;
}
