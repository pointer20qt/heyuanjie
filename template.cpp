#include<iostream>
#include<string>
#include<initializer_list>
#include<assert.h>
using namespace std;
template< int d,class T1, class T2,class T3=int>T1 Lmax(T1 a, T2 b)
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
template<class T> void Lswap(T& a,T& b)
{
	T tem = a;
	a = b;
	b = tem;
}
class A
{
public:
	int value = 0;
	char* p;
	A(int v)
	{
		p = new char[100];
		value = v;
	}
	operator int()
	{
		cout << "函数对象转化为int" << endl;
		return value;
	}
	A(const A& other) :A(other.value)
	{
		p = new char[100];
		value = other.value;
		cout << "拷贝构造A" << endl;
	}
	A& operator=(const A& other)
	{
		delete p;
		p = new char[100];
		value = other.value;
		return *this;
	}
	~A()
	{
		delete p;
		cout << "析构函数" << endl;
	}
};
int main()
{
	int x1 = 2, x2 = 5;
	double d1 = 2.3, d2 = 4.4;
	A a1(2), a2(5);
	//显式推导
	//cout << Lmax<2,int,int,double>(x1, d1) << endl;
	//隐式推导
	//cout << Lmax<2>(x1, x2) << endl;;
	//显式指定模板(强行使用模板生成)
	//cout << Lmax<5>(x1, x2)<<endl;
	Lswap(x1, x2);
	Lswap(a1, a2);
	cout << a1 << "与" << a2 << "交换了" << endl;
}