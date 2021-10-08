#include <iostream>
using namespace std;
template<typename T>
class List
{
public:
	List()
	{
		this->list_length = 0;
	}
	List(const T& value)
	{
		this->value_ = value;
		this->last_element_ = this;
		list_length = 1;
	}
	void list_push_back(const T& value)
	{
		if (list_length == 0)
		{
			this->value_ = value;
			this->prev_element_ = this;
			this->last_element_ = this;
		}
		else
		{
			this->prev_element_ = this->last_element_;
			this->last_element_->next_ = new List(value);
			this->last_element_ = this->last_element_->next_;
		}
		list_length++;
	}
	void list_pop_back()
	{
		if (list_length == 0)
		{
			return;
		}
		if (list_length == 1)
		{
			this->last_element_ = this;
			prev_element_ = this;
			list_length--;
			return;
		}
		this->last_element_ = prev_element_;
		prev_element_ = last_element_->prev_element_;
		delete last_element_->next_;
		list_length--;
	}
	void list_push_front(const T& value)
	{
		if (list_length == 0)
			this->value_ = value;
		else
		{
			List* new_list = this;
			this->value_ = value;
			this->next_ = new_list;
		}
		list_length++;
	}
	T& get_value()
	{
		if (list_length > 0)
			return this->value_;
		throw   string("exception no access");
	}
	List& get_next()
	{
		return *(this->next_);
	}
	List& get_prev()
	{
		return *(this->prev_element_);
	}
	List& operator=(const List& list)
	{
		this->value_ = list.value;
		this->next_ = list.next_;
		return *this;
	}
	int get_list_length()
	{
		return this->list_length;
	}
	T& operator[](int index)
	{
		return func(this, 0, index);
	}
	T& func(List<T>* list, int i, int index)
	{
		if (i > index || index >= this->list_length)
			throw string("exception no index access");
		if (i == index)
			return list->get_value();
		func(list->next_, ++i, index);
		
	}
private:
	T value_; //value of type T
	List* last_element_; //pointer to the last element
	List* prev_element_; //poiter to element before the last one
	List* next_; //pointer to the next element of the List
	int list_length; // length of the List
};



int main()
{
	try
	{
		List<int> l1;
		int n = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int value;
			cin >> value;
			l1.list_push_back(value);
		}
		int m = 0;
		cin >> m;
		cout << l1[m];
	}
	catch (string exception)
	{
		if (exception == "exception no access" || exception == "exception no index access")
			cout << exception << '\n';
	}
	return 0;
}