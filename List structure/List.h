#pragma once
#include <initializer_list>
#include <iterator>
template<typename T>
class ListIterator;

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
	typedef ListIterator<list_element<T>> iterator;
	typedef ListIterator<const list_element<T>> const_iterator;
	
	List();
	List(std::initializer_list<T> init);


	void pop_front();
	void pop_back();
	void push_front(T elem);
	void push_back(T elem);
	T front();
	T back();
	void insert(List<T>::iterator, T value);
	//void copy(iterator fst, iterator lst, std::ostream_iterator<T> action);
	void unique();
	void merge(List<T> to_merge);

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;
	

private:
	list_element<T> *first;

};



template<typename T>
class ListIterator : public std::iterator<std::input_iterator_tag, T>
{
	friend class List<T>;
private:
	
	T* p;
public:
	ListIterator(T* p);
	ListIterator(const ListIterator& it);
	

	bool operator!=(ListIterator const& other) const;
	bool operator==(ListIterator const& other) const;
	T& operator*() const;
	ListIterator& operator++();
	ListIterator& operator--();
};

