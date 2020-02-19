#include<iostream>
#include<string>
#include<initializer_list>
#include<math.h>
#include<time.h>
using namespace std;
void run1(int a)
{
	//怎么通过rand生成[0,a)的数
	int r = rand() % a;
	cout << r << endl;
}
void run2(int a,int b)
{
	//怎么通过rand生成[a,b)的数
	int r = rand() % (b-a)+a;
	cout << r << endl;
}
void run3(double a)
{
	//怎么生成一个0~1的随机小数double
	double r = ((double)rand() )/RAND_MAX;
	cout << r << endl;
}
void run4(int a, int b)
{
	//怎么生成a~b的随机小数
	double r = rand() % (b - a) + a + ((double)rand()) / RAND_MAX;
	cout << r << endl;
}
bool run5(int a)
{
	//传入0到100的整数，概率性判断成功,成功返回true
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
	//传入0到1的double，概率性判断成功，成功返回ture。
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