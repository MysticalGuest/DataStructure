#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// 6. Z ���α任
/*
��������
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
    int increment=2; // Z��б�ߴ����濪ʼ������
    for(int i=0; i<strlen(s); ){
        for(int j=0; j<numRows; j++, i++){
            if(i<strlen(s)){
                temp[j][col]=s[i];
                //printf("s[i]:%c\n", s[i]);
            }

        }
        col++;
        for(int j=0; j<numRows-2; j++, col++, i++){ // ��¼Z��б��
            if(i>=strlen(s)) break;
            num=numRows-increment;
            int k;
            for(k=0; k<num; k++){
                //temp[k][col]='#'; // ��ʾ�Ͽ�λ��
                //printf("��ʾ�Ͽ�λ��temp[k][col]:%c\n", temp[k][col]);
            }
            temp[k][col]=s[i]; // �м��һ��Ԫ��
            //printf("temp[k][col]:%c\n", temp[k][col]);
            for(k++; k<numRows; k++){
                //temp[k][col]='#'; // ��ʾ�¿�λ��
                //printf("��ʾ�¿�λ��temp[k][col]:%c\n", temp[k][col]);
            }
            increment++;
        }
        increment=2; // ��������
    }
    /* ��ӡͼ��
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
    printf("�������ַ�����\n");
    gets(str);
    printf("����������\n");
    scanf("%d", &row);
    //puts(s);
    puts(convert(s, row));
    return 0;
}
