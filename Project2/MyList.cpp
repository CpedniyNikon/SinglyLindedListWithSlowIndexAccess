#include "MyList.h"
#include <string>
#include <iostream>
//There are only int-classes functions so far.
template<>
MyList<int>::MyList()
{
	this->list_length = 0;
}
template<>
MyList<int>::MyList(const int& value)
{
	value_ = value;
	last_element_ = this;
	first_element_ = this;
	next_ = nullptr;
	list_length = 1;
}
template<>
void MyList<int>::push_back(const int& value)
{
	if (list_length == 0)
	{
		value_ = value;
		last_element_ = this;
		first_element_ = this;
	}
	else
	{
		prev_element_ = last_element_;
		last_element_->next_ = new MyList(value);
		last_element_ = last_element_->next_;
	}
	list_length++;
}
template<>
void MyList<int>::pop_back()
{
	if (list_length == 0)
	{
		throw std::string("exception no element");
	}
	if (list_length == 1)
	{
		last_element_ = nullptr;
		first_element_ = nullptr;
		list_length--;
		return;
	}
	last_element_ = prev_element_;
	list_length--;
}
template<>
void MyList<int>::push_front(const int& value)
{
	MyList* new_ = new MyList(value);
	list_length++;
	if (list_length == 1)
	{
		first_element_ = new MyList(value);
		last_element_ = new MyList(value);
		return;
	}
	new_->next_ = first_element_;
	first_element_ = new_;
}
template<>
MyList<int>* MyList<int>::begin()
{
	return this->first_element_;
}
template<>
MyList<int>* MyList<int>::end()
{
	return this->last_element_->next_;
}
template<>
MyList<int>& MyList<int>::operator=(const MyList<int>& list)
{
	value_ = list.value_;
	return *this;
}
template<>
MyList<int>* MyList<int>::get_next()
{
	return this->next_;
}
template<>
int& MyList<int>::get_value()
{
	return this->value_;
}
template<>
void MyList<int>::insert(int pos, const int value)
{
	func1(first_element_, 0, pos, value);
}
template<>
int MyList<int>::size()
{
	return list_length;
}
template<>
int& MyList<int>::operator[](int index)
{
	return func(first_element_, 0, index);
}
template<>
int& MyList<int>::func(MyList<int>* list, int i, int index)
{
	if (!list)
		throw std::string("exception no index access");
	if (i > index || index >= list_length)
		throw std::string("exception no index access");
	if (i == index)
		return list->value_;
	func(list->next_, ++i, index);
}
template<>
void MyList<int>::func1(MyList<int>* list, int i, int index, int value)
{
	if (!list)
		throw std::string("exception no index access");
	if (i > index || index >= list_length)
		throw std::string("exception no index access");
	if (i == index - 1)
	{
		MyList* new_ = new MyList(value);
		new_->next_ = list->next_;
		list->next_ = new_;
		list_length++;
		return;
	}
	func1(list->next_, ++i, index, value);
}