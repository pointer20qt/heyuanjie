#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> a{ 1, 2, 3, 4, 5 };
	try{
		for (int i = 0; i < 7; i++)
		{
			cout << a.at(i) << endl;
		}
		throw(2);
		cout << "打印完了" << endl;
	}
	catch (out_of_range& e)
	{
		cout << "出现了越界" << endl;
	}
	catch (...)
	{
		cout << "出现了异常" << endl;
	}
}