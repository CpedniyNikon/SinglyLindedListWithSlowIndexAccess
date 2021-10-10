#include "MyList.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	try
	{
		//some code to show how it works in practice
		MyList<int> list;
		for (int i = 0; i < 5; i++)
		{
			list.push_back(i);
		}
		list.pop_back();
		list.pop_back();
		list.push_front(-1);
		list.push_front(-2);
		for (int i = 0; i < list.size(); i++)
		{
			cout << list[i] << endl;
		}
		//some code to show how it works in practice
	}
	catch (string exception)
	{
		cout << exception << '\n';
	}
	return 0;
}
