#include "MyList.h"
#include <string>
template<typename Ty> MyList<Ty>::MyList()
{
	this->list_length = 0;
}
template<typename Ty> MyList<Ty>::MyList(const Ty& value)
{
	this->value_ = value;
	this->last_element_ = this;
	this->first_element_ = this;
	list_length = 1;
}
template<typename Ty> void MyList<Ty>::list_push_back(const Ty& value)
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
template<typename Ty> void MyList<Ty>::list_pop_back()
{
	if (list_length == 0)
	{
		
		throw std::string("exception no element");
	}
	if (list_length == 1)
	{
		last_element_ = this;
		first_element_ = this;
		delete last_element_;
		list_length--;
		return;
	}
	delete last_element_;
	last_element_ = prev_element_;
	list_length--;
}
template<typename Ty> void MyList<Ty>::list_push_front(const Ty& value)
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
template<typename Ty> Ty& MyList<Ty>::get_value()
{
	if (list_length > 0)
		return value_;
	throw std::string("exception no access");
}
template<typename Ty> MyList<Ty>& MyList<Ty>::get_next()
{
	return *(next_);
}
template<typename Ty> MyList<Ty>& MyList<Ty>::operator=(const MyList<Ty>& list)
{
	value_ = list.value;
	next_ = list.next_;
	first_element_ = list.first_element_;
	return *this;
}
template<typename Ty> int MyList<Ty>::get_list_length()
{
	return list_length;
}
template<typename Ty> Ty& MyList<Ty>::operator[](int index)
{
	return func(first_element_, 0, index);
}
template<typename Ty> Ty& MyList<Ty>::func(MyList<Ty>* list, int i, int index)
{
	if (!list)
		throw std::string("exception no index access");
	if (i > index || index >= list_length)
		throw std::string("exception no index access");
	if (i == index)
		return list->get_value();
	func(list->next_, ++i, index);

}