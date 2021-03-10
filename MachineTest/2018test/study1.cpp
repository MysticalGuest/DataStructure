#include <iostream>

using namespace std;

#define Size 100

//内联函数，交换两个数的值
inline void swap(int *m, int *n){
    int temp;
    temp = *m;
    *m = *n;
    *n = temp;
}

//带默认参数的函数
void func(int n, float b=1.2, char c='@'){
    cout<<n<<", "<<b<<", "<<c<<endl;
}

/*
在C++中，这完全没有必要。C++ 允许多个函数拥有相同的名字，
只要它们的参数列表不同就可以，这就是函数的重载（Function Overloading）。
借助重载，一个函数名可以有多种用途。
*/
//交换 int 变量的值
void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//交换 float 变量的值
void Swap(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}
//交换 char 变量的值
void Swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int study1()
{
    std::printf("http://c.biancheng.net\n");

    //定义字符串变量
    string str;
    //定义 int 变量
    int age;
    //从控制台获取用户输入
    cin>>str>>age;
    //将数据输出到控制台
    cout<<str<<"已经成立"<<age<<"年了！"<<endl;

    cout<<"Please input two int numbers:\n";

    int a, b;
    bool flag;  //定义布尔变量
    ///遗憾的是，在 C++ 中使用 cout 输出 bool 变量的值时还是用数字 1 和 0 表示，而不是 true 或 false
    cin>>a>>b;
    flag = a > b;
    cout<<"flag = "<<flag<<endl;

    /*
    在C语言中，动态分配内存用 malloc() 函数，释放内存用 free() 函数。
    在C++中，这两个函数仍然可以使用，
    但是C++又新增了两个关键字，new 和 delete：new 用来动态分配内存，delete 用来释放内存。
    */
    int *p = new int;  //分配1个int型的内存空间，new 操作符会根据后面的数据类型来推断所需空间的大小。
    delete p;  //释放内存

    /*
    如果希望分配一组连续的数据，可以使用 new[]：
    用 new[] 分配的内存需要用 delete[] 释放，它们是一一对应的。
    和 malloc() 一样，new 也是在堆区分配内存，必须手动释放，否则只能等到程序运行结束由操作系统回收。
    为了避免内存泄露，通常 new 和 delete、new[] 和 delete[] 操作符应该成对出现，
    并且不要和C语言中 malloc()、free() 一起混用。

    在C++中，建议使用 new 和 delete 来管理内存，它们可以使用C++的一些新特性，
    最明显的是可以自动调用构造函数和析构函数，后续我们将会讲解。
    */
    int *q = new int[10];  //分配10个int型的内存空间
    delete[] q;

    /*
    为了消除函数调用的时空开销，C++ 提供一种提高效率的方法，即在编译时将函数调用处用函数体替换，
    类似于C语言中的宏展开。
    这种在函数调用处直接嵌入函数体的函数称为内联函数（Inline Function），又称内嵌函数或者内置函数。
    */
    cout<<a<<", "<<b<<endl;
    /*
    当编译器遇到函数调用swap(&a, &b)时，会用 swap() 函数的代码替换swap(&m, &n)，
    同时用实参代替形参。这样，程序下一行就被置换成：
    int temp;
    temp = *(&a);
    *(&a) = *(&b);
    *(&b) = temp;
    */
    swap(&a, &b);
    /*
    使用内联函数的缺点也是非常明显的，编译后的程序会存在多份相同的函数拷贝，
    如果被声明为内联函数的函数体非常大，那么编译后的程序体积也将会变得很大，
    所以再次强调，一般只将那些短小的、频繁调用的函数声明为内联函数。
    */
    cout<<a<<", "<<b<<endl;

    //为所有参数传值
    func(10, 3.5, '#');
    //为n、b传值，相当于调用func(20, 9.8, '@')
    func(20, 9.8);
    //只为n传值，相当于调用func(30, 1.2, '@')
    func(30);

    /*
    默认参数除了使用数值常量指定，也可以使用表达式指定，例如：
    float d = 10.8;
    void func(int n, float b=d+2.9, char c='@'){
        cout<<n<<", "<<b<<", "<<c<<endl;
    }
    C++规定，默认参数只能放在形参列表的最后，而且一旦为某个形参指定了默认值，
    那么它后面的所有形参都必须有默认值。
    实参和形参的传值是从左到右依次匹配的，默认参数的连续性是保证正确传参的前提。
    */

    return 0;
}
