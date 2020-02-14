#include<iostream>
#include<string>
#include<initializer_list>
using namespace std;
class vec
{
	int* obj;
public:
	vec(initializer_list<int> arr)
	{
		obj = new int[arr.size()];
		for (int i = 0; i < arr.size(); i++)
		{
			obj[i] = *(arr.begin() + i);
		}
		for (auto i = arr.begin(); i != arr.end(); i++)
		{
			cout << *i << endl;
		}
	}
	int& operator[](unsigned int index)
	{
		return obj[index];
	}	
};
int main()
{
	vec v({ 1, 2, 3, 4, 5 });
	cout << v[1]<<endl;
}