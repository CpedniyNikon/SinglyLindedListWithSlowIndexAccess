#include <iostream>
#include <string>
using namespace std;
template<typename T>
class List
{
public:
	List()
	{
		this->list_length = 0;
		first_element_ = this;
	}
	List(const T& value)
	{
		this->value_ = value;
		this->last_element_ = this;
		this->first_element_ = this;
		list_length = 1;
	}
	void list_push_back(const T& value)
	{
		if (list_length == 0)
		{
			this->value_ = value;
			this->last_element_ = this;
			this->first_element_ = this;
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
			throw string("exception no element");
		}
		if (list_length == 1)
		{
			this->last_element_ = this;
			this->first_element_ = this;
			delete last_element_;
			list_length--;
			return;
		}
		delete last_element_;
		last_element_ = prev_element_;
		list_length--;
	}
	void list_push_front(const T& value)
	{
		List* new_ = new List(value);
		list_length++;
		if (list_length == 1)
		{
			new_->next_ = nullptr;
			first_element_ = last_element_ = new_;
			return;
		}
		new_->next_ = first_element_;
		first_element_ = new_;
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
	List& operator=(const List& list)
	{
		this->value_ = list.value;
		this->next_ = list.next_;
		this->first_element_ = list.first_element_;
		return *this;
	}
	int get_list_length()
	{
		return this->list_length;
	}
	T& operator[](int index)
	{
		return func(first_element_, 0, index);
	}
	T& func(List<T>* list, int i, int index)
	{
		if (!list)
			throw string("exception no index access");
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
	List* first_element_; //pointer to first element of the List
	int list_length; // length of the List
};



int main()
{
	try
	{
		List<int> list;
		int N = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int value = 0;
			cin >> value;
			list.list_push_back(value);
		}
		list.list_pop_back();
		list.list_pop_back();
		list.list_push_front(-1);
		list.list_push_front(-2);
		for (int i = 0; i < list.get_list_length(); i++)
		{
			cout << list[i] << " ";
		}
	}
	catch (string exception)
	{
		if (exception == "exception no access" || exception == "exception no index access")
			cout << exception << '\n';
	}
	return 0;
}