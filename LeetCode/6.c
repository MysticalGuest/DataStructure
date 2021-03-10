#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// 6. Z 字形变换
/*
测试用例
"PAYPALISHIRING"
3
*/

#define Length 1000

char * convert(char * s, int numRows){
    //char temp[Length][Length], result[Length];
    int slen=strlen(s);
    if(numRows==1||slen<numRows)
        return s;
    char temp[Length][Length];
    //char *t=result;
    char *t;
    t=malloc(sizeof(char)*(strlen(s)+1));
    int num, col=0;
    int increment=2; // Z的斜边从下面开始的增量
    for(int i=0; i<strlen(s); ){
        for(int j=0; j<numRows; j++, i++){
            if(i<strlen(s)){
                temp[j][col]=s[i];
                //printf("s[i]:%c\n", s[i]);
            }

        }
        col++;
        for(int j=0; j<numRows-2; j++, col++, i++){ // 记录Z的斜边
            if(i>=strlen(s)) break;
            num=numRows-increment;
            int k;
            for(k=0; k<num; k++){
                //temp[k][col]='#'; // 表示上空位置
                //printf("表示上空位置temp[k][col]:%c\n", temp[k][col]);
            }
            temp[k][col]=s[i]; // 中间的一个元素
            //printf("temp[k][col]:%c\n", temp[k][col]);
            for(k++; k<numRows; k++){
                //temp[k][col]='#'; // 表示下空位置
                //printf("表示下空位置temp[k][col]:%c\n", temp[k][col]);
            }
            increment++;
        }
        increment=2; // 重置增量
    }
    /* 打印图像
    for(int i=0; i<numRows; i++){
        for(int j=0; j<col; j++){
            printf("%c ", temp[i][j]);
        }
        printf("\n");
    }
    */
    int index=0;
    for(int i=0; i<numRows; i++){
        for(int j=0; j<col; j++){
            if(temp[i][j]!='\0'){
                t[index]=temp[i][j];
                index++;
            }
        }
    }
    //t=result;
    //result[index]='\0';
    return t;
}

int zigzag_conversion()
{
    char str[Length];
    char *s=str;
    int row;
    printf("请输入字符串：\n");
    gets(str);
    printf("输入行数：\n");
    scanf("%d", &row);
    //puts(s);
    puts(convert(s, row));
    return 0;
}
