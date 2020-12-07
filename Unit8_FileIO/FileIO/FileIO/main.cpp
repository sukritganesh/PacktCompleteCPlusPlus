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

// BINARY FILES

struct Record {
	int id;
	char name[10];
};

void WriteRecord(Record* p1, Record* p2) {
	std::ofstream binstream{ "records.bin", std::ios::binary | std::ios::out };
	binstream.write((const char*)p1, sizeof(Record));
	binstream.write((const char*)p2, sizeof(Record));

}

Record GetRecord() {
	std::ifstream input{ "records.bin", std::ios::binary | std::ios::in };
	Record r1;
	Record r2;
	input.read((char*) &r1, sizeof(Record));
	input.read((char*)&r2, sizeof(Record));

	std::cout << r1.id << " | " << r1.name << std::endl;
	std::cout << r2.id << " | " << r2.name << std::endl;


	return r1;
}

void binaryFileDemo() {
	std::ofstream textstream{ "nonbinary.bin" };
	textstream << 12345678;

	std::ofstream binstream{ "binary.bin", std::ios::binary | std::ios::out };
	int num{ 12345678 };
	binstream.write((const char*) &num, sizeof(num));		// one char is one byte
	binstream.close();

	int num2{};
	std::ifstream input{ "binary.bin", std::ios::binary | std::ios::in };
	input.read((char*) &num2, sizeof(num2));
	std::cout << num2 << std::endl;

	// Writing structs to bin file
	Record r1;
	Record r2;
	r1.id = 1001;
	r2.id = 1002;
	strcpy_s(r1.name, 8, "Lincoln");
	strcpy_s(r2.name, 10, "Abraham");
	WriteRecord(&r1, &r2);

	Record r = GetRecord();
	std::cout << r.id << " | " << r.name << std::endl;

}

int main() {
	//basicFileIODemo();
	//filecopy();
	//charIOSeekingDemo();
	//usingFstream();
	binaryFileDemo();

	return 0;
}