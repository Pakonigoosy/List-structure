#pragma once
#include <initializer_list>

template<typename T>
struct list_element
{
	T value;
	list_element<T> *next;
	list_element<T> *prev;
};

template<typename T>
class List
{
public:
	List();
	List(std::initializer_list<T> init);
	void test();
private:
	list_element<T> *first;
};



