#include<iostream>
using namespace std;
class teacher
{
	string name;
public:
	teacher(string name)
	{
		this->name = name;
	}
	~teacher()
	{
		cout << "杨老师下班了" << endl;
	}
};
class school
{
public:
	string schoolname;
	string schooltype;
	string address;
	teacher* master;
	~school()
	{
		delete master;
	}
	school(string schoolname, string schooltype, string address)
	{
		this->schoolname = schoolname;
		this->schooltype = schooltype;
		this->address = address;
		master = new teacher("杨老师");
	}
	//默认所有成员对象
	school(const school &p)
	{
		cout << "进行了拷贝构造" << endl;
		master = new teacher(*(p.master));
	}
};
void swap(school a, school b)
{
	school t = a;
	/*a = b;
	b = t;*/
}
int main()
{
	school s1("东北石油大学", "大学", "大庆");
	school s2("八一农垦大学", "大学", "大庆");
	swap(s1, s2);
	cout << "最后一句代码" << endl;
}