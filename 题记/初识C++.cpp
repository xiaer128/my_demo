#include<iostream>
#include<vector>
#include<windows.h>
using namespace std;
class A//类与对象
{
private:
    int x;
    int& rx;//引用变量
    const double pi;//常量
public:
    A(int v) : x(v), rx(x), pi(3.14)    //成员初始化列表
    {	}
    void print()
    {
        cout << "x = " << x << " rx = " << rx << " pi = " << pi << endl;
    }
};
class Score
{
public:
    Score(int m = 0, int f = 0);
    void setscore(int m, int f);
    void showscore();
    ~Score();       //析构函数
private:
    int mid_exam;
    int fin_exam;
};
void Score::setscore(int m, int f)
{
    mid_exam=m;
    fin_exam=f;
}
void Score::showscore()
{
    cout<<mid_exam<<endl;
    cout<<fin_exam<<endl;
}
Score::Score(int m, int f) : mid_exam(m), fin_exam(f)
{
    cout << "构造函数使用中..." << endl;
}

Score::~Score()
{
    cout << "析构函数使用中..." << endl;
}
class Student
{
private:
    char *name;
    char *stu_no;
    float score;
public:
    Student(char *name1, char *stu_no1, float score1);
    ~Student();
    void modify(float score1);
    void show();
};

Student::Student(char *name1, char *stu_no1, float score1)
{
    name = new char[strlen(name1) + 1];
    strcpy(name, name1);
    stu_no = new char[strlen(stu_no1) + 1];
    strcpy(stu_no, stu_no1);
    score = score1;
}

Student::~Student()
{
    delete []name;
    delete []stu_no;
    cout<<"析构函数使用中。。。"<<endl;
}

void Student::modify(float score1)
{
    score = score1;
}

void Student::show()
{
    cout << "姓名: " << name << endl;
    cout << "学号: " << stu_no << endl;
    cout << "成绩：" << score << endl;
}
class Person
{
public:
    Person(string name,int age)
    {
        this->my_name=name;
        this->my_age=age;
    }
    string my_name;
    int my_age;
};

class Family
{
private:
    string drinks;
public:
    Family(string name = "饮料"): drinks(name) { }
    string getName()
    {
        return drinks;
    }
    virtual void like() //虚函数，可以在后续派生类中被重写
    {
        cout << "大家喜欢不同的饮料: " << endl;
    }
};

class Mother: public Family
{
public:
    Mother(string name = "可乐"): Family(name) { }
    void like()
    {
        cout << "妈妈喜欢" << getName() << endl;
    }
};

class Daughter: public Family
{
public:
    Daughter(string name = "雪碧"): Family(name) { }
    void like()
    {
        cout << "女儿喜欢" << getName() << endl;
    }
};

void test01()//容器使用
{
    vector<Person>v;
    Person p1("：董伟",666);
    Person p2("：沈凡",666);
    v.push_back(p1);
    v.push_back(p2);
    //遍历容器中的数据
    for(vector<Person>::iterator it = v.begin();it!=v.end();it++)
    {
        cout<<it->my_name<<"别卷了"<<"\n";
        Sleep(1000);
        cout<<it->my_name<<" : "<<it->my_age<<"\n";
        Sleep(1000);
    }
}
void test02(string str)//字符串拼接
{
    str+=str;
    cout<<str<<endl;
}
void test03()//查找字符串操作
{
    string str1="沈董伟凡";
    string str2="董伟沈凡不要卷了";
    int pos2=str2.rfind("董伟");//查找字符串中指定子串的最后一次出现位置
    int pos1=str2.find("沈凡");//如果找到了子串，则返回子串的起始位置；如果没找到，则返回-1
    cout<<"pos1 = "<<pos1<<endl;
    cout<<"pos2 = "<<pos2<<endl;
}
void test04(int x,int y)
{
    string name1="沈凡666";
    string name2="董伟666";
    if(x==1)
    {
        name1.replace(4,0,"又在卷");
    }
    if(y==1)
    {
        name2.replace(4,0,"又在卷");
    }
    cout<<name1<<endl;
    cout<<name2<<endl;
}

void test05()
{
    Family *p;
    Family family;
    Mother mother;
    Daughter daughter;
    p=&family;
    p->like();
    p=&mother;
    p->like();
    p=&daughter;
    p->like();
    return ;
}
int main()
{
    test01();
    test03();
    int op;
    test04(1,1);
    A(2).print();
    Score(2,3).showscore();//直接调用Score进行赋值操作并打印，打印完后编译器会自动进行析构函数操作
    //只有一次访问机会
    Score op1(99,100);//若先定义对象名再进行操作，则会先打印后，在执行完所有程序后进行析构函数操作
    //在程序结束前都可以进行反复访问
    Score op2(88);
    Score op3;
    op1.showscore();
    op2.showscore();
    op3.showscore();
    Student stu1("沈凡","212206433",99);
    stu1.modify(100);
    stu1.show();
    Student stu2("董伟","212206410",120);
    stu2.modify(100);
    stu2.show();
    test05();
    cout<<"你想吃大便味的巧克力还是巧克力味的大便？  //不吃选1，吃选0\n  1/0"<<endl;
    cin>>op;
    if(op==1)
    {
        cout<<"既然不吃，那就随便说点什么吧！";
        string str1;
        cin>>str1;
        test02(str1);
    }
    return 0;
}
