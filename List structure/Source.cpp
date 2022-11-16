#include <iostream>
#include "List.cpp"
using namespace std;
int main() {
	List<int> listok = {1, 2, 3};
	List<int> listok2 = { 0, 10 };
	//List<int>::iterator it = listok2.insert(listok2.begin(), 2);
	//++it;
	listok.unique();
	
}