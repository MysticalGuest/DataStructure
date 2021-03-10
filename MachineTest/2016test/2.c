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
        if(s[i]!=' '){ // ת���ַ�Ϊ����
            num = s[i]-'0';
            seq.data[index]=num;
            index++;
        }
    }
    seq.num=(i+1)/2; // ���ֵĸ���
    printf("seq.num:%d\n", seq.num);
    return seq;
}

// ѡ������
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
    char str[SIZE]; // ������������ָ�����һ���������ַ����洢���ٴ���
    Seq seq_sorted[SIZE]; // ��������������������
    Seq temp;
    printf("����������:\n");
    scanf("%d", &n);
    fflush(stdin);
    printf("ÿ�����뼸������:\n");
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
