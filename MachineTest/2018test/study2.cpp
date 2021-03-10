#include <iostream>

using namespace std;

/*
��ֻ��һ��ģ�壨Template���������ռ���ڴ�ռ䣬�����ڶ�����ʱ���ܶԳ�Ա�������г�ʼ����
��Ϊû�еط��洢���ݡ�
ֻ���ڴ��������Ժ�Ż����Ա���������ڴ棬���ʱ��Ϳ��Ը�ֵ�ˡ�

*/
class Student{
public:
    //��Ա����
    char *name;
    int age;
    float score;
    //��Ա����
    void say(){
        cout<<name<<"��������"<<age<<"���ɼ���"<<score<<endl;
    }

    void say_out();
};

///Ҳ����ֻ�����������������������������������������
/*
����Ա��������������ʱ���ͱ����ں�����ǰ��������������޶���
::����Ϊ���������Ҳ����������������������޶��������������������ͺ�������ָ����ǰ���������ĸ��ࡣ

��Ա��������������������ԭ��������Ȼ�������ⶨ�壬Ҳ����˵�����λ��Ӧ�ں�������֮ǰ��

�������к������ⶨ���Ա������������ģ��������ж���ĳ�Ա�������Զ���Ϊ�����������������ⶨ��Ĳ��ᡣ
��Ȼ���������ڲ�����ĺ���Ҳ���Լ� inline �ؼ��֣������Ƕ���ģ���Ϊ�����ڲ�����ĺ���Ĭ�Ͼ�������������

��������һ�㲻�������������ģ����Ὣ�������ô��ú���������������ҽ����������ڲ��Գ�Ա������������
���������ⲿ���ж��壬����һ�����õı��ϰ�ߣ�ʵ�ʿ����д��Ҳ���������ġ�
*/
//��������
void Student::say_out(){
    cout<<name<<"��������"<<age<<"���ɼ���"<<score<<"(�⺯��)"<<endl;
}

/*
public��protected��private �����ؼ��������Ƴ�Ա�����ͳ�Ա�����ķ���Ȩ�ޣ�
���Ƿֱ��ʾ���еġ��ܱ����ġ�˽�еģ�����Ϊ��Ա�����޶�����
��ν����Ȩ�ޣ��������ܲ���ʹ�ø����еĳ�Ա��

Java��C# ����Աע�⣬C++ �е� public��private��protected ֻ��������ĳ�Ա�����������࣬C++�е���û�й���˽��֮�֡�

������ڲ���������Ĵ����ڲ��������۳�Ա������Ϊ public��protected ���� private��
���ǿ��Ի�����ʵģ�û�з���Ȩ�޵����ơ�

������ⲿ��������Ĵ���֮�⣩��ֻ��ͨ��������ʳ�Ա������ͨ������ֻ�ܷ��� public ���Եĳ�Ա��
���ܷ��� private��protected ���Եĳ�Ա��
*/

//�������
class HighStudent{
private:  //˽�е�
    char *m_name;
    int m_age;
    float m_score;
public:  //���е�
    //�������캯��
    HighStudent();
    HighStudent(char *name, int age, float score);
    //������ͨ��Ա����
    void setname(char *name);
    void setage(int age);
    void setscore(float score);
    void show();
};
//��Ա�����Ķ���
//���幹�캯��
/*
���캯�������� public ���Եģ����򴴽�����ʱ�޷����á���Ȼ������Ϊ private��protected ����Ҳ���ᱨ������û�����塣

���캯��û�з���ֵ����Ϊû�б��������շ���ֵ����ʹ��Ҳ�����ô�������ζ�ţ�
�������������Ƕ��壬������ǰ�涼���ܳ��ַ���ֵ���ͣ���ʹ�� void Ҳ������
�������в����� return ��䡣

����ͨ��Ա����һ�������캯�����������صġ�һ��������ж�����صĹ��캯������������ʱ���ݴ��ݵ�ʵ�����жϵ�����һ�����캯����

���캯���ĵ�����ǿ���Եģ�һ�������ж����˹��캯������ô��������ʱ��һ��Ҫ���ã��������Ǵ���ġ�
����ж�����صĹ��캯������ô��������ʱ�ṩ��ʵ�α�������е�һ�����캯��ƥ�䣻
������˵����������ʱֻ��һ�����캯���ᱻ���á�
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
//������ͨ��Ա����
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
    //cout<<m_name<<"��������"<<m_age<<"���ɼ���"<<m_score<<endl;
    if(m_name == NULL || m_age <= 0){
        cout<<"��Ա������δ��ʼ��"<<endl;
    }else{
        cout<<m_name<<"��������"<<m_age<<"���ɼ���"<<m_score<<endl;
    }
}

int study2()
{
    //��������
    Student stu;
    stu.name =(char*)"С��";
    stu.age = 15;
    stu.score = 92.5f;
    stu.say();
    stu.say_out();

    //C�����о����ָ���� C++ ����Ȼ�㷺ʹ�ã�������ָ������ָ�룬û�����Ͳ���ʵ��ĳЩ���ܡ�
    Student stu1;
    Student *pStu1 = &stu1;
    pStu1->name=(char*)"С��";
    pStu1->age=18;
    pStu1->score=92;
    pStu1->say();

    /*
    ��Ȼ����Ҳ�����ڶ��ϴ����������ʱ�����Ҫʹ��ǰ�潲����new�ؼ��֡�
    ��ջ�ϴ��������Ķ�����һ�����֣����� stu��ʹ��ָ��ָ�������Ǳ���ġ�
    ����ͨ�� new ���������Ķ���Ͳ�һ���ˣ����ڶ��Ϸ����ڴ棬û�����֣�
    ֻ�ܵõ�һ��ָ������ָ�룬���Ա���ʹ��һ��ָ��������������ָ�룬
    �����Ժ���Ҳ�޷��ҵ���������ˣ���û�а취ʹ������
    Ҳ����˵��ʹ�� new �ڶ��ϴ��������Ķ����������ģ�û��ֱ��ʹ�ã�
    ����Ҫ��һ��ָ��ָ�������ٽ���ָ�����������ĳ�Ա�������Ա������
    */
    Student *pStu2 = new Student; // ע�������new��java�е�new������

    /*
    ���˶���ָ��󣬿���ͨ����ͷ->�����ʶ���ĳ�Ա�����ͳ�Ա������
    ���ͨ���ṹ��ָ�����������ĳ�Ա���ƣ��뿴�����ʾ����
    */
    pStu2 -> name = (char*)"С��";
    pStu2 -> age = 16;
    pStu2 -> score = 97.5f;
    pStu2 -> say();
    pStu2 -> say_out();

    //��ջ�ϴ�������
    HighStudent hstu1;
    hstu1.setname((char*)"����");
    hstu1.setage(15);
    hstu1.setscore(92.5f);
    hstu1.show();
    //�ڶ��ϴ�������
    HighStudent *phstu1 = new HighStudent;
    phstu1 -> show();
    phstu1 -> setname((char*)"�");
    phstu1 -> setage(16);
    phstu1 -> setscore(96);
    phstu1 -> show();

    /*
    ��������Ӵ���
    HighStudent stu;
    //m_name��m_age��m_score ��˽�г�Ա���������������ⲿͨ���������
    stu.m_name = "С��";
    stu.m_age = 15;
    stu.m_score = 92.5f;
    stu.show();
    */

    //��������ʱ���캯������
    HighStudent hstu2((char*)"С��", 15, 92.5f);
    hstu2.show();
    //��������ʱ���캯������
    HighStudent *phstu2 = new HighStudent((char*)"�", 16, 96);
    phstu2 -> show();

    delete pStu1;  //ɾ������
    delete pStu2;  //ɾ������
    delete phstu1;
    delete phstu2;
    return 0;
}
