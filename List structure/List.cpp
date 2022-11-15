#include "List.h"
#include <iostream>
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
	list_element<T> first_le = new list_element<T>;
	first = &first_le;
}

template <typename T>
List<T>::List(std::initializer_list<T> init) {
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
	current->prev->next = NULL;
	
}

template <typename T>
void List<T>::pop_front() {
	list_element<T>* next = first->next;
	delete first;
	first = next;
	first->prev = NULL;
}

template <typename T>
void List<T>::pop_back() {
	list_element<T>* current = first;
	while (current->next != NULL) {
		current = current->next;
	}
	list_element<T>* prev = current->prev;
	delete current;
	prev->next = NULL;
}

template <typename T>
void List<T>::push_front(T elem) {
	list_element<T>* cur = new list_element<T>;
	first->prev = cur;
	cur->next = first;
	cur->prev = NULL;
	cur->value = elem;
	first = cur;
}

template <typename T>
void List<T>::push_back(T elem) {
	list_element<T>* cur = new list_element<T>;
	list_element<T>* last = first;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = cur;
	cur->next = NULL;
	cur->prev = last;
	cur->value = elem;
}

template <typename T>
T List<T>::front() {
	return first->value;
}

template <typename T>
T List<T>::back() {
	list_element<T>* last = first;
	while (last->next != NULL) {
		last = last->next;
	}
	return last->value;
}


template <typename T>
ListIterator<list_element<T>> List<T>::begin() {
	
	return iterator(first);
}

template <typename T>
ListIterator<list_element<T>> List<T>::end() {
	list_element<T>* last = first;
	while (last->next != NULL) {
		last = last->next;
	}
	return iterator(last);
}

template <typename T>
ListIterator<const list_element<T>> List<T>::begin() const {
	return const_iterator(first);
}

template <typename T>
ListIterator<const list_element<T>> List<T>::end() const{
	list_element<T>* last = first;
	while (last->next != NULL) {
		last = last->next;
	}
	return const_iterator(last);
}

template<typename T>
ListIterator<T>::ListIterator(T* p) : p(p) {
}

template<typename T>
ListIterator<T>::ListIterator(const ListIterator& it) : p(it.p) {

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
ListIterator<T> &ListIterator<T>::operator++() {
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