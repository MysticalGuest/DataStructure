#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 255

int string_replace()
{
    char a[SIZE], b[SIZE], c[SIZE], temp[2*SIZE];
    int start=-1, end=-1; // ��¼b��a�г��ֵ���ʼ�±�,-1��ʾbû�г�����a��,���ԭ��a
    printf("��ֱ�����3���ַ�����\n");
    gets(a);
    gets(b);
    gets(c);
    for(int i=0; i<strlen(a); i++){
        if(a[i]==b[0]){ // ��ʼƥ��
            int j;
            for(j=0; j<strlen(b); j++){
                if(a[i+j]!=b[j])
                    break;
            }
            if(j==strlen(b)){ // ȫ��ƥ��ɹ�
                start=i;end=i+j-1;
            }
        }
    }
    if(start==-1&&end==-1){ // bû�г�����a��,���ԭ��a
        printf("%s\n", a);
    }
    else{
        for(int i=0; i<=start; i++){
            temp[i]=a[i]; // ��ʼ����a��ǰ���ַ�
        }
        for(int i=0; i<=strlen(c); i++){
            temp[i+start]=c[i]; // ��ʼ����b�е��ַ�
        }
        int k=strlen(c)+start;
        for(int i=end+1; i<strlen(a); i++,k++){
            temp[k]=a[i]; // ��ʼ����a��ʣ����ַ�
        }
        temp[k]='\0'; //����temp[]û�г�ʼ��������tempĩβ��ֵ��δ����ģ����Կ��ܻ���֣�
        //printf("%s\n", temp);
        puts(temp);
    }
    return 0;
}
