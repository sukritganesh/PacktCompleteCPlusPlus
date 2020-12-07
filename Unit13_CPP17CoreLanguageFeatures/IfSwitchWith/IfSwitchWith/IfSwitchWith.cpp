#include <iostream>
#include <fstream>

void Alloc() {
	// p is accessible outside if statement since it is declared outside
	int* p = (int*)malloc(sizeof(int));
	if (p != nullptr) {
		*p = 50;
		free(p);
	}

	// if (initialization; condition) {
	// p is accessible only INSIDE if statement; it is limited in scope!
	if (int* p = (int*)malloc(sizeof(int)); p != nullptr) {
		*p = 50;
		free(p);
	}
	else {
		// here p will be nullptr
	}
}

void Write(std::string data) {
	// old way (out is visible outside if statement)
	std::ofstream out{ "file.txt" };
	if (out) {
		if (!data.empty()) {
			std::cout << data;
		}
		else {
			std::cout << "No data to write\n";
		}
	}

	// new way (out is visible only INSIDE the if-else statements)
	if (std::ofstream out{ "file.txt" }; !data.empty()) {
		std::cout << data;
	}
	else {
		std::cout << "no data to write\n";
	}
}

void UsingSwitch(int errorCode) {
	switch (std::ofstream out{ "file.txt" }; errorCode) {
	case 0:
		out << "Invalid parameter\n";
		break;
	case 1:
		out << "Could not read from the file\n";
			break;
	}
}

int main() {

}