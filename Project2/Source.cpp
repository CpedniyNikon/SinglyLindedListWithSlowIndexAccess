#include "MyList.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	try
	{
		MyList<int> list;
		for (int i = 0; i < 5; i++)
		{
			list.list_push_back(i);
		}
		list.list_pop_back();
		list.list_pop_back();
		list.list_push_front(-1);
		list.list_push_front(-2);
		for (int i = 0; i < list.get_list_length(); i++)
		{
			cout << list[i] << endl;
		}
	}
	catch (string exception)
	{
		cout << exception << '\n';
	}
	return 0;
}
