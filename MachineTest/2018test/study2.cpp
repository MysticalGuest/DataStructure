#include <iostream>

using namespace std;

/*
类只是一个模板（Template），编译后不占用内存空间，所以在定义类时不能对成员变量进行初始化，
因为没有地方存储数据。
只有在创建对象以后才会给成员变量分配内存，这个时候就可以赋值了。

*/
class Student{
public:
    //成员变量
    char *name;
    int age;
    float score;
    //成员函数
    void say(){
        cout<<name<<"的年龄是"<<age<<"，成绩是"<<score<<endl;
    }

    void say_out();
};

///也可以只在类体中声明函数，而将函数定义放在类体外面
/*
当成员函数定义在类外时，就必须在函数名前面加上类名予以限定。
::被称为域解析符（也称作用域运算符或作用域限定符），用来连接类名和函数名，指明当前函数属于哪个类。

成员函数必须先在类体中作原型声明，然后在类外定义，也就是说类体的位置应在函数定义之前。

在类体中和类体外定义成员函数是有区别的：在类体中定义的成员函数会自动成为内联函数，在类体外定义的不会。
当然，在类体内部定义的函数也可以加 inline 关键字，但这是多余的，因为类体内部定义的函数默认就是内联函数。

内联函数一般不是我们所期望的，它会将函数调用处用函数体替代，所以我建议在类体内部对成员函数作声明，
而在类体外部进行定义，这是一种良好的编程习惯，实际开发中大家也是这样做的。
*/
//函数定义
void Student::say_out(){
    cout<<name<<"的年龄是"<<age<<"，成绩是"<<score<<"(外函数)"<<endl;
}

/*
public、protected、private 三个关键字来控制成员变量和成员函数的访问权限，
它们分别表示公有的、受保护的、私有的，被称为成员访问限定符。
所谓访问权限，就是你能不能使用该类中的成员。

Java、C# 程序员注意，C++ 中的 public、private、protected 只能修饰类的成员，不能修饰类，C++中的类没有共有私有之分。

在类的内部（定义类的代码内部），无论成员被声明为 public、protected 还是 private，
都是可以互相访问的，没有访问权限的限制。

在类的外部（定义类的代码之外），只能通过对象访问成员，并且通过对象只能访问 public 属性的成员，
不能访问 private、protected 属性的成员。
*/

//类的声明
class HighStudent{
private:  //私有的
    char *m_name;
    int m_age;
    float m_score;
public:  //共有的
    //声明构造函数
    HighStudent();
    HighStudent(char *name, int age, float score);
    //声明普通成员函数
    void setname(char *name);
    void setage(int age);
    void setscore(float score);
    void show();
};
//成员函数的定义
//定义构造函数
/*
构造函数必须是 public 属性的，否则创建对象时无法调用。当然，设置为 private、protected 属性也不会报错，但是没有意义。

构造函数没有返回值，因为没有变量来接收返回值，即使有也毫无用处，这意味着：
不管是声明还是定义，函数名前面都不能出现返回值类型，即使是 void 也不允许；
函数体中不能有 return 语句。

和普通成员函数一样，构造函数是允许重载的。一个类可以有多个重载的构造函数，创建对象时根据传递的实参来判断调用哪一个构造函数。

构造函数的调用是强制性的，一旦在类中定义了构造函数，那么创建对象时就一定要调用，不调用是错误的。
如果有多个重载的构造函数，那么创建对象时提供的实参必须和其中的一个构造函数匹配；
反过来说，创建对象时只有一个构造函数会被调用。
*/
HighStudent::HighStudent(){
    //m_name = NULL;
    //m_age = 0;
    //m_score = 0.0;
}
HighStudent::HighStudent(char *name, int age, float score){
    m_name = name;
    m_age = age;
    m_score = score;
}
//定义普通成员函数
void HighStudent::setname(char *name){
    m_name = name;
}
void HighStudent::setage(int age){
    m_age = age;
}
void HighStudent::setscore(float score){
    m_score = score;
}
void HighStudent::show(){
    //cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
    if(m_name == NULL || m_age <= 0){
        cout<<"成员变量还未初始化"<<endl;
    }else{
        cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
    }
}

int study2()
{
    //创建对象
    Student stu;
    stu.name =(char*)"小明";
    stu.age = 15;
    stu.score = 92.5f;
    stu.say();
    stu.say_out();

    //C语言中经典的指针在 C++ 中仍然广泛使用，尤其是指向对象的指针，没有它就不能实现某些功能。
    Student stu1;
    Student *pStu1 = &stu1;
    pStu1->name=(char*)"小兰";
    pStu1->age=18;
    pStu1->score=92;
    pStu1->say();

    /*
    当然，你也可以在堆上创建对象，这个时候就需要使用前面讲到的new关键字。
    在栈上创建出来的对象都有一个名字，比如 stu，使用指针指向它不是必须的。
    但是通过 new 创建出来的对象就不一样了，它在堆上分配内存，没有名字，
    只能得到一个指向它的指针，所以必须使用一个指针变量来接收这个指针，
    否则以后再也无法找到这个对象了，更没有办法使用它。
    也就是说，使用 new 在堆上创建出来的对象是匿名的，没法直接使用，
    必须要用一个指针指向它，再借助指针来访问它的成员变量或成员函数。
    */
    Student *pStu2 = new Student; // 注意这里的new和java中的new的区别

    /*
    有了对象指针后，可以通过箭头->来访问对象的成员变量和成员函数，
    这和通过结构体指针来访问它的成员类似，请看下面的示例：
    */
    pStu2 -> name = (char*)"小王";
    pStu2 -> age = 16;
    pStu2 -> score = 97.5f;
    pStu2 -> say();
    pStu2 -> say_out();

    //在栈上创建对象
    HighStudent hstu1;
    hstu1.setname((char*)"花花");
    hstu1.setage(15);
    hstu1.setscore(92.5f);
    hstu1.show();
    //在堆上创建对象
    HighStudent *phstu1 = new HighStudent;
    phstu1 -> show();
    phstu1 -> setname((char*)"李华");
    phstu1 -> setage(16);
    phstu1 -> setscore(96);
    phstu1 -> show();

    /*
    下面的例子错误：
    HighStudent stu;
    //m_name、m_age、m_score 是私有成员变量，不能在类外部通过对象访问
    stu.m_name = "小明";
    stu.m_age = 15;
    stu.m_score = 92.5f;
    stu.show();
    */

    //创建对象时向构造函数传参
    HighStudent hstu2((char*)"小明", 15, 92.5f);
    hstu2.show();
    //创建对象时向构造函数传参
    HighStudent *phstu2 = new HighStudent((char*)"李华", 16, 96);
    phstu2 -> show();

    delete pStu1;  //删除对象
    delete pStu2;  //删除对象
    delete phstu1;
    delete phstu2;
    return 0;
}
