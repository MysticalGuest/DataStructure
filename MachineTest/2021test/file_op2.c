#include <stdio.h>
#include <stdlib.h>

#define M 100

//在C语言中，读写文件比较灵活，既可以每次读写一个字符，也可以读写一个字符串，甚至是任意字节的数据（数据块）。

int file_op2()
{
    // int fgetc (FILE *fp);
    /*
    fp 为文件指针。fgetc() 读取成功时返回读取到的字符，读取到文件末尾或读取失败时返回EOF。

    EOF 是 end of file 的缩写，表示文件末尾，是在 stdio.h 中定义的宏，它的值是一个负数，往往是 -1。
    fgetc() 的返回值类型之所以为 int，就是为了容纳这个负数（char不能是负数）。
    ```EOF 不绝对是 -1，也可以是其他负数，这要看编译器的实现。```
    */
    FILE *fp;
    char ch;
    /*以“读写”方式打开文件。既可以读取也可以写入，也就是随意更新文件。文件必须存在，否则打开失败。*/
    //FILE *fp = fopen("demo.txt", "r+");
    // 表示从demo.txt文件中读取一个字符，并保存到变量 ch 中。
    /*
    在文件内部有一个位置指针，用来指向当前读写到的位置，也就是读写到第几个字节。
    在文件打开时，该指针总是指向文件的第一个字节。
    使用 fgetc() 函数后，该指针会向后移动一个字节，所以可以连续多次使用 fgetc() 读取多个字符。
    */

    //如果文件不存在，给出提示并退出
    if( (fp=fopen("demo.txt","rt")) == NULL ){
        puts("Fail to open file!");
        exit(0);
    }
    //每次读取一个字节，直到读取完毕
    while( (ch=fgetc(fp)) != EOF ){
        putchar(ch);
    }
    putchar('\n');  //输出换行符
    fclose(fp);
    return 0;
}
