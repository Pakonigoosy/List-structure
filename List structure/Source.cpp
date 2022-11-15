#include <iostream>
#include "List.cpp"
using namespace std;
int main() {
	List<int> listok = {4, 6, 3, 2};
	List<int>::iterator it = listok.begin();
	List<int>::iterator it2 = listok.begin();
	advance(it, 3);
	cout << *it;
}