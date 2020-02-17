#include<iostream>
#include<string>
#include<initializer_list>
#include<assert.h>
#include<vector>
#include<memory>
using namespace std;
class tool
{
public:
	int value=0;
	tool()
	{
		cout << "tool构造了" << endl;
	}
	~tool()
	{
		cout << "tool析构了" << endl;
	}
};
void fun()
{
	shared_ptr<tool> ptr(new tool);
	cout << "当前引用计数：" << ptr.use_count() << endl;
	shared_ptr<tool> ptr2{ ptr };
	shared_ptr<tool> ptr3;
	ptr3 = ptr2;
	cout << "当前引用计数：" << ptr.use_count() << endl;
	cout << "当前引用计数：" << ptr2.use_count() << endl;
	cout << "当前引用计数：" << ptr3.use_count() << endl;
}
struct A
{
	shared_ptr<A> pre;
	shared_ptr<A> next;
	~A()
	{
		cout << "A被析构了" << endl;
	}
};
void use()
{
	shared_ptr<A> a1(new A);
	shared_ptr<A> a2(new A);
	a1->next = a2;
	a2->pre = a1;
}
int main()
{
	fun();
	use();
}