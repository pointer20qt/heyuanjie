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
	auto_ptr<tool> ptr(new tool);
	auto_ptr<tool> ptr2{ ptr };
	auto_ptr<tool> ptr3;
	ptr3 = ptr2;
	int t = 5;
	if (t == 5)
	{
		return;
	}
}
template<class T>
class L_autoptr
{
	T* obj = nullptr;
public:
	L_autoptr(T* ptr) :obj(ptr)
	{
		obj = ptr;
	}
	L_autoptr() = default;
	~L_autoptr()
	{
		delete obj;
	}
	L_autoptr(L_autoptr<T>& ptr)
	{
		obj = ptr.obj;
		ptr.obj = nullptr;
	}
	L_autoptr& operator = (L_autoptr<T>& ptr)
	{
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
		return *this;
	}
	void reset(T* newptr)
	{
		delete obj;
		obj = newptr;
	}
	T* release()
	{
		auto tem = obj;
		obj = nullptr;
		return tem;
	}
	T& operator*()
	{
		return *obj;
	}
	T* operator->()
	{
		return obj;
	}
	T* get()
	{
		return obj;
	}
};
int main()
{
	L_autoptr<tool> ptr{ new tool };
	L_autoptr<tool> ptr2{ ptr };
	L_autoptr<tool> ptr3;
	ptr3 = ptr2;
	ptr3->value;
}