#include <iostream>
#include "List.cpp"
using namespace std;
int main() {
	List<int> listok = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
	List<int> to_merge = { 7, 8, 9 };
	copy(listok.begin(), listok.end(), ostream_iterator<list_element<int>>(cout, " "));
	cout << endl;
	listok.unique();
	listok.merge(to_merge);
	copy(listok.begin(), listok.end(), ostream_iterator<list_element<int>>(cout, " "));
	
}