#include<iostream>
#include<string>
#include<initializer_list>
#include<assert.h>
#include<vector>
using namespace std;
void Lprint()
{
	cout << "²ð°üÍê±Ï" << endl;
}
template<class T, class... args> void Lprint(T t,args...d)
{
	cout << t << endl;
	Lprint(d...);
}

int main()
{
	Lprint<int>(1, 2, 3, 4.5,"hyj");

}