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
		cout << "����ʦ�°���" << endl;
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
		cout << schoolname << "��У��" << endl;
		delete master;
	}
	school(string schoolname, string schooltype, string address)
	{
		cout << "��ͨ���캯��" << endl;
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
	virtual void schoolopens()
	{
		cout << this->schoolname << "��ѧ��" << endl;
	}
	virtual void schoolopens(int i)
	{
		for (int j = 0; j < i; j++)
		{
			cout << this->schoolname << "��ѧ��" << endl;
		}
	}
};
class university :public school
{
public:
	teacher* vice;
	university() :school("����ָ��", "��ѧ", "����")
	{
		cout << "��ѧ�Ĺ��캯��" << endl;
		vice = new teacher("����ʦ");
	}
	virtual void schoolopens()
	{
		cout << "�ڴ�ѧУ��������" << getname() <<"��ѧ��������"<< endl;
	}
	~university()
	{
		cout << "���ô�ѧ����������" << endl;
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
	school* ps = new school("�����׶�԰", "�׶�԰", "����");
	university *us = new university();
	printfschool(ps);
	printfschool(us);

	/*university u;
	printfschool(u);*/
}