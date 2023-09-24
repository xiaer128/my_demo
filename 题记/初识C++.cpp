#include<iostream>
#include<vector>
#include<windows.h>
using namespace std;
class A//�������
{
private:
    int x;
    int& rx;//���ñ���
    const double pi;//����
public:
    A(int v) : x(v), rx(x), pi(3.14)    //��Ա��ʼ���б�
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
    ~Score();       //��������
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
    cout << "���캯��ʹ����..." << endl;
}

Score::~Score()
{
    cout << "��������ʹ����..." << endl;
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
    cout<<"��������ʹ���С�����"<<endl;
}

void Student::modify(float score1)
{
    score = score1;
}

void Student::show()
{
    cout << "����: " << name << endl;
    cout << "ѧ��: " << stu_no << endl;
    cout << "�ɼ���" << score << endl;
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
    Family(string name = "����"): drinks(name) { }
    string getName()
    {
        return drinks;
    }
    virtual void like() //�麯���������ں����������б���д
    {
        cout << "���ϲ����ͬ������: " << endl;
    }
};

class Mother: public Family
{
public:
    Mother(string name = "����"): Family(name) { }
    void like()
    {
        cout << "����ϲ��" << getName() << endl;
    }
};

class Daughter: public Family
{
public:
    Daughter(string name = "ѩ��"): Family(name) { }
    void like()
    {
        cout << "Ů��ϲ��" << getName() << endl;
    }
};

void test01()//����ʹ��
{
    vector<Person>v;
    Person p1("����ΰ",666);
    Person p2("����",666);
    v.push_back(p1);
    v.push_back(p2);
    //���������е�����
    for(vector<Person>::iterator it = v.begin();it!=v.end();it++)
    {
        cout<<it->my_name<<"�����"<<"\n";
        Sleep(1000);
        cout<<it->my_name<<" : "<<it->my_age<<"\n";
        Sleep(1000);
    }
}
void test02(string str)//�ַ���ƴ��
{
    str+=str;
    cout<<str<<endl;
}
void test03()//�����ַ�������
{
    string str1="��ΰ��";
    string str2="��ΰ�򷲲�Ҫ����";
    int pos2=str2.rfind("��ΰ");//�����ַ�����ָ���Ӵ������һ�γ���λ��
    int pos1=str2.find("��");//����ҵ����Ӵ����򷵻��Ӵ�����ʼλ�ã����û�ҵ����򷵻�-1
    cout<<"pos1 = "<<pos1<<endl;
    cout<<"pos2 = "<<pos2<<endl;
}
void test04(int x,int y)
{
    string name1="��666";
    string name2="��ΰ666";
    if(x==1)
    {
        name1.replace(4,0,"���ھ�");
    }
    if(y==1)
    {
        name2.replace(4,0,"���ھ�");
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
    Score(2,3).showscore();//ֱ�ӵ���Score���и�ֵ��������ӡ����ӡ�����������Զ�����������������
    //ֻ��һ�η��ʻ���
    Score op1(99,100);//���ȶ���������ٽ��в���������ȴ�ӡ����ִ�������г�������������������
    //�ڳ������ǰ�����Խ��з�������
    Score op2(88);
    Score op3;
    op1.showscore();
    op2.showscore();
    op3.showscore();
    Student stu1("��","212206433",99);
    stu1.modify(100);
    stu1.show();
    Student stu2("��ΰ","212206410",120);
    stu2.modify(100);
    stu2.show();
    test05();
    cout<<"����Դ��ζ���ɿ��������ɿ���ζ�Ĵ�㣿  //����ѡ1����ѡ0\n  1/0"<<endl;
    cin>>op;
    if(op==1)
    {
        cout<<"��Ȼ���ԣ��Ǿ����˵��ʲô�ɣ�";
        string str1;
        cin>>str1;
        test02(str1);
    }
    return 0;
}
