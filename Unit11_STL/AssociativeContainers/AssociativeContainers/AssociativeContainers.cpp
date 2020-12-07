#include <iostream>
#include <string>
#include <set>
#include <functional>
#include <map>

void setDemo() {
	std::set<int, std::greater<int>> s{ 8, 2, 0, 9, 5 };
	s.insert(1);
	s.insert(3);

	for (auto it = s.begin(); it != s.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	s.erase(2);
	s.erase(s.begin());		// erase first element

	auto a = s.find(8);			// returns iterator pointing to element 9, s.end() if 9 doesn't exist
	std::cout << *a << std::endl;
}

void multisetDemo() {
	std::multiset<int> s{ 8, 2, 0, 9, 5 };

	s.insert(5);		// can insert duplicates
	s.insert(5);

	for (auto it = s.begin(); it != s.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	auto found = s.equal_range(5);		// returns range of elements where 5 is located
	while (found.first != found.second) {
		std::cout << *found.first++ << " ";
	}
	std::cout << std::endl;
}

void mapDemo() {
	std::map<int, std::string> m{
		{1, "Superman"},
		{2, "Batman"},
		{3, "Green Lantern"}
	};

	// insert
	m.insert(std::make_pair(4, "Captain America"));
	m[0] = "Flash";
	m.insert(std::make_pair(4, "Hello World"));	// WILL BE DISCARDED since 4 is existing key

	for (const auto &x : m) {
		std::cout << x.first << ":" << x.second << " ";
	}
	std::cout << std::endl;

	m[0] = "Santa Claus";		// how to change values for existing keys
	m.erase(3);		// erase {3, "Green Lantern"}

	auto itr = m.find(1);
	std::cout << itr->first << ":" << itr->second << std::endl;
	std::cout << m[4] << std::endl;


	// avoid this, since you may accidentaly read nonexistant key and assign default value to it
	std::cout << "m[10]: " << m[10] << std::endl;
	std::cout << "m[10]: " << m[10] << std::endl;

	for (const auto& x : m) {
		std::cout << x.first << ":" << x.second << " ";
	}
	std::cout << std::endl;

	// for multimap, use equal_range to get iterators specifying range of pairs
	std::multimap<int, std::string> mm{
		{1, "Hello"},
		{1, "Goodbye"}
	};

	for (auto it = mm.equal_range(1).first; it != mm.equal_range(1).second; ++it) {
		std::cout << it->first << ":" << it->second << " ";
	}
	std::cout << std::endl;
}

int main() {
	//setDemo();
	//multisetDemo();
	mapDemo();

	return 0;
}