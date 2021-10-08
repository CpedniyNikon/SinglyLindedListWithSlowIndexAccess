#pragma once
#ifndef MYLIST_H
#define MYLIST_H
template<typename T>
class MyList
{
public:
	MyList();
	MyList(const T& value);
	void list_push_back(const T& value);
	void list_pop_back();
	void list_push_front(const T& value);
	T& get_value();
	MyList& get_next();
	MyList& operator=(const MyList& list);
	int get_list_length();
	T& operator[](int index);
	T& func(MyList<T>* list, int i, int index);
private:
	T value_; //value of type T
	MyList* last_element_; //pointer to the last element
	MyList* prev_element_; //poiter to element before the last one
	MyList* next_; //pointer to the next element of the MyList
	MyList* first_element_; //pointer to first element of the MyList
	int list_length; // length of the MyList
};
#endif // !MYLIST_H