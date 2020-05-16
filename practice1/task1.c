#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void main(){
    printf("Please enter an 8-bit unsigned integer constant:");
    char array[8];
    scanf("%s", array);
    int len = strlen(array);
    // 判断用户输入是否是8位无符号整型常量
    // 并判断用户输入是否为二进制
    // 如果长度不为8,或不是二进制数,则重新输入
    while(len!=8 || strspn(array, "01")!=len){
        printf("Your input does not meet the conditions!\nPlease enter an 8-bit unsigned integer constant as required:");
        scanf("%s", array);
        len = strlen(array);
    }
    int arrayToInt = strtol(array, NULL, 2);

    //十进制转二进制函数的声明
    int transfer(int x);
    int i=0, num=0;
    for(i; i<len; i++){
        if(transfer(arrayToInt)%2 == 1)
            num++;
        arrayToInt=arrayToInt>>1;
    }
    printf("The number of \"1\" in its binary representation is: %d.\n", num);

    printf("The program will continue to run, press any key to close it.");
    getch();
}

int transfer(int x)
{
    int i=0;
    int binary = 0b0;
    for(i ; i<x ; i++){
        binary++;
    }
    return binary;
}