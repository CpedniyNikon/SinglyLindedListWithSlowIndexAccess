#pragma once
#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
template<typename T>
class MyList
{
public:
	MyList();
	MyList(const T&);
	void push_back(const T&);
	void pop_back();
	void push_front(const T&);
	void insert(int, const int);
	MyList& operator=(const MyList&);
	//std::ostream& operator<<(std::ostream& fout, const MyList& list);
	MyList* begin();
	MyList* end();
	int size();
	T& get_value();
	MyList* get_next();
	T& operator[](int);
private:
	T value_; //value of type T
	MyList* last_element_; //pointer to the last element
	MyList* prev_element_; //poiter to element before the last one
	MyList* next_; //pointer to the next element of the MyList
	MyList* first_element_; //pointer to first element of the MyList
	int list_length; // length of the MyList
	T& func(MyList<T>*, int, int);
	void func1(MyList<T>*, int, int, int);
};
#endif // !MYLIST_H