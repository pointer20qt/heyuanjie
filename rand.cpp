#include<iostream>
#include<string>
#include<initializer_list>
#include<math.h>
#include<time.h>
using namespace std;
void run1(int a)
{
	//��ôͨ��rand����[0,a)����
	int r = rand() % a;
	cout << r << endl;
}
void run2(int a,int b)
{
	//��ôͨ��rand����[a,b)����
	int r = rand() % (b-a)+a;
	cout << r << endl;
}
void run3(double a)
{
	//��ô����һ��0~1�����С��double
	double r = ((double)rand() )/RAND_MAX;
	cout << r << endl;
}
void run4(int a, int b)
{
	//��ô����a~b�����С��
	double r = rand() % (b - a) + a + ((double)rand()) / RAND_MAX;
	cout << r << endl;
}
bool run5(int a)
{
	//����0��100���������������жϳɹ�,�ɹ�����true
	int r = rand() % 100;
	if (r < a)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool run5(double a)
{
	//����0��1��double���������жϳɹ����ɹ�����ture��
	double r = ((double)rand()) /RAND_MAX;
	if (r < a)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int t=0, f=0;
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		if (run5(0.45))
		{
			t++;
		}
		else
		{
			f++;
		}
	}
	cout << t<<"  "<<f << endl;
	
	
}