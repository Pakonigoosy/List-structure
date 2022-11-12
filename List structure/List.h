#pragma once
#include <initializer_list>
#include <iterator>


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


	void pop_front();
	void pop_back();
	void push_front(T elem);
	void push_back(T elem);
	T front();
	T back();
	void insert();
	void copy();
	void unique();
	void merge(List<T> to_merge);

	//Нереализованные методы итераторов
	/*iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;*/
	

private:
	list_element<T> *first;
	const size_t size;

};


//Нереализованный итератор
/*template<typename T>
class ListIterator : public std::iterator<std::input_iterator_tag, T>
{
	friend class List;

};*/

