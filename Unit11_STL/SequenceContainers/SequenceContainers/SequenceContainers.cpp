#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

void arrayDemo() {
	// Initialize
	std::array<int, 5> arr;
	std::array<int, 5> arr2{ 0, 1, 2, 3, 4 };

	// Access/Modify
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = i;
	}

	// Iterator
	auto it = arr.begin();
	for (auto it = arr.begin(); it != arr.end(); ++it) {
		*it += 1;
	}
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	// Data function
	int * theArr = arr.data();
	std::cout << theArr[2] << std::endl;
}

void vectorDemo() {
	// Initialize
	std::vector<int> myVec;
	std::vector<int> myVec2{ 0, 1, 2, 3, 4};
	
	// Add to back
	for (int i = 0; i < 10; i++) {
		myVec.push_back(i);
		std::cout << myVec.size() << " ";
	}
	std::cout << std::endl;

	// Remove from back
	myVec.pop_back();

	// Access/Modify
	myVec[4] = 10;
	std::cout << "myVec[4]: " << myVec[4] << std::endl;

	// Insert
	myVec.insert(myVec.begin() + 3, 300);

	// Remove
	myVec.erase(myVec.begin() + 2);
	myVec.erase(myVec.end() - 2);

	// Iterator
	for (auto it = myVec.begin(); it != myVec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

}

void dequeDemo() {
	// Initialize
	std::deque<int> x;

	// Add to back
	for (int i = 0; i < 10; i++) {
		x.push_back(i);
		std::cout << x.size() << " ";
	}


	// Add to front
	for (int i = -1; i > -10; i--) {
		x.push_front(i);
		std::cout << x.size() << " ";
	}
	std::cout << std::endl;

	// Remove from back
	x.pop_back();

	// Access/Modify
	x[4] = 10;
	std::cout << "x[4]: " << x[4] << std::endl;

	// Insert
	x.insert(x.begin() + 3, 300);

	// Remove
	x.erase(x.begin() + 4);
	x.erase(x.end() - 3);
	x.pop_front();		// Remove from front

	// Iterator
	for (auto it = x.begin(); it != x.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


// LIST and FORWARD LIST
void listDemo() {
	// Initialize list
	std::list<int> x;
	for (int i = 0; i < 5; i++) {
		x.push_back(i);
	}

	// insert and erase
	auto it = x.begin();
	x.insert(it, 100);
	++it;
	++it;
	x.insert(it, 200);
	++it;
	++it;
	x.erase(it);

	// iterator (access)
	for (auto it = x.begin(); it != x.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Initialize forward list
	std::forward_list<int> y;
	for (int i = 0; i < 10; i++) {
		y.push_front(i);
	}

	// insert and erase (happens AFTER specified element)
	auto it2 = y.begin();
	y.insert_after(it2, 10);
	++it2;
	++it2;
	y.insert_after(it2, 200);
	++it2;
	++it2;
	y.erase_after(it2);

	// iterator
	for (auto el : y) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

int main() {
	//arrayDemo();
	//vectorDemo();
	//dequeDemo();
	listDemo();

	return 0;
}