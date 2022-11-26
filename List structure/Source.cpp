#include <iostream>
#include "List.h"
using namespace std;
bool test(int x) {
	if (x > 2) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	List<int> listok = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	copy(listok.begin(), listok.end(), ostream_iterator<list_element<int>>(cout, " "));
	cout << endl;
	listok.remove_if(&test);
	copy(listok.begin(), listok.end(), ostream_iterator<list_element<int>>(cout, " "));
	
}