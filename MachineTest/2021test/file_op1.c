#include <stdio.h>
#include <stdlib.h>

#define M 100

int file_op1()
{
    // FILE *fopen(char *filename, char *mode);
    /*
    ��ʾ�ԡ�ֻ������ʽ�򿪵�ǰĿ¼�µ�demo.txt�ļ�����ʹfpָ����ļ��������Ϳ���ͨ��fp������demo.txt�ˡ�
    fp ͨ������Ϊ�ļ�ָ�롣
    rb ��ʾ�Զ����Ʒ�ʽ��demo.txt �ļ����������д��
    */
    FILE *fp1 = fopen("demo.txt", "r");
    FILE *fp2;

    char str[M + 1];

    ///�ж��ļ��Ƿ��ʧ��
    if( fp2=fopen("D:\\demo.txt","rb") == NULL ){
        printf("Fail to open file!\n");
        //exit(0);  //�˳����򣨽�������
    }

    ///ѭ����ȡ�ļ���ÿһ������
    /*
    char *fgets(char *str, int n, FILE *stream)
    str -- ����ָ��һ���ַ������ָ�룬������洢��Ҫ��ȡ���ַ�����
    n -- ����Ҫ��ȡ������ַ������������Ŀ��ַ�����ͨ����ʹ���� str ���ݵ����鳤�ȡ�
    stream -- ����ָ�� FILE �����ָ�룬�� FILE �����ʶ��Ҫ���ж�ȡ�ַ�������

    ����ɹ����ú���������ͬ�� str ��������������ļ�ĩβ����û�ж�ȡ���κ��ַ���str �����ݱ��ֲ��䣬������һ����ָ�롣

    ����������󣬷���һ����ָ�롣
    */
    while( fgets(str, M, fp1) != NULL ) {
        /* ���׼��� stdout д������ */
        //puts(str);
        printf("%s", str);
    }

    ///����������ر��ļ�
    // int fclose(FILE *fp);
    fclose(fp1);
    return 0;
}
