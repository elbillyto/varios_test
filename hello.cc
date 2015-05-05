//============================================================================
// Name        : hello.cc
// Author      : manuel
// Version     :
// Copyright   : copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>     // std::cout
#include <algorithm>    // std::binary_search, std::sort
#include <vector>       // std::vector
using namespace std;

bool myfunction(int i, int j) {
	return (i < j);
}

class Answer {
public:
	static bool exists(int ints[], int size, int k) {


		if(!size || !sizeof(ints)||ints==NULL)//if array empty
			return false;

		std::vector<int> v(ints, ints + size ); // -9, 14, 37, 102
		//for (int i=0; i<size; i++) v.at(i) = ints[i];

		// using default comparison:
		//std::sort(v.begin(), v.end());

//		std::cout << "The contents are:";
//		  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
//		    std::cout << ' ' << *it;
//		  std::cout << '\n';

		if (std::binary_search(v.begin(), v.end(), k)) {
			//std::cout << "found!\n";
			return true;
		} else {
			//std::cout << "not found.\n";
			return false;
		}

//		// using myfunction as comp:
//		std::sort(v.begin(), v.end(), myfunction);
//
//		if (std::binary_search(v.begin(), v.end(), k, myfunction)) {
//			std::cout << "found!\n";
//			return true;
//		} else {
//			std::cout << "not found.\n";
//			return false;
//		}
	}
};

int main() {
	int ints[] = { -9, 14, 37, 102 };
	std::cout << "Hello.exe" << std::endl;
	cout << Answer::exists(ints, 4, 102) << endl; // 1
	cout << Answer::exists(ints, 4, 36) << endl; // 0
	cout << Answer::exists(ints, 0, 102) << endl; // 0
	cout << Answer::exists(NULL, 0, 102) << endl; // 0

	return 0;
}