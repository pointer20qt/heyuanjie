#include<iostream>
#include<string>
using namespace std;
class A
{
public:
	virtual void fun()
	{
		cout << "����A��fun" << endl;
	}
	virtual void druck()
	{
		cout << "����A��druck" << endl;
	}
};
class B :public A
{
	public:
	virtual void fun()
	{
		cout << "����B��fun" << endl;
	}
};
class C
{
public:
	virtual void wash() = 0;
};
class D :public C
{
public:
	void wash()
	{
		cout << "��д�˴��麯��" << endl;
	}
};
int main()
{
	A a;
	B b;
	D d;
	d.wash();
	A* pb = &b;
	pb->druck();
	pb->fun();
}