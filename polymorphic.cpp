#include<iostream>
#include<string>
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
	string schoolname;
	string schooltype;
	string address;
	teacher* master;
public:
	string getname()
	{
		return schoolname;
	}
	virtual~school()
	{
		cout << schoolname << "闭校了" << endl;
		delete master;
	}
	school(string schoolname, string schooltype, string address)
	{
		cout << "普通构造函数" << endl;
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
	virtual void schoolopens()
	{
		cout << this->schoolname << "开学了" << endl;
	}
	virtual void schoolopens(int i)
	{
		for (int j = 0; j < i; j++)
		{
			cout << this->schoolname << "开学了" << endl;
		}
	}
};
class university :public school
{
public:
	teacher* vice;
	university() :school("大庆指针", "大学", "大庆")
	{
		cout << "大学的构造函数" << endl;
		vice = new teacher("朱老师");
	}
	virtual void schoolopens()
	{
		cout << "在大学校长带领下" << getname() <<"开学典礼完事"<< endl;
	}
	~university()
	{
		cout << "调用大学的析构函数" << endl;
		delete vice;
	}
};
void printfschool(school* s)
{
	s->schoolopens();
	delete s;
}
void printfschool(school& s)
{
	s.schoolopens();
	delete &s;
}
int main()
{
	school* ps = new school("春花幼儿园", "幼儿园", "大庆");
	university *us = new university();
	printfschool(ps);
	printfschool(us);

	/*university u;
	printfschool(u);*/
}