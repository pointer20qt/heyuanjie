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
	school(school&& other) :schoolname(other.schoolname), schooltype(other.schooltype), address(other.address)
	{
		cout << "用了移动构造" << endl;
		master = other.master;
		other.master = NULL;
	}
};
school getschool()
{
	school s2("东北石油大学", "大学", "大庆");
	return s2;
}
int main()
{
	school s1(getschool());
	cout << "最后一句代码" << endl;
}