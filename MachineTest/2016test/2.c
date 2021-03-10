#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct{
    int data[SIZE];
    int num;
}Seq;

Seq format(char s[]){
    Seq seq;
    int num, i, index=0;
    for(i=0; s[i]!='\0'; i++){
        if(s[i]!=' '){ // 转换字符为数字
            num = s[i]-'0';
            seq.data[index]=num;
            index++;
        }
    }
    seq.num=(i+1)/2; // 数字的个数
    printf("seq.num:%d\n", seq.num);
    return seq;
}

// 选择排序
void sort(Seq *seq){
    int min, temp;
    for(int i=0; i<seq->num; i++){
        min = i;
        for(int j=i+1; j<seq->num; j++){
            if(seq->data[min]>seq->data[j])
                min=j;
        }
        if(min!=i){
            temp=seq->data[min];
            seq->data[min]=seq->data[i];
            seq->data[i]=temp;
        }
    }
}

int multiple_sort()
{
    int n;
    char str[SIZE]; // 由于输入的数字个数不一样，先用字符串存储，再处理
    Seq seq_sorted[SIZE]; // 用来存放排序的所有序列
    Seq temp;
    printf("请输入行数:\n");
    scanf("%d", &n);
    fflush(stdin);
    printf("每行输入几个整数:\n");
    for(int i=0; i<n; i++){
        gets(str);
        temp=format(str);
        sort(&temp);
        seq_sorted[i]=temp;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<seq_sorted[i].num; j++){
            printf("%d  ", seq_sorted[i].data[j]);
        }
        printf("\n");
    }
    return 0;
}
