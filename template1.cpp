#include<iostream>
#include<string>
#include<initializer_list>
#include<assert.h>
#include<vector>
using namespace std;
#include<iostream>
#include<string>
#include<initializer_list>
#include<assert.h>
#include<vector>
using namespace std;
template< int d, class T1, class T2, class T3 = int>T1 Lmax(T1 a, T2 b)
{
	cout << d << endl;
	cout << "模板推导函数" << endl;
	return a > b ? a : b;
}
int Lmax(int a, int b)
{
	cout << "int版本函数" << endl;
	return a > b ? a : b;
}
template<class T> void Lswap(T& a, T& b)
{
	T tem = move(a);
	a = move(b);
	b = move(tem);
}
class tool
{
public:
	tool()
	{
		cout << "创建了tool对象" << endl;
	}
	~tool()
	{
		cout << "析构了tool对象" << endl;
	}

};
class A
{
public:
	int value = 0;
	tool* t;
	A(int v)
	{
		t = new tool;
		value = v;
		cout << "构造函数" << endl;
	}
	operator int()
	{
		cout << "函数对象转化为int" << endl;
		return value;
	}
	A(const A& other)
	{
		t = new tool;
		value = other.value;
		cout << "拷贝构造A" << endl;
	}
	A(A&& other)
	{
		t = other.t;
		other.t = nullptr;
		value = other.value;
		cout << "移动构造A" << endl;
	}
	//复制赋值运算符
	A& operator=(const A& other)
	{
		delete t;
		t = new tool;
		value = other.value;
		return *this;
	}
	//移动赋值运算符
	A& operator=(const A&& other)
	{
		delete t;
		t = nullptr;
		value = other.value;
		cout << "移动赋值A" << endl;
		return *this;
	}
	~A()
	{
		delete t;
		cout << "析构函数" << endl;
	}
};
template<class T>class L_stack
{
	vector<T> arr;
public:
	void push(T&& obj)
	{
		arr.push_back(obj);
	}
	void pop(){
		arr.pop_back();
	}
	T& top(){
		return arr.back();
	}
	size_t size()
	{
		return arr.size();
	}
	bool empty()
	{
		return arr.empty();
	}


};
void fun()
{
	A a1(2), a2(5);
	Lswap(a1, a2);
	cout << "函数结束" << endl;
}
int main()
{
	//显式推导
	//cout << Lmax<2,int,int,double>(x1, d1) << endl;
	//隐式推导
	//cout << Lmax<2>(x1, x2) << endl;;
	//显式指定模板(强行使用模板生成)
	//cout << Lmax<5>(x1, x2)<<endl;
	//Lswap(x1, x2);
	L_stack<int> l;
	l.push(5);
	l.push(6);
	l.push(7);
	cout << l.top() << endl;
	l.pop();
	cout << l.top() << endl;
	cout << l.size() << endl;

}
