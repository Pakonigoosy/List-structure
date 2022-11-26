#pragma once
#include <initializer_list>
#include <iterator>
#include <iostream>
template<typename T>
class ListIterator;

template<typename T>
struct list_element
{
	T value;
	list_element<T> *next;
	list_element<T> *prev;
	operator T() const { return value; };
};

template<typename T>
class List
{
	
public:
	typedef ListIterator<list_element<T>> iterator;
	typedef ListIterator<const list_element<T>> const_iterator;
	typedef list_element<T> value_type;
	
	List();
	List(std::initializer_list<T> init);
	~List();


	void pop_front();
	void pop_back();
	void push_front(T elem);
	void push_back(T elem);
	T front();
	T back();
	iterator insert(List<T>::iterator, T value);
	void unique();
	void merge(List<T> to_merge);
	void erase(iterator start, iterator finish);
	iterator erase(iterator pos);
	void remove(T x);
	void remove_if(bool (*function)(T));



	size_t get_size() { return size; };

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;
	

private:
	list_element<T>* first;
	list_element<T>* last;
	size_t size;
	void delete_element(iterator& pos);

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

template<typename T>
bool operator!=(const list_element<T>& a, const list_element<T>& b) {
	return a.value != b.value;
}

template<typename T>
bool operator==(const list_element<T>& a, const list_element<T>& b) {
	return a.value == b.value;
}
template<typename T>
std::ostream& operator<<(std::ostream& out, const list_element<T>& a) {
	out << a.value;
	return out;
}



template <typename T>
List<T>::List() {
	list_element<T>* first_le = new list_element<T>;
	list_element<T>* last_le = new list_element<T>;
	first = first_le;
	first->next = last;
	first->value = NULL;
	first->prev = NULL;
	last = new list_element<T>;
	last->next = NULL;
	last->prev = first;
	last->value = NULL;
	size = 0;
}

template <typename T>
List<T>::List(std::initializer_list<T> init) {
	if (init.size() > 0) {
		list_element<T>* current = new list_element<T>;
		list_element<T>* prev = new list_element<T>;
		first = current;
		current->prev = NULL;
		for (auto& item : init) {
			prev = current;
			current->value = item;
			current->next = new list_element<T>;
			current = current->next;
			current->prev = prev;
		}
		current->next = NULL;
		current->value = NULL;
		last = current;
		size = init.size();
	}
	else {
		List();
	}
}

template<typename T>
List<T>::~List() {
	for (iterator it = iterator(last->prev); it != iterator(first); ) {
		delete_element(it);
	}
	delete first;
	delete last;
}

template <typename T>
void List<T>::pop_front() {
	if (size > 0) {
		iterator fst = iterator(first);
		delete_element(fst);
		size -= 1;
	}
	
}

template <typename T>
void List<T>::pop_back() {
	if (size > 0) {
		iterator lst = iterator(last->prev);
		delete_element(lst);
		size -= 1;
	}
}

template <typename T>
void List<T>::push_front(T elem) {
	list_element<T>* cur = new list_element<T>;
	first->prev = cur;
	cur->next = first;
	cur->prev = NULL;
	cur->value = elem;
	first = cur;
	size += 1;
}

template <typename T>
void List<T>::push_back(T elem) {
	list_element<T>* cur = new list_element<T>;
	list_element<T>* lst = last->prev;
	lst->next = cur;
	cur->next = last;
	cur->prev = lst;
	cur->value = elem;
	last->prev = cur;
	size += 1;
}

template <typename T>
T List<T>::front() {
	return first->value;
}

template <typename T>
T List<T>::back() {
	list_element<T>* lst = last->prev;
	return lst->value;
}


template <typename T>
ListIterator<list_element<T>> List<T>::begin() {

	return iterator(first);
}

template <typename T>
ListIterator<list_element<T>> List<T>::end() {
	return iterator(last);
}

template <typename T>
ListIterator<const list_element<T>> List<T>::begin() const {
	return const_iterator(first);
}

template <typename T>
ListIterator<const list_element<T>> List<T>::end() const {
	return const_iterator(last);
}

template<typename T>
ListIterator<T>::ListIterator(T* p) : p(p) {
}

template<typename T>
ListIterator<T>::ListIterator(const ListIterator& it) : p(&(*it)) {

}

template<typename T>
bool ListIterator<T>::operator!=(ListIterator const& other) const {
	return p != other.p;
}

template<typename T>
bool ListIterator<T>::operator==(ListIterator const& other) const {
	return p == other.p;
}

template<typename T>
T& ListIterator<T>::operator*() const {
	return *p;
}

template<typename T>
ListIterator<T>& ListIterator<T>::operator++() {
	if (p->next != NULL) {
		p = p->next;
	}
	return *this;
}

template<typename T>
ListIterator<T>& ListIterator<T>::operator--() {
	if (p->prev != NULL) {
		p = p->prev;
	}
	return *this;
}

template<typename T>
ListIterator<list_element<T>> List<T>::insert(List<T>::iterator it, T value) {
	list_element<T>* elem = new list_element<T>;
	list_element<T>* next = &(*it);
	list_element<T>* prev = next->prev;
	if (prev != nullptr) {
		prev->next = elem;
	}
	else {
		first = elem;
	}
	elem->prev = prev;
	elem->value = value;
	elem->next = next;
	next->prev = elem;
	size += 1;
	return iterator(elem);
}

template<typename T>
void List<T>::unique() {
	for (list_element<T> elem : *this) {
		iterator cur = iterator(&elem);
		iterator it = cur;
		++it;
		for (it; it != last; ++it) {
			if ((*it).value == (*cur).value) {
				delete_element(it);
			}

		}
	}
}

template<typename T>
void List<T>::merge(List to_merge) {
	for (list_element<T> elem : to_merge) {
		this->push_back(elem);
	}
	size += to_merge.get_size();
}

template<typename T>
void List<T>::delete_element(iterator& pos) {
	this;
	list_element<T>* el = &(*pos);
	bool fst = false;
	bool lst = false;
	if (el->prev == NULL) {
		fst = true;
	}
	if (el->next == last) {
		lst = true;
	}
	if (!fst && !lst) {
		el->prev->next = el->next;
		el->next->prev = el->prev;
	}
	else if (fst && !lst) {
		el->next->prev = NULL;
		first = el->next;
	}
	else if (!fst && lst) {
		el->prev->next = last;
		last->prev = el->prev;
	}
	else if (fst && lst) {
		first = new list_element<T>;
		first->value = NULL;
		first->prev = NULL;
		first->next = last;
		last->prev = first;
	}
	if (fst) {
		++pos;
	}
	else {
		--pos;
	}
	delete el;

	
	size -= 1;
}

template<typename T>
void List<T>::erase(iterator start, iterator finish) {
	++finish;
	for (iterator it = start; it != finish; ++it) {
		delete_element(it);

	}
}

template<typename T>
ListIterator<list_element<T>> List<T>::erase(iterator pos) {
	delete_element(pos);
	++pos;
	return pos;
}

template<typename T>
void List<T>::remove(T x) {
	
	for (iterator it = begin(); it!=last; ++it)
	{

		if ((*it).value == x) {
			delete_element(it);
		}
	}
}

template<typename T>
void List<T>::remove_if(bool (*function)(T )) {

	for (iterator it = begin(); it != last; ++it)
	{
		
		if (function((*it).value)) {
			delete_element(it);
		}
	}
}