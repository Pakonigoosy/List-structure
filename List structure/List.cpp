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
void List<T>::test() {
	std::cout << first->value;
}

