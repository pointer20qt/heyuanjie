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
};
void swap(school a, school b)
{
	school t = a;
	/*a = b;
	b = t;*/
}
int main()
{
	school s1("����ʯ�ʹ�ѧ", "��ѧ", "����");
	school s2("��һũ�Ѵ�ѧ", "��ѧ", "����");
	swap(s1, s2);
	cout << "���һ�����" << endl;
}