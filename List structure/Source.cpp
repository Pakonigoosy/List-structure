#include <iostream>
#include "List.cpp"
using namespace std;
int main() {
	List<int> listok = {4, 6, 3, 2};
	List<int>::iterator it = listok.begin();
	advance(it, 2);
	listok.insert(it, 8);
}