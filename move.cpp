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
		cout << "����ʦ�°���" << endl;
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
		master = new teacher("����ʦ");
	}
	//Ĭ�����г�Ա����
	school(const school &p)
	{
		cout << "�����˿�������" << endl;
		master = new teacher(*(p.master));
	}
	school(school&& other) :schoolname(other.schoolname), schooltype(other.schooltype), address(other.address)
	{
		cout << "�����ƶ�����" << endl;
		master = other.master;
		other.master = NULL;
	}
};
school getschool()
{
	school s2("����ʯ�ʹ�ѧ", "��ѧ", "����");
	return s2;
}
int main()
{
	school s1(getschool());
	cout << "���һ�����" << endl;
}