#include<iostream>
using namespace std;
using I = int;
class school
{
	friend class A;
	string schoolname;
	string schooltype;
	string address;
	I num;
};
class A
{
public:
	school s;
	void fun()
	{
		s.num = 100;
		cout << s.num << endl;
	}
};
int main1()
{
	A a;
	a.fun();
	return 0;
}
