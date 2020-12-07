#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

// BASIC FILEIO

void Write1() {
	std::string filename = "data.txt";
	std::ofstream out{ filename };
	out << "Hello World" << std::endl;
	out << 10 << std::endl;
	out.close();
}

void Read1() {
	std::string filename = "data.txt";
	//std::string filename = "data.txt";	// nonexistent file
	std::ifstream input{ filename };
	// input.open(filename); // alternate method

	if (input.fail() || !input.is_open()) {
		std::cout << "Could not open file!" << std::endl;
		return;
	}

	std::string message;
	std::getline(input, message);
	int value{};
	input >> value;
	input >> value;	// will result in "end of file" as eof has been read and "some I/O operations failed"
	if (input.eof()) {
		std::cout << "End of file encountered" << std::endl;
	}

	if (input.good()) {
		std::cout << "I/O operations are successful" << std::endl;
	}
	else {
		std::cout << "Some I/O operations failed" << std::endl;
	}

	std::cout << input.bad() << std::endl;
	input.setstate(std::ios::badbit);
	std::cout << input.bad() << std::endl;
	input.clear();
	std::cout << input.fail() << std::endl;
	input.close();
	std::cout << "String: " << message << " | Value: " << value << std::endl;
}

void basicFileIODemo() {
	Write1();
	Read1();
}

// FILECOPY (create copy of main.cpp)

void filecopy() {
	using namespace std::filesystem;
	path source(current_path());
	source /= "main.cpp";

	path dest(current_path());
	dest /= "Copy.cpp";

	std::ifstream input{ source };
	if (!input) {
		std::cout << "Source file not found" << std::endl;
		return;
	}

	std::ofstream output{ dest };
	
	std::string line;
	while (!std::getline(input, line).eof()) {
		output << line << std::endl;
	}

	input.close();
	output.close();
}

// FileIO - Character IO and Seeking

void Write2() {
	std::ofstream out("test.txt");
	if (!out) {
		std::cout << "Could not open file for writing" << std::endl;
		return;
	}
	std::string message{ "C++ was invented by Bjarne" };
	for (char ch : message) {
		out.put(ch);
	}
	out.seekp(15);
	out.put('#');
}

void Read2() {
	std::ifstream input("test.txt");
	if (!input) {
		std::cout << "Source file not found" << std::endl;
		return;
	}
	std::cout << "Current position: " << input.tellg() << std::endl;
	input.seekg(10, std::ios::beg);		// default beg, can use cur or end
	std::cout << "Current position (seek): " << input.tellg() << std::endl;
	char ch{};
	while (input.get(ch)) {
		std::cout << ch;
	}
	std::cout << std::endl;
}

void charIOSeekingDemo() {
	Write2();
	Read2();
}

// FSTREAM

void usingFstream() {
	std::fstream stream{ "file.txt" };
	if (!stream) {
		std::cout << "FILE DOES NOT EXIST. CREATING ONE ..." << std::endl;
		std::ofstream out{ "file.txt" };
		out.close();
		stream.open("file.txt");
	}

	// write
	stream << "Hello world fstream!!!!" << std::endl;

	// read
	std::string line;
	stream.seekg(0);
	std::getline(stream, line);
	std::cout << line << std::endl;
}

int main() {
	//basicFileIODemo();
	filecopy();
	charIOSeekingDemo();
	usingFstream();

	return 0;
