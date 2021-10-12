#include "MyList.h"
#include <iostream>
#include <string>
using namespace std;

std::ostream& operator<<(std::ostream& fout, MyList<int> list)
{
	fout << list.get_value();
	return fout;
}

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
		list.insert(0, -1);
		for (auto it = list.begin(); it != list.end(); it = it->get_next())
		{
			cout << *it << " ";
		}
		//some code to show how it works in practice
	}
	catch (string exception)
	{
		cout << exception << '\n';
	}
	return 0;
}
