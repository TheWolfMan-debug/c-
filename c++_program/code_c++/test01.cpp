#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <functional>
#include <cstdlib>
#include <numeric>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;



// class Animal {
// public:

// 	Animal()
// 	{
// 		cout << "Animal 构造函数调用！" << endl;
// 	}
// 	virtual void Speak() = 0;

// 	//析构函数加上virtual关键字，变成虚析构函数
// 	//virtual ~Animal()
// 	//{
// 	//	cout << "Animal虚析构函数调用！" << endl;
// 	//}


// 	virtual ~Animal() = 0;
// };

// Animal::~Animal()
// {
// 	cout << "Animal 纯虚析构函数调用！" << endl;
// }

// //和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。

// class Cat : public Animal {
// public:
// 	Cat(string name)
// 	{
// 		cout << "Cat构造函数调用！" << endl;
// 		m_Name = new string(name);
// 	}
// 	virtual void Speak()
// 	{
// 		cout << *m_Name <<  "小猫在说话!" << endl;
// 	}
// 	~Cat()
// 	{
// 		cout << "Cat析构函数调用!" << endl;
// 		if (this->m_Name != NULL) {
// 			delete m_Name;
// 			m_Name = NULL;
// 		}
// 	}

// public:
// 	string *m_Name;
// };

// void test01()
// {
// 	Animal *animal = new Cat("Tom");
// 	animal->Speak();

// 	//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
// 	//怎么解决？给基类增加一个虚析构函数
// 	//虚析构函数就是用来解决通过父类指针释放子类对象
// 	delete animal;
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }




// //抽象制作饮品
// class AbstractDrinking {
// public:
// 	//烧水
// 	virtual void Boil() = 0;
// 	//冲泡
// 	virtual void Brew() = 0;
// 	//倒入杯中
// 	virtual void PourInCup() = 0;
// 	//加入辅料
// 	virtual void PutSomething() = 0;
// 	//规定流程
// 	void MakeDrink() {
// 		Boil();
// 		Brew();
// 		PourInCup();
// 		PutSomething();
// 	}
// };

// //制作咖啡
// class Coffee : public AbstractDrinking {
// public:
// 	//烧水
// 	virtual void Boil() {
// 		cout << "煮农夫山泉!" << endl;
// 	}
// 	//冲泡
// 	virtual void Brew() {
// 		cout << "冲泡咖啡!" << endl;
// 	}
// 	//倒入杯中
// 	virtual void PourInCup() {
// 		cout << "将咖啡倒入杯中!" << endl;
// 	}
// 	//加入辅料
// 	virtual void PutSomething() {
// 		cout << "加入牛奶!" << endl;
// 	}
// };

// //制作茶水
// class Tea : public AbstractDrinking {
// public:
// 	//烧水
// 	virtual void Boil() {
// 		cout << "煮自来水!" << endl;
// 	}
// 	//冲泡
// 	virtual void Brew() {
// 		cout << "冲泡茶叶!" << endl;
// 	}
// 	//倒入杯中
// 	virtual void PourInCup() {
// 		cout << "将茶水倒入杯中!" << endl;
// 	}
// 	//加入辅料
// 	virtual void PutSomething() {
// 		cout << "加入枸杞!" << endl;
// 	}
// };

// //业务函数
// void DoWork(AbstractDrinking* drink) {
// 	drink->MakeDrink();
// 	delete drink;
// }

// void test01() {
// 	DoWork(new Coffee);
// 	cout << "--------------" << endl;
// 	DoWork(new Tea);
// }


// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }



// class Base
// {
// public:
// 	//纯虚函数
// 	//类中只要有一个纯虚函数就称为抽象类
// 	//抽象类无法实例化对象
// 	//子类必须重写父类中的纯虚函数，否则也属于抽象类

// 	virtual void func() = 0;
// };

// class Son :public Base
// {
// public:
// 	virtual void func() 
// 	{
// 		cout << "func调用" << endl;
// 	}

// };

// void test01()
// {
// 	Base * base = NULL;
// 	// base = new Base; // 错误，抽象类无法实例化对象
// 	base = new Son;
// 	base->func();
// 	delete base;//记得销毁
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }






// class Calculator
// {
// public:
// 	int getResult(string oper)
// 	{
// 		if (oper == "+")
// 		{
// 			return m_Num1 + m_Num2;
// 		}
// 		else if (oper == "-")
// 		{
// 			return m_Num1 - m_Num2;
// 		}
// 		else if (oper == "*")
// 		{
// 			return m_Num1 * m_Num2;
// 		}
// 		//如果要提供新的运算，需要修改源码
// 		return 0;
// 	}

// public:
// 	int m_Num1;
// 	int m_Num2;
// };

// void test01()
// {
// 	//普通实现测试
// 	Calculator c;
// 	c.m_Num1 = 10;
// 	c.m_Num2 = 10;
// 	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;

// 	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;

// 	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
// }

// //多态实现
// //抽象计算器类
// //多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护
// class AbstractCalculator
// {
// public:
// 	virtual int getResult()
// 	{
// 		return 0;
// 	}

// 	int m_Num1;
// 	int m_Num2;
// };

// //加法计算器
// class AddCalculator : public AbstractCalculator
// {
// public:
// 	int getResult()
// 	{
// 		return m_Num1 + m_Num2;
// 	}
// };

// //减法计算器
// class SubCalculator : public AbstractCalculator
// {
// public:
// 	int getResult()
// 	{
// 		return m_Num1 - m_Num2;
// 	}
// };

// //乘法计算器
// class MulCalculator : public AbstractCalculator
// {
// public:
// 	int getResult()
// 	{
// 		return m_Num1 * m_Num2;
// 	}
// };

// void test02()
// {
// 	//创建加法计算器
// 	AbstractCalculator *abc = new AddCalculator;
// 	abc->m_Num1 = 10;
// 	abc->m_Num2 = 10;
// 	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
// 	delete abc; //用完了记得销毁

// 	//创建减法计算器
// 	abc = new SubCalculator;
// 	abc->m_Num1 = 10;
// 	abc->m_Num2 = 10;
// 	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
// 	delete abc;

// 	//创建乘法计算器
// 	abc = new MulCalculator;
// 	abc->m_Num1 = 10;
// 	abc->m_Num2 = 10;
// 	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
// 	delete abc;
// }

// int test03(AbstractCalculator &abs,string ch)
// {
// 	abs.m_Num1 = 10;
// 	abs.m_Num2 = 10;
// 	cout << abs.m_Num1 << ch << abs.m_Num2 << " = " << abs.getResult() << endl;
// 	return abs.getResult();
// }

// int main()
// {

// 	//test01();

// 	// test02();

// 	AddCalculator add;
// 	SubCalculator sub;
// 	MulCalculator mul;

// 	test03(add,"+");
// 	test03(sub,"-");
// 	test03(mul,"*");

// 	system("pause");

// 	return 0;
// }

// class Animal
// {
// public:
// 	//Speak函数就是虚函数
// 	//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
// 	virtual void speak()
// 	{
// 		cout << "动物在说话" << endl;
// 	}
// };

// class Cat :public Animal
// {
// public:
// 	void speak()
// 	{
// 		cout << "小猫在说话" << endl;
// 	}
// };

// class Dog :public Animal
// {
// public:

// 	void speak()
// 	{
// 		cout << "小狗在说话" << endl;
// 	}

// };
// //我们希望传入什么对象，那么就调用什么对象的函数
// //如果函数地址在编译阶段就能确定，那么静态联编
// //如果函数地址在运行阶段才能确定，就是动态联编

// void DoSpeak(Animal & animal)
// {
// 	animal.speak();
// }
// //
// //多态满足条件：
// //1、有继承关系
// //2、子类重写父类中的虚函数
// //多态使用：
// //父类指针或引用指向子类对象

// void test01()
// {
// 	Cat cat;
// 	DoSpeak(cat);

// 	Dog dog;
// 	DoSpeak(dog);
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// class Animal
// {
// public:
// 	int m_Age;
// };

// //继承前加virtual关键字后，变为虚继承
// //此时公共的父类Animal称为虚基类
// class Sheep : virtual public Animal {};
// class Tuo   : virtual public Animal {};
// class SheepTuo : public Sheep, public Tuo {};

// void test01()
// {
// 	SheepTuo st;
// 	st.Sheep::Animal::m_Age = 100;
// 	st.Tuo::m_Age = 200;

// 	cout << "st.Sheep::Animal::m_Age = " << st.Sheep::Animal::m_Age << endl;
// 	cout << "st.Tuo::m_Age = " <<  st.Tuo::m_Age << endl;
// 	cout << "st.m_Age = " << st.m_Age << endl;
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// class Base {
// public:
// 	Base()
// 	{
// 		m_A = 100;
// 	}

// 	void func()
// 	{
// 		cout << "Base - func()调用" << endl;
// 	}

// 	void func(int a)
// 	{
// 		cout << "Base - func(int a)调用" << endl;
// 	}

// public:
// 	int m_A;
// };

// class Son : public Base {
// public:
// 	Son()
// 	{
// 		m_A = 200;
// 	}

// 	//当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
// 	//如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
// 	void func()
// 	{
// 		cout << "Son - func()调用" << endl;
// 	}
// public:
// 	int m_A;
// };

// void test01()
// {
// 	Son s;

// 	cout << "Son下的m_A = " << s.m_A << endl;
// 	cout << "Base下的m_A = " << s.Base::m_A << endl;

// 	s.func();
// 	s.Base::func();
// 	s.Base::func(10);

// }
// int main() {

// 	test01();

// 	system("pause");
// 	return EXIT_SUCCESS;
// }

// class Base
// {
// public:
// 	int m_A;
// protected:
// 	int m_B;
// private:
// 	int m_C; //私有成员只是被隐藏了，但是还是会继承下去
// };

// //公共继承
// class Son :public Base
// {
// public:
// 	int m_D;
// };

// void test01()
// {
// 	cout << "sizeof Son = " << sizeof(Son) << endl;
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// class MyPrint
// {
// public:
// 	void operator()(string text)
// 	{
// 		cout << text << endl;
// 	}

// };
// void test01()
// {
// 	//重载的（）操作符 也称为仿函数
// 	MyPrint myFunc;
// 	myFunc("hello world");
// }

// class MyAdd
// {
// public:
// 	int operator()(int v1, int v2)
// 	{
// 		return v1 + v2;
// 	}
// };

// void test02()
// {
// 	MyAdd add;
// 	int ret = add(10, 10);
// 	MyAdd ad = MyAdd();
// 	cout << "ret = " << ret << endl;
// 	cout << "ret = " << ad(10,10) << endl;

// 	//匿名对象调用
// 	cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
// }

// int main() {

// 	test01();
// 	test02();

// 	system("pause");

// 	return 0;
// }

// class MyInteger {

// 	friend ostream& operator<<(ostream& out, MyInteger myint);

// public:
// 	MyInteger() {
// 		m_Num = 0;
// 	}
// 	//前置++
// 	MyInteger& operator++() {
// 		//先++
// 		m_Num++;
// 		//再返回
// 		return *this;
// 	}

// 	//后置++
// 	MyInteger operator++(int) {
// 		//先返回
// 		MyInteger temp = *this; //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
// 		m_Num++;
// 		return temp;
// 	}

// private:
// 	int m_Num;
// };

// ostream& operator<<(ostream& out, MyInteger myint) {
// 	out << myint.m_Num;
// 	return out;
// }

// //前置++ 先++ 再返回
// void test01() {
// 	MyInteger myInt;
// 	cout << ++myInt << endl;
// 	cout << myInt << endl;
// }

// //后置++ 先返回 再++
// void test02() {

// 	MyInteger myInt;
// 	cout << myInt++ << endl;
// 	cout << myInt << endl;
// }

// int main() {

// 	test01();
// 	test02();

// 	system("pause");

// 	return 0;
// }

// class Person {
// 	friend ostream& operator<<(ostream& out, Person& p);

// public:

// 	Person(int a, int b)
// 	{
// 		this->m_A = a;
// 		this->m_B = b;
// 	}

// 	//成员函数 实现不了  p << cout 不是我们想要的效果
// 	//void operator<<(Person& p){
// 	//}

// private:
// 	int m_A;
// 	int m_B;
// };

// //全局函数实现左移重载
// //ostream对象只能有一个
// ostream& operator<<(ostream& cout, Person& p) {
// 	cout << "a:" << p.m_A << " b:" << p.m_B;
// 	return cout;
// }

// void test() {

// 	Person p1(10, 20);

// 	cout << p1 << endl << "hello world" << endl; //链式编程
// }

// int main() {

// 	test();

// 	system("pause");

// 	return 0;
// }

// class Person {
// public:
// 	Person() {
// 		m_A = 0;
// 		m_B = 0;
// 	}

// 	//this指针的本质是一个指针常量，指针的指向不可修改
// 	//如果想让指针指向的值也不可以修改，需要声明常函数
// 	void ShowPerson() const {
// 		//const Type* const pointer;
// 		//this = NULL; //不能修改指针的指向 Person* const this;
// 		//this->mA = 100; //但是this指针指向的对象的数据是可以修改的

// 		//const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
// 		this->m_B = 100;
// 	}

// 	void MyFunc() const {
// 		//mA = 10000;
// 		cout << "MyFunc" << endl;
// 	}

// public:
// 	int m_A;
// 	mutable int m_B; //可修改 可变的
// };

// //const修饰对象  常对象
// void test01() {

// 	const Person person; //常量对象
// 	cout << person.m_A << endl;
// 	//person.mA = 100; //常对象不能修改成员变量的值,但是可以访问
// 	person.m_B = 100; //但是常对象可以修改mutable修饰成员变量

// 	//常对象访问成员函数
// 	person.MyFunc(); //常对象不能调用const的函数

// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// class Person
// {
// public:

// 	Person(int age)
// 	{
// 		//1、当形参和成员变量同名时，可用this指针来区分
// 		this->age = age;
// 	}

// 	Person& PersonAddPerson(Person p)
// 	{
// 		this->age += p.age;
// 		//返回对象本身
// 		return *this;
// 	}

// 	int age;
// };

// void test01()
// {
// 	Person p1(10);
// 	cout << "p1.age = " << p1.age << endl;

// 	Person p2(10);
// 	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
// 	cout << "p2.age = " << p2.age << endl;
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// class Person
// {
// public:
// 	Person()
// 	{
// 		mA = 0;
// 	}
// 	//非静态成员变量占对象空间
// 	int mA;
// 	//静态成员变量不占对象空间
// 	static int mB;
// 	//函数也不占对象空间，所有函数共享一个函数实例
// 	void func()
// 	{
// 		cout << "mA:" << this->mA << endl;
// 	}
// 	//静态成员函数也不占对象空间
// 	static void sfunc()
// 	{
// 	}
// };

// int main()
// {
// 	Person p;
// 	Person p1;

// 	// cout << sizeof(Person) << endl;
// 	// cout << sizeof(p) << endl;
// 	p.func();
// 	p1.mA = 2;
// 	p1.func();

// 	system("pause");

// 	return 0;
// }

// class Person
// {

// public:

// 	static int m_A; //静态成员变量

// 	//静态成员变量特点：
// 	//1 在编译阶段分配内存
// 	//2 类内声明，类外初始化
// 	//3 所有对象共享同一份数据

// private:
// 	static int m_B; //静态成员变量也是有访问权限的

// public:
// 	int get_m_B()
// 	{
// 		return m_B;
// 	}
// 	void set_m_B(int m_b)
// 	{
// 		m_B = m_b;
// 	}
// };
// int Person::m_A = 10;
// int Person::m_B = 10;

// void test01()
// {
// 	//静态成员变量两种访问方式

// 	//1、通过对象
// 	Person p1;
// 	p1.m_A = 100;
// 	cout << "p1.m_A = " << p1.m_A << endl;

// 	Person p2;
// 	p2.m_A = 200;
// 	cout << "p1.m_A = " << p1.m_A << endl; //共享同一份数据
// 	cout << "p2.m_A = " << p2.m_A << endl;

// 	//2、通过类名
// 	cout << "m_A = " << Person::m_A << endl;

// 	p2.set_m_B(5);
// 	cout << "m_B = " << p2.get_m_B() << endl; //私有权限访问不到
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// class Phone
// {
// public:
// 	Phone(string name)
// 	{
// 		m_PhoneName = name;
// 		cout << "Phone构造" << endl;
// 	}

// 	~Phone()
// 	{
// 		cout << "Phone析构" << endl;
// 	}

// 	string m_PhoneName;

// };

// class Person
// {
// public:

// 	//初始化列表可以告诉编译器调用哪一个构造函数
// 	Person(string name, string pName) :m_Name(name), m_Phone(pName)
// 	{
// 		cout << "Person构造" << endl;
// 	}

// 	~Person()
// 	{
// 		cout << "Person析构" << endl;
// 	}

// 	void playGame()
// 	{
// 		cout << m_Name << " 使用" << m_Phone.m_PhoneName << " 牌手机! " << endl;
// 	}

// 	string m_Name;
// 	Phone m_Phone;

// };
// void test01()
// {
// 	//当类中成员是其他类对象时，我们称该成员为 对象成员
// 	//构造的顺序是 ：先调用对象成员的构造，再调用本类构造
// 	//析构顺序与构造相反
// 	Person p("张三" , "苹果X");
// 	p.playGame();

// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// class Person {
// public:

// 	////传统方式初始化
// 	//Person(int a, int b, int c) {
// 	//	m_A = a;
// 	//	m_B = b;
// 	//	m_C = c;
// 	//}

// 	//初始化列表方式初始化
// 	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}
// 	void PrintPerson() {
// 		cout << "mA:" << m_A << endl;
// 		cout << "mB:" << m_B << endl;
// 		cout << "mC:" << m_C << endl;
// 	}
// private:
// 	int m_A;
// 	int m_B;
// 	int m_C;
// };

// int main() {

// 	Person p(1, 2, 3);
// 	p.PrintPerson();

// 	system("pause");

// 	return 0;
// }

// class Person {
// public:
// 	//无参（默认）构造函数
// 	Person() {
// 		cout << "无参构造函数!" << endl;
// 	}
// 	//有参构造函数
// 	Person(int age ,int height) {

// 		cout << "有参构造函数!" << endl;

// 		m_age = age;
// 		m_height = new int(height);

// 	}
// 	//拷贝构造函数
// 	Person(const Person& p) {
// 		cout << "拷贝构造函数!" << endl;
// 		//如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
// 		m_age = p.m_age;
// 		m_height = new int(*p.m_height);
// 		// m_height = p.m_height;

// 	}

// 	//析构函数
// 	~Person() {
// 		cout << "析构函数!" << endl;
// 		if (m_height != NULL)
// 		{
// 			delete m_height;
// 		}
// 	}
// public:
// 	int m_age;
// 	int* m_height;
// };

// void test01()
// {
// 	Person p1(18, 180);

// 	Person p2(p1);

// 	cout << "p1的年龄： " << p1.m_age << " 身高： " << *p1.m_height << endl;

// 	cout << "p2的年龄： " << p2.m_age << " 身高： " << *p2.m_height << endl;
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// class Person {
// public:
// 	//无参（默认）构造函数
// 	Person() {
// 		cout << "无参构造函数!" << endl;
// 	}
// 	//有参构造函数
// 	Person(int a) {
// 		age = a;
// 		cout << "有参构造函数!" << endl;
// 	}
// 	//拷贝构造函数
// 	Person(const Person& p) {
// 		age = p.age;
// 		cout << "拷贝构造函数!" << endl;
// 	}
// 	//析构函数
// 	~Person() {
// 		cout << "析构函数!" << endl;
// 	}
// public:
// 	int age;
// };

// void test01()
// {
// 	Person p;

// 	Person p1(18);
// 	//如果不写拷贝构造，编译器会自动添加拷贝构造，并且做浅拷贝操作
// 	Person p2(p1);

// 	cout << "p2的年龄为： " << p2.age << endl;
// }

// void test02()
// {
// 	//如果用户提供有参构造，编译器不会提供默认构造，会提供拷贝构造
// 	Person p1; //此时如果用户自己没有提供默认构造，会出错
// 	Person p2(10); //用户提供的有参
// 	Person p3(p2); //此时如果用户没有提供拷贝构造，编译器会提供

// 	//如果用户提供拷贝构造，编译器不会提供其他构造函数
// 	Person p4; //此时如果用户自己没有提供默认构造，会出错
// 	Person p5(10); //此时如果用户自己没有提供有参，会出错
// 	Person p6(p5); //用户自己提供拷贝构造
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// class Person
// {
// public:
// 	Person()
// 	{
// 		cout << "无参构造函数!" << endl;
// 		mAge = 0;
// 	}
// 	Person(int age)
// 	{
// 		cout << "有参构造函数!" << endl;
// 		mAge = age;
// 	}
// 	Person(const Person &p)
// 	{
// 		cout << "拷贝构造函数!" << endl;
// 		mAge = p.mAge;
// 	}
// 	//析构函数在释放内存之前调用
// 	~Person()
// 	{
// 		cout << "析构函数!" << endl;
// 	}

// public:
// 	int mAge;
// };

// //1. 使用一个已经创建完毕的对象来初始化一个新对象
// void test01()
// {

// 	Person man(100);	  //p对象已经创建完毕
// 	Person newman(man);	  //调用拷贝构造函数
// 	Person newman2 = man; //拷贝构造

// 	//Person newman3;
// 	//newman3 = man; //不是调用拷贝构造函数，赋值操作
// }

// //2. 值传递的方式给函数参数传值
// //相当于Person p1 = p;
// void doWork(Person p1)
// {
// 	cout << (int *)&p1 << endl;
// }
// void test02()
// {
// 	Person p; //无参构造函数
// 	cout << (int *)&p << endl;
// 	doWork(p);
// }

// //3. 以值方式返回局部对象
// Person doWork2()
// {
// 	Person p1;
// 	cout << (int *)&p1 << endl;
// 	return p1;
// }

// void test03()
// {
// 	Person p = doWork2();
// 	cout << (int *)&p << endl;
// }

// int main()
// {

// 	test01();
// 	// test02();
// 	// test03();

// 	system("pause");

// 	return 0;
// }

// class Person
// {
// public:
// 	//构造函数
// 	Person()
// 	{
// 		cout << "Person的构造函数调用" << endl;
// 	}
// 	//析构函数
// 	~Person()
// 	{
// 		cout << "Person的析构函数调用" << endl;
// 	}

// };

// void test01()
// {
// 	Person p;
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// //学生类
// class Student {
// public:
// 	void setName(string name) {
// 		m_name = name;
// 	}
// 	void setID(int id) {
// 		m_id = id;
// 	}

// 	void showStudent() {
// 		cout << "name:" << m_name << " ID:" << m_id << endl;
// 	}
// public:
// 	string m_name;
// 	int m_id;
// };

// int main() {

// 	Student stu;
// 	stu.setName("德玛西亚");
// 	stu.setID(250);
// 	stu.showStudent();

// 	system("pause");

// 	return 0;
// }

// //圆周率
// const double PI = 3.14;

// //1、封装的意义
// //将属性和行为作为一个整体，用来表现生活中的事物

// //封装一个圆类，求圆的周长
// //class代表设计一个类，后面跟着的是类名
// class Circle
// {
// public:  //访问权限  公共的权限

// 	//属性
// 	int m_r;//半径

// 	//行为
// 	//获取到圆的周长
// 	double calculateZC()
// 	{
// 		//2 * pi  * r
// 		//获取圆的周长
// 		return  2 * PI * m_r;
// 	}
// };

// int main() {

// 	//通过圆类，创建圆的对象
// 	// c1就是一个具体的圆
// 	Circle c1;
// 	c1.m_r = 10; //给圆对象的半径 进行赋值操作

// 	//2 * pi * 10 = = 62.8
// 	cout << "圆的周长为： " << c1.calculateZC() << endl;

// 	system("pause");

// 	return 0;
// }

// int func(int a, int b = 10, int c = 10) {
// 	return a + b + c;
// }

// //1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
// //2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
// int func2(int a, int b);
// int func2(int a = 10, int b = 10) {
// 	return a + b;
// }

// int main() {

// 	cout << "ret = " << func(20, 20) << endl;
// 	cout << "ret = " << func(100) << endl;

// 	cout << "ret = " << func2(20, 20) << endl;
// 	cout << "ret = " << func2(100) << endl;

// 	system("pause");

// 	return 0;
// }

// //引用使用的场景，通常用来修饰形参
// void showValue(const int& v) {
// 	//v += 10;
// 	cout << v << endl;
// }

// int main() {

// 	//int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
// 	//加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
// 	const int& ref = 10;

// 	//ref = 100;  //加入const后不可以修改变量
// 	cout << ref << endl;

// 	//函数中利用常量引用防止误操作修改实参
// 	int a = 10;
// 	showValue(ref);

// 	system("pause");

// 	return 0;
// }

// //发现是引用，转换为 int* const ref = &a;
// void func(int& ref){
// 	ref = 100; // ref是引用，转换为*ref = 100
// }
// int main(){
// 	int a = 10;

//     //自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
// 	int& ref = a;
// 	ref = 20; //内部发现ref是引用，自动帮我们转换为: *ref = 20;

// 	cout << "a:" << a << endl;
// 	cout << "ref:" << ref << endl;

// 	func(a);

// 	cout << "a:" << a << endl;
// 	cout << "ref:" << ref << endl;
// 	return 0;
// }

// // //返回局部变量引用
// // int& test01() {
// // 	int a = 10; //局部变量
// // 	return a;
// // }

// //返回静态变量引用
// int& test02() {
// 	static int a = 20;
// 	return a;
// }

// int main() {

// 	//不能返回局部变量的引用
// 	// int& ref = test01();
// 	// cout << "ref = " << ref << endl;
// 	// cout << "ref = " << ref << endl;

// 	//如果函数做左值，那么必须返回引用
// 	int& ref2 = test02();
// 	cout << "ref2 = " << ref2 << endl;
// 	cout << "ref2 = " << ref2 << endl;

// 	test02() = 1000;

// 	cout << "ref2 = " << ref2 << endl;
// 	cout << "ref2 = " << ref2 << endl;

// 	system("pause");

// 	return 0;
// }

// int main() {

// 	int a = 10;
// 	int &b = a;

// 	cout << "a = " << a << endl;
// 	cout << "b = " << b << endl;

// 	b = 100;

// 	cout << "a = " << a << endl;
// 	cout << "b = " << b << endl;

// 	system("pause");

// 	return 0;
// }

// //堆区开辟数组
// int main() {

// 	int* arr = new int[10];

// 	for (int i = 0; i < 10; i++)
// 	{
// 		arr[i] = i + 100;
// 	}

// 	for (int i = 0; i < 10; i++)
// 	{
// 		cout << arr[i] << endl;
// 	}
// 	//释放数组 delete 后加 []
// 	delete[] arr;

// 	system("pause");

// 	return 0;
// }

// int* func()
// {
// 	int* a = new int(10);
// 	return a;
// }

// int main() {

// 	int *p = func();

// 	cout << *p << endl;
// 	cout << *p << endl;

// 	//利用delete释放堆区数据
// 	delete p;

// 	// cout << *p << endl; //报错，释放的空间不可访问
// 	// cout << *p << endl; //报错，释放的空间不可访问

// 	system("pause");

// 	return 0;
// }

// int* func()
// {
// 	int* a = new int(10);
// 	return a;
// }

// int main() {

// 	int *p = func();

// 	cout << *p << endl;
// 	cout << *p << endl;

// 	system("pause");

// 	return 0;
// }

// int * func()
// {
// 	int a = 10;
// 	return &a;
// }

// int main() {

// 	int *p = func();

// 	cout << *p << endl;
// 	cout << *p << endl;

// 	system("pause");

// 	return 0;
// }

// //全局变量
// int g_a = 10;
// int g_b = 10;

// //全局常量
// const int c_g_a = 10;
// const int c_g_b = 10;

// int main() {

// 	//局部变量
// 	int a = 10;
// 	int b = 10;

// 	//打印地址
// 	cout << "局部变量a地址为： " << (int)&a << endl;
// 	cout << "局部变量b地址为： " << (int)&b << endl;

// 	cout << "全局变量g_a地址为： " <<  (int)&g_a << endl;
// 	cout << "全局变量g_b地址为： " <<  (int)&g_b << endl;

// 	//静态变量
// 	static int s_a = 10;
// 	static int s_b = 10;

// 	cout << "静态变量s_a地址为： " << (int)&s_a << endl;
// 	cout << "静态变量s_b地址为： " << (int)&s_b << endl;

// 	cout << "字符串常量地址为： " << (int)&"hello world" << endl;
// 	cout << "字符串常量地址为： " << (int)&"hello world1" << endl;

// 	cout << "全局常量c_g_a地址为： " << (int)&c_g_a << endl;
// 	cout << "全局常量c_g_b地址为： " << (int)&c_g_b << endl;

// 	const int c_l_a = 10;
// 	const int c_l_b = 10;
// 	cout << "局部常量c_l_a地址为： " << (int)&c_l_a << endl;
// 	cout << "局部常量c_l_b地址为： " << (int)&c_l_b << endl;

// 	system("pause");

// 	return 0;
// }

// //英雄结构体
// struct hero
// {
// 	string name;
// 	int age;
// 	string sex;
// };
// //冒泡排序
// void bubbleSort(hero arr[], int len)
// {
// 	for (int i = 0; i < len - 1; i++)
// 	{
// 		for (int j = 0; j < len - 1 - i; j++)
// 		{
// 			if (arr[j].age > arr[j + 1].age)
// 			{
// 				hero temp = arr[j];
// 				arr[j] = arr[j + 1];
// 				arr[j + 1] = temp;
// 			}
// 		}
// 	}
// }
// //打印数组
// void printHeros(hero arr[], int len)
// {
// 	for (int i = 0; i < len; i++)
// 	{
// 		cout << "姓名： " << arr[i].name << " 性别： " << arr[i].sex << " 年龄： " << arr[i].age << endl;
// 	}
// 	cout << "------------------------------" << endl;
// }

// int main()
// {

// 	struct hero arr[5] =
// 		{
// 			{"刘备", 23, "男"},
// 			{"关羽", 22, "男"},
// 			{"张飞", 20, "男"},
// 			{"赵云", 21, "男"},
// 			{"貂蝉", 19, "女"},
// 		};

// 	int len = sizeof(arr) / sizeof(hero); //获取数组元素个数

// 	printHeros(arr, len); //打印

// 	bubbleSort(arr, len); //排序

// 	printHeros(arr, len); //打印

// 	system("pause");

// 	return 0;
// }

// struct Student
// {
// 	string name;
// 	int score;
// };
// struct Teacher
// {
// 	string name;
// 	Student sArray[5];
// };

// void allocateSpace(Teacher tArray[] , int len)
// {
// 	string tName = "教师";
// 	string sName = "学生";
// 	string nameSeed = "ABCDE";
// 	for (int i = 0; i < len; i++)
// 	{
// 		tArray[i].name = tName + nameSeed[i];

// 		for (int j = 0; j < 5; j++)
// 		{
// 			tArray[i].sArray[j].name = sName + nameSeed[j];
// 			tArray[i].sArray[j].score = rand() % 61 + 40;
// 		}
// 	}
// }

// void printTeachers(Teacher tArray[], int len)
// {
// 	for (int i = 0; i < len; i++)
// 	{
// 		cout << tArray[i].name << endl;
// 		for (int j = 0; j < 5; j++)
// 		{
// 			cout << "\t姓名：" << tArray[i].sArray[j].name << " 分数：" << tArray[i].sArray[j].score << endl;
// 		}
// 	}
// }

// int main() {

// 	srand((unsigned int)time(NULL)); //随机数种子 头文件 #include <ctime>

// 	Teacher tArray[3]; //老师数组

// 	int len = sizeof(tArray) / sizeof(Teacher);

// 	allocateSpace(tArray, len); //创建数据

// 	printTeachers(tArray, len); //打印数据

// 	system("pause");

// 	return 0;
// }

// //学生结构体定义
// struct student
// {
// 	//成员列表
// 	string name;  //姓名
// 	int age;      //年龄
// 	int score;    //分数
// };

// //教师结构体定义
// struct teacher
// {
//     //成员列表
// 	int id; //职工编号
// 	string name;  //教师姓名
// 	int age;   //教师年龄
// 	struct student stu; //子结构体 学生
// };

// int main() {

// 	struct teacher t1;
// 	t1.id = 10000;
// 	t1.name = "老王";
// 	t1.age = 40;

// 	t1.stu.name = "张三";
// 	t1.stu.age = 18;
// 	t1.stu.score = 100;

// 	cout << "教师 职工编号： " << t1.id << " 姓名： " << t1.name << " 年龄： " << t1.age << endl;

// 	cout << "辅导学员 姓名： " << t1.stu.name << " 年龄：" << t1.stu.age << " 考试分数： " << t1.stu.score << endl;

// 	system("pause");

// 	return 0;
// }

// //结构体定义
// struct student
// {
// 	//成员列表
// 	string name;  //姓名
// 	int age;      //年龄
// 	int score;    //分数
// };

// int main() {

// 	struct student stu = { "张三",18,100, };

// 	struct student * p = &stu;

// 	p->score = 80; //指针通过 -> 操作符可以访问成员

// 	cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;

// 	system("pause");

// 	return 0;
// }

// //冒泡排序函数
// void bubbleSort(int * arr, int len)  //int * arr 也可以写为int arr[]
// {
// 	for (int i = 0; i < len - 1; i++)
// 	{
// 		for (int j = 0; j < len - 1 - i; j++)
// 		{
// 			if (arr[j] > arr[j + 1])
// 			{
// 				int temp = arr[j];
// 				arr[j] = arr[j + 1];
// 				arr[j + 1] = temp;
// 			}
// 		}
// 	}
// }

// //打印数组函数
// void printArray(int arr[], int len)
// {
// 	for (int i = 0; i < len; i++)
// 	{
// 		cout << arr[i] << endl;
// 	}
// }

// int main() {

// 	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
// 	int len = sizeof(arr) / sizeof(int);

// 	bubbleSort(arr, len);

// 	printArray(arr, len);

// 	system("pause");

// 	return 0;
// }

// //值传递
// void swap1(int a ,int b)
// {
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }
// //地址传递
// void swap2(int * p1, int *p2)
// {
// 	int temp = *p1;
// 	*p1 = *p2;
// 	*p2 = temp;
// }

// int main() {

// 	int a = 10;
// 	int b = 20;
// 	swap1(a, b); // 值传递不会改变实参

// 	swap2(&a, &b); //地址传递会改变实参

// 	cout << "a = " << a << endl;

// 	cout << "b = " << b << endl;

// 	system("pause");

// 	return 0;
// }

// int main() {

// 	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

// 	int * p = arr;  //指向数组的指针

// 	cout << "第一个元素： " << arr[0] << endl;
// 	cout << "指针访问第一个元素： " << *p << endl;

// 	for (int i = 0; i < 10; i++)
// 	{
// 		//利用指针遍历数组
// 		cout << *p << endl;
// 		p++;
// 	}

// 	system("pause");

// 	return 0;
// }

// int main() {

// 	int a = 10;
// 	int b = 10;

// 	// //const修饰的是指针，指针指向可以改，指针指向的值不可以更改
// 	// const int * p1 = &a;
// 	// p1 = &b; //正确
// 	// // *p1 = 100;  报错

// 	// //const修饰的是常量，指针指向不可以改，指针指向的值可以更改
// 	// int * const p2 = &a;
// 	// //p2 = &b; //错误
// 	// // *p2 = 100; //正确

//     // //const既修饰指针又修饰常量
// 	// const int * const p3 = &a;
// 	// //p3 = &b; //错误
// 	// // *p3 = 100; //错误

// 	system("pause");

// 	return 0;
// }

// int main() {

// 	//指针变量p指向内存地址编号为0x1100的空间
// 	int * p = (int *)0x1100;

// 	//访问野指针报错
// 	cout << *p << endl;

// 	system("pause");

// 	return 0;
// }

// int main() {

// 	//指针变量p指向内存地址编号为0的空间
// 	int * p = NULL;

// 	//访问空指针报错
// 	//内存编号0 ~255为系统占用内存，不允许用户访问
// 	cout << *p << endl;

// 	system("pause");

// 	return 0;
// }

// int main() {

// 	int a = 10;

// 	int * p;
// 	p = &a; //指针指向数据a的地址

// 	cout << *p << endl; //* 解引用
// 	cout << sizeof(p) << endl;
// 	cout << sizeof(char *) << endl;
// 	cout << sizeof(float *) << endl;
// 	cout << sizeof(double *) << endl;

// 	system("pause");

// 	return 0;
// }

// int main() {

// 	//1、指针的定义
// 	int a = 10; //定义整型变量a

// 	//指针定义语法： 数据类型 * 变量名 ;
// 	int * p;

// 	//指针变量赋值
// 	p = &a; //指针指向变量a的地址
// 	cout << &a << endl; //打印数据a的地址
// 	cout << p << endl;  //打印指针变量p

// 	//2、指针的使用
// 	//通过*操作指针变量指向的内存
// 	cout << "*p = " << *p << endl;

// 	system("pause");

// 	return 0;
// }

// int main()
// {

// 	//声明可以多次，定义只能一次
// 	//声明
// 	// int max(int a, int b);

// 	int a = 100;
// 	int b = 200;

// 	cout << max(a, b) << endl;

// 	system("pause");

// 	return 0;
// }

// //定义
// int max(int a, int b)
// {
// 	return a > b ? a : b;
// }

// int main() {

// 	int scores[3][3] =
// 	{
// 		{100,100,100},
// 		{90,50,100},
// 		{60,70,80},
// 	};

// 	string names[3] = { "张三","李四","王五" };

// 	for (int i = 0; i < 3; i++)
// 	{
// 		int sum = 0;
// 		for (int j = 0; j < 3; j++)
// 		{
// 			sum += scores[i][j];
// 		}
// 		cout << names[i] << "同学总成绩为： " << sum << endl;
// 	}

// 	system("pause");

// 	return 0;
// }

// int main() {

// 	//二维数组数组名
// 	int arr[2][3] =
// 	{
// 		{1,2,3},
// 		{4,5,6}
// 	};

// 	cout << "二维数组大小： " << sizeof(arr) << endl;
// 	cout << "二维数组一行大小： " << sizeof(arr[0]) << endl;
// 	cout << "二维数组元素大小： " << sizeof(arr[0][0]) << endl;

// 	cout << "二维数组行数： " << sizeof(arr) / sizeof(arr[0]) << endl;
// 	cout << "二维数组列数： " << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

// 	//地址
// 	cout << "二维数组首地址：" << arr << endl;
// 	cout << "二维数组第一行地址：" << arr[0] << endl;
// 	cout << "二维数组第二行地址：" << arr[1] << endl;

// 	cout << "二维数组第一个元素地址：" << &arr[0][0] << endl;
// 	cout << "二维数组第二个元素地址：" << &arr[0][1] << endl;

// 	system("pause");

// 	return 0;
// }

// int main() {

// 	int arr[9] = { 4,2,8,0,5,7,1,3,9 };

// 	for (int i = 0; i < 9 - 1; i++)
// 	{
// 		for (int j = 0; j < 9 - 1 - i; j++)
// 		{
// 			if (arr[j] > arr[j + 1])
// 			{
// 				int temp = arr[j];
// 				arr[j] = arr[j + 1];
// 				arr[j + 1] = temp;
// 			}
// 		}
// 	}

// 	for (int i = 0; i < 9; i++)
// 	{
// 		cout << arr[i] << endl;
// 	}

// 	system("pause");

// 	return 0;
// }

// int main()
// {

// 	//数组名用途
// 	//1、可以获取整个数组占用内存空间大小
// 	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// 	cout << "整个数组所占内存空间为： " << sizeof(arr) << endl;
// 	cout << "每个元素所占内存空间为： " << sizeof(arr[0]) << endl;
// 	cout << "数组的元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;

// 	//2、可以通过数组名获取到数组首地址
// 	cout << "数组首地址为： " << (arr) << endl;
// 	cout << "数组中第一个元素地址为： " << (&arr[0]) << endl;
// 	cout << "数组中第二个元素地址为： " << (&arr[1]) << endl;

// 	//arr = 100; 错误，数组名是常量，因此不可以赋值

// 	system("pause");

// 	return 0;
// }

// int main() {

// 	cout << "1" << endl;

// 	goto FLAG;

// 	cout << "2" << endl;
// 	cout << "3" << endl;
// 	cout << "4" << endl;

// 	FLAG:

// 	cout << "5" << endl;

// 	system("pause");

// 	return 0;
// }

// int main() {
// 	//在嵌套循环语句中使用break，退出内层循环
// 	for (int i = 0; i < 10; i++)
// 	{
// 		for (int j = 0; j < 10; j++)
// 		{
// 			if (j == 5)
// 			{
// 				break;
// 			}
// 			cout << "*" << " ";
// 		}
// 		cout << endl;
// 	}

// 	system("pause");

// 	return 0;
// }

// int main() {

// 	for (int i = 0; i < 10; i++)
// 	{
// 		cout << i << endl;
// 	}

// 	system("pause");

// 	return 0;
// }

// int main() {

// 	int i = 1;
// 	int j = 1;
// 	cout << (i == j) << endl;

// 	system("pause");

// 	return 0;
// }

// int main()
// {

// 	string str = "hello world";
// 	cout << str << endl;

// 	system("pause");

// 	return 0;
// }

// int main() {

// 	float f1 = 3.14f;
// 	double d1 = 3.14;

// 	cout << f1 << endl;
// 	cout << d1<< endl;

// 	cout << "float  sizeof = " << sizeof(f1) << endl;
// 	cout << "double sizeof = " << sizeof(d1) << endl;

// 	//科学计数法
// 	float f2 = 3e2; // 3 * 10 ^ 2
// 	cout << "f2 = " << f2 << endl;

// 	float f3 = 3e-2;  // 3 * 0.1 ^ 2
// 	cout << "f3 = " << f3 << endl;

// 	system("pause");

// 	return 0;
// }

// int main() {

// 	cout << "short 类型所占内存空间为： " << sizeof(short) << endl;

// 	cout << "int 类型所占内存空间为： " << sizeof(int) << endl;

// 	cout << "long 类型所占内存空间为： " << sizeof(long) << endl;

// 	cout << "long long 类型所占内存空间为： " << sizeof(long long) << endl;

// 	system("pause");

// 	return 0;
// }

// int main() {

// 	//变量的定义
// 	//语法：数据类型  变量名 = 初始值

// 	int a;
// 	a = 10;
// 	#define N 10
// 	cout << "a = " << a << endl;
// 	cout << "N = " << N << endl;

// 	system("pause");

// 	return 0;
// }

// #define max(a, b) (a > b ? a : b)
// int F(int a[], int s, int e)
// {
// 	if (s == e)
// 	{
// 		return a[s];
// 	}
// 	else if (s + 1 == e) //递归边界
// 	{
// 		return max(a[s], a[e]);
// 	}
// 	else
// 	{
// 	return max(a[s], F(a, s + 1, e)); //递归公式!!!
// 	}
// }
// int main()
// {
// 	int a[] = {5, 1, 4, 6, 2};
// 	int s = 0, e = 4;
// 	cout << F(a, s, e) << endl;
// 	return 0;
// }

// #define N 10

// void bubblesort(int myarray[], int n)
// {
// 	bool j = false;
// 	while (!j)
// 	{
// 		j = true;
// 		for (int i = 0; i < n - 1; i++)
// 		{
// 			if (myarray[i] > myarray[i + 1])
// 			{
// 				int temp = myarray[i];
// 				myarray[i] = myarray[i + 1];
// 				myarray[i + 1] = temp;
// 				j = false;
// 			}
// 		}
// 		n--;
// 	}
// }

// void binarySearch(int myarray[], int n, int data)
// {
// 	int begin = 0, end = n - 1;
// 	int middle = 0;
// 	while (begin < end)
// 	{
// 		middle = (begin + end) / 2;
// 		if (data < myarray[middle])
// 		{
// 			end = middle;
// 			// middle = (begin + middle) / 2;
// 		}
// 		else if (data > myarray[middle])
// 		{
// 			begin = middle;
// 		}
// 		else
// 		{
// 			cout << "i=" << middle << endl;
// 			return;
// 		}
// 	}
// 	cout << data << "不存在" << endl;
// }

// void print(int myarray[], int n)
// {
// 	for (int i = 0; i < n; i++)
// 	{
// 		cout << myarray[i] << " ";
// 	}
// 	cout << endl;
// }

// int main()
// {

// 	int myarray[N];
// 	srand((unsigned int)time(NULL));
// 	for (int i = 0; i < 10; i++)
// 	{
// 		myarray[i] = rand() % 100 + 1;
// 		// myarray[i] = i;
// 	}

// 	cout << "交换前" << endl;
// 	print(myarray, N);

// 	bubblesort(myarray, N);

// 	cout << "交换后" << endl;
// 	print(myarray, N);

// 	//二分查找
// 	cout << "Please input what you want to find:" << endl;
// 	int data;
// 	cin >> data;
// 	binarySearch(myarray, N, data);

// 	system("pause");
// 	return 0;
// }

// // 作者：嵌入式Linux
// // 链接：https://zhuanlan.zhihu.com/p/92549558
// // 来源：知乎
// // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// #include   <conio.h>
// #include   <stdio.h>
// #include  <stdlib.h>
// #include    <time.h>
// #include <Windows.h>

// /**********初始化参数************/
// int i,j,N,T,F,J,X,Y,dx,dy,  KEY_V,  Cache1,Cache2,NU,NI,RU,RI,  P_X,P_Y,POS_Y_MAX,  LEVEL=1,SCORE=0,  P[4],  POINT_V[12][22],  MARK[21],  FLAG[5]={0,0,0,1,0};
// int TGM[7][4]={{0x159D,0x89AB,0x159D,0x89AB},{0x126A,0x4856,0x159A,0x4526},{0x926A,0x456A,0x1592,0x0456},{0x4859,0x4859,0x4859,0x4859},{0x5926,0x0156,0x5926,0x0156},{0x4159,0x4596,0x1596,0x4156},{0x156A,0x4152,0x156A,0x4152}};
// int SRS[7][4]={{0x159D,0x89AB,0x26AE,0x4567},{0x0159,0x4856,0x159A,0x4526},{0x8159,0x456A,0x1592,0x0456},{0x4859,0x4859,0x4859,0x4859},{0x4815,0x459A,0x5926,0x0156},{0x4159,0x4596,0x1596,0x4156},{0x0459,0x8596,0x156A,0x4152}};

// /**********光标位置函数**********/
// void Pos(int x,int y)
// {
//         COORD pos;
//         HANDLE hOutput;
//         pos.X=2*x;
//         pos.Y=y;
//         hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
//         SetConsoleCursorPosition(hOutput,pos);
// }

// void HideCursor()
// {
//         CONSOLE_CURSOR_INFO cursor_info={1,0};
//         SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
// }

// /**********初始化界面************/
// void CreatUI()
// {
//         int i,j,BOUNDARY;
//         printf("┏━━━━━━━━━━┓\n");
//         for(j=1;j<=20;j++) {
//                 if     (j==3){printf("┃　　　　　　　　　　┃LEVEL：1\n");}
//                 else if(j==5){printf("┃　　　　　　　　　　┃SCORE：0\n");}
//                 else if(j==7){printf("┃　　　　　　　　　　┃NEXT   \n");}
//                 else         {printf("┃　　　　　　　　　　┃\n");}
//         }
//         printf("┗━━━━━━━━━━┛\n");
//         printf(" CopyRight@2016~2018 BY HAPPY\n");
//         for(j=1;j<=21;j++){
//                 for(i=0;i<=11;i++){
//                         BOUNDARY=i*(i-11)*(j-21);
//                         if(BOUNDARY==0){
//                                 POINT_V[i][j]=1;
//                         }else{
//                                 POINT_V[i][j]=0;
//                         }
//                 }
//         }
// }

// /**********按键获取**************/
// int Getkey(int N,int T)
// {
//         int start=clock();
//         if(KEY_V==115){return 115;}
//          do{
//                  if(kbhit()){
//                          KEY_V=(int)(getch());
//                          if(KEY_V<97){KEY_V+=32;}
//                          return KEY_V;
//                  }
//                 for(i=0;i<=N;i++);
//         }while((clock()-start)<T);
//         dy=1;
//         return -1;
// }

// /***********块体转置*************/
// int Rote(int S, int I)
// {
//         return (F==0)?TGM[S][(I+4)%4]:SRS[S][(I+4)%4];
// }

// /***********擦除显示*************/
// int Display(int x, int y, int CAC, int Mode)
// {
//         for(j=0;j<=3;j++){
//                 P[j]=CAC&0xF, CAC>>=4;
//                 if     (Mode==1){Pos((P[j]>>2)+x,(P[j]&0x3)+y);printf("■");}
//                 else if(Mode==0){Pos((P[j]>>2)+x,(P[j]&0x3)+y);printf("　");}
//         }
//         return 0;
// }

// /***********固化块体*************/
// int DoBlocks()
// {
//         //~~~游戏结束
//         if(Y<2){
//                 Pos(1,22);printf("GAME OVER！");
//                 exit(0);
//         }
//         //~~~固化块体
//         POS_Y_MAX=0, FLAG[3]=1;
//         for(j=0;j<=3;j++){
//                 P_X=(P[j]>>2)+X,P_Y=(P[j]&0x3)+Y;
//                 if(POS_Y_MAX<P_Y){POS_Y_MAX=P_Y;}
//                 POINT_V[P_X][P_Y]=1;
//         }
//         //~~~关卡得分
//         for(j=Y;j<=POS_Y_MAX;j++){
//                 FLAG[2]=1;
//                 for(i=1;i<=10;i++){
//                         if(POINT_V[i][j]==0){FLAG[2]=0;}
//                 }
//                 if(FLAG[2]){
//                         SCORE+=10,MARK[j]=1;
//                         if(SCORE==400){
//                                 SCORE=0,LEVEL+=1,T-=100;
//                                 FLAG[4]=1;
//                         }
//                 }
//         }
//         //~~~极品消行
//         for(j=20;j>=5;j--){
//                 if(FLAG[4]){
//                         for(i=1;i<=10;i++){
//                                 POINT_V[i][j]=0;
//                                 Pos(i,j);printf("　");
//                         }
//                 }
//                 else if(MARK[j])
//                 {
//                         MARK[j]=0,J=j-1;
//                         for(N=1;N<=3;N++){
//                                 if(MARK[J]){J--;}
//                         }
//                         MARK[J]=1;
//                         for(i=1;i<=10;i++){
//                                 Pos(i,j);
//                                 if(POINT_V[i][j]=POINT_V[i][J]){
//                                         printf("■");
//                                 }else{
//                                         printf("　");
//                                 }
//                         }
//                 }
//         }
//         FLAG[4]=0;
//         return 0;
// }

// /***********碰撞检测*************/
// int CheckCollision()
// {
//         for(j=0;j<=3;j++){
//                 P_X=(P[j]>>2)+X+dx,P_Y=(P[j]&0x3)+Y+dy;
//                 if(POINT_V[P_X][P_Y]){
//                         if(dx!=0){return 1;}
//                         if(dy){
//                                 DoBlocks();
//                                 Pos(12,3);printf("LEVEL：%-3d",LEVEL);
//                                 Pos(12,5);printf("SCORE：%-3d",SCORE);
//                                 return 2;
//                         }
//                         if(KEY_V==119){FLAG[0]=1;}
//                 }
//         }
//         return 0;
// }

// /***********循环核心*************/
// int GameCycle(int N, int T, int F)
// {
//         srand((unsigned)time(NULL));RU=rand()%7,RI=(rand()%4);
//         while(1){
//                 if(FLAG[3]){
//                         Display(12,8,Rote(RU,RI),0);
//                         X=4,Y=1, NU=RU,NI=RI, RU=rand()%7,RI=(rand()%4), FLAG[3]=0,KEY_V=0;
//                         Display(12,8,Rote(RU,RI),1);
//                         Display(X, Y,Rote(NU,NI),1);
//                 }
//                 dx=0,dy=0;
//                 KEY_V=Getkey(N,T);
//                   if(KEY_V==119){
//                           NI++;
//                          Display(X,Y,Rote(NU,NI),2);
//                 }//旋W
//                 else if(KEY_V==115){dy= 1;}//下S
//                 else if(KEY_V==97 ){dx=-1;}//左A
//                 else if(KEY_V==100){dx= 1;}//右D
//                 else if(KEY_V==112){getch(); }//暂停P
//                 else if(KEY_V==113){return 0;}//退出Q
//                 if(dx!=0 || dy!=0 || KEY_V==119){
//                         if(!CheckCollision()){
//                                 if(FLAG[0]){
//                                         NI--,FLAG[0]=0;
//                                         Display(X,Y,Rote(NU,NI),0);
//                                 }
//                                 else if(KEY_V==119){
//                                         Display(X,Y,Rote(NU,NI-1),0);
//                                 }else{
//                                         Display(X,Y,Rote(NU,NI),0);
//                                 }
//                                 Display(X+dx,Y+dy,Rote(NU,NI),1);
//                                 X+=dx,Y+=dy;
//                         }
//                 }
//         }
//         return 0;
// }

// /**********Main主函数***********/
// int main()
// {
//         system("color F0&mode con cols=35 lines=25");
//         HideCursor();
//         CreatUI();
//         GameCycle(10,800,1);
//         return 0;
// }

// // 作者：梦凡
// // 链接：https://zhuanlan.zhihu.com/p/84617748
// // 来源：知乎
// // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// #include<stdio.h>
// #include<time.h>
// #include<windows.h>
// #include<stdlib.h>

// #define U 1
// #define D 2
// #define L 3
// #define R 4 //蛇的状态，U：上 ；D：下；L:左 R：右

// typedef struct SNAKE //蛇身的一个节点
// {
//  int x;
//  int y;
//  struct SNAKE *next;
// }snake;

// //全局变量//
// int score=0,add=10;//总得分与每次吃食物得分。
// int status,sleeptime=200;//每次运行的时间间隔
// snake *head, *food;//蛇头指针，食物指针
// snake *q;//遍历蛇的时候用到的指针
// int endgamestatus=0; //游戏结束的情况，1：撞到墙；2：咬到自己；3：主动退出游戏。

// //声明全部函数//
// void Pos();
// void creatMap();
// void initsnake();
// int biteself();
// void createfood();
// void cantcrosswall();
// void snakemove();
// void pause();
// void gamecircle();
// void welcometogame();
// void endgame();
// void gamestart();

// void Pos(int x,int y)//设置光标位置
// {
//  COORD pos;
//  HANDLE hOutput;
//  pos.X=x;
//  pos.Y=y;
//  hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
//  SetConsoleCursorPosition(hOutput,pos);
// }

// void creatMap()//创建地图
// {
//  int i;
//  for(i=0;i<58;i+=2)//打印上下边框
//  {
//  Pos(i,0);
//  printf("■");
//  Pos(i,26);
//  printf("■");
//  }
//  for(i=1;i<26;i++)//打印左右边框
//  {
//  Pos(0,i);
//  printf("■");
//  Pos(56,i);
//  printf("■");
//  }
// }

// void initsnake()//初始化蛇身
// {
//  snake *tail;
//  int i;
//  tail=(snake*)malloc(sizeof(snake));//从蛇尾开始，头插法，以x,y设定开始的位置//
//  tail->x=24;
//  tail->y=5;
//  tail->next=NULL;
//  for(i=1;i<=4;i++)
//  {
//  head=(snake*)malloc(sizeof(snake));
//  head->next=tail;
//  head->x=24+2*i;
//  head->y=5;
//  tail=head;
//  }
//  while(tail!=NULL)//从头到为，输出蛇身
//  {
//  Pos(tail->x,tail->y);
//  printf("■");
//  tail=tail->next;
//  }
// }

// int biteself()//判断是否咬到了自己
// {
//  snake *self;
//  self=head->next;
//  while(self!=NULL)
//  {
//  if(self->x==head->x && self->y==head->y)
//  {
//  return 1;
//  }
//  self=self->next;
//  }
//  return 0;
// }

// void createfood()//随机出现食物
// {
//  snake *food_1;
//  srand((unsigned)time(NULL));
//  food_1=(snake*)malloc(sizeof(snake));
//  while((food_1->x%2)!=0) //保证其为偶数，使得食物能与蛇头对其
//  {
//  food_1->x=rand()%52+2;
//  }
//  food_1->y=rand()%24+1;
//  q=head;
//  while(q->next==NULL)
//  {
//  if(q->x==food_1->x && q->y==food_1->y) //判断蛇身是否与食物重合
//  {
//  free(food_1);
//  createfood();
//  }
//  q=q->next;
//  }
//  Pos(food_1->x,food_1->y);
//  food=food_1;
//  printf("■");
// }

// void cantcrosswall()//不能穿墙
// {
//  if(head->x==0 || head->x==56 ||head->y==0 || head->y==26)
//  {
//  endgamestatus=1;
//  endgame();
//  }
// }

// void snakemove()//蛇前进,上U,下D,左L,右R
// {
//  snake * nexthead;
//  cantcrosswall();

//  nexthead=(snake*)malloc(sizeof(snake));
//  if(status==U)
//  {
//  nexthead->x=head->x;
//  nexthead->y=head->y-1;
//  if(nexthead->x==food->x && nexthead->y==food->y)//如果下一个有食物//
//  {
//  nexthead->next=head;
//  head=nexthead;
//  q=head;
//  while(q!=NULL)
//  {
//  Pos(q->x,q->y);
//  printf("■");
//  q=q->next;
//  }
//  score=score+add;
//  createfood();
//  }
//  else //如果没有食物//
//  {
//  nexthead->next=head;
//  head=nexthead;
//  q=head;
//  while(q->next->next!=NULL)
//  {
//  Pos(q->x,q->y);
//  printf("■");
//  q=q->next;
//  }
//  Pos(q->next->x,q->next->y);
//  printf(" ");
//  free(q->next);
//  q->next=NULL;
//  }
//  }
//  if(status==D)
//  {
//  nexthead->x=head->x;
//  nexthead->y=head->y+1;
//  if(nexthead->x==food->x && nexthead->y==food->y) //有食物
//  {
//  nexthead->next=head;
//  head=nexthead;
//  q=head;
//  while(q!=NULL)
//  {
//  Pos(q->x,q->y);
//  printf("■");
//  q=q->next;
//  }
//  score=score+add;
//  createfood();
//  }
//  else //没有食物
//  {
//  nexthead->next=head;
//  head=nexthead;
//  q=head;
//  while(q->next->next!=NULL)
//  {
//  Pos(q->x,q->y);
//  printf("■");
//  q=q->next;
//  }
//  Pos(q->next->x,q->next->y);
//  printf(" ");
//  free(q->next);
//  q->next=NULL;
//  }
//  }
//  if(status==L)
//  {
//  nexthead->x=head->x-2;
//  nexthead->y=head->y;
//  if(nexthead->x==food->x && nexthead->y==food->y)//有食物
//  {
//  nexthead->next=head;
//  head=nexthead;
//  q=head;
//  while(q!=NULL)
//  {
//  Pos(q->x,q->y);
//  printf("■");
//  q=q->next;
//  }
//  score=score+add;
//  createfood();
//  }
//  else //没有食物
//  {
//  nexthead->next=head;
//  head=nexthead;
//  q=head;
//  while(q->next->next!=NULL)
//  {
//  Pos(q->x,q->y);
//  printf("■");
//  q=q->next;
//  }
//  Pos(q->next->x,q->next->y);
//  printf(" ");
//  free(q->next);
//  q->next=NULL;
//  }
//  }
//  if(status==R)
//  {
//  nexthead->x=head->x+2;
//  nexthead->y=head->y;
//  if(nexthead->x==food->x && nexthead->y==food->y)//有食物
//  {
//  nexthead->next=head;
//  head=nexthead;
//  q=head;
//  while(q!=NULL)
//  {
//  Pos(q->x,q->y);
//  printf("■");
//  q=q->next;
//  }
//  score=score+add;
//  createfood();
//  }
//  else //没有食物
//  {
//  nexthead->next=head;
//  head=nexthead;
//  q=head;
//  while(q->next->next!=NULL)
//  {
//  Pos(q->x,q->y);
//  printf("■");
//  q=q->next;
//  }
//  Pos(q->next->x,q->next->y);
//  printf(" ");
//  free(q->next);
//  q->next=NULL;
//  }
//  }
//  if(biteself()==1) //判断是否会咬到自己
//  {
//  endgamestatus=2;
//  endgame();
//  }
// }

// void pause()//暂停
// {
//  while(1)
//  {
//  Sleep(300);
//  if(GetAsyncKeyState(VK_SPACE))
//  {
//  break;
//  }

//  }
// }

// void gamecircle()//控制游戏
// {

//  Pos(64,15);
//  printf("不能穿墙，不能咬到自己\n");
//  Pos(64,16);
//  printf("用↑.↓.←.→分别控制蛇的移动.");
//  Pos(64,17);
//  printf("F1 为加速，F2 为减速\n");
//  Pos(64,18);
//  printf("ESC ：退出游戏.space：暂停游戏.");
//  Pos(64,20);
//  printf("c语言研究中心 www.dotcpp.com");
//  status=R;
//  while(1)
//  {
//  Pos(64,10);
//  printf("得分：%d ",score);
//  Pos(64,11);
//  printf("每个食物得分：%d分",add);
//  if(GetAsyncKeyState(VK_UP) && status!=D)
//  {
//  status=U;
//  }
//  else if(GetAsyncKeyState(VK_DOWN) && status!=U)
//  {
//  status=D;
//  }
//  else if(GetAsyncKeyState(VK_LEFT)&& status!=R)
//  {
//  status=L;
//  }
//  else if(GetAsyncKeyState(VK_RIGHT)&& status!=L)
//  {
//  status=R;
//  }
//  else if(GetAsyncKeyState(VK_SPACE))
//  {
//  pause();
//  }
//  else if(GetAsyncKeyState(VK_ESCAPE))
//  {
//  endgamestatus=3;
//  break;
//  }
//  else if(GetAsyncKeyState(VK_F1))
//  {
//  if(sleeptime>=50)
//  {
//  sleeptime=sleeptime-30;
//  add=add+2;
//  if(sleeptime==320)
//  {
//  add=2;//防止减到1之后再加回来有错
//  }
//  }
//  }
//  else if(GetAsyncKeyState(VK_F2))
//  {
//  if(sleeptime<350)
//  {
//  sleeptime=sleeptime+30;
//  add=add-2;
//  if(sleeptime==350)
//  {
//  add=1; //保证最低分为1
//  }
//  }
//  }
//  Sleep(sleeptime);
//  snakemove();
//  }
// }

// void welcometogame()//开始界面
// {
//  Pos(40,12);

//  system("title c语言研究中心 www.dotcpp.com");
//  printf("欢迎来到贪食蛇游戏！");
//  Pos(40,25);
//  system("pause");
//  system("cls");
//  Pos(25,12);
//  printf("用↑.↓.←.→分别控制蛇的移动， F1 为加速，2 为减速\n");
//  Pos(25,13);
//  printf("加速将能得到更高的分数。\n");
//  system("pause");
//  system("cls");
// }

// void endgame()//结束游戏
// {

//  system("cls");
//  Pos(24,12);
//  if(endgamestatus==1)
//  {
//  printf("对不起，您撞到墙了。游戏结束.");
//  }
//  else if(endgamestatus==2)
//  {
//  printf("对不起，您咬到自己了。游戏结束.");
//  }
//  else if(endgamestatus==3)
//  {
//  printf("您的已经结束了游戏。");
//  }
//  Pos(24,13);
//  printf("您的得分是%d\n",score);
//  exit(0);
// }

// void gamestart()//游戏初始化
// {
//  system("mode con cols=100 lines=30");
//  welcometogame();
//  creatMap();
//  initsnake();
//  createfood();
// }

// int main()
// {
//  gamestart();
//  gamecircle();
//  endgame();
//  return 0;
// }

// // 作者：嵌入式Linux
// // 链接：https://zhuanlan.zhihu.com/p/96623752
// // 来源：知乎
// // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <Windows.h>
// #include <time.h>
// #include <conio.h> /*键盘输入获取*/

// bool gameOver;
// bool stop = false;
// bool hit = false;
// /*游戏的边框大小*/
// const int width = 50;
// const int height = 20;
// /*蛇的坐标，食物的坐标还有分数*/
// int x,y,fruitX,fruitY,score;
// /*蛇每个点的坐标*/
// int tailX[200],tailY[200];
// /*蛇的默认长度*/
// int ntail=3;

// typedef enum
// {
// 	STOP = 0,
// 	LEFT,
// 	RIGHT,
// 	UP,
// 	DOWN
// }Direction;

// Direction Dir;
// /*开始菜单*/
// void menu()
// {
//     int a;
//     printf("------------------------------------------------------------------\n");
//     printf("|                              贪吃蛇游戏                        |\n");
//     printf("|                              1) 新游戏                         |\n");
//     printf("|                              2) 开始边界                       |\n");
//     printf("|                              3) 退出游戏                       |\n");
//     printf("------------------------------------------------------------------\n");
//     printf("---->请输入你的选择:");
//     scanf("%d", &a);
// }

// /*初始化状态*/
// void setup()
// {
//     gameOver = false;
//     /*根据当前时间设置“随机数种子”*/
//     srand(time(NULL));
//     Dir = STOP;

//     /*贪吃蛇的位置,固定在中间*/
//     x= width/2;
//     y= height/2;
//     /*食物的位置，位置是随机的*/
//     fruitX = rand()%width;
//     fruitY = rand()%height;
//     score = 0;
// }
// /*绘制界面*/
// void draw()
// {
// 	if(stop == true)
// 	{
// 		return;
// 	}
//     system("cls");/*清除屏幕*/
//     printf("分数:%d",score);
//     printf("\n");

// 	/*第一行*/
//     int i;
//     for(i= 0 ;i<width+1;i++)
// 	{
//         printf("-");
//     }
//     printf("\n");

//     /*画中间的画面*/
//     int p;
//     for(p= 0 ;p<height;p++)/*高度*/
// 	{
//         int q;
//         for(q= 0 ;q<width;q++)/*宽度*/
// 		{
// 			/*第一行最后已给字符*/
//             if(q==0 || q==width-1)
// 			{
//                 printf("|");
//             }

// 			if(p == fruitY && q == fruitX)/*食物的随机坐标*/
// 			{
//                 printf("O");
//             }
// 			else
// 			{
//                     int k=0;
//                     bool print = false;
//                     /*贪吃蛇的长度 默认长度是 3*/
// 					for(k=0;k<ntail;k++)
// 					{
//                         if(tailX[k]==q && tailY[k]==p)
// 						{
//                             printf("*");
//                             print = true;
//                         }
//                     }
//                     /*如果这个位置打印了 * 就不要打印空格了*/
//                     if(!print)
// 					{
// 						printf(" ");
// 					}
//             }
//         }
//         printf("\n");
//     }

// 	/*最后一行*/
//     int j;
//     for(j= 0 ;j<width+1;j++)
// 	{
//         printf("-");
//     }

// }
// /*按键输入控制*/
// void input()
// {
//     if(_kbhit())
// 	{
// 		/*获取键盘的输入字符*/
//         switch(_getch())
// 		{
//             case '4':
//             case 75:/*左键*/
//                 Dir = LEFT;
//                 hit= true;
//                 break;
//             case '8':
//             case 72:/*上键*/
//                 Dir = UP;
//                 hit= true;
//                 break;
//             case '6':
//             case 77:/*右键*/
//                 Dir = RIGHT;
//                 hit= true;
//                 break;
//             case '2':
//             case 80:/*向下键盘键 */
//                 Dir = DOWN;
//                 hit= true;
//                 break;
//             case 'x':
//             case 27:/*ESE*/
//                 gameOver = true;
//                 break;
//             case 32:/*空格 暂停键*/
// 				stop = !stop;
// 				break;
//         }
//     }
// 	else if(!hit && stop == false)/*如果没有改变方向*/
// 	{
//         x++;
//     }
// }
// /*判断贪吃蛇的长度*/
// void logic()
// {
// 	if(stop == true)
// 	{
// 		return;
// 	}

// 	/*把上一个位置记下*/
//     int lastX = tailX[0];
//     int lastY = tailY[0];
//     int last2X, last2Y;
//     /*重新获取当前的位置*/
// 	tailX[0]=x;
//     tailY[0]=y;
//     int i=0;
//     /*遍历整条蛇的长度 把 0 的位置空出来，其余蛇的位置往后面的空间移动*/
//     for(i=1; i<ntail;i++)
// 	{
//         last2X = tailX[i];
//         last2Y = tailY[i];
//         tailX[i]=lastX;
//         tailY[i]=lastY;
//         lastX = last2X;
//         lastY = last2Y;
//     }
//     /*根据方向来改变x y 的值*/
//     switch(Dir)
// 	{
//         case UP:
//             y--;
//             break;
//         case DOWN:
//             y++;
//             break;
//         case LEFT:
//             x--;
//             break;
//         case RIGHT:
//             x++;
//             break;
//     }
//     if(x<0 || width<x || y<0 || height<y)
// 	{
//         gameOver = true;
//         /*清除屏幕*/
//         system("cls");
//         printf("------------------------------------------------------------------\n");
// 	    printf("|                                                                |\n");
// 	    printf("|                                                                |\n");
// 	    printf("|                             游戏结束                           |\n");
// 	    printf("|                                                                |\n");
// 	    printf("|                                                                |\n");
// 	    printf("------------------------------------------------------------------\n");
//     }
//     if(x==fruitX && y==fruitY)
// 	{
// 		/*吃了一个食物，蛇的长度增加1*/
//         ntail++;
//         score+=10;
//         /*更新下一个食物的位置*/
//         fruitX = rand()%width;
//         fruitY = rand()%height;
//     }
// }
// int main()
// {
// #if 0
// 	while(1)
// 	{
// 		printf("%d\n",_getch());
// 	}
// #endif
//     menu();
//     setup();
//     draw();
//     /*循环画贪吃蛇的界面*/
// 	while(!gameOver)
// 	{
//         draw();
//         input();
//         logic();
//         Sleep(70);
//     }

//     return 0;
// }

// // 作者：彭瑶
// // 链接：https://zhuanlan.zhihu.com/p/37966089
// // 来源：知乎
// // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// #include<stdio.h>
// #include<Windows.h>
// #include<time.h>
// #include<conio.h>
// #define SIZE 19 //定义地图大小

// void init(int*, int*, int[SIZE][SIZE]);
// int getCommand(int);
// int move(int, int*, int[SIZE][SIZE]);
// void draw(int[SIZE][SIZE]);

// int main()
// {
// 	int map[SIZE][SIZE] = { 0 };
// 	int command, result, length = 0; //length表示蛇的长度
// 	init(&command, &length, map); //初始化游戏
// 	while (1)
// 	{
// 		command = getCommand(command); //获取玩家输入的命令
// 		result = move(command, &length, map); //根据命令移动蛇
// 		if (result == 1) //分析移动的结果
// 		{
// 			break;
// 		}
// 		else
// 		{
// 			draw(map); //将蛇画到控制台
// 		}
// 		Sleep(1000);
// 	}
// }

// void init(int *command, int *length, int map[SIZE][SIZE])
// {
// 	//初始化初始命令
// 	*command = 2; //初始命令向下
// 	//初始化蛇的长度
// 	*length = 3;
// 	//初始化蛇的位置
// 	map[2][1] = 1;
// 	map[1][1] = 2;
// 	map[0][1] = 3;
// 	//初始化食物的位置
// 	map[3][3] = -1;
// }

// int getCommand(int command)
// {
// 	int temp = -1;
// 	if (_kbhit()) //如果有键盘输入
// 	{
// 		switch (_getch())
// 		{
// 		case 'A': case 'a': temp = 3; break; //表示向左
// 		case 'S': case 's': temp = 2; break; //表示向下
// 		case 'D': case 'd': temp = 1; break; //表示向右
// 		case 'W': case 'w': temp = 0; break; //表示向上
// 		}
// 		if (temp != -1 && abs(command - temp) != 2) //蛇不能反向
// 		{
// 			command = temp;
// 		}
// 	}
// 	return command;
// }

// int move(int command, int *length, int map[SIZE][SIZE])
// {
// 	int i, j, head_i, head_j;
// 	for (i = 0; i < SIZE; i++)
// 	{
// 		for (j = 0; j < SIZE; j++)
// 		{
// 			if (map[i][j] == *length) //如果是蛇的最后一节身体
// 			{
// 				map[i][j] = 0;
// 			}
// 			else if (map[i][j] > 1) //如果是蛇中间节的身体
// 			{
// 				map[i][j] += 1;
// 			}
// 			else if (map[i][j] == 1) //如果是蛇头
// 			{
// 				map[i][j] += 1;
// 				//确定蛇头新的位置head_i和head_j
// 				switch (command)
// 				{
// 				case 0: head_i = i - 1, head_j = j; break;
// 				case 1: head_i = i, head_j = j + 1; break;
// 				case 2: head_i = i + 1, head_j = j; break;
// 				case 3: head_i = i, head_j = j - 1; break;
// 				}
// 			}
// 		}
// 	}
// 	if (map[head_i][head_j] == -1) //如果吃到了食物
// 	{
// 		map[head_i][head_j] = 1;
// 		*length = *length + 1; //蛇的长度加一
// 		//重新生成食物
// 		while (1)
// 		{
// 			i = rand() % SIZE, j = rand() % SIZE;
// 			if (map[i][j] == 0)
// 			{
// 				map[i][j] = -1;
// 				break;
// 			}
// 		}
// 	}
// 	//如果撞到了自己或者撞到了墙
// 	else if (map[head_i][head_j] > 0 || head_i < 0 || head_i == SIZE || head_j < 0 ||head_j == SIZE)
// 	{
// 		return 1;
// 	}
// 	else
// 	{
// 		map[head_i][head_j] = 1;
// 	}
// 	return 0;
// }

// void draw(int map[SIZE][SIZE])
// {
// 	int i, j;
// 	system("cls"); //清除屏幕
// 	for (i = 0; i <= SIZE; i++) //输出上边框
// 	{
// 		if (i == 0)
// 		{
// 			printf("┏");
// 		}
// 		else if (i == SIZE)
// 		{
// 			printf(" ━━┓");
// 		}
// 		else
// 		{
// 			printf(" ━");
// 		}
// 	}
// 	printf("\n");
// 	for (i = 0; i < SIZE; i++)
// 	{
// 		for (j = 0; j < SIZE; j++)
// 		{
// 			if (j == 0) //输出左边框
// 			{
// 				printf("┃ ");
// 			}
// 			if (map[i][j] == 1) //输出蛇头
// 			{
// 				printf("○");
// 			}
// 			else if (map[i][j] > 1) //输出蛇身
// 			{
// 				printf("●");
// 			}
// 			else if (map[i][j] == -1) //输出食物
// 			{
// 				printf("★");
// 			}
// 			else
// 			{
// 				printf("  ");
// 			}
// 			if (j == SIZE - 1) //输出右边框
// 			{
// 				printf("┃ ");
// 			}
// 		}
// 		printf("\n");
// 	}
// 	for (i = 0; i <= SIZE; i++) //输出下边框
// 	{
// 		if (i == 0)
// 		{
// 			printf("┗");
// 		}
// 		else if (i == SIZE)
// 		{
// 			printf(" ━━┛");
// 		}
// 		else
// 		{
// 			printf(" ━");
// 		}
// 	}
// 	printf("\n");
// }

// class myPrint
// {
// public:
// 	void operator()(int val)
// 	{
// 		cout << val << " ";
// 	}
// };

// void test01()
// {

// 	vector<int> v;
// 	v.resize(10);
// 	//填充
// 	fill(v.begin(), v.end(), 100);

// 	for_each(v.begin(), v.end(), myPrint());
// 	cout << endl;
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// class myPrint
// {
// public:
// 	void operator()(int val)
// 	{
// 		cout << val << " ";
// 	}
// };

// void my_print(int val)
// {
// 	cout << val << " ";
// }

// void test01()
// {
// 	vector<int> v1;
// 	vector<int> v2;
// 	for (int i = 0; i < 10; i++)
// 	{
// 		v1.push_back(i);
// 		v2.push_back(i + 100);
// 	}

// 	cout << "交换前： " << endl;
// 	for_each(v1.begin(), v1.end(), my_print);
// 	cout << endl;
// 	for_each(v2.begin(), v2.end(), myPrint());
// 	cout << endl;

// 	cout << "交换后： " << endl;
// 	swap(v1, v2);
// 	for_each(v1.begin(), v1.end(), myPrint());
// 	cout << endl;
// 	for_each(v2.begin(), v2.end(), myPrint());
// 	cout << endl;
// }

// int main()
// {

// 	system("cls");

// 	test01();

// 	system("pause");

// 	return 0;
// }

// #include <vector>
// #include <algorithm>
// void test01()
// {
// 	vector<bool> v;
// 	v.push_back(true);
// 	v.push_back(false);
// 	v.push_back(true);
// 	v.push_back(false);

// 	for (vector<bool>::iterator it = v.begin();it!= v.end();it++)
// 	{
// 		cout << *it << " ";
// 	}
// 	cout << endl;

// 	//逻辑非  将v容器搬运到v2中，并执行逻辑非运算
// 	vector<bool> v2;
// 	v2.resize(v.size());
// 	transform(v.begin(), v.end(),  v2.begin(), logical_not<bool>());
// 	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
// 	{
// 		cout << *it << " ";
// 	}
// 	cout << endl;
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// #include <vector>
// #include <algorithm>

// //1.一元谓词
// struct GreaterFive{
// 	bool operator()(int val) {
// 		return val > 5;
// 	}
// };

// void test01() {

// 	vector<int> v;
// 	for (int i = 0; i < 10; i++)
// 	{
// 		v.push_back(i);
// 	}

// 	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
// 	if (it == v.end()) {
// 		cout << "没找到!" << endl;
// 	}
// 	else {
// 		cout << "找到:" << *it << endl;
// 	}

// }

// int main() {

// 	// system("cls");

// 	test01();

// 	system("pause");

// 	return 0;
// }

// #define CEHUA  0
// #define MEISHU 1
// #define YANFA  2

// class Worker
// {
// public:
// 	string m_Name;
// 	int m_Salary;
// };

// void createWorker(vector<Worker>&v)
// {
// 	string nameSeed = "ABCDEFGHIJ";
// 	for (int i = 0; i < 10; i++)
// 	{
// 		Worker worker;
// 		worker.m_Name = "员工";
// 		worker.m_Name += nameSeed[i];

// 		worker.m_Salary = rand() % 10000 + 10000; // 10000 ~ 19999
// 		//将员工放入到容器中
// 		v.push_back(worker);
// 	}
// }

// //员工分组
// void setGroup(vector<Worker>&v,multimap<int,Worker>&m)
// {
// 	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
// 	{
// 		//产生随机部门编号
// 		int deptId = rand() % 3; // 0 1 2

// 		//将员工插入到分组中
// 		//key部门编号，value具体员工
// 		m.insert(make_pair(deptId, *it));
// 	}
// }

// void showWorkerByGourp(multimap<int,Worker>&m)
// {
// 	// 0  A  B  C   1  D  E   2  F G ...
// 	cout << "策划部门：" << endl;

// 	multimap<int,Worker>::iterator pos = m.find(CEHUA);
// 	int count = m.count(CEHUA); // 统计具体人数
// 	int index = 0;
// 	for (; pos != m.end() && index < count; pos++ , index++)
// 	{
// 		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary << endl;
// 	}

// 	cout << "----------------------" << endl;
// 	cout << "美术部门： " << endl;
// 	pos = m.find(MEISHU);
// 	count = m.count(MEISHU); // 统计具体人数
// 	index = 0;
// 	for (; pos != m.end() && index < count; pos++, index++)
// 	{
// 		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary << endl;
// 	}

// 	cout << "----------------------" << endl;
// 	cout << "研发部门： " << endl;
// 	pos = m.find(YANFA);
// 	count = m.count(YANFA); // 统计具体人数
// 	index = 0;
// 	for (; pos != m.end() && index < count; pos++, index++)
// 	{
// 		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary << endl;
// 	}

// }

// int main() {

// 	srand((unsigned int)time(NULL));

// 	//1、创建员工
// 	vector<Worker>vWorker;
// 	createWorker(vWorker);

// 	//2、员工分组
// 	multimap<int, Worker>mWorker;
// 	setGroup(vWorker, mWorker);

// 	//3、分组显示员工
// 	showWorkerByGourp(mWorker);

// 	////测试
// 	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
// 	//{
// 	//	cout << "姓名： " << it->m_Name << " 工资： " << it->m_Salary << endl;
// 	//}

// 	system("pause");

// 	return 0;
// }

// int main()
// {

// 	int a, b;

// 	printf("hello vscode\n");
// 	printf("hello vscode\n");
// 	printf("hello vscode\n");
// 	printf("hello vscode\n");

// 	// printf("\n\n");
// 	// scanf("%d%d", &a, &b);
// 	// printf("a+b=%d\n", a + b);

// 	printf("你好 中国\n");
// 	printf("你好 中国\n");
// 	printf("你好 中国\n");
// 	printf("你好 中国\n");
// 	printf("你好 中国\n");

// 	system("pause");
// 	return 0;
// }

// void printMap(map<int, int> &m)
// {
// 	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
// 	{
// 		cout << "key = " << it->first << " value = " << it->second << endl;
// 	}
// 	cout << endl;
// }

// void test01()
// {
// 	map<int, int> m; //默认构造
// 	m.insert(pair<int, int>(1, 10));
// 	m.insert(pair<int, int>(3, 20));
// 	m.insert(pair<int, int>(2, 30));
// 	m.insert(pair<int, int>(7, 40));

// 	printMap(m);

// 	map<int, int> m2(m); //拷贝构造
// 	printMap(m2);

// 	map<int, int> m3;
// 	m3 = m2; //赋值
// 	printMap(m3);
// }

// int main()
// {

// 	system("cls");

// 	test01();

// 	system("pause");

// 	return 0;
// }

// #include <set>

// class MyCompare
// {
// public:
// 	bool operator()(int v1, int v2) {
// 		return v1 > v2;
// 	}
// };

// void test01()
// {
// 	set<int> s1;
// 	s1.insert(10);
// 	s1.insert(40);
// 	s1.insert(20);
// 	s1.insert(30);
// 	s1.insert(50);

// 	//默认从小到大
// 	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
// 		cout << *it << " ";
// 	}
// 	cout << endl;

// 	//指定排序规则
// 	set<int,MyCompare> s2;
// 	s2.insert(10);
// 	s2.insert(40);
// 	s2.insert(20);
// 	s2.insert(30);
// 	s2.insert(50);

// 	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
// 		cout << *it << " ";
// 	}
// 	cout << endl;
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// #include <string>

// //对组创建
// void test01()
// {
// 	pair<string, int> p("Blue Tom", 20);
// 	cout << "姓名： " <<  p.first << " 年龄： " << p.second << endl;

// 	pair<string, int> p2 = make_pair("Jerry", 10);
// 	cout << "姓名： " << p2.first << " 年龄： " << p2.second << endl;
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// //set和multiset区别
// void test01()
// {
// 	set<int> s;
// 	pair<set<int>::iterator, bool>  ret = s.insert(10);
// 	if (ret.second) {
// 		cout << "第一次插入成功!" << endl;
// 	}
// 	else {
// 		cout << "第一次插入失败!" << endl;
// 	}

// 	ret = s.insert(10);
// 	if (ret.second) {
// 		cout << "第二次插入成功!" << endl;
// 	}
// 	else {
// 		cout << "第二次插入失败!" << endl;
// 	}

// 	//multiset
// 	multiset<int> ms;
// 	ms.insert(10);
// 	ms.insert(10);

// 	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
// 		cout << *it << " ";
// 	}
// 	cout << endl;
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// class Person {
// public:
// 	Person(string name, int age , int height) {
// 		m_Name = name;
// 		m_Age = age;
// 		m_Height = height;
// 	}

// public:
// 	string m_Name;  //姓名
// 	int m_Age;      //年龄
// 	int m_Height;   //身高
// };

// bool ComparePerson(Person& p1, Person& p2) {

// 	if (p1.m_Age == p2.m_Age) {
// 		return p1.m_Height  > p2.m_Height;
// 	}
// 	else
// 	{
// 		return  p1.m_Age < p2.m_Age;
// 	}

// }

// bool ComparePerson(Person& p1, Person& p2) {

// 	if (p1.m_Age == p2.m_Age) {
// 		return p1.m_Height  > p2.m_Height;
// 	}
// 	else if(p1.m_Age == p2.m_Age)
// 	{
// 		return p1.m_Name < p2.m_Name;
// 	}
// 	else
// 	{
// 		return  p1.m_Age > p2.m_Age;
// 	}

// }

// void myprint(list<Person> &L)
// {
// 	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++) {
// 		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age
//               << " 身高： " << it->m_Height << endl;
// 	}
// }

// void test01() {

// 	list<Person> L;

// 	Person p1("刘备", 35 , 175);
// 	Person p2("曹操", 45 , 180);
// 	Person p3("孙权", 40 , 170);
// 	Person p4("赵云", 25 , 190);
// 	Person p5("张飞", 35 , 160);
// 	Person p6("关羽", 35 , 200);

// 	L.push_back(p1);
// 	L.push_back(p2);
// 	L.push_back(p3);
// 	L.push_back(p4);
// 	L.push_back(p5);
// 	L.push_back(p6);

// 	// for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++) {
// 	// 	cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age
//     //           << " 身高： " << it->m_Height << endl;
// 	// }

// 	myprint(L);

// 	cout << "---------------------------------" << endl;
// 	L.sort(ComparePerson); //排序

// 	// for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++) {
// 	// 	cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age
//     //           << " 身高： " << it->m_Height << endl;
// 	// }
// 	myprint(L);
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// void printList(const list<int>& L) {

// 	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
// 		cout << *it << " ";
// 	}
// 	cout << endl;
// }

// bool myCompare(int val1 , int val2)
// {
// 	return val1 > val2;
// }

// //反转和排序
// void test01()
// {
// 	list<int> L;
// 	L.push_back(90);
// 	L.push_back(30);
// 	L.push_back(20);
// 	L.push_back(70);
// 	printList(L);

// 	//反转容器的元素
// 	L.reverse();
// 	printList(L);

// 	//排序
// 	L.sort(); //默认的排序规则 从小到大
// 	printList(L);

// 	L.sort(myCompare); //指定规则，从大到小
// 	printList(L);
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// #include <list>

// void printList(const list<int>& L) {

// 	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {  //注意迭代器类型const_iterator
// 		cout << *it << " ";
// 	}
// 	cout << endl;
// }

// void test01()
// {
// 	list<int>L1;
// 	L1.push_back(10);
// 	L1.push_back(20);
// 	L1.push_back(30);
// 	L1.push_back(40);

// 	printList(L1);

// 	list<int>L2(L1.begin(),L1.end());
// 	printList(L2);

// 	list<int>L3(L2);
// 	printList(L3);

// 	list<int>L4(10, 1000);
// 	printList(L4);
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// #include <vector>

// void test01()
// {
// 	vector<int> v;

// 	//预留空间
// 	v.reserve(100000);

// 	int num = 0;
// 	int* p = NULL;
// 	for (int i = 0; i < 1000; i++) {
// 		v.push_back(i);
// 		// if (p != &v[i]) {
// 		// 	p = &v[i];
// 		// 	num++;
// 		// }
// 		num++;
// 	}

// 	cout << "num:" << num << endl;
// 	cout << "cap:" << v.capacity() << endl;

// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// //字符串拼接
// void test01()
// {
// 	string str1 = "我";

// 	str1 += "爱玩游戏";

// 	cout << "str1 = " << str1 << endl;

// 	str1 += ':';

// 	cout << "str1 = " << str1 << endl;

// 	string str2 = "LOL DNF";

// 	str1 += str2;

// 	cout << "str1 = " << str1 << endl;

// 	string str3 = "I";
// 	str3.append(" love ");
// 	str3.append("game abcd", 4);
// 	// str3.append("game abcde", 4);
// 	//str3.append(str2);
// 	str3.append(str2, 4, 3); // 从下标4位置开始 ，截取3个字符，拼接到字符串末尾
// 	cout << "str3 = " << str3 << endl;
// }
// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// //赋值
// void test01()
// {
// 	string str1;
// 	str1 = "hello world";
// 	cout << "str1 = " << str1 << endl;

// 	string str2;
// 	str2 = str1;
// 	cout << "str2 = " << str2 << endl;

// 	string str3;
// 	str3 = 'a';
// 	cout << "str3 = " << str3 << endl;

// 	string str4;
// 	str4.assign("hello c++");
// 	cout << "str4 = " << str4 << endl;

// 	string str5;
// 	str5.assign("hello c++",5);
// 	cout << "str5 = " << str5 << endl;

// 	string str6;
// 	str6.assign(str5);
// 	cout << "str6 = " << str6 << endl;

// 	string str7;
// 	str7.assign(5, 'x');
// 	cout << "str7 = " << str7 << endl;

//     string str8="abcdef";
// 	cout << "str8 = " << str8 << endl;
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// //string构造
// void test01()
// {
// 	string s1; //创建空字符串，调用无参构造函数
// 	cout << "str1 = " << s1 << endl;

// 	const char* str = "hello world";
// 	string s2(str); //把c_string转换成了string

// 	cout << "str2 = " << s2 << endl;

// 	string s3(s2); //调用拷贝构造函数
// 	cout << "str3 = " << s3 << endl;

// 	string s4(10, 'a');
// 	cout << "str3 = " << s3 << endl;

//     string s5;
//     s5="你好 中国";
// 	cout << "str5 = " << s5 << endl;

//     string s6("abcdef");
// 	cout << "str6 = " << s6 << endl;

// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// void MyPrint(int val)
// {
//     cout << val << endl;
// }

// void test01()
// {

//     //创建vector容器对象，并且通过模板参数指定容器中存放的数据的类型
//     vector<int> v;
//     //向容器中放数据
//     v.push_back(10);
//     v.push_back(20);
//     v.push_back(30);
//     v.push_back(40);

//     //每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
//     //v.begin()返回迭代器，这个迭代器指向容器中第一个数据
//     //v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
//     //vector<int>::iterator 拿到vector<int>这种容器的迭代器类型

//     vector<int>::iterator pBegin = v.begin();
//     vector<int>::iterator pEnd = v.end();

//     //第一种遍历方式：
//     while (pBegin != pEnd)
//     {
//         cout << *pBegin << endl;
//         pBegin++;
//     }

//     cout << "-------------------" << endl;

//     //第二种遍历方式：
//     for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//     {
//         cout << *it << endl;
//     }
//     cout << "-------------------" << endl;

//     //第三种遍历方式：
//     //使用STL提供标准遍历算法  头文件 algorithm
//     for_each(v.begin(), v.end(), MyPrint);
// }

// int main()
// {

//     test01();

//     system("pause");

//     return 0;
// }

// class person
// {
// public:
//     person() {}

//     person(string name, string sex)
//     {
//         this->m_name = name;
//         this->m_sex = sex;
//     }

//     person(const person &p)
//     {
//         this->m_name = p.m_name;
//         this->m_sex = p.m_sex;
//     }

//     void showP()
//     {
//         cout << "姓名：" << this->m_name << endl;
//         cout << "性别：" << this->m_sex << endl;
//     }

// private:
//     string m_name;
//     string m_sex;
// };

// void test01()
// {
//     person p1("张飞", "男");
//     p1.showP();

//     person p2(p1);
//     p2.showP();
// }

// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

// // #pragma once
// // #include <iostream>
// // using namespace std;

// template<class T>
// class MyArray
// {
// public:

// 	//构造函数
// 	MyArray(int capacity)
// 	{
// 		this->m_Capacity = capacity;
// 		this->m_Size = 0;
// 		pAddress = new T[this->m_Capacity];
// 	}

// 	//拷贝构造
// 	MyArray(const MyArray & arr)
// 	{
// 		this->m_Capacity = arr.m_Capacity;
// 		this->m_Size = arr.m_Size;
// 		this->pAddress = new T[this->m_Capacity];
//         // this->m_Capacity = arr.getCapacity();
// 		// this->m_Size = arr.getSize();
// 		// this->pAddress = new T[this->getCapacity()];
// 		for (int i = 0; i < this->m_Size; i++)
// 		{
// 			//如果T为对象，而且还包含指针，必须需要重载 = 操作符，因为这个等号不是 构造 而是赋值，
// 			// 普通类型可以直接= 但是指针类型需要深拷贝
// 			this->pAddress[i] = arr.pAddress[i];
// 		}
// 	}

// 	//重载= 操作符  防止浅拷贝问题
// 	MyArray& operator=(const MyArray& myarray) {

// 		if (this->pAddress != NULL) {
// 			delete[] this->pAddress;
// 			this->m_Capacity = 0;
// 			this->m_Size = 0;
// 		}

// 		this->m_Capacity = myarray.m_Capacity;
// 		this->m_Size = myarray.m_Size;
// 		this->pAddress = new T[this->m_Capacity];
// 		for (int i = 0; i < this->m_Size; i++) {
// 			this->pAddress[i] = myarray[i];
// 		}
// 		return *this;
// 	}

// 	//重载[] 操作符  arr[0]
// 	T& operator [](int index)
// 	{
// 		return this->pAddress[index]; //不考虑越界，用户自己去处理
// 	}

// 	//尾插法
// 	void Push_back(const T & val)
// 	{
// 		if (this->m_Capacity == this->m_Size)
// 		{
// 			return;
// 		}
// 		this->pAddress[this->m_Size] = val;
// 		this->m_Size++;
// 	}

// 	//尾删法
// 	void Pop_back()
// 	{
// 		if (this->m_Size == 0)
// 		{
// 			return;
// 		}
// 		this->m_Size--;
// 	}

// 	//获取数组容量
// 	int getCapacity()
// 	{
// 		return this->m_Capacity;
// 	}

// 	//获取数组大小
// 	int	getSize()
// 	{
// 		return this->m_Size;
// 	}

// 	//析构
// 	~MyArray()
// 	{
// 		if (this->pAddress != NULL)
// 		{
// 			delete[] this->pAddress;
// 			this->pAddress = NULL;
// 			this->m_Capacity = 0;
// 			this->m_Size = 0;
// 		}
// 	}

// private:
// 	T * pAddress;  //指向一个堆空间，这个空间存储真正的数据
// 	int m_Capacity; //容量
// 	int m_Size;   // 大小
// };

// #include <string>

// void printIntArray(MyArray<int>& arr) {
// 	for (int i = 0; i < arr.getSize(); i++) {
// 		cout << arr[i] << " ";
// 	}
// 	cout << endl;
// }

// //测试内置数据类型
// void test01()
// {
// 	MyArray<int> array1(10);
// 	for (int i = 0; i < 10; i++)
// 	{
// 		array1.Push_back(i);
// 	}
// 	cout << "array1打印输出：" << endl;
// 	printIntArray(array1);
// 	cout << "array1的大小：" << array1.getSize() << endl;
// 	cout << "array1的容量：" << array1.getCapacity() << endl;

// 	cout << "--------------------------" << endl;

// 	MyArray<int> array2(array1);
// 	array2.Pop_back();
// 	cout << "array2打印输出：" << endl;
// 	printIntArray(array2);
// 	cout << "array2的大小：" << array2.getSize() << endl;
// 	cout << "array2的容量：" << array2.getCapacity() << endl;
// }

// //测试自定义数据类型
// class Person {
// public:
// 	Person() {}
// 		Person(string name, int age) {
// 		this->m_Name = name;
// 		this->m_Age = age;
// 	}
// public:
// 	string m_Name;
// 	int m_Age;
// };

// void printPersonArray(MyArray<Person>& personArr)
// {
// 	for (int i = 0; i < personArr.getSize(); i++) {
// 		cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << endl;
// 	}

// }

// void test02()
// {
// 	//创建数组
// 	MyArray<Person> pArray(10);
// 	Person p1("孙悟空", 30);
// 	Person p2("韩信", 20);
// 	Person p3("妲己", 18);
// 	Person p4("王昭君", 15);
// 	Person p5("赵云", 24);

// 	//插入数据
// 	pArray.Push_back(p1);
// 	pArray.Push_back(p2);
// 	pArray.Push_back(p3);
// 	pArray.Push_back(p4);
// 	pArray.Push_back(p5);

// 	printPersonArray(pArray);

// 	cout << "pArray的大小：" << pArray.getSize() << endl;
// 	cout << "pArray的容量：" << pArray.getCapacity() << endl;

// }

// int main() {

// 	//test01();

// 	test02();

// 	system("pause");

// 	return 0;
// }

// //2、全局函数配合友元  类外实现 - 先做函数模板声明，下方在做函数模板定义，在做友元
// template<class T1, class T2> class Person;

// //如果声明了函数模板，可以将实现写到后面，否则需要将实现体写到类的前面让编译器提前看到
// //template<class T1, class T2> void printPerson2(Person<T1, T2> & p);

// template<class T1, class T2>
// void printPerson2(Person<T1, T2> & p)
// {
// 	cout << "类外实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
// }

// template<class T1, class T2>
// class Person
// {
// 	//1、全局函数配合友元   类内实现
// 	friend void printPerson(Person<T1, T2> & p)
// 	{
// 		cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
// 	}

// 	//全局函数配合友元  类外实现
// 	friend void printPerson2<>(Person<T1, T2> & p);

// public:

// 	Person(T1 name, T2 age)
// 	{
// 		this->m_Name = name;
// 		this->m_Age = age;
// 	}

// private:
// 	T1 m_Name;
// 	T2 m_Age;

// };

// //1、全局函数在类内实现
// void test01()
// {
// 	Person <string, int >p("Tom", 20);
// 	printPerson(p);
// }

// //2、全局函数在类外实现
// void test02()
// {
// 	Person <string, int >p("Jerry", 30);
// 	printPerson2(p);
// }

// int main() {

// 	test01();

// 	// test02();

// 	system("pause");

// 	return 0;
// }

// //类模板
// template<class NameType, class AgeType = int>
// class Person
// {
// public:
// 	Person(NameType name, AgeType age)
// 	{
// 		this->mName = name;
// 		this->mAge = age;
// 	}
// 	void showPerson()
// 	{
// 		cout << "name: " << this->mName << " age: " << this->mAge << endl;
// 	}
// public:
// 	NameType mName;
// 	AgeType mAge;
// };

// //1、指定传入的类型
// void printPerson1(Person<string, int> &p)
// {
// 	p.showPerson();
// }
// void test01()
// {
// 	Person <string, int >p("孙悟空", 100);
// 	printPerson1(p);
// }

// //2、参数模板化
// template <class T1, class T2>
// void printPerson2(Person<T1, T2>&p)
// {
// 	p.showPerson();
// 	cout << "T1的类型为： " << typeid(T1).name() << endl;
// 	cout << "T2的类型为： " << typeid(T2).name() << endl;
// }
// void test02()
// {
// 	Person <string, int >p("猪八戒", 90);
// 	printPerson2(p);
// }

// //3、整个类模板化
// template<class T>
// void printPerson3(T & p)
// {
// 	cout << "T的类型为： " << typeid(T).name() << endl;
// 	p.showPerson();

// }
// void test03()
// {
// 	Person <string, int >p("唐僧", 30);
// 	printPerson3(p);
// }

// int main() {

// 	test01();
// 	test02();
// 	test03();

// 	system("pause");

// 	return 0;
// }

/* //类模板
template<class NameType, class AgeType = int> 
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};

//1、类模板没有自动类型推导的使用方式
void test01()
{
	// Person p("孙悟空", 1000); // 错误 类模板使用时候，不可以用自动类型推导
	Person <string,int>p("孙悟空", 1000); //必须使用显示指定类型的方式，使用类模板
	p.showPerson();
}

//2、类模板在模板参数列表中可以有默认参数
void test02()
{
	Person <string> p("猪八戒", 999); //类模板中的模板参数列表 可以指定默认参数
	p.showPerson();
}

int main() {

	test01();

	test02();

	system("pause");

	return 0;
} */