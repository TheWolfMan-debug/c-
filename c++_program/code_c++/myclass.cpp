#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class person
{
public:
    person(string name, int height, string sex)
    {
        this->m_name = name;
        this->m_height = height;
        this->m_sex = sex;
        cout << "这是person 的构造函数" << endl;
    }

    void operator=(person &p)
    {
        this->m_name = p.m_name;
        this->m_height = p.m_height;
        this->m_sex = p.m_sex;
    }

    person() {}

    person(person &p)
    {
        this->m_name = p.m_name;
        this->m_height = p.m_height;
        this->m_sex = p.m_sex;
    }
    ~person()
    {
        cout << "这是person 的析构函数" << endl;
    }

    void showPerson()
    {
        cout << "姓名： " << this->m_name << endl;
        cout << "性别： " << this->m_sex << endl;
        cout << "身高： " << this->m_height << endl;
    }

private:
    string m_name;
    int m_height;
    string m_sex;
};

void test01()
{
    person p1("wang", 180, "female");
    person p2 = p1;
    person p3(p2);
    p1.showPerson();
    p2.showPerson();
    p3.showPerson();


    person p4;
}

int main()
{
    test01();
    system("pause");
    return 0;
}