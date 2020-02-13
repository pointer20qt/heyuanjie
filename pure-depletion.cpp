#include<iostream>
#include<string>
using namespace std;
class A
{
public:
	virtual void fun()
	{
		cout << "走了A的fun" << endl;
	}
	virtual void druck()
	{
		cout << "走了A的druck" << endl;
	}
};
class B :public A
{
	public:
	virtual void fun()
	{
		cout << "走了B的fun" << endl;
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
		cout << "重写了纯虚函数" << endl;
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