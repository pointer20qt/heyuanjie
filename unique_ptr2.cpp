#include<iostream>
#include<string>
#include<initializer_list>
#include<assert.h>
#include<vector>
#include<memory>
using namespace std;
class tool
{
public:
	int value=0;
	tool()
	{
		cout << "tool������" << endl;
	}
	~tool()
	{
		cout << "tool������" << endl;
	}
};
void fun()
{
	unique_ptr<tool> ptr(new tool);
	unique_ptr<tool> ptr2{ move(ptr) };
	unique_ptr<tool> ptr3;
	ptr3 = move(ptr2);
}
int main()
{
	fun();
}