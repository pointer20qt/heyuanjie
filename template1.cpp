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
	cout << "ģ���Ƶ�����" << endl;
	return a > b ? a : b;
}
int Lmax(int a, int b)
{
	cout << "int�汾����" << endl;
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
		cout << "������tool����" << endl;
	}
	~tool()
	{
		cout << "������tool����" << endl;
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
		cout << "���캯��" << endl;
	}
	operator int()
	{
		cout << "��������ת��Ϊint" << endl;
		return value;
	}
	A(const A& other)
	{
		t = new tool;
		value = other.value;
		cout << "��������A" << endl;
	}
	A(A&& other)
	{
		t = other.t;
		other.t = nullptr;
		value = other.value;
		cout << "�ƶ�����A" << endl;
	}
	//���Ƹ�ֵ�����
	A& operator=(const A& other)
	{
		delete t;
		t = new tool;
		value = other.value;
		return *this;
	}
	//�ƶ���ֵ�����
	A& operator=(const A&& other)
	{
		delete t;
		t = nullptr;
		value = other.value;
		cout << "�ƶ���ֵA" << endl;
		return *this;
	}
	~A()
	{
		delete t;
		cout << "��������" << endl;
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
	cout << "��������" << endl;
}
int main()
{
	//��ʽ�Ƶ�
	//cout << Lmax<2,int,int,double>(x1, d1) << endl;
	//��ʽ�Ƶ�
	//cout << Lmax<2>(x1, x2) << endl;;
	//��ʽָ��ģ��(ǿ��ʹ��ģ������)
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
