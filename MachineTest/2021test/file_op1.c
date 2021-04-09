#include <stdio.h>
#include <stdlib.h>

#define M 100

int file_op1()
{
    // FILE *fopen(char *filename, char *mode);
    /*
    表示以“只读”方式打开当前目录下的demo.txt文件，并使fp指向该文件，这样就可以通过fp来操作demo.txt了。
    fp 通常被称为文件指针。
    rb 表示以二进制方式打开demo.txt 文件，允许读和写。
    */
    FILE *fp1 = fopen("demo.txt", "r");
    FILE *fp2;

    char str[M + 1];

    ///判断文件是否打开失败
    if( fp2=fopen("D:\\demo.txt","rb") == NULL ){
        printf("Fail to open file!\n");
        //exit(0);  //退出程序（结束程序）
    }

    ///循环读取文件的每一行数据
    /*
    char *fgets(char *str, int n, FILE *stream)
    str -- 这是指向一个字符数组的指针，该数组存储了要读取的字符串。
    n -- 这是要读取的最大字符数（包括最后的空字符）。通常是使用以 str 传递的数组长度。
    stream -- 这是指向 FILE 对象的指针，该 FILE 对象标识了要从中读取字符的流。

    如果成功，该函数返回相同的 str 参数。如果到达文件末尾或者没有读取到任何字符，str 的内容保持不变，并返回一个空指针。

    如果发生错误，返回一个空指针。
    */
    while( fgets(str, M, fp1) != NULL ) {
        /* 向标准输出 stdout 写入内容 */
        //puts(str);
        printf("%s", str);
    }

    ///操作结束后关闭文件
    // int fclose(FILE *fp);
    fclose(fp1);
    return 0;
}
