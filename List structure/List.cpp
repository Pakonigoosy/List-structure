#include "List.h"
#include <iostream>
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

//Нереализованные методы итераторов
/*
template <typename T>
List<T>::iterator List<T>::begin() {
	return first;
}

template <typename T>
List<T>::iterator List<T>::end() {
	list_element<T>* last = first;
	while (last->next != NULL) {
		last = last->next;
	}
	return last;
}*/