#include <iostream>
#include <cstring>

const char* Combine(const char* pFirst, const char* pLast) {
	char* fullname = new char[strlen(pFirst) + strlen(pLast) + 1];
	strcpy(fullname, pFirst);
	strcat(fullname, pLast);
	return fullname;
}

void cstringDemo() {
	char first[10];
	char last[10];
	std::cout << "Input two strings." << std::endl;
	std::cin.getline(first, 10);
	std::cin.getline(last, 10);

	const char* pFullName = Combine(first, last);

	std::cout << pFullName << std::endl;
	delete[] pFullName;
}

void stringDemo() {
	// Initialize & Assign
	std::string s = "Hello";

	// Access
	s[0] = 'W';
	char ch = s[1];

	std::cout << s << std::endl;
	std::cout << "Enter a string to store in s." << std::endl;
	std::cin >> s;

	std::string t;
	//std::cout << "Enter a string to store in t." << std::endl;
	//std::getline(std::cin, t);

	// Size
	std::cout << "Length of " << s << ": " << s.length() << std::endl;

	// Insert & Concatenate
	std::string s1{ "Hello" }, s2{ "World" };
	std::string s3{ s1 + s2 };
	s3 += "!";
	s3 += '.';
	s3.insert(5, " ");
	std::cout << s3 << std::endl;

	// Comparison
	if (s1 != s2) {
		// do something
	}

	// Removal
	s.erase();
	s3.erase(3, 8);
	std::cout << s3 << std::endl;
	s3.clear();

	// Search
	s = "Hello World";
	auto pos = s.find("World", 0);
	if (pos != std::string::npos) {
		// String Found
	}

	// Raw string
	printf("%s", s.c_str());
}

#include <sstream>

void stringStreamDemo() {
	int a{ 5 }, b{ 6 };
	int sum = a + b;
	std::cout << "Sum of " << a << " & " << b << " is " << sum << std::endl;
	//std::string otp = "Sum of " << a << " & " << b << " is " << sum << std::endl;


	// Using stringstream
	std::stringstream ss;
	ss << "Sum of " << a << " & " << b << " is " << sum << std::endl;
	std::string s = ss.str();
	std::cout << s << std::endl;
	ss.str("New");
	std::cout << ss.str() << std::endl;

	// TO STRING function
	std::string ssum = std::to_string(sum);
	std::cout << ssum << std::endl;

	// Reading from stringstream
	std::cout << std::endl;
	std::string data = "12 89 21";
	int a2;
	std::stringstream ss2;
	ss2.str(data);
	while (ss2 >> a2) {
		std::cout << a2 << std::endl;
	}

	// Conversion
	int p = std::stoi("46");
	std::cout << p << std::endl;

}

int main() {
	//cstringDemo();
	//stringDemo();
	stringStreamDemo();
}