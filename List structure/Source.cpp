#include <iostream>
#include "List.h"
using namespace std;
int main() {
	//List<int> listok = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	/*copy(listok.begin(), listok.end(), ostream_iterator<list_element<int>>(cout, " "));
	cout << endl;
	listok.pop_back();
	listok.pop_front();
	copy(listok.begin(), listok.end(), ostream_iterator<list_element<int>>(cout, " "));*/
	List<int>* listok = new List<int>();
	delete listok;
}